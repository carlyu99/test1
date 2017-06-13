#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 20;

int difs[MAXN * 2], num;

void search(int last_note, int left_notes)
{
	if (left_notes == 0)
	{
		difs[num] = 12 - last_note;
		
		if (difs[0] < difs[num])
			// Wrong if n >= 6. Should be change to the maximum suffix in the double-string.
			return;
		
		for (int i = 0; i <= num; i++)
			printf("%d ", difs[i]);
		printf("\n");
		return;
	}
	
	for (int i = last_note + 1; i <= 11; i++)
	{
		difs[num] = i - last_note;
		
		if (difs[0] < difs[num])
			break;
		
		num++;
		search(i, left_notes - 1);
		num--;
	}
}

void chord(int n = 3)
{
	
	num = 0;
	search(0, n - 1);
}

int main()
{
	chord(4);
	
	return 0;
}


