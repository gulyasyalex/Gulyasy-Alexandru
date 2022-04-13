#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int GetPriority(char ch)
{
	switch (ch) {
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		return 2;
	default:
		return 0;
	}
}

void ReadFormula(unsigned char Fisier[30], unsigned char *s, unsigned char **val)
{
	FILE* f;
	unsigned char contor = -1 , valori[30] = { 0 };

	f = fopen(Fisier, "r");
	if (f == NULL){
		printf("Fisierul din care doriti sa cititi nu exista.");
	}
	else{
		fgets(s,30,f);
		for (; *s; ++s) *s = tolower(*s);									//minuscule
		while (!feof(f))
		{
			contor++;
			fgets(valori, 30, f);
			*(val + contor) = valori;
			
		}
		fclose(f);
	}

}

int main() 
{
	unsigned char formula[30], contor = 0;
	unsigned char fp[30] = { 0 }, contorFp = 0;
	unsigned char st[30] = { 0 }, contorSt = 0;
	unsigned char i;
	unsigned char valori[30];

	ReadFormula("FormaPoloneza.txt", formula, &valori);
	printf("-Case Insensitive!-");
	printf("\nAti introdus formula: %s", formula);

	//Forma Poloneza Post Fixata
	while (contor < strlen(formula))									//seteaza lungimea sirului
	{
		if (formula[contor]>='a' && formula[contor] <= 'z') {			//daca este litera intra direct in fp(forma poloneza)
			fp[contorFp++] = formula[contor];
		}
		else if (formula[contor] == ')') {	
																//daca este ) cauta in stiva cealalta ( si pune
			while (st[contorSt-1] != '(')									//operatorii aritmetici in fp(forma poloneza)
			{
				fp[contorFp++] = st[--contorSt];
				st[contorSt]='\0';
			}
			st[--contorSt] = '\0';
		}
		else if (formula[contor] == ' ') {}								//daca in sir se gasesc spatii goale atunci trece peste ele		
		else {
			if (GetPriority(formula[contor]) == 2) {					//daca gaseste + sau - verifica si transpune 
				i = contorSt;											//	* sau / in stiva

				while (contorSt > 0 && st[contorSt-1] != '(')			//parcurge pana la inceputul stivei daca nu exista (
				{														// sau pana la ) daca exista
				
					if (GetPriority(st[contorSt-1]) == 1) {
						fp[contorFp++] = st[--contorSt];
						st[contorSt] = '\0';
					}
					else {
						break;
					}
				}
				st[contorSt++] = formula[contor];
			}
			else {														//in rest pune * / si ( in stiva
				st[contorSt++] = formula[contor];
			}
		}
		contor++;
	}
	printf("\nForma Poloneza: ");
	for (i = 0; i < contorFp; i++)
	{
		printf("%c", fp[i]);
	}
	for (i = 0; i < strlen(valori); i++)
	{
		printf("%c", valori[i]);
	}
	_getch();
	return 0;
}