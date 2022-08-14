#include<iostream>

using namespace std;
void sw(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// arr[]Ϊ��ȫ��������������õ�������
// nΪ��ȫ�������Ľڵ㣬�����鳤��
// iΪ��ά���Ľڵ�
void heapify(int arr[], int n, int i) {    //������������ȶѻ�

	//�ݹ����
	if (i >= n) return;

	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if (lson < n && arr[largest] < arr[lson]) {  //��������ֵ�Ƚϣ��ҵ����ڵ㣬��ֵ�±�
		largest = lson;
	}
	if (rson < n && arr[largest] < arr[rson]) {  //���Һ�����ֵ�Ƚϣ��ҵ����ڵ㣬��ֵ�±�
		largest = rson;
	}
	if (largest != i) {   //������ڵ����ֵ�±��֮ǰ�Ĳ�һ������ô�������ߵ���ֵ
		//sw(arr[largest], arr[i]);
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest); //����һ���ݹ飬��Ϊ����һ��Ľڵ㽻����֮���޷���֤�±߸��ڵ���ں��ӽڵ�
	}

}
void heap_sort(int arr[], int n) {
	//����
	int lastNode = n - 1;    //�Ӻ���ǰ����
	int parent = (lastNode - 1) / 2;
	for (int i = parent; i >= 0; i--) {
		heapify(arr, n, i);
	}

	//������
	for (int i = n - 1; i >= 0; i--) {
		sw(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}
int main() {
	int arr[] = { 26,4,6,22,53,7,9,4 };
	heap_sort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
