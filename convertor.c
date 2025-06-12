#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
void printLine()
{
	printf("\t\t\t\t================================================\n");
}
void welcomeScreen()
{
	printLine();
	printf("\t\t\t\t         NUMBER SYSTEM CONVERTOR         \n");
	printLine();
	printf("\n\t\t\t\t        DEVELOPED BY: MANEEHA TARIQ       \n");
	printf("\t\t\t\t        ROLL NO: BSEF24M046             \n");
	printf("\t\t\t\t          SEMESTER PROJECT                \n");
	printLine();
}
void logConversion(char input[], char result[])
{
	FILE* fp = fopen("conversion.txt", "a");
	if (fp != NULL)
	{
		fprintf(fp, "Input: %s -> Result: %s\n", input, result);
	}
	fclose(fp);
}
void viewLog()
{
	FILE* fp = fopen("conversion.txt", "r");
	if (fp == NULL)
	{
		printf("\n\tNo logs found.\n");
		return;
	}
	char ch;
	printf("\n\t-----Conversion History-----\n\n");
	while ((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}
	fclose(fp);
}
void clearLog()
{
	FILE* fp = fopen("conversion.txt", "w");
	if (fp != NULL)
	{
		fclose(fp);
		printf("\n\t       Conversion history cleared successfully.\n");
	}
	else
	{
		printf("\n\t   Unable to clear log file.\n");
	}
}
//  ---- CONVERSION FUNCTIONS: BINARY ----
long long binaryToDecimal(unsigned long long binary)
{
	long long decimal = 0;
	int i = 0;
	while (binary > 0)
	{
		int digit = binary % 10;
		if (digit != 0 && digit != 1)
		{
			printf("\n\t   Invalid binary digit\n");
			return -1;
		}
		decimal += digit * pow(2, i);
		binary /= 10;
		i++;
	}
	return decimal;
}
long long binaryToOctal(unsigned long long binary)
{
	long long decimal = binaryToDecimal(binary);
	if (decimal == -1)
	{
		return -1;
	}
	long long octal = 0, place = 1;
	while (decimal > 0)
	{
		octal += (decimal % 8) * place;
		decimal /= 8;
		place *= 10;
	}
	return octal;
}
void binaryToHexa(unsigned long long binary)
{
	long long decimal = binaryToDecimal(binary);
	if (decimal == -1)
	{
		printf("\n\tConversion failed\n");
		return;
	}
	char hex[50];
	int i = 0;
	if (decimal == 0)
	{
		printf("0\n");
		return;
	}
	while (decimal > 0)
	{
		int rem = decimal % 16;
		if (rem < 10)
		{
			hex[i] = rem + '0';
		}
		else
		{
			hex[i] = rem - 10 + 'A';
		}
		decimal /= 16;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", hex[j]);
	}
	printf("\n");
}
//  ---- CONVERSION FUNCTIONS : DECIMAL ----
void decimalToBinary(int decimal)
{
	if (decimal == 0)
	{
		printf("0\n");
		return;
	}
	if (decimal < 0)
	{
		printf("-");
		decimal = -decimal;
	}
	int binary[32], i = 0;
	while (decimal > 0)
	{
		binary[i] = decimal % 2;
		decimal /= 2;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%d", binary[j]);
	}
	printf("\n");
}
void decimalToOctal(int decimal)
{
	if (decimal == 0)
	{
		printf("0\n");
		return;
	}
	if (decimal < 0)
	{
		printf("-");
		decimal = -decimal;
	}
	char octal[50];
	int i = 0;
	while (decimal > 0)
	{
		octal[i] = (decimal % 8) + '0';
		decimal /= 8;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", octal[j]);
	}
	printf("\n");
}
void decimalToHexa(int decimal)
{
	if (decimal == 0)
	{
		printf("0\n");
		return;
	}
	if (decimal < 0)
	{
		printf("-");
		decimal = -decimal;
	}
	char hex[50];
	int i = 0;
	while (decimal > 0)
	{
		int rem = decimal % 16;
		if (rem < 10)
		{
			hex[i] = rem + '0';
		}
		else
		{
			hex[i] = rem - 10 + 'A';
		}
		decimal /= 16;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", hex[j]);
	}
	printf("\n");
}
//  ---- CONVERSION FUNCTIONS : OCTAL ----
long long octalToDecimal( int octal)
{
	int isNegative = 0;
	if (octal < 0)
	{
		isNegative = 1;
		octal = -octal;
	}
	long long decimal = 0, i = 0;
	while (octal > 0)
	{
		int digit = octal % 10;
		if (digit < 0 || digit>7)
		{
			printf("\n\t   Invalid octal digit\n");
			return -1;
		}
		decimal += digit * pow(8, i);
		octal /= 10;
		i++;
	}
	if (isNegative)
	{
		decimal = -decimal;
	}
	return decimal;
}
void octalToBinary( int octal)
{
	int decimal = octalToDecimal(octal);
	if (decimal != -1)
	{
		decimalToBinary(decimal);
	}
}
void octalToHexa( int octal)
{
	int decimal = octalToDecimal(octal);
	if (decimal != -1)
	{
		decimalToHexa(decimal);
	}
}
//  ---- CONVERSION FUNCTIONS : HEXADECIMAL ----
int hexToDecimal(char hex[])
{
	int decimal = 0, i = 0, value;
	while (hex[i] != '\0')
	{
		char ch = hex[i];
		if (ch >= '0' && ch <= '9')
		{
			value = ch - '0';
		}
		else if (ch >= 'A' && ch <= 'F')
		{
			value = ch - 'A' + 10;
		}
		else if (ch >= 'a' && ch <= 'f')
		{
			value = ch - 'a' + 10;
		}
		else
		{
			printf("\n\t    Invalid hex digit %c\n", ch);
			return -1;
		}
		decimal = decimal * 16 + value;
		i++;
	}
	return decimal;
}
void hexaToBinary(char hex[])
{
	int decimal = hexToDecimal(hex);
	if (decimal == -1)
	{
		printf("\n\tConversion not possible due to invalid hex digit\n");
		return;
	}
	else
	{
		decimalToBinary(decimal);
	}
}
void hexaToOctal(char hex[])
{
	int decimal = hexToDecimal(hex);
	if (decimal == -1)
	{
		printf("\n\tConversion not possible due to invalid hex digit\n");
		return;
	}
	else
	{
		decimalToOctal(decimal);
	}
}
// ---- MAIN INTERFACE ----
void startInterface()
{
	int choice, decimal, oct;
	unsigned long long binary;
	char hex[50];
	welcomeScreen();

	while (1)
	{
		printf("\n\t ----- Number System Convertor -----\n");
		printf("\t1.  Binary to Decimal\n");
		printf("\t2.  Binary to Octal\n");
		printf("\t3.  Binary to Hexadecimal\n");
		printf("\t4.  Decimal to Binary\n");
		printf("\t5.  Decimal to Octal\n");
		printf("\t6.  Decimal to Hexadecimal\n");
		printf("\t7.  Octal to Decimal\n");
		printf("\t8.  Octal to Binary\n");
		printf("\t9.  Octal to Hexadecimal\n");
		printf("\t10. Hexadecimal to Decimal\n");
		printf("\t11. Hexadecimal to Octal\n");
		printf("\t12. Hexadecimal to Binary\n");
		printf("\t13. View Conversion Log\n");
		printf("\t14. Clear Conversion Log\n");
		printf("\t15. Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d", &choice);

		char inputStr[100], resultStr[100];
		char again;
		switch (choice)
		{
		case 1:
			do 
			{
				
					printf("\n\tEnter binary number: ");
					scanf("%llu", &binary);
					long long result = binaryToDecimal(binary);
					printf("\tDecimal: %lld", result);
					printf("\n");

					sprintf(inputStr, "%llu", binary);
					sprintf(resultStr, "%lld", result);
					logConversion(inputStr, resultStr);
					printf("\n\tDo you want to try again? (y/n): ");
					scanf(" %c", &again);
			} while (again == 'Y' || again == 'y');
			break;
		case 2:
		do
		{
			printf("\n\tEnter binary number: ");
			scanf("%llu", &binary);
			long long result = binaryToOctal(binary);
			printf("\tOctal: %lld", result);
			printf("\n");

			sprintf(inputStr, "%llu", binary);
			sprintf(resultStr, "%lld", result);
			logConversion(inputStr, resultStr);
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 3:
		do
		{
			printf("\n\tEnter binary number: ");
			scanf("%llu", &binary);
			printf("\tHexadecimal:");
			binaryToHexa(binary);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 4:
		do
		{
			printf("\n\tEnter Decimal number: ");
			scanf("%d", &decimal);
			printf("\tBinary:");
			decimalToBinary(decimal);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		}while (again == 'Y' || again == 'y');
		break;
		case 5:
		do
		{
			printf("\n\tEnter Decimal number: ");
			scanf("%d", &decimal);
			printf("\tOctal:");
			decimalToOctal(decimal);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		}while (again == 'Y' || again == 'y');
		break;
		case 6:
		do
		{
			printf("\n\tEnter Decimal number: ");
			scanf("%d", &decimal);
			printf("\tHexadecimal:");
			decimalToHexa(decimal);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		}while (again == 'Y' || again == 'y');
		break;
		case 7:
		do
		{
			printf("\n\tEnter Octal number: ");
			scanf("%d", &oct);
			long long result = octalToDecimal(oct);
			printf("\tDecimal: %lld", result);
			printf("\n");

			sprintf(inputStr, "%d", oct);
			sprintf(resultStr, "%lld", result);
			logConversion(inputStr, resultStr);
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 8:
		do
		{
			printf("\n\tEnter Octal number: ");
			scanf("%d", &oct);
			printf("\tBinary:");
			octalToBinary(oct);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 9:
		do
		{
			printf("\n\tEnter Octal number: ");
			scanf("%d", &oct);
			printf("\tHexaDecimal:");
			octalToHexa(oct);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 10:
		do
		{
			printf("\n\tEnter HexaDecimal number: ");
			scanf("%s", hex);
			int result = hexToDecimal(hex);
			printf("\tDecimal: %d", result);
			printf("\n");

			sprintf(inputStr, "%s", hex);
			sprintf(resultStr, "%d", result);
			logConversion(inputStr, resultStr);
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 11:
		do
		{
			printf("\n\tEnter HexaDecimal number: ");
			scanf("%s", hex);
			printf("\tOctal: ");
			hexaToOctal(hex);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 12:
		do
		{
			printf("\n\tEnter HexaDecimal number: ");
			scanf("%s", hex);
			printf("\tBinary: ");
			hexaToBinary(hex);
			printf("\n");
			printf("\n\tDo you want to try again? (y/n): ");
			scanf(" %c", &again);
		} while (again == 'Y' || again == 'y');
		break;
		case 13:
		{
			viewLog();
			break;
		}
		case 14:
		{
			clearLog();
			break;
		}
		case 15:
		{
			printLine();
			printf("\t\t\t\t           THANK YOU FOR USING THE CONVERTOR!    \n");
			printLine();
			return;
		}
		default:
		{
			printf("\n\t   Invalid choice.Please Try again.\n");
		}
		}
	}
}
int main()
{
	startInterface();
}
