#pragma once
#include <iosfwd>

class SportGame {
protected:
    char* name{nullptr};
    int players{};
    int duration{};
    bool isOlympic{};

    static char* copyString(const char* src);

public:
    SportGame() : name{nullptr}, players{0}, duration{0}, isOlympic {false} {}
    SportGame(const char* src, int players, int duration, bool isOlympic);
    SportGame(const SportGame &other);
    SportGame& operator=(const SportGame &other);

    virtual ~SportGame() { delete[] name; }

    const char* getName() const { return name ? name : "Unknown"; }
    int getPlayers() const { return players; }
    int getTotalPlayers() const { return players * 2; }
    int getDuration() const { return duration; }
    bool getIsOlympic() const { return isOlympic; }
    void setName(const char* newName);
    void setPlayers(int newPlayers);
    void setDuration(int newDuration);
    void setIsOlympic(bool newIsOlympic);

    virtual int getTotalDuration() const { return duration; }
    virtual void printInfo(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const SportGame& game);
    friend std::istream& operator>>(std::istream& in, SportGame& game);
};
