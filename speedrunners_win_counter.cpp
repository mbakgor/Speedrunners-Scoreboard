#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits.h>
struct players {
	struct players *prev;
	char names[100];
	int points;
	int rounds;
	int id;
	struct players *next;
};
struct players *head    = (struct players*) malloc(sizeof(struct players)); 
struct players *nhead   = (struct players*) malloc(sizeof(struct players)); 

struct players *player1 = (struct players*) malloc(sizeof(struct players));
struct players *player2 = (struct players*) malloc(sizeof(struct players));
struct players *player3 = (struct players*) malloc(sizeof(struct players));
struct players *player4 = (struct players*) malloc(sizeof(struct players));

struct players *first_player = (struct players*) malloc(sizeof(struct players));
struct players *second_player = (struct players*) malloc(sizeof(struct players));
struct players *third_player = (struct players*) malloc(sizeof(struct players));
struct players *fourth_player = (struct players*) malloc(sizeof(struct players));


int pnumber = 0;

int player_names();
int points();
int get_largest();
int winning_table();

int main()
{
	head->next    = player1;
	nhead->next   = first_player;
	player1->next = player2;
    player2->next = player3;
    player3->next = player4;
    player4->next = NULL;
    
    first_player->next  = second_player;
	second_player->next = third_player;
	third_player->next  = fourth_player;
	fourth_player->next  = NULL;
    
	player_names();
}

int player_names()
{
	int result;
	
	for(int i = 0; i<4; i++)
	{
	pnumber++;
	printf("Please enter the name of players.(write 'quit' when you finish enter)\n");
	scanf("%s",player1->names);
	player1->id = i+1;
	result = strcmp(player1->names,"quit");
	player1=player1->next;
	if(result == 0)  {
		player1 = head->next;
     return points();
    }
}
pnumber++;
player1 = head->next;
return points();
}
  

int points()
{
	
	printf("\t");
	
	int choice;
	int marker=1;
	printf("PLEASE ENTER THE ID OF WINNER!\n");
	for(int z = 1; z < pnumber; z++)
	{
    printf("%d -> %s\n",marker++,player1->names);
    player1=player1->next;
    }
    
    scanf("%d",&choice);
    
    player1 = head->next;
    
    if(choice == player1->id)
    {
    	player1->rounds += 1;
    	player1->points += 3;
	}
	
	else if(choice == player2->id)
    {
    	player2->rounds += 1;
    	player2->points += 3;
	}
	
	else if(choice == player3->id)
    {
    	player3->rounds += 1;
    	player3->points += 3;
	}
	
	else if(choice == player4->id)
    {
    	player4->rounds += 1;
    	player4->points += 3;
	}
	
	else
	{
		printf("You entered wrong number!\n");
		return 0;
	}
	
	for(int x = 1; x < pnumber; x++)
	{
		int point = 0;
	printf("Please enter of the %s's earned point in this round\n(NOTICE THAT : DONT GIVE ANY POINTS TO WINNER!)\n",player1->names);
	scanf("%d",&point);
	
	player1->points += point;
	
	player1 = player1->next;
    }
    
    player1 = head->next;
    
    char checker;
    printf("Do you want to continue ? (y or n)\n");
    scanf(" %c",&checker);
    
    if(checker == 'y') return points();
    else {
    	
	for(int b = 0; b < 4; b++)
	{
		player1->points += player1->rounds * 2;
		player1 = player1->next;
		
	}
	
	player1 = head->next;
	return get_largest();   
}
}

int get_largest()
{
	
    first_player->points = second_player->points = third_player->points = INT_MIN;
    first_player->rounds = second_player->rounds = third_player->rounds = INT_MIN;
	
	
	for(int o = 0; o < 4; o++)
	{
		
		if(player1->points > first_player->points) 
		{
			
		fourth_player->rounds = third_player->rounds;
		third_player->rounds  = second_player->rounds;
		second_player->rounds = first_player->rounds;
		first_player->rounds = player1->rounds;
		
        fourth_player->points = third_player->points;
		third_player->points  = second_player->points;
		second_player->points = first_player->points;
		first_player->points  = player1->points;
		
		strcpy(fourth_player->names,third_player->names);
		strcpy(third_player->names,second_player->names);
		strcpy(second_player->names,first_player->names);
		strcpy(first_player->names,player1->names);
      	}
      	
      	else if(player1->points > second_player->points)
      	{
      		
      	fourth_player->rounds = third_player->rounds;
		third_player->rounds  = second_player->rounds;
		second_player->rounds = player1->rounds;
      		
      	fourth_player->points = third_player->points;
      	third_player->points  = second_player->points;
      	second_player->points = player1->points;
      	
      	strcpy(fourth_player->names,third_player->names);
		strcpy(third_player->names,second_player->names);
		strcpy(second_player->names,player1->names);
      		
		}
      	
      	else if(player1->points > third_player->points)
      	{
      	fourth_player->rounds = third_player->rounds;
		third_player->rounds  = player1->rounds;
      		
      	fourth_player->points = third_player->points;
      	third_player->points = player1->points;
      	
      	strcpy(fourth_player->names,third_player->names);
		strcpy(third_player->names,player1->names);
      		
		}
		
		else if(player1->points > fourth_player->points)
      	{
      	fourth_player->rounds = player1->rounds;
      	
      	fourth_player->points = player1->points;
      	
		strcpy(fourth_player->names,player1->names);
      		
		}
		  
		if(player1->next == NULL) 
		{
			
			player1 = head->next;
            first_player = nhead->next;
            return	winning_table();
			
		}
		
		player1 = player1->next;
	
	
}
    player1 = head->next;
    first_player = nhead->next;
	winning_table();
}

int winning_table()
{
	
	printf("RANK     NAME     ROUNDS     POINTS\n");
	for(int d = 0; d < 4; d++) printf("-");
	printf("     ");
	for(int d = 0; d < 4; d++) printf("-");
	printf("     ");
	for(int d = 0; d < 6; d++) printf("-");
	printf("     ");
	for(int d = 0; d < 6; d++) printf("-");
	printf("\n");
	
	for(int a = 1; a < pnumber; a++) 
	{ 
	printf("\n");                                                                
	printf("%d        %s         %d        %d",a,first_player->names,first_player->rounds,first_player->points);
                                                                                                        
    first_player = first_player->next;
	}
	
	player1 = head->next;
	
	int ch;
	scanf("%d",&ch);
	
	
}













