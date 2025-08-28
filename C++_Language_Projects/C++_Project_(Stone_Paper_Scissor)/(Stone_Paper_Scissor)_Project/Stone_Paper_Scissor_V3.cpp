#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    short computerWinTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName = "";
};

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
        return (roundInfo.computerChoice == enGameChoice::paper) ? enWinner::computer : enWinner::player1;

    case enGameChoice::paper:
        return (roundInfo.computerChoice == enGameChoice::scissors) ? enWinner::computer : enWinner::player1;

    case enGameChoice::scissors:
        return (roundInfo.computerChoice == enGameChoice::stone) ? enWinner::computer : enWinner::player1;
    }
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

string ChoiceName(enGameChoice choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};

    return arrGameChoices[choice - 1];
}

string WinnerName(enWinner winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner (Draw)"};

    return arrWinnerName[winner - 1];
}

enGameChoice ReadPlayer1Choice()
{
    short choice;

    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    return (enGameChoice)choice;
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

    return {howManyRounds, player1WinTimes, computerWinTimes, drawTimes, WhoWonTheGame(player1WinTimes, computerWinTimes), WinnerName(WhoWonTheGame(player1WinTimes, computerWinTimes))};
}

void StartGame()
{
    char playAgain = 'Y';

    do
    {
        system("cls");

        stGameResults gameResults = PlayGame(3);

        cout << "\nGame Over! Winner: " << gameResults.winnerName << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}