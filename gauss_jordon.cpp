#include<stdio.h>
#include<iostream>
using namespace std;


double display(double coef[3][4]){
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			printf("%f ",coef[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	const int n=3;
	// scanf("%d",n);
	double coef[n][n+1] = {{3,0.1,0.2,7.85},{0.1,7,0.3,-19.3},{0.3,0.2,10,71.4}};
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			double temp = coef[j][i]/coef[i][i];
			for(int k=0;k<=n;k++){
				coef[j][k] -=temp*(coef[i][k]);
			}
		}
		display(coef);

	}
	for(int i=n-1;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			double temp = coef[j][i]/coef[i][i];
			for(int k=0;k<=n;k++){
				coef[j][k] -=temp*(coef[i][k]);
			}
		}
	display(coef);
	}
	for(int i=0;i<n;i++){
			printf("%f\n",coef[i][n]/coef[i][i] );
	}
	return 0;
}