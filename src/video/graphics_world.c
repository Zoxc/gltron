#include "video/video.h"
#include "game/game.h"

void drawWalls(void) {
#undef WALL_H
#define WALL_H 48
  float t;
  float h;

  //R.K.
  gl2gles_vertex3v verts[6];
  gl2gles_vertex2v texture[6];
  
  t = game2->rules.grid_size / 240.0f;
  if (gSettingsCache.stretch_textures) {
    h = t * WALL_H;
    t = 1.0;
  } else h = WALL_H;

  glColor4f(1.0, 1.0, 1.0, 1.0);

  /*
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  */
  glEnable(GL_CULL_FACE);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  
  glEnableClientState (GL_VERTEX_ARRAY);
  glEnableClientState (GL_TEXTURE_COORD_ARRAY);
  
#define T_TOP 1.0f
  //R.K. first Wall
  glBindTexture(GL_TEXTURE_2D, gScreen->textures[TEX_WALL1]);
  //TODO:DONE Redo for GLES
  /*glBegin(GL_QUADS);
  glTexCoord2f(t, 0.0); glVertex3f(0.0, 0.0, 0.0);
  glTexCoord2f(t, T_TOP); glVertex3f(0.0, 0.0, h);
  glTexCoord2f(0.0, T_TOP); glVertex3f(game2->rules.grid_size, 0.0, h);
  glTexCoord2f(0.0, 0.0); glVertex3f(game2->rules.grid_size, 0.0, 0.0);
  glEnd();*/
  
  FillVertex2v(texture[0],t,0.0);
  FillVertex3v(verts[0],0.0,0.0,0.0);
  
  FillVertex2v(texture[1],t,T_TOP);
  FillVertex3v(verts[1],0.0,0.0,h);
  
  FillVertex2v(texture[2],0.0,T_TOP);
  FillVertex3v(verts[2],game2->rules.grid_size, 0.0, h);
  
  //End of first triangle
  
  FillVertex2v(texture[3],0.0,T_TOP);
  FillVertex3v(verts[3],game2->rules.grid_size, 0.0, h);
  
  FillVertex2v(texture[4],0.0,0.0);
  FillVertex3v(verts[4],game2->rules.grid_size, 0.0, 0.0);
  
  
  FillVertex2v(texture[5],t,0.0);
  FillVertex3v(verts[5],0.0,0.0,0.0);
  
  //Final triangle
  
  glVertexPointer	(3,GL_FLOAT,0, verts); 
  glTexCoordPointer	(2,GL_FLOAT,0,texture);

  glDrawArrays( GL_TRIANGLES , 0, 6 );
  //Draw it!
  
  
  //R.K. Second Wall
  glBindTexture(GL_TEXTURE_2D, gScreen->textures[TEX_WALL2]);
  /*glBegin(GL_QUADS);
  glTexCoord2f(t, 0.0); glVertex3f(game2->rules.grid_size, 0.0, 0.0);
  glTexCoord2f(t, T_TOP); glVertex3f(game2->rules.grid_size, 0.0, h);
  glTexCoord2f(0.0, T_TOP); 
  glVertex3f(game2->rules.grid_size, game2->rules.grid_size, h);
  glTexCoord2f(0.0, 0.0); 
  glVertex3f(game2->rules.grid_size, game2->rules.grid_size, 0.0);
  glEnd();*/
	FillVertex2v(texture[0],t,0.0);
    FillVertex3v(verts[0],game2->rules.grid_size,0.0,0.0);
    
    FillVertex2v(texture[1],t,T_TOP);
    FillVertex3v(verts[1],game2->rules.grid_size,0.0,h);
    
    FillVertex2v(texture[2],0.0,T_TOP);
    FillVertex3v(verts[2],game2->rules.grid_size, game2->rules.grid_size, h);
    
    //End of first triangle
    
    FillVertex2v(texture[3],0.0,T_TOP);
    FillVertex3v(verts[3],game2->rules.grid_size, game2->rules.grid_size, h);
    
    FillVertex2v(texture[4],0.0,0.0);
    FillVertex3v(verts[4],game2->rules.grid_size, game2->rules.grid_size, 0.0);
    
    
    FillVertex2v(texture[5],t,0.0);
    FillVertex3v(verts[5],game2->rules.grid_size,0.0,0.0);
    
    
    glVertexPointer	(3,GL_FLOAT,0, verts); 
    glTexCoordPointer(2,GL_FLOAT,0,texture);

    glDrawArrays( GL_TRIANGLES , 0, 6 );
    
    //End second wall
    
    //Begin 3d wall
  glBindTexture(GL_TEXTURE_2D, gScreen->textures[TEX_WALL3]);
  /*glBegin (GL_QUADS);
  glTexCoord2f(t, 0.0); 
  glVertex3f(game2->rules.grid_size, game2->rules.grid_size, 0.0);
  glTexCoord2f(t, T_TOP); 
  glVertex3f(game2->rules.grid_size, game2->rules.grid_size, h);
  glTexCoord2f(0.0, T_TOP); glVertex3f(0.0, game2->rules.grid_size, h);
  glTexCoord2f(0.0, 0.0); glVertex3f(0.0, game2->rules.grid_size, 0.0);
  glEnd(); */
    FillVertex2v(texture[0],t,0.0);
	FillVertex3v(verts[0],game2->rules.grid_size,game2->rules.grid_size,0.0);

	FillVertex2v(texture[1],t,T_TOP);
	FillVertex3v(verts[1],game2->rules.grid_size,game2->rules.grid_size,h);

	FillVertex2v(texture[2],0.0,T_TOP);
	FillVertex3v(verts[2],0.0, game2->rules.grid_size, h);

	//End of first triangle

	FillVertex2v(texture[3],0.0,T_TOP);
	FillVertex3v(verts[3],0.0, game2->rules.grid_size, h);

	FillVertex2v(texture[4],0.0,0.0);
	FillVertex3v(verts[4],0.0, game2->rules.grid_size, 0.0);

	FillVertex2v(texture[5],t,0.0);
	FillVertex3v(verts[5],game2->rules.grid_size, game2->rules.grid_size,0.0);

	glVertexPointer(3, GL_FLOAT,0, verts);
	glTexCoordPointer(2, GL_FLOAT,0, texture);

	glDrawArrays(GL_TRIANGLES, 0, 6);
  
  //END 3d wall
   
  //Begin 4th wall	
  glBindTexture(GL_TEXTURE_2D, gScreen->textures[TEX_WALL4]);
  /*glBegin(GL_QUADS);
  glTexCoord2f(t, 0.0); glVertex3f(0.0, game2->rules.grid_size, 0.0);
  glTexCoord2f(t, T_TOP); glVertex3f(0.0, game2->rules.grid_size, h);
  glTexCoord2f(0.0, T_TOP); glVertex3f(0.0, 0.0, h);
  glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0); 
  glEnd();*/
  
    FillVertex2v(texture[0],t,0.0);
  	FillVertex3v(verts[0],0.0,game2->rules.grid_size,0.0);

  	FillVertex2v(texture[1],t,T_TOP);
  	FillVertex3v(verts[1],0.0,game2->rules.grid_size,h);

  	FillVertex2v(texture[2],0.0,T_TOP);
  	FillVertex3v(verts[2],0.0, 0.0, h);

  	//End of first triangle

  	FillVertex2v(texture[3],0.0,T_TOP);
  	FillVertex3v(verts[3],0.0, 0.0, h);

  	FillVertex2v(texture[4],0.0,0.0);
  	FillVertex3v(verts[4],0.0, 0.0, 0.0);

  	FillVertex2v(texture[5],t,0.0);
  	FillVertex3v(verts[5],0.0,game2->rules.grid_size,0.0);

  	glVertexPointer(3, GL_FLOAT,0, verts);
  	glTexCoordPointer(2, GL_FLOAT,0, texture);

  	glDrawArrays(GL_TRIANGLES, 0, 6);
  
  //end 4th wall
#undef T_TOP
  
  
  polycount += 8;

  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_CULL_FACE);
}

/*!
 * drawFloorTextured 
 *
 * \return number of polygons drawn
 *
 * Draws the arena floor covered with a repeating floor texture
 */

int drawFloorTextured(int grid_size, GLuint texture) {
  int i, j, l, t;
  
  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  gl2gles_vertex2vx verts[6];
      
  gl2gles_vertex2vx texts[6];
  
  glEnableClientState (GL_TEXTURE_COORD_ARRAY);
  glEnableClientState (GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  
  
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);
  
  

    /* there are some strange clipping artefacts on some renderers */
    /* try subdividing things... */

    glColor4f(1.0, 1.0, 1.0, 1.0);
    l = grid_size / 4;
    t = l / 12;
    
     for (i = 0; i < grid_size; i += l) {
    	//TODO:DONE Redo for GLES
      /*glBegin(GL_QUADS);
      for (j = 0; j < grid_size; j += l) {
        glTexCoord2i(0, 0);
        glVertex2i(i, j);
        glTexCoord2i(t, 0);
        glVertex2i(i + l, j);
        glTexCoord2i(t, t);
        glVertex2i(i + l, j + l);
        glTexCoord2i(0, t);
        glVertex2i(i, j + l);
      }
      glEnd();*/
    	 
    	 for (j = 0; j < grid_size; j += l) {
    		 //draw_textured_rectangle_size2vi(0,0,t,t,i, j,i + l, j + l);
    		 
    		 FillVertex2vx(texts[0],0,0);
			 FillVertex2vx(verts[0],i,j);
			 
			 FillVertex2vx(texts[1],t,0);
			 FillVertex2vx(verts[1],i + l, j);
			 
			 FillVertex2vx(texts[2],t, t);
			 FillVertex2vx(verts[2],i + l, j + l);
			 
			 FillVertex2vx(texts[3],t, t);
			 FillVertex2vx(verts[3],i + l, j + l);
			 
			 FillVertex2vx(texts[4],0, t);
			 FillVertex2vx(verts[4],i, j + l);
			 
			 FillVertex2vx(texts[5],0,0);
			 FillVertex2vx(verts[5],i,j);
			 
			 glVertexPointer	(2,GL_SHORT,0,verts); 
			 glTexCoordPointer	(2,GL_SHORT,0,texts);

			 glDrawArrays( GL_TRIANGLES , 0, 6 );
    		 
			}	 
    }
   
    glDisable(GL_TEXTURE_2D);
    return grid_size * grid_size;
}

void drawFloorGrid(int grid_size,  int line_spacing, 
                   float line_color[4], float square_color[4]) {
  int i, j;
  
  gl2gles_vertex3vx verts[4];
  
  gl2gles_color trail_tops[4];
  
  //TODO:DONE redo for gles
  /*glColor3fv(line_color);
  
  glFogfv(GL_FOG_COLOR, square_color);
  glFogi(GL_FOG_MODE, GL_LINEAR);
  glFogi(GL_FOG_START, 100);
  glFogi(GL_FOG_END, 350);

  glEnable(GL_FOG);

  glBegin(GL_LINES);
  for (i = 0; i < grid_size; i += line_spacing) {
    for (j = 0; j < grid_size; j += line_spacing) {
      glVertex3i(i, j, 0);
      glVertex3i(i + line_spacing, j, 0);
      glVertex3i(i, j, 0);
      glVertex3i(i, j + line_spacing, 0);
    }
  }
  glEnd();

  glDisable(GL_FOG);*/
  
  glDisableClientState (GL_TEXTURE_COORD_ARRAY);
  
  glDisableClientState (GL_NORMAL_ARRAY);  
  glEnableClientState (GL_VERTEX_ARRAY);
  glEnableClientState (GL_COLOR_ARRAY);
  
  glColor3fv(line_color);
    //TODO: Renable fog
    /*glFogfv(GL_FOG_COLOR, square_color);
    glFogx(GL_FOG_MODE, GL_LINEAR);
    glFogx(GL_FOG_START, 100);
    glFogx(GL_FOG_END, 350);

    glEnable(GL_FOG);*/

    
  for(i=0;i<4;i++){
	  FillColor4vf(trail_tops[i],line_color[0],line_color[1],line_color[2],line_color[3]);
  }
    //glBegin(GL_LINES);
    for (i = 0; i < grid_size; i += line_spacing) {
      for (j = 0; j < grid_size; j += line_spacing) {
    	  
  
    	  FillVertex3vx(verts[0],i,j,0);
    	  FillVertex3vx(verts[1],i + line_spacing, j, 0);
    	  FillVertex3vx(verts[2],i,j,0);
    	  FillVertex3vx(verts[3],i, j + line_spacing, 0);
    	  
    	  glVertexPointer(3,GL_SHORT,0, verts);
    	  glColorPointer(4,GL_FLOAT,0,trail_tops);

    	  glDrawArrays( GL_LINES , 0, 4 );
    	  
    	  //draw_rectangle_lines3vx(i,j,i + line_spacing,j + line_spacing,50);
    	  
        //glVertex3i(i, j, 0);
        //glVertex3i(i + line_spacing, j, 0);
        //glVertex3i(i, j, 0);
        //glVertex3i(i, j + line_spacing, 0);
    	  
    	  //draw_rectangle_lines3vx(i,j);
    	  
      }
    }
    //glEnd();

    glDisable(GL_FOG);
  
}
