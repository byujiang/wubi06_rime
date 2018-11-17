/*
 * =====================================================================================
 *
 *       Filename:  wubi.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/14 12:23:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <locale.h>
#include <vector>
#include <cstdlib>
#include <set>
#include <ctime>
#include <random>
#include <unistd.h>

using namespace std;

void process_single_word(string name){
	wifstream infile(name.c_str());
	if (!infile.is_open()) {
		cerr << "Opening Single Word File Failed" << endl;
		exit(EXIT_FAILURE);
	}
	set<pair<wstring, wstring>,less< pair<wstring, wstring> > >* singleword = new set<pair<wstring, wstring>, less< pair< wstring, wstring> >  >[4];
	pair<wstring, wstring> temp;
	infile >> temp.second >> temp.first;
	long cnt = 0;
	while (!infile.eof()) {
		cnt++;
		//singleword[temp.second.size() - 1].push_back(temp);
		singleword[temp.first.size() - 1].insert(temp);
		wcout << cnt << endl;
		infile >> temp.second >> temp.first;
	}
	infile.close();
	name = "new_" + name;
	wofstream out(name.c_str());
	//vector<pair<wstring, wstring>, less< wstring>  >::iterator it;
	set<pair<wstring, wstring>, less<pair<wstring, wstring> > >::iterator it;
	for (int i = 0; i < 4; i++) {
		for (it  = singleword[i].begin(); it !=singleword[i].end(); it++) {
			//out << (*it).first << endl;
			out << (*it).first << "\t" << (*it).second << endl;
		}
	}
	out.close();
	cout << "Finished Reading Single World" << endl;
}

int main(int argc, const char *argv[]) {

	if (argc != 3) {
		cerr << "Parameter List Error" << endl;
		exit(EXIT_FAILURE);
	}

	string single = argv[1];
	string words = argv[2];

	// setlocale(LC_ALL,"zh_CN.UTF-8");
	locale china("zh_CN.UTF-8");
	locale::global(china);
	wifstream infile(single.c_str());

	if (!infile.is_open()) {
		cerr << "Opening Single Word File Failed" << endl;
		exit(EXIT_FAILURE);
	}
	// cout << "开始读取单字" << endl;
	// wcout.imbue(china);

	set<pair<wstring, wstring>,less<pair<wstring, wstring>>> singleword;// = new set<pair<wstring, wstring>, less< pair< wstring, wstring> >  >[4];
	pair<wstring, wstring> temp;
	long cnt = 0;
	infile >> temp.first >> temp.second;
	// cout << "您好" << endl;
	// wstring str=L"您好";
	// wcout << str << "低温一" << ", len = ";
	// cout << str.size() << endl;
	wcout.imbue(china);
	wcout << temp.first << " " << to_wstring(temp.second.length()) << " " << temp.second << endl;
	// usleep(10000000);
	while (!infile.eof()) {
		cnt++;
		singleword.insert(temp);
		wcout << temp.first << " " << temp.second << endl;
		infile >> temp.first >> temp.second;
	}
	infile.close();
	cout << "Finished Loading Single Word" << endl;

	
	wofstream out;
	//vector<pair<wstring, wstring>, less< wstring>>::iterator it;
	set<pair<wstring, wstring>, less<pair<wstring, wstring>> >::iterator it;

	infile.open(words.c_str());
	if (!infile.is_open()) {
		cerr << "Opening Word File Failed" << endl;
		exit(EXIT_FAILURE);
	}
	
	set<wstring,less<wstring>> word;// = new set<pair<wstring, wstring>, less< pair< wstring, wstring> >  >[4];
	set<wstring, less<wstring> >:: iterator wit;
	wstring inter;
	infile >> inter;// >> mtemp;
	while (!infile.eof()) {
		word.insert(inter);
		infile >> inter;
	}
	infile.close();
	wcout << "一共有" << to_wstring(word.size()) << "个词组" << endl;
	out.open("word_code.txt");
	int rnd = 0;
	cnt = 1;
	srand(clock_t());
	for (wit  = word.begin(); wit != word.end(); wit++) {
		int word_size = (*wit).size();
		if( word_size == 1)
			continue;
		out << (*wit) << "\t";
		if ((*wit).size() == 2) {
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[0] == (*it).second[0]) {
					out << (*it).first[0] << (*it).first[1];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[1] == (*it).second[0]) {
					out << (*it).first[0] << (*it).first[1];
					break;
				}
			}
		}

		if ((*wit).size() == 3) {
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[0] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[1] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[2] == (*it).second[0]) {
					out << (*it).first[0] << (*it).first[1];
					break;
				}
			}
		}

		if ((*wit).size() == 4) {
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[0] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[1] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[2] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[3] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
		}

		if (word_size >= 5) {
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[0] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[1] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[2] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
			for (it  = singleword.begin(); it != singleword.end(); it++) {
				if ( (*wit)[word_size - 1] == (*it).second[0]) {
					out << (*it).first[0];
					break;
				}
			}
		}
		rnd = rand() % 1024+1; cnt++;
		out << "\t" << rnd << endl;
	}
	
	wcout << "Good " << endl;
	setlocale(LC_ALL,"");
	return 0;
}

