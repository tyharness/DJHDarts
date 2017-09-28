#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"djhdartsfunc.h"

/*------------------------------------------------------------------------------------------------------------*/
bool printhelp(){

system("clear"); 

char strChoice[30];

int choice = -1;

do{
 system("clear"); 
 printf("DJH Darts --> Game On....\n\n");
 printf("Match Play mode functions as a simple 2 player score board.\n");
 printf("Press (q) or Ctrl c to quit at any time\n");
 printf("Press (s) to suggest checkouts\n");
 printf("-----------------------------------------------------\n\n");
 printf("Game Play mode is a mental agility exercise to test\nyou on your addition and subtraction.  ");
 printf("Starting from (say) 501, add\nthe 3 darts and take from the previous total score.\n");
 printf("The aim of the game is to finish on zero, but you must finish on a double.\n");  
 printf("Enter a checkout as 3 values sperated by white space, tab or return as follows\ne.g. :\n60 60 50,\n0 20 40 and\n0 0 32\n\n\n");


 printf("Press (g) to play game\nor just (return) for marking\n");
 
 fgets(strChoice,30,stdin);
 
 if (strcmp(strChoice,"g\n") == 0)  choice = 0; 
 if (strcmp(strChoice,"\n")  == 0)  choice = 1; 

 
}while(choice == -1);

 if (choice == 0) return true; else return false;

}

/*------------------------------------------------------------------------------*/
bool isaDouble(int da,int db,int dc){

 
if (dc == 0 && db == 0){
 //single check out with first dart da   e.g. 40 0 0
 if ((da%2 == 0 && da <41) || da==50) return true; else return false; 
}

if (dc == 0 && da == 0){
 //single check out with second dart dc 0 0 40
 if ((db%2 == 0 && db <=40) || db==50) return true; else return false; 
}


if (da == 0 && db == 0){
 //single check out with last dart dc 0 0 40
 if ((dc%2 == 0 && dc <41) || dc==50) return true; else return false; 
}


if (da == 0 && db != 0 && dc != 0){
//2 dart finsh
 if ((dc%2 == 0 && dc <41) || dc==50) return true; else return false; 
}

if (da != 0 && db == 0 && dc != 0){
//2 dart finsh
 if ((dc%2 == 0 && dc <41) || dc==50) return true; else return false; 
}

if (da != 0 && db != 0 && dc == 0){
//2 dart finsh
 if ((db%2 == 0 && db <41) || db==50) return true; else return false; 
}


if (dc != 0 && db != 0 && dc != 0){
 //3 dart checkout check last dart
 if ((dc%2 == 0 && dc <41) || dc==50) return true; else return false; 
}

return false;

}


/*--------------------------------------------------------------*/

bool isBogeyScore(int score){

if( score == 169 || score == 168 || score == 166
      || score == 165 || score == 163 || score == 162
        || score == 159 || score == 1){
         return true;
         }else return false;

}


/*--------------------------------------------------------------*/
void printfinishes(int score){

  
   if(score > 170 || score == 169 || score == 168 || score == 166
      || score == 165 || score == 163 || score == 162
        || score == 159 || score == 1){
         printf("\n%d No available checkout\n\n",score);
	 sleep(2);
         return;
         }

  char *checkouts[171];
  
  checkouts[0]   = "No available checkout";
  checkouts[1]   = "No available checkout";
  checkouts[2]   = "D1 Mad House";
  checkouts[3]   = "1 D1";
  checkouts[4]   = "D2";
  checkouts[5]   = "1 D4";
  checkouts[6]   = "D2\n\t2 D4";
  checkouts[7]   = "1 D3";
  checkouts[8]   = "D4";
  checkouts[9]   = "1 D4";
  checkouts[10]  = "D5 2 D4";
  checkouts[11]  = "3 D4";
  checkouts[12]  = "D6";
  checkouts[13]  = "1 D6";
  checkouts[14]  = "D7";
  checkouts[15]  = "7 D4";
  checkouts[16]  = "D8";
  checkouts[17]  = "9 D4";
  checkouts[18]  = "D9";
  checkouts[19]  = "11 D4\n\t3 D8";
  checkouts[20]  = "D10";
  checkouts[21]  = "1 D10\n\t5 D8";
  checkouts[22]  = "D11\n\t2 D10\n\t6 D8";
  checkouts[23]  = "7 D8";
  checkouts[24]  = "D12";
  checkouts[25]  = "1 D12\n\t7 D8";
  checkouts[26]  = "D13\n\t10 D8";
  checkouts[27]  = "11 D8";
  checkouts[28]  = "D14";
  checkouts[29]  = "13 D8";
  checkouts[30]  = "D15";
  checkouts[31]  = "15 D8";
  checkouts[32]  = "D16";
  checkouts[33]  = "1 D16\n\t17 D18\n\t3 D15";
  checkouts[34]  = "D17";
  checkouts[35]  = "3 D16";
  checkouts[36]  = "D18\n\t4 D16";
  checkouts[37]  = "5 D16";
  checkouts[38]  = "D19";
  checkouts[39]  = "7 D16\n\t19 D10\n\t3 D18";
  checkouts[40]  = "Tops D20";
  checkouts[41]  = "1 D20\n\t9 D16";
  checkouts[42]  = "10 D16\n\t6 D18";
  checkouts[43]  = "11 D16\n\t3 D20";
  checkouts[44]  = "12 D16\n\t4 D20";
  checkouts[45]  = "13 D16\n\t7 D19";
  checkouts[46]  = "6 D20\n\t10 D18";
  checkouts[47]  = "15 D16\n\t7 D20";
  checkouts[48]  = "16 D16";
  checkouts[49]  = "9 D20";
  checkouts[50]  = "Bull\n\t10 D20";
  checkouts[51]  = "11 D20\n\t15 D18";
  checkouts[52]  = "T12 D8";
  checkouts[53]  = "13 D20\n\t17 D18";
  checkouts[54]  = "14 D20";
  checkouts[55]  = "15 D20";
  checkouts[56]  = "T16 D4";
  checkouts[57]  = "17 D20";
  checkouts[58]  = "18 D20";
  checkouts[59]  = "19 D20";
  checkouts[60]  = "20 D20";
  checkouts[61]  = "T15 D8\nT11 D14";
  checkouts[62]  = "T10 D16\nT12 D13";
  checkouts[63]  = "T17 D6\nT13 D12";
  checkouts[64]  = "T16 D8";
  checkouts[65]  = "T11 D16";
  checkouts[66]  = "T10 D18\n\tT16 D9";
  checkouts[67]  = "T17 D8";
  checkouts[68]  = "T16 D10\n\tT18 D8";
  checkouts[69]  = "T19 D6";
  checkouts[70]  = "T18 D8\n\tT20 D5";
  checkouts[71]  = "T13 D16\n\tT19 D7";
  checkouts[72]  = "T16 D12\n\tT20 D6";
  checkouts[73]  = "T19 D8";
  checkouts[74]  = "T16 D13";
  checkouts[75]  = "T17 D12";
  checkouts[76]  = "T20 TD8\n\tT16 D14";
  checkouts[77]  = "T19 D10";
  checkouts[78]  = "T18 D12";
  checkouts[79]  = "T13 D20\n\tT19 D11";
  checkouts[80]  = "T20 D10\n\tT16 D16";
  checkouts[81]  = "T19 D12\n\tT15 D18";
  checkouts[82]  = "T14 D20";
  checkouts[83]  = "T17 D16";
  checkouts[84]  = "T20 D12";
  checkouts[85]  = "T19 D14\n\tT15 D20";
  checkouts[86]  = "T18 D16";
  checkouts[87]  = "T17 D18";
  checkouts[88]  = "T20 D14";
  checkouts[89]  = "T19 D16";
  checkouts[90]  = "T20 D15";
  checkouts[91]  = "T17 D20\n\tT16 D9";
  checkouts[92]  = "T19 D18\n\t25 T17 D8";
  checkouts[93]  = "T20 T18 D18";
  checkouts[94]  = "T18 D20\n\tBull T19 D6";
  checkouts[95]  = "T19 D19\n\t25 T20 D5";
  checkouts[96]  = "T20 D18";
  checkouts[97]  = "T19 D20";
  checkouts[98]  = "T20 D19";
  checkouts[99]  = "T19 10 D16";
  checkouts[100] = "T20 D20";
  checkouts[101] = "T20 9 D16\n\tT19 T12 D4";
  checkouts[102] = "T20 10 D16";
  checkouts[103] = "T19 6 D20\n\tT19 10 D18";
  checkouts[104] = "T19 15 D16\n\tT18 Bull";
  checkouts[105] = "T20 13 D16";
  checkouts[106] = "T20 T10 D8";
  checkouts[107] = "T19 T10 D10";
  checkouts[108] = "T20 16 D16";
  checkouts[109] = "T20 9 D20";
  checkouts[110] = "T20 T10 D10\n\tT20 Bull";
  checkouts[111] = "T20 18 D20";
  checkouts[112] = "T20 T12 D8";
  checkouts[113] = "T19 16 D20";
  checkouts[114] = "T20 14 D20";
  checkouts[115] = "T20 18 D20";
  checkouts[116] = "T20 11 D20\n\tT19 14 D20";
  checkouts[117] = "T20 17 D20\n\tT19 20 D20";
  checkouts[118] = "T20 18 D20";
  checkouts[119] = "T19 T12 D13";
  checkouts[120] = "Shanghai\n\tT20 20 D20";
  checkouts[121] = "T20 T11 D14\n\tT17 T20 D5";
  checkouts[122] = "T18 T18 D7";
  checkouts[123] = "T19 T16 D9";
  checkouts[124] = "T20 T14 D11";
  checkouts[125] = "T18 T19 D7\n\tT20 T15 D10";
  checkouts[126] = "T19 T19 D6";
  checkouts[127] = "T20 T17 D8";
  checkouts[128] = "T18 T14 D16\n\tT20 T18 D7";
  checkouts[129] = "T19 T16 D12\n\tT20 T19 D6";
  checkouts[130] = "T20 T20 D5";
  checkouts[131] = "T20 T13 D16\n\tT19 T14 D12";
  checkouts[132] = "T20 T16 D12";
  checkouts[133] = "T20 T19 D8";
  checkouts[134] = "T20 T16 D13";
  checkouts[135] = "T20 T17 D12";
  checkouts[136] = "T20 T20 D8";
  checkouts[137] = "T20 T19 D10";
  checkouts[138] = "T20 T18 D12\n\tT19 T19 D12";
  checkouts[139] = "T20 T13 D20";
  checkouts[140] = "T20 T20 D10";
  checkouts[141] = "T20 T19 D12";
  checkouts[142] = "T20 T14 D20\n\tT19 T19 D14";
  checkouts[143] = "T20 T17 D16\n\tT19 T18 D16";
  checkouts[144] = "T20 T20 D12";
  checkouts[145] = "T20 T19 D14";
  checkouts[146] = "T20 T18 D16\n\tT19 T19 D16";
  checkouts[147] = "T20 T17 D18\n\tT19 T18 D18";
  checkouts[148] = "T20 T20 D14\n\tT19 T17 D20";
  checkouts[149] = "T20 T19 D16";
  checkouts[150] = "T20 T18 D18\n\tT19 T19 D18";
  checkouts[151] = "T20 T17 D20\n\tT19 T18 D20";
  checkouts[152] = "T20 T20 D16";
  checkouts[153] = "T20 T19 D18";
  checkouts[154] = "T20 T18 D20";
  checkouts[155] = "T20 T19 D19";
  checkouts[156] = "T20 T20 D18";
  checkouts[157] = "T20 T19 D20";
  checkouts[158] = "T20 T20 D19\n\tT18 T18 Bull";
  checkouts[159] = "No available checkout";
  checkouts[160] = "T20 T20 D20";
  checkouts[161] = "T20 T17 Bull";
  checkouts[162] = "No available checkout";
  checkouts[163] = "No available checkout";
  checkouts[164] = "T20 T18 D8\n\tT19 T19 Bull";
  checkouts[165] = "No available checkout";
  checkouts[166] = "No available checkout";
  checkouts[167] = "T20 T19 Bull";
  checkouts[168] = "No available checkout";
  checkouts[169] = "No available checkout";    
  checkouts[170] = "T20 T20 Bull"; 

  printf("\n\n%d -->\t%s\n",score,checkouts[score]);

  sleep(2);
  
  return;
}

/*--------------------------------------------------------------*/
void printgamescores(){

  system("clear");

  printf("------Game Play-------\n\n");
  printf("Player 1 Game ON...\n");
  printf("%d\n", P1score[0]);
  printf("---------\n");

  int i = 1;
  while (i < DARTS) {
   if (P1score[i] != -1) printf("%d\t\n",  P1score[i]); else break; 
  i += 1;
  }
}


/*--------------------------------------------------------------*/
void printscores(bool finishes,bool P2){

system("clear");


printf("-------Match Play-------\n\n");
printf("Player1\t|\tPlayer2\n");

printf("%d\t|\t%d\n", P1score[0], P2score[0]);
printf("-----------------------\n");


int i = 1;
while (i < DARTS) {
  if (P1score[i] != -1) printf("%d\t|",  P1score[i]); else break;
  if (P2score[i] != -1) printf("\t%d\n", P2score[i]); else break;
  i += 1;
}

if (finishes == true){
  if (P2 == false) printfinishes(P1score[i-1]);else printfinishes(P2score[i-1]);
 }

}

/*--------------------------------------------------------------*/

scorestate ValidateScore(int score, int throw){
 if (throw > 180) 	   return invalid;
 if (throw < 0)   	   return invalid;

 if (score-throw == 0 ){
   if (isBogeyScore(score)) return invalid; else return checkedout;
 }

 if (score-throw >  1 )   return valid;
 if (score-throw <  0 )   return noscore;
 if (score-throw == 1 )   return noscore;
 return unused;
}


bool ValidDart(int dart){

if (dart >= 0 && dart <61) { 
  //check for bogey dart
  if (dart == 23 || dart == 29 || dart == 31 || dart == 35 || dart == 37 
    || dart == 41 || dart == 43 || dart == 46 || dart == 47 || dart == 49
      || dart == 52 || dart == 53 || dart == 55 || dart == 56 || dart == 58
        || dart == 59 ) return false;

  return true;
}
  else return false;

}







