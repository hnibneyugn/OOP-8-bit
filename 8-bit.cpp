#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string id;
    string name;
    int birthYear;
public:
    Employee();
    Employee(string, string, int);
    Employee(const Employee&);
    string getID();
    void setID(string);
    string getName();
    void setName(string);
    int getBirthYear();
    void setBirthYear(int);
    virtual long getSalary() = 0;
    virtual void input();
    virtual void display();
    virtual ~Employee();
};

//Lớp EmployeePT    

class EmployeePT : public Employee {
private:
    int workHour;
    long salaryPerHour;
public:
    EmployeePT();
    EmployeePT(string, string, int, int, long);
    EmployeePT(const EmployeePT&);
    int getWorkHour();
    void setWorkHour(int);
    long getSalaryPerHour();
    void setSalaryPerHour(long);
    void input();
    void display();
    long getSalary();
    ~EmployeePT();
};

//Lớp EmployeeFT

class EmployeeFT : public Employee {
    private:
    int YoE;
    long constSal;
    long incSal;
    public:
    EmployeeFT();
    EmployeeFT(string, string, int, int, long);
    EmployeeFT(const EmployeeFT&);
    int getYoE();
    void setYoE(int);
    long getConstSal();
    void setConstSal(long);
    void input();
    bool checkA();
    void display();
    long getSalary();
    ~EmployeeFT();
};

//Phương thức làm tròn đến chữ số hàng nghìn của phương thức tính lương tháng của nhân viên
long roundSalary(long salary) {    
    int residual = salary % 1000;
    if(residual != 0){
    return (salary + (1000 - residual)) / 1000 * 1000;
    }
    else return salary;
}

//Phương thức chuẩn hóa khi nhập tên của nhân viên
void standard(string &t) {
    string res = "";
    stringstream ss(t);
    string token;
    while(ss >> token) {
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++) {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    t = res;
}

//---Các hàm kiểm tra tuổi nhân viên---//
bool checkAge(int birthYear) {
    if (2024 - birthYear < 18 || birthYear < 1959) return true;
    else return false;
}

bool Checkage(int byear, int YoE) {
    if(YoE - byear < 18 || YoE > 2024) return true;
    else return false;
}
//---Hàm kiểm tra số giờ làm của nhân viên---//
bool CheckHour(int hour) {
    if (hour > 200 || hour < 0) return true;
    else return false;
}

///////////////Hàm main///////////////


int main() {
    EmployeePT a[100];
    int aN = 0;
    EmployeeFT b[100];
    int bN = 0;
    char check;
    while (cin >> check) {
        if (check == 'P') {
            a[aN].input();
            a[aN].getSalary();
            aN++;
        }
        else if (check == 'F') {
            b[bN].input();
            b[bN].getSalary();
            bN++;
        }
    }
    if (aN != 0) {
        cout << "Nhan vien part-time: \n";
        for (int i = 0; i < aN; i++) {
            a[i].display();
            cout << endl;
        }
    }
    if (bN != 0) {
        cout << "Nhan vien full-time: \n";
        for (int i = 0; i < bN; i++) {
            b[i].display();
            cout << endl;
        }
    }
    return 0;
}


///////////////Các constructor và phương thức của lớp Employee///////////////


//Constructor mặc định của lớp Employee
Employee::Employee() {}

//Constructor có tham số của lớp Employee
Employee::Employee(string id, string name, int birthYear) {
    this ->id = id;
    this ->name = name;
    this ->birthYear = birthYear;
}

//Constructor sao chép của lớp Employee
Employee::Employee(const Employee& other){
    this ->id = other.id;
    this ->name = other.name;
    this ->birthYear = other.birthYear;
}

//Getter của thuộc tính ID
string Employee::getID() {
    return id;
}

//Setter của thuộc tính ID
void Employee::setID(string id) {
    this->id = id;
}

//Getter của thuộc tính name
string Employee::getName() {
    return name;
}

//Setter của thuộc tính name 
void Employee::setName(string name){
    this->name = name;
}

//Getter của thuộc tính birthYear
int Employee::getBirthYear() {
    return birthYear;
}
//Setter của thuộc tính birthYear
void Employee::setBirthYear(int birthYear){
    this->birthYear = birthYear;
}

//Phương thức ảo nhập thông tin của nhân viên
void Employee::input() {
    cin >> id;
    cin.ignore();
    getline(cin, name);
    cin >> birthYear;
    standard(name);
}

//Phương thức xuất thông tin chung của lớp Employee
void Employee::display() {
    cout << "ID: " << id << endl;
    cout << "Ho va ten: " << name << endl;
    cout << "Nam sinh: " << birthYear << endl;
}

//Destructor của lớp Employee
Employee::~Employee() {}


///////////////Các constructor và phương thức của lớp EmployeePT///////////////


//Constructor mặc định của lớp EmployeePT
EmployeePT::EmployeePT() {}

//Constructor chứa tham số của lớp EmployeePT
EmployeePT::EmployeePT(string id, string name, int birthYear, int workHour, long salaryperhour):Employee(id,  name, birthYear) {
    this->workHour = workHour;
    this->salaryPerHour = salaryPerHour;
}

//Constructor sao chép của lớp EmployeePT
EmployeePT::EmployeePT(const EmployeePT& other):Employee(other){
    this->workHour = other.workHour;
    this->salaryPerHour = other.salaryPerHour;
}

//Getter của thuộc tính workHour
int EmployeePT::getWorkHour() {
    return workHour;
}

//Setter của thuộc tính workHour
void EmployeePT::setWorkHour(int workHour) {
    this->workHour = workHour;
}

//Getter của thuộc tính salaryPerHour
long EmployeePT::getSalaryPerHour() {
    return salaryPerHour;
}

//Setter của thuộc tính salaryPerHour
void EmployeePT::setSalaryPerHour(long salaryPerHour) {
    this->salaryPerHour = salaryPerHour;
}

//Phương thức nhập dữ liệu của lớp EmployeePT
void EmployeePT::input() {
    Employee::input();
    cin >> workHour;
    cin >> salaryPerHour;
}

//Phương thức xuất thông tin của lớp EmployeePT (bao gồm id, họ tên, năm sinh, số giờ làm và lương tháng này)
void EmployeePT::display() {
    if(checkAge(Employee::getBirthYear()) || CheckHour(workHour)) {
        cout << Employee::getName() << endl << "Thong tin khong hop le" << endl; 
    }
    else {
        Employee::display();
        cout << "So gio da lam thang nay: " << workHour << "h" << endl;
        cout << "Luong thang nay: " << getSalary() << " VND" << endl;
    }
}

//Phương thức lấy lương tháng của lớp EmployeePT
long EmployeePT::getSalary() {
    long salary = salaryPerHour* workHour;
    return roundSalary(salary);
}

//Destructor của lớp EmployeePT
EmployeePT::~EmployeePT() {}


///////////////Các constructor và phương thức của lớp EmployeeFT///////////////


//Constructor mặc định của lớp EmployeeFT
EmployeeFT::EmployeeFT() {}

//Constructor chứa tham số của lớp EmployeeFT
EmployeeFT::EmployeeFT(string id, string name, int birthYear, int YoE, long constSal):Employee(id,  name, birthYear) {
    this->YoE = YoE;
    this->constSal = constSal;
}

//Constructor sao chép của lớp EmployeeFT
EmployeeFT::EmployeeFT(const EmployeeFT& other):Employee(other){
    this->YoE = other.YoE;
    this->constSal = other.constSal;
}

//Getter của thuộc tính YoE
int EmployeeFT::getYoE() {
    return YoE;
}

//Setter của thuộc tính Yoe
void EmployeeFT::setYoE(int YoE){
    this->YoE = YoE;
}

//Getter của thuộc tính constSal
long EmployeeFT::getConstSal() {
    return constSal;
}

//Setter của thuộc tính constSal
void EmployeeFT::setConstSal(long constCal){
    this->constSal = constCal;
}

//Phương thức nhập dữ liệu cho lớp EmployeeFT
void EmployeeFT::input() {
    Employee::input();
    cin >> YoE;
    cin >> constSal;
}

//Xuất thông tin nhân viên (bao gồm id, họ tên, năm sinh, năm bắt đầu làm việc và mức lương hiện tại)
void EmployeeFT::display() {
    if(checkAge(Employee::getBirthYear()) || Checkage(Employee::getBirthYear(), YoE)) {
        cout << Employee::getName() << endl << "Thong tin khong hop le" << endl;
    }
    else {
        Employee::display();
        cout << "Tham nien: " << 2024- YoE << " nam" << endl;
        cout << "Luong hien tai: " << getSalary()  << " VND" << endl;
        cout << "Luong duoc tang: " << incSal << " VND" << endl;
    }
}

//Tính lương theo thâm niên làm việc (tính tới 2024)
long EmployeeFT::getSalary() {
    int increase = (2024 - YoE)/3;
    for(int i = 0; i < increase; i++){
        incSal += (constSal * 0.2);
    }
    long salary = constSal + incSal;
    return roundSalary(salary);
}

//Destructor của lớp EmployeeFT
EmployeeFT::~EmployeeFT() {}