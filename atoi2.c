int atoi2(char* numeros){
   int i = 0;
   int numero = 0;
   do {
      numero = (numero * 10) + numeros[i] - '0';
      i++;
      }
   while(numeros[i] != '\0');
   return numero;
}

int cdae(char n){ return n - '0'; }

