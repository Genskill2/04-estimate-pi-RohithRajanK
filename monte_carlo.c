#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int n);
float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
    }
  }
}
float mc_pi(int n)
{
	
	float circlepoint=0,temp,temp1,temp2;
	float pei;
	for(int i=1;i<=n;i++)
	{
	temp=frandom();
	temp1=frandom();
	temp2=sqrt(((temp-0)*(temp-0))-((temp1-0)*(temp1-0)));
	if(temp2<1)
	{
	circlepoint=circlepoint+1;	
	}
	}
	pei=((4*circlepoint)/n);
	return(pei);

		
}


