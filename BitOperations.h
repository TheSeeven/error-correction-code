#pragma once
#include <stdbool.h>
#include <math.h>
#define byte unsigned char 



static bool CheckBit(const byte b,unsigned const char pos) {
	if (b & (unsigned char)pow(2, pos)) return true;
	return false;}

static void SetBit(byte* b, int pos) { (*b) ^= (unsigned char)pow(2, pos); }

static unsigned int div(unsigned int a, unsigned int b) {
	if (a == 0) return 0;
	return a / b;}

static void DataCopy(byte* dest, byte* data,unsigned const int columns, unsigned const int rows) {
	unsigned int data_index = 0;
	for (unsigned int i = 0; i < (columns+1) * (rows+1); i++) {
		if (i%(columns+1)==0 || i<columns+1) {
			dest[i] = 0;
		}
		else
		{
			dest[i] = data[data_index];
			data_index++;
		}
	}
}


static byte* GetFormat(const byte*  data,  unsigned const columns,unsigned const rows ) {
	byte* data_wrapped = (byte*)malloc((rows+1) * (columns+1) * sizeof(byte));
	DataCopy(data_wrapped, data, columns, rows);

	for (unsigned int i = 0; i < rows * columns; i++)
	{
		for (unsigned bit = 0; bit < 8; bit++)
		{
			if (CheckBit(data[i], bit))
			{
				SetBit(&data_wrapped[(i%columns)+1], bit);
				SetBit(&data_wrapped[(columns+1)*(div(i,columns)+1)],0);
			}
		}
	}
	return data_wrapped;
}