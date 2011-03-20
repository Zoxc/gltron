#include "CustomMSDLMainObs.h"
#include "native_bridge.h"

extern CustomMSDLMainObs *cmmoControler;

extern "C"{
char getDecimalChar(void)
{
	return cmmoControler->getDecimalChars();
	
}
}
