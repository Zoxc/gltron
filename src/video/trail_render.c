#include "video/trail_geometry.h"
								 
void trailStatesNormal(Player *pPlayer, int texture) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	// glDisable(GL_TEXTURE_2D);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	//TODO: changed i to x
	glTexEnvx(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	{ 
		float black[] = { 0, 0, 0, 1 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
		//TODO: Redo for gles
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);
	}

	if(gSettingsCache.alpha_trails) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}

void trailStatesShadowed(void) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	// glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDisable(GL_LIGHTING);
}

void trailStatesRestore(void) {
	glDisable(GL_COLOR_MATERIAL);
	glCullFace(GL_BACK);
	glDisable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	//TODO: REdo for GLES
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void trailRender(TrailMesh *pMesh) {
	if(pMesh->iUsed == 0)
		return;
	
	glVertexPointer(3, GL_FLOAT, 0, pMesh->pVertices);
	glNormalPointer(GL_FLOAT, 0, pMesh->pNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, pMesh->pTexCoords);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, pMesh->pColors);

	checkGLError("texcoord pointer");

	glDrawElements(GL_TRIANGLES, pMesh->iUsed, GL_UNSIGNED_SHORT, pMesh->pIndices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	checkGLError("trail");
}
