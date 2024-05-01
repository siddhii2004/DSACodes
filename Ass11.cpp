/*Problem Statement:
Department maintains a student information. The file contains roll number,
name, division and address. Allow user to add, delete information of student.
Display information of particular employee. If record of student does not
exist an appropriate message is displayed. If it is, then the system displays
the student details. Use sequential file to main the data.
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct stud {
    int roll;
    char name[10];
    char div;
    char add[10];
}rec;

class student {
public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout;
    fout.open("stud.dat", ios::out | ios::binary);
    do {
        cout << "\n\tEnter Roll No of Student : ";
        cin >> rec.roll;
        cout << "\n\tEnter Name of Student : ";
        cin >> rec.name;
        cout << "\n\tEnter Division of Student : ";
        cin >> rec.div;
        cout << "\n\tEnter Address of Student : ";
        cin >> rec.add;
        fout.write((char *)&rec, sizeof(stud)); // Write data to file
        cout << "\n\tDo You Want to Add More Records: ";
        cin >> ans;
    } while(ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display() {
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    cout << "\n\tThe Contents of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while(fin.read((char *)&rec, sizeof(stud))) { // Read data from file
        if(rec.roll != -1)
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
    }
    fin.close();
}

int student::search() {
    int r;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    cout << "\n\tEnter Roll No: ";
    cin >> r;
    while(fin.read((char *)&rec, sizeof(stud))) { // Read data from file
        if(rec.roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            fin.close();
            return 1;
        }
    }
    cout << "\n\tRecord Not Found\n";
    fin.close();
    return -1;
}

void student::Delete() {
    int pos;
    pos = search();
    if(pos == -1) {
        cout << "\n\tRecord Not Found";
        return;
    }
    fstream f;
    f.open("stud.dat", ios::in | ios::out | ios::binary);
    f.seekp(pos * sizeof(stud)); // Move the file pointer to the position of the record
    rec.roll = -1; // Mark the record as deleted
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");
    f.write((char *)&rec, sizeof(stud)); // Write the updated record to the file
    f.close();
    cout << "\n\tRecord Deleted";
}

int main() {
    student obj;
    int ch;
    char ans;
    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch(ch) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.Delete(); break;
            case 4: obj.search(); break;
            default: cout << "\n\tInvalid Choice";
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu: "; 
        cin >> ans;
    } while(ans == 'y' || ans == 'Y');
    return 0;
}


