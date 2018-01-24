#include <stdio.h>

void primeFactors(int n)
{
  	static int k=2; if(k>n) return;
 	if(n%k==0)
    {
      printf("%d\n",k); primeFactors(n/k);
    }
    else{
    k = nextPrime(k);
    primeFactors(n);
    }

}

int isPrime(int n)
{
  if(n<=1) return 0;
  if(n<=3) return 1;
  if(n%2==0 || n%3==0) return 0;
  int i;
  for(i=5;i*i<=n;i++)
  {
    if(n%i==0 || n%(i+2)==0) return 0;
  }
  return 1;
}
int nextPrime(int n)
{
  if(n==2) return 3;
  if(n%2==0) n++;
  else n+=2;
  while(isPrime(n)!=1) n+=2;
  return n;
}

  int main()
{
	int a,b;
	scanf("%d", &a);
	primeFactors(a);
}
