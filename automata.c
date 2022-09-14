#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atoi2.c"

#define MAX_CADENA 100

int esDecimal(const char*);
int columnadecimal(int);
int esOctal(const char*);
int columnaoctal(int);
int esHexa(const char*);
int columnahexa(int);
char concatenarchar(char, char*);

int main(int argc, char *argv[]){
int a = esDecimal("123456789");
int a2 = esDecimal("1254ss2");
int a3 = esDecimal("02145");
int o = esOctal("01234567");
int o2= esOctal("01d24");
int o3 = esOctal("124");
int h = esHexa("0x12345ABCDEF");
int h2 = esHexa("0123456789ABCD");
int h3 = esHexa("214124asf");
int h4 = esHexa("124");
printf("Decimal 12: %d \nDecimal 1254ss2: %d \nDecimal 02145: %d \n",a, a2, a3);
printf("Octal 0215: %d \nOctal 01d24: %d \nOctal 124: %d \n", o, o2, o3);
printf("Hexa 0x12345ABCDEF: %d \nHexa 0123456789ABCD: %d \nHexa 214124asf: %d \nHexa 124:%d \n", h, h2, h3, h4);

char cadena[MAX_CADENA] = "12345&135&0124&0x1245F&51&0215&f32023f&25125&00"; //4 dec 3 oct 1 hexa

char c = cadena[0];
int i = 0;
char numero[MAX_CADENA] = "";
char vacio[MAX_CADENA] = "";
int decimales = 0;
int octales = 0;
int hexadecimales = 0;
while(c != '\0'){
   while(c != '&' && c != '\0'){
   strncat(numero, &c, 1);
   i++;
   c = cadena[i];
   }
   if(esDecimal(numero)) decimales++;
   else if(esOctal(numero)) octales++;
   else if(esHexa(numero)) hexadecimales++;
   printf("Numero: %s \n", &numero);
   i++;
   c = cadena[i];
   strcpy(numero, vacio);
}

printf("Cant Decimales: %d\nCant Octales: %d\nCant Hexadecimales: %d", decimales, octales, hexadecimales);


return 0;
}

int esDecimal(const char* cadena){
   static int tt[3][3] ={{1, 2, 2},
                         {1, 1, 2},
                         {2, 2, 2}};
   int e = 0;
   int i = 0;
   int c = cadena[0];
   while(c != '\0' && c != '&' && e != 2){
      e = tt[e][columnadecimal(c)];
      i++;
      c = cadena[i];
   }
   if (e == 2) return 0;
   return 1;
}

int columnadecimal(int c){
   c = cdae(c);
   if(c>0 && c<=9) return 0;
   else if(c == 0) return 1;
   else return 2;
}

int esOctal(const char* cadena){
   static int tt[3][3] ={{2, 1, 2},
                         {1, 1, 2},
                         {2, 2, 2}};
   int e = 0;
   int i = 0;
   int c = cadena[0];
   while(c != '\0' && c != '&' && e != 2){
      e = tt[e][columnaoctal(c)];
      i++;
      c = cadena[i];
   }
   if (e == 2) return 0;
   return 1;
}

int columnaoctal(int c){
   c = cdae(c);
   if(c>0 && c<=7) return 0;
   else if(c == 0) return 1;
   else return 2;
}

int esHexa(const char* cadena){
   static int tt[4][4] ={{1, 3, 3, 3},
                         {3, 2, 3, 3},
                         {2, 3, 2, 3},
                         {3, 3, 3, 3}};
   int e = 0;
   int i = 0;
   int c = cadena[0];
   while(c != '\0' && c != '&' && e != 2){
      e = tt[e][columnahexa(c)];
      i++;
      c = cadena[i];
   }
   if (e == 3) return 0;
   return 1;
}

int columnahexa(int c){
   if(c == 48) return 0;
   else if(c == 'x' || c == 'X') return 1;
   else if(c>48 && c<=57 || c>=65 && c<=70) return 2;
   else return 3;
}

