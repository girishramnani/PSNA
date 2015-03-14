#include<iostream>

using namespace std;

double mul_p(double p, int i){
	double ans=1;
	if(i%2==0){
		ans*=(p*p);
	}
	else{
		ans*=(p);
	}
	int a = (i-1)/2;
	for(int i=1;i<=a;i++){
		
		ans*=((p*p)-(i*i));

	}
	return ans;

}


int fact(int num){

	if (num ==1){
		return 1;
	}
	return num*fact(num-1);

}
double sterling(double *arr,int n,double p){
	
	double ans[n][n];
	int i=0;
	int j=0;
	for(i=0;i<n;i++){
		ans[0][i]=arr[i];
		
	}
	
	for(i=1;i<n;i++){
		for( j=0;j<n-i;j++){
			ans[i][j] = ans[i-1][j+1]-ans[i-1][j];
			
		}
	}
	for(i=0;i<n;i++){
		
		for(j=0;j<n-i;j++){
			printf("%f ",ans[j][i]);
		}
		cout <<endl;

	}
	double Yp=0;
	int o=n/2;
	Yp+=ans[0][o];
	for(int i=1;i<n;i++){
		double dely;
		if(i%2!=0){
		dely=(ans[i][o-i/2]+ans[i][o-(i/2)-1])/2;
		}
		else{
		dely = (ans[i][o-i/2]);
		}
		double mpx = mul_p(p,i);
		printf(" i = %d  dely = %f  mpx= %f\n",i,dely,mpx );
		Yp+=((mpx/fact(i))*dely);


	}


	return Yp;
}

	


int main(int argc, char const *argv[])
 {
 	int n;
 	// cin >> n;
 	double test=12.2;
 	// for(int i=0;i<n;i++){
 	// 	cin >>number[i];
 	// }
 	double number[] ={0.23967,0.28060,0.31788,0.35209,0.3868};
 	int x[] = {10,11,12,13,14};
 	
 	double p = (test -x[2])/(x[1]-x[0]);
 	double ans =sterling(number,5,p);
 	printf("%f\n",mul_p(p,4));
 	printf("%f\n",ans);

 	return 0;
 } 