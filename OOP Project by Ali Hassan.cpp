#include<iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;

class students
{
	public: 

	string student_name;	
	string roll_no;	
	string student_year;
	int location;
	int buss_no;
	
	
	students(){}
	
	students(string student_name, string roll_no, string student_year, int location, int buss_no){
		this->student_name = student_name;
		this->roll_no = roll_no;
		this->student_year = student_year;
		this->location = location;
		this->buss_no = buss_no;
	}	
	
	void show_data(){
		
		cout<<"\nStudent Name: "<<student_name<<"\nRoll No: "<<roll_no<<"\nStudent Year: "<<student_year<<"\nLocation no: "<<location<<"\nBuss No: "<<buss_no;
	}
	
	void write(ofstream &fout){
	
		fout<<student_name<<"\n"<<roll_no<<"\n"<<student_year<<"\n"<<location<<"\n"<<buss_no<<"\n";

	}
			
};

class admin
{
	int passcode;
	
	public:
	
	admin(int passcode){
		this->passcode = passcode;
	}
	
	int get_passcode(){
		return passcode;
	}
	
	void set_passcode(int passcode){
		this->passcode = passcode;
	}
	
		
	void read(ifstream &fin, students s){
				
		getline(fin>>ws,s.student_name);
		getline(fin>>ws,s.roll_no);
		getline(fin>>ws,s.student_year);
		fin>>s.location;
		fin>>s.buss_no;	
		if(s.student_name==" "||s.student_name=="");
		else
		s.show_data();	
	}		
	
};

void read_bus_files(ifstream &fin){
	string ch;
	getline(fin>>ws,ch);
	while(!fin.eof()){
		if(ch==" " || ch=="\n" || cout<<endl){
			cout<<"\n";
		}
		cout<<ch;
		getline(fin>>ws,ch);
	}
}

int main() 
{
	students s[10];
	int vote;	
	int choice;
	int n = 0;
	int p;
	admin ob1(7860);	
	
		
	// THE ADMINISTRATOR PINCODE IS 7860

	
	cout<<"\n\n1.Administrator\n2.student\nPlease select your identity: ";
	cin>>choice;
	
	while( choice>2 || choice<1)
	{
		cout<<"\nInvalid Entry!!";
		cout<<"\n\n1.Administrator\n2.student\nPlease select your identity: ";
	    cin>>choice;
		
	}
	
	
	if(choice==1)
	{
		cout<<"\n\nPlease enter your four digit PINCODE :";
		cin>>p;
		
		
		while(p!=ob1.get_passcode())
		{
			cout<<"\n\nAccess Denied!!\n\nPlease try again.\n\n";
			cout<<"\n\nPlease enter your four digit PINCODE :";
			cin>>p;
			
		if (p==ob1.get_passcode())
			break;
		}
		
		if (p==ob1.get_passcode())
		{
			cout<<"\nsuccessfull login\n\n";
			

	    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"                                                                                          STUDENT'S BUS DATA\n";
		cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

			choice=0;
			cout<<"Please Select\n\n1. Show the Record of All Students \n\n2. Search for a specific student's record"<<endl;
			cin>>choice;
			
			if(choice==2){
			string s_std;

			cout<<"Enter the Roll Number of student: "<<endl;
			cin>>s_std;
			
			ifstream fin;
			fin.open("Student_data.txt",ios::in);
			
			if(!fin){cout<<"Unable to open"<<endl;}

			int i=0;
			ob1.read(fin,s[i]);

			while(!fin.eof()){
				i++;
				if(s[i].roll_no==s_std){
					cout<<"\nRecord Available: "<<endl;
					ob1.read(fin,s[i]);
					}
				}
			fin.close();							
			}
			else{
			
			ifstream fin;
			fin.open("Student_data.txt",ios::in);
			
			if(!fin){cout<<"Unable to open"<<endl;}
			int i=0;
			ob1.read(fin,s[i]);
			while(!fin.eof()){
				i++;
				ob1.read(fin,s[i]);
				fin.close();			
					}
				}				
			}
		}

	else{
	
	do{
	

	cout<<"------------------------------------------------------Welcome to Buss Transportation Service-------------------------------------------"<<endl;
	cout<<"Enter your Name: "<<endl;
	getline(cin>>ws,s[n].student_name);
	
	cout<<"Enter your Roll No: "<<endl;
	getline(cin>>ws,s[n].roll_no);

	cout<<"Enter your Year at University: "<<endl;
	getline(cin>>ws,s[n].student_year);
	
	ifstream fin;
	
	fin.open("Location.txt");
	
	if(!fin){cout<<"Unable to open"<<endl;}
	
	read_bus_files(fin);
	
	fin.close();		

	cout<<"\n\nSelect your Location: "<<endl;
	cin>>s[n].location;
	
	
		switch (s[n].location)
	{
	    case 1:
			cout<<"\nThese buses passes through your location with it's following routes'"<<endl;
			fin.open("bus23.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			
			break;
			
		case 2:
			cout<<"\nThese buses passes through your location with it's following routes'";
		
			fin.open("bus5.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus6.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			
			break;
			
		case 3:
			cout<<"\nThese buses passes through your location with it's following routes'";
		
			fin.open("bus8.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;
			
		case 4:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus23.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus18.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus8.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus7.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
		
			break;
			
		case 5:
			cout<<"\nThese buses passes through your location with it's following routes'";

			fin.open("bus17.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus9.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus6.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus5.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;	
				
		case 6:
			cout<<"\nThese buses passes through your location with it's following routes'";

			fin.open("bus17.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus22.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;
			
		case 7:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus18.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;
			
		case 8:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus10.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			
			break;
			
		case 9:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus17.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus16.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;
			
		case 10:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus12.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 11:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus1.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 12:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus13.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 13:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus14.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;			
			
		case 14:
			cout<<"\nThese buses passes through your location with it's following routes";
			fin.open("bus4.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;
			
		case 15:
			cout<<"\nThese buses passes through your location with it's following routes";
			fin.open("bus24.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 16:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus21.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus24.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 17:
			cout<<"\nThese buses passes through your location with it's following routes'";
		
			fin.open("bus20.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 18:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus20.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 19:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus15.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 20:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus15.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 21:
			cout<<"\nThese buses passes through your location with it's following routes";
			fin.open("bus15.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			fin.open("bus16.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 22:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus14.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 23:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus24.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		
			break;

		case 24:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus4.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;

		case 25:
			cout<<"\nThese buses passes through your location with it's following routes'";
			fin.open("bus19.txt");
			
			if(!fin){cout<<"Unable to open"<<endl;}
			
			read_bus_files(fin);
			
			fin.close();		

			break;		
	}
	
	cout<<"\n\nSelect your Buss No: "<<endl;
	cin>>s[n].buss_no;
	
		if(s[n].student_year=="Freshman" || s[n].student_year=="freshman")
	{
		cout<<"\nDear Freshman your seat has been reserved in bus "<<s[n].buss_no<<" for a day by the name of "<<s[n].student_name<<" and ID "<<s[n].roll_no<<".Please pay RS 22000 at the accounts office to book it.";
	}
	else if(s[n].student_year=="Sophomore" || s[n].student_year=="sophomore")
	{
	   	cout<<"\nDear Sophomore your seat has been reserved in bus "<<s[n].buss_no<<" for a day by the name of "<<s[n].student_name<<" and ID "<<s[n].roll_no<<".Please pay RS 22000 at the accounts office to book it.";
	}
	else if(s[n].student_year=="Junior" || s[n].student_year=="junior")
	{
		cout<<"\nDear Junior your seat has been reserved in bus "<<s[n].buss_no<<" for a day by the name of "<<s[n].student_name<<" and ID "<<s[n].roll_no<<".Please pay RS 22000 at the accounts office to book it.";
	}

	else if(s[n].student_year=="Senior" || s[n].student_year=="senior")
	{
	  	cout<<"\nDear Senior your seat has been reserved in bus "<<s[n].buss_no<<" for a day by the name of "<<s[n].student_name<<" and ID "<<s[n].roll_no<<".Please pay RS 22000 at the accounts office to book it.";
	}

	
	cout<<"\n\nDo you want to add another student's data\nEnter 1 for yes \nEnter 0 for no?"<<endl;
	cin>>vote;
	
	++n;
		}while(vote=0);
	

	ofstream fout;
	fout.open("Student_data.txt",ios::app);
	if(!fout){cout<<"Unable to open"<<endl;}
	
	for(int i=0; i<n; i++){
	
	s[i].write(fout);
	fout.close();
		}
	}
}
