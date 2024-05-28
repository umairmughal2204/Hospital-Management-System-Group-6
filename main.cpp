#include "Patient.cpp"
int main()
{
    string file_name = "Patient_Record.txt";
    int choice;
    do {
        cout << "\nPatient Database Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Display Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPatient(file_name);
                break;
            case 2:
            {
                int id;
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                deletePatient(file_name, id);
                break;
            }
            case 3:
            {
                int id;
                cout << "Enter Patient ID to update: ";
                cin >> id;
                updatePatient(file_name, id);
                break;
            }
            case 4:
            {
                int id;
                cout << "Enter Patient ID to display: ";
                cin >> id;
                displayPatient(file_name, id);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
