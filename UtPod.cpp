//
// Created by tonyb on 10/30/2019.
//

#include "UtPod.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

UtPod::UtPod() {

    memSize = MAX_MEMORY;
    head = NULL;
    tail = NULL;
}

UtPod::UtPod(int size) {

    if(size <= 0 || size > MAX_MEMORY)
        memSize = MAX_MEMORY;
    else
        memSize = size;

    head = NULL;
    tail = NULL;
}

int UtPod::addSong(Song const &s) {

    SongNode *temp= new SongNode;
    temp->s = s;
    temp->next = NULL;

    if(temp->s.getSize()>getRemainingMemory()){

        return NO_MEMORY;
    }

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }

    return SUCCESS;


}

int UtPod::removeSong(Song const &s) {

    SongNode *current = head;
    SongNode *previous = head;

    while(current != NULL){
        if(current->s == s){
            previous->next = current->next;
            delete (current);
            return SUCCESS;
        }
        previous = current;
        current = current->next;
    }

    return NOT_FOUND;

}

void UtPod::shuffle() {

    int numSongs = getNumSongs();

    if (numSongs < 2){
        cout << "Add more songs to shuffle." << endl;
        return;
    }

    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);

    for (int i = 0; i < 10*numSongs ; ++i) {

        int randomSongIndex1 = rand() % numSongs;
        int randomSongIndex2 = rand() % numSongs;
        SongNode *ranSong1 = head;
        SongNode *ranSong2 = head;

        for(randomSongIndex1; randomSongIndex1 != 0; randomSongIndex1--){

            ranSong1 = ranSong1->next;
        }

        for(randomSongIndex2; randomSongIndex2 != 0; randomSongIndex2--){

            ranSong2 = ranSong2->next;
        }

        Song temp = ranSong1->s;    //swap contents without changing pointer to next
        ranSong1->s = ranSong2->s;
        ranSong2->s = temp;




        
    }






}

void UtPod::showSongList() {

    SongNode *temp = head;

    if (temp == NULL){

        cout << "No songs." << endl;
        return;
    }

    while(temp != NULL){

        cout << "Title: " << temp->s.getTitle() << " Artist: " << temp->s.getArtist()
            << " Size: " << temp->s.getSize() << " MB" << endl;

        temp = temp->next;
    }



}

void UtPod::sortSongList() {

    if(getNumSongs() < 2){

        cout << "Not enough Songs to sort." << endl;
        return;
    }

    SongNode *outer = head;
    SongNode *inner = NULL;
    SongNode *smaller = NULL;

    while(outer != NULL){

        smaller = outer;
        inner = outer->next;

        while(inner != NULL){

            if(inner->s < smaller->s){
                smaller = inner;
            }

            inner = inner->next;
        }

        if(smaller != outer){       //changes artist, title, and size
                                    //without changing pointer to next
            Song temp = smaller->s;
            smaller->s = outer->s;
            outer->s = temp;
        }

        outer = outer->next;

    }


}

void UtPod::clearMemory() {

    SongNode *current = head;
    SongNode *temp = NULL;


    while(current != NULL){
        temp = current->next;
        delete (current);
        current = temp;
    }

    head = NULL;

}

int UtPod::getRemainingMemory() {

    SongNode *temp = head;
    int podSize = 0;

    while(temp != NULL){
        podSize = temp->s.getSize() + podSize;
        temp = temp->next;
    }

    return (getTotalMemory() - podSize);


}
int UtPod::getNumSongs() {

    SongNode *temp = head;
    int count = 0;

    while (temp != NULL) {

        count++;
        temp = temp->next;

    }

    return count;
}

UtPod::~UtPod() {

    clearMemory();

}




