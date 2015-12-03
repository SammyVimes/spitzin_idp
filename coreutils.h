#ifndef COREUTILS
#define COREUTILS

template <class T>
T random(T min, T max) {
    return min + (rand() % (int)(max - min + 1));
}

#endif // COREUTILS

