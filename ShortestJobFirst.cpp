#include<iostream>
#include<algorithm>
using namespace std;
const int max_pro=10;
const int max_res=10;
class Process{
    public:
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    
    Process(): id(0), at(0), bt(0), ct(0), tat(0), wt(0) {}
};
bool compAT(Process a, Process b){
    return a.at < b.at;
}
bool compBT(Process a, Process b){
    return a.bt < b.bt;
}
void calcCT(Process proc[], int n){
    int currtime = 0;
    for(int i = 0; i < n; i++){
        if(currtime < proc[i].at)
        currtime = proc[i].at;
        currtime += proc[i].bt;
        proc[i].ct= currtime;
    }
}
void calcTAT(Process proc[], int n){
    for(int i = 0; i < n; i++){
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}
void calcWT(Process proc[], int n){
    for(int i = 0; i < n; i++){
        proc[i].wt = proc[i].tat - proc[i].bt; 
    }
}
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    
    Process proc[n];
    
    cout<<"Enter arival time and burst time for each process: \n";
    for(int i = 0; i < n; i++){
        proc[i].id = i+1;
        cout<<"Process "<<i+1<<" - Arival time: ";
        cin>>proc[i].at;
        cout<<"Process "<<i+1<<" - Burst time: ";
        cin>>proc[i].bt;}
        
        //sort process baised on arival time
        sort(proc, proc+n, compAT);
        //sort process baised on burst time
        sort(proc, proc+n, compBT);
        
        calcCT(proc,n);
        calcTAT(proc,n);
        calcWT(proc,n);
        
        cout<<"Process\t\tArival\t\tBurst\t\tCompletion\t\tTurnaround\t\tWaiting"<<endl;
        for(int i = 0; i < n; i++){
            cout<<proc[i].id<<"\t\t\t"<<proc[i].at<<"\t\t\t"<<proc[i].bt<<"\t\t\t"<<proc[i].ct<<"\t\t\t"<<proc[i].tat<<"\t\t\t"<<proc[i].wt<<endl;
        }
    //avg tat and avg wt
    double totaltat, totalwt;
    for(int i = 0; i < n; i++){
        totaltat += proc[i].tat;
        totalwt += proc[i].wt;
    }
    cout<<"Average Turnaround time "<<totaltat/n<<endl;
    cout<<"Average Waiting time "<<totalwt/n<<endl;
    return 0;
}