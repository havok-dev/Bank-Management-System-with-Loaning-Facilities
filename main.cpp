#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<ctime>
using namespace std;
time_t now =time(0);
tm * ltm= localtime(&now);
const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class date{
    int day;
    int month;
    int year;
public:
void gettime(){
    day=ltm->tm_mday;
    month=1+ltm->tm_mon;
    year=1900+ltm->tm_year;
    }
void showdate(){
cout<<day<<"/"<<month<<"/"<<year;}
int countLeapYears(date d)
{
    int years = d.year;
    if (d.month <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}
int getdifference(date b){
    long int n1 = year * 365 + day;
    for (int i = 0; i < month - 1; i++)
        n1 += monthDays[i];

        n1 += countLeapYears(*this);
    long int n2 = b.year * 365 + b.day;
    for (int i = 0; i < b.month - 1; i++)
        n2 += monthDays[i];

        n2 += countLeapYears(b);

    return (n1 - n2);
}
void getdata(){
cin>>day>>month>>year;
}};
class loan{
private:
    int amount;
    date lastupdate;
    int interest;
public:
    int istaken;
    loan(){
    amount=0;
    lastupdate.gettime();
    interest=0;
    }
int maxlimit(char socialno){
    int n;
    if(socialno=='1'){
        interest=10;
        n=2;
    }
    else if(socialno=='2'){
        n=5;
        interest=8;
    }
    else if(socialno=='3'){
        n=10;
        interest=7;
    }
    else if(socialno=='4'){
        n=15;
        interest=5;
    }
    else if(socialno=='5'){
        n=20;
        interest=4;
        }
    else if(socialno=='6'){
        n=30;
        interest=3;}
    else if(socialno=='7'){
        n=10000;
        interest=1;}
    else{
        n=100000;
        interest=1;
    }
    return n;
}
void addinterest(){
    if(istaken==1){
    date a;
    a.gettime();
    int b=a.getdifference(lastupdate);
    b=b/30;
    for(int i=0;i<b;i++){
            amount=amount+((amount*interest)/100);
    }
    lastupdate.gettime();
    }}
int payloan(int deposit){
    if(istaken==0){
        cout<<"\n\n\n\tTHE IS NO LOAN TAKEN BY THIS ACCOUNT"<<endl;

    }else{
        char c;
        cout<<"\n\n\n\tCURRENT AMOUNT TO BE PAID : "<<amount;
        cout<<"\n\tHOW WOUD YOU LIKE TO PAY?";
		cout<<"\n\n\t01. CASH";
		cout<<"\n\n\t02. FROM DEPOSIT";
		cin>>c;
		switch(c){
        case '1':
            cout<<"Enter the amount you want to pay : ";
            int x;
            cin>>x;
            amount=amount-x;
            if(amount==0){
                cout<<"\n\n\tLOAN PAID SUCCESSFULLY"<<endl;
                    istaken=0;
            }else{
                cout<<"\n\n\tAMOUNT PAID SUCCESSFULLY \n\tCURRENT AMOUNT LEFT : "<<amount;}
		case '2':
		    cout<<"\n\n\n\tCURRENT AMOUNT IN ACCOUNT : "<<deposit<<"\n\tENTER THE AMOUNT YOU WANT TO PAY : ";
		    cin>>x;
		    while(1){
		    if(x>deposit){
                cout<<"ENTER APPROPIATE VALUE OF DEPOSIT : ";
		    }else{
                amount=amount-x;
                deposit=deposit-x;
                if(amount==0){
                cout<<"\n\n\tLOAN PAID SUCCESSFULLY"<<endl;
                    istaken=0;
            }else{
                cout<<"\n\n\tAMOUNT PAID SUCCESSFULLY \n\tCURRENT AMOUNT LEFT : "<<amount;}
		        }}

		}}

    return deposit;
}
void takeloan(char socialno,int income){
    if(istaken==1){
        cout<<"\n\n\n\tPAY YOUR CURRENT LOAN THEN ONLY YOU WILL BE ALLOWED TO TAKE A LOAN"<<endl;
    }else{
    int lower_limit=20000;
    int upper_limit=income*maxlimit(socialno);
    int n;
    cout<<"\n\n\n\tTHE RANGE IN WHICH YOU CAN TAKE MONEY IS : "<<lower_limit<<"-" <<upper_limit;
    while(1){
    cout<<"\n\tENTER THE AMOUNT YOU WANT TO BORROW : ";
    cin>>n;
    if(n<lower_limit||n>upper_limit){
        cout<<"\n\n\tTHE AMOUNT "<<n<<" IS INVALID IT MUST BE IN RANGE "<<lower_limit<<"-"<<upper_limit;
    }else{

        amount=n;
        istaken=1;
        lastupdate.gettime();
        break;
    }

} }}
void checkstatus(){
    if (istaken==0){
        cout<<"\n\n\n\tTHE IS NO LOAN TAKEN BY THIS ACCOUNT"<<endl;
    }else{
        cout<<"\n\n\n\tAMOUNT TO BE PAID : "<<amount;
            cout<<"\n\tINTEREST : "<<interest;
            cout<<"\n\tDATE LAST UPDATED : ";
            lastupdate.showdate();
            cout<<endl<<endl;

    }
    }
void report(){
if(istaken==0){
    cout<<"No loan taken";
}else{
    cout<<amount<<"   "<<interest<"    ";
    lastupdate.showdate();
}
}

    };

class account{

	int acno;
	char name[50];
	int deposit;
	char type;
	int income;
	char socialno;
    int debt;
    date dateacc_created;
    date datelastsavinginterest;
public:
    loan L1;
void updatesocialid(){
    if(income<30000){
        socialno='1';
    }
    else if(income<60000&& income>=30000){
        socialno='2';
    }
    else if(income<90000&& income>=60000){
        socialno='3';
    }
    else if(income<120000&& income>=90000){
        socialno='4';
    }
    else if(income<180000&& income>=120000){
        socialno='5';
    }
    else if(income<300000 && income>=180000){
        socialno='6';
    }else if(income<600000 && income>=300000){
    socialno='7';
    }
    else{
        socialno='8';
    }
}
void create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\nEnter your income :";
	cin>>income;
	updatesocialid();
	dateacc_created.gettime();
	datelastsavinginterest.gettime();
    L1.istaken=0;
	cout<<"\n\n\nAccount Created..";
}
void show_account()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\nIncome : "<<income;
	cout<<"\nSocial number : "<<socialno;
	cout<<"\nDate account created : ";
	dateacc_created.showdate();
	cout<<"\nMost recent savings update : ";
	datelastsavinginterest.showdate();
	cout<<L1.istaken;
	L1.checkstatus();


}
void updatesaving(){
    if(type=='S'){
    date a;
    a.gettime();
    int b=a.getdifference(datelastsavinginterest);
    b=b/30;
    cout<<b;
    for(int i=0;i<b;i++){
            deposit=deposit+((deposit*5)/100);
    }
    datelastsavinginterest.gettime();
}}
void modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}
void dep(int x)
{
	deposit+=x;
}

void draw(int x)
{
	deposit-=x;
}

void report()
{cout<<acno<<"      "<<name<<"            "<<type<<"  "<<deposit<<"    "<<socialno<<"  ";
dateacc_created.showdate();
cout<<"          ";
datelastsavinginterest.showdate();
cout<<"      ";
L1.report();
cout<<endl;
}


int retacno() const{
	return acno;
}

int retdeposit() const{
	return deposit;
}

char rettype() const{
	return type;
}
char retsocialno(){
    return socialno;
}
int retincome(){
    return income;
}
void updatedeposit(int x){
deposit=x;
}
};
void write_account(){    //function to write record in binary file

	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n){	//function to display account details given by user

	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{   ac.updatesaving();
            ac.L1.addinterest();
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void modify_account(int n){	//function to modify record of file

	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{   ac.updatesaving();
            ac.L1.addinterest();
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void delete_account(int n){	//function to delete record of file

	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}
void display_all(){		//function to display all account details

	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=======================================================================================================================================================================================\n";
	cout<<"A/c no.      NAME           Type  Balance         Social number     Date account created      Date of Last interest Update        Loan Status   Loan Amount    Date of last loan update";
	cout<<"\n=====================================================================================================================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{   ac.updatesaving();
        ac.L1.addinterest();
		ac.report();

	}
	inFile.close();
}
void deposit_withdraw(int n, int option){ // function to desposit/withdraw amount for given account

	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			ac.updatesaving();
			ac.L1.addinterest();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void takealoan(int n){
    bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			int sn=ac.retsocialno();
			int income=ac.retincome();
			ac.L1.takeloan(sn,income);
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void paytheloan(int n){
    bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			int dep=ac.retdeposit();
			ac.L1.addinterest()l
			dep=ac.L1.payloan(dep);
			ac.updatedeposit(dep);
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void loanmenu(){
char ch;
int num;
do{
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. TAKE A LOAN";
		cout<<"\n\n\t02. PAY YOUR LOAN";
		cout<<"\n\n\t03. VIEW STATUS";
		cout<<"\n\n\t04. EXIT";
		cin>>ch;
		switch(ch){
        case'1':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			takealoan(num);
			break;
        case'2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			paytheloan(num);
			break;
        case'3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		}
}while(ch!='4');



}
void intro(){	//introductory screen function

	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : Harshal Beniwal-2K19/IT/057";
	cout<<"\n\n\n\n          Harshwardhan-2K19/IT/059";
	cin.get();
}

int main()
{
	char ch;
	int num;
	intro();
	do
	{
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. OPEN LOAN MENU";
		cout<<"\n\n\t09. EXIT";
		cout<<"\n\n\tSelect Your Option (1-9) ";
		cin>>ch;
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
            loanmenu();
            break;
		 case '9':
			cout<<"\n\n\tThanks for using bank management system";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='9');
	return 0;
}

