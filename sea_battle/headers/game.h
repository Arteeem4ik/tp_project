#ifndef TP_SEA_BATTLE__GAME_H_
#define TP_SEA_BATTLE__GAME_H_
#include "player.h"
#include "interface.h"

class Game {
 public:
  Interface interface;
  Player first = Player(interface);
  Player second = Player(interface);
  bool game = true;

  Game(Interface interface) : interface(interface) {
  }

  Player& Opponent(Player player);

  void SpecialMove(Player& player, int number);

  void Move(Player& player);

  void SeaBattle();
};

#endif //TP_SEA_BATTLE__GAME_H_
