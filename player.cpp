#include<iostream>
#include<string.h>
using namespace std;
class Player
{
	int jersey_no;
	char name[50];
	int runs;
	int wickets;
	int no_of_matches;
	static Player* p[100]; // Static array to hold player pointers
    static int n; // Static variable to track number of players
    
	public:
	Player()
	{
		this->jersey_no = 0;
        strcpy(this->name, "Not Given");
        this->runs = 0;
        this->wickets = 0;
        this->no_of_matches = 0;
	}
	Player(int jersey, const char* player_name, int player_runs, int player_wickets, int matches_played)
    {
        this->jersey_no = jersey;
        strcpy(this->name, player_name);
        this->runs = player_runs;
        this->wickets = player_wickets;
        this->no_of_matches = matches_played;
    }
    void setJerseyNo(int a)
    {
    	this->jersey_no = a;
	}
	int getJerseyNo()
	{
		return this->jersey_no;
	}
	void setName(char* player_name)
	{
		strcpy(name,player_name);
	}
	char* getName()
	{
		return this->name;
	}
	void setRuns(int b)
	{
		this->runs = b;
	}
	int  getRuns()
	{
		return this->runs;
	}
	void setWickets(int c)
	{
		this->wickets=c;		
	}
	int getWickets()
	{
		return this->wickets;
	}
	void setMatchesPlayed(int d)
	{
		this->no_of_matches = d;
	}
	int getMatchesPlayed()
	{
		return this->no_of_matches;
	}
		
	void display()
	{
		cout<<"*---------------------------------------------*"<<"\n";
		cout<<jersey_no<<"  is the jersey number of  player."<<"\n";
		cout<<name<<"  is the name  of player."<<"\n";	
		cout<<runs<<"  is the runs of  player. "<<"\n";
		cout<<wickets<<"  is the wickets of player. "<<"\n";
		cout<<no_of_matches<<"  is the number of matches of player. "<<"\n";
		cout<<"*---------------------------------------------*"<<"\n";
		
	}
	void searchByJersey_Number(int jersey_number)
	{
		if(getJerseyNo() == jersey_number)
		{
			cout<<"Player found.......:)\n";
			display();
		}
		
	}
		
	void searchByName(char* name)
	{
		
		if(strcmp(getName(),name) == 0)
		{
			cout<<"Player found.......:)\n";
			display();
		}
	}
	void findbyMaxRuns()
	{
	    if (n == 0) {
	        cout << "No players in the team." << endl;
	        return;
	    }
	
	    int max_runs = 0;
	    Player* max_runs_player = NULL;
	    for (int i = 0; i < n; i++) {
	        if (p[i]->getRuns() > max_runs) {
	            max_runs = p[i]->getRuns();
	            max_runs_player = p[i];
	        }
	    }
	
	    if (max_runs_player != NULL) {
	        cout << "Player with maximum runs: " << endl;
	        max_runs_player->display();
	    }
	}
	
	void findbyMaxWickets()
	{
	    if (n == 0) {
	        cout << "No players in the team." << endl;
	        return;
	    }
	
	    int max_wickets = 0;
	    Player* max_wickets_player = NULL;
	    for (int i = 0; i < n; i++) {
	        if (p[i]->getWickets() > max_wickets) {
	            max_wickets = p[i]->getWickets();
	            max_wickets_player = p[i];
	        }
	    }
	
	    if (max_wickets_player != NULL) {
	        cout << "Player with maximum wickets: " << endl;
	        max_wickets_player->display();
	    }
	}

	void updatePlayers(int jersey_no,int runs, int wickets, int no_of_matches)
	{
		for(int i = 0; i < n; i++) {
            if(p[i]->getJerseyNo() == jersey_no) {
                p[i]->setRuns(runs);
                p[i]->setWickets(wickets);
                p[i]->setMatchesPlayed(no_of_matches);
                cout << "Player stats updated successfully." << endl;
                display();
                return;
            }
        }
        cout << "Player not found with the given jersey number." << endl;
	}
	void deletePlayers(int jersey_no)
	{
		for(int i = 0; i < n; i++) {
            if(p[i]->getJerseyNo() == jersey_no) {
                delete p[i];
                for(int j = i; j < n-1; j++)
                    p[j] = p[j+1];
                n--;
                cout << "Player deleted successfully." << endl;
                return;
            }
        }
        cout << "Player not found with the given jersey number." << endl;
	}
	void displayByTopRuns()
	{
		 for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(p[j]->getRuns() < p[j+1]->getRuns()) {
                    Player* temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
        // Display top players by runs
        cout << "Top Players by Runs:" << endl;
        for(int i = 0; i < n; i++)
            p[i]->display();
	}
};

Player* Player::p[100]; // Initialize static array
int Player::n = 0; // Initialize static variable

int main()
{
	Player* p[4];
	p[0] = new Player{1,"Sachin", 100, 7,4};
	p[1] = new Player{2, "Shubhman", 340, 3, 5};
	p[2] = new Player{3, "Rishabh", 440, 6, 2};
	p[3] = new Player{4, "Ishan",560 ,5, 3};
	
	int  n = 4;
	int choice;
	do
	{
		cout << "\nMenu:\n";
        cout << "1. Display Team\n";
        cout << "2. Search by Jersey Number\n";
        cout << "3. Search by Name\n";
        cout << "4. Find Players with Maximum Runs\n";
        cout << "5. Find Players with Maximum Wickets\n";
        cout << "6. Update Player Stats\n";
        cout << "7. Delete Player\n";
        cout << "8. Display Top Players by Runs\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		
		switch(choice )
		{
			case 1:
				for(int i = 0 ;i < n; i++)
				p[i]->display();
				break;
			case 2:
				int jersey_no;
            	cout << "Enter the jersey number: ";
            	cin >> jersey_no;
            	for(int i = 0; i < n;i++)
            	p[i]->searchByJersey_Number(jersey_no);
				break;
			case 3:
				char name[20];
            	cout << "Enter the name: ";
            	cin >> name;
            	for(int i = 0; i < n;i++)
				p[i]->searchByName(name);
				break;
			case 4:
                p[0]->findbyMaxRuns();
                break;
            case 5:
                p[0]->findbyMaxWickets();
                break;
            case 6:
                int upd_jersey, upd_runs, upd_wickets, upd_matches;
                cout << "Enter jersey number to update: ";
                cin >> upd_jersey;
                cout << "Enter new runs: ";
                cin >> upd_runs;
                cout << "Enter new wickets: ";
                cin >> upd_wickets;
                cout << "Enter new matches played: ";
                cin >> upd_matches;
                p[0]->updatePlayers(upd_jersey, upd_runs, upd_wickets, upd_matches);
                break;
            case 7:
                int del_jersey;
                cout << "Enter jersey number to delete: ";
                cin >> del_jersey;
                p[0]->deletePlayers(del_jersey);
                break;
            case 8:
                p[0]->displayByTopRuns();
                break;
			case 9:
				cout<<"Exit Program.........:) ";
				break;
			default:
				cout<<"Invalid choice";
				break;
				
				
		}
	}while(choice != 9);
	

	return 0;
}

