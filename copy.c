#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define lli long long int

lli calc_contd_frac_val_x(lli D)
{
 double Alpha=floor(sqrt((double)D));

 return (lli)floor(((sqrt((double)D)+Alpha)/((double)D-pow(Alpha,2.0))));
}

int Perfect_square_x(int D)
{
 float temp=(float)sqrt((float)D);
 int temp1=temp;

 return (temp1 ==temp)?1:0;
}

int contd_frac_x(lli frac[],lli depth,lli a,double b)
{
 lli n=(lli)floor(1.0/(b-(double)a));
 printf("a=%lld b=%lf n=%lld\n",a,b,n);

 if(depth <=1)
 {
  frac[1]=a*n+1;
  frac[0]=n;
  return 0;
 }
 
 contd_frac_x(frac,depth-1,n,(1/(b-(double)a)));

 lli temp=n*frac[1]+frac[0];
 frac[0]=frac[1];
 frac[1]=temp;

 return 1;
}

int main()
{
 lli frac[2],itrs,D,lar_D=INT_MIN,lar_x=INT_MIN;

 for(D=13;D<=13;D++)
 {
  if(!Perfect_square_x(D))
  {
   for(itrs=5;itrs<=5;itrs++)
   {
//    printf("%lld\n",calc_contd_frac_val_x(D));
    contd_frac_x(frac,itrs,(lli)floor(sqrt(D)),sqrt(D));
    
//    printf("%lld/%lld\n",frac[0],frac[1]);
/*    lli exp=(frac[0]*frac[0])-D*(frac[1]*frac[1]);
//    printf("%lf\n",exp);
    if(exp ==1)
    {
     printf("%lld) %lld %lld\n",D,frac[0],frac[1]);
   
     break;
    }*/

   }
  }
 }
 
 printf("%d %d\n",lar_x,lar_D);
 return 0;
}
