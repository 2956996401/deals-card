/*每个人的卡牌和名字
@自己写出来真的感觉成就感满满，这种感觉真的太棒了
@shuffle(int *card) 这是洗牌函数，主要运用了伪随机数，也是这个程序的灵魂
@deals(int *card, int *card1, int *card2, int *card3) 这是发牌函数，主要是将card@里面的数字一个一个分配给三个人
@show(int *card, char *name) 这是显示程序，传进去每个人的卡牌和名字
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *card);
void deals(int *card, int *card1, int *card2, int *card3);
void show(int *card, char *name);

int main()
{
	int i;
	char name1[5];
	char name2[5];
	char name3[5];
	int card[54];
	char *str1 = name1;
	char *str2 = name2;
	char *str3 = name3;
	int card1[17];
	int card2[17];
	int card3[17];

	int *c1 = card1;
	int *c2 = card2;
	int *c3 = card3;

	printf("请输入1号玩家的名字：");
	scanf("%s", str1);
	printf("请输入2号玩家的名字：");
	scanf("%s", str2);
	printf("请输入3号玩家的名字：");
	scanf("%s", str3);
		
	for (i = 0; i < 54; i++)
GGGG	{
		card[i] = i + 1;
	}
	card[i] = '\0';	
	shuffle(card);
	deals(card, card1, card2, card3);
	
	show(card1, str1);
	show(card2, str2);
	show(card3, str3);	

	return 0;
}

void shuffle(int *card)
{
	int i;

	//使用当前时间值初始化伪随机种子序列
	srand(time(NULL));
	for (i = 0; i < 54; i++)
	{
		int j = rand() % 54;
		int temp = card[i];
		card[i] = card[j];
		card[j] = temp;
		
	}
	
}

void deals(int *card, int *card1, int *card2, int *card3)
{
	int j = 0, k = 0, l = 0;
	for (int i = 1; i <= 54; i++)
	{
		if (i % 3 == 1)
		{	
			card1[j] = card[i - 1];
			j++;
		}
		else if(i % 3 == 2)
		{
			
			card2[k] = card[i - 1];
			k++; 
		}
		else if(i % 3 == 0)
		{
			card3[l] = card[i - 1];
			l++;
		}
	}

}

void show(int *card, char *name)
{
	int i;

	printf("%s手上的牌是:", name);
	for (i = 0; i < 17; i++)
	{
		if (card[i] <= 10)
		{
			printf("方角%d ", card[i]);
		}
		else if(card[i] <= 20)
		{
			printf("梅花%d ", card[i] - 10);
		}
		else if(card[i] <= 30)
		{
			printf("红桃%d ", card[i] - 20);
		}
		else if(card[i] <= 40)
		{
			printf("黑桃%d ", card[i] - 30);
		}
		else if(card[i] <= 43)
		{	switch (card[i])
			{
				case 41:
					printf("方块J "); 
					break;
				case 42: 		
					printf("方块Q ");
					break;
				case 43: 	
					printf("方块K ");
					break;
				
			}
		}
		else if(card[i] <= 46)
		{
			switch (card[i])
			{
				case 44:
					printf("梅花J ");
					break;
				case 45:
					printf("梅花Q ");
					break;
				case 46: 
					printf("梅花K ");
					break;
				
			}

		}
		else if(card[i] <= 49)
		{
			switch (card[i])
			{
				case 47: 
					printf("红桃J ");
					break;
				case 48: 
					printf("红桃Q ");
					break;
				case 49: 
					printf("红桃K ");
					break;
			}
		}
		else if(card[i] <= 52)
		{
			switch (card[i])
			{
				case 50: 
					printf("黑桃J ");
					break;
				case 51: 
					printf("黑桃Q ");
					break;
				case 52: 
					printf("黑桃K ");
					break;
			}
		}
		else if(card[i] == 53)
		{
			printf("小王 ");
		}
		else if(card[i] == 54)
		{
			printf("大王 ");
		}
	}
	putchar('\n');
	putchar('\n');
}
