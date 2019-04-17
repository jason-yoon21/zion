#include "pch.h"
#include "Player.h"
#include "globals.h"
#include <iostream>
#include "Arena.h"


///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		std::cout << "***** The player must be in some Arena!" << std::endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		std::cout << "**** Player created with invalid coordinates (" << r
			<< "," << c << ")!" << std::endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

int Player::row() const
{
	//#TODO: TRIVIAL:  Return what row the player is at.
	// Delete the following line and replace it with the correct code.
	return m_row; // This implementation compiles, but is incorrect.
}

int Player::col() const
{
	//#TODO: TRIVIAL:  Return what column the player is at.
	// Delete the following line and replace it with the correct code.
	return m_col; // This implementation compiles, but is incorrect.
}

int Player::age() const
{
	//#TODO:  TRIVIAL:  Return the player's age.
	// Delete the following line and replace it with the correct code.
	return m_age; // This implementation compiles, but is incorrect.
}

std::string Player::takeComputerChosenTurn()
{
	// TODO:  Replace this implementation:
	stand();
	return "Stood";
	// Your replacement implementation should do something intelligent
	// and return a string that describes what happened.  When you've
	// decided what action to take, take it by calling move, shoot, or stand.
	// This function must return one of the following four strings:
	//     "Moved."
	//     "Shot and hit!"
	//     "Shot and missed!"
	//     "Stood."

	// Here's one possible strategy:
	//   If moving in some direction would put me in less immediate danger
	//     than standing, then move in that direction.
	//   else shoot in the direction of the nearest robot I can hit.

	// A more aggressive strategy is possible, where you hunt down robots.
}

void Player::stand()
{
	m_age++;
}

void Player::move(int dir)
{
	m_age++;
	switch (dir)
	{
	case UP:
		//#TODO:  Move the player up one row if possible.
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

bool Player::shoot(int dir)
{
	m_age++;

	if (rand() % 3 == 0) // miss with 1/3 probability
		return false;

	// TODO:  Damage the nearest robot in direction dir, returning
	// true if a robot is hit and damaged, false if not hit.
	return false; // This implementation compiles, but is incorrect.
}

bool Player::isDead() const
{
	//#TODO:  TRIVIAL:  Return whether the player is dead.

	return m_dead; // This implementation compiles, but is incorrect.
}

void Player::setDead()
{
	m_dead = true;
}
