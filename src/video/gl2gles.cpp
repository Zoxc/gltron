#include "../include/video/gl2gles.h"


extern "C"{
void draw_textured_rectangle2v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
	static const GLfloat verts[6 * 2] = 
	{    
		 x0,  y0,      x1,  y0,  
		 x1,  y1,/*se*/x1,  y1,
		 x0,  y1,	   x0,  y0 
	}; 


	static const GLfloat texture[6 * 2] = 
	{    
		 0.0,  0.0,      1.0,  0.0, 
		 1.0,  1.0,/*se*/1.0,  1.0,
		 0.0,  1.0,	     0.0,  0.0
	};
	//glColor4f( 0.0f, 1.0f, 1.0f,1.0f ); 
	//glEnableClientState (GL_VERTEX_ARRAY);
	//glEnableClientState (GL_TEXTURE_COORD_ARRAY);

	glVertexPointer		(2,GL_FLOAT,0, verts); 
	glTexCoordPointer	(2,GL_FLOAT,0,texture);

	glDrawArrays( GL_TRIANGLES , 0, 6 );
}

/**
 * Floats
 * 2v vectors
 * 2v for Texture
 * */
void draw_textured_rectangle_size2vf(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1,GLfloat xtex0,GLfloat ytex0,GLfloat xtex1,GLfloat ytex1)
{
	static const GLfloat verts[6 * 2] = 
	{    
		 x0,  y0,      x1,  y0, 
		 x1,  y1,/*se*/x1,  y1,
		 x0,  y1,	   x0,  y0 
	}; 


	static const GLfloat texture[6 * 2] = 
	{    
		xtex0,  ytex0,      xtex1,  ytex0, 
		xtex1,  ytex1,/*se*/xtex1,  ytex1,
		xtex0,  ytex1,	    xtex0,  ytex0
	};
	//glColor4f( 0.0f, 1.0f, 1.0f,1.0f ); 
	//glEnableClientState (GL_VERTEX_ARRAY);
	//glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	//glEnableClientState (GL_COLOR_ARRAY);
	//glEnableClientState (GL_NORMAL_ARRAY);

	glVertexPointer		(2,GL_FLOAT,0, verts); 
	glTexCoordPointer	(2,GL_FLOAT,0,texture);

	glDrawArrays( GL_TRIANGLES , 0, 6 );
}

/**
 * Integers
 * 2v vectors
 * 2v for Texture
 * */
void draw_textured_rectangle_size2vi(GLshort x0, GLshort y0, GLshort x1, GLshort y1,GLshort xtex0,GLshort ytex0,GLshort xtex1,GLshort ytex1)
{
	static const GLshort verts[6 * 2] = 
	{    
		 x0,  y0,      x1,  y0, 
		 x1,  y1,/*se*/x1,  y1,
		 x0,  y1,	   x0,  y0 
	}; 


	static const GLshort texture[6 * 2] = 
	{    
		xtex0,  ytex0,      xtex1,  ytex0, 
		xtex1,  ytex1,/*se*/xtex1,  ytex1,
		xtex0,  ytex1,	    xtex0,  ytex0
	};
	//glColor4f( 0.0f, 1.0f, 1.0f,1.0f ); 
	//glEnableClientState (GL_VERTEX_ARRAY);
	//glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	//glEnableClientState (GL_COLOR_ARRAY);
	//glEnableClientState (GL_NORMAL_ARRAY);

	glVertexPointer		(2,GL_SHORT,0, verts); 
	glTexCoordPointer	(2,GL_SHORT,0,texture);
	
	
	
	glDrawArrays( GL_TRIANGLES , 0, 6 );
}


void draw_rectangle2v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
	
	static const GLfloat verts[6 * 2] = 
		{    
			 x0,  y0,      x1,  y0, 
			 x1,  y1,/*se*/x1,  y1,
			 x0,  y1,	   x0,  y0 
		}; 


		
		//glColor4f( 0.0f, 1.0f, 1.0f,1.0f ); 
		//glEnableClientState (GL_VERTEX_ARRAY);
		//glEnableClientState (GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(2,GL_FLOAT,0, verts); 

		glDrawArrays( GL_TRIANGLES , 0, 6 );
}



void draw_rectangle3v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z)
{
	
	static const GLfloat verts[6 * 3] = 
		{    
			 x0,  y0,  z,      x1,  y0,  z, 
			 x1,  y1,  z,/*se*/x1,  y1,  z,
			 x0,  y1,  z,	   x0,  y0,  z 
		}; 


		
		//glColor4f( 0.0f, 1.0f, 1.0f,1.0f ); 
		//glEnableClientState (GL_VERTEX_ARRAY);
		//glEnableClientState (GL_TEXTURE_COORD_ARRAY);

		glVertexPointer		(3,GL_FLOAT,0, verts); 

		glDrawArrays( GL_LINES , 0, 6 );
}


void draw_rectangle_lines3vx(GLuint x0,GLuint y0,GLuint x1, GLuint y1, GLuint z)
{
	static const GLuint verts[6 * 3] = 
			{    
				 x0,  y0,  z,      x1,  y0,  z, 
				 x1,  y1,  z,/*se*/x1,  y1,  z,
				 x0,  y1,  z,	   x0,  y0,  z 
			}; 
	
	glVertexPointer	(3,GL_UNSIGNED_SHORT,0, verts); 

	glDrawArrays( GL_LINES , 0, 6 );
	
}

}
