#include <fstream>
#include <iostream>
#include "BinaryTree.h"
#include "ForwardList.h"
#include "Result.hpp"
using namespace std;

// ������� ��� ��������� ���� ����������� (����� ��� ������� � ����������� � ForwardList)
// � ��� ���������� �� �������, ������� ���������� ��� ����� Result.surname
// � ������ ���� ���������� ������� ��� ��������� - compare(), ���� � ����������
// ��� ��������� ���� �����: string firstStr � string secondStr:
// firstStr.compare(secondStr) ����� ������� 3 ��������:
// = 0 - ����� firstStr � secondStr ���� � �� �� �����
// > 0 - ����� firstStr �� �������� ������, ��� secondStr
// < 0 - ����� firstStr �� �������� �����, ��� secondStr
bool isResultGreaterByName(const Result& first, const Result& second)
{
	return first.surname.compare(second.surname) > 0;
}

bool isResultGreaterByAverage(const Result& first, const Result& second)
{
	return first.averageValue > second.averageValue;
}

// ���������� ��� ����������� �������� ������ � ������� �������� ������
// ���� 'Result', �������� ������ �� ����� 'file'
ForwardList<Result> forwardListFromFile(ifstream& file)
{
	size_t n;
	ForwardList<Result> results;

	if (!file.is_open())
	{
		throw exception("File not found.");
	}
	file >> n;
	for (size_t i = 0; i < n && file.good(); i++)
	{
		Result result;

		file >> result.surname >> result.surname;
		for (size_t j = 0; j < 4; j++)
		{
			double value;
			file >> value;
			result.averageValue += value;
		}
		result.averageValue /= 4.0;
		results.pushByPriorityAsc(result, isResultGreaterByName);
	}

	file.close();
	return results;
}

// ���������� �������� ������ �
BinaryTree<Result> binaryTreeFromFile(ifstream& file)
{
	size_t n;
	BinaryTree<Result> results(isResultGreaterByAverage);

	if (!file.is_open())
	{
		throw exception("File not found.");
	}
	file >> n;
	for (size_t i = 0; i < n && file.good(); i++)
	{
		Result result;

		file >> result.surname >> result.surname;
		for (size_t j = 0; j < 4; j++)
		{
			double value;
			file >> value;
			result.averageValue += value;
		}
		result.averageValue /= 4.0;
		results.add(result);
	}

	file.close();
	return results;
}

int main()
{
	try
	{
		string firstFilename = "input1.txt";
		string secondFilename = "input2.txt";

		//Part 1:
		ifstream firstInputFile(firstFilename);
		ForwardList<Result> results = forwardListFromFile(firstInputFile);
		cout << "Result of the first input file (" << firstFilename << "):\n";
		cout << results.toString();

		//Part 2
		ifstream secondInputFile(secondFilename);
		BinaryTree<Result> tree(binaryTreeFromFile(secondInputFile));
		cout << "\n\nResult of the second input file (" << secondFilename << "):\n";
		cout << tree.toString(4); // ������� 4 ������ 3, ����� ���������, ��� ��� ���� 4 ��� ����
		return 0;
	}
	catch (const exception& ex)
	{
		cerr << "Exception: " << ex.what();
	}
}
