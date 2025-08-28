#include <iostream>

using namespace std;

enum enQuestionsLevel
{
    easyLevel = 1,
    medLevel = 2,
    hardLevel = 3,
    mixLevel = 4
};

enum enOperationType
{
    collection = 1,
    subtraction = 2,
    multiply = 3,
    division = 4,
    mix = 5
};

struct stFinalResult
{
    short numberOfQuestions = 0;
    enQuestionsLevel questionsLevel;
    enOperationType operationType;
    short numberOfRightAnswers = 0;
    short numberOfWrongAnswers = 0;
};

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

short HowManyQuestions()
{
    short answer = 0;

    do
    {
        cout << "How many questions do you want answer: ";
        cin >> answer;
    } while (answer <= 0);

    return answer;
}

enQuestionsLevel SelectQuestionsLevel()
{
    short answer = 0;

    cout << "\nQuestions Level: " << endl;
    cout << "1) Easy.\n2) Mid.\n3) Hard.\n4) Mix." << endl;

    do
    {
        cout << "Please, enter questions level [1 - 4]: ";
        cin >> answer;
    } while (answer < 1 || answer > 4);

    return (enQuestionsLevel)answer;
}

enOperationType SelectOperationType()
{
    short answer = 0;

    cout << "\nOperation Type: " << endl;
    cout << "1) Add.\n2) Sub.\n3) Mul.\n4) Div.\n5) Mix." << endl;

    do
    {
        cout << "Please, enter operation type [1 - 5]: ";
        cin >> answer;
    } while (answer < 1 || answer > 5);

    return (enOperationType)answer;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

char GenerateRandomOperationType()
{
    short arr[4] = {42, 43, 45, 47};

    short index = rand() % 4;

    return (char)arr[index];
}

char GenerateOperationType(enOperationType operationType)
{
    switch (operationType)
    {
    case collection:
        return '+';

    case subtraction:
        return '-';

    case multiply:
        return '*';

    case division:
        return '/';

    case mix:
        return GenerateRandomOperationType();
    }

    return 0;
}

short EasyLevelOfQuestions()
{
    return RandomNumber(1, 10);
}

short MedLevelOfQuestions()
{
    return RandomNumber(10, 30);
}

short HardLevelOfQuestions()
{
    return RandomNumber(30, 100);
}

short MixLevelOfQuestions()
{
    return RandomNumber(1, 100);
}

void IsRightAnswer(short userAnswer, short correctAnswer, stFinalResult &finalResult)
{
    cout << "Correct Answer is: " << correctAnswer << endl;

    if (userAnswer == correctAnswer)
    {
        cout << "Your Answer is Right :)" << endl;
        finalResult.numberOfRightAnswers++;
    }
    else
    {
        cout << "Your Answer is Wrong :(" << endl;
        finalResult.numberOfWrongAnswers++;
    }
}

short CheckCollectionNumbers(short firstNumber, short secondNumber)
{
    short result = 0;

    result = firstNumber + secondNumber;

    return result;
}

short CheckSubtractionNumbers(short firstNumber, short secondNumber)
{
    short result = 0;

    result = firstNumber - secondNumber;

    return result;
}

short CheckMultiplyNumbers(short firstNumber, short secondNumber)
{
    short result = 0;

    result = firstNumber * secondNumber;

    return result;
}

short CheckDivisionNumbers(short firstNumber, short secondNumber)
{
    short result = 0;

    result = firstNumber / secondNumber;

    return result;
}

void CheckAnswer(enOperationType operationType, short firstNumber, short secondNumber, short userAnswer, short correctAnswer, stFinalResult &finalResult)
{
    switch (operationType)
    {
    case collection:
        correctAnswer = CheckCollectionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case subtraction:
        correctAnswer = CheckSubtractionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case multiply:
        correctAnswer = CheckMultiplyNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case division:
        correctAnswer = CheckDivisionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;
    }
}

void CheckAnswerForMixOperation(char operationType, short firstNumber, short secondNumber, short userAnswer, short correctAnswer, stFinalResult &finalResult)
{
    switch (operationType)
    {
    case '+':
        correctAnswer = CheckCollectionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case '-':
        correctAnswer = CheckSubtractionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case '*':
        correctAnswer = CheckMultiplyNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;

    case '/':
        correctAnswer = CheckDivisionNumbers(firstNumber, secondNumber);
        IsRightAnswer(userAnswer, correctAnswer, finalResult);
        break;
    }
}

void ScreenOfEndGame(stFinalResult finalResult)
{
    cout << "\n-----------------------------------------" << endl;
    if (finalResult.numberOfRightAnswers > finalResult.numberOfWrongAnswers)
    {
        cout << "Final results is pass." << endl;
    }
    else
    {
        cout << "Final results is fail." << endl;
    }
    cout << "-----------------------------------------" << endl;

    cout << "Number of questions: " << finalResult.numberOfQuestions << endl;

    switch (finalResult.questionsLevel)
    {
    case easyLevel:
        cout << "Questions level: Easy" << endl;
        break;

    case medLevel:
        cout << "Questions level: Med" << endl;
        break;

    case hardLevel:
        cout << "Questions level: Hard" << endl;
        break;

    case mixLevel:
        cout << "Questions level: Mix" << endl;
        break;
    }

    switch (finalResult.operationType)
    {
    case collection:
        cout << "Operation type: Collection" << endl;
        break;

    case subtraction:
        cout << "Operation type: Subtraction" << endl;
        break;

    case multiply:
        cout << "Operation type: Multiply" << endl;
        break;

    case division:
        cout << "Operation type: Division" << endl;
        break;

    case mix:
        cout << "Operation type: Mix" << endl;
        break;
    }

    cout << "Number of right answers: " << finalResult.numberOfRightAnswers << endl;
    cout << "Number of wrong answers: " << finalResult.numberOfWrongAnswers << endl;

    cout << "-----------------------------------------" << endl;
}

void PlayGame()
{
    WelcomeMessage();

    char playAgain = 'y';
    do
    {

        stFinalResult finalResult;

        short numberOfQuestions = HowManyQuestions();
        enQuestionsLevel questionLevel = SelectQuestionsLevel();
        enOperationType operationType = SelectOperationType();
        short firstNumber = 0, secondNumber = 0, correctAnswer = 0, userAnswer = 0;

        finalResult.numberOfQuestions = numberOfQuestions;
        finalResult.questionsLevel = questionLevel;
        finalResult.operationType = operationType;

        for (short question = 1; question <= numberOfQuestions; question++)
        {
            cout << "\nQuestion [" << question << " / " << numberOfQuestions << " ]:" << endl;

            switch (questionLevel)
            {
            case easyLevel:
                firstNumber = EasyLevelOfQuestions();
                secondNumber = EasyLevelOfQuestions();
                cout << firstNumber << " " << GenerateOperationType(operationType) << " " << secondNumber << ": ";
                cin >> userAnswer;
                CheckAnswer(operationType, firstNumber, secondNumber, userAnswer, correctAnswer, finalResult);
                break;

            case medLevel:
                firstNumber = MedLevelOfQuestions();
                secondNumber = MedLevelOfQuestions();
                cout << firstNumber << " " << GenerateOperationType(operationType) << " " << secondNumber << ": ";
                cin >> userAnswer;
                CheckAnswer(operationType, firstNumber, secondNumber, userAnswer, correctAnswer, finalResult);
                break;

            case hardLevel:
                firstNumber = HardLevelOfQuestions();
                secondNumber = HardLevelOfQuestions();
                cout << firstNumber << " " << GenerateOperationType(operationType) << " " << secondNumber << ": ";
                cin >> userAnswer;
                CheckAnswer(operationType, firstNumber, secondNumber, userAnswer, correctAnswer, finalResult);
                break;

            case mixLevel:
                firstNumber = MixLevelOfQuestions();
                secondNumber = MixLevelOfQuestions();
                char mixOperationType = GenerateOperationType(operationType);
                cout << firstNumber << " " << mixOperationType << " " << secondNumber << ": ";
                cin >> userAnswer;
                CheckAnswerForMixOperation(mixOperationType, firstNumber, secondNumber, userAnswer, correctAnswer, finalResult);
                break;
            }
        }

        ScreenOfEndGame(finalResult);

        cout << "Do you play again ( Y / N ): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    PlayGame();

    cout << endl
         << endl;

    return 0;
}