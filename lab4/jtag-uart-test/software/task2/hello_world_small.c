#include <stdio.h>
#include <string.h>
#define CHARLIM 256		// Maximum character length of what the user places in memory.  Increase to allow longer sequences
#define QUITLETTER '~' 		// Letter to kill all processing

void print_text(char *text, const int length) {
	char *printMsg;
	asprintf(&printMsg, "<--> Detected %d characters: %s <--> \n %c", length, text, 0x4); 	// Print out the strings
	alt_putstr(printMsg);
	free(printMsg);
	memset(text, 0, 2*CHARLIM);								// Empty the text buffer for next input
}

char generate_text(char curr, int *length, char *text, int *running) {
	if(curr == '\n') return curr;								// If the line is empty, return nothing.
	int idx = 0;										// Keep track of how many characters have been sent down for later printing
	char newCurr = curr;

	while (newCurr != EOF && newCurr != '\n'){						// Keep reading characters until we get to the end of the line
		if (newCurr == QUITLETTER) { *running = 0; }					// If quitting letter is encountered, setting running to 0
		text[idx] = newCurr;								// Add the next letter to the text buffer
		idx++;										// Keep track of the number of characters read
		newCurr = alt_getchar();							// Get the next character
	}
	*length = idx;

	return newCurr;
}

int read_chars() {
	char text[2*CHARLIM];									// The buffer for the printing text
	char prevLetter = '!';
	int length = 0;
	int running = 1;

	while (running) {									// Keep running until QUITLETTER is encountered
		prevLetter = alt_getchar();							// Extract the first character (and create a hold until one arrives)
		prevLetter = generate_text(prevLetter, &length, text, &running);		// Process input text
		print_text(text, length);							// Print input text
	}

	return 0;
}

int main() {
	return read_chars();
}
