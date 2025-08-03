/* aiac one (and only) source file */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mod(float innum1, float innum2, float* ptrres);
void runaudio();

float number1, number2, result;
char signe;

int main(void){
	
	printf("aiac is a calculator\n");
	printf("TYPE 0 0 h OR h FOR HELP\n");
	
	while (1) {
		result = 0;
		number1 = 0;
		number2 = 0;
		printf("? ");
		scanf("%f %f\n", &number1, &number2);
		scanf(" %c", &signe);

		if (number1 == 0 | number2 == 0 && signe == '/') { printf("ILLEGAL OPERATION\n"); number1 = 0; number2 = 0; signe = '+'; }

		if (signe == '+') { result = number1 + number2; }
		else if (signe == '-') { result = number1 - number2; }
		else if (signe == '*') { result = number1 * number2; }
		else if (signe == '/') { result = number1 / number2; }
		else if (signe == 'q') { exit(0); }
		else if (signe == 's') { result = sqrt(number1); }
		else if (signe == 'c') { result = cos(number1 * PI / 180); }
		else if (signe == 'i') { result = sin(number1 * PI / 180); }
		else if (signe == 't') { result = tan(number1 * PI / 180); }
		else if (signe == '%') { mod(number1, number2, &result); }
		else if (signe == 'a') { runaudio(); }
		else if (signe == 'h') { printf("SYNTAX: <OP1> <OP2> <PARAMETER>\n==PARAMETERS==\n+ ADDITION\n- SUBSTRATION\n* MULTIPLICATION\n/ DIVISION\n%% MOD\ns SQUARE-ROOT\nc COS\ni SIN\nt TAN\nq QUIT\n== ==\nNOTE: FOR S,C,I,T , ONLY <OP1> IS USED , <OP2> CAN BE LEAVED TO 0\nNOTE 2: C,I,T ARE IN DEGREES\n"); }

		else { printf("ILLEGAL PARAMETER\n"); }

		printf("%f\n", result);
	}
}

void mod(float innum1, float innum2, float* ptrres) {
	int intnum1 = (int)innum1;
	int intnum2 = (int)innum2;
	*ptrres = intnum1 % intnum2;
}

void runaudio(){
	char* BINARY = "aplay"; /* define the binary name of aplay (or any player) */
	char filename[256];
	char command[sizeof(filename) + sizeof(BINARY) + 2];
	printf("Type the name/path of the audio(WAVE) file: ");
	scanf("%255s", filename);
	snprintf(command, sizeof(command), "%s %s", BINARY, filename); /*we better be safe (although scanf already checks the size of the imput to avoid any buffer overflow) */
	system(command);
}
