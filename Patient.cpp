#include "Patient.h"
int Patient::getId() const 
{
    return Id; 
}
string Patient::getName() const 
{
    return name; 
}
string Patient::getCnic() const 
{ 
    return cnic; 
}
string Patient::getPhoneNumber() const 
{ 
    return phoneNumber; 
}
string Patient::getDisease() const 
{ 
    return disease; 
}
bool Patient::getIsAdmitted() const 
{ 
    return isAdmitted; 
}
void Patient::setId(int id) 
{ 
    Id = id; 
}
void Patient::setName(const string& name) 
{ 
    this->name = name; 
}
void Patient::setCnic(const string& cnic) 
{ 
    this->cnic = cnic; 
}
void Patient::setPhoneNumber(const string& phoneNumber) 
{ 
    this->phoneNumber = phoneNumber; 
}
void Patient::setDisease(const string& disease) 
{ 
    this->disease = disease; 
}
void Patient::setIsAdmitted(bool isAdmitted) 
{ 
    this->isAdmitted = isAdmitted; 
}
void addPatient(string fileName)
{
    Patient p;
    int id;
    string name, cnic, phoneNumber, disease;
    bool isAdmitted;
    cout << "Enter Patient ID: ";
    cin >> id;
    p.setId(id);
    cin.ignore(); 
    cout << "Enter Patient Name: ";
    getline(cin, name);
    p.setName(name);
    cout << "Enter Patient CNIC: ";
    getline(cin, cnic);
    p.setCnic(cnic);
    cout << "Enter Patient Phone Number: ";
    getline(cin, phoneNumber);
    p.setPhoneNumber(phoneNumber);
    cout << "Enter Patient Disease: ";
    getline(cin, disease);
    p.setDisease(disease); 
    cout << "Is Patient Admitted (1 for Yes, 0 for No): ";
    cin >> isAdmitted;
    p.setIsAdmitted(isAdmitted);
    ofstream file(fileName, ios::binary | ios::app);
    file.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
    file.close();
    cout << "Patient record added successfully.\n";
}
void deletePatient(string fileName, int id)
{
    ifstream infile(fileName, ios::binary);
    if (!infile) 
    {
        cerr << "Error opening file for reading.\n";
        return;
    }  
    ofstream outfile("temp.txt", ios::binary);
    if (!outfile) 
    {
        cerr<< "Error opening file for writing.\n";
        return;
    }
    Patient p;
    bool found = false;
    while (infile.read(reinterpret_cast<char*>(&p), sizeof(Patient)))
    {
        if (p.getId() == id) 
        {
            found = true;
            continue;
        }
        outfile.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
    }
    infile.close();
    outfile.close();
    if (!found)
    {
        cout << "Patient not found.\n";
        remove("temp.txt");
        return;
    }
    ifstream tempin("temp.txt", ios::binary);
    ofstream origout(fileName, ios::binary | ios::trunc);
    if (!tempin || !origout) 
    {
        cerr << "Error opening file for final write.\n";
        return;
    }
    while (tempin.read(reinterpret_cast<char*>(&p), sizeof(Patient)))
    {
        origout.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
    }
    tempin.close();
    origout.close();
    remove("temp.dat");
    cout << "Patient record deleted successfully.\n";
}

void updatePatient(string fileName, int id)
{
    fstream file(fileName, ios::binary | ios::in | ios::out);
    Patient p;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Patient)))
    {
        if (p.getId() == id)
        {
            found = true;
            string name, cnic, phoneNumber, disease;
            bool isAdmitted;
            cout << "Enter new Patient Name: ";
            cin.ignore();
            getline(cin, name);
            p.setName(name);
            cout << "Enter new Patient CNIC: ";
            getline(cin, cnic);
            p.setCnic(cnic);
            cout << "Enter new Patient Phone Number: ";
            getline(cin, phoneNumber);
            p.setPhoneNumber(phoneNumber);
            cout << "Enter new Patient Disease: ";
            getline(cin, disease);
            p.setDisease(disease);
            cout << "Is Patient Admitted (1 for Yes, 0 for No): ";
            cin >> isAdmitted;
            p.setIsAdmitted(isAdmitted);
            file.seekp(-static_cast<int>(sizeof(Patient)), ios::cur);
            file.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
            break;
        }
    }
    file.close();
    if (found)
    {
        cout << "Patient record updated successfully.\n";
    } else
    {
        cout << "Patient not found.\n";
    }
}

void displayPatient(string fileName, int id)
{
    ifstream file(fileName, ios::binary);
    Patient p;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Patient)))
    {
        if (p.getId() == id)
        {
            found = true;
            cout << "Patient ID: " << p.getId() << endl;
            cout << "Name: " << p.getName() << endl;
            cout << "CNIC: " << p.getCnic() << endl;
            cout << "Phone Number: " << p.getPhoneNumber() << endl;
            cout << "Disease: " << p.getDisease() << endl;
            cout << "Is Admitted: " << (p.getIsAdmitted() ? "Yes" : "No") << endl;
            cout << endl;
            break;
        }
    }
    file.close();
    if (!found)
    {
        cout << "Patient not found.\n";
    }
}