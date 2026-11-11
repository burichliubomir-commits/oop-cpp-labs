#include "Word.h"

Word::Word(const Word &other)
    : ukrWord(other.ukrWord), engWord(other.engWord) {
    if (other.details != nullptr) {
        details = new std::string(*other.details);
    } else {
        details = nullptr;
    }
}

Word& Word::operator=(const Word &other) {
    if (this == &other) { return *this; }
    delete details;
    ukrWord = other.ukrWord;
    engWord = other.engWord;
    if (other.details != nullptr) {
        details = new std::string(*other.details);
    } else {
        details = nullptr;
    }
    return *this;
}

Word::~Word() {
    delete details;
};

std::string Word::getDetails() const {
    if (details != nullptr) {
        return *details;
    }
    throw std::runtime_error("Опис відсутній.");
}

void Word::setDetails(const std::string &newDetails) {
    delete details;
    details = new std::string(newDetails);
}

bool Word::operator<(const Word &other) const {
    return ukrWord < other.ukrWord;
}

bool Word::operator>=(const Word &other) const {
    return !(*this < other);
}

std::ostream &operator<<(std::ostream &os, const Word &word) {
    os << word.ukrWord << " " << word.engWord;
    return os;
}
