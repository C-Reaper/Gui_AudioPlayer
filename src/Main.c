#include "/home/codeleaded/System/Static/Library/WindowEngine.h"
#include "/home/codeleaded/System/Static/Library/AudioPlayer.h"

AudioPlayer ap;

void Setup(AlxWindow* w){
	ap = AudioPlayer_New();
	AudioPlayer_Start(&ap);
}
void Update(AlxWindow* w){
	if(Stroke(ALX_KEY_W).PRESSED){
		AudioPlayer_Add(&ap,"./sound/coin.wav");
	}
	if(Stroke(ALX_KEY_S).PRESSED){
		AudioPlayer_Add(&ap,"./sound/beat.wav");
	}
	if(Stroke(ALX_KEY_A).PRESSED){
		AudioPlayer_Add(&ap,"./sound/endleveldone.wav");
	}
	if(Stroke(ALX_KEY_D).PRESSED){
		AudioPlayer_Add(&ap,"./sound/explosion.wav");
	}

	Clear(BLACK);

	//String str = String_Format("MI:%d",nMaxIterations);
	//CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.font,str.Memory,str.size,0.0f,0.0f,WHITE);
	//String_Free(&str);
}
void Delete(AlxWindow* w){
	AudioPlayer_Free(&ap);
}

int main(){
    if(Create("Audio Player",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}