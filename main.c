/* aiac only (and only) source file */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923

void add(float innum1, float innum2, float* ptrres);
void sub(float innum1, float innum2, float* ptrres);
void mul(float innum1, float innum2, float* ptrres);
void div_(float innum1, float innum2, float* ptrres);
void mod(float innum1, float innum2, float* ptrres);

int main(void) {
	
	float number1, number2, result;
	char signe;

	printf("aiac is a calculator\n");
	printf("TYPE 0 0 h OR h FOR HELP\n");
	
	while (1) {
		result = 0;
		number1 = 0;
		number2 = 0;
		printf("? ");
		scanf_s("%f %f\n", &number1, &number2);
		scanf_s(" %c", &signe, 1);

		if (number1 == 0 | number2 == 0 && signe == '/') { printf("ILLEGAL OPERATION\n"); number1 = 0; number2 = 0; signe = '+'; }

		if (signe == '+') { add(number1, number2, &result); }
		else if (signe == '-') { sub(number1, number2, &result); }
		else if (signe == '*') { mul(number1, number2, &result); }
		else if (signe == '/') { div_(number1, number2, &result); }
		else if (signe == 'q') { exit(0); }
		else if (signe == 's') { result = sqrt(number1); }
		else if (signe == 'c') { result = cos(number1 * PI / 180); }
		else if (signe == 'i') { result = sin(number1 * PI / 180); }
		else if (signe == 't') { result = tan(number1 * PI / 180); }
		else if (signe == '%') { mod(number1, number2, &result); }
		else if (signe == 'h') { printf("SYNTAX: <OP1> <OP2> <PARAMETER>\n==PARAMETERS==\n+ ADDITION\n- SUBSTRATION\n* MULTIPLICATION\n/ DIVISION\n%% MOD\ns SQUARE-ROOT\nc COS\ni SIN\nt TAN\nq QUIT\n== ==\nNOTE: FOR S,C,I,T , ONLY <OP1> IS USED , <OP2> CAN BE LEAVED TO 0\nNOTE 2: C,I,T ARE IN DEGREES\n"); }

		else { printf("ILLEGAL PARAMETER\n"); }

		printf("%f\n", result);
	}
}

void add(float innum1, float innum2, float* ptrres) {
	*ptrres = innum1 + innum2;
}

void sub(float innum1, float innum2, float* ptrres) {
	*ptrres = innum1 - innum2;
}

void mul(float innum1, float innum2, float* ptrres) {
	*ptrres = innum1 * innum2;
}

void div_(float innum1, float innum2, float* ptrres) {
	*ptrres = innum1 / innum2;
}

void mod(float innum1, float innum2, float* ptrres) {
	int intnum1 = (int)innum1;
	int intnum2 = (int)innum2;
	*ptrres = intnum1 % intnum2;
}