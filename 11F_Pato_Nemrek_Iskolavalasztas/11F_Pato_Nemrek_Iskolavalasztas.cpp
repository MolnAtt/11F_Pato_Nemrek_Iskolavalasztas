#include <iostream>
#include <vector>

using namespace std;

bool Jo(int i, int j, vector<int> X, vector<vector<int>> Y, vector<int> kapacitasok)
{
	return 0 < Y[i][X[i]] && 0 < kapacitasok[Y[i][X[i]] - 1]; // v�lasztott valamit �S ott van is m�g szabad kapacit�s
}

int main()
{

	// Beolvas�s
	int N, M;

	cin >> N >> M;

	vector<int> X(N,-1);
	vector<vector<int>> Y(N,vector<int>(2,0));
	vector<int> kapacitasok(M,0);

	for (int i = 0; i < N; i++)
		cin >> Y[i][0] >> Y[i][1];
	
	for (int i = 0; i < M; i++)
		cin >> kapacitasok[i];

	// F�program
	int i = 0;
	while (-1<i && i < N)
	{
		X[i]++;
		if (X[i]<2 && Jo(i, X[i], X, Y, kapacitasok))
		{
			--kapacitasok[Y[i][X[i]] - 1];
			i++;
		}
		else
		{
			X[i] = -1; // eleve -1 van ott?
			i--;
			++kapacitasok[Y[i][X[i]] - 1];
		}
	}

	// X indext�rol�b�l �rt�kt�rol�t csin�lunk
	for (int ix = 0; ix < N; ix++)
		X[ix] = Y[ix][X[ix]];


	// Ki�r�s
	if (i==-1)
	{
		cout << -1;
	}
	else
	{
		for (auto& elem : X)
			cout << elem << " ";
	}



}
