#include <fstream>
#include <set>
#include <iostream>
#include <iterator>
#include <string.h>
#include <string>
#include <tuple>
using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out");
int nr_stari, nr_alfabet,nr_tranzitii,nr_stari_finale;

bool diferit(set<string> X, set<string> Y)
{
	if(X.size()!=Y.size())
		return 1;

	set<string>::iterator i1=X.begin();
	set<string>::iterator i2=Y.begin();
	while(i1!=X.end())
	{
	if(*i1!=*i2)
		return 1;
	i1++;
	i2++;
	}

	return 0;
}

int main()
{
	//---------citim------------
	set<string> M[100][100];
	fin>>nr_stari;
	set<string> stari;
	for(int i=0;i<nr_stari;i++)
	{
		string x;
		fin>>x;
		stari.insert(x);

	}

	fin>>nr_alfabet;

	set<string> alfabet;
	for(int i=0;i<nr_alfabet;i++)
	{
		string x;
		fin>>x;
		alfabet.insert(x);

	}
	string stare_initiala;
	fin>>stare_initiala;
	fin>>nr_stari_finale;

	set<string> stari_finale;
	for(int i=0;i<nr_stari_finale;i++)
	{
		string x;
		fin>>x;
		stari_finale.insert(x);

	}
struct{
	string a,b,c;
}tranzitii[100];


	fin>>nr_tranzitii;

	for(int i=0;i<nr_tranzitii;i++)
		fin>>tranzitii[i].a>>tranzitii[i].b>>tranzitii[i].c;

///////////////-------------nu mai citim-----------/////////////////////

 	set <string >::iterator itr;
 	int k=0;
	for(itr = alfabet.begin(); itr != alfabet.end(); ++itr)
		{M[0][k+1].insert(*itr); k++;}

	M[1][0].insert(stare_initiala);
	for(int i=1;i<=nr_alfabet;i++)
	{
		set <string >::iterator itr1;
		for(itr1 = alfabet.begin(); itr1 != alfabet.end(); ++itr1)
			if(*itr1==*(M[0][i].begin()))
				break;
		if(itr1!=alfabet.end())
			for (int j=0;j<nr_tranzitii;j++)
				if(tranzitii[j].a==stare_initiala&&tranzitii[j].b==*itr1)
					M[1][i].insert(tranzitii[j].c);
	}

	int i=1,linia_curenta=1,ultima_coloana=1;

	M[1][0].insert(stare_initiala);
	while(linia_curenta<=ultima_coloana)
	{
		set <string> :: iterator itr4;  
	    for (itr4 = M[linia_curenta][0].begin(); itr4 != M[linia_curenta][0].end(); ++itr4) 
	    	for(int j=1;j<=nr_alfabet+1;j++)
	    		for(int k=0;k<nr_tranzitii;k++)
	    			if(tranzitii[k].a==*itr4&&tranzitii[k].b==*M[0][j].begin())
	    				M[linia_curenta][j].insert(tranzitii[k].c);


	    for(int j=1;j<=nr_alfabet+1;j++)
	    {
	    	bool contor=0;
	    	for(int q=1;q<=ultima_coloana;q++)
	    		if(diferit(M[q][0],M[linia_curenta][j])==0)
	    			contor=1;
	    	if(contor==0&&M[linia_curenta][j].size()>0)
	    	{
	    		ultima_coloana=ultima_coloana+1;
	    		M[ultima_coloana][0]=M[linia_curenta][j];
	    	}
	    }
	    linia_curenta++;
	}


	set <string> :: iterator itr3;  
    for (itr3 = M[3][0].begin(); itr3 != M[3][0].end(); ++itr3) 
    { 
        cout << *itr3; 
    } 


	return 0;
}