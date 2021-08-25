#include <iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<string.h>
#include <stdio.h>
#include<windows.h>

using namespace std;

int index=0;  /// global variable


class login;     /// login class/abstract class

class teacher
{
private:



 int op;
 int rollno;
char name[50];
int p_marks, c_marks, m_marks, e_marks, cs_marks;
float per;
char grade;
int num;

protected:

//virtual int test()=0; /// random pure virtual function, no use

void getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	cin>>name;
	cout<<"\nEnter The marks in Physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in Chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in Maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in English out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in Computer Science out of 100 : ";
	cin>>cs_marks;
	calculate();


}
 void calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=80)
		grade='A';
	else if(per>=70)
		grade='B';
	else if(per>=60)
		grade='C';
	else if(per>=33)
		grade='D';
	else
		grade='F';
}


    void result()
{
	char ch;
	int rno;
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? "<<endl<<endl<<endl<<endl;
	char date[9],time[9];

	cout<<endl <<"Current Date : "<< date << endl;
	cout<<endl <<"Current Time : "<< time << endl;


	cin>>ch;
	system("CLS");
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}
  void class_result()
{
	teacher st;
	ifstream inFile;
	inFile.open("students.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"=======================================================================\n";
	cout<<"R.No       Name           P    C    M    E    CS    %age    Grade"<<endl;
	cout<<"=======================================================================\n";
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		st.show_tabular();
	}


	inFile.close();
getch();
	system("CLS");
    display();

}


  void delete_student(int n)
{
	teacher st;
	ifstream inFile;
	inFile.open("students.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(teacher));
		}
	}
	outFile.close();
	inFile.close();
	remove("students.txt");
	rename("Temp.txt","students.txt");
	cout<<"\n\n\tRecord Deleted ..";

	getch();
		system("CLS");
    display();
}
  void modify_student(int n)
{
	int found=0;
	teacher st;
	fstream File;
	File.open("students.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}

	while(File.read((char *) &st, sizeof(teacher)) && found==0)
	{
		if(st.retrollno()==n)
		{

			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    int pos=(-1)*sizeof(st);
		    File.seekp(pos,ios::cur);
		    File.write((char *) &st, sizeof(teacher));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
		system("CLS");
    display();
}
    void display_sp(int n)
{
	teacher st;
	ifstream inFile;
	inFile.open("students.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";

	getch();
		system("CLS");
    display();
}

      void write_student()
{
	teacher st;
	ofstream outFile;
	outFile.open("students.txt",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(teacher));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();

	system("CLS");
    display();
}

void display_all()
{
	teacher st;
	ifstream inFile;
	inFile.open("students.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		st.show_tabular();

		cout<<"\n\n====================================\n";
		getch();
	system("CLS");
	}
	inFile.close();

	getch();
	system("CLS");
    display();
}





public:

void showdata()
{
	cout<<"\nRoll number of student : "  <<rollno;
	cout<<"\nName of student : "         <<name;
	cout<<"\nMarks in Physics : "        <<p_marks;
	cout<<"\nMarks in Chemistry : "      <<c_marks;
	cout<<"\nMarks in Maths : "          <<m_marks;
	cout<<"\nMarks in English : "        <<e_marks;
	cout<<"\nMarks in Computer Science :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"      <<grade;

	getch();
	system("CLS");

}

void show_tabular()
{
	cout<<rollno<<"       "<<name<<"           "<<p_marks<<"    "<<c_marks<<"    "<<m_marks<<"    "<<e_marks<<"    "<<cs_marks<<"    "<<per<<"    "<<grade<<endl;

//	cout<<rollno<<setw(3)<<" "<<name<<setw(20)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)<<e_marks<<setw(4)<<cs_marks<<setw(4)<<per<<setw(4)<<" "<<grade<<endl;
}
int retrollno()
{
	return rollno;
}

void display()
    {
                system("color 6");

        cout<<endl<<endl<<endl<<endl;

   cout<<"                *********************************************************************"<<endl;
   cout<<"                *-                      Welcome to Teacher Portal                  -*"<<endl;
   cout<<"                *-                      ________________________                   -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   ENTRY MENU                                    -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   	    	                                   -*"<<endl;
   cout<<"                *-         1-CREATE STUDENT RECORD                                 -*"<<endl;
   cout<<"                *-         2-DISPLAY ALL STUDENTS RECORDS                          -*"<<endl;
   cout<<"                *-         3-SEARCH STUDENT RECORD                                 -*"<<endl;
   cout<<"                *-         4-MODIFY STUDENT RECORD                                 -*"<<endl;
   cout<<"                *-         5-DELETE STUDENT RECORD                                 -*"<<endl;
   cout<<"                *-         6-BACK TO LOGIN SCREEN                                  -*"<<endl;
   cout<<"                *-                 Please Enter Your Choice (1-6)                  -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-*****************************************************************-*"<<endl;

cin>>op;
system("CLS");
	switch(op)
	{
	case 1:	write_student(); break;
	case 2:	class_result(); break;
	case 3:	cout<<"Please Enter The roll number "; cin>>num;
				display_sp(num);
				display(); break;
	case 4:	cout<<"Please Enter The roll number "; cin>>num;
				modify_student(num);break;
	case 5:	cout<<"Please Enter The roll number "; cin>>num;
				delete_student(num);break;
	case 6:   	break;
	default:	cout<<"\a"; display();
	}
    }
};
/////////////////////////////////////////////////
class student   ///student class /abstract class
{
private:
float fees;
int rno;
int op;

public:

    void getfees()
    {


ofstream fs("fees.txt",ios::app);
                cout<<"Enter Roll number ?";
                cin>>rno;
                cout<<"Enter fees : ";
                cin>>fees;


                fs<<rno<<" "<<fees<<" ";
                cout<<"Fees Updated!"<<endl;
                fs.close();
	getch();

	system("CLS");

    }

    void displayf(int n)
    {
        int countt=0;

ifstream fs("fees.txt",ios::in);
           while(!fs.eof())
                {
                fs>>rno>>fees;

                if(n==this->rno)        ///this
                {
                    cout<<"Fees :"<<fees;
                     break;
                  }

                }
                fs.close();

    }

    void display()
    {
        system("color 3");
   cout<<endl<<endl<<endl<<endl;

   cout<<"                *********************************************************************"<<endl;
   cout<<"                *-                      Welcome to Student Portal                  -*"<<endl;
   cout<<"                *-                      _______________________________            -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   ENTRY MENU                                    -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   	    	                                     -*"<<endl;
   cout<<"                *-         1-STUDENT REPORT CARD                                   -*"<<endl;
   cout<<"                *-         2-CLASS RESULT                                          -*"<<endl;
   cout<<"                *-         3-STUDENT FEES                                          -*"<<endl;
   cout<<"                *-         4-GO BACK TO LOGIN SCREEN                               -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                 Please Enter Your Choice (1-4)                  -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-*****************************************************************-*"<<endl;

cin>>op;
system("CLS");
	switch(op)
	{
	case 1:	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
	        display_sp(rno) ;
	        display();break;
	case 2:	class_result();
	        display(); break;
	case 3:cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
            displayf(rno);
	        display();break;

	case 4:   	break;
	default:	cout<<"\a"; display();
	}
    }



void class_result()
{

	teacher st;  /// composition
	ifstream inFile;
	inFile.open("students.txt",ios::binary);
	 try
    {
	if(!inFile)
	{
	    int i;
		 throw i;
		getch();
		return;
	}
    }

    catch(int)
    {
        cout<<"File could not be open !! Press any Key...";

    }
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"=======================================================================\n";
	cout<<"R.No       Name           P    C    M    E    CS    %age    Grade"<<endl;
	cout<<"=======================================================================\n";
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		st.show_tabular();
	}

	getch();
	inFile.close();
}

void display_sp(int n)
{
	teacher st;
	ifstream inFile;
	inFile.open("students.txt",ios::binary);

if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(teacher)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";

	getch();
}


};

class admin :public teacher,public student  ///multiple inheritance
{
public:
    int op;
    char username[50];
    char password[50];
     int flag=0;

int login (int ,int)    ///function overloading
{
 cout<<"Integers cannot be used! sorry!"<<endl;
 getch();
 return(0);
}
 int login(char  un[],char pw[]) ///function overloading
            {
                ifstream fs("Login.txt",ios::in);
                while(!fs.eof())
                {
                fs>>username>>password>>index;

                if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
                {
                    if(index==1)
                    {
                        flag=1;
                        student::display();
                        return 1;
                        break;
                    }
                    else if(index==2)
                    {
                        flag=1;
                        teacher::display();
                        return 1;
                        break;

                    }
                    else if(index==3)
                    {
                        flag=1;
                        admin::display();
                        return (1);
                        break;
                    }


                }




                }



                fs.close();

                return 0;
            }

    void getLogin()
{
    cout<<"Enter username?"<<endl;
    cin>>username;
    cout<<"Enter Password?"<<endl;
    cin>>password;


}



      void RegisterLogin()
      {

     ofstream fs("Login.txt",ios::app);
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter password: ";
                cin>>password;
                cout<<"Enter the following:"<<endl<<"1. Student."<<endl <<"2. Teacher"<<endl <<"3. Admin"<<endl;
                cin>>index;
                fs<<username<<" "<<password<<" "<<index<<" ";
                cout<<"Account Created!"<<endl;
                fs.close();
	getch();

	system("CLS");
    display();


      }



protected:
    void currentfees()
    {
        student s1;
        s1.getfees();
    }

public:




   void display()
    {
        system("color 4");
        cout<<endl<<endl<<endl<<endl;

   cout<<"                *********************************************************************"<<endl;
   cout<<"                *-                      Welcome to Administrater Portal            -*"<<endl;
   cout<<"                *-                      _______________________________            -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   ENTRY MENU                                    -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   	    	                                   -*"<<endl;
   cout<<"                *-         1-REGISTER LOGIN                                     -*"<<endl;
   cout<<"                *-         2-UPDATE STUDENT FEES                                   -*"<<endl;
   cout<<"                *-         3-GO BACK TO LOGIN SCREEN                               -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                 Please Enter Your Choice (1-3)                  -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-*****************************************************************-*"<<endl;

cin>>op;
system("CLS");
	switch(op)
	{
	case 1:	RegisterLogin(); break;
	case 2:	 currentfees();break;
	case 3: 	break;

	default:	cout<<"\a"; display();
	}
    }

};

class login : public admin ///inheritance
{
private:
char username[50];
char password[50];
string u;
string p;
 int ch1;
int hits=0;


public:

void operator ++()
{
    ifstream read;  /// ifstream to read file
    read.open("Counter.txt");
    read>>hits;
    read.close();

    ofstream write;   ///offsteam to write in file
    write.open("Counter.txt");
    hits++;
    write<<hits;
    write.close();

}

login()  ///constructor
{
    cout<<"Loading....Press Enter to continue";
    getch();
    system("CLS");

}
     ~login() ///destructor
{
    cout<<endl<<"For Feedback, Contact: Haris Irfan"<<endl;
    getch();
}


 void intro()
{
	 system("title FA18-BCE-090 - School Management System");
    system("color e");
	cout<<"\n\n\n\t\t     School ";
	cout<<"\n\n\t\t MANAGEMENT SYSTEM";
	cout<<"\n\n\t\t       PROJECT   (RMS)";
	cout<<"\n\n\n\tMADE BY : "<<endl<<endl;
cout<<"   *     * "<<"   *    " <<"  ******   "<<"*** "<<"  ****  "<<endl;
cout<<"   *     * "<<" *   *  " <<"  *     *  "<<" *  "<<" *     "<<endl;
cout<<"   ******* "<<" *****  " <<"  ******   "<<" *  "<<"   ***   "<<endl;
cout<<"   *     * "<<" *   *  " <<"  *   *    "<<" *  "<<"      * "<<endl;
cout<<"   *     * "<<" *   *  " <<"  *    *   "<<"*** "<<"  **** "<<endl;
cout<<endl<<endl<<endl<<endl<<endl;

cout<<"Press Enter to continue"<<endl;
	getch();
}

int access()
{
    login a2;
    ++a2;   ///overloaded operator
    int counter=0;
    ifstream r;
    r.open("Counter.txt");
    r>>hits;
    counter=hits;
    r.close();


        fflush(stdin);


   cout<<endl<<endl<<endl<<endl;
   cout<<"                *********************************************************************"<<endl;
   cout<<"                *-                      School Portal Login                        -*"<<endl;
   cout<<"                *-                      ___________________                        -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                 Total Login Attempts:"<<counter  <<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-                   	    	                                   -*"<<endl;
   cout<<"                *-          Username :";cin>>username;cout<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-          Password :";cin>>password;cout<<endl;
   cout<<"                *-                                                                 -*"<<endl;
   cout<<"                *-*****************************************************************-*"<<endl;




    system("CLS");

int k;
admin a1;



k=a1.login(username,password);
  ///a1.login(1,4); ///overloaded func




if(k==0)
    cout<<"Wrong Credentials"<<endl;
    Beep(1568, 5000);                      ///beep
getch();

intro();

getch();



    system("CLS");


   access();



}


};








int main()
{
    login a1;

    a1.access();


}
