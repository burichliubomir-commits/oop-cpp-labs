#pragma once
#include "SportGame.h"

class Football : public SportGame {
private:
    char* league{nullptr};
    int homeGoals{};
    int awayGoals{};
    int extraTime{};

public:
    Football();
    Football(const char* league, int homeGoals, int awayGoals, int extraTime);
    Football(const Football& other);
    Football& operator=(const Football& other);
    ~Football() override { delete[] league; }

    const char* getLeague() const { return league ? league : "Невідома ліга"; }
    int getHomeGoals() const { return homeGoals; }
    int getAwayGoals() const { return awayGoals; }
    int getExtraTime() const { return extraTime; }

    void setLeague(const char* newLeague);
    void setHomeGoals(int goals);
    void setAwayGoals(int goals);
    void setExtraTime(int minutes);

    const char* getMatchResult() const;

    int getTotalDuration() const override { return duration + extraTime; }
    void printInfo(std::ostream& out) const override;

    friend std::istream& operator>>(std::istream& in, Football& match);
};