//Si includono le librerie per il corretto funzionamento del programma

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
//Dichiarazione delle variabili sia intere che array char
time_t  tempo;
char stringa[128];
int r=0;
int counts,countc;
char c,s;
char passwordc[128];
char plain[128];
int lchiave;
int lstringa;
// richiamo delle funzioni per poter essere usate all'interno del main
void inserimeto_chiave();
void random_key();


int main(){
//si chiede all'utente di inserire la strinfa che si vuole cifrare
printf("inserire la stringa che si vuole cifrare (max 128): \n");
fgets(stringa, 128, stdin);
lstringa=strlen(stringa);
printf("|**********************************|\n");
printf("|scegliere come procedere:         |\n");
printf("|inserire una chiave da tastiera(1)|\n");
printf("|generarne una in modo casuale(2)  |\n");
printf("|**********************************|\n");
//ciclo per verificare che venga digitato il numero 1 o 2
do{
  printf("digitare: ");
scanf("%d",&r);

if (r==1) {

  inserimeto_chiave();
}
    else if(r==2){
random_key();

          }
          else{printf("valore non valido\n");}
        }while(r!=1&&r!=2);
        }

// funzione void che non ritorna valori per l'iserimento della chiave da tastiera
void inserimeto_chiave(){
int c;
do {
  c = getchar();
}while(c != '\n' && c != EOF);
char chiave[128];
do{
printf("inserire la chiave (max 128): \n");
fgets(chiave,128,stdin);



lchiave = strlen(chiave);

if(lchiave<lstringa){
  printf("è stata inserita una chiave più corta del testo\n");

}



}while(lchiave<lstringa);

//cicli per l'operazione di XOR
printf("la password cifrata è: ");
for (int i = 0; i <lchiave ; i++) {


   passwordc[i]= stringa[i]^chiave[i];
   printf("%x",passwordc[i]);
}
//stampo la stringa facendo l'operazione xor tra la password e la chiave
for (int j = 0; j < 128; j++) {
plain[j]=passwordc[j]^chiave[j];


}

//stampa delle stringhe ottenute
printf("\n");
printf("la password di partenza era: ");
puts(plain);

}
//funzione void per la gestione della chiave generata in modo casuale con la funzione rand
void random_key(){
char chiaverandom[lstringa];
srand((unsigned)time(&tempo));
for (int i = 0; i < lstringa; i++) {
   int rand_num = (rand() % (128-32+1)) + 32;

chiaverandom[i] = (char)(rand_num);
}

//cicli per l'operazione di XOR

for (int i = 0; i <strlen(chiaverandom); i++) {


   passwordc[i]= stringa[i]^chiaverandom[i];

}
//stampo la stringa facendo l'operazione xor tra la password e la chiave
for (int j = 0; j < 128; j++) {
plain[j]=passwordc[j]^chiaverandom[j];


}

//stampa delle stringhe ottenute
printf("la password cifrata è: ");
puts(passwordc);
printf("la chiave scelta è: ");
puts(chiaverandom);
printf("la password di partenza era: ");
puts(plain);
}
