#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

const int H = 24;
const int W = 60;

const int ts = 25;

int q = 0;
bool life = true;

String TileMap[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBBaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMBB",//0
"BBBBBBBBBBBBBBBBBBBBBBBaM______________+M______________+M-BB",//1
"BBBBBBBBBBBBBBBBBBBBBBaM-             aM-             aM-BBB",//2
"BBBBBBBBBBBBBBBBBBBBBaM- aPPM0 aPPM0 aM- aPPM0 aPPM0 aM-BBBB",//3
"BBBBBBBBBBBBBBBBBBBBaM- aPPM- aPPM- aM- aPPM- aPPM- aM-BBBBB",//4
"BBBBBBBBBBBBBBBBBBBaM- 0___- 0___- aM- 0___- 0___- aM-BBBBBB",//5
"BBBBBBBBBBBBBBBBBBaM-             aM-             aM-BBBBBBB",//6
"BBBBBBBBBBBBBBBBBaM- aPPM0 aPPM0 aM- aPPM0 aPPM0 aM-BBBBBBBB",//7
"BBBBBBBBBBBBBBBBaM- 0___- 0___- aM- 0___- 0___- aM-BBBBBBBBB",//8
"BBBBBBBBBBBBBBBaM-             aM-             aM-BBBBBBBBBB",//9
"BBBBBBBBBBBBBBaAAPM0 aPPPPPPPPPPPPPPPPPPPM0 aPPM-BBBBBBBBBBB",//10
"BBBBBBBBBBBBB0__+M- 0____________________- aM__-BBBBBBBBBBBB",//11
"BBBBBBBBBBBBaAAAM-                        aAAAMBBBBBBBBBBBBB",//12
"BBBBBBBBBBB0____- aPPPPPPPPPPPPPPPPPPPM0 0____-BBBBBBBBBBBBB",//13
"BBBBBBBBBBBBBBBB 0____________________- BBBBBBBBBBBBBBBBBBBB",//14
"BBBBBBBBBaAAAM0                        aAAAM0BBBBBBBBBBBBBBB",//15
"BBBBBBBBB__+M- aPPPPPPPPPPPPPPPPPPPM0 aM___-BBBBBBBBBBBBBBBB",//16
"BBBBBBBBBBaM- 0________+M__________- aM-BBBBBBBBBBBBBBBBBBBB",//17
"BBBBBBBBBaM-          aM-           aM-BBBBBBBBBBBBBBBBBBBBB",//18
"BBBBBBBBaM- aPPPPPM0 aM- aPPPPPPM0 aM-BBBBBBBBBBBBBBBBBBBBBB",//19
"BBBBBBBaM- 0______- aM- 0_______- aM-BBBBBBBBBBBBBBBBBBBBBBB",//20
"BBBBBBaM-          aM-           aM-BBBBBBBBBBBBBBBBBBBBBBBB",//21
"BBBBBaAAAAAAAAAAAAAAAAAAAAAAAAAAAM-BBBBBBBBBBBBBBBBBBBBBBBBB",//22
"BBBB0____________________________-BBBBBBBBBBBBBBBBBBBBBBBBBB",//23
};

//String TileMap[H] = {
//"BBBBBBBBBBBBBBBBBBBBBBBaAAAAAAAAAAAAAAAAAAAAKBBB",//0
//"BBBBBBBBBBBBBBBBBBBBBBaK        aK        aKBBBB",//1
//"BBBBBBBBBBBBBBBBBBBBBaK aK aPK aK aPK aK aKBBBBB",//2
//"BBBBBBBBBBBBBBBBBBBBaK        aK        aKBBBBBB",//3
//"BBBBBBBBBBBBBBBBBBBaK aK aK aPPK aK aK aKBBBBBBB",//4
//"BBBBBBBBBBBBBBBBBBaK aK     aK     aK aKBBBBBBBB",//5
//"BBBBBBBBBBBBBBBBBaAAAK aPK aK aPK aAAAKBBBBBBBBB",//6
//"BBBBBBBBBBBBBBBBBBBaK aPK    aPK aKBBBBBBBBBBBBB",//7
//"BBBBBBBBBBBBBBBaAAAK aPK aK aPK aAAAKBBBBBBBBBBB",//8
//"BBBBBBBBBBBBBBBBB   aK      aK   BBBBBBBBBBBBBBB",//9
//"BBBBBBBBBBBBBaAAAK aK aAAK aK aAAAKBBBBBBBBBBBBB",//10
//"BBBBBBBBBBBBBBBaK aK      aK aKBBBBBBBBBBBBBBBBB",//11
//"BBBBBBBBBBBaAAAK aK aPPK aK aAAAKBBBBBBBBBBBBBBB",//12
//"BBBBBBBBBBaK        aK        aKBBBBBBBBBBBBBBBB",//13
//"BBBBBBBBBaK aK aPK aK aPK aK aKBBBBBBBBBBBBBBBBB",//14
//"BBBBBBBBaK    aK  aK  aK    aKBBBBBBBBBBBBBBBBBB",//15
//"BBBBBBBaK aK aK aPPK aK aK aKBBBBBBBBBBBBBBBBBBB",//16
//"BBBBBBaK    aK  aK  aK    aKBBBBBBBBBBBBBBBBBBBB",//17
//"BBBBBaK aPPPPK aK aPPPPK aKBBBBBBBBBBBBBBBBBBBBB",//18
//"BBBBaK                  aKBBBBBBBBBBBBBBBBBBBBBB",//19
//"BBBaAAAAAAAAAAAAAAAAAAAAKBBBBBBBBBBBBBBBBBBBBBBBB",//20
//};

class Player {
public:
	float frame = 0;
	int x = 22, y = 9;
	int newx = 32, newy = 12;
	int rotate = 1, ti = 0;

	void update() {
		frame += 0.01;
		if (frame > 5)
			frame -= 5;

		ti++;
		if (ti >= 500) {
			switch (rotate)
			{
			case 1:
				if (TileMap[y][newx + 1] != 'A'&& TileMap[y][newx + 1] != 'K' && TileMap[y][newx + 1] != 'P'
					&& TileMap[y][newx + 1] != 'a' && TileMap[y][newx + 1] != '0' && TileMap[y][newx + 1] != '_'
					&& TileMap[y][newx + 1] != '-' && TileMap[y][newx + 1] != 'M')
					newx += 1;
				break;
			case 2:
				if (TileMap[y][newx - 1] != 'A' && TileMap[y][newx - 1] != 'K' && TileMap[y][newx - 1] != 'P' 
					&& TileMap[y][newx - 1] != 'a' && TileMap[y][newx - 1] != '0' && TileMap[y][newx - 1] != '_'
					&& TileMap[y][newx - 1] != '-' && TileMap[y][newx - 1] != 'M')
					newx -= 1;
				break;
			case 3:
				if (TileMap[newy - 1][x+1] != 'A' && TileMap[newy - 1][x+1] != 'K' && TileMap[newy - 1][x+1] != 'P'
					&& TileMap[newy - 1][x+1] != 'a' && TileMap[newy - 1][x + 1] != '0' && TileMap[newy - 1][x + 1] != '_'
					&& TileMap[newy - 1][x + 1] != '-' && TileMap[newy - 1][x + 1] != 'M')
				{
					newy -= 1;
					newx += 1;
				}
				break;
			case 4:
				if (TileMap[newy + 1][x-1] != 'A' && TileMap[newy + 1][x-1] != 'K' && TileMap[newy + 1][x-1] != 'P' 
					&& TileMap[newy + 1][x-1] != 'a' && TileMap[newy + 1][x - 1] != '0' && TileMap[newy + 1][x - 1] != '_'
					&& TileMap[newy + 1][x - 1] != '-' && TileMap[newy + 1][x - 1] != 'M')
				{
					newy += 1;
					newx -= 1;
				}
				break;
			}

			ti = 0;
		}

		if (TileMap[newy][newx] == ' ' || TileMap[newy][newx] == 'B') {
			if (TileMap[newy][newx] == ' ')
				q++;

			if (TileMap[newy][newx] == '1'
				|| TileMap[newy][newx] == '2' || TileMap[newy][newx] == '3' || TileMap[newy][newx] == '4')
				life = false;

			TileMap[y][x] = 'B';

			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}

		if (newy == 14 && (newx == 10 || newx == 45)) {
			if (newx == 10)
				newx = 44;
			else
				newx = 11;

			TileMap[y][x] = 'B';

			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}
	}
};

class Enemy {
public:
	int x[4] = { 26 , 53 , 10, 32 }, y[4] = { 2, 2, 21, 21 };
	int newx[4] = { 26 , 53 , 10, 32 }, newy[4] = { 2, 2, 21, 21 };
	int rotate[4] = { 1, 1, 1, 1 }, ti = 0;

	void update() {
		ti++;

		if (ti >= 500) {
			for (int i = 0; i < 4; i++) {
				rotate[i] = rand() % 4 + 1;

				newx[i] = x[i];
				newy[i] = y[i];

				switch (rotate[i])
				{
				case 1:
					if (TileMap[y[i]][newx[i] + 1] != 'A'&& TileMap[y[i]][newx[i] + 1] != 'a' && TileMap[y[i]][newx[i] + 1] != '_'
						&& TileMap[y[i]][newx[i] + 1] != '0' && TileMap[y[i]][newx[i] + 1] != 'K' && TileMap[y[i]][newx[i] + 1] != 'P'
						&& TileMap[y[i]][newx[i] + 1] != 'M' && TileMap[y[i]][newx[i] + 1] != '-')
						newx[i] += 1;
					break;
				case 2:
					if (TileMap[y[i]][newx[i] - 1] != 'A' && TileMap[y[i]][newx[i] - 1] != 'a' && TileMap[y[i]][newx[i] - 1] != '_'
						&& TileMap[y[i]][newx[i] - 1] != '0' && TileMap[y[i]][newx[i] - 1] != 'K' && TileMap[y[i]][newx[i] - 1] != 'P'
						&& TileMap[y[i]][newx[i] - 1] != 'M' && TileMap[y[i]][newx[i] - 1] != '-')
						newx[i] -= 1;
					break;
				case 3:
					if (TileMap[newy[i] - 1][x[i]+1] != 'A' && TileMap[newy[i] - 1][x[i]+1] != 'a' && TileMap[newy[i] - 1][x[i]+1] != '_'
						&& TileMap[newy[i] - 1][x[i]+1] != '0' && TileMap[newy[i] - 1][x[i]+1] != 'K' && TileMap[newy[i] - 1][x[i]+1] != 'P'
						&& TileMap[newy[i] - 1][x[i]+1] != 'M' && TileMap[newy[i] - 1][x[i]+1] != '-')
					{
						newy[i] -= 1;
						newx[i] += 1;
					}
					break;
				case 4:
					if (TileMap[newy[i] + 1][x[i]-1] != 'A' && TileMap[newy[i] + 1][x[i]-1] != 'a' && TileMap[newy[i] + 1][x[i]-1] != '_'
						&& TileMap[newy[i] + 1][x[i]-1] != '0' && TileMap[newy[i] + 1][x[i]-1] != 'K' && TileMap[newy[i] + 1][x[i]-1] != 'P'
						&& TileMap[newy[i] + 1][x[i]-1] != 'M' && TileMap[newy[i] + 1][x[i]-1] != '-')
					{
						newy[i] += 1;
						newx[i] -= 1;
					}
					break;
				}
			}

			ti = 0;
		}
		//Kurwa bober
		for (int i = 0; i < 4; i++) {
			if (TileMap[newy[i]][newx[i]] == ' ' || TileMap[newy[i]][newx[i]] == 'B' ||
				TileMap[newy[i]][newx[i]] == 'C') {
				if (TileMap[newy[i]][newx[i]] == 'B')
					TileMap[y[i]][x[i]] = 'B';
				else if (TileMap[newy[i]][newx[i]] == ' ')
					TileMap[y[i]][x[i]] = ' ';
				else if (TileMap[newy[i]][newx[i]] == 'C')
					life = false;

				if (i == 0)
					TileMap[newy[i]][newx[i]] = '1';
				if (i == 1)
					TileMap[newy[i]][newx[i]] = '2';
				if (i == 2)
					TileMap[newy[i]][newx[i]] = '3';
				if (i == 3)
					TileMap[newy[i]][newx[i]] = '4';

				x[i] = newx[i];
				y[i] = newy[i];
			}

			if (newy[i] == 14 && (newx[i] == 10 || newx[i] == 45)) {
				if (newx[i] == 10)
					newx[i] = 44;
				else
					newx[i] = 11;

				TileMap[y[i]][x[i]] = 'B';

				if (i == 0)
					TileMap[newy[i]][newx[i]] = '1';
				if (i == 1)
					TileMap[newy[i]][newx[i]] = '2';
				if (i == 2)
					TileMap[newy[i]][newx[i]] = '3';
				if (i == 3)
					TileMap[newy[i]][newx[i]] = '4';

				x[i] = newx[i];
				y[i] = newy[i];
			}
		}
	}
};

int main() {
	srand(time(0));
	RenderWindow window(VideoMode(W * ts, H * ts), "Maze!");

	Texture t;
	t.loadFromFile("source/title_2_3.png");
	Sprite plat(t);

	Texture yw;
	yw.loadFromFile("source/youwin.png");
	Sprite youwin(yw);
	youwin.setPosition(100, 210);

	Texture yl;
	yl.loadFromFile("source/youlose.png");
	Sprite youlose(yl);
	youlose.setPosition(100, 210);

	Player p;
	Enemy en;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (q < 218 && life)
				if (event.type == Event::KeyPressed) {
					p.newx = p.x;
					p.newy = p.y;

					if (event.key.code == Keyboard::Right)
						p.rotate = 1;
					if (event.key.code == Keyboard::Left)
						p.rotate = 2;
					if (event.key.code == Keyboard::Up)
						p.rotate = 3;
					if (event.key.code == Keyboard::Down)
						p.rotate = 4;
				}
		}

		if (q < 218 && life) {
			p.update();
			en.update();
		}
		window.clear(Color::Black);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'P')
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'A')
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				if (TileMap[i][j] == 'a')
					plat.setTextureRect(IntRect(ts, ts, ts, ts));
				if (TileMap[i][j] == 'K')
					plat.setTextureRect(IntRect(0, ts, ts, ts));
				if (TileMap[i][j] == 'M')
					plat.setTextureRect(IntRect(5*ts, ts, ts, ts));
				if (TileMap[i][j] == 'C')
					plat.setTextureRect(IntRect(ts * (int(p.frame)), ts * (p.rotate+1), ts, ts));
				if (TileMap[i][j] == ' ')
					plat.setTextureRect(IntRect(2*ts, 0, ts, ts));
				if (TileMap[i][j] == '_')//np
					plat.setTextureRect(IntRect(3 * ts, ts, ts, ts));
				if (TileMap[i][j] == '-')//MINUS
					plat.setTextureRect(IntRect(4* ts, 1*ts, ts, ts));
				if (TileMap[i][j] == '+')//PLUS
					plat.setTextureRect(IntRect(4 * ts, 0 * ts, ts, ts));
				if (TileMap[i][j] == '0')
					plat.setTextureRect(IntRect(3*ts,0*ts, ts, ts));
				if (TileMap[i][j] == '1')
					plat.setTextureRect(IntRect(ts * 5, ts * (en.rotate[0]+1), ts, ts));
				if (TileMap[i][j] == '2')
					plat.setTextureRect(IntRect(ts * 5, ts * (en.rotate[1]+1), ts, ts));
				if (TileMap[i][j] == '3')
					plat.setTextureRect(IntRect(ts * 5, ts * (en.rotate[2]+1), ts, ts));
				if (TileMap[i][j] == '4')
					plat.setTextureRect(IntRect(ts * 5, ts * (en.rotate[3]+1), ts, ts));
				if (TileMap[i][j] == 'B')
					continue;

				plat.setPosition(j * ts, i * ts);
				window.draw(plat);
			}

		if (q == 218)
			window.draw(youwin);
		if (!life)
			window.draw(youlose);

		window.display();
	}

	return 0;
}