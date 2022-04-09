#ifndef TP_SEA_BATTLE__GAME_H_
#define TP_SEA_BATTLE__GAME_H_
#include "player.h"

class Game {
 public:
  Player first;
  Player second;

  Player& Opponent(Player player) {
    if (player == first) {
      return second;
    }
    return first;
  }

  bool game = true;

  void Move(Player& player) {
    std::cout << player.name << ", ваш ход: ";
    std::string str;
    std::cin >> str;
    if (player.field.opp_field[str[1] - '0'][str[0] - 64].condition == "ship") {
      Opponent(player).field.own_field[str[1] - '0'][str[0] - 64].condition = "beaten_ship";
      player.field.opp_field[str[1] - '0'][str[0] - 64].condition = "beaten_ship";
      if (Opponent(player).field.IsDied(str[1] - '0', str[0] - 64)) {
        std::cout << "\nПотопил\n\n";
        ++(player.points);
      } else {
        std::cout << "\nРанил\n\n";
      }
    } else {
      Opponent(player).field.own_field[str[1] - '0'][str[0] - 64].condition = "beaten_empty";
      player.field.opp_field[str[1] - '0'][str[0] - 64].condition = "beaten_empty";
      std::cout << "\nМимо\n";
      player.move = false;
      Opponent(player).move = true;
    }
    std::cout << "Нажмите любую кнопку: ";
    std::cin >> str;
    std::cout << "\n";
  }

  void SeaBattle() {
    std::string first_player_name;
    std::string second_player_name;
    std::cout << "Игрок 1, введите своё имя: ";
    std::cin >> first_player_name;
    first.name = first_player_name;
    std::cout << "\nИгрок 2, введите своё имя: ";
    std::cin >> second_player_name;
    second.name = second_player_name;
    first.move = true, second.move = false;
    first.PlayerArrangement();
    second.PlayerArrangement();
    for (int i = 1; i < 9; ++i) {
      for (int j = 1; j < 9; ++j) {
        first.field.opp_field[i][j].condition = second.field.own_field[i][j].condition;
        second.field.opp_field[i][j].condition = first.field.own_field[i][j].condition;
      }
    }
    while (game) {
      if (first.move) {
        first.field.Print();
        Move(first);
        if (first.points == 10) {
          std::cout << first.name << " победил!";
          game = false;
        }
      } else {
        second.field.Print();
        Move(second);
        if (second.points == 10) {
          std::cout << second.name << " победил!";
          game = false;
        }
      }
    }
  }
};

#endif //TP_SEA_BATTLE__GAME_H_
