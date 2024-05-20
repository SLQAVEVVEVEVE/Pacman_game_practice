#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

const int H = 21;
const int W = 48;

const int ts = 25;

int q = 0;
bool life = true;
//52
String TileMap[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBaAAAAAAAAAAAAAAAAAAAAKBBB",//0
"BBBBBBBBBBBBBBBBBBBBBBaK        aK        aKBBBB",//1
"BBBBBBBBBBBBBBBBBBBBBaK aK aPK aK aPK aK aKBBBBB",//2
"BBBBBBBBBBBBBBBBBBBBaK        aK        aKBBBBBB",//3
"BBBBBBBBBBBBBBBBBBBaK aK aK aPPK aK aK aKBBBBBBB",//4
"BBBBBBBBBBBBBBBBBBaK aK     aK     aK aKBBBBBBBB",//5
"BBBBBBBBBBBBBBBBBaAAAK aPK aK aPK aAAAKBBBBBBBBB",//6
"BBBBBBBBBBBBBBBBBBBaK aPK    aPK aKBBBBBBBBBBBBB",//7
"BBBBBBBBBBBBBBBaAAAK aPK aK aPK aAAAKBBBBBBBBBBB",//8
"BBBBBBBBBBBBBBBBB   aK      aK   BBBBBBBBBBBBBBB",//9
"BBBBBBBBBBBBBaAAAK aK aAAK aK aAAAKBBBBBBBBBBBBB",//10
"BBBBBBBBBBBBBBBaK aK      aK aKBBBBBBBBBBBBBBBBB",//11
"BBBBBBBBBBBaAAAK aK aPPK aK aAAAKBBBBBBBBBBBBBBB",//12
"BBBBBBBBBBaK        aK        aKBBBBBBBBBBBBBBBB",//13
"BBBBBBBBBaK aK aPK aK aPK aK aKBBBBBBBBBBBBBBBBB",//14
"BBBBBBBBaK    aK  aK  aK    aKBBBBBBBBBBBBBBBBBB",//15
"BBBBBBBaK aK aK aPPK aK aK aKBBBBBBBBBBBBBBBBBBB",//16
"BBBBBBaK    aK  aK  aK    aKBBBBBBBBBBBBBBBBBBBB",//17
"BBBBBaK aPPPPK aK aPPPPK aKBBBBBBBBBBBBBBBBBBBBB",//18
"BBBBaK                  aKBBBBBBBBBBBBBBBBBBBBBB",//19
"BBBaAAAAAAAAAAAAAAAAAAAAKBBBBBBBBBBBBBBBBBBBBBBBB",//20
};

class Player {
public:
	float frame = 0;
	int x = 22, y = 9;
	int newx = 25, newy = 9;
	int rotate = 1, ti = 0;

	void update() {
		frame += 0.01;
		if (frame > 5)
			frame -= 5;

		ti++;
		if (ti >= 1500) {
			switch (rotate)
			{
			case 1:
				if (TileMap[y][newx + 1] != 'A'&& TileMap[y][newx + 1] != 'K' && TileMap[y][newx + 1] != 'P'
					&& TileMap[y][newx + 1] != 'a')
					newx += 1;
				break;
			case 2:
				if (TileMap[y][newx - 1] != 'A' && TileMap[y][newx - 1] != 'K' && TileMap[y][newx - 1] != 'P' 
					&& TileMap[y][newx - 1] != 'a')
					newx -= 1;
				break;
			case 3:
				if (TileMap[newy - 1][x+1] != 'A' && TileMap[newy - 1][x+1] != 'K' && TileMap[newy - 1][x+1] != 'P'
					&& TileMap[newy - 1][x+1] != 'a')
				{
					newy -= 1;
					newx += 1;
				}
				break;
			case 4:
				if (TileMap[newy + 1][x-1] != 'A' && TileMap[newy + 1][x-1] != 'K' && TileMap[newy + 1][x-1] != 'P' 
					&& TileMap[newy + 1][x-1] != 'a')
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

		if (newy == 9 && (newx == 13 || newx == 35)) {
			if (newx == 13)
				newx = 34;
			else
				newx = 14;

			TileMap[y][x] = 'B';
			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}
	}
};

class Enemy {
public:
	int x[4] = { 1, 17 , 1, 17 }, y[4] = { 1, 1, 19, 19 };
	int newx[4] = { 0 , 0 , 0, 0 }, newy[4] = { 0, 0, 0, 0 };
	int rotate[4] = { 1, 1, 1, 1 }, ti = 0;

	void update() {
		ti++;

		if (ti >= 1500) {
			for (int i = 0; i < 4; i++) {
				rotate[i] = rand() % 4 + 1;

				newx[i] = x[i];
				newy[i] = y[i];

				switch (rotate[i])
				{
				case 1:
					if (TileMap[y[i]][newx[i] + 1] != 'A')
						newx[i] += 1;
					break;
				case 2:
					if (TileMap[y[i]][newx[i] - 1] != 'A')
						newx[i] -= 1;
					break;
				case 3:
					if (TileMap[newy[i] - 1][x[i]] != 'A')
						newy[i] -= 1;
					break;
				case 4:
					if (TileMap[newy[i] + 1][x[i]] != 'A')
						newy[i] += 1;
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

			if (newy[i] == 9 && (newx[i] == 0 || newx[i] == 18)) {
				if (newx[i] == 0)
					newx[i] = 17;
				else
					newx[i] = 1;

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
	t.loadFromFile("source/title_2.png");
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

			if (q < 171 && life)
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

		if (q < 171 && life) {
			p.update();
			//en.update();
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
				if (TileMap[i][j] == 'C')
					plat.setTextureRect(IntRect(ts * (int(p.frame)), ts * (p.rotate+1), ts, ts));
				if (TileMap[i][j] == ' ')
					plat.setTextureRect(IntRect(2*ts, 0, ts, ts));
				/*if (TileMap[i][j] == '1')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[0], ts, ts));
				if (TileMap[i][j] == '2')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[1], ts, ts));
				if (TileMap[i][j] == '3')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[2], ts, ts));
				if (TileMap[i][j] == '4')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[3], ts, ts));*/
				if (TileMap[i][j] == 'B')
					continue;

				plat.setPosition(j * ts, i * ts);
				window.draw(plat);
			}

		if (q == 171)
			window.draw(youwin);
		if (!life)
			window.draw(youlose);

		window.display();
	}

	return 0;
}