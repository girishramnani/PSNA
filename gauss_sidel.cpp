#include<stdio.h>


int main(int argc, char const *argv[])
{
	const int n=3;
	double coef[n][n+1] ={3,-0.1,-0.2,7.85,0.1,7,-0.3,-19.3,0.3,-0.2,10,71.4};
	double sym[n];
	for(int i=0;i<n;i++){
		sym[i]=0;
	}

	// for(int i=0;i<5;i++){

	
	// 	x = (1/coef[0][0])*(coef[0][3]-coef[0][1]*y - coef[0][2]*z);
	// 	y = (1/coef[1][1])*(coef[1][3]-coef[1][0]*x - coef[1][2]*z);
	// 	z = (1/coef[2][2])*(coef[2][3]-coef[2][0]*x - coef[2][1]*y);
	// }

	// for general 
	for(int i=0;i<4;i++){


	for(int j=0;j<n;j++){
			double temp;
			temp=0;
			for(int k =0; k<n;k++){
				if (k==j){
					continue;
				}
				temp+=(coef[j][k]*sym[k]);
			}
			sym[j] = (1/coef[j][j])*(coef[j][n]-temp);
			
		}
	}
	printf("%f %f %f\n",sym[0],sym[1],sym[2] );
	return 0;
}