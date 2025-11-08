#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char question[256];
  char options[4][100];
  int correct_option;
} QuizQuestion;

void loadQuestions(QuizQuestion *quiz) {
  //question1
  strcpy(quiz[0].question, "What was Sung Jin-Woo's initial Hunter Rank before he got his unique ability?");
  strcpy(quiz[0].options[0], "S-rank");
  strcpy(quiz[0].options[1], "A-rank");
  strcpy(quiz[0].options[2], "E-rank");
  strcpy(quiz[0].options[3], "D-rank");
  quiz[0].correct_option = 2;
  //question2
  strcpy(quiz[1].question, "What is the name of Megumi Fushiguro's Domain Expansion?");
  strcpy(quiz[1].options[0], "Malevolent Shrine");
  strcpy(quiz[1].options[1], "Hollow Purple");
  strcpy(quiz[1].options[2], "Unlimited void");
  strcpy(quiz[1].options[3], "Chimera Shadow Garden");
  quiz[1].correct_option = 3;
  //question3
  strcpy(quiz[2].question, "What is the first jutsu that Naruto learns to save Iruka sensei?");
  strcpy(quiz[2].options[0], "Rasengan");
  strcpy(quiz[2].options[1], "Majestic Destroyer Flame");
  strcpy(quiz[2].options[2], "Sexy Jutsu: Reverse Harem");
  strcpy(quiz[2].options[3], "Multi Shadow Clone Jutsu");
  quiz[2].correct_option = 3;
  //question4
  strcpy(quiz[3].question, "When Light Yagami went on his first killing spree, how many days did he spend killing people?");
  strcpy(quiz[3].options[0], "3 days");
  strcpy(quiz[3].options[1], "10 days");
  strcpy(quiz[3].options[2], "5 days");
  strcpy(quiz[3].options[3], "7 days");
  quiz[3].correct_option = 2;
  //question5
  strcpy(quiz[4].question, "Who is the person before Zeke Jaeger to be the holder of the Beast Titan?");
  strcpy(quiz[4].options[0], "Udo");
  strcpy(quiz[4].options[1], "Porco");
  strcpy(quiz[4].options[2], "Mr. Ksaver");
  strcpy(quiz[4].options[3], "Calvin");
  quiz[4].correct_option = 2;
  //question6
  strcpy(quiz[5].question, "What is the maximum of The Eight Inner Gates that Rock Lee can open?");
  strcpy(quiz[5].options[0], "3 Gates");
  strcpy(quiz[5].options[1], "4 Gates");
  strcpy(quiz[5].options[2], "5 Gates");
  strcpy(quiz[5].options[3], "6 Gates");
  quiz[5].correct_option = 3;
  //question7
  strcpy(quiz[6].question, "Who was the third player in the 3-man team that Hinata and Kageyama played with to secure their spot in the team?");
  strcpy(quiz[6].options[0], "Nishinoya");
  strcpy(quiz[6].options[1], "Sugawara");
  strcpy(quiz[6].options[2], "Daichi");
  strcpy(quiz[6].options[3], "Tanaka");
  quiz[6].correct_option = 3;
  //question8
  strcpy(quiz[7].question, "How many Titans did Eren possess by the end of the show?");
  strcpy(quiz[7].options[0], "2");
  strcpy(quiz[7].options[1], "4");
  strcpy(quiz[7].options[2], "3");
  strcpy(quiz[7].options[3], "5");
  quiz[7].correct_option = 2;
  //question9
  strcpy(quiz[8].question, "Who's death did Nanami regret in Jujutsu Kaisen 0?");
  strcpy(quiz[8].options[0], "Riko");
  strcpy(quiz[8].options[1], "Haibara");
  strcpy(quiz[8].options[2], "Nobara");
  strcpy(quiz[8].options[3], "Geto");
  quiz[8].correct_option = 1;
  //question10
  strcpy(quiz[9].question, "Which of the following characters was not murdered by the adult Johan Liebert or under his direct command?");
  strcpy(quiz[9].options[0], "The Liebert's adoptive parents");
  strcpy(quiz[9].options[1], "Dr. Udo Heinemann");
  strcpy(quiz[9].options[2], "Inspector Lunge's wife");
  strcpy(quiz[9].options[3], "'The Baby' Frankfurt");
  quiz[9].correct_option = 2;
}
  
  int askQuestion(QuizQuestion q) {
    printf("\n%s\n", q.question);

    for(int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }

    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer < 1 || answer > 4) {
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        return 0;
    }

    if (answer - 1 == q.correct_option) {
        printf("✅ Correct!\n");
        return 1;
    } else {
        printf("❌ Incorrect. The correct answer was: %s\n", q.options[q.correct_option]);
        return 0;
    }
}
  
  int main() {
    int totalQuestions = 10;
    QuizQuestion *quiz = malloc(sizeof(QuizQuestion) * totalQuestions);
    
    loadQuestions(quiz);
    
    int score = 0;
    for(int i=0; i < totalQuestions; i++) {
      printf("\nQuestion %d:\n", i+1);
      score += askQuestion(quiz[i]);
    }
      
      printf("\nYour final score: %d out of %d\n", score, totalQuestions);
      
      free(quiz);
      return 0;
  }
  