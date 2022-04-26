#ifndef TP_SEA_BATTLE__PLAYER_H_
#define TP_SEA_BATTLE__PLAYER_H_
#include "field.h"
#include "interface.h"
#include <string>
#include <iostream>

class Player {
 public:
  Interface interface;

  int points = 0;

  std::string name = "";

  std::string password = "";

  bool move;

  Field field;

  Player(Interface interface) : interface(interface) {
  }

  bool operator==(Player other);

  bool IsCorrect(int x, int y, Field& field);

  void Arrangement(int length);

  void PlayerArrangement();
};

#endif //TP_SEA_BATTLE__PLAYER_H_
