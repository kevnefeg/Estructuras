#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct canciones
{
    string title;
    string artist;
    string genre;
    float time;
};
struct canciones songs;


void menu(queue<canciones> songshappy,queue<canciones> songssad,queue<canciones> songsstudy)
{
    int option1;
    int option2;
    int option3;
    int option4;
    bool status = true;

    while (status)
    {
        cout<<"\n WELCOME TO  NEFEG C++ MUSIC \n ";
        cout<<"\n  What is your mood today?   \n";
        cout<<"\n 1. My mood is happy \n";
        cout<<"\n 2. My mood is sad \n";
        cout<<"\n 3. My mood is time to study \n";
        cin>>option1;


        switch (option1)
        {
        case 1:
        cout<<"1. Add to happy playlist \n";
        cout<<"2. Delete one happy song \n";
        cout<<"3. Delete all happy songs  \n";
        cout<<"4. Display happy songs  \n";
        cin>>option2;
            break;
        case 2:
        cout<<"\n1. Add to sad playlist \n";
        cout<<"2. Delete one sad song \n";
        cout<<"3. Delete all sad songs \n";
        cout<<"4. Display all sad songs \n";
        cin>>option3;
            break;
        case 3:
        cout<<"\n1. Add to Study Playlist \n";
        cout<<"2. Delete one study song \n";
        cout<<"3. Delete all study songs \n";
        cout<<"4. Display all study songs \n";
        cin>>option4;
            break;
        default:
            break;
        }
        switch (option2,option3,option4)
        {
        case 1:
        cin.ignore();
            cout<<"Type the title of the song \n";
            getline(cin,songs.title);
            cout<<"Type the artist  \n";
            getline(cin,songs.artist);
            cout<<"Type the genre \n";
            getline(cin,songs.genre);
        do
        {
            cout<<"Type the time  \n";
            cin>>songs.time;
        } while (songs.time<0);
         
        if (option2)
        {
            songshappy.push(songs);
        }
        else if (option3)
        {
            songssad.push(songs);
        }
        else
        {
            songsstudy.push(songs);
        }
        
        
        
            
            break;
        case 2:
        songshappy.pop();
        break;
        case 3:
         while (!songshappy.empty())
            {
                songshappy.pop();
            }
            cout<<"\nNo more songs\n";
        break;

        case 4:
        //showhappy(songshappy);
        default:
            break;
        }

    }
    
}


int main()
{
     queue<canciones> songshappy;
    queue<canciones> songssad;
    queue<canciones> songsstudy;

    menu(songshappy,songssad,songsstudy);
}