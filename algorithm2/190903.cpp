#include <iostream>
#include <ctime>

using namespace std;

char S[100];

int partition(int low, int high) {
	//partition
	int pivotitem = S[low];
	int j = low;
	for (int i = low + 1; i <= high; ++i) {
		if (S[i] < pivotitem) {
			++j;
			swap(S[i], S[j]);
		}
	}
	int pivotpoint = j;
	swap(S[low], S[pivotpoint]);

	return pivotpoint;
}
int rand_partition(int low, int high) {
	int i = (rand() % (high - low + 1))  + low;
	swap(S[low], S[i]);
	return partition(low, high);
}
void sort(int low, int high) {
	if (low < high) {
		int pivotpoint = rand_partition(low, high);
		sort(low, pivotpoint - 1);
		sort(pivotpoint + 1, high);
	}
}

void permutation(int k, int n) {
	if (k >= n) {
		//print
		for (int i = 0; i <= n; ++i) cout << S[i];
		cout << endl;
		return;
	}
	sort(k, n); //�ʱ� ����
	permutation(k + 1, n); sort(k+1,n);
	int m=k+1; //�ٸ� ���ڸ� ã�� index, ��� k�� ��ġ���� �ڿ� ����
	while (m > k && m <= n) {
		//�ٸ� �����Ǵ�
		if (S[k] < S[m]) {
			swap(S[k], S[m]);
			permutation(k+1,n);
			sort(k+1, n);
		}
		++m;
	}
}

int main() {
	srand((unsigned int)time(0));
	cin >> S;
	permutation(0, strlen(S)-1);

	system("PAUSE");
	return 0;
}