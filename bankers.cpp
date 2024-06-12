#include<iostream>

using namespace std;
const int max_pro = 10;
const int max_res = 10;

int main(){
	int n,m;
	cout<<"Enter number of process";
	cin>>n;
	cout<<"Enter number of resources";
	cin>>m;
	
	int alloc[max_pro][max_res];
	int max[max_pro][max_res];
	int avail[max_res];
	int need[max_pro][max_res];
	
	cout<<"enter allocation matrix:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>alloc[i][j];
		}
	}
	cout<<"enter maximum matrix:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>max[i][j];
		}
	}
	cout<<"enter available vector:"<<endl;
		for(int j=0; j<m; j++){
			cin>>avail[j];
	}
	cout<<"need matrix: "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			need[i][j] = max[i][j] - alloc[i][j];}
	}
	bool safe = false;
	bool marked[max_pro] = {false};
	int safeseq[max_pro];
	int safeindex = 0;
	while(!safe){
		safe = true;
		for(int i = 0; i <n; i++){
			if(!marked[i]){
				bool canExecute = true;
				for(int j = 0; j<m; j++){
					if(need[i][j] > avail[j]){
						canExecute = false;
						break;
					}
				}
				if(canExecute){
					marked[i] = true;
					safeseq[safeindex++] = i;
					for(int j = 0; j < m; j++){
						avail[j]+=alloc[i][j];
					}
					safe = false;
				}
			}
		}
	}
	cout<<"safe sequence: "<<endl;
	for(int i = 0; i <n; i++){
		cout<<"P"<< safeseq[i]<<" ";
	}
	cout<<endl;
	return 0;
}