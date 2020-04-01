#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int winTicket[6]={1,2,3,4,5,6};
struct winnerTalleys {
	long GrandPrize;
	long Alt1;
	long Alt2;
	long Alt3;
	long Alt4;
	long Alt5;
	long Alt6;
	long Alt7;
	long Alt8;
} winTalley={0,0,0,0,0,0,0,0,0};
volatile int ticketsBought=0;
void closeoutLottery()
{ 	long oddsOfWinning=0;
	oddsOfWinning=69L*68L*67L*66L*65L*26L/5L/4L/3L/2L;
	printf("\nWinner of $40M was after %'d tickets were sold.\n"
		"Odds of winning GrandPrize are 1:%'ld.\n",
			ticketsBought,oddsOfWinning);
	printf("Profitability:\n\tTicket Sales:$%'.2f"
		"\n\t%'ld Grand Prize Winner = $%'.2f"
		"\n\t%'ld 1st Prize Winners  = $%'.2f"
		"\n\t%'ld 2nd Prize Winners  = $%'.2f"
		"\n\t%'ld 3rd Prize Winners  = $%'.2f"
		"\n\t%'ld 4th Prize Winners  = $%'.2f"
		"\n\t%'ld 5th Prize Winners  = $%'.2f"
		"\n\t%'ld 6th Prize Winners  = $%'.2f"
		"\n\t%'ld 7th Prize Winners  = $%'.2f"
		"\n\t%'ld 8th Prize Winners  = $%'.2f"
		"\n\tTotal Prize Money Paid Out = $%'.2f"
		"\n\tLottery made this much profit: $%'.2f   (%'.2f%% profit)\n"
			,(double)ticketsBought*2.0
			,winTalley.GrandPrize, (double)40000000*(double)winTalley.GrandPrize
			,winTalley.Alt1, (double) 1000000*(double)winTalley.Alt1
			,winTalley.Alt2, (double)   50000*(double)winTalley.Alt2
			,winTalley.Alt3, (double)     100*(double)winTalley.Alt3
			,winTalley.Alt4, (double)     100*(double)winTalley.Alt4
			,winTalley.Alt5, (double)       7*(double)winTalley.Alt5
			,winTalley.Alt6, (double)       7*(double)winTalley.Alt6
			,winTalley.Alt7, (double)       4*(double)winTalley.Alt7
			,winTalley.Alt8, (double)       4*(double)winTalley.Alt8 
			, (double)40000000*(double)winTalley.GrandPrize
			+ (double) 1000000*(double)winTalley.Alt1
			+ (double)   50000*(double)winTalley.Alt2
			+ (double)     100*(double)winTalley.Alt3
			+ (double)     100*(double)winTalley.Alt4
			+ (double)       7*(double)winTalley.Alt5
			+ (double)       7*(double)winTalley.Alt6
			+ (double)       4*(double)winTalley.Alt7
			+ (double)       4*(double)winTalley.Alt8 
			, (double)ticketsBought*2.0 - (
			  (double)40000000*(double)winTalley.GrandPrize
			+ (double) 1000000*(double)winTalley.Alt1
			+ (double)   50000*(double)winTalley.Alt2
			+ (double)     100*(double)winTalley.Alt3
			+ (double)     100*(double)winTalley.Alt4
			+ (double)       7*(double)winTalley.Alt5
			+ (double)       7*(double)winTalley.Alt6
			+ (double)       4*(double)winTalley.Alt7
			+ (double)       4*(double)winTalley.Alt8 ) 
			, ( (double)ticketsBought*2.0 - (
			    (double)40000000*(double)winTalley.GrandPrize
			+   (double) 1000000*(double)winTalley.Alt1
			+   (double)   50000*(double)winTalley.Alt2
			+   (double)     100*(double)winTalley.Alt3
			+   (double)     100*(double)winTalley.Alt4
			+   (double)       7*(double)winTalley.Alt5
			+   (double)       7*(double)winTalley.Alt6
			+   (double)       4*(double)winTalley.Alt7
			+   (double)       4*(double)winTalley.Alt8 ) )
			/ ( (double)40000000*(double)winTalley.GrandPrize
			+   (double) 1000000*(double)winTalley.Alt1
			+   (double)   50000*(double)winTalley.Alt2
			+   (double)     100*(double)winTalley.Alt3
			+   (double)     100*(double)winTalley.Alt4
			+   (double)       7*(double)winTalley.Alt5
			+   (double)       7*(double)winTalley.Alt6
			+   (double)       4*(double)winTalley.Alt8  
			+   (double)       4*(double)winTalley.Alt7 )*100
			);
}

int isWin8(int myTicket[])
{ 	//If Powerball matches
	if ( myTicket[5]==winTicket[5] ) //powerball
		return 1; //Winner!
	else
		return 0; //Loser
}

int isWin7(int myTicket[])
{ 	//If 1 of 5 of the first balls are matched + Powerball
	if ( ! (myTicket[5]==winTicket[5]) ) //powerball
		return 0; //not a winning ticket	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==1)
		return 1; //Winner
	else
		return 0; //not a winner
}

int isWin6(int myTicket[])
{ 	//If 2 of 5 of the first balls are matched + Powerball
	if ( ! (myTicket[5]==winTicket[5]) ) //powerball
		return 0; //not a winning ticket	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==2)
		return 1; //Winner
	else
		return 0; //not a winner
}

int isWin5(int myTicket[])
{ 	//If 3 of 5 of the first balls are matched (ignore Powerball)
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==3)
		return 1; //Winner 
	else
		return 0; //not a winner
}

int isWin4(int myTicket[])
{ 	//If 3 of 5 of the first balls are matched + Powerball
	if ( ! (myTicket[5]==winTicket[5]) ) //powerball
		return 0; //not a winning ticket	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==3)
		return 1; //Winner
	else
		return 0; //not a winner
}


int isWin3(int myTicket[])
{ 	//If 4 of 5 of the first balls are matched (ignore Powerball)
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==4)
		return 1; //Winner
	else
		return 0; //not a winner
}

int isWin2(int myTicket[])
{ 	//If 4 of 5 of the first balls are matched + Powerball
	if ( ! (myTicket[5]==winTicket[5]) ) //powerball
		return 0; //not a winning ticket	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==4)
		return 1; //Winner of Win2 prize
	else
		return 0; //not a winner
}

int isWin1(int myTicket[])
{ 	//If all 5 of the first balls are matched	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==5)
		return 1; //Winner 
	else
		return 0; //not a winner
}

int isGrandPrizeWinner(int myTicket[])
{ 	if ( ! (myTicket[5]==winTicket[5]) ) //powerball
		return 0; //not a winning ticket	
	int iBallsMatch[5]={0,0,0,0,0}; //flag array.  Set to 1 if Match!
	for (int i=0;i<5;i++)
	{  	iBallsMatch[i]=0; //0 if lost, 1 if winner 
		for(int j=0;j<5;j++)
		{ 	if (myTicket[i]==winTicket[j])
			{	iBallsMatch[i]=1; //this ticket is OK	       
			}
		}//end for
	}
	if (iBallsMatch[0]+iBallsMatch[1]+iBallsMatch[2]+iBallsMatch[3]+iBallsMatch[4]==5)
		return 1; //Winner 
	else
		return 0; //not a winner
}

void talleyWinners(int myTicket[])
{//function to keep track of all 9 ways of winning
	if (isGrandPrizeWinner(myTicket))
		winTalley.GrandPrize+=1;
	else if ( isWin1(myTicket) )
		winTalley.Alt1+=1;
	else if ( isWin2(myTicket) )
		winTalley.Alt2+=1;
	else if ( isWin3(myTicket) )
		winTalley.Alt3+=1;
	else if ( isWin4(myTicket) )
		winTalley.Alt4+=1;
	else if ( isWin5(myTicket) )
		winTalley.Alt5+=1;
	else if ( isWin6(myTicket) )
		winTalley.Alt6+=1;
	else if ( isWin7(myTicket) )
		winTalley.Alt7+=1;
	else if ( isWin8(myTicket) )
		winTalley.Alt8+=1;
}

void printTicket(int myTicket[])
{ 	for(int i=0;i<6;i++)
		printf("Position %d has number %d.\n",i,myTicket[i]);
}

void buyATicket(int myTicket[])
{ 	int duplicate=0; //set to 1 if duplicate found
	for(int i=0;i<5;i++) //pick first 5 balls, no duplicates
	{ 	int try=rand()%69+1; //1-69 inclusive
		//do I already have 'try' in my array? (I can't sell the same number twice on a ticket)
		for(int j=0;j<i;j++) { 	if (myTicket[j]==try) duplicate=1; } //found a duplicate	
		if (!duplicate) {myTicket[i]=try; } 
		else {i--;duplicate=0;}  //need to try again
	}
	myTicket[5]=rand()%26+1;//Powerball is 1-26 inclusive
}

void main(int argc, char * argv[])
{ 	srand(time(0));
        setlocale(LC_NUMERIC, "en_US.UTF-8");
        setlocale(LC_MONETARY, "en_US");
	int ticket[6];
	do
	{ 	buyATicket(ticket); 
		ticketsBought++;
		talleyWinners(ticket);//record all winning tickets
	} while (!isGrandPrizeWinner(ticket));
	closeoutLottery();
/*
	//Testcase to prove 1 winning ticket
	ticket[0]=1;
	ticket[1]=2;
	ticket[2]=3;
	ticket[3]=4;
	ticket[4]=5;
	ticket[5]=6;
	ticketsBought++;
	talleyWinners(ticket);
	printTicket(ticket);
	closeoutLottery();
*/
}

