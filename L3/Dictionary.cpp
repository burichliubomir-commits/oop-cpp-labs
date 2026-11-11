#include "Dictionary.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>

void Dictionary::reallocate(const size_t newCapacity) {
    Word* newWords = new Word[newCapacity];
    for (size_t i = 0; i < count; ++i) {
        newWords[i] = words[i];
    }
    delete[] words;
    words = newWords;
    capacity = newCapacity;
}

void Dictionary::push(const Word& word) {
    if (count == capacity) {
        reallocate(capacity == 0 ? 4 : capacity * 2);
    }
    words[count++] = word;
}

Dictionary::Dictionary(const Word* arr, const size_t n) {
    if (n > 0) {
        reallocate(n);
        for (size_t i = 0; i < n; ++i) {
            words[i] = arr[i];
        }
        count = n;
    }
}

Dictionary::Dictionary(const Dictionary& other) {
    if (other.count > 0) {
        reallocate(other.count);
        for (size_t i = 0; i < other.count; ++i) {
            words[i] = other.words[i];
        }
        count = other.count;
    }
}

Dictionary& Dictionary::operator=(const Dictionary& other) {
    if (this == &other) { return *this; }
    delete[] words;
    words = nullptr;
    count = 0;
    capacity = 0;
    if (other.count > 0) {
        reallocate(other.count);
        for (size_t i = 0; i < other.count; ++i) {
            words[i] = other.words[i];
        }
        count = other.count;
    }
    return *this;
}

Dictionary::~Dictionary() {
    delete[] words;
}

Dictionary Dictionary::operator+(const Word& word) const {
    Dictionary result = *this;
    result.push(word);
    return result;
}

Dictionary Dictionary::operator-(const char* ukrWord) const {
    Dictionary result = *this;
    for (size_t i = 0; i < result.count; ++i) {
        if (std::strcmp(result.words[i].getUkr(), ukrWord) == 0) {
            for (size_t j = i; j + 1 < result.count; ++j) {
                result.words[j] = result.words[j + 1];
            }
            --result.count;
            return result;
        }
    }
    char errMsg[256];
    std::snprintf(errMsg, sizeof(errMsg), "Слово '%s' не знайдено у словнику!", ukrWord);
    throw std::runtime_error(errMsg);
}

void Dictionary::sort(const bool byEnglish) const {
    for (size_t i = 0; i < count; ++i) {
        for (size_t j = i + 1; j < count; ++j) {
            const bool needSwap = byEnglish
                ? (std::strcmp(words[j].getEng(), words[i].getEng()) < 0)
                : (words[j] < words[i]);

            if (needSwap) {
                Word const temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

Word Dictionary::find(const char* ukrWord) const {
    for (size_t i = 0; i < count; ++i) {
        if (std::strcmp(words[i].getUkr(), ukrWord) == 0) {
            return words[i];
        }
    }
    char errMsg[256];
    std::snprintf(errMsg, sizeof(errMsg), "Слово '%s' не знайдено у словнику!", ukrWord);
    throw std::runtime_error(errMsg);
}

std::ostream& operator<<(std::ostream& os, const Dictionary& dict) {
    if (dict.count == 0) {
        os << "Словник порожній.";
        return os;
    }
    os << "=== Словник (всього слів: " << dict.count << ") ===\n";
    for (size_t i = 0; i < dict.count; ++i) {
        os << i + 1 << ". " << dict.words[i] << std::endl;
    }
    return os;
}