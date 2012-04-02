#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void num24();
int num21();
int num21(int limit);
int num8();
int num6();
int num2();
int num1();

int main()
{
	cout << "Number 21: " << num21() << endl;

	return 0;
}

void num24()
{
	int nums[] = {0,1,2,3,4,5,6,7,8,9};
	int final[10];
	int perms = 1000000;

	for(int i = 10; i >= 2 && perms > 0; i--)
	{
		//number of permutations for digit
		int temp = 1;
		for(int j = 2; j < i; j++)
			temp *= j;
		
		int count = 0;
		while(perms > (count + 1) * temp)
			count++;
		//count now has index of next digit

		perms -= count * temp; //how many permutations left to go
		
		for(int j = 0; j <= count; j++)
		{
			if(nums[j] == -1)
				count++;
		}
				
		final[10-i] = nums[count];
		cout << nums[count];	
		nums[count] = -1; //can no longer use this digit
	}

	for(int i = 0; i < 10; i++)
	{
		if(nums[i] != -1)
			cout << nums[i];
	}
}

int num21()
{
	return num21(10000);
}

int num21(int limit)
{
	int amicableSum = 0;
	
	for(int i = 1; i < limit; i++)
	{
		int d1 = 0, d2 = 0;
		
		for(int j = 1; j <= i/2; j++) //only need to look at bottom half for divisors
		{
			if(i % j == 0)
				d1 += j;
		}
		
		if(d1 < i) //avoid double counting pairs
		{
			for(int j = 1; j <= d1/2; j++)
			{
				if(d1 % j == 0)
					d2 += j;
			}
			
			if(d2 == i)
			{
				//cout << d1 << " and " << d2 << endl;
				amicableSum += (d1 + d2);
			}
		}
	}
	
	return amicableSum;
}

int num8()
{
	string bigNum = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	int prod = 0;

	for(int i = 0; i < bigNum.length() - 4; i++)
	{
		string temp = "";

		for(int j = 0; j < 5; j++)
			temp += bigNum[i+j];
		
		int fiveDigits = atoi(temp.c_str());
		int test = fiveDigits / 10000;
		fiveDigits -= (test * 10000);

		for(int i = 3; i >= 0; i--)
		{
			int temp = fiveDigits / pow(10,i);
			test *= temp;
			fiveDigits -= (temp * pow(10,i));
		}

		if(test > prod)
			prod = test;
	}

	return prod;
}

int num6()
{
	int sumOfSq = 0, sqOfSum = 0;

	for(int i = 1; i <= 100; i++)
	{
		sumOfSq += i * i;
		sqOfSum += i;
	}

	sqOfSum *= sqOfSum;

	return sqOfSum - sumOfSq;
}

int num2()
{
	int fib1 = 1, fib2 = 2, fib3, sum = 2;

	do
	{
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;

		if(fib3 % 2 == 0)
			sum += fib3;
	}
	while(fib3 < 4000000);

	return sum;
}

int num1()
{
	int ans = 0;

	for(int i = 0; i < 1000; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
			ans += i;
	}
	
	return ans;
}
