#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Word {
private:
    std::string ukrWord{};
    std::string engWord{};
    std::string*details = nullptr;
public:
    Word() : ukrWord("Невідомо"), engWord("Unknown") {}
    Word(const std::string &ukr, const std::string &eng)
        : ukrWord(ukr), engWord(eng){}
    Word(const std::string &ukr, const std::string &eng, const std::string &det)
        : ukrWord(ukr), engWord(eng), details(new std::string(det)) {}

    Word(const Word &other);
    Word& operator=(const Word &other);
    ~Word();

    std::string getUkr() const { return ukrWord; }
    std::string getEng() const { return engWord; }
    std::string getDetails() const;
    void setDetails(const std::string &newDetails);

    bool operator<(const Word &other) const;
    bool operator>=(const Word &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Word &word);
};