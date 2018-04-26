//---------------------------------------------------------------------------
//
// Name:        main.cpp
// Author:      zatrax & sinaxin
// Created:     2018-04-25
// License:     MIT
// Description: Main file for calling the the OnkyoRi library. Please change
// 		the code below for the wanted one.
//
//---------------------------------------------------------------------------
#include <unistd.h>
#include "OnkyoRI.h"

int main()
{
	// Raspberry Pi pin based on WiringPi mode
	OnkyoRI onk = OnkyoRI(15);
	
	// Change 0x420 for the code wanted. 
	// See readme for code list.
	onk.send(0x420);
}
