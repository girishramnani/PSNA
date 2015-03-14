#include<stdio.h>
#include<math.h>
void function(int p,int array[],int deg,float a,float b,float f_a,float f_b,float x)
{
int check;
for(check=0; ;check++)
{
   float x1=((a*f_b)-(b*f_a))/(f_b-f_a);
   int i;
   float total=0;
   float power=pow(10,-(p+1));
   for(i=0;i<=deg;i++)
      {
      float h=pow(x1,i);
      total=total+(h*array[i]);
      }
   if (abs(x-x1)<=power)
      {
      printf("The root is %d",x1);
      break;
      
      }
   else if (total>0)
       {
        b=x1;
        x=x1;
        f_b=total;
        }
        
    else
        {
         a=x1;
         x=x1;
         f_a=total;
         }
}
}





float answer(int i,int deg,int arr[])
{

float cnt=0;
int cnt1=0;


for(cnt1=0;cnt1<=deg;cnt++)
{
  float p=pow(i,cnt1);
  cnt=cnt+(p*arr[cnt1]);
}
    return cnt;
    
}



void main()
{
int degree;
int array[5];
int k=0;
float a1,b1;
float sum1=0,sum2=0;
int prec;
int r=0;
float x1,x2,x3,x4;

printf("\n\nEnter the precision factor: \n");
scanf("%d",&prec);

printf("Enter the degree of polynomials:\n");
scanf("%d",&degree);

   for(k=0;k<=degree;k++)
    {
      printf("Enter the coeffecient of degree %d\n",k);
      scanf("%d",&array[k]);
    }
    
    for(r=1; ;r++)
    {
      x1=answer(r,degree,array);
      x2=answer(-r,degree,array);
      x3=answer(r-1,degree,array);
      x4=answer(-(r-1),degree,array);
      
      if(x1>0 && x3<0)
         {
          
         a1=r-1;
         b1=r;
         break; 
         } 
      else if(x1<0 && x3>0)
      {
        a1=r;
        b1=r-1;
        break;
      }
    
     else if(x2>0 && x4<0)
     {
      a1=-(r-1);
      b1=-r;
      break;
     }
     
     else if(x2<0 && x4>0)
     {
       a1=-r;
       b1=-(r-1);
       break;
     }
     else
     	continue;
    }
   sum1=answer(a1,degree,array);
   sum2=answer(b1,degree,array);
   printf("\n %f %f",sum1,sum2);
function(prec,array,degree,a1,b1,sum1,sum2,0);

}
  






