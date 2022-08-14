#include<iostream>

using namespace std;
void sw(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// arr[]为完全二叉树层序遍历得到的数组
// n为完全二叉树的节点，即数组长度
// i为待维护的节点
void heapify(int arr[], int n, int i) {    //把这个二叉树先堆化

	//递归出口
	if (i >= n) return;

	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if (lson < n && arr[largest] < arr[lson]) {  //和左孩子数值比较，找到最大节点，赋值下标
		largest = lson;
	}
	if (rson < n && arr[largest] < arr[rson]) {  //和右孩子数值比较，找到最大节点，赋值下标
		largest = rson;
	}
	if (largest != i) {   //如果现在的最大值下标和之前的不一样，那么交换二者的数值
		//sw(arr[largest], arr[i]);
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest); //进行一个递归，因为在上一层的节点交换完之后，无法保证下边父节点大于孩子节点
	}

}
void heap_sort(int arr[], int n) {
	//建堆
	int lastNode = n - 1;    //从后往前建堆
	int parent = (lastNode - 1) / 2;
	for (int i = parent; i >= 0; i--) {
		heapify(arr, n, i);
	}

	//堆排序
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
