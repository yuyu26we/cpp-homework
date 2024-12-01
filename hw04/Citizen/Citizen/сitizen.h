#include <iostream>
#include <string>

using namespace std;

//enums
enum class Gender 
{ 
	Male, Female 
};

enum class VisaType 
{
	TouristVisa, 
	BusinessVisa, 
	StudentVisa, 
	WorkVisa, 
	TransitVisa, 
	VisitorVisa
};

enum class Country 
{
	//—писок всех стран
};

//structs
struct Date
{
	int day;
	int month;
	int year;
};

struct Passport 
{
	int PINFL;
	string name;
	string surName;
	Gender gender;
	Date birthDate;
	Country citizenship;
};

struct Visa
{
	VisaType visaType;
	Date dateOfExpire;
	int lengthOfStayInDays;
};

//classes
class Citizen 
{
private:
	Passport passport;
	string uid;

	//—оздает уникальный ид, к примеру, использу€ данные из паспорта
	string getUnicId();

	//выбрасывает исключение, если данные невалидные
	Passport isInfoValid(int PINFL, Date birthDate, Country citizenship);

public:
	Citizen(int PINFL, string name, string surName, Gender gender, Date birthDate, Country citizenship)
	{
		isInfoValid(PINFL, birthDate, citizenship);

		passport.PINFL = PINFL;
		passport.name = name;
		passport.surName = surName;
		passport.gender = gender;
		passport.birthDate = birthDate;
		passport.citizenship = citizenship;
		uid = getUnicId();
	}

	//getters
	Passport getPassport() { return passport; }
	string getUid() { return uid; }

	//setters
	void setPassportPINFL(int PINFL) {
		isInfoValid(PINFL, passport.birthDate, passport.citizenship);
		passport.PINFL = PINFL;
	}
	void setPassportDate(Date birthDate) {
		isInfoValid(passport.PINFL, birthDate, passport.citizenship);
		passport.birthDate = birthDate;
	}
	void setPassportCitizenship(Country citizenship) {
		isInfoValid(passport.PINFL, passport.birthDate, citizenship);
		passport.citizenship = citizenship;
	}
	void setPassportName(const std::string& name) {
		passport.name = name;
	}
	void setPassportSurName(const std::string& surName) {
		passport.surName = surName;
	}
	void setPassportGender(Gender gender) {
		passport.gender = gender;
	}

	//methods
	virtual void getCitizenInfo() = 0;
	virtual bool isCitizenSuspect() = 0;
};

class ForeignCitizen : public Citizen 
{
private:
	Visa visa;

public:
	ForeignCitizen(int PINFL, string name, string surName, Gender gender, Date birthDate, Country citizenship,
		VisaType visaType, Date dateOfExpire, int lengthOfStayInDays) :
		Citizen(PINFL, name, surName, gender, birthDate, citizenship)
	{
		visa.visaType = visaType;
		visa.dateOfExpire = dateOfExpire;
		visa.lengthOfStayInDays = lengthOfStayInDays;
	}

	//getters
	Visa getVisa() { return visa; }

	//setters
	void setVisa(VisaType visaType) {
		visa.visaType = visaType;
	}
	void setVisaDateOfExpire(Date dateOfExpire) {
		visa.dateOfExpire = dateOfExpire;
	}
	void setVisaLengthOfStayInDays(int lengthOfStayInDays) {
		visa.lengthOfStayInDays = lengthOfStayInDays;
	}

	void showCitizenInfo();
	bool isCitizenSuspect();
};

class LocalCitizen : public Citizen
{
public:
	LocalCitizen(int PINFL, string name, string surName, Gender gender, Date birthDate, Country citizenship) :
		Citizen(PINFL, name, surName, gender, birthDate, citizenship) {}

	void showCitizenInfo();
	bool isCitizenSuspect();
};
