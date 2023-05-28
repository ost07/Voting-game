#include <stdio.h>

void voting();
void game();

int main()
{
    int i;
    voting();
    printf("\nPress:\n0 to Play Game\nAnywhere to Exit\nWrite your Response here: ");
    scanf("%d", &i);
    if(i==0) game();
    return 0;
}

void voting()
{
    int count[4]= {0, 0, 0, 0};
    int vote;
    int i;
    printf("|| Voting Booth ||\nEnter:\n1 for Party 'A'\n2 for Party 'B'\n3 for Party 'C'\n4 for NOTA\n0 to End Poll\n\n");
    
    for(i=1; ; i++) {
        printf("Voter %d: ", i);
        scanf("%d", &vote);
        
        if(vote==0) break;
        
        if(vote>=1 && vote<=4) {
            count[vote-1]++;
        }
        else{
            i--;
            printf("Invalid Vote. Please enter a Valid Number.\n");
        }
    }
    
    printf("\n|| Vote Count ||\n");
    for (i=1; i<=3; i++) {
        printf("Party '%c': %d votes\n", i+64, count[i-1]);
    }
    printf("NOTA: %d votes\n", count[3]);
    printf("\nThank You for Voting!\n");
}

void game()
{
    int ms=21, t;
    printf("\n\n|| GAME TIME ||\nRules:\nThere are 21 Matchsticks.\nPlayer takes 1-4 Matchsticks.\nWho takes Last Matchstick LOSES.\nUser Starts!\n\n");
    
    while(1){
        printf("User: ");
        scanf("%d", &t);
        while (t<1 || t>4 || t>ms) {
            printf("Invalid! Try Again!\n");
            printf("User: ");
            scanf("%d", &t);
        }
        
        if((ms-=t)<=0){ //here 2 tasks are happening at same time
            printf("\nUser takes Last Matchstick.\nComputer Wins !!!\n");
            break;
        }
        
        printf("Computer: %d\n", 5-t);
        printf("Matchsticks Left: %d\n", ms-=5-t); //here 2 tasks are happening at same time
    }
    printf("\nThank You for Playing!\n");
}
