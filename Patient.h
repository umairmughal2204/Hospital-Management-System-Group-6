#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Patient
{
    
public:
    int getId() const;
    void setId(int id);
    string getName() const;
    void setName(const string& name);
    string getCnic() const;
    void setCnic(const string& cnic);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);
    string getDisease() const;
    void setDisease(const string& disease);
    bool getIsAdmitted() const;
    void setIsAdmitted(bool isAdmitted);
private:
    int Id;
    string name;
    string cnic;
    string phoneNumber;
    string disease;
    bool isAdmitted;
};
#endif
void addPatient(string file_name);
void deletePatient(string file_name, int id);
void updatePatient(string file_name, int id);
void displayPatient(string file_name, int id);


