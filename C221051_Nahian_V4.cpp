#include<bits/stdc++.h>
using namespace std;
int std_cnt=0,n=0,tec_cnt=0,m=0,n1,m1,cr=0,course[100];
double ar[100]={0};
class student
{
    string std_name,ID,sem,sec,std_tec,std_pass,reg;
public:
    student()
    {}
    student(string std_name, string ID, string sem, string sec, string std_tec,string std_pass,string reg)
    {
        this->std_name=std_name;
        this->ID=ID;
        this->sem=sem;
        this->sec=sec;
        this->std_tec=std_tec;
        this->std_pass=std_pass;
        this->reg=reg;
    }
    void get_std()
    {
        cout<<"\t\t\t\t\tName                 : "<<std_name<<endl;
        cout<<"\t\t\t\t\tMetric ID            : "<<ID<<endl;
        cout<<"\t\t\t\t\tSemester             : "<<sem<<endl;
        cout<<"\t\t\t\t\tSection              : "<<sec<<endl;
        cout<<"\t\t\t\t\tTeachers's Name      : "<<std_tec<<endl;
        cout<<"\t\t\t\t\tRegistration Status  : INCOMPLETE"<<endl;
    }
    string Id()
    {
        return ID;
    }
    string pass()
    {
        return std_pass;
    }
    string tec_name()
    {
        return std_tec;
    }
    friend void read_std_info();
    friend void write_std_info();

    friend void add_std_info();
    friend void search_std_info();
    friend void edit_std_info();
    friend void delete_std_info();
    friend void tec_registration();
    friend void check_result();
    friend void tec_result();
    friend void change_pass();
    friend void reg();
    friend void result();
    friend void read_reg_info();
    friend void write_reg_info();
    friend void write_result_info();
    friend void read_result_info();
    friend void search_tec_info();
} student_arr[100];
class registration
{
    string ID,CSE_1221,MATH_1207,CSE_1230,EEE_1222,PHY_1201;
    int total_credit;
public:
    registration(){}
    void set_registration(string ID,string CSE_1221,string MATH_1207,string CSE_1230,string EEE_1222,string PHY_1201,int total_credit)
    {
        this->ID           = ID;
        this->CSE_1221     = CSE_1221;
        this->MATH_1207    = MATH_1207;
        this->CSE_1230     = CSE_1230;
        this->EEE_1222     = EEE_1222;
        this->PHY_1201     = PHY_1201;
        this->total_credit = total_credit;
    }
    void get_registration()
    {
        cout << "\t\t\t" <<" Course Code        Course Title                Credit Hour     Status" << endl;
        cout << "\t\t\t" <<" CSE-1221           Computer Programming II          3         : " << CSE_1221 << endl;
        cout << "\t\t\t" <<" MATH-1207          Mathematics II                   3         : " << MATH_1207 << endl;
        cout << "\t\t\t" <<" EEE-1222           Competitive Programming I        1         : " << CSE_1230 << endl;
        cout << "\t\t\t" <<" CSE-1230           Electronics                      3         : " << EEE_1222<< endl;
        cout << "\t\t\t" <<" PHY-1201           Physics II                       3         : " << PHY_1201 << endl;
        cout << "\t\t\t" <<"                        ### --> TOTAL CREDIT HOUR  = " << total_credit << endl;
    }
    string Id()
    {
        return ID;
    }
    friend void write_reg_info();
    friend void read_reg_info();
}registration_arr[100];
class result
{
    string ID;
    double cgpa;
public:
    result(){}
    void set_result(string ID,double cgpa)
    {
        this->ID=ID;
        this->cgpa=cgpa;
    }
    void get_result()
    {
        printf("\t\t\t CGPA = %.2lf\n",cgpa);
    }
    string Id()
    {
        return ID;
    }
    friend void write_result_info();
    friend void read_result_info();
}result_arr[100];
void write_reg_info()
{
    fstream write("C221051_reg.txt",ios::out);
    write<<std_cnt<<endl;
    for(int i=0; i<std_cnt; i++)
    {
        write << registration_arr[i].ID << endl;
        write << registration_arr[i].CSE_1221 << endl;
        write << registration_arr[i].MATH_1207 << endl;
        write << registration_arr[i].EEE_1222 << endl;
        write << registration_arr[i].CSE_1230 << endl;
        write << registration_arr[i].PHY_1201 << endl;
        write << registration_arr[i].total_credit << endl;
    }

    write.close();
}
void read_reg_info()
{
    fstream read("C221051_reg.txt",ios::in);
    read>>std_cnt;
    for(int i=0;i<std_cnt;i++)
    {
        read >> registration_arr[i].ID;
        read.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(read, registration_arr[i].CSE_1221);
        getline(read, registration_arr[i].MATH_1207);
        getline(read, registration_arr[i].EEE_1222);
        getline(read, registration_arr[i].CSE_1230);
        getline(read, registration_arr[i].PHY_1201);
        read >> registration_arr[i].total_credit;
    }
}
void write_result_info()
{
    fstream write("C221051_result.txt",ios::out);
    write<<std_cnt<<endl;
    for(int i=0;i<std_cnt;i++)
    {
        write << result_arr[i].ID <<endl;
        write << result_arr[i].cgpa <<endl;
    }
    write.close();
}
void read_result_info()
{
    fstream read("C221051_result.txt",ios::in);
    read >> std_cnt;
    for(int i=0;i<std_cnt;i++)
    {
        read>>result_arr[i].ID;
        read>>result_arr[i].cgpa;
    }
    read.close();
}
void write_std_info()
{
    fstream write("C221051_std.txt",ios::out);
    write<<std_cnt<<endl;
    for(int i=0;i<std_cnt;i++)
    {
        write<<student_arr[i].std_name<<endl;
        write<<student_arr[i].ID<<endl;
        write<<student_arr[i].sem<<endl;
        write<<student_arr[i].sec<<endl;
        write<<student_arr[i].std_tec<<endl;
        write<<student_arr[i].std_pass<<endl;
        write<<student_arr[i].reg<<endl;
    }
    write.close();
}
void read_std_info()
{
    fstream read("C221051_std.txt",ios::in);
    read>>std_cnt;
    for(int i=0;i<std_cnt;i++)
    {
        read >> student_arr[i].std_name;
        read >> student_arr[i].ID;
        read >> student_arr[i].sem;
        read >> student_arr[i].sec;
        read >> student_arr[i].std_tec;
        read >> student_arr[i].std_pass;
        read >> student_arr[i].reg;
        read << endl;
    }
    read.close();
}
void add_std_info()
{
    system("cls");
    read_std_info();
    cout<<endl<<"\t\t\t\t\t  Total Student : ";
    cin>>n;
    int n1=1;
    if(std_cnt>0){
        n1=std_cnt+1;
    }
    for(int i=std_cnt;i<(std_cnt+n);i++)
    {
        string std_name,ID,sem,sec,std_tec,reg,std_pass;
        cout<<endl;
        iD:
        cout << "\t\tEnter Info Of Student Number : " << n1 <<endl;
        cout << "\t\tEnter Name           : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, std_name);
        cout << "\t\tEnter Metric ID      : ";
        cin >> ID;

        for(int j=0;j<(std_cnt+n);j++){
            if(ID == student_arr[j].Id()){
                system("cls");
                cout<<"\n\t\t\t\t\t\tID Already Exists!"<<endl<<"  \t\t\t\t\t\t  Enter Again!"<<endl<<endl;
                int value;
                cout<<"\t\t\t\t\tReturn To Main Menu ( Press 0 ) : ";
                cin>>value;
                if(value==0){
                    goto v;
                }
                else{
                    goto iD;
                }
            }
        }
        cout << "\t\tEnter Semester       : ";
        cin >> sem;
        cout << "\t\tEnter Section        : ";
        cin >> sec;
        cout << "\t\tEnter Teacher's Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, std_tec);
        cout << "\t\tEnter Password       : ";
        cin >> std_pass;

        student_arr[i] = student(std_name, ID, sem, sec, std_tec, std_pass, reg);
        cout<<endl;
        n1++;
    }
    std_cnt+=n;
    v:
    write_std_info();
}
void search_std_info()
{
    system("cls");
    read_std_info();
    if(std_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else
    {
        string ID;
        int x=0;
        cout<<endl;
        cout<<"\t\t\t\t\t  Enter Metric ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<std_cnt;i++){
            if(ID ==student_arr[i].Id())
            {
                student_arr[i].get_std();
                x=1;
                break;
            }
        }
        if(x==0){
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else{
            cout<<"\n\t\t\t\t\tPress Enter To Continue..."<<endl;
            fflush(stdin);
            getchar();
            system("cls");
        }
    }
    cout<<endl;
}
void edit_std_info()
{
    system("cls");
    read_std_info();
    if(std_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else
    {
        string id;
        int x=0,wrong_pass=0;
        cout<<endl;
        cout<<"\t\t\t\t\tEnter Metric ID : ";
        cin>>id;
        string password;
        cout<<"\t\t\t\t\tEnter Password  : ";
        cin>>password;
        cout<<endl;
        for(int i=0;i<std_cnt;i++)
        {
            if(id  ==  student_arr[i].Id())
            {
                if(password == student_arr[i].pass())
                {
                    x=1;
                    string std_name,ID,sem,sec,std_tec,std_pass,reg;
                    cout<<endl;
                    cout << "\t\t\t\t\tEnter Info Of        : " << id <<endl<<endl;
                    cout << "\t\t\t\t\tEnter Name           : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, std_name);
                    cout << "\t\t\t\t\tEnter Metric ID      : ";
                    cin >> ID;
                    cout << "\t\t\t\t\tEnter Semester       : ";
                    cin >> sem;
                    cout << "\t\t\t\t\tEnter Section        : ";
                    cin >> sec;
                    cout << "\t\t\t\t\tEnter Teacher's Name : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, std_tec);
                    student_arr[i] = student(std_name, ID, sem, sec, std_tec, std_pass, reg);
                    cout<<endl;
                    wrong_pass=0;
                    break;
                }
                else{
                    wrong_pass=1;
                }
            }
        }
        if(wrong_pass==1){
            cout<<"\t\t\t\t\t\tWRONG PASSWORD!\n\t\t\t\t\t\t   TRY AGAIN."<<endl;
        }
        else if(x==0){
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else{
            cout<<"\t\t\t\t   Successfully Edited Info Of : "<<id<<endl<<endl;
        }
    }
    write_std_info();
}
void delete_std_info()
{
    system("cls");
    read_std_info();
    if(std_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else
    {
        string ID;
        int x=0,change;
        cout<<endl;
        cout<<"\t\t\t\t\t  Enter Metric ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<std_cnt;i++)
        {
            if(ID==student_arr[i].Id())
            {
                x=1;
                change=i;
                break;
            }
        }
        if(x==0){
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else{
            for(int i=change;i<std_cnt;i++)
            {
                student_arr[i]      = student_arr[i+1];
            }
            std_cnt-=1;
            cout<<"\t\t\t\t\t  Successfully Deleted!"<<endl<<endl;
        }
    }
    write_std_info();
}
class teacher
{
    string name,ID,dept,des,pass;
public:
    teacher()
    {}
    teacher(string name,string ID,string dept,string des,string pass)
    {
        this->name=name;
        this->ID=ID;
        this->dept=dept;
        this->des=des;
        this->pass=pass;
    }
    void tec_get()
    {
        cout<<"\t\t\t\t\tName           : "<<name<<endl;
        cout<<"\t\t\t\t\tID             : "<<ID<<endl;
        cout<<"\t\t\t\t\tDepartment     : "<<dept<<endl;
        cout<<"\t\t\t\t\tDesignation    : "<<des<<endl;
    }
    string Id()
    {
        return ID;
    }
    string tec_pass()
    {
        return pass;
    }
    string Name()
    {
        return name;
    }
    friend void read_tec_info();
    friend void write_tec_info();
    friend void add_tec_info();
    friend void search_tec_info();
    friend void edit_tec_info();
    friend void std_registration();
    friend void tec_registration();
    friend void tec_change_pass();
    friend void delete_tec_info();
} teacher_arr[100];
void write_tec_info()
{
    fstream write("C221051_tec.txt",ios::out);
    write<<tec_cnt<<endl;
    for(int i=0;i<tec_cnt;i++)
    {
        write<<teacher_arr[i].name<<endl;
        write<<teacher_arr[i].ID<<endl;
        write<<teacher_arr[i].dept<<endl;
        write<<teacher_arr[i].des<<endl;
        write<<teacher_arr[i].pass<<endl;
        write<<endl;
    }
    write.close();
}
void read_tec_info()
{
    fstream read("C221051_tec.txt",ios::in);
    read>>tec_cnt;
    for(int i=0;i<tec_cnt;i++)
    {
        read >> teacher_arr[i].name;
        read >> teacher_arr[i].ID;
        read >> teacher_arr[i].dept;
        read >> teacher_arr[i].des;
        read >> teacher_arr[i].pass;
    }
    read.close();
}
void add_tec_info()
{
    system("cls");
    read_tec_info();
    cout<<"\t\t\t\t\t  Total Teacher : ";
    cin>>m;
    int m1=1;
    if(tec_cnt>0){
        m1=tec_cnt+1;
    }
    for(int i=tec_cnt;i<(tec_cnt+m);i++)
    {
        string name,ID,dept,des,pass;
        cout<<endl;
        iD:
        cout<<"\t\t\t\tEnter Info Of Teacher No : "<<m1<<endl;
        cout << "\t\t\t\tEnter Name        : ";
        cin >> name;
        cout << "\t\t\t\tEnter ID          : ";
        cin >> ID;
        for(int j=0;j<(tec_cnt+m);j++){
            if(ID == teacher_arr[j].Id()){
                system("cls");
                cout<<"\n\t\t\t\t\t\tID Already Exists!"<<endl<<"  \t\t\t\t\t\t  Enter Again!"<<endl<<endl;
                int value;
                cout<<"\t\t\t\t\tReturn To Main Menu ( Press 0 ) : ";
                cin>>value;
                if(value==0){
                    goto v;
                }
                else{
                    goto iD;
                }
            }
        }
        cout << "\t\t\t\tEnter Department  : ";
        cin >> dept;
        cout << "\t\t\t\tEnter Designation : ";
        cin >> des;
        cout << "\t\t\t\tEnter Password    : ";
        cin>> pass;
        teacher_arr[i] = teacher(name, ID, dept, des, pass);
        cout<<endl;
        m1++;
    }
    tec_cnt+=m;
    v:
    write_tec_info();
}
void search_tec_info()
{
    system("cls");
    read_tec_info();
    if(tec_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Teacher Info Inserted"<<endl;
    }
    else
    {
        string ID;
        int y=0,total_std=0,check=0;
        cout<<endl;
        cout<<"\t\t\t\t\t  Enter ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<tec_cnt;i++)
        {
            if(ID == teacher_arr[i].Id())
            {
                y=1;
                teacher_arr[i].tec_get();
                for(int j=0;j<std_cnt;j++)
                {
                    if(teacher_arr[i].Name() == student_arr[j].tec_name())
                    {
                        total_std++;
                    }
                }
                cout<<"\t\t\t\t\tTotal Sudent   : "<<total_std<<endl;
                cout<<"\n\t\t\t\t\tPress 1 to Show Student's Data : ";
                cin>>check;
                if(check==1){
                    for(int j=0;j<std_cnt;j++)
                    {
                        if(teacher_arr[i].Name() == student_arr[j].tec_name())
                        {
                            student_arr[j].get_std();
                            cout<<endl;
                            fflush(stdin);
                            getchar();
                        }
                    }
                }
                else{
                    goto v;
                }
                break;
            }
        }
        if(y==0)
        {
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else{
            v:
            cout<<"\n\t\t\t\t\tPress Enter To Continue..."<<endl;
            fflush(stdin);
            getchar();
            system("cls");
        }
    }
}
void edit_tec_info()
{
    system("cls");
    read_tec_info();
    if(tec_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Teacher Info Inserted"<<endl;
    }
    else
    {
        system("cls");
        string ID,password;
        int x=0,y=0;
        cout<<"\n\t\t\t\t\t  Enter ID         : ";
        cin>>ID;
        cout<<"\t\t\t\t\t  Enter Password   : ";
        cin>>password;
        cout<<endl;
        for(int i=0;i<tec_cnt;i++)
        {
            if(ID == teacher_arr[i].Id())
            {
                x=1;
                if(password == teacher_arr[i].tec_pass())
                {
                    y=1;
                    string name,ID,dept,des,total_std,pass;
                    cout<<endl;
                    cout<<"\t\t\t\tEnter Info Of Teacher No : "<<ID<<endl;
                    cout << "\n\t\t\t\t\tEnter Name        : ";
                    cin >> name;
                    cout << "\t\t\t\t\tEnter ID          : ";
                    cin >> ID;
                    cout << "\t\t\t\t\tEnter Department  : ";
                    cin >> dept;
                    cout << "\t\t\t\t\tEnter Designation : ";
                    cin >> des;
                    teacher_arr[i] = teacher(name, ID, dept, des, pass);
                    cout<<endl;
                }
            }
        }
        if(x==0){
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else if(y==0){
            cout<<"\t\t\t\t\t\tWRONG PASSWORD!\n\t\t\t\t\t\t   TRY AGAIN."<<endl;
        }
        else{
            cout<<"\t\t\t\tSuccessfully Edited Info Of : "<<ID<<endl;
        }
    }
    write_tec_info();
}
void delete_tec_info()
{
    system("cls");
    read_tec_info();
    if(tec_cnt==0)
    {
        cout<<"\t\t\t\t\tNo Teacher Info Inserted"<<endl;
    }
    else
    {
        string ID,pass;
        int x=0,change,y=0;
        cout<<endl;
        cout<<"\t\t\t\t\t  Enter Metric ID : ";
        cin>>ID;
        cout<<"\t\t\t\t\t  Enter Password  : ";
        cin>>pass;
        cout<<endl;
        for(int i=0;i<std_cnt;i++)
        {
            if(ID==teacher_arr[i].Id())
            {
                x=1;
                if(pass==teacher_arr[i].tec_pass())
                {
                    y=1;
                    change=i;
                    break;
                }
            }
        }
        if(x==0){
            cout<<"\t\t\t\t\t\tData Not Found!"<<endl<<"\t\t\t\t\t    Returned To Main Menu"<<endl;
        }
        else if(y==1){
            cout<<"\t\t\t\t\t\tWrong Password!"<<endl;
        }
        else{
            for(int i=change;i<tec_cnt;i++)
            {
                teacher_arr[i]      = teacher_arr[i+1];
            }
            tec_cnt-=1;
            cout<<"\t\t\t\t\t  Successfully Deleted!"<<endl<<endl;
        }
    }
    write_tec_info();
}
void tec_change_pass()
{
    system("cls");
    read_tec_info();
    if(tec_cnt==0){
        cout<<"\t\t\t\t\tNo Teacher Info Inserted"<<endl;
    }
    else{
    string id,name,ID,dept,des,new_pass1,new_pass2;
    int temp=0,try_failed=3,wrong=0;
    cout<<"\n\t\t\t\t\tEnter ID           : ";
    cin>>id;
    again_pass:
    string password;
    cout<<"\t\t\t\t\tEnter Old Password : ";
    cin>>password;
    for(int i=0;i<tec_cnt;i++)
    {
        if(id  ==  teacher_arr[i].Id())
        {
            if(password == teacher_arr[i].tec_pass())
            {
                again:
                wrong=0;
                cout<<"\n\t\t\t\t\tEnter New Password   : ";
                cin>>new_pass1;
                cout<<"\t\t\t\t\tConfirm New Password : ";
                cin>>new_pass2;
                if(new_pass1 == new_pass2){
                    teacher_arr[i] = teacher(name, ID, dept, des, new_pass2);
                    temp=1;
                    break;
                }
                else{
                    goto again;
                }
            }
            else{
                wrong=1;
            }
        }
    }
    if(wrong==1){
        system("color C0");
        cout<<"\t\t\t\t\t\tWrong Password!"<<endl;
        if(try_failed==1)
        {
            system("color E0");
        }
        cout<<"\t\t\t\t\t\tTry Again."<<endl;
        try_failed--;
        system("color E0");
        goto again_pass;
    }
    else if(temp == 1){
        cout<<"\n\t\t\t\t\tPassword Changed Successfully!"<<endl;
    }
    }
    write_std_info();
}
void change_pass()
{
    system("cls");
    read_std_info();
    if(std_cnt==0){
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else{
    string id,std_name,ID,sem,sec,std_tec,new_pass1,new_pass2,reg;
    int temp=0,try_failed=3,wrong=0;
    cout<<"\n\t\t\t\t\tEnter METRIC ID : ";
    cin>>id;
    again_pass:
    string password;
    cout<<"\t\t\t\t\tEnter Old Password : ";
    cin>>password;
    for(int i=0;i<std_cnt;i++)
    {
        if(id  ==  student_arr[i].Id())
        {
            if(password == student_arr[i].pass())
            {
                again:
                wrong=0;
                cout<<"\n\t\t\t\t\tEnter New Password   : ";
                cin>>new_pass1;
                cout<<"\t\t\t\t\tConfirm New Password : ";
                cin>>new_pass2;
                if(new_pass1 == new_pass2)
                {
                    student_arr[i] = student(std_name, ID, sem, sec, std_tec, reg, new_pass2);
                    temp=1;
                    break;
                }
                else
                {
                    goto again;
                }
            }
            else{
                wrong=1;
            }
        }
    }
    if(wrong==1){
        system("color C0");
        cout<<"\t\t\t\t\t\tWrong Password!"<<endl;
        if(try_failed==1)
        {
            system("color E0");
        }
        cout<<"\t\t\t\t\t\tTry Again."<<endl;
        try_failed--;
        system("color E0");
        if(try_failed>0){
            goto again_pass;
        }
    }
    else if(temp == 1){
        cout<<"\n\t\t\t\t\tPassword Changed Successfully!"<<endl;
    }
    }
    write_std_info();
}
void std_registration()
{
    system("cls");
    string ID;
    if(std_cnt==0){
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else{
    int check=0;
    cout<<"\t\t\t\t\t  Enter ID : ";
    cin>>ID;
    for(int i=0;i<std_cnt;i++)
    {
        if(ID == student_arr[i].Id())
        {
            if(course[i]==1){
                cout<<"\n\t\t\t\t\t   ALREADY APPLIED!"<<endl;
                break;
            }
            else if(course[i]==2){
                cout<<"\n\t\t\t\t\t   REQUEST ACCEPTED!"<<endl;
                break;
            }
            else if(course[i]==3){
                cout<<"\n\t\t\t\t\t   REQUEST DENIED!"<<endl;
                course[i]=0;
                break;
            }
            else{
                course[i]=1;
                check=1;
                break;
            }
        }
        else{
            check=0;
        }
    }
    if(check==1)
    {
        cr++;
        cout<<"\n\t\t\t\tApplication For Course Registration Succeed!!"<<endl;
        cout<<"\t\t\t  Please Wait For Course Teacher To Confirm Your Application."<<endl;
    }
    }
    cout<<endl;
}
void tec_registration()
{
    system("cls");
    int X=0;
    if(cr==0){
        cout<<"\t\t\tNO NEW APPLICATION!"<<endl;
    }
    else{
        cout<<"\t\t\t\t\tNew Application Found!"<<endl<<"\t\t\t\t  Showing Requested Students Info...."<<endl;
        for(int i=0;i<std_cnt;i++)
        {
            if(course[i]==1)
            {
                cout<<endl;
                student_arr[i].get_std();
                cout<<"\n\t\t\t\t\t< 1 > ACCEPT \t\t< 2 > REJECT"<<endl;
                cout<<endl<<"\t\t\t\t\t   I Choose : ";
                cin>>X;
                cout<<endl<<endl;
                if(X==1){
                    course[i]=2;
                }
                else if(X==2){
                    course[i]=3;
                }
                cr--;
            }
        }
    }
}
void check_result()
{
    system("cls");
    if(std_cnt==0){
        cout<<"\t\t\t\t\tNo Student Info Inserted"<<endl;
    }
    else{
    string ID;
    cout<<"\t\t\t\t\t  Enter ID : ";
    cin>>ID;
    cout<<endl;
    for(int i=0;i<std_cnt;i++)
    {
        if(ID == student_arr[i].Id())
        {
            if(ar[i]!=0&&course[i]==2){
                student_arr[i].get_std();
                printf("\t\t\t\t\tCGPA                 : %.2lf\n\n",ar[i]);
                break;
            }
            else if(course[i]==0||course[i]==3){
                cout<<"\t\t\t\tFinish Your Course Registration First!"<<endl<<endl;
                break;
            }
            else{
                cout<<"\t\t\t\t\t   Result Not Yet Available!"<<endl<<endl;
                break;
            }

        }
    }
    }
}
void tec_result()
{
    system("cls");
    string ID;
    int fail=0;
    cout<<"\t\t\t\t\t  Enter ID : ";
    cin>>ID;
    for(int i=0;i<std_cnt;i++)
    {
        if(ID == student_arr[i].Id())
        {
            if(course[i]==2){
                student_arr[i].get_std();
                cout<<"\t\t\t\t\tEnter Result         : ";
                cin>>ar[i];
                cout<<endl;
                fail=1;
                break;
            }
            else if(course[i]==0||course[i]==3){
                cout<<"\n\t\t\t\t\tCourse Registration Incomplete!"<<endl<<endl;
                fail=1;
                break;
            }

        }
    }
    if(fail==0){
            system("color C0");
        cout<<"\t\t\t\tINVALID ID , PLEASE TRY AGAIN!!"<<endl<<endl;
        system("color E0");
    }
}
int main()
{
    system("cls");
    system("color E0");
    ifstream check_std_file("C221051_std.txt");
    if(!check_std_file)
    {
        fstream open_file_std("C221051_std.txt", ios::app);
        {
            open_file_std << " \t\t\tTOTAL STUDENT = 0 \n"<<endl;
        }
    }
    ifstream check_tec_file("C221051_tec.txt");
    if(!check_tec_file)
    {
        fstream open_file_tec("C221051_tec.txt", ios::app);
        {
            open_file_tec << " \t\t\tTOTAL TEACHER = 0 \n" <<endl;
        }
    }
    ifstream check_reg_file("C221051_reg.txt");
    if(!check_reg_file)
    {
        fstream open_file_reg("C221051_reg.txt", ios::app);
        {
            open_file_reg << " \t\t\tTOTAL STUDENT = 0 \n" << endl;
        }
    }
    ifstream check_result_file("C221051_result.txt");
    if(!check_result_file)
    {
        fstream open_file_result("C221051_resut.txt",ios::app);
        {
            open_file_result << "\t\t\tTOTAL STUDENT = 0 \n" <<endl;
        }
    }
    int a,a1,b;
    cout<<"\t\t\t\t\t   Bismillahir Rahmanir Rahim\n";
    cout <<"\t\t\t\t\t        Welcome to IIUC" << endl;
    cout<<"\t\t\t\t       ================================="<<endl;
    while(1)
    {
        cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t S T U D E N T \t\t\t\t\t T E A C H E R"<<endl;
        cout<<"\t\t\t    PRESS 1 \t\t\t\t\t    PRESS 2"<<endl;
        cout<<"\t\t\t\t\t\t    EXIT"<<endl;
        cout<<"\t\t\t\t\t\t   PRESS 0"<<endl;
        cout<<endl<<"\t\t\t\t\t\tI Choose : ";
        cin>>a;
        n1=m1=0;
        if(a==0)
        {
            cout<<endl<<"\t\t\t\t\t      DO YOU WANT TO EXIT?"<<endl;
            cout<<"\t\t\t\t< 1 > YES          \t\t\t< 2 > NO"<<endl;
            cout<<"\t\t\t\t\t\tI Choose : ";
            cin>>a1;
            if(a1==1){
                cout<<endl<<"\t\t\t\t\t\tTHANK YOU!";
                cout<<endl<<"\t\t\t\t\t   Exited Successfully!!"<<endl;
                return 0;
            }
            else{
                continue;
            }
        }
        else if(a==1)
        {
            while(1)
            {
                failed:
                //system("cls");
                system("color E0");
                cout<<"\n\t\t\t\t\t   | STUDENT MAIN MENU |"<<endl;
                cout<<"\t\t\t\t\t   ....................."<<endl<<endl;
                cout<<"\t\t\t\t\t < 1 > Add New Students"<<endl;
                cout<<"\t\t\t\t\t < 2 > Search Student Info"<<endl;
                cout<<"\t\t\t\t\t < 3 > Edit Student Data"<<endl;
                cout<<"\t\t\t\t\t < 4 > Delete Student Data"<<endl;
                cout<<"\t\t\t\t\t < 5 > Course Registration"<<endl;
                cout<<"\t\t\t\t\t < 6 > See Result"<<endl;
                cout<<"\t\t\t\t\t < 7 > Change Password"<<endl;
                cout<<"\t\t\t\t\t < 0 > Main Menu"<<endl;
                cout<<endl<<"\t\t\t\t\t   I Choose : ";
                cin>>b;
                if(b==0){
                    break;

                }
                else if(b==1){
                    add_std_info();
                }
                else if(b==2){
                   search_std_info();
                }
                else if(b==3){
                    edit_std_info();
                }
                else if(b==4){
                    delete_std_info();
                }
                else if(b==5){
                    std_registration();
                }
                else if(b==6){
                    check_result();
                }
                else if(b==7){
                    change_pass();
                }
            }
        }
        else if(a==2)
        {
            while(1)
            {
                system("color E0");
                cout<<"\n\t\t\t\t\t   | TEACHER MAIN MENU |"<<endl;
                cout<<"\t\t\t\t\t   ....................."<<endl<<endl;
                cout<<"\t\t\t\t\t < 1 > Add New Teacher"<<endl;
                cout<<"\t\t\t\t\t < 2 > Search Teacher's Info"<<endl;
                cout<<"\t\t\t\t\t < 3 > Edit Teacher's Info"<<endl;
                cout<<"\t\t\t\t\t < 4 > Delete Teacher's Info"<<endl;
                cout<<"\t\t\t\t\t < 5 > Course Regestration Request |"<<cr<<"|"<<endl;
                cout<<"\t\t\t\t\t < 6 > Result Processing"<<endl;
                cout<<"\t\t\t\t\t < 7 > Change Password"<<endl;
                cout<<"\t\t\t\t\t < 0 > Main Menu"<<endl<<endl;
                cout<<"\t\t\t\t\t   I Choose : ";
                cin>>b;
                if(b==0){
                    break;
                }
                else if(b==1){
                    add_tec_info();
                }
                else if(b==2){
                    search_tec_info();
                }
                else if(b==3){
                    edit_tec_info();
                }
                else if(b==4){
                    delete_tec_info();
                }
                else if(b==5){
                    tec_registration();
                }
                else if(b==6){
                    tec_result();
                }
                else if(b==7){
                    tec_change_pass();
                }
            }
        }
    }
}
