#include <iostream>
#include <cstdlib>
// #include <ctime>

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

enum enChoices
{
    stone = 1,
    paper = 2,
    scissors = 3
};

struct stPlayer
{
    enChoices choice;
    int wins = 0;
    int losses = 0;
    int draws = 0;
};

struct stPlayersInfo
{
    stPlayer player1;
    stPlayer computer;
};

int ReadNumberOfRounds()
{
    int numberOfRound = 0;

    do
    {
        cout << "\nHow Many Rounds You Want Play (From 1 To 10): ";
        cin >> numberOfRound;
    } while (numberOfRound <= 0 || numberOfRound > 10);

    return numberOfRound;
}

enChoices PlyerChoicesInterface()
{
    int choice = 0;

    cout << "Choices:" << endl;
    cout << "1: Stone." << endl;
    cout << "2: Paper." << endl;
    cout << "3: Scissors." << endl;
    cout << "Please, enter Your Choice: ";
    cin >> choice;

    return (enChoices)choice;
}

enChoices ComputerChoiceRandomNumber1To3()
{
    return (enChoices)((rand() % 3) + 1);
}

stPlayersInfo WinnerOfRound(int roundNumber, stPlayersInfo plyers)
{
    cout << "\n-------------------------- ROUND - " << roundNumber << " ------------------------------" << endl;

    if (plyers.player1.choice == enChoices::stone)
    {
        if (plyers.computer.choice == enChoices::stone)
        {
            cout << "Plyer Choice: Stone" << endl;
            cout << "Computer Choice: Stone" << endl;
            cout << "Round Winner: [No Winner]" << endl;

            plyers.player1.draws++;
            plyers.computer.draws++;
        }
        else if (plyers.computer.choice == enChoices::paper)
        {
            cout << "Plyer Choice: Stone" << endl;
            cout << "Computer Choice: Paper" << endl;
            cout << "Round Winner: [Computer]" << endl;

            plyers.computer.wins++;
        }
        else if (plyers.computer.choice == enChoices::scissors)
        {
            cout << "Plyer Choice: Stone" << endl;
            cout << "Computer Choice: Scissors" << endl;
            cout << "Round Winner: [Plyer]" << endl;

            plyers.player1.wins++;
        }
    }
    else if (plyers.player1.choice == enChoices::paper)
    {
        if (plyers.computer.choice == enChoices::stone)
        {
            cout << "Plyer Choice: Paper" << endl;
            cout << "Computer Choice: Stone" << endl;
            cout << "Round Winner: [Plyer]" << endl;

            plyers.player1.wins++;
        }
        else if (plyers.computer.choice == enChoices::paper)
        {
            cout << "Plyer Choice: Paper" << endl;
            cout << "Computer Choice: Paper" << endl;
            cout << "Round Winner: [No Winner]" << endl;

            plyers.player1.draws++;
            plyers.computer.draws++;
        }
        else if (plyers.computer.choice == enChoices::scissors)
        {
            cout << "Plyer Choice: Paper" << endl;
            cout << "Computer Choice: Scissors" << endl;
            cout << "Round Winner: [Computer]" << endl;

            plyers.computer.wins++;
        }
    }
    else if (plyers.player1.choice == enChoices::scissors)
    {
        if (plyers.computer.choice == enChoices::stone)
        {
            cout << "Plyer Choice: Scissors" << endl;
            cout << "Computer Choice: Stone" << endl;
            cout << "Round Winner: [Computer]" << endl;

            plyers.computer.wins++;
        }
        else if (plyers.player1.choice == enChoices::paper)
        {
            cout << "Plyer Choice: Scissors" << endl;
            cout << "Computer Choice: Paper" << endl;
            cout << "Round Winner: [Plyer]" << endl;

            plyers.player1.wins++;
        }
        else if (plyers.player1.choice == enChoices::scissors)
        {
            cout << "Plyer Choice: Scissors" << endl;
            cout << "Computer Choice: Scissors" << endl;
            cout << "Round Winner: [No Winner]" << endl;

            plyers.player1.draws++;
            plyers.computer.draws++;
        }
    }

    cout << "-------------------------------------------------------------------" << endl;

    return plyers;
}

string GameWinner(stPlayersInfo plyers)
{
    if (plyers.player1.wins > plyers.computer.wins)
    {
        return "Plyer Winner.";
    }
    else if (plyers.computer.wins > plyers.player1.wins)
    {
        return "Computer Winner.";
    }
    else
    {
        return "No Winner";
    }
}

void GameResults(int numberOfRounds, stPlayersInfo plyers)
{
    cout << "__________________________________________________________" << endl;
    cout << "\n                   Game Over                            " << endl;
    cout << "__________________________________________________________" << endl;
    cout << "\n________________[Game Results]____________________________" << endl;
    cout << "Game Rounds: " << numberOfRounds << endl;
    cout << "Plyer Winner Items: " << plyers.player1.wins << endl;
    cout << "Computer Winner Items: " << plyers.computer.wins << endl;
    cout << "Drow Items: " << plyers.player1.draws << endl;
    cout << "Final Winner: " << GameWinner(plyers) << endl;
    cout << "__________________________________________________________" << endl;
}

void RepeatRounds(int numberOfRounds)
{
    stPlayersInfo plyers;

    for (int i = 1; i <= numberOfRounds; i++)
    {
        cout << "\nRound " << i << " Begins: \n"
             << endl;

        plyers.player1.choice = PlyerChoicesInterface();
        plyers.computer.choice = ComputerChoiceRandomNumber1To3();

        plyers = WinnerOfRound(i, plyers);
    }

    GameResults(numberOfRounds, plyers);
}

void StartGame()
{
    char answer;

    do
    {
        RepeatRounds(ReadNumberOfRounds());
        cout << "\nDo you play again? (Y | N): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
}

int main()
{
    WelcomeMessage();

    srand(time(0));

    StartGame();

    cout << endl
         << endl;

    return 0;
}