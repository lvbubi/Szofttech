#include "Plays.h"

void Plays::listPlays() {
	throw "Not yet implemented";
}

Play* Plays::selectPlay() {
	throw "Not yet implemented";
}

Plays::Plays()
{

    Eloadas eloadas;//egy random eloadas, beolvasod/feltoltod random adatokkal a teszteleshez, a helyeket mar beolvassa
    eloadas.play=new Play();
    eloadas.date="1995.04.25";



    int i=0,j=0;
    ifstream bemenet("terem.txt");

    string line;

    if (bemenet.is_open())//helyek beolvasasa, jegyek hozzadasa a megfelelo helyhez.
     {
       while ( getline (bemenet,line) )
       {
         eloadas.spaces.push_back(vector<int> (line.size()));//egy sor a he
         eloadas.tickets.push_back(vector<Ticket> (line.size()));

         for(char c:line){
             if(c-'0'==0)
                 eloadas.tickets[i][j]=Ticket(i,j,eloadas.play,eloadas.date);
             eloadas.spaces[i][j++]=c-'0';

         }
         i++;
         j=0;
       }
       bemenet.close();
     }

    for(vector<int> v:eloadas.spaces){
        for(int hely:v)
            cout<<hely;
        cout<<endl;
    }
}
