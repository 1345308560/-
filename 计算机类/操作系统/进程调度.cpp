#include<iostream>
#include<string>
#include<queue> 
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++) 
struct PCB{
	string Na; //���� 
	int P,Ar,Rt,Rta,Sta;        
    //����������ʱ�� ����ʱ�� ������ʱ�� ״̬��0���� 1���� 2��� �� 
	bool operator<(const PCB& b) const{return P<b.P;}
}; 
priority_queue<PCB> Q; //��������
void Print_PCB(PCB A);
bool fc(PCB* P,int n,int ti); 
int main(){
	int n;            // ������ 
	cout<<"�������������"<<endl;cin>>n;
	PCB* P=new PCB[n];// PCB�ṹ 
	cout<<"������������֡�������������ʱ�䡢��Ҫ����ʱ�䣺"<<endl;
	f(i,0,n){ // ������Ϣ 
		cin>>P[i].Na>>P[i].P>>P[i].Ar>>P[i].Rt;
		P[i].Rta=0;P[i].Sta=2;
	}
	f(i,0,100)if(fc(P,n,i))break;
} 
void Print_PCB(PCB A){
	cout<<"-----------------------"<<endl;
	cout<<"�������ƣ�"<<A.Na<<endl;
	cout<<"��������"<<A.P<<endl;
	cout<<"����ʱ�䣺"<<A.Ar<<endl;
	cout<<"������ʱ�䣺"<<A.Rt<<endl;
	cout<<"������ʱ�䣺"<<A.Rta<<endl;
	cout<<"״̬:"; 
	if(A.Sta==1) cout<<"����"<<endl;
	else if(A.Sta==2) cout<<"����"<<endl;
	else cout<<"���"<<endl; 
}
bool fc(PCB* P,int n,int ti){
	// �������Ѿ�������δ��ɣ������������ 
	f(i,0,n)if(P[i].Ar<=ti&&P[i].Sta!=3)Q.push(P[i]);	
	PCB temp=Q.top();	// �õ�������ȼ� 
	int ct;
	f(i,0,n)if(P[i].Na==temp.Na)ct=i;
	P[ct].Sta=1; // ��Ϊ����״̬ 
	Q.pop();           // ���������� 
	cout<<"****************"<<"ʱ��"<<ti<<"********************"<<endl;
	cout<<"��ǰ�������еĳ���Ϊ��"<< temp.Na<<endl;        // ���� 
	cout<<"�������У�";                                      // �������� 
	while(!Q.empty()){
		PCB t=Q.top();
		cout<<t.Na<<" ";
		Q.pop();
	}
	cout<<endl; 
	f(i,0,n)Print_PCB(P[i]); // ��ӡ״̬ 
	P[ct].Rta+=1;         // ����ʱ��+1 
	P[ct].P-=1;           // ���ȼ�-1 
	if(P[ct].Rta>=P[ct].Rt) P[ct].Sta=3;// ��� 
	else P[ct].Sta=2;  //����״̬ 	
	f(i,0,n)if(P[i].Sta!=3)return false;// �޸�״̬ 
	cout<<"ȫ����ɣ�����"; 
	return true;
}

