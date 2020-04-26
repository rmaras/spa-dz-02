#include <iostream>
#include <ctime>
#include<string>
/*nije mi uspjela implementacija kroz klase nisam mogao rijesiti problem tako da saljem ovu jednostavnu verziju odradjenu samo pomocu funkcija i maina*/
using namespace std;

const int red = 10;
const int stupac = 35;

bool _sadaGeneracija[red][stupac];
bool NovaGen[red][stupac];

void reset() {
	{
		for (long i = 0; i < red; i++) {
			for (long j = 0; j < stupac; j++) {
				_sadaGeneracija[i][j] = false;
				NovaGen[i][j] = false;
			}
		}

	}
};
void randomX() {
		int percent = 30;
		int max = ((red * stupac) / 100) * percent;
		int now = 0;
		while (now < max) {
			int y = 0 + (rand() % (red + 1));
			int x = 0 + (rand() % (stupac + 1));
			if (_sadaGeneracija[y][x] == false) {
				_sadaGeneracija[y][x] = true;
			}
			else {
				now--;
			}
			++now;
		}
};
void NovaGen_deklaracija() {
	{
		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				NovaGen[i][j] = _sadaGeneracija[i][j];
			}
		}
	}
};
void komšije() {
	{
		int komšo = 0;
		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				if (_sadaGeneracija[i + 1][j + 1] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i + 1][j] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i + 1][j - 1] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i][j - 1] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i][j + 1] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i - 1][j] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i - 1][j + 1] == true) {
					++komšo;
				}
				if (_sadaGeneracija[i - 1][j - 1] == true) {
					++komšo;
				}
				if (NovaGen[i][j] == true && komšo > 3) {
					NovaGen[i][j] = false;
				}
				if (NovaGen[i][j] == false && komšo == 3) {
					NovaGen[i][j] = true;
				}
				if (NovaGen[i][j] == true && komšo == 3) {
					NovaGen[i][j] = true;
				}
				if (NovaGen[i][j] == true && komšo < 2) {
					NovaGen[i][j] = false;
				}
				if (NovaGen[i][j] == true && komšo == 2) {
					NovaGen[i][j] = true;
				}
				komšo = false;
			}
		}
	}
};
void updateX() {
	{
		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				_sadaGeneracija[i][j] = NovaGen[i][j];
			}
		}
	}
};
void ispis() {
	{
		system("CLS");
		using namespace std;
		char live = 'o';
		char dead = '.';
		for (int i = red; i > 0; i--) {
			cout << endl;
			for (long j = stupac; j > 0; j--) {
				if (i != 0 && i != red) {
					if (_sadaGeneracija[i][j]) {
						cout << live;
					}
					else {
						cout << dead;
					}
					cout << " ";
				}
			}
		}
	}
};

int main()
{
	using namespace std;
	srand((unsigned)time(NULL));
	int brojac = 0;
	int generation = 0;
	reset();
	randomX();
	NovaGen_deklaracija();
	bool running = true;
	while (running) {
		if (brojac == 1000000) {

			ispis();
			komšije();
			updateX();
			++generation;
			brojac = 0;
		}
	++brojac;
	}
	return 0;
}