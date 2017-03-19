#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp>
#include<Windows.h>

using namespace sf;
RenderWindow window(VideoMode(984, 600, 32), "Math");
Texture im;
Sprite s;
Event event;
Font font;
char *ch = (char*)malloc(sizeof(char));
RectangleShape box;
Text numb;
RectangleShape mox;
String slovo(char ch[])
{
	String lol(ch, std::locale("rus"));
	return lol;
}
Text ESC(slovo("Для возврата нажмите клавишу ESC"), font, 23);
void Help()
{
	Text tt("1000", font, 10);
	tt.setPosition(892, 95);
	Text tex(slovo("Программа раскладывает число x на простые множители,\n\nгде x — натуральное число, которое больше 1 и меньше 10  .\n\nПрограмма находит простые множители и выводит их\n\nна экран."), font, 27);
	tex.setPosition(30, 30);
	while (!(Keyboard::isKeyPressed(Keyboard::Escape)))
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				exit(0);
		}
		window.draw(s);
		window.draw(mox);
		window.draw(tex);
		window.draw(tt);
		window.draw(ESC);
		window.display();
	}
}
void math(int asd)
{
	Text text;
	Text t(slovo("Пожалуйста, подождите, пока программа найдет простые множители"), font, 22);
	Text ex(slovo("Чтобы прервать программу нажмите на крестик"), font, 20);
	ex.setPosition(155,460);
	text.setFillColor(Color(0, 0, 0, 150));
	text.setFillColor(Color::Blue);
	t.setPosition(Vector2f(50, 50));
	t.setFillColor(Color(0, 0, 0, 200));
	window.draw(s);
	window.draw(box);
	window.display();
	window.draw(s);
	window.draw(box);
	window.draw(numb);
	window.draw(t);
	window.draw(ex);
	window.display();
	text.setCharacterSize(15);
	text.setPosition(150, 200);
	int as = 0, zxc = 0;
	text.setFont(font);
	char *sh = (char*)malloc(sizeof(char));
	char cq[1000]; char qh[1000];
	int i, x, k, a, m , w, mi, b; bool l, p;
	strcpy(cq, ch);
	mi = m = asd;
	k = 1;
	sh[0] = '1';
	if (ch[m - 1] % 2 == 0)
		sh[0] = '0';
	else
		sh[0] = '1';
	do
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				return;
		}
		sh[k - 1] += 2;
		b = 1;
		while (sh[k - b] >= 58)
		{
			if (k == b)
			{
				k++;
				sh = (char*)realloc(sh, k*sizeof(char));
				for (i = k - 1; i>0; i--)
				{
					sh[i] = sh[i - 1];
				}
				sh[0] = 48;
			}
			sh[k - b] -= 10;
			sh[k - b - 1]++;
			b++;
		}
		sh[k] = 0;
		do
		{
			p = 1; x = 0; w = 0;
			do
			{
				l = 0; a = 0; i = 0;
				while ((ch[i] == sh[i]) && (i<k))
					i++;
				if (ch[i]<sh[i])
				{
					if (p == 0)
					{
						qh[w] = x + 48;
						w++;
						x = 0;
					}
					p = 1;
					for (i = 0; i<k; i++)
					{
						if (ch[k - i]<(sh[k - 1 - i] + l))
						{
							ch[k - i] = ch[k - i] - sh[k - i - 1] + 58 - l;
							l = 1;
						}
						else
						{
							ch[k - i] = ch[k - i] - sh[k - i - 1] + 48 - l;
							l = 0;
						}
					}
					ch[k - i] -= l;
				}
				else
				{
					p = 0;
					for (i = 1; i <= k; i++)
					{
						if (ch[k - i]<(sh[k - i] + l))
						{
							ch[k - i] = ch[k - i] - sh[k - i] + 58 - l;
							l = 1;
						}
						else
						{
							ch[k - i] = ch[k - i] - sh[k - i] + 48 - l;
							l = 0;
						}
					}
				}
				x++;
				while (ch[0] == 48)
				{
					if ((p == 0) && (m >= k))
					{
						qh[w] = x + 48;
						w++;
						x = 0;
					}
					p = 0;
					for (i = 0; i<m; i++)
					{
						ch[i] = ch[i + 1];
					}
					ch[i] = 0;
					m--;
				}
				while ((m == k) && (ch[a] == sh[a]) && (a<k))
					a++;
			} while ((m>k) || ((m == k) && (ch[a] >= sh[a])));
			if (x != 0)
			{
				qh[w] = x + 48;
				w++;
			}
			qh[w] = 0;
			if (ch[0] == 0)
			{
				strcpy(ch, qh);
				strcpy(cq, ch);
				window.display();
				while (sh[as])
				{
					text.setPosition((float)(150 + zxc), (float)200);
					text.setString(sh[as]);
					window.draw(text);
					zxc += 9;
					as++;
				}
				zxc += 9;
				window.display();
				as = 0;
				mi = w;
				m = w;
				i = 1;
			}
			else
			{
				strcpy(ch, cq);
				i = 0;
				m = mi;
			}
		} while (i == 1 && (ch[0] != 49 || m != 1));
		if (sh[k - 1] == '2')
			sh[k - 1] = '1';
	} while (ch[0] != 49 || m != 1);
	ex.setCharacterSize(23);
	ex.setString(slovo("Программа нашла все множители для продолжения нажмите ESC"));
	ex.setPosition(60, 350);
	window.display();
	window.draw(ex);
	window.display();
	while (!(Keyboard::isKeyPressed(Keyboard::Escape)))
	{ 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				exit(0);
		}
	}
}
void Start()
{
	ch[0] = 0;
	unsigned char keyboard[256];
	box.setPosition(Vector2f(150, 150));
	box.setSize(Vector2f(684, 200));
	box.setOutlineColor(Color(0, 0, 0, 255));
	box.setFillColor(Color(200, 200, 200, 150));
	int i = 0, l = 0;
	Text suppor(slovo("Введите число"), font, 35);
	suppor.setFillColor(Color(0,0,0,200));
	suppor.setPosition(Vector2f(350, 65));
	numb.setFillColor(Color(0, 0, 0, 150));
	numb.setPosition(Vector2f(150, 150));
	numb.setFont(font);
	numb.setCharacterSize(15);
	s.setTexture(im);
	memset(keyboard, 0, 256);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				exit(0);
		}
		for (int i = 0; i < 256; i++)
		{
			keyboard[i] = (UINT)GetKeyState(i);
			if ((keyboard[i]>>7)==1)
			{
				if (i>47 && i < 58)
				{
					ch = (char*)realloc(ch, (l + 1)*sizeof(char));
					ch[l] = i;
					l++;
					ch[l] = 0;
				}
				keyboard[i] = 0;
				switch (i)
				{
				case 27:
					return;
				case 8:
					if (l)
					{
						l--;
						ch = (char*)realloc(ch, (l + 1)*sizeof(char));
						ch[l] = 0;
					}
					break;
				case 13:
					math(l);
					ch[0] = 0;
					l = 0;
				}
				keyboard[i] = 0;
			}
		}
		numb.setString(ch);
		window.draw(s);
		window.draw(box);
		window.draw(numb);
		window.draw(suppor);
		window.draw(ESC);
		window.display();
		Sleep(135);
	}
}
void About()
{
	Text main(slovo("Программа разработана\nстудентом ТУСУРа\n594-ой группы\nОруспай С.Х.\n\n\n\n\n						   Томск 2015"), font, 40); 
	main.setPosition(50, 50);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				exit(0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return;
		window.draw(s);
		window.draw(mox);
		window.draw(ESC);
		window.draw(main);
		window.display();
	}
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	font.loadFromFile("tt6807m_.ttf");
	mox.setSize(Vector2f(984, 680));
	mox.setFillColor(Color(0, 0, 0, 135));
	ESC.setPosition(235, 530);
	Mouse mouse;
	window.setPosition(Vector2i(100,10));
	RectangleShape box;
	box.setSize(Vector2f(225, 680));
	box.setOutlineColor(Color(0, 128, 128, 150));
	box.setFillColor(Color(0, 0, 0, 50));
	Text help(slovo("Помощь"), font, 40);
	Text start(slovo("Старт"),font, 40);
	Text exit(slovo("Выход"), font, 40);
	Text about(slovo("Автор"), font, 40);
	help.setPosition(30, 320);
	about.setPosition(30, 240);
	exit.setPosition(30, 400);
	start.setPosition(30, 160);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		im.loadFromFile("hp.png");
		s.setTexture(im);
		start.setFillColor(Color(255, 255, 255, 150));
		exit.setFillColor(Color(255, 255, 255, 150));
		about.setFillColor(Color(255, 255, 255, 150));
		help.setFillColor(Color(255, 255, 255, 150));
		if (mouse.getPosition(window).x > 31 && mouse.getPosition(window).x < 185
			&& mouse.getPosition(window).y>169 && mouse.getPosition(window).y < 203)
		{
			start.setFillColor(Color(0, 0, 0, 150));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Start();
			}
		}
		if (mouse.getPosition(window).x>31 && mouse.getPosition(window).x < 168
			&& mouse.getPosition(window).y>409 && mouse.getPosition(window).y < 443)
		{
			exit.setFillColor(Color(0, 0, 0, 150));
			if (Mouse::isButtonPressed(Mouse::Left))
				return 1;
		}
		if (mouse.getPosition(window).x>31 && mouse.getPosition(window).x < 177
			&& mouse.getPosition(window).y>249 && mouse.getPosition(window).y < 283)
		{
			about.setFillColor(Color(0, 0, 0, 150));
			if (Mouse::isButtonPressed(Mouse::Left))
				About();
		}
		if (mouse.getPosition(window).x>31 && mouse.getPosition(window).x < 203
			&& mouse.getPosition(window).y>329 && mouse.getPosition(window).y < 363)
		{
			help.setFillColor(Color(0, 0, 0, 150));
			if (Mouse::isButtonPressed(Mouse::Left))
				Help();
		}

		window.clear();
		window.draw(s);
		window.draw(box);
		window.draw(start);
		window.draw(exit);
		window.draw(help);
		window.draw(about);
		window.display();
	}
	return 0;
}