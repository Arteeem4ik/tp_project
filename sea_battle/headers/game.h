#ifndef TP_SEA_BATTLE__GAME_H_
#define TP_SEA_BATTLE__GAME_H_
#include "player.h"

class Game {
 public:
  Player first;
  Player second;
  bool game = true;

  Player& Opponent(Player player);

  void Move(Player& player);

  void SeaBattle();
};

#endif //TP_SEA_BATTLE__GAME_H_
