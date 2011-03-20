#include "Nebu_audio.h"

extern "C" {
#include "game/game.h"
#include "video/video.h" // 3d sound engine needs to know the camera's location!
}

extern "C" {


  void Audio_EnableEngine(void) {
	
  }

  void Audio_DisableEngine(void) {
   
    // printf("[audio] turning off engine sound\n");
  }

  void Audio_Idle(void) { 
   
  }

  void Audio_CrashPlayer(int player) {
   
  }

  void Audio_Init(void) {
    
  }

  void Audio_Start(void) {
   
  }

  void Audio_Quit(void) {
    
  }

  void Audio_LoadMusic(char *name) {
    
  }

  void Audio_PlayMusic(void) {
   
  }

  void Audio_StopMusic(void) {
  
  }

  void Audio_SetMusicVolume(float volume) {
  
  }
  
  void Audio_SetFxVolume(float volume) {
    
  }

  void Audio_StartEngine(int iPlayer) {
   
  }

  void Audio_StopEngine(int iPlayer) {
    
  }
 
  void Audio_LoadPlayers(void) {
    

  }

  void Audio_LoadSample(char *name, int number) {
   
  }
}
