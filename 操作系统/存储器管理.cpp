#include<iostream>
#include<queue>
#define f(i,a,b) for(int i=a;i<b;i++) 
#define ct cout
using namespace std;
struct Tb{  // ���Ľṹ�� 
	int num,l,srt,s;// ��š����ȡ���ʼ��״̬(0δ���䣬1����) 
	bool operator < (const Tb& b)const{return l>b.l;} // ���� < 
};
class B{  // �� 
private:
	int n;    // ������ 
	Tb* T; // �� 
	priority_queue<Tb> Q; //����Ķ��� 
public:
	B();          // ���� 
	void Alloc();     // ���� 
	void Free();      // ���� 
	void ShowTable(); // չʾ		
};
int main(){
	B Bl;
	while(1){
		ct<<"\n**************************\n";
		ct<<"what do you wang to do?\n";
		ct<<"   1 ����ռ�\n"<<"   2 �ͷſռ�\n";
		ct<<"   3 ��ʾ����˵����\n"<<"   4 �˳�\n";
		ct<<"you input :   ";
		int tp;cin>>tp;
		if(tp==1)Bl.Alloc();
		else if(tp==2)Bl.Free();
		else if(tp==3)Bl.ShowTable();
		else break;
	} 
}
B::B(){// �������� 
	ct<<"�������������\n";cin>>n;
	T=new Tb[n];
	f(i,0,n){
		ct<<"������No."<<i<<":\n"<<"������������ȣ�";
		cin>>T[i].l;
		ct<<"���������ʼ��ַ��";
		cin>>T[i].srt;
		T[i].s=0;T[i].num=i;
	}
} 
void B::ShowTable(){ // չʾ���� 
	ct<<"\n ���� \t ���� \t ʼַ \t ״̬ \n";
	f(i,0,n){
	printf("|%d\t|%d\t",T[i].num,T[i].l); 
	printf("|%d\t|%d\t\n",T[i].srt,T[i].s); 
	}
}
void B::Alloc(){ //���� 
	f(i,0,n)if(T[i].s==0)Q.push(T[i]);
	int bn,fg=0,cnt=0;
	ct<<"(1) Malloc: how many do you want:(K)   ";
	cin>>bn;
	while(!Q.empty()){
		Tb tp=Q.top();
		Q.pop();
		if(bn<=tp.l&&fg==0){
			ct<<"����ɹ�,�������ǣ�"<<tp.num<<endl;
			fg=1;
			T[tp.num].s=1;
		}
	}
	if(fg==0)ct<<"����ʧ��\n";
}
void B::Free(){ // ���� 
	ct<<"(2) Free: where do you want to free:";
	int handle;cin>>handle;
	f(i,0,n)if(T[i].s==1){
		ct<<"�ͷųɹ�\n";
		T[i].s=0;
		return; 
	}
	ct<<"�ͷ�ʧ��\n";
}
