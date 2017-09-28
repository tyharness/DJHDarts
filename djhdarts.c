/*----DJH Darts v1.0- Ty Harness Sept 2017


Match Play:
Use this application as a simple method of
scoring a 501 dart match.  Press s to suggest
out shot finishes once you get below 170.

Game Play: - Mental arithmatic game.
Starting from 501:
(The dart players score is randomly generated.)
Add the 3 the darts and take from the score until
a check out is avaiable and then enter 3 darts
to finish on zero.  You must finish on a double.
e.g. a 3 dart finish:  	170-> 60 60 50 [return]
e.g. a 2 dart finish:  	58 -> 0 8 50   [return]
e.g. a 1 dart finish:	40 -> 0 0 40   [return]
e.g. a 1 dart finish:	40 -> 40 0 0   [return]
You have to put the additional 0 darts in, sorry
it's the easiast way to do it in c.



Alas no speedboats or teasmaids in this game, 

--------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include"djhdartsfunc.h"


/*Main Function*/
int main(int argc, char **argv){


srand(time(NULL));

char cthrow[12];

int throw = 0;

/*use an array to hold the darts score for each player
Initilise the array*/
int i=0;
while (i < DARTS) {
 P1score[i] = -1;
 P2score[i] = -1;
 i += 1;
}


if (argc == 1) {
   //no arguments
   P1score[0] = 501;
   P2score[0] = 501;    
  }else{
    
     if (argc == 2){
      P1score[0]   = atoi(argv[1]); 
      P2score[0]   = atoi(argv[1]); 
      }else if (argc == 3){
	P1score[0]   = atoi(argv[1]); 
	P2score[0]   = atoi(argv[2]); 
	}else{
         P1score[0] = 501;
	 P2score[0] = 501;
       } 

 }


bool gamemode;

gamemode = printhelp();

start:

i = 1;

if (gamemode == false){
/*------Matchplay mode------*/

printscores(false,false);

 while (i < DARTS) {

   if(P1score[i] == -1 ){

      if(scanf("%s", cthrow) == 1){
      

       if ( strcmp(cthrow,"q")==0 ) {
        break;
       }

       if ( strcmp(cthrow,"s")==0 ) {
        printscores(true,false);
        goto start;
       }

       throw = atoi (cthrow);
     

       if ( ValidateScore(P1score[i-1],throw) == invalid){
        P1score[i] = -1;
        goto start;
       }

       if ( ValidateScore(P1score[i-1],throw) == valid){
        P1score[i] = P1score[i-1] - throw;
       }

       if ( ValidateScore(P1score[i-1],throw) == noscore){
        P1score[i] = P1score[i-1];
       }

       if ( ValidateScore(P1score[i-1],throw) == checkedout){
        P1score[i] = P1score[i-1] - throw;
        printf("\n\nGame shot and the match Player 1\n\n");
        break;
       }
     } //end of scanf

     printscores(false,false);

    }//end of P1score[i] == -1




   if(P2score[i] == -1 ){

      if(scanf("%s", cthrow) == 1){
          
 
       if ( strcmp(cthrow,"q")==0 ) {
        break;
       }

       if ( strcmp(cthrow,"s")==0 ) {
        printscores(true,true);
        goto start;
       
       }

       throw = atoi (cthrow);
      
 
       if ( ValidateScore(P2score[i-1],throw) == invalid){
        P2score[i] = -1;
        goto start;
       }

       if ( ValidateScore(P2score[i-1],throw) == valid){
        P2score[i] = P2score[i-1] - throw;
       }

       if ( ValidateScore(P2score[i-1],throw) == noscore){
        P2score[i] = P2score[i-1];
       }

       if ( ValidateScore(P2score[i-1],throw) == checkedout){
        P2score[i] = P2score[i-1] - throw;
        printf("\n\nGame shot and the match Player 2\n\n");
       break;
       }



     } //end of scanf

     printscores(false, true);

    }//end p2score[i] = -1


   i += 1;


  }//end of the darts while loop

}else{

//gameplay mode
 while (i < DARTS) {

  printgamescores();

   if(P1score[i] == -1 ){
    
    int gscore;
    int score;    
    score = P1score[i-1];

    if (score > 171 || isBogeyScore(score) == true){
    
    int dart1 = (rand()%3+1) * (rand()%20 + 1);
    int dart2 = (rand()%3+1) * (rand()%20 + 1);
    int dart3 = (rand()%3+1) * (rand()%20 + 1);

    gscore = dart1 + dart2 + dart3;

    printf("\n%d\t--> %d --> %d --> %d  ", score, dart1, dart2, dart3 );
   
    int sum=1000;

    do{
     if (scanf(" %d", &sum) == 1){     
        if (score - sum == gscore) {
         if(gscore > 99) printf("Good arrows!\n");else printf("correct.\n");
           P1score[i] = score - gscore; 
        } else  printf("%d --> try again \n", score);
        sleep(1) ;
    }else{
      printf("Invalid input --> try again\n");
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF);
    }

    }
    while (score-sum != gscore);

   }else{
     printf("%d --> There's a checkout on -- take your time....\n",score);
     int da,db,dc;
    
    do{

      if( scanf("%d %d %d", &da, &db, &dc) == 3){
       //conversion ok
       if (ValidDart(da) && ValidDart(db) && ValidDart(dc)) {
        gscore = da + db + dc;        
       } else {
         printf("Bogey dart --> try again\n");
         gscore = 0;
        }
      }else{
       printf("Invalid input --> try again\n");
       int ch;
       while ((ch = getchar()) != '\n' && ch != EOF);
       gscore = 0;
      }




       if (score == gscore){        	 
         if (isaDouble(da,db,dc)==true){
          printf("\nGame shot and the Match\n");          
          return 0;
         }else gscore = 0;          
       } 
         


       if(gscore < score){  
          if (score-gscore == 1 || score-gscore<0){
           printf("No score\n");
          }else score -= gscore; 
         // printf("you require %d\n",score);      
        }else{
          printf("No score\n");
        }
    
        printf("you require %d\n",score);  
        sleep(1) ;
      
      }
      while (score != gscore);

   }

 i += 1;

 }

}

}//end of the game mode


return 0;
}//end of main



















