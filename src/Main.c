#include "/home/codeleaded/System/Static/Library/WindowEngine.h"
#include "/home/codeleaded/System/Static/Library/AudioPlayer.h"
#include "/home/codeleaded/System/Static/Library/FT.h"

Vector ffts;
AudioPlayer ap;

void Setup(AlxWindow* w){
	ap = AudioPlayer_New();
	AudioPlayer_Start(&ap);

	ffts = Vector_New(sizeof(FS));
}
void Update(AlxWindow* w){
	for(int i = 0;i<ffts.size;i++){
		FS* fs = (FS*)Vector_Get(&ffts,i);
		FS_Free(fs);
	}
	Vector_Clear(&ffts);
	
	if(ap.output.size > 0){
		for(int i = 0;i<ap.a.numChannels;i++){
			FS fft = FFT_CalcFS_I16_C((AudioSample*)ap.output.Memory,ap.output.size,ap.a.numChannels,i);
			Vector_Push(&ffts,&fft);
		}
	}
	
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

	const Pixel colors[] = { RED,GREEN,BLUE,YELLOW,WHITE };
	const size_t count = sizeof(colors) / sizeof(*colors);
	const float paddingX = 50.0f;
	const float paddingY = 50.0f;
	const float ChannelWidth = ap.a.numChannels > 0 ? GetWidth() / ap.a.numChannels : 1.0f;

	for(int i = 0;i<ffts.size;i++){
		FS* fs = (FS*)Vector_Get(&ffts,i);
		FS_RenderFreq(
			WINDOW_STD_ARGS,
			fs,
			0,fs->size,
			paddingX + i * ChannelWidth,paddingY,
			ChannelWidth - paddingX * 2.0f,GetHeight() - paddingY * 2,
			colors[i % count]
		);
	}
}
void Delete(AlxWindow* w){
	for(int i = 0;i<ffts.size;i++){
		FS* fs = (FS*)Vector_Get(&ffts,i);
		FS_Free(fs);
	}
	Vector_Free(&ffts);

	AudioPlayer_Free(&ap);
}

int main(){
    if(Create("Audio Player and FFT",2300,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}