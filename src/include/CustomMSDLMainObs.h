/*
 * CustomMSDLMainObs.h
 *
 *  Created on: 17/10/2010
 *      Author: il030560
 */

#include <sdlmain.h>
#ifndef CUSTOMMSDLMAINOBS_H_
#define CUSTOMMSDLMAINOBS_H_

class CustomMSDLMainObs: public MSDLMainObs
{
public:
	CustomMSDLMainObs();
	
	void BringToFront();
	char getDecimalChars();
	virtual TInt SDLMainEvent(TInt aEvent, TInt aParam, CSDL* aSdl);
	virtual ~CustomMSDLMainObs();
protected:
	CSDL* m_aSdl;
};

#endif /* CUSTOMMSDLMAINOBS_H_ */
