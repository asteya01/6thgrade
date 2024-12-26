#include <stdio.h>
#include <unistd.h> // For usleep
#include <stdlib.h> // For system()

int main() {
    // Metronome settings
    int bpm = 80;                 // Beats per minute
    int beat_interval_ms = 60000 / bpm; // Interval in milliseconds

    printf("Metronome started at %d BPM. Press Ctrl+C to stop.\n", bpm);

    // Ensure beep is available
    if (system("which beep > /dev/null 2>&1") != 0) {
        printf("Error: 'beep' command not found. Install it using: sudo apt install beep\n");
        return 1;
    }

    while (1) {
        //system("beep -f 440 -l 100"); // 440Hz frequency, 100ms duration
        system("play -n synth 0.1 sine 440");
        usleep(beat_interval_ms * 1000); // Convert ms to microseconds and sleep
    }

    return 0;
}
