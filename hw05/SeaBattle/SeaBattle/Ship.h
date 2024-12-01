#include <vector>
#include <iostream>
#include "PositionStructs.h"
#include "DirectionEnums.h"

using namespace std;

enum class ShipType
{
	OneDecked = 1,
	TwoDecked,
	ThreeDecked,
	FourDecked
};

class Ship
{
public:
	Ship(ShipType shipType);
	~Ship();

	bool isHitted(Position hitPosition); 

	//getters
	ShipType				getShipType() { return shipType; }
	bool					getIsShipSunk() { return isSunk; }
	const ShipPartPosition* getAllShipParts() { return allShipParts; }
	
	void setShipPartsPosition(Position startPosition, Direction direction);

private:
	ShipType shipType;
	ShipPartPosition* allShipParts;
	bool isSunk = false;

	void isShipSunk(); 
};
