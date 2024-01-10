#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
#include <iostream>
using namespace std;
static int blockaddress[20000];
static int before[20000];
static int t = 0;

int misstype(int ba, int nb, int l);
//void generateRandomMemorySequence(int sequenceLength, const char* fileName) {
//	FILE* fp;
//	int i;
//
//	srand(time(NULL));
//
//	fp = fopen(fileName, "w");
//	if (fp == NULL) {
//		printf("无法打开文件。\n");
//		return;
//	}
//
//	for (i = 0; i < sequenceLength; i++) {
//		int randomNumber = rand() % 50;
//
//		fprintf(fp, "%d\n", randomNumber);
//	}
//
//	fclose(fp);
//}
int main()
{
	
	//FILE* fp;
	int cachesize;
	int blocksize;
	int assoc;
	int blockinbyte;
	int NOofblock;
	int NOofset;
	int choice;//选择关联方式
	float misscount, accesscount, hitcount;
	int index, byte, tag, ii;
	int i = 0, j, x, y, z, cc, c, m;
	int bytearray[20010], wordaddress[20010];
	int newarray[300][300] = { 0 }, lru[300][300] = { 0 };
	char ans = 'y';
	int c1c = 0, c2c = 0, c3c = 0;
	float missrate = 0, hitrate = 0;

	do
	{
		printf("Cache Simulation Project:");
		printf("\n\n1. Direct_mapped\n2. Set_associate\n3. Fully_associate\n\n: ");
		// choice from direct mapped, set associate and fully associate
		scanf("%d", &choice);
		if (choice == 1 || choice == 2 || choice == 3)
			break;
		printf("Incorrect input.");

	} while (1);

	do
	{
		printf("\n\nCache Size from range[64/128/256]: ");
		scanf("%d", &cachesize);
		if (cachesize == 64 || cachesize == 128 || cachesize == 256 || cachesize == 16)// choose cache size
			break;
		printf("Incorrect input.");
	} while (1);
	//int sequenceLength = 10; // 设定序列长度
	//const char* fileName = "project.txt";
	//generateRandomMemorySequence(sequenceLength, fileName);
	do
	{
		printf("\n\nBlock Size from range[1/2/4]: ");
		scanf("%d", &blocksize);
		if (blocksize == 1 || blocksize == 2 || blocksize == 4) //choose block size
			break;
		printf("Incorrect input.");
	} while (1);

	do
	{
		printf("\n\nEnter the value for n-way Set value from[1/2/4/8/16]: ");
		scanf("%d", &assoc);
		if (assoc == 1 || assoc == 2 || assoc == 4 || assoc == 8 || assoc == 16)
			break;
		printf("Incorrect input.\n");
	} while (1);

	for (ii = 0; ii < 500; ii++)
		before[ii] = -1;

	//fp = fopen(".\\project.txt", "r");//open the file
	/*while (fscanf(fp, "%d", &byte) != EOF)
	{
		bytearray[i] = byte;
		i++;
	}*/
	/*for (int jjj = 0; jjj < i; jjj++)cout << bytearray[jjj] << ' ';
	cout << endl;*/
	//fclose(fp);
	int stride = 131;
	for(int k=0;k<10000;k++)
		for (j = 0; j < 256; j = j + stride)
		{
			bytearray[i] = j * 4;
			i++;
		}
	blockinbyte = blocksize * 4;                   //���ֽڼ�����Ŀ����calculate the block size in bit
	NOofblock = cachesize / blockinbyte;           // calculate the # of blocks
	NOofset = NOofblock / assoc;                       //calculate the # of sets
	misscount = 0;                                   // initial miss counter=0
	hitcount = 0;                                    // initial hit counter=0                                       
	accesscount = 0;                                 // initial access counter=0
	for (j = 0; j < i; j++)
	{
		accesscount++;                             //increase the access counter
		wordaddress[j] = bytearray[j] / 4; //�������ݵ��ֵ�ַ            //calculate the word address
		blockaddress[j] = wordaddress[j] / blocksize; //�������ݵĿ��ַ //calculate the block address
		index = blockaddress[j] % NOofset; //�����������ڵ�set��ַ            //calculate the index
		tag = blockaddress[j] / NOofset;   //�����������ڵ�tag            //calculate the tag
		//cout << "wordaddress" << ':' << wordaddress[j] << " blockaddress" << ' ' << blockaddress[j] << " index:" << index << " tag:" << tag << endl;
		x = y = z = 0;
		if (choice == 1 || choice == 2) //��Ϊֱ��ӳ�������ӳ��                  //direct mapped or set associativity
		{
			//assoc����n-way��n
			while (z < (assoc * 2))                    /*chech the tag bit of one set, I multiple 2 in here because I will
													put the tag and valid bit in to a new 2-D array, step is two*/
			{
				cc = 0;
				c = 0;
				if (newarray[index][z] == 0)          ////��cache �ж�Ӧλ���ϵ���Чλ��Ч�����ݲ���cache�У�ʧЧ check the valid bit
				{
					newarray[index][z + 1] = tag;      //����tagλ put the tag into a new array
					newarray[index][z] = 1;          //������Чλ set valid bit to 1
					misscount++;
					c = misstype(blockaddress[j], NOofblock, j);//�ж�ʧЧ���� dicide the type of miss
					cc = 1;
					for (m = 0; m < (assoc * 2); m = m + 2)     //��������ʹ�ò���lru policy
						lru[index][m]++;           //increase the value of lru[index][m] to 1 in the same index
					lru[index][z] = 0;               //set the  recent use value to 0
					z = (assoc * 2);                   // while loop out
				}
				else//��cache �ж�Ӧλ���ϵ���Чλ��Ч
				{
					if (newarray[index][z + 1] == tag)   ////����tagλһ�£�������cache �У�����if the tag already in the cache
					{
						hitcount++;                 //hit counter increase
						for (m = 0; m < (assoc * 2); m = m + 2)
							lru[index][m]++;
						lru[index][z] = 0;
						z = (assoc * 2);
					}
					else//����tagλ��һ��
					{
						if (assoc < 2)                   //Direct mapped
						{
							newarray[index][z + 1] = tag; // put the tag into a new array
							misscount++;
							c = misstype(blockaddress[j], NOofblock, j); //decide which miss type this miss belong to
							cc = 1;
							z = (assoc * 2);
						}
						else
						{
							if (x < lru[index][z])
							{
								x = lru[index][z];
								y = z;
							}
							if (z == ((assoc * 2) - 2))
							{
								newarray[index][y + 1] = tag;
								misscount++;
								c = misstype(blockaddress[j], NOofblock, j);
								cc = 1;
								for (m = 0; m < (assoc * 2); m = m + 2)
									lru[index][m]++;
								lru[index][y] = 0;
							}
							z = z + 2;
						}
					}
				}
			}

			if (c == 1 && cc == 1)
				c1c++;
			if (c == 2 && cc == 1)
				c2c++;
			if (c == 3 && cc == 1)
				c3c++;
		}
		else                        //fully associativity
		{
			while (z <= NOofblock)
			{

				cc = 0;
				if (newarray[z][0] == 0)                //valid bit is 0 
				{
					newarray[z][1] = blockaddress[j];   // staore the block address in the new array
					newarray[z][0] = 1;                // valid bit set to 1
					misscount++;
					c = misstype(blockaddress[j], NOofblock, j);
					cc = 1;
					for (m = 0; m <= NOofblock; m++)
						lru[m][1]++;
					lru[z][1] = 0;
					z = (NOofblock + 1);
				}
				else                                  // valid bit is 1
				{
					if (newarray[z][1] == blockaddress[j])// tag already in the array
					{
						hitcount++;
						for (m = 0; m <= NOofblock; m++)
							lru[m][1]++;
						lru[z][1] = 0;
						z = NOofblock + 1;
					}
					else
					{
						if (x < lru[z][1])
						{
							x = lru[z][1];
							y = z;
						}
						if (z == NOofblock)
						{
							newarray[y][1] = blockaddress[j];
							misscount++;
							c = misstype(blockaddress[j], NOofblock, j);
							cc = 1;
							for (m = 0; m <= NOofblock; m++)
								lru[m][1]++;
							lru[y][1] = 0;
						}
						z++;
					}
				}
			}
			if (c == 1) c1c++;
			if (c == 2) c2c++;
			if (c == 3) c3c++;
		}
	}

	missrate = (misscount / accesscount);
	hitrate = (hitcount / accesscount);
	printf("\n        Miss Rate = %3f \n", missrate);
	printf("\n         Hit Rate = %3f \n", hitrate);
	printf("\n  Compulsory Miss = %3d \n", c1c);
	printf("\n    Capacity Miss = %3d \n", c3c);
	printf("\n    Conflict Miss = %3d \n", c2c);
	printf("\n       hit Number = %3f \n", hitcount);
	printf("\n      miss Number = %3f \n", misscount);
	printf("\n    Access Number = %3f \n", accesscount);
	return 0;
}

int misstype(int ba, int nb, int l) // this function is used to decide which miss type it's belong to
{
	int u, k = 0, b = 0, n = 0, m, ii;
	int blarray[500];
	int type;
	for (ii = 0; ii < 500; ii++)          // initila the array
		blarray[ii] = 9999;
	for (u = 0; u <= t; u++)               // check if the block address already in the array
	{
		if (before[u] == ba)          //if the block address in the before array
		{
			k = 0;
			break;
		}
		else
			k = 1;
	}
	if (k == 1)                        // compulsory miss
	{
		type = 1;
		before[t] = ba;
		t++;
	}
	if (k == 0)						//capacity or conflict miss	
	{
		for (u = (l - 1); u >= 0; u--)
		{
			if (blockaddress[u] == ba)	// current address is refered before	
			{
				break;
			}
			else
			{
				n = 0;
				for (m = 0; m <= b; m++)
				{
					n++;
					if (blarray[m] == blockaddress[u])	 //it it's not a distinct address, then break
						break;
				}

				if (n == (b + 1))
				{
					blarray[b] = blockaddress[u];		//store the address in the blarray 
					b++;					        //blarray[b+1] to store next address
				}
			}
		}
		if ((b) < nb)						//conflict miss
			type = 2;
		else						    // capacity miss
			type = 3;
	}
	return type;
}







