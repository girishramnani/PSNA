#include<iostream>

using namespace std;


void forward(int *arr,int n){
	int ans[n][n];
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
		
		for(j=0;j<n-i-1;j++){
			cout<<ans[j][i]<<" ";
		}
		cout <<endl;

	}
	
}

	


int main(int argc, char const *argv[])
 {
 	int n;
 	cin >> n;
 	int number[n];
 	for(int i=0;i<n;i++){
 		cin >>number[i];
 	}
 	forward(number,5);
 	

 	return 0;
 } 