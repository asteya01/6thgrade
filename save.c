#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios old, raw;
    tcgetattr(0, &old);
    raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_iflag &= ~(IXON);  // Allow Ctrl+S to be captured
    tcsetattr(0, TCSAFLUSH, &raw);

    FILE *f = fopen("typed_output.txt", "w");
    char c;
    write(1, "Start typing (Ctrl+S to save):\n", 31);
    while (read(0, &c, 1) && c != 19) { // 19 = Ctrl+S
        fputc(c, f);
        write(1, &c, 1);
    }

    fclose(f);
    tcsetattr(0, TCSAFLUSH, &old);
    write(1, "\nSaved to typed_output.txt\n", 27);
    return 0;
}
