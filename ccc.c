/*
	xxxx-xx-xx xxx

	名称：剪刀石头布

    语言：C
    IDE：VC++6.0

	分析：
		1.剪刀s0、石头r1、布p2
		2.玩家赢
		3.电脑赢
		4.平局

	%c%*c：可以多输出一个字符却不赋给任何变量

	总结：
		因为需要获取字符，总跟缓冲区的遗留字符有关，而我没有太好地处理缓冲区内容，
		所以此程序还不太完善
*/

# include <stdio.h>
# include  <stdlib.h>	//srand(),rand()
# include <time.h>		//time()

void playGame(void);
char yourTurn(void);
int computerTurn(void);
void judgeTime(char playerChoice, int computerChoice);

int main(void)
{
	playGame();
	
	return 0;
}

void playGame(void)
{
	char playerChoice;
	int computerChoice;
	int play = 1;
	
	printf("GAME:Scissors-Rock-Paper\n");
	printf("\nScissors->s\n""Rock->r\n""Paper->p\n");
	
	while(play)
	{
		playerChoice = yourTurn();
		computerChoice = computerTurn();
		judgeTime( playerChoice,computerChoice );

		printf("\nContinue or not(非0/0):\n");
		scanf("%d", &play);			//遗留问题处
		getchar();
	}
	
	printf("\nEND\n");
}

char yourTurn(void)
{
	char playerChoice = 'o';

	do
	{
		printf("\n->Your choice is ");
		playerChoice = getchar();	//遗留问题处
		getchar();
	}while('s'!=playerChoice && 'r'!=playerChoice && 'p'!=playerChoice);

	return playerChoice;			//srp
}

int computerTurn(void)
{
	int computerChoice = -1;

	srand( (unsigned)time(NULL) );
	computerChoice = rand() % 3;

	printf("->Computer choose ");
	switch (computerChoice)
	{
		case 0: putchar('s');break;
		case 1: putchar('r');break;
		case 2: putchar('p');break;
		default:putchar('w');
	}
	putchar('\n');

	return computerChoice;			//012
}

void judgeTime(char playerChoice, int computerChoice)
{
	if (('s'==playerChoice && 0==computerChoice) ||
		('r'==playerChoice && 1==computerChoice) ||
		('p'==playerChoice && 2==computerChoice))
		printf("->Dogfall\n");

	if (('s'==playerChoice && 2==computerChoice) ||
		('r'==playerChoice && 0==computerChoice) ||
		('p'==playerChoice && 1==computerChoice))
		printf("->Player win\n");

	if (('s'==playerChoice && 1==computerChoice) ||
		('r'==playerChoice && 2==computerChoice) ||
		('p'==playerChoice && 0==computerChoice))
		printf("->Computer win\n");
}
