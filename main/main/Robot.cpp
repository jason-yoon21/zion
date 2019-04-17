#include "pch.h"
#include "Robot.h"
#include <cstdlib>
#include <ostream>
#include "Arena.h"
#include "globals.h"
#include <iostream>


///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////

Robot::Robot(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		std::cout << "***** A robot must be in some Arena!" << std::endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		std::cout << "***** Robot created with invalid coordinates (" << r << ","
			<< c << ")!" << std::endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
}

int Robot::row() const
{
	return m_row;
}

int Robot::col() const
{
	//#TODO: TRIVIAL:  Return what column the robot is at.
	// Delete the following line and replace it with the correct code.
	return m_col; // This implementation compiles, but is incorrect.
}

void Robot::move()
{
	// Attempt to move in a random direction; if we can't move, don't move
	switch (rand() % 4)
	{
	case UP:
		//#TODO:  Move the robot up one row if possible.
		m_row++;
		break;
	case DOWN:
	case LEFT:
	case RIGHT:
		//#TODO:  Implement the other movements.
		m_col++;
		break;
	}
}

bool Robot::takeDamageAndLive()
{
	// TODO:  If the robot has been hit once before, return false (since a
	// second hit kills a robot).  Otherwise, return true (since the robot
	// survived the damage).
	return m_arena->player()->isDead();
}