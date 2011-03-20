
#include <gles\gl.h>
#include <stdio.h>
#include <SDL.h>


static const GLbyte vertices[3 * 3] =
	{
	-1,	1,	0,
	1,	-1, 0,
	1, 1, 	0
	};
	
static const GLubyte colors[3 * 4] = 
	{
	255,	0, 		0,		255,
	0,		255,	255,	255,
	0,		0,		255,	255
	};
	
int panic(char* str)
	{
	fprintf(stderr,"%s: %s\n",str, SDL_GetError());
	exit( 1 );
	return 0;
	}


typedef struct{
	float x;
	float y;
	float z;
	
}gl2gles_vertex3v;

void testLines()
{
static float normal[] = { 0.3, 0.4, 0.6 ,0.3, 0.4, 0.6};

  

	float trail_top[] = { 1.0, 1.0, 1.0, 1.0 };
	float trail_tops[2][4] = {{ 0.0, 1.0, 1.0, 1.0 },
							{ 0.0, 1.0, 0.4, 1.0 }};


	gl2gles_vertex3v tempvertex[3];

	gl2gles_vertex3v vNormal[3];

	
	glEnableClientState (GL_VERTEX_ARRAY);
	  glEnableClientState (GL_COLOR_ARRAY);
	  glEnableClientState (GL_NORMAL_ARRAY);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);

	/*glColor4fv(trail_top);

  glBegin(GL_LINES);

	glVertex3f(-0.5,
						 -0.5,
						 1.0);
  glVertex3f( 0.5,
	      -0.5,
	      1 );

  glEnd();*/
  glColorPointer(4,GL_FLOAT,0,trail_tops);


	vNormal[0].x = normal[0];
      vNormal[0].y = normal[1];
      vNormal[0].z = normal[2];
      
      vNormal[1]=vNormal[0];
      vNormal[2]=vNormal[0];

      
  //glNormalPointer(GL_FLOAT,0,normal);
  glNormal3f(normal[0],normal[1],normal[2]);

  tempvertex[0].x = -0.5;
  tempvertex[0].y = -0.5;
  tempvertex[0].z = 1.0;

  tempvertex[1].x = 0.5;
  tempvertex[1].y = -0.5;
  tempvertex[1].z = 1.0;
  
  tempvertex[2].x = 0.0;
  tempvertex[2].y = 0.5;
  tempvertex[2].z = 1.0;
  

  glVertexPointer(3, GL_FLOAT,0, tempvertex);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisable(GL_BLEND);
  glDisable(GL_LINE_SMOOTH);

  
  glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void renderFrame()
	{
	/*glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -5.f);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	*/
	
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
				
	glPushMatrix();
	//Code goes here
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_COLOR_ARRAY);
	glEnableClientState (GL_NORMAL_ARRAY);
	
	testLines();
	
	glPopMatrix();
	}

int main(int argc, char** argv)
	{
	int width;
	int height;
	SDL_Surface* screen;
	SDL_Rect** modes;
	int videoFlags = SDL_OPENGL | SDL_FULLSCREEN;
	int done = 0;
	SDL_Event event;
	
	argc;
	argv;
	

	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	 	{
		panic("SDL Init");
		}

	modes = SDL_ListModes(NULL, videoFlags);
	
	if(modes == NULL)
		{
		panic("No available video modes");
		}

	width = 240;
	height = 320;
	
	if(modes != (SDL_Rect**) -1)
		{
		width = modes[0]->w;
		height = modes[0]->h;
		}
	
	SDL_GL_LoadLibrary(NULL);	
		
	screen = SDL_SetVideoMode(width, height, 16, videoFlags);	
	
	if(screen == NULL)
		{
		panic("No GLES surface available");
		}
			
	/*glDisable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.f, 0.f, 0.1f, 1.f);
	
	glVertexPointer(3, GL_BYTE, 0, vertices);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glViewport(0, 0, width, height);
	//glMatrixMode(GL_PROJECTION);
	//glFrustumf(-1.f, 1.f, -1.f, 1.f, 3.f, 1000.f);
	//glMatrixMode(GL_MODELVIEW);

	while(!done)
		{
		if(SDL_PollEvent(&event))
			{
			switch(event.type)
				{
				case SDL_KEYDOWN:
				case SDL_QUIT:
				done = 1;
				break;
				}
			}
		else
			{
			GLenum gl_error;
			renderFrame();
			SDL_GL_SwapBuffers();
			/* Check for error conditions. */
			gl_error = glGetError();	
			if(gl_error != GL_NO_ERROR ) 
				{
				fprintf(stderr, "OpenGL error: %d\n", gl_error );
				SDL_FreeSurface(screen);
    			SDL_Quit();
				exit( 1 );
				}
			SDL_Delay(20);
			}
		}
		
	SDL_FreeSurface(screen);
	/* Shutdown all subsystems */
    SDL_Quit();
	return 0;
	}
