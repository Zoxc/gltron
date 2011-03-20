#include "../include/video/nebu_video_system.h"

#include "SDL.h"
#include <SDL_syswm.h>
#include <swl-utils.h>
#include <GLES/gl.h>

static SDL_Surface *screen;
static int width, height;
static int flags;
static int fullscreen;
extern int video_initialized;

void SystemSwapBuffers() {
  swl_swap();
}

void SystemInitWindow(int x, int y, int w, int h) {
  width = w;
  height = h;
}

void SystemInitDisplayMode(int f, unsigned char full) {
  int bitdepth, zdepth;

  flags = f;
  //S60: R.K. symbian changed 
  fullscreen = SYSTEM_FULLSCREEN;
  if(!video_initialized) {
    if(SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
      fprintf(stderr, "[system] can't initialize Video: %s\n", SDL_GetError());
      exit(1); /* OK: critical, no visual */
    }
  }

  if(flags & SYSTEM_DOUBLE)
   ;// SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);

  if(flags & SYSTEM_32_BIT) {
    zdepth = 24;
    bitdepth = 32;
  } else {
    zdepth = 16;
    bitdepth = 16;
  }
  if(flags & SYSTEM_DEPTH)
    ;//SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, zdepth);
  if(flags & SYSTEM_STENCIL)
     ;//SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8);
  else 
     ;//SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 0);
  video_initialized = 1;
  /* FIXME: bitdepth value unused */
}

void SystemSetGamma(float red, float green, float blue) {
  //SDL_SetGamma(red, green, blue);
}

int SystemCreateWindow(char *name) {
  int f = 0;
  if(fullscreen & SYSTEM_FULLSCREEN)
    f |= SDL_FULLSCREEN;
  if( (screen = SDL_SetVideoMode( width, height, 16, f )) == NULL ) {
    fprintf(stderr, "[system] Couldn't set GL mode: %s\n", SDL_GetError());
    exit(1); /* OK: critical, no visual */
  }
  SDL_WM_SetCaption("GLtron", "");

  SDL_SysWMinfo sysInfo;
  SDL_VERSION(&sysInfo.version);

  if(SDL_GetWMInfo(&sysInfo) <= 0)
    exit(1); /* OK: critical, no visual */

  enum swl_result result = swl_context_allocate(sysInfo.info.x11.window, XOpenDisplay(0));

  if(result != SWLR_OK) {
    fprintf(stderr, "[system] Couldn't create context, %d\n", result);
    exit(1); /* OK: critical, no visual */
  }

  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  swl_swap();
  return 1;
}

void SystemDestroyWindow(int id) {
  /* quit the video subsytem
	 * otherwise SDL can't create a new context on win32, if the stencil
	 * bits change 
	 */
	/* there used to be some problems (memory leaks, unprober driver unloading)
	 * caused by this, but I can't remember what they where
	 */
		 
  swl_quit();
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  video_initialized = 0;
}

void SystemReshapeFunc(void(*reshape)(int, int)) {
}

int SystemWriteBMP(char *filename, int x, int y, unsigned char *pixels) {
  /* this code is shamelessly stolen from Ray Kelm, but I believe he
     put it in the public domain */
  SDL_Surface *temp;
  int i;

  temp = SDL_CreateRGBSurface(SDL_SWSURFACE, x, y, 24,
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
			      0x000000FF, 0x0000FF00, 0x00FF0000, 0
#else
			      0x00FF0000, 0x0000FF00, 0x000000FF, 0
#endif
			      );

  if (temp == NULL)
    return -1;

  for (i = 0; i < y; i++)
    memcpy(((char *) temp->pixels) + temp->pitch * i, 
	   pixels + 3 * x * (y - i - 1), x * 3);

  SDL_SaveBMP(temp, filename);
  SDL_FreeSurface(temp);
  return 0;
}

