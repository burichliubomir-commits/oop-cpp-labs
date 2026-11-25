#include "SportGame.h"
#include <iostream>
#include <cstring>
#include <iomanip>

char *SportGame::copyString(const char *src) {
    if (src == nullptr) { return nullptr; }
    char* dest = new char[std::strlen(src) + 1];
    return std::strcpy(dest, src);
}

SportGame::SportGame(const char* src, const int players, const int duration, bool isOlympic)
    : name(copyString(src)),
      players(players > 0 ? players : 0),
      duration(duration > 0 ? duration : 0),
      isOlympic(isOlympic) {}

SportGame::SportGame(const SportGame& other)
    : name(copyString(other.name)),
      players(other.players),
      duration(other.duration),
      isOlympic(other.isOlympic) {}

SportGame& SportGame::operator=(const SportGame &other) {
    if (this == &other) { return *this; }
    delete[] name;
    name = copyString(other.name);
    players = other.players;
    duration = other.duration;
    isOlympic = other.isOlympic;
    return *this;
}

void SportGame::setName(const char* newName) {
    if (newName == nullptr || this->name == newName) { return; }
    delete[] name;
    name = copyString(newName);
}

void SportGame::setPlayers(const int newPlayers) {
    if (newPlayers <= 0) { players = 0;}
    else { players = newPlayers; }
}
void SportGame::setDuration(const int newDuration) {
    if (newDuration <= 0) { duration = 0; }
    else { duration = newDuration; }
}
void SportGame::setIsOlympic(const bool newIsOlympic) {
    isOlympic = newIsOlympic;
}
void SportGame::printInfo(std::ostream& out) const {
    out << "Спорт: " << getName()
        << " | Гравців в команді: " << players
        << " (Загальна кількість гравців: " << getTotalPlayers() << ")"
        << " | Тривалість: " << duration << " хвилин"
        << " | " << (isOlympic ? "Олімпійський вид спорту" : "Не олімпійський вид спорту");
}
std::ostream& operator<<(std::ostream& out, const SportGame& game) {
    game.printInfo(out);
    return out;
}
std::istream& operator>>(std::istream& in, SportGame& game) {
    char buffer[256];
    int players{};
    int duration{};
    bool olympic = false;
    if (in >> std::setw(256) >> buffer >> players >> duration >> olympic) {
        game.setName(buffer);
        game.setPlayers(players);
        game.setDuration(duration);
        game.setIsOlympic(olympic);
    }
    return in;
}
