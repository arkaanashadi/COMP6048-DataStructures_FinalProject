#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>


using namespace std;

struct Movie
{
    string title,director,main_actor;
    int action, comedy, romance, thriller, sci_fi, horror, fantasy;
    
    Movie(){}
    
    Movie(string title, string director, string main_actor, int action, int comedy, int romance, int thriller, int sci_fi, int horror, int fantasy)
    {
        this -> title      = title;
        this -> director   = director;
        this -> main_actor = main_actor;
        this -> action     = action;
        this -> comedy     = comedy;
        this -> romance    = romance;
        this -> thriller   = thriller;
        this -> sci_fi     = sci_fi;
        this -> horror     = horror;
        this -> fantasy    = fantasy;
    }
    
    void printall()
    {
        cout<<"Title:\t\t"<<this->title<<endl;
        cout<<"Director:\t"<<this->director<<endl;
        cout<<"Main Actors:\t"<<main_actor<<endl;
    }
    
    string getTitle()
    {
        return this -> title;
    }
    
    string getDirector()
    {
    	return this -> director;
	}
	
	string getActors()
	{
		return this -> main_actor;
	}
	
    int getWeight(char genre)
    {
        switch (genre)
        {
            case 'A': // genre Action
                return this -> action;
            case 'C': // genre Comedy
                return this -> comedy;
            case 'R': // genre Romance
                return this -> romance;
            case 'H': // genre Horror
                return this -> horror;
            case 'T': // genre Thriller
                return this -> thriller;
            case 'S': // genre Sci-Fi
                return this -> sci_fi;
            case 'F': // genre Fantasy
                return this -> fantasy;
            default:
                cout<<"Error, invalid genre";
                return 0;
        }
    }
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void genretsort(vector<Movie>& movielist)
{
    cout<<"Please select a genre to sort"<<endl;
    cout<<"1. Action"<<endl<<"2. Comedy"<<endl<<"3. Romance"<<endl<<"4. Horror"<<endl<<"5. Thriller"<<endl<<"6. Sci-Fi"<<endl<<"7. Fantasy"<<endl;
    string selection;
    cout<<">> "; getline(cin, selection);
    transform(selection.begin(), selection.end(), selection.begin(), ::tolower);
    
    char genre;
    
    if(selection == "1" || selection == "action") 
        genre = 'A';
        
    else if(selection == "2" || selection == "comedy")
        genre = 'C';
        
    else if(selection == "3" || selection == "romance")
        genre = 'R';
    
    else if(selection == "4" || selection == "horror")
        genre = 'H';
    
    else if(selection == "5" || selection == "thriller")
        genre = 'T';
    
    else if(selection == "6" || selection == "sci-fi")
        genre = 'S';
    
    else if(selection == "7" || selection == "fantasy")
        genre = 'F';
    
    else
    {
        cout<<"Invalid genre"<<endl;
    }
    
    Movie current;
    int indexer;
    
    for(int index = 1; index < movielist.size(); index++)
    {
        current = movielist[index];
        indexer = index-1;
        while (indexer >= 0 && current.getWeight(genre) > movielist[indexer].getWeight(genre))
        {
            movielist[indexer+1] = movielist[indexer];
            indexer--;
        }
        movielist[++indexer] = current;
    }
}

void printmovies(vector<Movie>& movielist, string command)
{
    for (int index = 0; index < movielist.size(); index++)
    {
        if(command == "all")
        {
            movielist[index].printall();
            cout<<endl;
        }
        else if(command == "title")
            cout<<index+1<<". ["<<movielist[index].getTitle()<<"] "<<endl;
        else 
        {
            cout<<"Error, invalid command";
        }
    }
}

vector<string> split(string sentence, char delimiter){
    string word;
    stringstream tokenize(sentence);
    vector<string> tokens;
    while (getline(tokenize, word, ' ')) {
        tokens.push_back(word);
    }
    return tokens;
}

void searchmovies(vector<Movie>& movielist)
{
	cout<<"Please input a title"<<endl;
	string s;
	cout<<">> ";
    getline(cin, s);
    cout<<endl;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    vector<string> keywords;
    keywords = split(s, ' ');

    vector<int> matched_indexes;

    for (int movie_index = 0; movie_index < movielist.size(); movie_index++)
    {   
        string movie_title;
        movie_title = movielist[movie_index].getTitle();

        transform(movie_title.begin(), movie_title.end(), movie_title.begin(), ::tolower);

        vector<string> title_tokens;
        title_tokens = split(movie_title, ' ');
        
        if(title_tokens.size() < keywords.size())
            continue;
            
        int matches = 0;
        for(int keyword_index = 0; keyword_index < keywords.size(); keyword_index++)
//            cout<<keywords[keyword_index]<<" "<<title_tokens[keyword_index]<<endl;
            if(title_tokens[keyword_index] == keywords[keyword_index])
//                cout<<matches<<endl;
                matches++;
                
        if(matches == keywords.size())
            matched_indexes.push_back(movie_index);
    }
    
    if(matched_indexes.size() > 0)
    {
        cout<<"Movie titles containing: \""<<s<<"\"\n\n";
        for(int match_index = 0; match_index < matched_indexes.size(); match_index++)
        {
            movielist[matched_indexes[match_index]].printall();
            cout<<endl;
            
        }
        return;
    }
    
	cout<<"Not Found!\n"<<endl;
}

void addmovies(vector<Movie>& movielist)
{
    cout<<"Please input title"<<endl;
    	string title;
    	cout<<">> "; getline(cin, title);
        
    	cout<<"Please input Director's name"<<endl;
    	string director;
    	cout<<">> "; getline(cin, director);

    	cout<<"Please input main Actor"<<endl;
    	string main_actor;
    	cout<<">> "; getline(cin, main_actor);

        cout<<"Please input the weight value for action (0-7)"<<endl;
        int action;
        cout<<">> "; cin>>action;
        
        cout<<"Please input the weight value for comedy (0-7)"<<endl;
        int comedy;
        cout<<">> "; cin>>comedy;
        
        cout<<"Please input the weight value for romance (0-7)"<<endl;
        int romance;
        cout<<">> "; cin>>romance;
        
        cout<<"Please input the weight value for thriller (0-7)"<<endl;
        int thriller;
        cout<<">> "; cin>>thriller;
        
        cout<<"Please input the weight value for sci_fi (0-7)"<<endl;
        int sci_fi;
        cout<<">> "; cin>>sci_fi;
        
        cout<<"Please input the weight value for horror (0-7)"<<endl;
        int horror;
        cout<<">> "; cin>>horror;
        
        cout<<"Please input the weight value for fantasy (0-7)"<<endl;
        int fantasy;
        cout<<">> "; cin>>fantasy;
        
        movielist.push_back(Movie(title, director, main_actor, action, comedy, romance, thriller, sci_fi, horror, fantasy));
}

void removemovies(vector<Movie>& movielist)
{
    printmovies(movielist, "title");
    int index;
	cout<<"Which movie would you like  of the movie you want to delete ?"<<endl;
	cin>>index;
    movielist.erase(movielist.begin()+(index-1));
}

static Movie arr[] = {
    Movie("Ready Player One", "Steven Spielberg", "SomeGuy", 1, 2, 3, 4, 5, 6, 7),
    Movie("Die Hard", "John McTiernan", "Bruce Willis", 7, 0, 3, 6, 0, 0, 0),
    Movie("Die Hard 2", "Renny Harlin", "Bruce Willis", 7, 0, 3, 6, 0, 0, 0),
    Movie("Hot Fuzz", "Edgar Wright", "Simon Pegg", 6, 7, 0, 5, 0, 0, 0),
    Movie("Deadpool", "Tim Miller", "Ryan Reynolds", 7, 6, 3, 4, 6, 0, 0),
    Movie("Titanic", "James Cameron", "Leonardo DiCaprio", 0, 0, 7, 4, 0, 0, 0),
    };
    
static int n = sizeof(arr) / sizeof(arr[0]);
static vector<Movie> movies(arr, arr + n);

void mainMenu(vector<Movie>& movielist)
{
    cout<<"Select an option"<<endl;
    cout<<"1. Display all"<<endl<<"2. Search movie"<<endl<<"3. Sort by genre"<<endl<<"4. Add movie"<<endl<<"5. Remove movie"<<endl<<"6. Exit"<<endl;
    
    char selection;
    cout<<">> "; cin>>selection; cout<<endl;
    cin.clear();
    cin.ignore();
    
    switch (selection) {
        
        case '1':

            printmovies(movielist, "all");
            break;
            
        case '2':
			searchmovies(movielist);
			break; 
            
        case '3':
            genretsort(movielist);
            cout<<endl;
            printmovies(movielist, "title");
            cout<<endl;
            break;

        case '4':
            addmovies(movielist);
            break;
            
        case '5':
        	removemovies(movielist);
        	break;
            
        case '6':
            cout<<"Bye";
            exit(0);
            
        default:
            cout<<"Please input the number you would like to select"<<endl;
    }
}

int main(int argc, char *argv[]) {
    while (true) {
        mainMenu(movies);
    }
}
