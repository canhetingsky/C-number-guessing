// ***********************************************************************
// Assembly         : 
// Author           : qin
// Created          : 02-03-2016
//
// Last Modified By : qin
// Last Modified On : 02-03-2016
// ***********************************************************************
// <copyright file="guess.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// Mains this instance.
/// </summary>
void main()
{
	int answer[4], guess[4], gs, times = 0, a = 0, b = 0, i, j;
	system("cls");
	system("color 5B");
	srand(time(NULL));

	for (i = 0; i<4; i++)
	{
		answer[i] = rand() % 10;
		for (j = 0; j<i; j++)
			if (answer[j] == answer[i])
				i--;
	}
	FILE *fp;
	fp = fopen("��Ϸ��¼.txt", "r");
	if (fp == NULL)
		printf("��Ϸ��¼.txtδ��������");
	else
	{
		fscanf(fp, "%d,%d", &times, &gs);
		printf("�����һ�β���%d�ξͲ³������%d\n��������Ӵ��ôô�գ�\n", times, gs);
	}
	fclose(fp);
	times = 0;
	printf("�����룺(%d%d%d%d)--->\n", answer[0], answer[1], answer[2], answer[3]);

	while(a!=4)
	{
		a=0;
		b=0;
		times++;
		printf("��%d��:", times);
		scanf("%d", &gs);
		if((gs>=0)&&(gs<=9999))
		{
			guess[0] = gs / 1000;
			guess[1] = gs / 100 % 10;
			guess[2] = gs / 10 % 10;
			guess[3] = gs % 10;
			for (i = 0; i<4; i++)
				for (j = 0; j<4; j++)
					if (guess[i] == answer[j])
					{
						if (i == j)
							a++;
						else
							b++;
						break;
					}
			printf("\t%dA%dB\n", a, b);
		}
		else
		{
			printf("������󣬳��򼴽��˳���\n");
			//continue;
			system("pause");
			exit(0);
		}     
	}
	fp = fopen("��Ϸ��¼.txt", "w");
	fprintf(fp,"%d,%d",times,gs);
	fclose(fp);
	printf("��ϲ�㣬������%d�ξͲ¶��ˣ�\n",times);
	for (i = 0; i < 6; i++)
		_beep(i*500,1200);
	printf("��Ϸ���������򼴽��˳���\n");
	system("pause");
	exit(0);
}