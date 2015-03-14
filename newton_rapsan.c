#include<stdio.h>
#include<math.h>
double function(double x){
	return exp(-x)-x;

}

double dif(double x){
	return -exp(-x)-1;
}
double newton_rapson(double (*p)(double), double upper ,double lower){
	double mid = (upper+lower)/2;
	double ans =0;
	for(int i=0;i<5;i++){
		ans = mid -(p(mid)/dif(mid));
		printf("%f\n",ans );
		mid =ans;
	}
}
int main(){
double upper =1;
double lower =0;
newton_rapson(function,0,1);


}