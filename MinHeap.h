#pragma once
#include <iostream>
using namespace std;

class MinHeap
{
public:
    MinHeap();
    MinHeap(int capacity);
    ~MinHeap();

    int getIndex(int data); //��������data�ڶ�����е�����
    int remove(int data);   //ɾ��������е�����data
    int insert(int data);   //������data���뵽�������
    void printHeap();       //��ӡ�����

    void FilterDown(int start, int end); //���µ����㷨
    void FilterUp(int start);            //���ϵ����㷨

private:
    int* mHeap;    //����
    int mCapacity; //�����ϵ�������
    int mSize;     //ʵ������
};

MinHeap::MinHeap()
{
    new (this) MinHeap(30);
}

MinHeap::MinHeap(int capacity)
{
    //����
    this->mSize = 0;
    this->mCapacity = capacity;
    this->mHeap = new int[mCapacity]; //��̬��������
}

MinHeap::~MinHeap()
{
    //���� �ͷ�
    this->mSize = 0;
    this->mCapacity = 0;
    delete[] this->mHeap;
}

int MinHeap::getIndex(int data)
{
    for (int i = 0; i < mSize; i++)
    {
        if (data == this->mHeap[i])
        {
            return i; //�ɹ��ҵ�
        }
    }
    return -1;
}

//���µ����㷨
void MinHeap::FilterDown(int start, int end)
{
    int cur = start;
    int left = 2 * cur + 1;
    int temp = mHeap[cur];

    while (left <= end)
    {
        // leftΪ���� left+1Ϊ����
        if (left < end && mHeap[left] > mHeap[left + 1])
        {
            left++; //������������ѡ�����ݽ�С�ߣ���ΪmHeap[left+1]
        }
        if (temp <= mHeap[left])
        {
            break; //��������
        }
        else
        {
            mHeap[cur] = mHeap[left];
            cur = left;
            left = 2 * left + 1;
        }
    }
    mHeap[cur] = temp;
}

int MinHeap::remove(int data)
{
    int index;
    if (this->mSize == 0)
    {
        //���Ϊ�ն� ����-1
        return -1;
    }

    index = this->getIndex(data);
    if (index == -1)
    {
        return -1; //����ʧ��
    }
    this->mHeap[index] = mHeap[--mSize]; //������Ԫ���
    this->FilterDown(index, mSize - 1);  //����
    return 1;                            //���ҳɹ�
}

//���ϵ����㷨
void MinHeap::FilterUp(int start)
{
    int cur = start;            // current
    int parent = (cur - 1) / 2; //��ȫ������������
    int temp = mHeap[cur];

    while (cur > 0)
    {
        //��û�е���ʱ���е���
        if (mHeap[parent] <= temp)
        {
            break;
        }
        else
        {
            mHeap[cur] = mHeap[parent];
            cur = parent;
            parent = (parent - 1) / 2; //�������ϵ���
        }
    }
    mHeap[cur] = temp;
}

//����������
int MinHeap::insert(int data)
{
    if (mSize == mCapacity)
    {
        //��ǰ������
        return -1;
    }
    mHeap[mSize] = data; //�������ݲ��뵽��β
    FilterUp(mSize);     //�Ӷ�β��ʼ���ϵ���
    mSize++;             //ʵ������++;
    return 1;
}

void MinHeap::printHeap()
{
    for (int i = 0; i < mSize; i++)
    {
        cout << mHeap[i] << " ";
    }
}