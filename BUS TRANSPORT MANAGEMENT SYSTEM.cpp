#include<iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;

class staff {
	public:
	string emp_id;
	string name;
	int age;

		staff(){}
		
		//optional parameterized constructor
		staff(string emp_id,string name,int age){
			this->emp_id=emp_id;
			this->name=name;
			this->age=age;
		}
		
		void setid (string id) {
			emp_id=id;
		}
		
		string getid () {
			return emp_id;
		}
		
		void setname (string n) {
			name=n;
		}
		
		string getname () {
			return name;
		}
		
		void setage (int a) {
			age=a;
		}
		
		int getage () {
			return age;
		}
		
};

class driver:public staff {

	public:

	int experience;
	string license;
	bool verified;
		driver () {}
		
		//optional parameterized constructor
		driver(string emp_id,string name,int age,int experience,string license,bool verified):staff(emp_id,name,age){
			this->experience=experience;
			this->license=license;
			this->verified=verified;
		}
		
		void setexp (int exp) {
			experience=exp;
		}
		
		int getexp () {
			return experience;
		}
		
		void setlic (string lic) {
			license=lic;
		}
		
		string getlic () {
			return license;
		}
		
		void setver (bool ver) {
			verified=ver;
		}
		
		bool getver () {
			return verified;
		}
		
		void driver_details () {
			cout<<"\nEnter driver details\n"<<endl;
			cout<<"\nName: ";
			cin>>name;
			cout<<"\nAge: ";
			cin>>age;
			cout<<"\nEmployee ID: ";
			cin>>emp_id;
			cout<<"\nYears of experience: ";
			cin>>experience;
			cout<<"\nLicense Number: ";
			cin>>license;
			cout<<"\nIs your license verified ? Press 1 for yes and 0 for no"<<endl;
			cin>>verified;
			if (verified){
				cout<<"\n\n-----------------------------------------------registration complete--------------------------------------------------------\n\n"<<endl;
			}
			else {
				cout<<"your license must be renewed and verified within 1 month"<<endl;
			}
		}
	
	void show(){
		
		cout<<"Employee Id: "<<emp_id<<"\nName: "<<name<<"\nAge: "<<age<<"\nExperience: "<<experience<<"\nLicense: "<<license<<"\nVerified: "<<verified<<endl;		
	}	
	
	void write(ofstream &fout){

		fout<<emp_id<<"\n"<<name<<"\n"<<age<<"\n"<<experience<<"\n"<<license<<"\n"<<verified<<endl;
	}

};

class attendent:public staff {

	public:

	int working_days;
	int working_hours;
	bool night_shift;
		attendent () {}
		
		attendent (string emp_id,string name,int age,int working_days,int working_hours,bool night_shift):staff(emp_id,name,age) {
			this->working_days=working_days;
			this->working_hours=working_hours;
			this->night_shift=night_shift;
		}
		
		void setwd (int wd) {
			working_days=wd;
		}
		
		int getwd () {
			return working_days;
		}
		
		void setwh (int wh) {
			working_hours=wh;
		}
		
		int getwh () {
			return working_hours;
		}
		
	   	void setns (bool ns) {
			night_shift=ns;
		}
		
		int getns () {
			return night_shift;
		}
		
		void attendent_preferences () {
			cout<<"\nEnter your details"<<endl;
			cout<<"\nName: ";
			cin>>name;
			cout<<"\nAge: ";
			cin>>age;
			cout<<"\nEmployee id: ";
			cin>>emp_id;
			cout<<"\nEnter your job preferences"<<endl;
			cout<<"\nEnter your preferred number of working days: ";
			cin>>working_days;
			cout<<"\nEnter your preffered number of working hours: ";
			cin>>working_hours;
			cout<<"\nAre you willing to do night shifts ? Press 1 for yes and 0 for No: ";
			cin>>night_shift;
			cout<<"\n\n-----------------------------------------Registration complete----------------------------------------\n\n"<<endl;
		}
	
	void show(){
		
		cout<<"Employee Id: "<<emp_id<<"\nName: "<<name<<"\nAge: "<<age<<"\nWorking Days: "<<working_days<<"\nWorking Hours: "<<working_hours<<"\nNight shift: "<<night_shift<<endl;		
	}	
	
	void write(ofstream &fout){

		fout<<emp_id<<"\n"<<name<<"\n"<<age<<"\n"<<working_days<<"\n"<<working_hours<<"\n"<<night_shift<<endl;
	}


};

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
		
		cout<<"\nStudent Name: "<<student_name<<"\tRoll No: "<<roll_no<<"\tStudent Year: "<<student_year<<"\tLocation "<<location<<"\tBuss No: "<<buss_no<<endl;
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
	
		void read(ifstream &fin, driver d){
	
		getline(fin>>ws,d.emp_id);
		getline(fin>>ws,d.name);
		fin>>d.age;
		fin>>d.experience;
		getline(fin>>ws,d.license);
		fin>>d.verified;
		d.show();
	}

	
	void read(ifstream &fin, attendent a){
	
		getline(fin>>ws,a.emp_id);
		getline(fin>>ws,a.name);
		fin>>a.age;
		fin>>a.working_hours;
		fin>>a.working_days;
		fin>>a.night_shift;
		a.show();
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

//Function overloading for pay calculation 
//payment rates are 200/hour for drivers and 150/hour for attendants 
int pay_calc (int hr) {
	int d_wage=200*hr;
	return d_wage;
}

int pay_calc (int hr,int days) {
	int salary = (((150*hr)*days)*4);
	return salary;
}

int main() 
{
	system ("color f0");
	students s[10];
	int vote;	
	int choice;
	int n = 0;
	int p;
	admin ob1(7860);	
	
		
	// THE ADMINISTRATOR PINCODE IS 7860

	
	
	cout<<"\n\n1.Administrator\n2.student\n3.Staff\nPlease select your identity: ";
	cin>>choice;
	
	while( choice>3 || choice<1)
	{
		cout<<"\nInvalid Entry!!";
		cout<<"\n\n1. Administrator\n\n2. Student\n\n3. Staff\n\nPlease select your identity: ";
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
			cout<<"Please Select\n\n1. Show the Record of All Students \n\n2. Search for a specific student's record\n\n3. See Record of Staff"<<endl;
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
				if(s[i].roll_no==s_std)
				{ob1.read(fin,s[i]);}
				
				fin.close();			
				}
			}
			else if(choice==1){
			
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
			if(choice==3){
			int z;
			driver d1;
			attendent a1;
			cout<<"\nWho's Records do you want to see?\n\n1. Driver\n\n2. Attendent\n Please select a number: "<<endl;
			cin>>z;
			if(z==1){
			ifstream fin("Driver_data.txt");
			ob1.read(fin,d1);
			fin.close();
			}
			else{
			ifstream fin("Attendent_data.txt");
			ob1.read(fin,a1);			
			fin.close();
			}
		}					
	}
}

	else if (choice==2) {
	
	do{
	

	cout<<"------------------------------------------------------Welcome to Bus Transportation Service-------------------------------------------"<<endl;
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

	cout<<"\n\nSelect your Location by entering its serial number: "<<endl;
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
	
	else if (choice==3) {
		driver d1;
		attendent a1;
		int pos;
		bool loop=1;
		bool validation=0;
		int x;
		cout<<"\n\nDo you want to check the Incomes or Register as an Employee\n 1.Check Incomes\n 2.Register as an Employee\nPlease select a number: "<<endl;
		cin>>x;
		if (x==1){
			int y;
			cout<<"\nCalculate incomes for:\n1.drivers\n2.attendants"<<endl;
			cin>>y;
			if (y==1) {
				int hours;
				cout<<"\nEnter the number of hours you will be working (income is calculated accordingly): "<<endl;
				cin>>hours;
				cout<<"\nYour wage for the day will be: $"<<pay_calc(hours)<<endl;
			}
			
			else if (y==2) {
				int hours,days;
				cout<<"\nenter the number of days you will be working: "<<endl;
				cin>>days;
				cout<<"\nenter the number of hours you will be working each day: "<<endl;
				cin>>hours;
				cout<<"\nYour monthly salary will be: $"<<pay_calc(hours,days);
			}
		}
		
		else if(x==2){
		while (loop){
			validation=0;
			while (validation==0) {
		cout<<"\n\n1. Driver\n\n2. Attendent\nChoose your positon by selecting a number:"<<endl;
		cin>>pos;
		if (pos==1){
			d1.driver_details();
			validation =1;
			ofstream fout("Driver_data.txt");
			d1.write(fout);
			fout.close();
		}
		
		else if (pos==2) {
			a1.attendent_preferences();
			validation=1;
			ofstream fout("Attendent_data.txt");
			a1.write(fout);
			fout.close();	
		}
		
		else {
			cout<<"Invalid entry. Please enter again"<<endl;
		}		
	}
		cout<<"\nDo yo wish to add another staff member? press 1 for yes 0 for no"<<endl;
		cin>>loop;
		}
	}

}
}
