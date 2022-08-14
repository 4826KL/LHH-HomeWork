#pragma once
#include<iostream>
using namespace std;

class MaxHeap
{
public:
    MaxHeap();
    MaxHeap(int capacity);
    ~MaxHeap();

    int getIndex(int data); //返回数据data在二叉堆中的索引
    int remove(int data);   //删除二叉堆中的数据data
    int insert(int data);   //将数据data插入到二叉堆中
    void printHeap();       //打印二叉堆

    void FilterDown(int start, int end); //向下调整算法
    void FilterUp(int start);            //向上调整算法

private:
    int* mHeap;    //数据
    int mCapacity; //理论上的总容量
    int mSize;     //实际容量
};

MaxHeap::MaxHeap()
{
    new (this) MaxHeap(30);
}

MaxHeap::MaxHeap(int capacity)
{
    //构造
    this->mSize = 0;
    this->mCapacity = capacity;
    this->mHeap = new int[mCapacity]; //动态申请数组
}

MaxHeap::~MaxHeap()
{
    //析构 释放
    this->mSize = 0;
    this->mCapacity = 0;
    delete[] this->mHeap;
}

int MaxHeap::getIndex(int data)
{
    for (int i = 0; i < mSize; i++)
    {
        if (data == this->mHeap[i])
        {
            return i; //成功找到
        }
    }
    return -1;
}

void MaxHeap::FilterDown(int start, int end)
{
    int cur = start;
    int left = 2 * cur + 1;
    int temp = mHeap[cur];

    while (left <= end)
    {
        // left为左子 left+1为右子
        if (left < end && mHeap[left] < mHeap[left + 1])
        {
            left++; //左右两孩子中选择数据较大者，即为mHeap[left+1]
        }
        if (temp >= mHeap[left])
        {
            break; //结束调整
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

int MaxHeap::remove(int data)
{
    int index;
    if (this->mSize == 0)
    {
        //如果为空堆 返回-1
        return -1;
    }

    index = this->getIndex(data);
    if (index == -1)
    {
        return -1; //查找失败
    }
    this->mHeap[index] = mHeap[--mSize]; //用最后的元素填补
    this->FilterDown(index, mSize - 1);  //调整
    return 1;                            //查找成功
}

//向上调整算法
void MaxHeap::FilterUp(int start)
{
    int cur = start;            // current
    int parent = (cur - 1) / 2; //完全二叉树的性质
    int temp = mHeap[cur];

    while (cur > 0)
    {
        //当没有到顶时进行调整
        if (mHeap[parent] >= temp)
        {
            break;
        }
        else
        {
            mHeap[cur] = mHeap[parent];
            cur = parent;
            parent = (parent - 1) / 2; //继续向上调整
        }
    }
    mHeap[cur] = temp;
}

//插入新数据
int MaxHeap::insert(int data)
{
    if (mSize == mCapacity)
    {
        //当前堆已满
        return -1;
    }
    mHeap[mSize] = data; //将新数据插入到队尾
    FilterUp(mSize);     //从队尾开始向上调整
    mSize++;             //实际容量++;
    return 1;
}

void MaxHeap::printHeap()
{
    for (int i = 0; i < mSize; i++)
    {
        cout << mHeap[i] << " ";
    }
}