

/* >>> Project 1 ( Quiz Game ) <<< */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Functions ..
void welcomeMassageFun();
void startOrEndPlayFun(int startOrEnd, int answer, int score);
void gameRulesFun();
int correctAnswerFun(int score);
int wrongAnswerFun(int score);
int question_1_Fun(int answer, int score);
int question_2_Fun(int answer, int score);
int question_3_Fun(int answer, int score);
int question_4_Fun(int answer, int score);
int question_5_Fun(int answer, int score);
int question_6_Fun(int answer, int score);
int question_7_Fun(int answer, int score);
int question_8_Fun(int answer, int score);
int question_9_Fun(int answer, int score);
int question_10_Fun(int answer, int score);

int main()
{
    welcomeMassageFun();

    int startOrEnd = 0, answer = 0, score = 0;

    startOrEndPlayFun(startOrEnd, answer, score);

    return 0;
}

// Functions ..
// Welcome massage / Function.
void welcomeMassageFun()
{
    printf("\n\nYou welcome in Project 1 ( Quiz Game ) ..\n\n");
}

// Start or end play / Function.
void startOrEndPlayFun(int startOrEnd, int answer, int score)
{
    printf("if you want play, please enter any number / if you can't play, please enter 0: ");
    scanf("%d", &startOrEnd);

    if (startOrEnd != 0)
    {
        gameRulesFun();
        score = question_1_Fun(answer, score);
        score = question_2_Fun(answer, score);
        score = question_3_Fun(answer, score);
        score = question_4_Fun(answer, score);
        score = question_5_Fun(answer, score);
        score = question_6_Fun(answer, score);
        score = question_7_Fun(answer, score);
        score = question_8_Fun(answer, score);
        score = question_9_Fun(answer, score);
        score = question_10_Fun(answer, score);
    }
}

// Game rules // Function.
void gameRulesFun()
{
    printf("\nYou welcome in ( Quiz Game ) ..\n\n");
    printf("Game rules: \n");
    printf("- The game Containing 10 questions Specializing in software engineering ..\n");
    printf("- For each correct answer, 5 points ..\n\n");
    printf("Let's start playing :)\n");
    printf("__________________________________________________________________________\n\n");
}

// Correct Answer / Function.
int correctAnswerFun(int score)
{
    printf("\nCorrect Answer\n");
    score += 5;
    printf("\nScore = %d\n", score);
    printf("__________________________________________________________________________\n\n");

    return score;
}

// Wrong Answer / Function.
int wrongAnswerFun(int score)
{
    printf("\nWrong Answer\n");
    printf("\nScore = %d\n", score);
    printf("__________________________________________________________________________\n\n");

    return score;
}

// Question 1 / Function.
int question_1_Fun(int answer, int score)
{
    printf("Q_1 : Why is learning programming fundamentals important?\n\n");
    printf("A_1 : To lay the foundation for understanding programming concepts and methods.\n");
    printf("A_2 : To produce complex software immediately.\n");
    printf("A_3 : To instantly overcome programming challenges.\n");
    printf("A_4 : To ignore problems in programming.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 2 / Function.
int question_2_Fun(int answer, int score)
{
    printf("Q_2 : What do you learn from programming basics?\n\n");
    printf("A_1 : Graphic design.\n");
    printf("A_2 : Marketing software.\n");
    printf("A_3 : Organizing data, program variables, and control structures.\n");
    printf("A_4 : Designing databases.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 3 / Function.
int question_3_Fun(int answer, int score)
{
    printf("Q_3 : How does learning the basics help in problem-solving?\n\n");
    printf("A_1 : It provides ready-made answers to problems..\n");
    printf("A_2 : It makes you ignore problems..\n");
    printf("A_3 : It makes you rely on others to solve problems..\n");
    printf("A_4 : It teaches you how to break down problems into smaller parts.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 4)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 4 / Function.
int question_4_Fun(int answer, int score)
{
    printf("Q_4 : What do the fundamentals in programming enable you to understand multiple programming languages?\n\n");
    printf("A_1 : Designing visual interfaces.\n");
    printf("A_2 : Control structures, variables, and loops.\n");
    printf("A_3 : Marketing software.\n");
    printf("A_4 : Organizing code documentation.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 5 / Function.
int question_5_Fun(int answer, int score)
{
    printf("Q_5 : What does \"errors and exceptions\" in programming mean?\n\n");
    printf("A_1 : Programming success.\n");
    printf("A_2 : Tips for speeding up programming.\n");
    printf("A_3 : Designing user interfaces.\n");
    printf("A_4 : Issues that arise when the program conflicts with rules.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 4)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 6 / Function.
int question_6_Fun(int answer, int score)
{
    printf("Q_6 : How can understanding the fundamentals help in evaluating other people's code?\n\n");
    printf("A_1 : It enables you to assess quality, efficiency, and security.\n");
    printf("A_2 : It makes you work solo.\n");
    printf("A_3 : It has no impact on team collaboration.\n");
    printf("A_4 : It makes you ignore team members.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 7 / Function.
int question_7_Fun(int answer, int score)
{
    printf("Q_7 : What does a proper understanding of programming basics mean?\n\n");
    printf("A_1 : Mastering all programming languages.\n");
    printf("A_2 : The ability to build and comprehend simple programs.\n");
    printf("A_3 : Relying solely on copy-paste.\n");
    printf("A_4 : Reducing the utilization of programming resources.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 8 / Function.
int question_8_Fun(int answer, int score)
{
    printf("Q_8 : How does understanding the basics contribute to improving coding skills?\n\n");
    printf("A_1 : It reduces the enjoyment of learning programming.\n");
    printf("A_2 : It doesn't affect teamwork capabilities.\n");
    printf("A_3 : It enables logical thinking and the creation of efficient solutions.\n");
    printf("A_4 : It leads to increased programming complexity without tangible benefits.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 9 / Function.
int question_9_Fun(int answer, int score)
{
    printf("Q_9 : How does mastering the fundamentals help in team collaboration?\n\n");
    printf("A_1 : It enhances communication and cooperation with team members.\n");
    printf("A_2 : It makes you work independently.\n");
    printf("A_3 : It doesn't influence teamwork.\n");
    printf("A_4 : It leads to ignoring team members.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    return score;
}

// Question 10 / Function.
int question_10_Fun(int answer, int score)
{
    printf("Q_10 : How do the fundamentals contribute to success in various programming domains?\n\n");
    printf("A_1 : It reduces the chances of success in one field only.\n");
    printf("A_2 : It makes you rely on pre-built software.\n");
    printf("A_3 : It increases programming complexity without tangible benefits.\n");
    printf("A_4 : By preparing you to develop diverse applications and learn multiple languages.\n\n");
    printf("Please enter the correct answer number: ");
    scanf("%d", &answer);

    if (answer == 4)
    {
        score = correctAnswerFun(score);
    }
    else
    {
        score = wrongAnswerFun(score);
    }

    printf("The endgame ... :)\n\n");

    return score;
}

/*

1. **Question: Why is learning programming fundamentals important?**
   - Correct Answer: To lay the foundation for understanding programming concepts and methods.
   - Wrong Answer 1: To produce complex software immediately.
   - Wrong Answer 2: To instantly overcome programming challenges.
   - Wrong Answer 3: To ignore problems in programming.

2. **Question: What do you learn from programming basics?**
   - Correct Answer: Organizing data, program variables, and control structures.
   - Wrong Answer 1: Graphic design.
   - Wrong Answer 2: Marketing software.
   - Wrong Answer 3: Designing databases.

3. **Question: How does learning the basics help in problem-solving?**
   - Correct Answer: It teaches you how to break down problems into smaller parts.
   - Wrong Answer 1: It provides ready-made answers to problems.
   - Wrong Answer 2: It makes you ignore problems.
   - Wrong Answer 3: It makes you rely on others to solve problems.

4. **Question: What do the fundamentals in programming enable you to understand multiple programming languages?**
   - Correct Answer: Control structures, variables, and loops.
   - Wrong Answer 1: Designing visual interfaces.
   - Wrong Answer 2: Marketing software.
   - Wrong Answer 3: Organizing code documentation.

5. **Question: What does "errors and exceptions" in programming mean?**
   - Correct Answer: Issues that arise when the program conflicts with rules.
   - Wrong Answer 1: Programming success.
   - Wrong Answer 2: Tips for speeding up programming.
   - Wrong Answer 3: Designing user interfaces.

6. **Question: How can understanding the fundamentals help in evaluating other people's code?**
   - Correct Answer: It enables you to assess quality, efficiency, and security.
   - Wrong Answer 1: It makes you work solo.
   - Wrong Answer 2: It has no impact on team collaboration.
   - Wrong Answer 3: It makes you ignore team members.

7. **Question: What does a proper understanding of programming basics mean?**
   - Correct Answer: The ability to build and comprehend simple programs.
   - Wrong Answer 1: Mastering all programming languages.
   - Wrong Answer 2: Relying solely on copy-paste.
   - Wrong Answer 3: Reducing the utilization of programming resources.

8. **Question: How does understanding the basics contribute to improving coding skills?**
   - Correct Answer: It enables logical thinking and the creation of efficient solutions.
   - Wrong Answer 1: It reduces the enjoyment of learning programming.
   - Wrong Answer 2: It doesn't affect teamwork capabilities.
   - Wrong Answer 3: It leads to increased programming complexity without tangible benefits.

9. **Question: How does mastering the fundamentals help in team collaboration?**
   - Correct Answer: It enhances communication and cooperation with team members.
   - Wrong Answer 1: It makes you work independently.
   - Wrong Answer 2: It doesn't influence teamwork.
   - Wrong Answer 3: It leads to ignoring team members.

10. **Question: How do the fundamentals contribute to success in various programming domains?**
    - Correct Answer: By preparing you to develop diverse applications and learn multiple languages.
    - Wrong Answer 1: It reduces the chances of success in one field only.
    - Wrong Answer 2: It makes you rely on pre-built software.
    - Wrong Answer 3: It increases programming complexity without tangible benefits.

*/