#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include <stdlib.h>
#include <fstream> 
#include<time.h>
#include <sstream>

using namespace std;
class save_acct//:private account
{
    float balance;
    float deposit;
    float withdraw;
	float loanamt;
	float rate;
    string file;
    string PIN;
    long long account;
    public:
    	
    	fstream f,b;
        save_acct()
        {
            balance=0.0;
            deposit=0.0;
            withdraw=0.0;
            loanamt=0.0;
            rate=5.0;
            PIN="0000";
            account=0;
        }
        void getdata(char acname[],char lname[],long long acno,string pin)
        {
        	 PIN=pin;
        	 account=acno;
            char name[]="";
            cout<<"\nDETAILS FOR THE ACCOUNT";
            strcpy(name,acname);
            strcat(name," ");
            strcat(name,lname);
          cout<<"\n\nACCOUNT HOLDER NAME       :"<<name;
            cout<<"\nACCOUNT NUMBER            :"<<acno;

            cout<<"\nENTER THE BALANCE         :";
                cin>>balance;

              cout<<"INTEREST RATE             :"<<rate<<"% per month";

            file=to_string(acno)+".txt";
                
            f.open(file,ios::out);    
            
                f<<"ACCOUNT HOLDER NAME       :"<<acname<<" "<<lname;
              f<<"\nACCOUNT NUMBER            :"<<acno;
              f<<"\nPIN                       :"<<pin;
              f<<"\nInterest Rate             :"<<rate<<"% per month for +ve amt and -"<<rate<<"% per month for -ve amt"<<endl<<endl;
              
              time_t now = time(0);
   			  tm *ltm = localtime(&now);
   			  f<< "DATE"<< "\t\t\t";
			  f<<"(D/W/L)"<<"\t\t\tBALANCE"<<endl<<endl;
   			  f<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
			  f<<"\t\t\t:"<<balance<<endl;
			  f.close();
			    
			  b.open("bank.txt",ios::app); 
   			  b<<endl;
			  b<<account<<"\t\t"<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
			  b<<"\t\t\t"<<balance<<endl;
        }
        void getdata(long long acno,long long b)
        {	
			balance=b;
            file=to_string(acno)+".txt";
            account=acno;
            
        }
        void sdeposit()
        {

                cout<<"\nMONEY DEPOSIT SCREEN";
                cout<<"\n\nENTER THE AMOUNT YOU WANT TO DEPOSIT        :";
                cin>>deposit;

                    balance=balance+deposit;
                    cout<<"\n\nTHE BALANCE AFTER MAKING DEPOSIT IS        :"<<balance;
                	f.open(file,ios::app); 
            		time_t now = time(0);
   					tm *ltm = localtime(&now);
   					f<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
            		f<<"(D) "<<deposit<<"\t\t:";
					f<<balance<<endl;
					f.close();
                    
                    fstream b;
			  		b.open("bank.txt",ios::app); 
			  		b<<account<<"\t\t"<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
            		b<<"(D) "<<deposit<<"\n";
			  		b.close();

        }
        void swithdraw()
        {

            cout<<"\nMONEY WITHDRAWAL SCREEN";
            cout<<"\n\nENTER THE WITHDRAWAL AMOUNT            :";
            cin>>withdraw;
            float temp;
            temp=balance-withdraw;
            if(temp<0)
            {
                cout<<"\nILLEGAL WITHDRAWAL BALANCE COMES TO LESS THAN ZERO";
                cout<<"\nCANNOT ALLOW TO WITHDRAW";
                  ;
                while(1){
                cout<<"\n\nAPPLY FOR LOAN(Y/N): ";
                char ch;
                cin>>ch;
                if(ch=='N')
                break;
                else if(ch=='Y'){
                	cout<<"\nLOAN APPROVAL SCREEN";
            		f.open(file,ios::app); 
            		cout<<"\n\nWITHDROWAL  AMOUNT                           :";
					cin>>loanamt;
                	balance=balance-loanamt;
            		  cout<<"\nBALANCE AFTER LOAN APPROVAL           :"<<setprecision(3)<<balance;
              		;
              		time_t now = time(0);
   					tm *ltm = localtime(&now);
   					f<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
   					f<<"(L+W) "<<loanamt<<"\t\t:";
					f<<balance<<endl;
   					f.close();
   					
   					b.open("bank.txt",ios::app); 
			  		b<< account<<"\t\t"<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
   					b<<"(L+W) "<<loanamt<<"\t\t";
					b<<balance<<endl;
			  		b.close();
   					break;
					}
					else
					cout<<"\n\nINVALID CHOICE";
            }
        }
            else
            {
                balance=balance-withdraw;
                cout<<"\n\nTHE BALANCE AFTER WITHDRAWAL IS    :"<<balance;
                  ;
                  //time_t t=time(NULL);
                  f.open(file,ios::app); 
            		//f<<ctime(&t);
            		time_t now = time(0);
   					tm *ltm = localtime(&now);
   					f<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
            		f<<"(W) "<<withdraw<<"\t\t\t:";
					f<<balance<<endl;
					f.close();
					
					fstream b;
			  		
			  		b.open("bank.txt",ios::app); 
			  		b<< account<<"\t\t"<<1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
            		b<<"(W) "<<withdraw<<"\t\t\t";
					b<<balance<<endl;
			  		b.close();
            }
        }
        void sdisplay()
        {
            cout<<"\n\nLATEST BALANCE IS : Rs. "<<balance;
            //time_t t=time(NULL);
            f.open(file,ios::app); 
            //f<<ctime(&t);
            time_t now = time(0);
   			tm *ltm = localtime(&now);
   			f<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
			f<<"\t\t\t:"<<balance<<endl;
			f.close();
			
			fstream b;
			  		
			  		b.open("bank.txt",ios::app); 
			  		b<< account<<"\t\t"<< 1900 + ltm->tm_year <<"/"<< 1 + ltm->tm_mon<<"/"<<  ltm->tm_mday << "\t\t";
					b<<"\t\t\t"<<balance<<endl;
			  		b.close();
        }
	
};

#define rate 5
int main()
{
    int ans;
    	system("CLS");
    	string welcome="\t\t             \\(*_*)\n\t\t   WELCOME TO  ) )Z  JNV BANK\n\t\t               / \\ \n\n";
    	cout<<welcome;
    	cout<<"CREATE NEW ACCOUNT(N)/ACCOUNT EXIST(E)"<<endl;
    	char choice;
    	cout<<endl;
    	while(1){
    	cin>>choice;
    	cout<<endl;    	
    	char acname[30],lname[30];
        long long acno;
    	if(choice=='N'){
        char c;
        char acname[30],lname[30];
        long long acno;
        string pin;
        cout<<"\nACCOUNT OPENING SYSTEM ";
        cout<<"\n\nENTER THE CUSTOMER NAME          :";
        int i;
        cin>>acname>>lname;
        cout<<"\nENTER ACCOUNT NUMBER             :";
		cin>>acno;
		cout<<"\nENTER PIN                        :";
		cin>>pin;
        int ch;

                save_acct s1;
                s1.getdata(acname,lname,acno,pin);
                while(1)
                {
				system("CLS");
    	string welcome="\t\t             \\(*_*)\n\t\t   WELCOME TO  ) )Z  JNV BANK\n\t\t               / \\ \n\n";
    			cout<<welcome;
    			cout<<"Hi "<<acname<<":)";

    			s1.sdisplay();
    			time_t t=time(NULL);
            	cout<<"\t\t"<<ctime(&t);
                    cout<<"\n\nACCOUNT MENU";
                    cout<<"\n\n1. DEPOSIT";
                    cout<<"\n2. WITHDRAW";
                    cout<<"\n3. EXIT";
                    cout<<"\n\nENTER YOUR CHOICE :";
                    cin>>ch;
                    if(ch==1)
                        s1.sdeposit();
                    else if(ch==2)
                        s1.swithdraw();
                    else if(ch==3)
                    {
                    	cout<<"\n\t\tTHANK YOU! HAVE A NICE DAY :)";
                        break;
                    }
                    else
                    {
                        cout<<"\n\nINVALID CHOICE";

                    }

                }
            }
           
        else if(choice=='E'){
        	cout<<"ENTER ACCOUNT NO          :";
        	long long acno;
        	cin>>acno;
        	string file=to_string(acno)+".txt";
        	ifstream f;
        	if(f.fail()){
        		cout<<"Account not exist"<<endl;
        		break;
        	}
        	else{
    		string line,l,h;
    		int count=0;
    		f.open(file,ios::in);
    		string str;
    		while (getline(f, line)) {
    			if(count<1){
    			str=line.c_str();
				}
    			if(count==2)
    			h=line.c_str();
        		l=line.c_str();
        		count++;
    		}
    		f.close();
    		int i=0;
    		while(str[i]!=':')
    		i++;
    		i++;
    		string nameacc="";
    		while(str[i]!=' '){
    		nameacc+=str[i];
    		i++;
    		}
    		
    		int j=0;
    		while(h[j]!=':')
    		j++;
    		j++;
    		string ss="";
    		while(h[j]!='\0')
    		{
    			ss+=h[j];
    			j++;
			}
			string password = ss;
			
			string pin;
			int wrongpin=0;
			while(1){
			cout<<"\nENTER PIN :";
			cin>>pin;
			
			if(pin==password){
			cout<<str[0]<<endl<<str[1]<<endl;
    		int i=0;
    		while(l[i]!=':')
    		i++;
    		i++;
    		string s="";
    		while(line[i]!='\0')
    		{
    			s+=line[i];
    			i++;
			}
			int balance ; 
			balance = std::atoi(s.c_str());
			;
			
			
			string y="";	y=y+line[2]+line[3];
			string m="";	m=m+line[5]+line[6];
			int year ; 
			year = std::atoi(y.c_str())+2000;
			int month ; 
			month = std::atoi(m.c_str());
			
			time_t now = time(0);
   			tm *ltm = localtime(&now);
   			year=year-(1900 + ltm->tm_year) ;
			month=month-(1 + ltm->tm_mon);
   			month=month+year*12;
   			if(balance<0)
			balance=balance-rate*month/100;
			else
			balance=balance+rate*month/100;			
			
                save_acct s1;
                s1.getdata(acno,balance);
                while(1)
                {
                	system("CLS");
    	string welcome="\t\t             \\(*_*)\n\t\t   WELCOME TO  ) )Z  JNV BANK\n\t\t               / \\ \n\n";
    				cout<<welcome;
    				cout<<"Hi "<<nameacc<<":)";
    				s1.sdisplay();
    				time_t t=time(NULL);
            		cout<<"\t\t"<<ctime(&t);
					int ch;
                    cout<<"\n\nACCOUNT MENU";
                    cout<<"\n\n1. DEPOSIT";
                    cout<<"\n2. WITHDRAW";
                    cout<<"\n3. EXIT";
                    cout<<"\n\nENTER YOUR CHOICE :";
                    cin>>ch;
                    if(ch==1)
                        s1.sdeposit();
                    else if(ch==2)
                        s1.swithdraw();
                    else if(ch==3)
                    {
                    	cout<<"\n\t\tTHANK YOU! HAVE A NICE DAY :)";
                        break;
                    }
                    else
                    {
                        cout<<"\n\nINVALID CHOICE";
                    }
                }
                break;
            }
            else{
            cout<<"\nINCORRECT PIN, TRY AGAIN\n";
            wrongpin++;
            if(wrongpin==5){
            	cout<<"\nTOO MANY WRONG ATTEMPTS, PLEASE TRY AGAIN LATER\n(IF YOU HAVE FORGOTTEN THE PIN PLEASE CONTACT BANK)\n";
            break;
        	}
        	}
        }
    }
	}
	break;
}
return 0;
}
