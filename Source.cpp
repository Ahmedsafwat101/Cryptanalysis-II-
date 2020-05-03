#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool sortByVal(const pair<char, int>& a,const pair<char, int>& b)
{
	return (a.second < b.second);
}

int main()
{
	string Plaintext = "PBFPVYFBQXZTYFPBFEQJHDXXQVAPTPQJKTOYQWIPBVWLXTOXBTFXQWAXBVCXQWAXFQJVWLEQNTOZQGGQLFXQWAKVWLXQWAEBIPBFXFQVXGTVJVWLBTPQWAEBFPBFHCVLXBQUFEVWLXGDPEQVPQGVPPBFTIXPFHXZHVFAGFOTHFEFBQUFTDHZBQPOTHXTYFTODXQHFTDPTOGHFQPBQWAQJJTODXQHFOQPWTBDHHIXQVAPBFZQHCFWPFHPBFIPBQWKFABVYYDZBOTHPBQPQJTQOTOGHFQAPBFEQJHDXXQVAVXEBQPEFZBVFOJIWFFACFCCFHQWAUVWFLQHGFXVAFXQHFUFHILTTAVWAFFAWTEVOITDHFHFQAITIXPFHXAFQHEFZQWGFLVWPTOFFA";
	char arr[26] = { 'E','T','A','O','I','N','S','H','R','D','L','C','U','M','W','F','G','Y','P','B','V','K','J','X','Q','Z' };

	map<char, int>Maping;
	map<char, int>sortedData;
	map<char, char>convert;
	map<char, int>::iterator it;
	vector<pair<char, int>>vec;
	for (int i = 0; i < Plaintext.length(); i++)
	{
		// not found 
		if (Maping.find(Plaintext[i]) == Maping.end()) 
		{
			cout << "I don't find the letter " << Plaintext[i] << endl;
			Maping.insert(make_pair(Plaintext[i], 1));
		}
		else
		{
			cout << "I found Letter" << Plaintext[i] << endl;
			Maping.insert(make_pair(Plaintext[i], Maping[Plaintext[i]]= Maping[Plaintext[i]]+1));
			//cout << Maping[Plaintext[i]] + 1 << endl;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		//not found pass
		if (Maping.find(arr[i]) == Maping.end())
		{
			Maping.insert(make_pair(arr[i], 0));
		}

	}

	//part 3
	for (it = Maping.begin(); it != Maping.end(); it++)
	{
		vec.push_back(make_pair(it->first, it->second));
	}

	sort(vec.begin(), vec.end(), sortByVal);

	cout << "The map, sorted by value is: " << endl;
	int counter = 0;
	for (int i = vec.size()-1; i>=0; i--)
	{
		cout << vec[i].second <<"-->"<<vec[i].first<< "--> " << arr[counter] << endl;
		convert.insert(make_pair(vec[i].first,arr[counter]));
		counter++;

	}

	for (int i = 0; i < Plaintext.length(); i++)
	{
		// this condition will not happen in any case coz i am already add all the cahrachters
		if (convert.find(Plaintext[i]) == convert.end())
		{
			// pass 
		}
		else
		{
			cout << convert[Plaintext[i]];
		}
	}
	cout << endl;
	cout << Maping.size() << endl;

	return 0;
}