#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NANOSECONDS_PER_SECOND 1000000000L

int main() {
    const int bpm = 60; // Beats per minute
    const long interval_ns = NANOSECONDS_PER_SECOND / (bpm / 60); // Nanoseconds per beat

    struct timespec next_beat_time;

    // Get the current time as the starting point
    clock_gettime(CLOCK_MONOTONIC, &next_beat_time);

    printf("Metronome: 60 BPM\n");
    printf("Press Ctrl+C to stop.\n");

    while (1) {
        // Produce the beep sound
        printf("\a"); // Generates the beep sound
        fflush(stdout);

        // Increment the next beat time by the interval
        next_beat_time.tv_nsec += interval_ns;

        // Normalize the time if nanoseconds overflow
        if (next_beat_time.tv_nsec >= NANOSECONDS_PER_SECOND) {
            next_beat_time.tv_nsec -= NANOSECONDS_PER_SECOND;
            next_beat_time.tv_sec++;
        }

        // Sleep until the next beat
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);

        long sleep_time_sec = next_beat_time.tv_sec - now.tv_sec;
        long sleep_time_ns = next_beat_time.tv_nsec - now.tv_nsec;

        if (sleep_time_ns < 0) {
            sleep_time_sec--;
            sleep_time_ns += NANOSECONDS_PER_SECOND;
        }

        // Only sleep if we are ahead of the beat
        if (sleep_time_sec > 0 || (sleep_time_sec == 0 && sleep_time_ns > 0)) {
            struct timespec sleep_time = {sleep_time_sec, sleep_time_ns};
            nanosleep(&sleep_time, NULL);
        }
    }

    return 0;
}
