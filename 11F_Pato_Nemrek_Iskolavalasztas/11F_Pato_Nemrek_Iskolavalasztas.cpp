#include <iostream>
#include <vector>

using namespace std;

bool Jo(int i, int j, vector<int> X, vector<vector<int>> Y, vector<int> kapacitasok)
{
	return;
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
		int j = X[i] + 1;
		if (j<2 && Jo(i, j, X, Y, kapacitasok))
		{
			//kapacitasok[...]--
			X[i++] = j;
		}
		else
		{
			//kapacitasok[...]++
			X[i--] = -1;
		}
	}

	// X indext�rol�b�l �rt�kt�rol�t csin�lunk
	for (int ix = 0; ix < N; ix++)
		X[i] = Y[i][X[ix]];

	// Ki�r�s
	for (auto& elem : X)
		cout << elem << " ";
}
