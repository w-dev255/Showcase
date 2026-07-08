#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
	char nickname[50];
	char mode[256];
	const char** expired;
} selected;

void remove_element(const char*** arr, int *size, const char* target) {
	

	return;
}

void game_pause(void) {
	int c;

	while ((c = getchar()) != 's');

	while ((c = getchar()) != '\n' && c != EOF);

	return;
}

void random_line(char nick[50], char m[256], const char** lines[], int count) {
	char truth_mode[6] = "truth";
	char dare_mode[5] = "dare";

	srand(time(NULL));

	int choice = rand() % count;

	if (strcmp(m, truth_mode) == 0) {
		if (lines[choice] != NULL) {
			printf("Question: %s, %s\n", nick, *lines[choice]);

			remove_element(lines, &count, choice);
		}
	} else if (strcmp(m, dare_mode) == 0) {
		if (lines[choice] != NULL) {
			printf("Challenge: %s, %s\n", nick, *lines[choice]);
		}
	} else {
		printf("warning: invalid mode.\n");

		game_pause();

		return;
	}

	game_pause();

	return;
}

int main(void) {
	selected select = {"", ""};

	char dare_mode[5] = "dare";

	char truth_mode[6] = "truth";

	char close_game[2] = "q";

	while (1) {
		while (1) {
			system("clear");

			printf("\n\n|----------------------------------------------------------|\n|                        Truth or Dare                     |\n|----------------------------------------------------------|\n\nChoose the nickname.\n\nNickname: ");
			if (fgets(select.nickname, sizeof(select.nickname), stdin) == NULL) {
				return 1;
			}

			select.nickname[strcspn(select.nickname, "\n")] = 0;

			int string_len = strlen(select.nickname);

			if (string_len == 0) {
				printf("The nickname cannot be empty.\n");

				game_pause();

				continue;
			} else {
				if (strcmp(select.nickname, close_game) == 0) {
					return 0;
				} else {
					break;
				}
			}
		}

		while (1) {
			system("clear");

			printf("\n\n|----------------------------------------------------------|\n|                        Truth or Dare                     |\n|----------------------------------------------------------|\n\nNickname: %s\n\nMode: ", select.nickname);
			if (fgets(select.mode, sizeof(select.mode), stdin) == NULL) {
				return 1;
			}

			select.mode[strcspn(select.mode, "\n")] = 0;

			int string_len = strlen(select.mode);

			if (string_len == 0) {
				printf("The string cannot be empty.\n");
				continue;
			} else {
				break;
			}
		}

		if (strcmp(select.mode, dare_mode) == 0) {
			int n = 2;

			const char** dare = malloc(n * sizeof(char*));

			dare[0] = "send me a video of you doing ten push-ups.";
			dare[1] = "send me a video of you jumping ten times.";

			random_line(select.nickname, select.mode, &dare, 2);
		} else if (strcmp(select.mode, truth_mode) == 0) {
			int n = 2;
			const char** truth = malloc(n * sizeof(char*));

			truth[0] = "what is your favorite song?";
			truth[1] = "have you ever had romantic relationships?";

			random_line(select.nickname, select.mode, &truth, 2);
		} else if (strcmp(select.mode, close_game) == 0) {
			break;
		} else {
			system("clear");

			printf("\n\n|----------------------------------------------------------|\n|                       What's wrong?                      |\n|----------------------------------------------------------|\n\nYou wrote: %s\n", select.mode);

			game_pause();

			continue;
		}
	}

	return 0;
}
