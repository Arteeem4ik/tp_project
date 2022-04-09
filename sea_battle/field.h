#ifndef TP_SEA_BATTLE__FIELD_H_
#define TP_SEA_BATTLE__FIELD_H_
#include <iostream>
#include <sstream>
#include "square.h"

class Field {
 public:
  Square own_field[10][10]{};
  Square opp_field[10][10]{};

  void Print() {
    system("clear");
    std::cout << "   Поле игрока                Поле соперника\n\n";
    std::cout << "   A B C D E F G H           A B C D E F G H \n";
    for (int i = 1; i < 9; ++i) {
      std::cout << " " << i << " ";
      for (int j = 1; j < 9; ++j) {
        if (own_field[i][j].condition == "empty") {
          std::cout << "· ";
        } else if (own_field[i][j].condition == "ship") {
          std::cout << "К ";
        } else if (own_field[i][j].condition == "beaten_ship") {
          std::cout << "Х ";
        } else {
          std::cout << "o ";
        }
      }
      std::cout << "        " << i << " ";
      for (int j = 1; j < 9; ++j) {
        if (opp_field[i][j].condition == "beaten_ship") {
          std::cout << "К ";
        } else if (opp_field[i][j].condition == "beaten_empty") {
          std::cout << "Х ";
        } else {
          std::cout << "· ";
        }
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }

  bool IsDied(int i, int j) {
    for (int k = i; k < 9; ++k) {
      if (own_field[k][j].condition == "empty" || own_field[k][j].condition == "beaten_empty") {
        break;
      } else if (own_field[k][j].condition == "ship") {
        return false;
      }
    }
    for (int k = i; k > 0; --k) {
      if (own_field[k][j].condition == "empty" || own_field[k][j].condition == "beaten_empty") {
        break;
      } else if (own_field[k][j].condition == "ship") {
        return false;
      }
    }
    for (int k = j; k < 9; ++k) {
      if (own_field[i][k].condition == "empty" || own_field[k][j].condition == "beaten_empty") {
        break;
      } else if (own_field[i][k].condition == "ship") {
        return false;
      }
    }
    for (int k = j; k > 0; --k) {
      if (own_field[i][k].condition == "empty" || own_field[k][j].condition == "beaten_empty") {
        break;
      } else if (own_field[i][k].condition == "ship") {
        return false;
      }
    }
    return true;
  }
};

#endif //TP_SEA_BATTLE__FIELD_H_
