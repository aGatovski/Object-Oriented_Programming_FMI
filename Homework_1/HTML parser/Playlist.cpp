#include <iostream>
#include <sstream>
#include <fstream>
#pragma warning(disable : 4996)

namespace GLOBAL_CONSTANTS {
  constexpr size_t NAME_SIZE = 64;
  constexpr size_t CONTENT_SIZE = 256;
  constexpr size_t PLAYLIST_SIZE = 30;
}

size_t getIntFromChar(char ch) {
    return ch;
}

enum Genre :uint8_t {// ???, ???, ???-???, ?????????? ??????, ????
    Rock = 1,
    Pop= 2,
    Hiphop= 4,
    Jazz= 8,
    Techno= 16,
};

struct Song {
private:
    uint8_t genre = 0;
    int songLength = 0;
    char songName[GLOBAL_CONSTANTS::NAME_SIZE] = "\0";
    char songContent[GLOBAL_CONSTANTS::CONTENT_SIZE] = "\0";

public:
    Song() = default;

    Song(uint8_t songGenre, int lengthSeconds, const char* name, const char* content) {
        setGenre(songGenre);
        setSongLength(lengthSeconds);
        setSongName(name);
        setSongContent(content);
    }

    void setGenre(uint8_t songGenre) {
        genre = songGenre;
    }

    uint8_t getGenre() const {
        return genre;
    }

    void setSongLength(int lengthSeconds) {
        if (lengthSeconds >= 0) {
            songLength = lengthSeconds;
        }
        else {
            std::cerr << "Invalid song length!" << std::endl;
        }
    }

    int getSongLength() const {
        return songLength;
    }

    void setSongName(const char* name) {
        strncpy(songName, name, GLOBAL_CONSTANTS::NAME_SIZE);
        songName[GLOBAL_CONSTANTS::CONTENT_SIZE - 1] = '\0';
    }

    const char* getSongName() const {
        return songName;
    }
    char* decimalToBinary(int decimal) {
        char* binary = new char[33]();
        int i = 0;

        if (decimal == 0) {
            return binary;
        }

        while (decimal > 0) {
            binary[i++] = (decimal % 2) + '0';
            decimal = decimal / 2;
        }

        if (strlen(binary) % 2 != 0) {
            binary[i++] = '0';
        }


        binary[i] = '\0';

        int len = i;
        for (int j = 0; j < len / 2; j++) {
            char temp = binary[j];
            binary[j] = binary[len - j - 1];
            binary[len - j - 1] = temp;
        }

        return binary;
    }
    void setSongContent(const char* content) {
        strcpy(songContent, content);
        songContent[GLOBAL_CONSTANTS::CONTENT_SIZE - 1] = '\0';
    }

    const char* getSongContent() const  {
        return songContent;
    }

    void setKthBitsToOne(const int k) {
        if (k < 0 || k > 32) {
            std::cout << "Invalid value of k." << std::endl;
            return;
        }

         char* s = new char[32];

         strcpy(s, getSongContent());

        int length = strlen(s); 

        for (int i = length - 1; i >= 0; i--) {
            if ((i % k-1) == 0) {
                s[i] ='1';
            }
        }

        setSongContent((const char*)(s));
        delete[]s;
    }

};

struct Playlist {
private:
    Song songs[GLOBAL_CONSTANTS::PLAYLIST_SIZE];
    unsigned songsCount = 0;

public:
    void setSongCount(unsigned count) {
        if (count <= GLOBAL_CONSTANTS::PLAYLIST_SIZE) {
            songsCount = count;
        }
        else {
            std::cout << "Cannot set song count greater than playlist size." << std::endl;
        }
    }

    unsigned getSongCount() const {
        return songsCount;
    }

    void setSongAtIndex(unsigned index, const Song& song) {
        if (index < GLOBAL_CONSTANTS::PLAYLIST_SIZE) {
            songs[index] = song;
        }
        else {
            std::cout << "Index out of range." << std::endl;
        }
    }

    const Song& getSongAtIndex(unsigned index) const {
        if (index < GLOBAL_CONSTANTS::PLAYLIST_SIZE) {
            return songs[index];
        }
        else {
            std::cout << "Index out of range. Returning first song." << std::endl;
            return songs[0];
        }
    }

    void swapSongs(unsigned index1, unsigned index2) {

        Song temp = songs[index1];
        songs[index1] = songs[index2];
        songs[index2] = temp;
    }

    void setKthBitsToOne(unsigned index, int k) {
        if (k < 0 || k > 32) {
            std::cout << "Invalid value of k." << std::endl;
            return;
        }
        songs[index].setKthBitsToOne(k);
    }


};



void setSongGenre(Song& song, const char* genreInput) {
    uint8_t genreSong = 0;

    while (*genreInput) {
        if (*genreInput == 'r' || *genreInput == 'R') {
            genreSong += 1;
        }
        else if (*genreInput == 'p' || *genreInput == 'P') {
            genreSong += 2;
        }
        else if (*genreInput == 'h' || *genreInput == 'H') {
            genreSong += 4;
        }
        else if (*genreInput == 'j' || *genreInput == 'J') {
            genreSong += 8;
        }
        else if (*genreInput == 't' || *genreInput == 'T') {
            genreSong += 16;
        }
        genreInput++;
    }
    
    song.setGenre(genreSong);
}

 char* decimalToBinary(int decimal) {
    char* binary = new char[33] ();
    int i = 0;

    if (decimal == 0) {
        return binary;
    }

    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0'; 
        decimal = decimal / 2;
    }

    if (strlen(binary) % 2 != 0) {
        binary[i++] = '0';
    }


    binary[i] = '\0';

    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }

    return binary;
}

 char* songContentFromBinaryFile(const char* fileName) {
     std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

     if (!ifs.is_open()) {
         std::cerr << "Failed to open file: " << fileName << std::endl;
         return nullptr;
     }

     char ch;
     int songContent = 0;

     while (!ifs.eof()) {
         ifs.get(ch);

         if (!ifs.eof()) {
             songContent = songContent << 8;
             songContent = songContent | (int)ch;
         }
     }

     ifs.close();

     char* songContentResult = decimalToBinary(songContent);
     return songContentResult;
 }

void addSong(Playlist& playlist, const char* songName, const double songLength, const char* genre, const char* fileName) {
    if (playlist.getSongCount() >= GLOBAL_CONSTANTS::PLAYLIST_SIZE) {
        std::cout << "Playlist is full. Cannot add more songs." << std::endl;
        return;
    }

    Song newSong;
    newSong.setSongName(songName);
    newSong.setSongLength(songLength);
    setSongGenre(newSong, genre);

    newSong.setSongContent(songContentFromBinaryFile(fileName));
    playlist.setSongAtIndex(playlist.getSongCount(), newSong);
    playlist.setSongCount(playlist.getSongCount() + 1);
}

void printGenre(const uint8_t& genre) {
    for (size_t i = 0; i < 8; i++) {
        uint8_t mask = 1;
        mask <<= i;
        if ((mask & genre) == mask) {
            switch (mask) {
            case Genre::Rock:
                std::cout << "Rock ";
                break;
            case Genre::Pop:
                std::cout << "Pop ";
                break;
            case Genre::Jazz:
                std::cout << "Jazz ";
                break;
            case Genre::Hiphop:
                std::cout << "Hiphop ";
                break;
            case Genre::Techno:
                std::cout << "Techno ";
                break;
            default:
                std::cout << "Unknown ";
            }
        }
    }
}

void printSong(const Song& song) {
    std::cout << "Song Name: " << song.getSongName() << std::endl;
    std::cout << "Song Length: " << song.getSongLength() << " seconds" << std::endl;
    std::cout << "Genre: ";
    printGenre(song.getGenre());
    std::cout << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void printPlaylist(const Playlist& playlist) {
    for (size_t i = 0; i < playlist.getSongCount(); i++) {
        printSong(playlist.getSongAtIndex(i));
    }
}

bool equalStrings(const char* str1, const char* str2) {
    size_t str1Length = strlen(str1);
    size_t str2Length = strlen(str2);


    if (str1Length != str2Length) {
        return false;
    }

    while (*str1){
        if (*str1 != *str2) {
            return false;
        }

        str1++;
        str2++;
    }


    return true;
}

void printSongByGivenName(const char* songName,const Playlist playlist) {

    for (size_t i = 0; i < playlist.getSongCount(); i++) {
        if (equalStrings(playlist.getSongAtIndex(i).getSongName(), songName)) {
            std::cout << "The song that you are looking for is at index: " << i << std::endl;
            printSong(playlist.getSongAtIndex(i));
            return;
        }
    }

    std::cout << "There is no song with that name in this playlist!" << std::endl;
}

void printSongByGivenGenre(const Genre& genre,const Playlist playlist) {
    std::cout << "Here are all the "; 
    printGenre(genre);
    std::cout<<" songs in the playlist!" << std::endl;

   for (size_t i = 0; i < playlist.getSongCount(); i++) {
       if ((playlist.getSongAtIndex(i).getGenre() & genre)  == genre ) {
           printSong(playlist.getSongAtIndex(i));
           return;
       }
   }
}

void sortBySongLength( Playlist& playlist) {
        for (size_t i = 0; i < playlist.getSongCount() - 1; i++) {
 
          size_t  min_idx = i;

            for (size_t j = i + 1; j < playlist.getSongCount(); j++) {
                if (playlist.getSongAtIndex(j).getSongLength() < playlist.getSongAtIndex(min_idx).getSongLength())
                    min_idx = j;
            }
            if (min_idx != i) {
               playlist.swapSongs(min_idx, i);
               //  playlist.swapSongs(playlist.getSongAtIndex(min_idx), playlist.getSongAtIndex(i));
            }
                
        }
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 'a' - 'A';
    }


    return ch;
}

bool isAlphabeticallyPre(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        char c1 = toLower(*str1);
        char c2 = toLower(*str2);

        if (c1 < c2) {
            return true;
        }
        else if (c1 > c2) {
            return false;
        }

        str1++;
        str2++;
    }

    return (strlen(str1) < strlen(str2));
}

void sortByName(Playlist& playlist) {
    for (size_t i = 0; i < playlist.getSongCount() - 1; i++) {

        size_t  min_idx = i;

        for (size_t j = i + 1; j < playlist.getSongCount(); j++) {
            if (isAlphabeticallyPre(playlist.getSongAtIndex(min_idx).getSongName(),playlist.getSongAtIndex(j).getSongName()))
                min_idx = j;
        }
        if (min_idx != i) {
            playlist.swapSongs(min_idx, i);
        }

    }
}

int main() {
    Playlist playlist;


    addSong(playlist, "First Song", 190, "rp", "file1.dat");
    addSong(playlist, "Second Song", 180, "ph", "file2.dat");


    printPlaylist(playlist);
   // decimalToBinary( playlist.getSongAtIndex(1).getSongContent());
    std::cout << playlist.getSongAtIndex(1).getSongContent() << std::endl;;
    playlist.setKthBitsToOne(1, 3);
    std::cout << playlist.getSongAtIndex(1).getSongContent();
   // decimalToBinary(playlist.getSongAtIndex(1).getSongContent());

   //std::cout<< playlist.getSongAtIndex(0).getSongContent();

  //  printSongByGivenName("First Song", playlist);

   // printSongByGivenGenre(Genre::Hiphop,playlist);

   // sortByName(playlist);

  //  printPlaylist(playlist);

  /* playlist.setKthBitsToOne(0, 3);
   std::cout << playlist.getSongAtIndex(0).getSongContent();*/
   // Song& song1 = playlist.getSongAtIndex(0);


   // playlist.getSongAtIndex(0).set

    return 0;
}
