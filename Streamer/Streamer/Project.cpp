// Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern "C"
{
	// NOTE: Additional directory ..\zeranoe.com\dev\include gets to the files
	#include "libavcodec\avcodec.h"
}

#pragma comment(lib, "avcodec.lib")


int main()
{
	AVCodec *codec = avcodec_find_encoder_by_name("H264");
	printf("%d\n", codec);
	system("PAUSE");
    return 0;
}

