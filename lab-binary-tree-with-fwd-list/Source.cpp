#include <fstream>
#include <iostream>
#include "BinaryTree.h"
#include "ForwardList.h"
#include "Result.hpp"
using namespace std;

// Функция для сравнения двух результатов (нужна для вставки с приоритетом в ForwardList)
// У нас сортировка по фамилии, поэтому сравнивать нам нужно Result.surname
// У строки есть стандартая функция для сравнения - compare(), ниже её объяснение
// для сравнения двух строк: string firstStr и string secondStr:
// firstStr.compare(secondStr) может вернуть 3 значения:
// = 0 - когда firstStr и secondStr одни и те же слова
// > 0 - когда firstStr по алфавиту раньше, чем secondStr
// < 0 - когда firstStr по алфавиту позже, чем secondStr
bool isResultGreaterByName(const Result& first, const Result& second)
{
	return first.surname.compare(second.surname) > 0;
}

bool isResultGreaterByAverage(const Result& first, const Result& second)
{
	return first.averageValue > second.averageValue;
}

// Возвращает нам односвязный линейный список в котором хранятся данные
// типа 'Result', считывая данные из файла 'file'
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

// Возвращает бинарное дерево с
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
		cout << tree.toString(4); // Поставь 4 вместо 3, чтобы проверить, что там есть 4 ряд цифр
		return 0;
	}
	catch (const exception& ex)
	{
		cerr << "Exception: " << ex.what();
	}
}
