#include <iostream>
#include "../headers/interface.h"
#include <sstream>

void Interface::PrintField(Field& field) {
  system("clear");
  std::cout << "   Поле игрока                Поле соперника\n\n";
  std::cout << "   A B C D E F G H           A B C D E F G H \n";
  for (int i = 1; i < 9; ++i) {
    std::cout << " " << i << " ";
    for (int j = 1; j < 9; ++j) {
      if (field.own_field[i][j].condition == "empty") {
        std::cout << "· ";
      } else if (field.own_field[i][j].condition == "ship") {
        std::cout << "К ";
      } else if (field.own_field[i][j].condition == "beaten_ship") {
        std::cout << "Х ";
      } else {
        std::cout << "o ";
      }
    }
    std::cout << "        " << i << " ";
    for (int j = 1; j < 9; ++j) {
      if (field.opp_field[i][j].condition == "beaten_ship") {
        std::cout << "К ";
      } else if (field.opp_field[i][j].condition == "beaten_empty") {
        std::cout << "Х ";
      } else {
        std::cout << "· ";
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void Interface::PrintIncorrectArrangement(std::string str) {
  std::cout << "Некорректная постановка корабля " << str << ", поставьте корабль заново\n";
}

void Interface::PrintSingleDeck(std::string name) {
  system("clear");
  std::cout << "\n" << name << ", расставьте однопалубные корабли\n";
}

void Interface::PrintTwoDeck(std::string name) {
  std::cout << "\n" << name << ", расставьте двухпаплубные корабли\n";
}

void Interface::PrintThreeDeck(std::string name) {
  std::cout << "\n" << name << ", расставьте трехпалубные корабли\n";
}

void Interface::PrintFourDeck(std::string name) {
  std::cout << "\n" << name << ", расставьте четырехпалубные корабли\n";
}

void Interface::PrintMove(std::string name) {
  std::cout << name << ", ваш ход: ";
}

void Interface::PrintIncorectMove() {
  std::cout << "Некорректный ход\n";
}

void Interface::PrintIncorrectShoot() {
  std::cout << "В эту клетку уже был выстрел\n";
}

void Interface::PrintInfo() {
  std::cout
      << "Здравствуйте! Игра 'Морской бой', необходимо потопить все корабли противника.\n"
         " Пример расстановки однопалубных кораблуй: A1 A3 A5 A7.\n"
         " Пример расстановки двухпалубных кораблей: A1:A3 B1:D1 B2:C2.\n\n";
}

void Interface::PrintInjure() {
  std::cout << "\nРанил\n\n";
}

void Interface::PrintMissed() {
  system("clear");
  std::cout << "\nМимо\n\n";
}

void Interface::PrintSunk() {
  std::cout << "\nПотопил\n\n";
}

void Interface::PrintReadPassword(std::string name) {
  std::cout << name << ", введите свой пароль, а затем нажмите Enter: ";
}

void Interface::PrintFirstPresentation() {
  std::cout << "Игрок 1, введите своё имя: ";
}

void Interface::PrintPassword(std::string name) {
  std::cout << name << " , придумайте пароль: ";
}

void Interface::PrintSecondPresentation() {
  system("clear");
  std::cout << "\nИгрок 2, введите своё имя: ";
}

void Interface::PrintEnd(std::string name) {
  std::cout << name << " победил!";
}

void Interface::PrintIncorrectPassword(std::string name) {
  std::cout << "Неверный пароль\n";
}

void Interface::EnterName(std::string& name) {
  std::cin >> name;
};

void Interface::EnterPassword(std::string& password) {
  std::cin >> password;
}

void Interface::EnterMove(std::string& move) {
  std::cin >> move;
}

void Interface::AddPassword(std::string& password) {
  std::cin >> password;
}
