#include "Word.h"
#include <cstring>

char* Word::copyString(const char* src) {
    if (src == nullptr) {
        return nullptr;
    }
    char* dest = new char[std::strlen(src) + 1];
    std::strcpy(dest, src);
    return dest;
}

Word::Word()
    : ukrWord(copyString("Невідомо")), engWord(copyString("Unknown")), details(nullptr) {}

Word::Word(const char* ukr, const char* eng)
    : ukrWord(copyString(ukr)), engWord(copyString(eng)), details(nullptr) {}

Word::Word(const char* ukr, const char* eng, const char* det)
    : ukrWord(copyString(ukr)), engWord(copyString(eng)), details(copyString(det)) {}

Word::Word(const Word& other)
    : ukrWord(copyString(other.ukrWord)),
      engWord(copyString(other.engWord)),
      details(copyString(other.details)) {}

Word& Word::operator=(const Word& other) {
    if (this == &other) {
        return *this;
    }

    delete[] ukrWord;
    delete[] engWord;
    delete[] details;

    ukrWord = copyString(other.ukrWord);
    engWord = copyString(other.engWord);
    details = copyString(other.details);

    return *this;
}

Word::~Word() {
    delete[] ukrWord;
    delete[] engWord;
    delete[] details;
}

const char* Word::getDetails() const {
    if (details != nullptr) {
        return details;
    }
    throw std::runtime_error("Опис відсутній.");
}

void Word::setDetails(const char* newDetails) {
    delete[] details;
    details = copyString(newDetails);
}

bool Word::operator<(const Word& other) const {
    return std::strcmp(ukrWord, other.ukrWord) < 0;
}

bool Word::operator>=(const Word& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Word& word) {
    os << (word.ukrWord ? word.ukrWord : "") << " "
       << (word.engWord ? word.engWord : "");
    return os;
}