#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define lli long long int

int Perfect_square_x(int D)
{
 float temp=(float)sqrt((float)D);
 int temp1=temp;

 return (temp1 ==temp)?1:0;
}

int contd_frac_x(lli frac[][2],lli D)
{
 lli i,a;
 float tmp=(float)sqrt((double)D);

 for(i=0;i<=1000;i++)
 {
  // Precision Issue use cyclic method
  a=floor(tmp);
  tmp=1.0f/(tmp-(float)a);
  //................

  if(i ==0)
  {
   frac[i][0]=a;
   frac[i][1]=1;
  }
  else
  {
   if(i ==1)
   {
    frac[i][0]=frac[0][0]*a+1;
    frac[i][1]=a;    
   }
   else
   {
    frac[i][0]=frac[i-1][0]*a+frac[i-2][0];
    frac[i][1]=frac[i-1][1]*a+frac[i-2][1];    
   }
  }
 }
}

int main()
{
 lli frac[1001][2],itrs,D,lar_D=INT_MIN,lar_x=INT_MIN;  //0 Num, 1 Den

 for(D=61;D<=61;D++)
 {
  if(!Perfect_square_x(D))
  {
    contd_frac_x(frac,D);
    
    for(itrs=0;itrs<=1000;itrs++)
     printf("%lld) %lld/%lld\n",itrs,frac[itrs][0],frac[itrs][1]);

    if(frac[0] <0 || frac[1] <0)
    {
     printf("%lld PREMATURE EXIT\n",D);
     exit(0);
    }
/*    lli exp=(frac[0]*frac[0])-D*(frac[1]*frac[1]);

    if(exp ==1)
    {
//     printf("%lld) %lld %lld\n",D,frac[0],frac[1]);
     
     if(frac[0] >lar_x)
     {
      lar_x=frac[0];
      lar_D=D;
     }

     break;
    }*/

  }
 }
 
 printf("%d %d\n",lar_x,lar_D);
 return 0;
}
