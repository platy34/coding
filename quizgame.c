#include <stdio.h>
#include <ctype.h>

int main(){

    char questions[][100] = {"What is the largest planet in the solar system?",
                             "What is the hottest planet?",
                             "Which planet has the most moons?",
                             "Is the Earth flat?"};

    char options[][100] = {"A. Jupiter\nB. Saturn\nC. Uranus\nD. Neptune",
                            "A. Mercury\nB. Venus\nC. Saturn\nD. Earth",
                            "A. Earth\nB. Neptune\nC. Jupiter\nD. Saturn",
                            "A. Yes\nB. No\nC. Maybe\nD. Sometimes"};

    char answerKey[] = {'A', 'B', 'D', 'B'};

    int questionCount = sizeof(questions)/sizeof(questions[0]);

    char guess = '\0';
    int score = 0;

    printf("*** QUIZ GAME ***\n");

    for (int i = 0; i < questionCount; i++){
        printf("\n%s\n", questions[i]);
        printf("\n%s\n", options[i]);
        printf("\nEnter your choice: ");
        scanf(" %c", &guess);
        
        guess = toupper(guess);

        if (guess == answerKey[i]){
            printf("Correct\n");
            score++;
        }
        else{
            printf("Wrong\n");
        }
    }

    printf("\nYour score is %d out of %d points\n", score, questionCount);


    return 0;

}
