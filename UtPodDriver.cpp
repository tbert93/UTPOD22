/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int code;
    bool finished = false;
    basic_string<char> inputArtist;
    basic_string<char> inputTitle;
    int inputSize;

    UtPod t;
    UtPod s(300);

    UtPod zero(0);                          //checking pod size, should be 512 mb
    UtPod thousand(1000);
    int result = zero.getRemainingMemory();
    cout << "size of ZeroMBPod: " << result << endl;
    result = thousand.getRemainingMemory();
    cout << "size of ThousandMBPod: " << result << endl;




    Song s1("Beatles", "Hey Jude1", 4);
    result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 1);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 2);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Adele", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.shuffle();
    t.showSongList();

    cout << endl;
    t.shuffle();
    t.showSongList();

    cout << endl;
    t.sortSongList();
    t.showSongList();


    cout << endl;
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    t.clearMemory();
    cout << "memory = " << t.getRemainingMemory() << endl;
    t.showSongList();


    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    while(!finished){

        cout << "1-Add Song, 2-Remove Song, 3-Shuffle, 4-Sort, 5-Show, 6-Clear Mem, 7-Exit\n";
        cin >> code;

        if(code == 1){

            cout << "Artist: ";
            cin >> inputArtist;
            cout << "Title: ";
            cin >> inputTitle;
            cout << "Size: ";
            cin >> inputSize;

            Song tempSong(inputArtist, inputTitle, inputSize);
            result = t.addSong(tempSong);
            cout << "add result = " << result << endl;
        }

        if(code == 2){

            cout << "Artist: ";
            cin >> inputArtist;
            cout << "Title: ";
            cin >> inputTitle;
            cout << "Size: ";
            cin >> inputSize;

            Song tempSong(inputArtist, inputTitle, inputSize);
            result = t.removeSong(tempSong);
            cout << "delete result = " << result << endl;




        }

        if(code == 3)
            t.shuffle();

        if(code == 4)
            t.sortSongList();

        if(code == 5)
            t.showSongList();

        if(code == 6)
            t.clearMemory();

        if(code == 7)
            finished = true;



    }

    finished = false;

    while(!finished){

        cout << "300MB UTPOD: 1-Add Song, 2-Remove Song, 3-Shuffle, 4-Sort, 5-Show, 6-Clear Mem, 7-Exit\n";
        cin >> code;

        if(code == 1){

            cout << "Artist: ";
            cin >> inputArtist;
            cout << "Title: ";
            cin >> inputTitle;
            cout << "Size: ";
            cin >> inputSize;

            Song tempSong(inputArtist, inputTitle, inputSize);
            result = s.addSong(tempSong);
            cout << "add result = " << result << endl;
        }

        if(code == 2){

            cout << "Artist: ";
            cin >> inputArtist;
            cout << "Title: ";
            cin >> inputTitle;
            cout << "Size: ";
            cin >> inputSize;

            Song tempSong(inputArtist, inputTitle, inputSize);
            result = s.removeSong(tempSong);
            cout << "delete result = " << result << endl;




        }

        if(code == 3)
            s.shuffle();

        if(code == 4)
            s.sortSongList();

        if(code == 5)
            s.showSongList();

        if(code == 6)
            s.clearMemory();

        if(code == 7)
            finished = true;



    }


}
