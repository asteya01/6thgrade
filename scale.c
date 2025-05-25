#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void play_tone(int freq, float duration) {
    char cmd[200];
    sprintf(cmd, "timeout %.1f play -n synth %.1f sine %d vol 0.3 2>/dev/null", 
            duration, duration, freq);
    system(cmd);
}

int main() {
    int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
    char notes[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C'};
    
    printf("Playing C Major Scale...\n");
    
    for(int i = 0; i < 8; i++) {
        printf("♪ %c (%d Hz)\n", notes[i], frequencies[i]);
        play_tone(frequencies[i], 0.5);
        usleep(100000);
    }
    
    printf("Scale complete!\n");
    return 0;
}