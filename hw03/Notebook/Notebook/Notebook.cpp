#include "Notebook.h"

int main()
{
    vector<Note> notebook {};
    CreateNote(notebook);


}

void CreateNote(vector<Note>& notebook)
{
    Note newNote;

    while (true)
    {
        string stringedNum;

        try
        {
            printf("Enter the mobile number of the contact (Nums Only): ");
            cin >> stringedNum;

            newNote.mobileNumber = stoi(stringedNum);
            break;
        }
        catch (invalid_argument) 
        {
            printf("Incorrect input!\n");
        }
    }

    printf("Enter the name of the contact (Strings Only): ");
    cin >> newNote.name;

    printf("Enter the surname of the contact (Strings Only): ");
    cin >> newNote.surname;

    while(true) 
    {
        string gender;
        printf("Enter the gender of the contact (Male/Famale): ");

        cin >> gender;

        if (gender == "Male" || gender == "Female") { break; }
        else { printf("Incorrect input!\n"); }
    }

    notebook.push_back(newNote);
}

Note& SearchNote(vector<Note>& notebook) 
{

}