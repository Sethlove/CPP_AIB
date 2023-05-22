#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<string>
using namespace std;
class Student{
    private :
        string name,room,dob,sex;
        int id;
    public :
        void input(){
            cout<<"ID : ";cin>>id;
            cin.ignore();
            cout<<"Name : "; getline(cin,name);
            cout<<"Sex : ";cin>>sex;
            cout<<"Date of Birth : ";cin>>dob;
            cout<<"Room : ";cin>>room;
        }
        void information(){
            cout<<setw(10)<<id;
            cout<<setw(12)<<name;
            cout<<setw(12)<<sex;
            cout<<setw(16)<<dob;
            cout<<setw(10)<<room<<endl;
        }
        void headIF(){
            cout<<setw(10)<<"Id";
            cout<<setw(12)<<"Name";
            cout<<setw(12)<<"Sex";
            cout<<setw(15)<<"DOB";
            cout<<setw(12)<<"Room"<<endl;
        }
        int getid(){
            return id;
        }
};
void menu(){
    cout<<"\t\t\t\t---------- STUDENT MANAGEMENT SYSTEM ----------\n"<<endl;
    cout<<"1. Input Student "<<endl;
    cout<<"2. View Student "<<endl;
    cout<<"3. Search Student "<<endl;
    cout<<"4. Update Student "<<endl;
    cout<<"5. Delete Student "<<endl;
    cout<<"6. Sort Student "<<endl;
    cout<<"7. Exit "<<endl;
}
int main(){
    Student objs[10],obj,objtmp;
    int option,n,i,idtmp;
    do{
        system("cls");
        menu();
        cout<<"Input Option : ";cin>>option;
        switch(option){
            case 1:
                cout<<">>>>> Input Student <<<<<"<<endl;
                objs[n].input();
                n++;
                break;
            case 2:
                cout<<">>>> View Student <<<<<<"<<endl;
                    obj.headIF();
                    for(i=0;i<n;i++){
                        objs[i].information();
                    }

                break;
            case 3 : 
                int x;
                cout<<">>>>> Search Student <<<<<"<<endl;
                cout<<"Input ID Student To Search : ";cin>>idtmp;
                x=0;
                for(i=0;i<n;i++){
                    if(idtmp==objs[i].getid()){
                        x=1;
                        obj.headIF();
                        objs[i].information();
                        break;
                    }
                }
                if(x==0){
                    cout<<"Search Not Found!!!"<<endl;
                }
                break;
            case 4 :
            	cout<<">>>>>> Update Student <<<<<<<"<<endl;
            	cout<<"Input ID Student To Update : ";cin>>idtmp;
                x=0;
                for(i=0;i<n;i++){
                    if(idtmp==objs[i].getid()){
                        x=1;
                        objs[i].input();
                        cout<<"Update Successfully***"<<endl;
                        break;
                    }
                }
                if(x==0){
                    cout<<"Search Not Found!!!"<<endl;
                }
            	break;
            case 5: 
            	cout<<">>>>>> Deleting Student <<<<<<<"<<endl;
            	cout<<"Input ID Student To Delete : ";cin>>idtmp;
                x=0;
                for(i=0;i<n;i++){
                    if(idtmp==objs[i].getid()){
                    	x=1;
                		for(int j=i;j<n;j++){
                			objtmp=objs[j];
                			objs[j]=objs[j+1];
                			objs[j+1]=objtmp;
						}
						n--;
						break;
                    }
                }
                if(x==0){
                    cout<<"Search Not Found!!!"<<endl;
                }else{
                	cout<<"Deleting Successfully***"<<endl;
				}
            	break;
            case 6:
            	cout<<">>>>>> Sort ID Student <<<<<"<<endl;
                for(i=0;i<n;i++){
                    for(int j=i;j<n;j++){
                        if(objs[i].getid()>objs[j].getid()){
                            objtmp=objs[i];
                            objs[i]=objs[j];
                            objs[j]=objtmp;
                        }
                    }
                }
                obj.headIF();
                for(i=0;i<n;i++){
                    objs[i].information();
                }
            	break;
            case 7: exit(0);
            	break;
            default:
                cout<<"Invalid Option!!!"<<endl;
                break;
        }cout<<"Press Enter To Continue..."<<endl;
    }while(getch()==13);
    return 0;
}