#pragma once

using namespace std;

class Card
{
public:

	enum Symbols { DIAMOND = 1, SQUIGGLE, OVAL };
	enum Shadings { SOLID = 1, STRIPED, OPEN };
	enum Colors { RED = 1, GREEN, PURPLE};

	Card();
	Card(int count, Symbols symbol, Shadings shade, Colors color);
	Card(const Card& other);
	~Card();

	// getters
	Card::Symbols getSymbol() const;
	Card::Shadings getShading() const;
	Card::Colors getColor() const;
	int getNumber() const;

	// operators
	Card & operator=(const Card & rhs);
	friend ostream &operator<<(ostream &cstr, const Card &c);

private:
	int _number;
	Symbols _symbol;
	Shadings _shading;
	Colors _color;
	
	// string getters
	string getSymbolString() const;
	string getShadingString() const;
	string getColorString() const;
};

static const string SymbolStrings[3]{ "Diamond", "Squiggle", "Oval" };
static const string ShadingStrings[3]{ "Solid", "Striped", "Open" };
static const string ColorStrings[3]{ "Red", "Green", "Purple" };

