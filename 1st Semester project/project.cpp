#include<iostream>
#include<conio.h>
//#include<stdlib.h>
#include<fstream>
using namespace std;

int mainmenu();
void Sect2(string a);
void setxy(int,int);
void exit();
void About();

// Teacher class
class teacher{
	protected:
		int id;
		string name;
		string sub;
		
	public:
		void login();
		
};

//Student Class
class student{
	protected:
		int rollno;
		string name;
		int c=1;
		int stds=5;
	public:	
		void record();
		void Attendance();
		void Chk();
		
};

// Student Marks Record 
void student::record(){
	string error,s,m,ph,ic,p,e; int count,c=1,r;
	system("cls");
	student s1;
	
	ifstream fin("Name.txt");
	ifstream roll("Roll.txt");
	Chk();
	// loop for reading the file
	while(fin.good()){
		getline(fin,s);	
		roll>>r;
		if(name==s && rollno==r){
		ifstream fe("FE.txt");
		ifstream math("Math.txt");
		ifstream phy("Phy.txt");
		ifstream pf("PF.txt");
		ifstream iict("IICT.txt");
		
	for(int i=0;i<c;i++){
		getline(math,m);
		getline(phy,ph);
		getline(fe,e);
		getline(pf,p);
		getline(iict,ic);
	}
	
	setxy(10,5);
	cout<<"\t\tMarks\n\n\tName \tFE \tMath \tAP \tPF \tIICT\n\n";
	cout<<"\t"<<s<<"\t"<<e<<"\t"<<m<<"\t"<<ph<<"\t"<<p<<"\t"<<ic;
	}
	
	else if(name!=s && rollno!=r){
		c++;
	}
	
	else{
		cout<<"\nName or Roll NO may be incorrect";
		}
	}	
	
	cout<<"\n\n\n\nGo to Main menu(press m)\nRecheck(press r)\nCheck Attendance(press a)\nexit(press any key)\nOutput: ";
	char ch;
	cin>>ch;
	
	if(ch=='M' || ch=='m')
		mainmenu();
	else if(ch=='a'||ch=='A')
		Attendance();
	else if(ch=='r'||ch=='R')
		record();
	else
		exit(0);
}

// Teacher Login Portal 
void teacher::login(){
	char chr;
	system("cls");
	
	// Hardcoded data of teachers
	string arr[5]={"Saleem","Naeem","Umerubab","Jabbar","Anoud"}; 
	int pass[5]={1234,2345,3456,4567,5678};
	string subj[5]={"Math","PF","FE","Phy","IICT"};
	
	teacher t1;
	
	cout<<"Enter your Name :"; cin>>name;
	cout<<"\nEnter your login Id :"; cin>>id;
	
	for(int i=0;i<5;i++){
		if(arr[i]==name && pass[i]==id){
			sub=subj[i];
			system("cls");
			cout<<"\n\tWelcome Sir/Mam\n\n";
			sleep(2);
			
			Sect2(sub);// Calling  
		
		}
		else if(i==4)
		 	cout<<"\nIncorrect Name or id!\n\n\n";
	}	
	cout<<"Go to Main menu(press m)\nRetry(press r)\nexit(press any key)\nOutput: ";
	cin>>chr;
	
		if(chr=='M' || chr=='m')
		mainmenu();
		else if(chr=='r' || chr=='R')
		login();
		else
		exit(0);
		
}

// Start of Main function
int main(){
	mainmenu();
 	
	
	return 0;
}

// Mainmenu Function
int mainmenu(){
	system("cls");
	int op;
		
	cout<<"\n\t\tManagement Information System(MIS)";
	cout<<"\n\t\t\tMUET Jamshoro\n";
	cout<<"\n\t1. Student Marks Record";
	cout<<"\n\t2. Attendance Record";
	cout<<"\n\t3. Teacher Login portal";
	cout<<"\n\t4. About Us";
	cout<<"\n\t5. Exit";
	cout<<"\n\n\tSelect Option:"; cin>>op;

	switch (op){
		case 1: {student s1; s1.record();
		break;}
		case 2: {student s1; s1.Attendance();
		break;}
		case 3:{teacher t1; t1.login();
		break;}
		case 4: About();
		break;
		case 5: exit();
		break;
		default: cout<<"invalid input";	
	}
}

// Function Shows marks and Attendance of all students
void Sect2(string sub){
	setxy(5,4);
	char ch,chr; int m; 
	string s,marks,dir,cir,sh,attend;
	
	dir=sub+".txt";
	cir="A"+sub+".txt";
	
	ifstream subj(dir.c_str());
	ifstream fin("Roll.txt");
	ifstream att(cir.c_str());
	
	cout<<"Roll no\t marks\tLectures\tTotal\n\n";
	
	while(fin.good()){
		getline(fin,s);
		getline(subj,marks);
		getline(att,attend);
		cout<<"\t"<<s<<"\t  "<<marks<<"\t     "<<attend<<"\t\t  "<<"45"<<endl;	
	}
	subj.close();
	fin.close();
	
	cout<<"\n\nUpdate Marks(press 1)\nTake Attendance(press 2)\nLogout(press 3)\nOutput: "; 
	cin>>ch;
	
	if(ch=='1'){
		ofstream subj(dir.c_str());
		ifstream fin("Roll.txt");
		
		for(int i=0;i<5;i++){
			getline(fin,sh);
			cout<<"Enter marks for Roll no "<<sh<<endl;		
			cin>>m;
			subj<<m<<endl;
		}	
	}
	else if(ch=='2'){
		ofstream att(cir.c_str());
		ifstream fin("Roll.txt");
		
		cout<<"Enter attendence in lecture hours\n";
		for(int i=0;i<5;i++){
			getline(fin,sh);
			cout<<"Roll no "<<sh<<" :";		
			cin>>attend;
			att<<attend<<endl;
		}	
	}
	else if(ch=='3')
		mainmenu();
	
	cout<<"\n\n\n\nGo to Main menu(press m)\nGo Back(press r)\nexit(press any key)\nOutput: ";
	cin>>chr;
	
	if(chr=='M' || chr=='m')
		mainmenu();
	else if(chr=='r' || chr=='R'){
		system("cls");
		Sect2(sub);
}
	else 
		exit(0);
}


// Student Attendance
void student::Attendance(){
	string s,a,b,c,d,e; int count=1,r; char ch;
	system("cls");
	ifstream fin("Name.txt");
	ifstream roll("Roll.txt");
	Chk();
	
	while(fin.good()){
		getline(fin,s);
		roll>>r;	
		
		if(name==s && rollno==r){
			ifstream AMath("AMath.txt");
			ifstream AFE("AFE.txt");
			ifstream APhy("APhy.txt");
			ifstream APF("APF.txt");
			ifstream AIICT("AIICT.txt");
			
		cout<<"\n\n\n\n\t\t\tAttendance";	
		cout<<"\n\n\tName \tFE \tMath \tAP \tPF \tIICT\n\n";
		cout<<"\t"<<s;
		
		for(int j=0;j<count;j++){
			getline(AFE,a);
			getline(AMath,b);
			getline(APhy,c);
			getline(APF,d);
			getline(AIICT,e);
		}
			cout<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e;
		}
		
		else if(name!=s && rollno!=r){
			count++;
		}
		
		else{
		cout<<"\nName or Roll NO may be incorrect";
		}
	}	
	
		cout<<"\n\n\n\nGo to Main menu(press m)\nRecheck(press r)\nexit(press any key)\nOutput: ";
		cin>>ch;
		
		if(ch=='M' || ch=='m')
		mainmenu();
		else if(ch=='r'||ch=='R')
		Attendance();
		else
		exit(0);
}

// Student Name Check	
void student::Chk(){
	system("cls");
	cout<<"Enter your Roll No: "; cin>>rollno;
	cout<<"Enter your Name: "; cin>>name;
		
}

// Set Lines and spaces
void setxy(int x,int y){
	for(int i=0;i<y;i++){
		cout<<"\n";
	}
	for(int j=0;j<x;j++){
		cout<<" ";
	}
}

void exit(){
	system("cls");
	cout<<"Thanks for visiting";
	exit(0);
}

void About(){
	char a,ch;
	system("cls");
	setxy(50,3);
	cout<<"ABOUT US";
	cout<<"\n\nThe Directorate of Management Information Systems (MIS) aims at providing accurate and comprehensive set of information to help students, faculty, and management make key decisions.In this regard, the directorate compiles students \nattendance and produce comprehensive reports for each semester of all Bachelors, Masters, and Phd programs. The reports help students and faculty know the course of attendance in a subject, and eligibility of a student for appearing in the examinations, determined on the basis of 75% attendance. ";
	
	a=getch();
	string scope="start https://www.youtube.com/watch?v=E1VjnjVmxcc";
	system(scope.c_str());
	
	cout<<"\n\n\n\nGo to Main menu(press m)\nexit(press any key)\nOutput: ";
	cin>>ch;
	
	if(ch=='M' || ch=='m')
	mainmenu();
	else
	exit(0);
	}