// beep.cpp: 主项目文件。

#include "stdafx.h"

#include "dos.h"

#define MUSIC_BPM 95
#define MUSIC_LEN 194
#define MUSIC_NAME "小酒窝"
#define MUSIC_LYRICS "王雅君"
#define MUSIC_COMPOSER "林俊杰"
#define MUSIC_SINGER "林俊杰"
#define CROTCHET_DURATION 60000 / MUSIC_BPM

using namespace System;

enum pitch {
	d1 = 262,
	d1_ = 277,
	d2 = 294,
	d2_ = 311,
	d3 = 330,
	d4 = 349,
	d5 = 392,
	d5_ = 415,
	d6 = 440,
	d6_ = 466,
	d7 = 494,
	z1 = 523,
	z1_ = 554,
	z2 = 578,
	z2_ = 622,
	z3 = 659,
	z4 = 698,
	z4_ = 740,
	z5 = 784,
	z5_ = 831,
	z6 = 880,
	z6_ = 932,
	z7 = 988,
	g1 = 1046,
	g1_ = 1109,
	g2 = 1175,
	g2_ = 1245,
	g3 = 1318,
	g4 = 1397,
	g4_ = 1480,
	g5 = 1568,
	g5_ = 1661,
	g6 = 1760,
	g6_ = 1865,
	g7 = 1976,
	ya = 0
};

enum duration {
	semiqu = CROTCHET_DURATION / 4, //十六分音符

	quaver = CROTCHET_DURATION / 2, //八分音符
	quaved = CROTCHET_DURATION / 2 + CROTCHET_DURATION / 4, //八分附点音符

	crotch = CROTCHET_DURATION, //四分音符
	cro_se = CROTCHET_DURATION + CROTCHET_DURATION / 4, //四分 + 十六分连音音符
	crotcd = CROTCHET_DURATION + CROTCHET_DURATION / 2, //四分附点音符
	crotdd = CROTCHET_DURATION + CROTCHET_DURATION / 2 + CROTCHET_DURATION / 4, //四分双附点音符

	minims = CROTCHET_DURATION * 2, //二分音符
	min_qu = CROTCHET_DURATION * 2 + CROTCHET_DURATION / 2, //二分 + 八分连音音符
	minimd = CROTCHET_DURATION * 3, //二分附点音符

	semibr = CROTCHET_DURATION * 4, //全音符
	semibd = CROTCHET_DURATION * 6 //全音附点音符
};


struct music_score
{
	enum pitch _pitch;
	enum duration _duration;
};

//int main(array<System::String ^> ^args)
int main()
{
	int music_len = MUSIC_LEN;
	//Console::WriteLine(L"{0:s}\n作词 {1:s} 作曲：{2:s}\n演唱：{3:s}\n", MUSIC_NAME, MUSIC_LYRICS, MUSIC_COMPOSER, MUSIC_SINGER);
	printf("%s\n作词 %s 作曲：%s\n演唱：%s\n", MUSIC_NAME, MUSIC_LYRICS, MUSIC_COMPOSER, MUSIC_SINGER);

	struct music_score _music_score[MUSIC_LEN] = {
		{z3,crotcd}, {z3,quaver}, {z4,crotch}, {z3,quaver}, {z2,quaver}, //5
		{z2,crotcd}, {z2,quaver}, {z5,crotch}, {z2,quaver}, {z1,quaver}, //10
		{z1,crotcd}, {z1,quaver}, {z6,crotch}, {z5,crotch}, //14
		{z3,crotdd}, {z4,semiqu}, {z3,semiqu}, {z2,semiqu}, {z2, minims}, //19
		{z3,crotcd}, {z3,quaver}, {z4,crotch}, {z5,quaver}, {z3,quaver}, //24
		{z5,crotcd}, {z5,quaver}, {g2,crotch}, {z7,quaver}, {g1,quaver}, //29
		{g1,minims}, {g1,quaver}, {z7,quaver}, {z6,quaver}, {z7,quaver}, //34
		{g1,crotcd}, {z7,quaver}, {g1,minims}, //37
		{g1,quaver}, {z7,quaver}, {g1,quaver}, {z7,quaver}, {g1,crotch}, {z3,quaver}, {z5,quaver}, //44
		{z5,min_qu}, {z6,quaver}, {z7,quaver}, //47
		{g1,quaver}, {z7,quaver}, {g1,quaver}, {z7,quaver}, {g1,crotch}, {g2,crotch}, {g3,crotch}, //54
		{g3,minimd}, {z6,quaver}, {z7,quaver}, //57
		{g1,quaver}, {z7,quaver}, {g1,quaver}, {z7,quaver}, {g1,crotch}, {g3,crotch}, //63
		{z7,quaver}, {z6,quaver}, {z7,quaver}, {z6,quaver}, {z7,quaver}, {z5,quaver}, {z5,quaver}, {g1,quaver}, //71
		{g1,minims}, {g3,quaved}, {g4,semiqu}, {g4,quaver}, {g3,quaver}, //76
		{g2,minims}, {ya,quaver}, {z5,quaver}, {g1,quaver}, {g2,quaver}, //81
		{g3,quaver}, {g1,quaver}, {g1,quaver}, {z5,quaver}, {z5,crotch}, {z5,quaver}, {g3,quaver}, //88
		{g2,quaver}, {g3,quaver}, {g2,quaver}, {g1,quaver}, {z5,quaver}, {z5,quaver}, {z6,quaver}, {z7,quaver}, //96
		{g1,quaver}, {z6,quaver}, {z6,quaver}, {z3,quaver}, {z3,crotch}, {ya,quaver}, {z7,quaver}, //103
		{g1,quaver}, {z7,quaver}, {g1,quaver}, {g2,quaver}, {z6,quaver}, {z5,quaver}, {z5,crotch}, //110
		{z6,crotch}, {z5,quaver}, {z6,quaver}, {z7,crotch}, {g3,quaver}, {g4,quaver}, //116
		{g3,quaver}, {g4,quaver}, {g3,quaver}, {g2,quaver}, {g2,quaver}, {g1,crotch}, {z5,quaver}, //123
		{z5,quaver}, {z4,quaver}, {z4,quaver}, {g1,quaver}, {g1,quaver}, {g3,quaver}, {g3,quaver}, {g1,quaver}, //131
		{g2,minims}, {ya,quaver}, {z5,quaver}, {g1,quaver}, {g2,quaver}, //136
		{g3,quaver}, {g1,quaver}, {g1,quaver}, {z5,quaver}, {z5,crotch}, {z5,quaver}, {g3,quaver}, //143
		{g2,quaver}, {g3,quaver}, {g2,quaver}, {g1,quaver}, {z5,quaver}, {z5,quaver}, {z6,quaver}, {z7,quaver}, //151
		{g1,quaver}, {z6,quaver}, {z6,quaver}, {z3,quaver}, {z3,crotch}, {z3,quaver}, {z7,quaver}, //158
		{g1,quaver}, {z7,quaver}, {g1,quaver}, {g2,quaver}, {z6,quaver}, {z5,quaver}, {z5,crotch}, //165
		{z6,quaver}, {z7,quaver}, {g1,quaver}, {g2,crotch}, {g3,quaver}, {g4,quaver}, //171
		{g3,quaver}, {g4,quaver}, {g2,quaver}, {g1,quaver}, {g2,quaver}, {g1,quaver}, {g1,crotch}, //178
		{g2,quaver}, {g1,quaver}, {g2,quaver}, {z6,quaver}, {g1,crotch}, {g2,quaver}, {g1,quaver}, //185
		{g1,semibr}, //186
		{g2,quaver}, {g1,quaver}, {g2,quaver}, {z6,quaver}, {z7,crotch}, {z7,quaver}, {g1,quaver}, //193
		{g1,semibr}, //194
	};

	struct music_score *music_note;
	music_note = _music_score;

	while (music_len--)
	{
		printf("%d %d\n", music_note->_pitch, music_note->_duration);
		Beep(music_note->_pitch, music_note->_duration);
		music_note++;
	}
	system("pause");
	return 0;
}