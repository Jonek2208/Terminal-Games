#include <bits/stdc++.h>
using namespace std;

#ifdef __linux__ 
    #define CLEAR system("clear")
	#define Beep(x, y) 
#elif _WIN32
	#include <windows.h>
	#define CLEAR system("clear")
#else
#endif


typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) ((int)(c).size())
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

struct note
{
	int val;
	int freq;
	note(int _val, int _freq)
	{
		val = _val;
		freq = _freq;
	}
};
struct sound
{
	#define C3 65
	#define Cis3 69
	#define Des3 69
	#define D3 73
	#define Dis3 77
	#define Es3 77
	#define E3 82
	#define F3 87
	#define Fis3 92
	#define Ges3 92
	#define G3 98
	#define Gis3 103
	#define As3 103
	#define A3 110
	#define Ais3 116
	#define B3 116
	#define H3 123
	#define C4 130
	#define Cis4 138
	#define Des4 138
	#define D4 146
	#define Dis4 155
	#define Es4 155
	#define E4 164
	#define F4 174
	#define Fis4 185
	#define Ges4 185
	#define G4 196
	#define Gis4 207
	#define As4 207
	#define A4 220
	#define Ais4 133
	#define B4 233
	#define H4 247
	#define C5 261
	#define Cis5 277
	#define Des5 277
	#define D5 293
	#define Dis5 311
	#define Es5 311
	#define E5 329
	#define F5 349
	#define Fis5 370
	#define Ges5 370
	#define G5 391
	#define Gis5 415
	#define As5 415
	#define A5 440
	#define Ais5 466
	#define B5 466
	#define H5 493
	#define C6 523
	#define Cis6 554
	#define Des6 554
	#define D6 587
	#define Dis6 622
	#define Es6 622
	#define E6 659
	#define F6 698
	#define Fis6 740
	#define Ges6 740
	#define G6 784
	#define Gis6 830
	#define As6 830
	#define A6 880
	#define Ais6 932
	#define B6 932
	#define H6 987
	
	int tempo;
	PII metrum;
	vector<note> score;
	
	sound(int _t, int _x, int _y)
	{
		tempo = _t;
		metrum = MP(_x, _y);
	}
	
	void play()
	{
		FOREACH(it, score)
		{
			Beep(it->freq, (metrum.ND * 60000)/it->val/tempo);
		}
	}
};

sound fail(100, 4, 4);
sound win(150, 4, 4);
sound remis(120, 4, 4);
sound error (150, 4, 4);

void init()
{
	error.score.PB(note(8, F4));
	error.score.PB(note(6, H4));
	fail.score.PB(note(4, A4));
	fail.score.PB(note(4, As4));
	fail.score.PB(note(4, G4));
	fail.score.PB(note(2, Ges4));
	remis.score.PB(note(8, C5));
	remis.score.PB(note(8, E5));
	remis.score.PB(note(8, G5));
	remis.score.PB(note(8, C6));
	remis.score.PB(note(8, G5));
	remis.score.PB(note(8, E5));
	remis.score.PB(note(4, C5));
	win.score.PB(note(8, C6));
	win.score.PB(note(8, D6));
	win.score.PB(note(8, E6));	
	win.score.PB(note(4, G6));
	win.score.PB(note(8, E6));
	win.score.PB(note(2, G6));
}

int rnd(PII range)
{
	return rand() % (range.ND - range.ST) + range.ST;
}

	
const int S = 9;
const int MV[] = {-1, 6, 7, 8, 3, 4, 5, 0, 1, 2};

struct gra
{
	int T[S];
	//0 - brak, 1 - O, 2 - X

	gra()
	{
		REP(i, S) T[i] = 0;
	}
	
	void draw(int pl)
	{
		CLEAR;
		cout<<"Ruch: " << (pl == 1 ? 'O' : 'X') <<"\n\n";
		for(int i = 0; i < S; i+=3)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<(T[i+j] == 0 ? '-' : (T[i+j] == 1 ? 'O' : 'X'))<<" ";
			}
			cout<<"\n";
		}
		
		cout<<"\nMozliwe ruchy\n";
		
		for(int i = 6; i >= 0; i-=3)
		{
			for(int j = 0; j < 3; j++)
			{
				if(T[MV[i+j+1]] == 0) cout<<i+j+1;
				else cout << '-';
				cout<<" ";
			}
			cout<<"\n";
		}
	}
	
	int state()
	{
		FOR(f, 1, 2)
		{
			//przekatne
			if((T[0] == f && T[4] == f && T[8] == f) ||
			(T[2] == f && T[4] == f && T[6] == f) ||
			//pionowe
			(T[0] == f && T[3] == f && T[6] == f) ||
			(T[1] == f && T[4] == f && T[7] == f) ||
			(T[2] == f && T[5] == f && T[8] == f) ||
			//poziome
			(T[0] == f && T[1] == f && T[2] == f) ||
			(T[3] == f && T[4] == f && T[5] == f) ||
			(T[6] == f && T[7] == f && T[8] == f)) return f;
		}
		
		REP(i, S) if(T[i] == 0) return -1;
		return 0;
	}
	
	int pos_id(int pl, int P[S])
	{
		int il = 1;
		if(state() == -1)
		{
			
			REP(i, S) P[i] = T[i];
			REP(i, S)
			{
				if(T[i] == 0 && state() == -1)
				{
					P[i] = pl;
					int tmp = pos_id(3-pl, P);
					P[i] = 0;
					il *= tmp;
				}
			}
		}
		if(state() == 0) return 2;
		if(state() > 0) return 0;
		
		if(il == 0) return 1;
		if(il > 1) return 2;
		return 0;
	}
	
	int make_move(int pl, int pos, bool computer=false)
	{
		if(!computer)
		{
			if(pos > 9 || pos < 0 || T[MV[pos]] != 0) return 1;
			T[MV[pos]] = pl;
		}
		else T[pos] = pl;
		return 0;
	}
	
	void play(int _pl)
	{
		int pl = _pl;
		draw(pl);
		while(state() == -1)
		{	
			if(pl == 1)
			{
				int a;
				cin>>a;
				while(make_move(pl, a))
				{
					draw(pl);
					cout<<"\t\tPODAJ POPRAWNE POLE !!!!\n";
					error.play();
					cin>>a;
				}
				
				make_move(pl, a);
					
			}
			else
			{
				int mx = -1, x;
				REP(i, S) if(T[i] == 0)
				{
					T[i] = pl;
					//~ int tmp = 0;
					int tmp = pos_id(3-pl, T);
					T[i] = 0;
					if(tmp == 0)
					{
						x = i;
						break;
					}
					else
					{
						if(tmp > mx)
						{
							mx = tmp;
							x = i;
						}
					}
					
				}
				
				make_move(pl, x, true);
								
			}
			
			pl = 3-pl;
			draw(pl);
		}
		
		int res = state();
		cout<<"\n\t\t";
		if(res == 0)
		{
			cout<<"REMIS";
			remis.play();
		}
		else
		{
			if(res == 1)
			{
				cout<<"WYGRAL O";
				win.play();
			}
			else
			{
				cout<<"WYGRAL X";
				fail.play();
			}
		}
		cout<<"\n";
	}
	
	
};

gra *g;

int main()
{
	g = new gra;
	init();
	g->play(1);
	//~ cout<<g->pos_id(2, g->T);
	return 0;
}

