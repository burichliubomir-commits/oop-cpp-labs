#pragma once
#include <iostream>

class Word {
private:
    char* ukrWord = nullptr;
    char* engWord = nullptr;
    char* details = nullptr;

    static char* copyString(const char* src);

public:
    Word();
    Word(const char* ukr, const char* eng);
    Word(const char* ukr, const char* eng, const char* det);

    Word(const Word& other);
    Word& operator=(const Word& other);
    ~Word();

    const char* getUkr() const { return ukrWord; }
    const char* getEng() const { return engWord; }
    const char* getDetails() const;
    void setDetails(const char* newDetails);

    bool operator<(const Word& other) const;
    bool operator>=(const Word& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Word& word);
};