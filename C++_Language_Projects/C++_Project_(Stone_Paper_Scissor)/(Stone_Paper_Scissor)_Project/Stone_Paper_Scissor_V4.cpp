#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//* Enums

enum enGameChoice
{
    stone = 1,
    paper = 2,
    scissors = 3
};

enum enWinner
{
    player1 = 1,
    computer = 2,
    draw = 3
};

//* End Enums

//* Structs

struct stRoundInfo
{
    short roundNumber = 0;
    enGameChoice player1Choice;
    enGameChoice computerChoice;
    enWinner winner;
    string winnerName;
};

struct stGameResults
{
    short gameRounds = 0;
    short player1WinTimes = 0;
    short computer2WinTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName = "";
};

//* End Structs

//* Functions

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

short ReadHowManyRounds()
{
    short gameRounds = 1;

    do
    {
        cout << "How Many Rounds 1 to 10: ";
        cin >> gameRounds;
    } while (gameRounds < 1 || gameRounds > 10);

    return gameRounds;
}

enGameChoice ReadPlayer1Choice()
{
    short choice = 1;

    do
    {
        cout << "\nYour choice: [1]-Stone, [2]-Paper, [3]-Scissors: ";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    return (enGameChoice)choice;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo roundInfo)
{
    if (roundInfo.player1Choice == roundInfo.computerChoice)
    {
        return enWinner::draw;
    }

    switch (roundInfo.player1Choice)
    {
    case enGameChoice::stone:
        if (roundInfo.computerChoice == enGameChoice::paper)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::paper:
        if (roundInfo.computerChoice == enGameChoice::scissors)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::scissors:
        if (roundInfo.computerChoice == enGameChoice::stone)
        {
            return enWinner::computer;
        }
        break;
    }

    return enWinner::player1;
}

string WinnerName(enWinner winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerName[winner - 1];
}

string ChoiceName(enGameChoice choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};

    return arrGameChoices[choice - 1];
}

void PrintRoundResults(stRoundInfo roundInfo)
{
    cout << "\n____________ Round [" << roundInfo.roundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(roundInfo.player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(roundInfo.computerChoice) << endl;
    cout << "Round Winner   : [" << roundInfo.winnerName << "]\n";
    cout << "_________________________________________\n"
         << endl;
}

enWinner WhoWonTheGame(short player1WinTimes, short computerWinTimes)
{
    if (player1WinTimes > computerWinTimes)
    {
        return enWinner::player1;
    }
    else if (computerWinTimes > player1WinTimes)
    {
        return enWinner::computer;
    }
    else
    {
        return enWinner::draw;
    }
}

stGameResults FillGameResults(short gameRounds, short player1WinTimes, short computerWinTimes, short drawTimes)
{
    stGameResults gameResults;

    gameResults.gameRounds = gameRounds;
    gameResults.player1WinTimes = player1WinTimes;
    gameResults.computer2WinTimes = computerWinTimes;
    gameResults.drawTimes = drawTimes;
    gameResults.gameWinner = WhoWonTheGame(player1WinTimes, computerWinTimes);
    gameResults.winnerName = WinnerName(gameResults.gameWinner);

    return gameResults;
}

stGameResults PlayGame(short howManyRounds)
{

    stRoundInfo roundInfo;
    short player1WinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (short gameRound = 1; gameRound <= howManyRounds; gameRound++)
    {
        cout << "\nRound [" << gameRound << "] begins:\n";
        roundInfo.roundNumber = gameRound;
        roundInfo.player1Choice = ReadPlayer1Choice();
        roundInfo.computerChoice = GetComputerChoice();
        roundInfo.winner = WhoWonTheRound(roundInfo);
        roundInfo.winnerName = WinnerName(roundInfo.winner);

        if (roundInfo.winner == enWinner::player1)
        {
            player1WinTimes++;
        }
        else if (roundInfo.winner == enWinner::computer)
        {
            computerWinTimes++;
        }
        else
        {
            drawTimes++;
        }

        PrintRoundResults(roundInfo);
    }

    return FillGameResults(howManyRounds, player1WinTimes, computerWinTimes, drawTimes);
}

// string Tabs(short numberOfTabs)
// {
//     string t = "";
//     for (short i = 1; i < numberOfTabs; i++)
//     {
//         t = t + "\t";
//         cout << t;
//     }
//     return t;
// }

void ShowGameOverScreen()
{
    cout << "--------------------------------------------------------\n";
    cout << "              +++ Game Over +++\n";
    cout << "--------------------------------------------------------\n\n";
}

void ShowFinalGameResults(stGameResults gameResults)
{
    cout << "------------------- [ Game Results ] -------------------\n\n";
    cout << "Game Round                  : " << gameResults.gameRounds << endl;
    cout << "Player 1 Win Times          : " << gameResults.player1WinTimes << endl;
    cout << "Computer Win Times          : " << gameResults.computer2WinTimes << endl;
    cout << "Draw Times                  : " << gameResults.drawTimes << endl;
    cout << "Final Winner                : " << gameResults.winnerName << endl;
    cout << "--------------------------------------------------------\n\n";
}

void ResetScreen()
{
    system("cls");
}

void StartGame()
{
    char playAgain = 'y';

    do
    {
        ResetScreen();
        WelcomeMessage();
        stGameResults gameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(gameResults);

        cout << endl
             << "Do you want to play again ? ( y / n ): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

//* End Functions

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}