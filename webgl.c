#include <emscripten.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

float counter = 0.0;
bool toggle = false;

void update() {
    if (toggle) {
        counter += 0.005;
        EM_ASM( Update($0), counter );
    }
}

int main() {
    emscripten_set_main_loop(update, 0, 0);
    return 1;
}

void test() {
    toggle = !toggle;
    printf("***** Hello from C! *****\nMotion: %d\nTime counter: %f\n", toggle, counter);
}
