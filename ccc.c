/*
	xxxx-xx-xx xxx

	���ƣ�����ʯͷ��

    ���ԣ�C
    IDE��VC++6.0

	������
		1.����s0��ʯͷr1����p2
		2.���Ӯ
		3.����Ӯ
		4.ƽ��

	%c%*c�����Զ����һ���ַ�ȴ�������κα���

	�ܽ᣺
		��Ϊ��Ҫ��ȡ�ַ����ܸ��������������ַ��йأ�����û��̫�õش����������ݣ�
		���Դ˳��򻹲�̫����
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

		printf("\nContinue or not(��0/0):\n");
		scanf("%d", &play);			//�������⴦
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
		playerChoice = getchar();	//�������⴦
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
