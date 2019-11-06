//
// Created by tonyb on 10/29/2019.
//

#ifndef PROJ5_SONG_H
#define PROJ5_SONG_H

#include <string>

using namespace std;

class Song {
private:
    string title;
    string artist;
    int size;

public:
    //constructor
    Song();

    Song(string songArtist, string songTitle, int songSize);

    void setArtist(string songArtist);

    string getArtist() const;

    void setTitle(string songTitle);

    string getTitle() const;

    void setSize(int songSize);

    int getSize() const;

    bool operator>(Song const &music);

    bool operator==(Song const &music);

    bool operator<(Song const &music);


};


#endif //PROJ5_SONG_H
