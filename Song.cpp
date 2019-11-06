//
// Created by tonyb on 10/29/2019.
//

#include "Song.h"

using namespace std;

Song::Song(){

    artist = "";
    title = "";
    size = 0;
}

Song::Song(string songArtist, string songTitle, int songSize) {

    artist = songArtist;
    title = songTitle;
    size = songSize;
}

void Song::setArtist(string songArtist) {

    artist = songArtist;
}

string Song::getArtist() const {

    return artist;
}

void Song::setTitle(string songTitle){

    title = songTitle;

}

string Song::getTitle() const {

    return title;
}

void Song::setSize(int songSize) {

    size = songSize;
}

int Song::getSize() const {

    return size;
}

bool Song::operator>(Song const &music) {

    if(artist != music.artist)
        return artist > music.artist;

    if(title != music.title)
        return title > music.title;

    if(size != music.size)
        return size > music.size;

    return false;

}

bool Song::operator==(Song const &music) {

    return (artist == music.artist && title == music.title && size == music.size);

}

bool Song::operator<(Song const &music) {

    if(artist != music.artist)
        return artist < music.artist;

    if(title != music.title)
        return title < music.title;

    if(size != music.size)
        return size < music.size;

    return false;
}


