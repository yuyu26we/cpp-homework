#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Gender
{
	Male,
	Female
};

struct Note
{
	int mobileNumber;
	string name;
	string surname;
	Gender gender;
};

void CreateNote(vector<Note>& notebook);
void SearchNotes(vector<Note>& notebook);