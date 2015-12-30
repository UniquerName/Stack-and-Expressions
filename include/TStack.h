
//#ifndef __TMATRIX_H__
//#define __TMATRIX_H__

#include <iostream>

using namespace std;

#define MemSize   50

class TStack
{
	int *pMem;
	int Size;
	int Top;
public:
	TStack();
	TStack(int n);
	TStack(const TStack &s);
	~TStack();

	bool IsEmpty(void) const;
	bool IsFull(void) const;

	void  Put(const int Val);
	int Peek(void) const;
	int Push(void);
	void SetSize(int n);
};


TStack::TStack()
{
	Top = -1;
	Size = MemSize;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::TStack(int s) {
	if (s<0)
		throw invalid_argument("Size < 0");
	else if (s>MemSize)
		throw invalid_argument("Size more than MemSize");
	Top = -1;
	Size = s;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::~TStack()
{
	delete[]pMem;
}

TStack::TStack(const TStack &s)
{
	Size = s.Size;
	pMem = new int[Size];
	Top = s.Top;
	for (int i = 0; i < Size; i++)
		pMem[i] = s.pMem[i];
}

bool TStack::IsEmpty() const
{
	if (Top == -1)
		return true;
	else
		return false;
}

bool TStack::IsFull() const
{
	if (Top == Size - 1)
		return true;
	else
		return false;
}

void TStack::Put(int Val)
{
	if (this->IsFull())
		throw invalid_argument("Stack is full");
	pMem[++Top] = Val;
}



int TStack::Peek() const
{
	if (Top == -1)
		throw ("Stack hasn't any elements");
	return pMem[Top];
}

int TStack::Push()
{
	if (this->IsEmpty())
		throw ("Stack is empty");
	return pMem[Top--];
}

void TStack::SetSize(int n)
{
	if (n<0)
		throw invalid_argument("NEW SIZE < 0");
	if (n<Top + 1)
		throw invalid_argument("NEW SIZE < TOP");
	int *p = new int[Top + 1];
	for (int i = 0; i < Top + 1; i++)
		p[i] = pMem[i];

	Size = n;
	delete[]pMem;
	pMem = new int[Size];
	for (int i = 0; i < Top + 1; i++)
		pMem[i] = p[i];
	for (int i = Top + 1; i < Size; i++)
		pMem[i] = 0;
}
//#endif