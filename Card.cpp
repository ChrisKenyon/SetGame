#include "stdafx.h"
#include "Card.h"


Card::Card()
{
}

Card::Card(int num, Symbols symbol, Shadings shade, Colors color) :
	_number(num), _symbol(symbol), _shading(shade), _color(color)
{
	if (num < 1 || num > 3)
		throw new argumentException();
}

Card::Card(const Card & other)
{
	if (this == &other)
		return;

	_number = other.getNumber();
	_color = other.getColor();
	_shading = other.getShading();
	_symbol = other.getSymbol();
}

Card::~Card()
{
}

Card::Symbols Card::getSymbol() const { return _symbol; }
Card::Shadings Card::getShading() const { return _shading; }
Card::Colors Card::getColor() const { return _color; }
int Card::getNumber() const { return _number; }

Card& Card::operator=(const Card & rhs)
{
	if (this == &rhs)
		return *this;

	_number = rhs.getNumber();
	_color = rhs.getColor();
	_shading = rhs.getShading();
	_symbol = rhs.getSymbol();
	return *this;
}

string Card::getSymbolString() const
{
	return SymbolStrings[(int)_symbol-1];
}

string Card::getShadingString() const
{
	return ShadingStrings[(int)_shading-1];
}

string Card::getColorString() const
{
	return ColorStrings[(int)_color-1];
}

ostream & operator<<(ostream & cstr, const Card & c)
{
	cstr << "A " << c.getColorString() << " " << c.getShadingString()
		 << " " << c.getSymbolString() << " with the number " << c.getNumber() << endl;
	
	return cstr;
}

