#include <eikstart.h>
#include <sdlmain.h>
#include <sdlepocapi.h>
#include <aknglobalnote.h>

#include "CustomMSDLMainObs.h"

CustomMSDLMainObs *cmmoControler;


/*
This file demonstrates how to change CSDL when using sdlexe.lib - i.e. if default flags are not
ok  - you dont have to use CSDL API directly, you can write this file add add it in to your S60 SDL 
compilation. Then you dont statically link  sdlmain.lib or  sdlmaint.lib libraries 
*/

GLREF_C TInt E32Main()
    {
	TInt iRet=0;
	
#ifdef __WINS__ 
	User::After(25000000);
#endif
	
/*	
	_LIT(KTxtLine1,"First line");
	_LIT(KTxtLine2,"Second line");
	_LIT(KButt1,"a");
	_LIT(KButt2,"b");

	TInt whichbutton(-1);
	TRequestStatus stat;

	RNotifier notifier;

	notifier.Connect();

	notifier.Notify(KTxtLine1,KTxtLine2,KButt1,KButt2,whichbutton,stat);


	User::WaitForRequest(stat);

	if (whichbutton==0)
	    {
	    // first button selected
	    }
	if (whichbutton==1)
	    {
	    // Second button selected
	    }

	notifier.Close();
*/
	
	
	iRet = SDLEnv::SetMain(SDL_main, CSDL::EEnableFocusStop | CSDL::EImageResizeZoomOut 
           | CSDL::EAutoOrientation/* | CSDL::EAllowImageResizeKeepRatio | CSDL::EDrawModeGdi*/,
           cmmoControler=new CustomMSDLMainObs(),0 /*SDLEnv::EParamQuery | SDLEnv::EEnableVirtualMouseMoveEvents*/);
	
	return iRet;
    }

    
