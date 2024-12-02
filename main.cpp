#include <iostream>
#include <string>
#include <set>

class BullsAndCowsGame {
private:
    std::string secretNumber;
    int maxAttempts;

    std::string generateSecretNumber() {
        std::srand(std::time(nullptr));
        std::set<int> uniqueDigits;
        while (uniqueDigits.size() < 4) {
            uniqueDigits.insert(std::rand() % 10);
        }

        std::string number;
        for (int digit : uniqueDigits) {
            number += std::to_string(digit);
        }
        return number;
    }

    bool isValidGuess(const std::string& guess) {
        if (guess.length() != 4) return false;

        std::set<char> uniqueDigits(guess.begin(), guess.end());
        return uniqueDigits.size() == 4;
    }

    std::pair<int, int> checkGuess(const std::string& guess) {
        int bulls = 0, cows = 0;
        for (int i = 0; i < 4; ++i) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
            } else if (secretNumber.find(guess[i]) != std::string::npos) {
                cows++;
            }
        }
        return {bulls, cows};
    }

public:
    BullsAndCowsGame(int attempts = 10) : maxAttempts(attempts) {
        secretNumber = generateSecretNumber();
    }

    void play() {
        std::cout << "----------------------------------------\n";
        std::cout << "Добро пожаловать в игру 'Быки и коровы'!\n";
        std::cout << "Я загадал 4-значное число. У вас " << maxAttempts << " попыток его угадать.\n";
        std::cout << "Введите 4 разные цифры. Я скажу сколько 'быков' и 'коров'.\n";
        std::cout << "----------------------------------------\n";

        int currentAttempt = 0;
        while (currentAttempt < maxAttempts) {
            std::string guess;
            std::cout << "\nПопытка " << currentAttempt + 1 << " / " << maxAttempts << ": ";
            std::cout << "Введите ваше предположение: ";
            std::cin >> guess;

            if (!isValidGuess(guess)) {
                std::cout << "Некорректный ввод! Введите 4 разные цифры.\n";
                continue;
            }

            auto [bulls, cows] = checkGuess(guess);

            std::cout << "Результат: Быки - " << bulls << ", Коровы - " << cows << "\n";
            std::cout << "----------------------------------------\n";

            if (bulls == 4) {
                std::cout << "\nПоздравляю! Вы угадали число " << secretNumber << "!\n";
                std::cout << "----------------------------------------\n";
                return;
            }

            currentAttempt++;
        }

        std::cout << "\nИгра окончена. Загаданное число было: " << secretNumber << "\n";
        std::cout << "----------------------------------------\n";
    }
};

int main() {

    BullsAndCowsGame game;

    char playAgain;
    do {
        game = BullsAndCowsGame();
        game.play();

        std::cout << "\nХотите сыграть еще? (y/n): ";
        std::cin >> playAgain;
        std::cout << "----------------------------------------\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}