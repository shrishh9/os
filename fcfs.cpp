
#include <iostream>
#include <iomanip>
using namespace std;
class Process{
    public:
    int id;
    int bt;
    int at;
    int ct;
    int tat;
    int wt;
    
    Process(): id(0), bt(0), at(0), ct(0), tat(0), wt(0) {} 
};

void calcCT(Process proc[], int n){
    int currenttime=0;
    for(int i=0; i<n; i++){
        if(currenttime< proc[i].at){
            currenttime=proc[i].at;
            currenttime+=proc[i].bt;
            proc[i].ct=currenttime;
        }
    }
}
void calcTAT(Process proc[], int n){
    for (int i=0; i<n; i++){
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}
void calcWT(Process proc[], int n){
    for (int i=0; i<n; i++){
        proc[i].wt = proc[i].tat - proc[i].bt;
    }
}
int main() {
    int n, choice;
    cout<<"Enter number of process: ";
    cin>>n;
    
    Process proc[n];
    
    cout<<"Choose mode for arival time: \n";
    cout<<"1. Arival time for all process= 0\n";
    cout<<"2. Specify arival time and bust time for each process\n ";
    cout<<"enter your choice (1/2): ";
    cin>>choice;
    
    switch (choice){
        case 1:
        for (int i=0; i<n; i++){
            proc[i].id = i+1;
            proc[i].at = 0;
            cout<<"Enter burst time for process"<<i+1<<":";
            cin>>proc[i].bt;
        }
        break;
        case 2:
        cout<<"Enter arival time and burst time for each process: ";
        for (int i=0; i<n; i++){
        	proc[i].id = i+1;
            cout<<"process "<<i+1<<" - arival time: ";
            cin>>proc[i].at;
            cout<<"process "<<i+1<<" - burst time: ";
            cin>>proc[i].bt;
        }
        break;
        default:
        cout<<"invalid choice";
        return 1;
    }
    calcCT(proc,n);
    calcTAT(proc, n);
    calcWT(proc, n);
    cout<<left<<setw(10)<<"Process"<<setw(15)<<"Arivaltime"<<setw(15)<<"Bursttime"<<setw(20)<<"Completiontime"<<setw(20)<<"Turnaroundtime"<<setw(15)<<"Waitingtime"<<endl;
    for( int i=0; i<n; i++){
        cout<<left<<setw(10)<<proc[i].id<<setw(15)<<proc[i].at<<setw(15)<<proc[i].bt<<setw(20)<<proc[i].ct<<setw(20)<<proc[i].tat<<setw(15)<<proc[i].wt<<endl;
    }
    //avg turnaround time and avg waiting time
    double totalTAT=0, totalWT=0;
    for(int i=0; i<n; i++){
        totalTAT+=proc[i].tat;
        totalWT+=proc[i].wt;}
        cout<<"Average Turnaround time: "<<totalTAT/n<<endl;
        cout<<"Average Waiting time: "<<totalWT/n<<endl;
    return 0;
}