#ifndef TP_SEA_BATTLE__PLAYER_H_
#define TP_SEA_BATTLE__PLAYER_H_
#include "field.h"
#include <string>
#include <iostream>

class Player {
 public:
  int points = 0;

  std::string name = "";

  bool move;

  Field field;

  bool operator==(Player other) {
    return (name == other.name);
  }

  void Arrangement(int length) {
    std::string str;
    std::cin >> str;
    if (length == 1) {
      field.own_field[str[1] - '0'][str[0] - 64].condition = "ship";
    } else if (str[0] == str[3] or str[0] == str[4]) {
      for (int i = 0; i < length; ++i) {
        field.own_field[str[1] - '0' + i][str[0] - 64].condition = "ship";
      }
    } else {
      for (int i = 0; i < length; ++i) {
        field.own_field[str[1] - '0'][str[0] - 64 + i].condition = "ship";
      }
    }
  }

  void PlayerArrangement() {
    field.Print();
    std::cout << "\n" << name << ", расставьте однопалубные корабли\n";
    for (int i = 0; i < 4; ++i) {
      Arrangement(1);
    }
    field.Print();
    std::cout << "\n" << name << ", расставьте двухпалубные корабли\n";
    for (int i = 0; i < 3; ++i) {
      Arrangement(2);
    }
    field.Print();
    std::cout << "\n" << name << ", расставьте трехпалубные корабли\n";
    for (int i = 0; i < 2; ++i) {
      Arrangement(3);
    }
    field.Print();
    std::cout << "\n" << name << ", расставьте четырехалубный корабль\n";
    Arrangement(4);
  }
};

#endif //TP_SEA_BATTLE__PLAYER_H_
