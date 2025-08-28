#include <iostream>

using namespace std;

enum enQuestionsLevel
{
    easyLevel = 1,
    midLevel = 2,
    hardLevel = 3,
    mixLevel = 4
};

enum enOperationType
{
    addition = 1,
    subtraction = 2,
    multiplication = 3,
    division = 4,
    mixOperation = 5
};

struct stQuestion
{
    int number1 = 0;
    int number2 = 0;
    enOperationType operationType;
    enQuestionsLevel questionLevel;
    int correctAnswer = 0;
    int plyerAnswer = 0;
    bool answerResult = false;
};

struct stQuiz
{
    stQuestion questionList[100];
    short numberOfQuestions = 0;
    enOperationType operationType;
    enQuestionsLevel questionsLevel;
    short numberOfRightAnswers = 0;
    short numberOfWrongAnswers = 0;
    bool isPass = false;
};

void ResetScreen()
{
    system("cls");
}

void WelcomeMessage()
{
    ResetScreen();

    cout << "\nWelcome to the Project - Math Game (Version 3) ..\n"
         << endl;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
    short numberOfQuestions = 0;
    do
    {
        cout << "How many questions do you want to answer: ";
        cin >> numberOfQuestions;
    } while (numberOfQuestions < 1 || numberOfQuestions > 100);

    return numberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short questionsLevel = 0;
    do
    {
        cout << "Please, enter questions level ( 1 - easy, 2 - med, 3 - hard, 4 - mix): ";
        cin >> questionsLevel;
    } while (questionsLevel < 1 || questionsLevel > 4);

    return (enQuestionsLevel)questionsLevel;
}

enOperationType ReadOperationType()
{
    short operationType = 0;
    do
    {
        cout << "Please, enter operation type ( 1 - add, 2 - sub, 3 - mul, 4 - div, 5 - mix): ";
        cin >> operationType;
    } while (operationType < 1 || operationType > 5);

    return (enOperationType)operationType;
}

enOperationType GetRandomOperationType()
{
    short operationType = RandomNumber(1, 4);
    return (enOperationType)operationType;
}

int SimpleCalculator(int number1, int number2, enOperationType operationType)
{
    switch (operationType)
    {
    case enOperationType::addition:
        return number1 + number2;

    case enOperationType::subtraction:
        return number1 - number2;

    case enOperationType::multiplication:
        return number1 * number2;

    case enOperationType::division:
        return number1 / number2;

    default:
        return number1 + number2;
    }
}

stQuestion GenerateQuestion(enQuestionsLevel questionsLevel, enOperationType operationType)
{
    stQuestion question;

    if (questionsLevel == enQuestionsLevel::mixLevel)
    {
        questionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }

    if (operationType == enOperationType::mixOperation)
    {
        operationType = GetRandomOperationType();
    }

    question.operationType = operationType;

    switch (questionsLevel)
    {
    case easyLevel:
        question.number1 = RandomNumber(1, 10);
        question.number2 = RandomNumber(1, 10);

        question.correctAnswer = SimpleCalculator(question.number1, question.number2, question.operationType);
        question.questionLevel = questionsLevel;
        return question;

    case midLevel:
        question.number1 = RandomNumber(1, 50);
        question.number2 = RandomNumber(1, 50);

        question.correctAnswer = SimpleCalculator(question.number1, question.number2, question.operationType);
        question.questionLevel = questionsLevel;
        return question;

    case hardLevel:
        question.number1 = RandomNumber(1, 50);
        question.number2 = RandomNumber(1, 50);

        question.correctAnswer = SimpleCalculator(question.number1, question.number2, question.operationType);
        question.questionLevel = questionsLevel;
        return question;
    }

    return question;
}

void GenerateQuizQuestions(stQuiz &quiz)
{
    for (short question = 0; question < quiz.numberOfQuestions; question++)
    {
        quiz.questionList[question] = GenerateQuestion(quiz.questionsLevel, quiz.operationType);
    }
}

string GetOperationTypeSymbol(enOperationType operationType)
{
    switch (operationType)
    {
    case enOperationType::addition:
        return "+";
    case enOperationType::subtraction:
        return "-";
    case enOperationType::multiplication:
        return "x";
    case enOperationType::division:
        return "/";
    default:
        return "Mix";
    }
}

void PrintTheQuestion(stQuiz &quiz, short questionNumber)
{
    cout << "\nQuestion [ " << questionNumber + 1 << " / " << quiz.numberOfQuestions << " ]:"
         << endl;
    cout << quiz.questionList[questionNumber].number1 << endl;
    cout << quiz.questionList[questionNumber].number2 << " ";
    cout << GetOperationTypeSymbol(quiz.questionList[questionNumber].operationType);
    cout << "\n----------" << endl;
}

int ReadQuestionAnswer()
{
    int answer = 0;

    cin >> answer;

    return answer;
}

void CorrectTheQuestionAnswer(stQuiz &quiz, short questionNumber)
{
    if (quiz.questionList[questionNumber].plyerAnswer != quiz.questionList[questionNumber].correctAnswer)
    {
        quiz.questionList[questionNumber].answerResult = false;
        quiz.numberOfWrongAnswers++;

        cout << "Wrong Answer" << endl;
        cout << "The Right answer is: ";
        cout << quiz.questionList[questionNumber].correctAnswer << endl;
    }
    else
    {
        quiz.questionList[questionNumber].answerResult = true;
        quiz.numberOfRightAnswers++;
        cout << "Right Answer" << endl;
    }
    cout << endl;
}

void AskAndCorrectQuestionListAnswers(stQuiz &quiz)
{
    for (short questionNumber = 0; questionNumber < quiz.numberOfQuestions; questionNumber++)
    {
        PrintTheQuestion(quiz, questionNumber);

        quiz.questionList[questionNumber].plyerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(quiz, questionNumber);
    }

    quiz.isPass = (quiz.numberOfRightAnswers >= quiz.numberOfWrongAnswers);

    /*
    if (quiz.numberOfRightAnswers >= quiz.numberOfWrongAnswers)
    {
        quiz.isPass = true;
    }
    else
    {
        quiz.isPass = false;
    }
    */
}

string GetFinalResultsText(bool pass)
{
    if (pass)
    {
        return "Pass";
    }
    else
    {
        return "Fail";
    }
}

string GetQuestionLevelText(enQuestionsLevel questionsLevel)
{
    string arrQuestionLevelText[4] = {"Easy", "Mid", "Hard", "Mix"};
    return arrQuestionLevelText[questionsLevel - 1];
}

void PrintQuizResults(stQuiz &quiz)
{
    cout << "\n------------------------------------";
    cout << "\nFinal Results is: " << GetFinalResultsText(quiz.isPass);
    cout << "\n------------------------------------\n";

    cout << "Number of questions: " << quiz.numberOfQuestions << endl;
    cout << "Questions level: " << GetQuestionLevelText(quiz.questionsLevel) << endl;
    cout << "Operation type: " << GetOperationTypeSymbol(quiz.operationType) << endl;
    cout << "Number of right answer: " << quiz.numberOfRightAnswers << endl;
    cout << "Number of wrong answer: " << quiz.numberOfWrongAnswers << endl;

    cout << "------------------------------------\n";
}

void PlayMathGame()
{
    stQuiz quiz;

    quiz.numberOfQuestions = ReadHowManyQuestions();
    quiz.questionsLevel = ReadQuestionsLevel();
    quiz.operationType = ReadOperationType();

    GenerateQuizQuestions(quiz);
    AskAndCorrectQuestionListAnswers(quiz);

    PrintQuizResults(quiz);
}

void StartGame()
{
    char playAgain = 'y';

    do
    {
        WelcomeMessage();
        PlayMathGame();

        cout << "\nDo you want play again? ( Y / N ): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}