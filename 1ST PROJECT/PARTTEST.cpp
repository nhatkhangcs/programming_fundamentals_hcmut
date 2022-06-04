#include <bits/stdc++.h>
using namespace std;

int main()
{
	int HP1, EXP1, M1, E3;
	cin >> HP1 >> EXP1 >> M1 >> E3;
	
	//road 1
	
	int P1[9];
	int t = 1;
	int count1 = 0;
	for (int i = 0; i < 9; i++)
	{
		P1[i] = fmod((t+E3),26) + 65;
		if (P1[i] == 80)
		{
			count1 ++;
			HP1 = HP1 - P1[i]*(i+1)*2;
			EXP1 = EXP1 + fmod((1000-P1[i]*(i+1)),101);
			M1 = ceil(M1 - E3*1.0/9*(i+1));
		}
		t = t + 2;
	}
	
	if (count1 == 0) M1 = ceil(M1 - E3*1.0/9 * pow(9,2));
	if (EXP1 > 900) EXP1 = 900;
	if (EXP1 < 0) EXP1 = 0;
	if (M1 > 2000) M1 = 2000;
	if (M1 < 0) M1 = 0;	
	if (HP1 > 999) HP1 = 999;
	if (HP1 < 0) HP1 = 0;
	
	//road 2
	
	int count2 = 0;
	int P2[7] = {2,3,5,7,11,13,17};
	int S = 0;
	for (int i = 0; i < 7; i++)
	{	
		P2[i] = fmod((P2[i]+E3),26);
		S = S + P2[i];
	}
	int m = ceil(S*1.0/7);
	
	for (int i = 0; i < 7; i++)
	{
		P2[i] = fmod((P2[i] + S + m),26) + 65;
	}
	
	for (int i = 0; i < 7; i++)
	{
		if (P2[i] == 80)
		{
			count2 ++;
			HP1 = HP1 - P2[i]*(i+1)*2;
			EXP1 = EXP1 + fmod((1000 - P2[i]*(i+1)),101);
			M1 = ceil(M1 - E3*1.0/9 * (i+1));
		}
	}
	
	if (count2 == 0) M1 = ceil(M1 - E3* 1.0/9 * 49);
	if (EXP1 > 900) EXP1 = 900;
	if (EXP1 < 0) EXP1 = 0;
	if (M1 > 2000) M1 = 2000;
	if (M1 < 0) M1 = 0;
	if (HP1 > 999) HP1 = 999;
	if (HP1 < 0) HP1 = 0; 

	//road 3
	
	int P3[20];
	int b = 2;
	int count3 = 0;
	for (int x = 0; x < 20; x++)
	{
		P3[x] = b*b;
		b += 2;
	}
	
	int ma = fmod((P3[0] + pow(E3,2)),113);
	
	for (int x = 1; x < 20; x++)
	{
		P3[x] = fmod(P3[x] + pow(E3,2),113);
		if (P3[x] > ma) ma = P3[x];
	}
	
	for (int x = 0; x < 20; x++)
	{
		P3[x] = fmod(ceil((P3[x] + E3)/ma),26)+65;
		if (P3[x] == 80)
		{
			count3 ++;
			HP1 = HP1 - P3[x]*(20-x)*3;
			EXP1 = EXP1 + (3500-P3[x]*(20-x))%300;
			M1 = ceil(M1 - E3*1.0/9 * (20-x));
		}
	}
	if (count3 == 0) M1 = ceil(M1 - E3*1.0/9*400);
	if (EXP1 > 900) EXP1 = 900;
	if (EXP1 < 0) EXP1 = 0;
	if (M1 > 2000) M1 = 2000;
	if (M1 < 0) M1 = 0;
	if (HP1 > 999) HP1 = 999;
	if (HP1 < 0) HP1 = 0;
	
	//road 4
	
	int temp = 0;
	int count4 = 0;
	int P4[12] = {31 , 28 , 31, 30 ,31 ,30 ,31 , 31 ,30 , 31, 30, 31};
	int min = fmod(P4[0] + ceil(pow((E3/29),3)),9);
	
	for (int i = 1; i < 12; i++)
	{
		P4[i] = fmod(P4[i] + ceil(pow((E3/29),3)),9);
		if (P4[i] < min) 
		{
			min = P4[i];
			int temp = i+1;
		}
	}
	
	for (int i = 0; i < 12; i++)
	{
		P4[i] = fmod(((P4[i]+E3)*ceil(min*1.0/temp)),26)+65;
		if (P4[i] == 80)
		{
			count4 ++;
			HP1 = HP1 - P4[i]*(12-i)*4;
			EXP1 = EXP1 + fmod(4500-P4[i]*(12-i),400);
			M1 = ceil(M1 - E3* 1.0/9* (12-i));
		}
	}
	
	if (count4 == 0) M1 = ceil(M1 - E3*1.0/9 *144);
	if (EXP1 > 900) EXP1 = 900;
	if (EXP1 < 0) EXP1 = 0;
	if (M1 > 2000) M1 = 2000;
	if (M1 < 0) M1 = 0;
	if (HP1 > 999) HP1 = 999;
	if (HP1 < 0) HP1 = 0;
	
	
	int count = count1 + count2 + count3 + count4;
	if (count == 0) 
		{
			HP1 = HP1 - fmod((E3*59),900);
			EXP1 = EXP1 - fmod((E3*79),300); 
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (HP1 > 999) HP1 = 999;
			if (HP1 < 0) HP1 = 0;
			return -1
		}
		
	else
	{
		if (EXP1 > 900) EXP1 = 900;
		if (EXP1 < 0) EXP1 = 0;
		if (HP1 > 999) HP1 = 999;
		if (HP1 < 0) HP1 = 0;
	} 
	
	cout << HP1 << " " << EXP1 << " " << M1;
}

