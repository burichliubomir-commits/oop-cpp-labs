#include "Football.h"
#include <iostream>
#include <iomanip>

Football::Football()
    : SportGame("Футбол", 11, 90, true),
      league(nullptr),
      homeGoals{},
      awayGoals{},
      extraTime{} {}

Football::Football(const char* league, const int homeGoals, const int awayGoals, const int extraTime)
    : SportGame("Футбол", 11, 90, true),
      league(copyString(league)),
      homeGoals(homeGoals >= 0 ? homeGoals : 0),
      awayGoals(awayGoals >= 0 ? awayGoals : 0),
      extraTime(extraTime >= 0 ? extraTime : 0) {}

Football::Football(const Football& other)
    : SportGame(other),
      league(copyString(other.league)),
      homeGoals(other.homeGoals),
      awayGoals(other.awayGoals),
      extraTime(other.extraTime) {}

Football& Football::operator=(const Football& other) {
    if (this == &other) { return *this; }
    SportGame::operator=(other);
    delete[] league;
    league = copyString(other.league);
    homeGoals = other.homeGoals;
    awayGoals = other.awayGoals;
    extraTime = other.extraTime;
    return *this;
}

void Football::setLeague(const char* newLeague) {
    if (newLeague == nullptr || this->league == newLeague) {
        return;
    }
    delete[] league;
    league = copyString(newLeague);
}

void Football::setHomeGoals(const int goals) {
    homeGoals = (goals >= 0) ? goals : 0;
}

void Football::setAwayGoals(const int goals) {
    awayGoals = (goals >= 0) ? goals : 0;
}

void Football::setExtraTime(const int minutes) {
    extraTime = (minutes >= 0) ? minutes : 0;
}

const char* Football::getMatchResult() const {
    if (homeGoals > awayGoals) { return "Перемога господарів"; }
    if (awayGoals > homeGoals) { return "Перемога гостей"; }
    return "Нічия";
}

void Football::printInfo(std::ostream& out) const {
    SportGame::printInfo(out);
    out << "\n  -> Ліга: " << getLeague()
        << " | Рахунок: " << homeGoals << ":" << awayGoals
        << " (" << getMatchResult() << ")"
        << " | Доданий час: +" << extraTime << " хв"
        << " | Загальний час матчу: " << getTotalDuration() << " хв";
}

std::istream& operator>>(std::istream& in, Football& match) {
    char buffer[256];
    int home{};
    int away{};
    int extra{};
    if (in >> std::setw(256) >> buffer >> home >> away >> extra) {
        match.setLeague(buffer);
        match.setHomeGoals(home);
        match.setAwayGoals(away);
        match.setExtraTime(extra);
    }
    return in;
}