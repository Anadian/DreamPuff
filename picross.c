#include <stdio.h>

int main(int argc, char *argv[]){
	unsigned short col_rules[20][4] = {
		{1},
		{2},
		{2},
		{3},
		{4,3},
		{9},
		{10},
		{10,1},
		{10,2},
		{8,3,2},
		{8,2,3},
		{1,5,7},
		{2,3,2,2},
		{4,2,4},
		{10,3},
		{1,5,2},
		{2,2,2},
		{1,2,2},
		{5,2},
		{5,3}
	};
	unsigned long col_values[20][64];
	unsigned long i;
	for(i = 0; i < 1048576; i++){
		
