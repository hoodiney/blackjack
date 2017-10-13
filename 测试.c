/*来呀，快活啊之21点*/ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j,p=0;
int order[52];

struct card{
 int number;
	char kind[8];
	};
 struct card CARD[52]=
 {{11,"diamond"},{11,"club"},{11,"heart"},{11,"spade"},
  {2,"diamond"},{2,"club"},{2,"heart"},{2,"spade"},
  {3,"diamond"},{3,"club"},{3,"heart"},{3,"spade"},	
  {4,"diamond"},{4,"club"},{4,"heart"},{4,"spade"},
  {5,"diamond"},{5,"club"},{5,"heart"},{5,"spade"},
  {6,"diamond"},{6,"club"},{6,"heart"},{6,"spade"},
  {7,"diamond"},{7,"club"},{7,"heart"},{7,"spade"},
  {8,"diamond"},{8,"club"},{8,"heart"},{8,"spade"},
  {9,"diamond"},{9,"club"},{9,"heart"},{9,"spade"},
  {10,"diamond"},{10,"club"},{10,"heart"},{10,"spade"},
  {10,"diamond"},{10,"club"},{10,"heart"},{10,"spade"},
  {10,"diamond"},{10,"club"},{10,"heart"},{10,"spade"},
  {10,"diamond"},{10,"club"},{10,"heart"},{10,"spade"}};

int main()
 { 
srand((int)time(0));
order[0]=rand()%52;

for(i=1;i<52;i++)
{order[i]=rand()%52;
for(j=0;j<i;j++)
  {if(order[i]==order[j])
    {i--;}
}
}
   int sumB,sumP;
   char begin,judge;
  printf("Are you ready?(Y/N)\n");
  scanf("%c",&begin);
  fflush(stdin);
  if(begin=='y'||begin=='Y')
   {printf("Player's card is:%d %s\n",CARD[order[p]].number,CARD[order[p]].kind );
   sumP=CARD[order[p]].number;}
  else{ 
   printf("大爷有空常来啊！"); 
   return 0;} 
   
   
 for(;;)
  { 
  	printf("Player go on?(Y/N/Q)\n");
  	scanf("%c",&judge);
  	fflush(stdin);
  	
if(judge=='Y'||judge=='y'){
	 printf("Player's card is:%d %s\n\n",CARD[order[++p]].number,CARD[order[++p]].kind );
     sumP+=CARD[order[p]].number;
     printf("Total=%d\n\n",sumP);
	 if(sumP>21)
	 {printf("Player bust");
	  break;}
	 }
	  
else if(judge=='N'||judge=='n'){
	 printf("Banker's card is:%d %s\n",CARD[order[++p]].number,CARD[order[++p]].kind );
	 sumB=CARD[order[p]].number; 
	 for(;;)
      {char JUDGE;
 	   printf("\nBanker go on?(Y/N/Q)\n\n");
 	   scanf("%c",&JUDGE);
 	    fflush(stdin);
 	if(JUDGE=='Y'||JUDGE=='y')
      {
       printf("Banker's card is:%d %s\n",CARD[order[++p]].number,CARD[order[++p]].kind);
       sumB+=CARD[order[p]].number;
       printf("Total is=%d\n\n",sumB);
       if(sumB>21)
       {printf("Banker bust!");
        break;}}  
    else if(JUDGE=='N'||JUDGE=='n')
      {if(sumB>sumP)
       printf("Banker wins!");
       else if(sumP>sumB) 
       printf("Player wins!");
       else if(sumP=sumB)
       printf("Push!");
       break;
	   } 
    else if(JUDGE=='Q'||JUDGE=='q')
       printf("大爷有空常来啊！");}
	  break;}
	
else if(judge=='Q'||judge=='q')
{
printf("大爷有空常来啊！");
break;} 
   }

  
  
return 0;

}


