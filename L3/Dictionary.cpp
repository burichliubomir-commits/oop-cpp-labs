#include "Dictionary.h"

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

Dictionary Dictionary::operator-(const std::string& ukrWord) const {
    Dictionary result = *this;
    for (size_t i = 0; i < result.count; ++i) {
        if (result.words[i].getUkr() == ukrWord) {
            for (size_t j = i; j + 1 < result.count; ++j) {
                result.words[j] = result.words[j + 1];
            }
            --result.count;
            return result;
        }
    }
    throw std::runtime_error("Слово '" + ukrWord + "' не знайдено у словнику!");
}

void Dictionary::sort() const {
    sort(SortBy::Ukrainian);
}

void Dictionary::sort(const SortBy criterion) const {
    for (size_t i = 1; i < count; ++i) {
        Word key = words[i];
        size_t j = i;
        while (j > 0) {
            const bool less = (criterion == SortBy::Ukrainian)
                            ? (key < words[j - 1])
                            : (key.getEng() < words[j - 1].getEng());
            if (!less) { break; }
            words[j] = words[j - 1];
            --j;
        }
        words[j] = key;
    }
}

Word Dictionary::find(const std::string& ukrWord) const {
    for (size_t i = 0; i < count; ++i) {
        if (words[i].getUkr() == ukrWord) {
            return words[i];
        }
    }
    throw std::runtime_error("Слово '" + ukrWord + "' не знайдено у словнику!");
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