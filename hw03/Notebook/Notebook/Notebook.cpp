#include "Notebook.h"

int main()
{
    vector<Note> notebook {};

    while (true) 
    {
        string answer;

        printf("Write new contact\n");
        CreateNote(notebook);

        printf("Add one more contact? (y/n): ");
        cin >> answer;
        if (answer == "y") { continue; }
        else if (answer == "n") { break; }
    }

    SearchNotes(notebook);
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

void SearchNotes(vector<Note>& notebook) 
{
    string detail;

    printf("Enter contact detail: ");
    cin >> detail;

    bool isAtLeastOneFound = false;

    printf("List of founded: ");

    for (const Note& note : notebook)
    {
        int counter = 0;
        if (to_string(note.mobileNumber) == detail || note.name == detail || note.surname == detail) 
        {
            counter++;
            isAtLeastOneFound = true;
            printf("%i---------------", counter);
            printf("Name: %s\n", note.name);
            printf("Surname: %s\n", note.surname);
            printf("Mobile number: %i\n", note.mobileNumber);
            printf("Gender: %s\n", (note.gender == Gender::Male) ? "Male" : "Female");
            printf("----------------");
        }
    }
}