#include<conio.h>
#using <system.dll>

using namespace System;
using namespace System::Collections::Generic;

void SortedDictionaryExample(Dictionary<int, String^>^ inDict)
{
	SortedDictionary<int, String^>^ dict = gcnew SortedDictionary<int, String^>(inDict);

	for each (KeyValuePair<int, String^>^ pair in dict)
	{
		Console::WriteLine("Key = [{0}]\tValue = [{1}]",
			pair->Key, pair->Value);
	}
}

int main(array<System::String ^> ^args)
{
	Dictionary<int, String^>^ dict = gcnew Dictionary<int, String^>();

	dict->Add(9, "Nine");
	dict->Add(6, "Six");
	dict->Add(5, "Five");
	dict->Add(3, "Three");
	dict->Add(1, "One");
	dict->Add(10, "Ten");
	dict->Add(2, "Two");

	SortedDictionaryExample(dict);
	//-------------------------------------
	try
	{
		dict->Add(1, "Value");
	}
	catch (ArgumentException^)
	{
		Console::WriteLine("An element with Key = 1 already exists.");
	}

	//-------------------------------------
	String^ value = "";
	if (dict->TryGetValue(9, value))
	{
		Console::WriteLine("For key = 9, value = {0}.", value);
		Console::WriteLine("For key = 9, value = {0}.", dict[9]);
	}
	else
	{
		Console::WriteLine("Key = 9 is not found.");
	}
	//-------------------------------------
	dict->Remove(9);

	if (!dict->ContainsKey(9))
	{
		Console::WriteLine("Key 9 is not found.");
	}

	_getch();
	return 0;
}