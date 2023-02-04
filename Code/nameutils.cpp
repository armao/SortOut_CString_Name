#include"nameutils.h"

char abcCapt(char c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
		return c;
	}
	return c;
}
char capABCt(char c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return c;
	}
	return c;
}
void back_space(char ch[], int n, int a)
{
	for (int i = 1; i <= (a - n); ++i)
	{
		ch[n + i - 1] = ch[n + i];
	}
}

void typing(char ch[], int in, int end, char ch_in) {
	for (int i = 0; i <= (end + 1 - in); ++i)
	{
		ch[end + 1 - i] = ch[end - i];
	}
	ch[in] = ch_in;
}

int count(char ch[])
{
	int size = 0;
	for (int i = 0; ch[i] != 0; ++i)
	{
		size += 1;
	}
	return size;
}

void space_delete(char argv[], int on)
{
	int c = count(argv);
	if (argv[0] == ' ' && argv[1] != ' ') {  // head space cut
		back_space(argv, 0, c);
	}
	if (argv[on] == ' ' && on + 1 == c) {  // tail space cut
		argv[on] = argv[on + 1];
	}

	if (argv[on] == ' ' && argv[on + 1] == ' ') {  //  catch middle space
		back_space(argv, on, c);
		return space_delete(argv, on);
	}

	else if (on >= c) {  // close function

	}

	else {  // NEXT!!
		return space_delete(argv, on + 1);
	}
}

int find_final(char argv[], int endIndex)
{
	int r = 0;
	for (int w = 30; argv[w] != ' ' && argv[w - 1] != ' ';--w)
	{
		++r;
	}
	return r;
}
using namespace nameutile;

void nameutile::capitalize(char argv[])
{
	int a = count(argv);
	space_delete(argv, 0);

	for (int i = 0; i < a;++i)
	{
		if (argv[i] != ' ')
		{
			argv[i] = abcCapt(argv[i]);
			++i;
			while (argv[i] != ' ' && i < a)
			{
				argv[i] = capABCt(argv[i]);
				++i;
			}
		}
	}
	argv[a] = 0;
}

void nameutile::trim_midle_names(char argv[])
{
	int total = count(argv);
	int a = total - find_final(argv, total);

	for (int i = 1;i <= a; ++i) {
		if (argv[i] != ' ' && argv[i - 1] == ' ' && argv[i + 1] != ' ')
		{
			while (argv[i] != ' ' && argv[i - 1] == ' ' && argv[i + 1] != ' ' && i < a)
			{
				back_space(argv, i + 1, total);
				--a;
			}
			typing(argv, i + 1, total, '.');
			++a;
		}
	}
}
