/*
 * CustomMSDLMainObs.cpp
 *
 *  Created on: 17/10/2010
 *      Author: il030560
 */

#include "CustomMSDLMainObs.h"
#include <aknappui.h> 
#include <COEMAIN.H>
#include <APGTASK.H>
//#include <aknkeylock.h> 


CustomMSDLMainObs::CustomMSDLMainObs()
{
	m_aSdl = NULL;

}

CustomMSDLMainObs::~CustomMSDLMainObs()
{

}

void CustomMSDLMainObs::BringToFront()
{
	CCoeEnv* env = CCoeEnv::Static();
	if (env)
	{
		TApaTask task((STATIC_CAST(CEikonEnv*,env))->WsSession());
		task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
		task.SendToBackground();
		User::After(1000000);
		task.BringToForeground();
	}
}

TInt CustomMSDLMainObs::SDLMainEvent(TInt aEvent, TInt aParam, CSDL* aSdl)
{
	if(aEvent==MSDLMainObs::ESDLCreated)
	{
		
		m_aSdl=aSdl;
		CCoeEnv* env = CCoeEnv::Static();
					if(env)
					{
						if(env->AppUi())
						{
							CAknAppUiBase* appUiBase = REINTERPRET_CAST( CAknAppUiBase*, env->AppUi() );
							appUiBase->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
						
						}
						
						CEikonEnv::Static()->WsSession().ComputeMode( RWsSession::EPriorityControlDisabled );
						CEikonEnv::Static()->RootWin().EnableReceiptOfFocus( ETrue );
					
						    
						TApaTask task((STATIC_CAST(CEikonEnv*,env))->WsSession());
						task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());

						task.BringToForeground();
					}
				
		
	}
	return 0;
}

char CustomMSDLMainObs::getDecimalChars()
{
	TLocale locale;
	TUint temp = (TUint)locale.DecimalSeparator();
	return (char)temp;
	
}
