#include "Ship.h"

Ship::Ship(ShipType shipType)
{
	this->shipType = shipType;
	allShipParts = new ShipPartPosition[(int)shipType];
}

Ship::~Ship()
{
	delete[] allShipParts;
}

void Ship::setShipPartsPosition(Position startPosition, Direction direction)
{
	allShipParts[0].x = startPosition.x;
	allShipParts[0].y = startPosition.y;

	if (shipType != ShipType::OneDecked)
	{
		for (int i = 1; i < (int)shipType; i++)
		{
			if (direction == Direction::horizontal) 
			{ 
				startPosition.x += 1; 
				allShipParts[i].x = startPosition.x;
				allShipParts[i].y = startPosition.y;
			}
			else 
			{ 
				startPosition.y += 1; 
				allShipParts[i].x = startPosition.x;
				allShipParts[i].y = startPosition.y;
			}
		}
	}
}

void Ship::isShipSunk()
{
	for (int i = 0; i < (int)shipType; i++)
	{
		if (!allShipParts[i].isHitted) return;
	}

	isSunk = true;
}

bool Ship::isHitted(Position hitPosition)
{
	for (int i = 0; i < (int)shipType; i++)
	{
		if ((Position)allShipParts[i] == hitPosition)
		{
			isShipSunk();
			return true;
		}
	}

	return false;
}