#include "Ship.h"

class Participant
{
public:
	Participant();
	~Participant();

	virtual void makeMove(Position positionToHit) = 0;
	virtual void setAllShips() = 0;

	void takeHit(Position hitPosition);
	
private:
	static const int fieldSize = 10;

	int allyField[fieldSize][fieldSize];
	int enemyField[fieldSize][fieldSize];
	vector<Ship> ownedShips;
};

Participant::Participant() : ownedShips(fieldSize, Ship(ShipType::OneDecked))
{
	ownedShips[0] = Ship(ShipType::FourDecked);
	ownedShips[1] = Ship(ShipType::ThreeDecked);
	ownedShips[2] = Ship(ShipType::ThreeDecked);
	ownedShips[3] = Ship(ShipType::TwoDecked);
	ownedShips[4] = Ship(ShipType::TwoDecked);
	ownedShips[5] = Ship(ShipType::TwoDecked);
}

class Player : Participant 
{
public:
	void makeMove(Position positionToHit);
	void setAllShips();
};

class Enemy : Participant 
{
public:
	void makeMove(Position positionToHit);
	void setAllShips();
};