#include <iostream>
#include <cstdlib> 
#include <time.h>
#include <fstream>
using namespace std;


#include "Heap.h" 
#include "DataNode.h"
#include "Queue.h"
#include "Stack.h"
#include "HuffCodeNode.h"
#include "HuffCodeBuilder.h"

//int bianli(DataNode *root)
//{
//	if(root)
//	{
//		if (!root->leftchild_ && !root->rightchild_)
//			cout << static_cast<unsigned int>(root->getData()) << " ";
//		int a = bianli(root->leftchild_);
//		int b = bianli(root->rightchild_);
//		return (a>b?a:b)+1;
//	}
//	else
//		return 0;
//	
//}

void jianli(HuffCodeNode * finallCode,HuffCodeBuilder & builder,DataNode * root)
{
	Queue<DataNode *> que;
	DataNode * temp = root;	
	Stack<DataNode *> stack;
	while(temp || !stack.isEmpty())
	{
		while(temp)
		{
			stack.push(temp);
			temp = temp->leftchild_;
			builder.add(false);
		}
		if(!stack.isEmpty())
		{
			temp = stack.pop();
			builder.del();
			if(!temp->leftchild_ && !temp->rightchild_)
			{
				builder.buildCode(finallCode[static_cast<unsigned>(temp->getData())]);
			}
			temp = temp->rightchild_;
			builder.add(true);
		} 
	}
	
}

void fileRead(DataNode* data)
{
	fstream binaryio;
	binaryio.open("./data/1.txt", ios::in | ios::binary);
	if(!binaryio)
	{
		printf("data read error"); 
	}
	char forFile;

	for (int i=0 ;!binaryio.eof() ; i++)
	{
		binaryio.read(&forFile,1);
		data[static_cast<unsigned char>(forFile)]++;
	}

	binaryio.close();
}
void fileWrite(HuffCodeNode * finallCode)
{
	fstream binaryio;
	fstream writ;
	binaryio.open("./data/1.txt", ios::in | ios::binary);
	if(!binaryio)
	{
		printf("data read error"); 
	}
	writ.open("./data/code.txt", ios::out | ios::binary);
	if(!writ)
	{
		printf("data writ error"); 
	}
	char forFile;


	int forWrite=0;
	int  wirtBit=0;
	
	for (int i=0 ;!binaryio.eof() ; i++)
	{
		binaryio.read(&forFile,1);
		finallCode[static_cast<unsigned char>(forFile)].writ(writ,forWrite,wirtBit);
	}

	binaryio.close();
}

int main()
{
	const int ss = 256;
	DataNode* data = new DataNode[ss+1];
	for (int i=0; i<ss; i++)
	{
		data[i].setData(static_cast<char>(i));
	}

	fileRead(data);
	Heap<DataNode> heap(data, ss);
	

	DataNode *huffCode;
	try {
		huffCode = new DataNode[2*ss];
	}
	catch (const bad_alloc& e)
	{
		cout << " error" << endl;
			return 0;
	}
	DataNode *temp = 0;
	for(int i=0; i<2*ss-2; i++)
	{
		huffCode[i] = heap.pop();
		i++;
		huffCode[i] = heap.pop();
		int a;
		int b;
		a = huffCode[i].getWeight();
		b = huffCode[i-1].getWeight();
		temp = new DataNode(a+b, huffCode+i-1, huffCode+i);
		if(heap.push(*temp))
		{
			cout << "insert error" << endl;
			return 0;
		}
		delete temp;
	}
	DataNode *root = new DataNode(heap.pop());

//	int level = bianli(root);
//	for(int i=0; i<ss; i++)
//		cout << '\111' << " ";
//	cout << endl;
//	cout<< (int)level << "@@@\163" << endl; 
	
//	Queue<DataNode *> que;
//	temp = root;
//	while(temp)
//	{
//		if(temp->leftchild_)
//			que.enQueue(temp->leftchild_);
//		if(temp->rightchild_)
//			que.enQueue(temp->rightchild_);
//		if(!temp->leftchild_ && !temp->rightchild_)
//			cout << static_cast<unsigned>(temp->getData()) << "  ";
//		temp = que.deQueue();
//	}
//	cout << "####"<< (char)101 <<endl;


	HuffCodeBuilder builder;
	HuffCodeNode * finallCode = new HuffCodeNode[ss];
	
	jianli(finallCode,builder,root);
	
	fileWrite(finallCode);
	
	delete[] huffCode;	
	return 0;
}
