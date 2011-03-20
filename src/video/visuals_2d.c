#include "video/video.h"
#include "game/game.h"



/* draw a 2d map */

void draw2D( Visual *d ) {
		float width, height;
		float border_left, border_bottom;
		int i,size_array,j;
		float glfX,glfY;
		gl2gles_vertex2v vertex2temp;
		gl2gles_vertex2v verts[6];
		gl2gles_vertex2v *pVerts = NULL;
		gl2gles_vertex3v fVerts[6];

		float aspect = (float)d->vp_w / (float)d->vp_h;
		if(d->vp_w / game2->grid.width < d->vp_h / game2->grid.height) {
				// black borders top/bottom
				width = game2->grid.width + 1.0f;
				height = width / aspect;
				border_bottom = (height - game2->grid.height) / 2;
				border_left = 0;
		} else {
				// black borders left/right
				height = game2->grid.height + 1.0f;
				width = height * aspect;
				border_left = (width - game2->grid.width) / 2;
				border_bottom = 0;
		}

		/*
		{
				static int foo = 0;
				if(!foo)
						printf("w,h: (%f,%f), border l/b: (%f,%f)\n",
									 width, height, border_left, border_bottom);
				foo = 1;
		}
		*/

		glViewport(d->vp_x, d->vp_y, d->vp_w, d->vp_h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//TODO: DONE redo for gles
		glOrthof(0, width, 0, height, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(border_left, border_bottom, 0);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		
		glEnableClientState (GL_VERTEX_ARRAY);
		
		//R.K. moved it higher otherwise it would crash on symbian
		glDisable(GL_LIGHTING);
		
		{
			float w = game2->grid.width;
			float h = game2->grid.height;

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			
			
			//TODO:DONE Redo for Gles
			/*glBegin(GL_QUADS);
			glColor4f(0.7f, 0.7f, 0.7f, 0.3f);
			glVertex2f(0, 0);
			glVertex2f(w, 0);
			glVertex2f(w, h);
			glVertex2f(0, h);
			glEnd();*/
			
			glColor4f(0.7f, 0.7f, 0.7f, 0.3f);
			//draw_rectangle2v(0,0,w,h);

			FillVertex2v(verts[0],0,0);
			
			FillVertex2v(verts[1],w,0);
			
			FillVertex2v(verts[2],w,h);
			
			FillVertex2v(verts[3],w,h);
			
			FillVertex2v(verts[4],0,h);
			
			FillVertex2v(verts[5],0,0);
			
			glVertexPointer	(2,GL_FLOAT,0,verts);  
			glDrawArrays( GL_TRIANGLES , 0, 6 );
		}
		
		
		// glDisable(GL_BLEND);
		glEnable(GL_BLEND);
		{
				float w = game2->grid.width;
				float h = game2->grid.height;
				//TODO: redo for gles
				/*glColor3f(1, 1, 1);
				glBegin(GL_LINE_LOOP);
				glVertex3f( 0, 0, 0 );
				glVertex3f( w, 0, 0 );
				glVertex3f( w, h, 0 );
				glVertex3f( 0, h, 0 );
				glEnd();*/
				
				glColor3f(1, 1, 1);
				FillVertex3v(fVerts[0],0,0,0);
				FillVertex3v(fVerts[1],w,0,0);
				FillVertex3v(fVerts[2],w,h,0);
				FillVertex3v(fVerts[3],0,h,0);
				FillVertex3v(fVerts[4],0,0,0);
				
				glVertexPointer(3, GL_FLOAT,0, fVerts);

				glDrawArrays(GL_LINE_LOOP, 0, 5);
				//draw_rectangle3v(0,0,w,h,1);
				
		}
		for(i = 0; i < game->players; i++) {
				Player *p = &game->player[i];
				PlayerVisual *pV = gPlayerVisuals + i;
				segment2* trail;
				float x, y;

				getPositionFromData(&x, &y, p->data);
				
				// fixme: check if trails vanish
        if (p->data->trail_height <= 0) {
          continue;
        }
        
        if (p->data->trail_height < TRAIL_HEIGHT) {
          /* 
             if player crashed but the trail hasn't disappeared yet, fade
             the trail on the 2d map as it disappears.
           */
          glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
          glColor4f(pV->pColorAlpha[0], pV->pColorAlpha[1], pV->pColorAlpha[2],
                    p->data->trail_height / TRAIL_HEIGHT);
        } else {
          glBlendFunc(GL_ONE, GL_ONE);
          //TODO:DONE redo for gles
          glColor3fv(pV->pColorAlpha);
        }
        
        glPointSize(2);
				//TODO: redo for gles
				/*glBegin(GL_POINTS);
				glVertex2f( x, y );
				glEnd();*/
			
		FillVertex2v(vertex2temp,x,y);
		glVertexPointer(2, GL_FLOAT,0, &vertex2temp);

		glDrawArrays(GL_POINTS, 0, 1);

		/*
		 glBegin(GL_LINES);
		 for(trail = p->data->trails; trail != p->data->trails + p->data->trailOffset; trail++)
		 {
		 glVertex2f(trail->vStart.v[0], 
		 trail->vStart.v[1]
		 );
		 glVertex2f(trail->vStart.v[0] + trail->vDirection.v[0], 
		 trail->vStart.v[1] + trail->vDirection.v[1]
		 );
		 }
		 if(trail != p->data->trails)
		 {
		 trail--;
		 glVertex2f(trail->vStart.v[0] + trail->vDirection.v[0], 
		 trail->vStart.v[1] + trail->vDirection.v[1]
		 );
		 glVertex2f( floorf(x), floorf(y));
		 }
		 else
		 {
		 glVertex2f(trail->vStart.v[0], 
		 trail->vStart.v[1]
		 );
		 glVertex2f( floorf(x), floorf(y));
		 } */

		size_array=(p->data->trailOffset+1)<<1;
		pVerts = (gl2gles_vertex2v *)malloc(sizeof(gl2gles_vertex2v)*size_array);
		
		for (trail = p->data->trails,j=0; trail != p->data->trails
				+ p->data->trailOffset; trail++,j+=2)
		{
			glfX=trail->vStart.v[0];
			glfY=trail->vStart.v[1];
			FillVertex2v(pVerts[j],glfX,glfY);
			FillVertex2v(pVerts[j+1],glfX+trail->vDirection.v[0],glfY+trail->vDirection.v[1]);
			
		}
		if (trail != p->data->trails)
		{
			trail--;
			
			FillVertex2v(pVerts[j-2],trail->vStart.v[0] + trail->vDirection.v[0],
					trail->vStart.v[1] + trail->vDirection.v[1]);
			FillVertex2v(pVerts[j-1],floorf(x), floorf(y));
		}
		else
		{
			
			FillVertex2v(pVerts[j],trail->vStart.v[0], trail->vStart.v[1]);
			FillVertex2v(pVerts[j+1],floorf(x), floorf(y));
		}
				
		glVertexPointer(2, GL_FLOAT,0, pVerts);

		glDrawArrays(GL_LINES, 0, size_array);
		
		free(pVerts);
		
#if 0
				// draw AI debug lines
				glColor3f(1,1,1);
				glVertex2f(p->ai->front.vStart.v[0],
									 p->ai->front.vStart.v[1]);
				glVertex2f(p->ai->front.vStart.v[0] + p->ai->front.vDirection.v[0],
									 p->ai->front.vStart.v[1] + p->ai->front.vDirection.v[1]);
				glColor3f(0,1,0);
				glVertex2f(p->ai->left.vStart.v[0],
									 p->ai->left.vStart.v[1]);
				glVertex2f(p->ai->left.vStart.v[0] + p->ai->left.vDirection.v[0],
									 p->ai->left.vStart.v[1] + p->ai->left.vDirection.v[1]);
				glColor3f(0,0,1);
				glVertex2f(p->ai->right.vStart.v[0],
									 p->ai->right.vStart.v[1]);
				glVertex2f(p->ai->right.vStart.v[0] + p->ai->right.vDirection.v[0],
									 p->ai->right.vStart.v[1] + p->ai->right.vDirection.v[1]);
				glColor3f(0,1,1);
				glVertex2f(p->ai->backleft.vStart.v[0],
									 p->ai->backleft.vStart.v[1]);
				glVertex2f(p->ai->backleft.vStart.v[0] + 
									 p->ai->backleft.vDirection.v[0],
									 p->ai->backleft.vStart.v[1] + 
									 p->ai->backleft.vDirection.v[1]);
#endif
				//TODO: REdo for gles
				//glEnd();
		}
		glDisable(GL_BLEND);
}
	
