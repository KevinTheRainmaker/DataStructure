#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
		if(num == 1)    // 이동할 원반의 수가 1개라면
				printf("원반1을 %c에서 %c로 이동 \n", from, to);
		else
		{
				HanoiTowerMove(num-1, from, to, by);
				printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);
				HanoiTowerMove(num-1, by, from, to);
		}
}

int main()
{
		// 막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
		HanoiTowerMove(3, 'A', 'B', 'C');
		return 0;
}


>> 원반1을 A에서 C로 이동
>> 원반2을(를) A에서 B로 이동
>> 원반1을 C에서 B로 이동
>> 원반3을(를) A에서 C로 이동
>> 원반1을 B에서 A로 이동
>> 원반2을(를) B에서 C로 이동
>> 원반1을 A에서 C로 이동
