#include "Notebook.h"

int main()
{
    vector<Note> notebook {};

    while (true) 
    {
        string answer;

        printf("| Write new contact |\n\n");
        CreateNote(notebook);

        while (true) 
        {
            printf("Add one more contact? (y/n): ");
            cin >> answer;
            printf("\n");

            if (answer != "y" && answer != "n") 
            {
                printf("Incorrect input!\n\n");
                continue;
            }
            break;
        }

        if(answer == "n") { break; }
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
            printf("Enter the mobile number of the contact(Num must consist of 9 digits): ");
            cin >> stringedNum;

            if (stringedNum.length() != 9) 
            {
                printf("Mobile number must consist of 9 digits!\n");
                continue;
            }
            newNote.mobileNumber = stoi(stringedNum);
            break;
        }
        catch (invalid_argument) 
        {
            printf("Incorrect input!\n\n");
        }
    }

    printf("Enter the name of the contact: ");
    cin >> newNote.name;

    printf("Enter the surname of the contact: ");
    cin >> newNote.surname;

    while(true) 
    {
        string stringedGender;
        int gender;

        try
        {
            printf("Enter the gender of the contact (Male = 0 | Female = 1): ");
            cin >> stringedGender;

            printf("\n");

            gender = stoi(stringedGender);

            if (gender != 0 && gender != 1) 
            {
                printf("Incorrect input!\n\n");
                continue;
            }

            newNote.gender = (Gender)gender;
            break; 
        }

        catch (invalid_argument)
        {
            printf("Incorrect input!\n\n");
        }
    }

    notebook.push_back(newNote);
}

void SearchNotes(vector<Note>& notebook) 
{
    string detail;

    printf("Enter contact detail(Case sensitive): ");
    cin >> detail;

    bool isAtLeastOneFound = false;

    printf("\n");
    printf("List of founded:\n\n");

    int counter = 0;

    for (const Note& note : notebook)
    {
        if (note.name == detail || note.surname == detail) 
        {
            counter++;
            isAtLeastOneFound = true;

            printf("No %i ---------------|\n", counter);
            printf("Name: %s\n", note.name.c_str());
            printf("Surname: %s\n", note.surname.c_str());
            printf("Mobile number: %i\n", note.mobileNumber);
            printf("Gender: %s\n", (note.gender == Gender::Male) ? "Male" : "Female");
            printf("-------------------|\n");
        }
    }

    if (counter == 0) 
    { 
        printf("-------------------------------------------|\n\n");
        printf("No results found for the search query \"%s\"\n\n", detail.c_str()); 
        printf("-------------------------------------------|\n");
    }

}