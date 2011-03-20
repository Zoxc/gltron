#include "video/video.h"

void enableSkyboxTexture(void) {
  glEnable(GL_TEXTURE_2D);
}

void disableSkyboxTexture(void) {
  glDisable(GL_TEXTURE_2D);
}

static void bindSkyboxTexture(int index) {
  glBindTexture(GL_TEXTURE_2D, gScreen->textures[ TEX_SKYBOX + index ]);
}

void drawSkybox(int grid_size) {
  /* 
     matrices are: 
     projection: perspective projection 
     modelview: identity
  */
  
  /* these are the values for y == up, x == front */
  /* 
  float sides[6][4][3] = {
    { { 1, -1, -1 }, { 1, -1, 1 }, { 1, 1, 1 },  { 1, 1, -1 } }, // front
    { { 1, 1, -1 }, { 1, 1, 1 }, { -1, 1, 1 }, { -1, 1, -1 } }, // top
    { { -1, -1, -1 }, { 1, -1, -1 },  { 1, 1, -1 }, { -1, 1, -1 } }, // left
    { { 1, -1, 1 }, { -1, -1, 1 }, { -1, 1, 1 }, { 1, 1, 1 } }, // right
    { { -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 } }, // bottom
    { { -1, -1, 1 }, { -1, -1, -1 }, { -1, 1, -1 }, { -1, 1, a1 } } // back
  };
  */

  /* these values are for z == up, x == front */
  float sides[6][4][3] = {
    { { 1, 1, -1 }, { 1, -1, -1 }, { 1, -1, 1 },  { 1, 1, 1 } }, /* front */
    { { 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 } }, /* top */
    { { -1, 1, -1 }, { 1, 1, -1 },  { 1, 1, 1 }, { -1, 1, 1 } }, /* left */
    { { 1, -1, -1 }, { -1, -1, -1 }, { -1, -1, 1 }, { 1, -1, 1 } }, /* right */
    { { -1, 1, -1 }, { -1, -1, -1 }, { 1, -1, -1 }, { 1, 1, -1 } }, /* bottom */
    { { -1, -1, -1 }, { -1, 1, -1 }, { -1, 1, 1 }, { -1, -1, 1 } } /* back */
  };
    
  float uv[4][2] = { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
  int i, j;
  float d = grid_size * 3;
  
  gl2gles_vertex3v verts[6];
    
  gl2gles_vertex2v texts[6];
  
  glEnable(GL_TEXTURE_2D);
  glDepthMask(GL_FALSE);
  //TODO:DONE REdo for gles
  /*glColor3f(1.0, 1.0, 1.0);
  for(i = 0; i < 6; i++) {
    bindSkyboxTexture(i);
    glBegin(GL_QUADS);
    for(j = 0; j < 4; j++) {
      glTexCoord2fv( uv[j] );
      glVertex3f( sides[i][j][0] * d, sides[i][j][1] * d, sides[i][j][2] * d );
    }
    glEnd();
  }*/
  
  glEnableClientState (GL_TEXTURE_COORD_ARRAY);
  glDisableClientState (GL_NORMAL_ARRAY);  
  glEnableClientState (GL_VERTEX_ARRAY);
  glDisableClientState (GL_COLOR_ARRAY);
  
  glColor3f(1.0, 1.0, 1.0);
    for(i = 0; i < 6; i++) {
      bindSkyboxTexture(i);
      //glBegin(GL_QUADS);
      /*for(j = 0; j < 4; j++) {
        glTexCoord2fv( uv[j] );
        glVertex3f( sides[i][j][0] * d, sides[i][j][1] * d, sides[i][j][2] * d );
      }*/
      
      FillVertex2v(texts[0],uv[0][0],uv[0][1]);
	  FillVertex3v(verts[0],sides[i][0][0] * d, sides[i][0][1] * d, sides[i][0][2] * d);
	  
	  FillVertex2v(texts[1],uv[1][0],uv[1][1]);
	  FillVertex3v(verts[1],sides[i][1][0] * d, sides[i][1][1] * d, sides[i][1][2] * d);
	  
	  FillVertex2v(texts[2],uv[2][0],uv[2][1]);
	  FillVertex3v(verts[2],sides[i][2][0] * d, sides[i][2][1] * d, sides[i][2][2] * d);
	  
	  FillVertex2v(texts[3],uv[2][0],uv[2][1]);
	  FillVertex3v(verts[3],sides[i][2][0] * d, sides[i][2][1] * d, sides[i][2][2] * d);
	  
	  FillVertex2v(texts[4],uv[3][0],uv[3][1]);
	  FillVertex3v(verts[4],sides[i][3][0] * d, sides[i][3][1] * d, sides[i][3][2] * d);
	  
	  FillVertex2v(texts[5],uv[0][0],uv[0][1]);
	  FillVertex3v(verts[5],sides[i][0][0] * d, sides[i][0][1] * d, sides[i][0][2] * d);
	  
	  glVertexPointer	(3,GL_FLOAT,0,verts); 
	  glTexCoordPointer	(2,GL_FLOAT,0,texts);

	  glDrawArrays( GL_TRIANGLES , 0, 6 );
      
      //glEnd();
    }
  
  glDisable(GL_TEXTURE_2D);
  glDepthMask(GL_TRUE);
}
