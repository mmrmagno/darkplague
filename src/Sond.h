#ifndef SOUND_H
#define SOUND_H

class Sound {
public:
    bool init();
    void playSound(const char* filePath);
    void cleanup();
};

#endif
