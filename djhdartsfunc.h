/*Types*/
typedef enum { false, true } bool;
typedef enum {invalid=-3, noscore=-2,unused=-1, checkedout=0,valid=1} scorestate ;
typedef enum {firstDart, secondDart, thirdDart} dart ;

/*Defines*/
#define DARTS 30 

/*Globals*/
int P1score[DARTS];
int P2score[DARTS];

/*Function protypes*/
bool printhelp();
void printfinishes(int score);
void printscores(bool finishes, bool P2);
scorestate ValidateScore(int score, int throw);
void printgamescores();
bool isBogeyScore(int score);
bool isaDouble(int da,int db, int dc);
bool ValidDart(int dart);
