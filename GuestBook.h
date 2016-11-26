#ifndef GUESTBOOK_H
#define GUESTBOOK_H

#include <list>
#include "Review.h"
#include<fstream>

using namespace std;
class GuestBook {

private:
    list<Review*> reviews;
    GuestBook();                        //singleton oszt�ly, ebb�l tuti nem lesz t�bb, itt t�rt�nik meg a beolvas�s is
public:
    static GuestBook& getInstance();
    void listReviews(bool checked);     //ez csak azokat a review-kat list�zza,amelyek m�r checkolva lettek(az admint csak a nem csekkolt,
                                        //mindenki m�st csak a csekkolt verzi� �rdekelheti

    void addReview(const string& name,const string&label,const string& comment);    //review hozz�ad�sa
    ~GuestBook();                   //ide m�g meg k�ne �rni a f�jlba �r�st, illetve a felszabad�t�st
};
#endif //GUESTBOOK_H
