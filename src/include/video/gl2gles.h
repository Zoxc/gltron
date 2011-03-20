#ifndef __GL2GLES_H__
#define __GL2GLES_H__

#include <GLES/gl.h>


#define glColor4fv(color_4v) glColor4f(color_4v[0],color_4v[1],color_4v[2],color_4v[3])
#define glColor3fv(color_3v) glColor4f(color_3v[0],color_3v[1],color_3v[2],1.0f)
#define glColor3f(c1,c2,c3) glColor4f(c1,c2,c3,1.0f)
//TODO: check this!
#define glColor3ubv(color_3v) glColor4x(color_3v[0],color_3v[1],color_3v[2],255)
#define glColor3d(c1,c2,c3) glColor3f(c1,c2,c3)

//Floating
#define FillVertex2v(vert,x1,y1) {vert.x=x1;vert.y=y1;}
#define FillVertex3v(vert,x1,y1,z1) {vert.x=x1;vert.y=y1;vert.z=z1;}

//Decimal
#define FillVertex3vx(vert,x1,y1,z1) {vert.x=x1;vert.y=y1;vert.z=z1;}
#define FillVertex2vx(vert,x1,y1) FillVertex2v(vert,x1,y1)

//Color
#define FillColor4vf(col,r1,g1,b1,a1){col.r=r1;col.g=g1;col.b=b1;col.alpha=a1;}


#ifdef cosf
#undef cosf
#endif

#define cosf cos
#define sinf sin
#define sqrtf sqrt
#define tanf tan
#define acosf acos
#define floorf floor
#define fabsf fabs

#ifdef __cplusplus
extern "C"{
#endif	

typedef struct{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	
}gl2gles_vertex3v;

typedef struct{
	GLfloat x;
	GLfloat y;
	
}gl2gles_vertex2v;


typedef struct{
	GLshort x;
	GLshort y;
	GLshort z;
	
}gl2gles_vertex3vx;


typedef struct{
	GLshort x;
	GLshort y;
	
}gl2gles_vertex2vx;

typedef struct{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat alpha;
}gl2gles_color;
	
void draw_textured_rectangle2v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);

void draw_textured_rectangle_size2vf(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1,GLfloat xtex0,GLfloat ytex0,GLfloat xtex1,GLfloat ytex1);

void draw_textured_rectangle_size2vi(GLshort x0, GLshort y0, GLshort x1, GLshort y1,GLshort xtex0,GLshort ytex0,GLshort xtex1,GLshort ytex1);

void draw_rectangle2v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);

void draw_rectangle3v(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z);

void draw_rectangle_lines3vx(GLuint x0,GLuint y0,GLuint x1, GLuint y1, GLuint z);


#ifdef __cplusplus
}
#endif	



#endif
