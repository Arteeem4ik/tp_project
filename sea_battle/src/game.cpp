#include "../headers/game.h"
#include "../headers/interface.h"

Player& Game::Opponent(Player player) {
  if (player == first) {
    return second;
  }
  return first;
}

void Game::Move(Player& player) {
  bool change_move = false;
  interface.PrintMove(player.name);
  std::string str;
  bool correct = true;
  while (correct) {
    interface.EnterMove(str);
    if (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8') {
      interface.PrintIncorectMove();
      continue;
    }
    if (player.field.opp_field[str[1] - '0'][str[0] - 64].condition == "beaten_ship") {
      interface.PrintIncorrectShoot();
      continue;
    } else if (player.field.opp_field[str[1] - '0'][str[0] - 64].condition == "ship") {
      Opponent(player).field.own_field[str[1] - '0'][str[0] - 64].condition = "beaten_ship";
      player.field.opp_field[str[1] - '0'][str[0] - 64].condition = "beaten_ship";
      if (Opponent(player).field.IsDied(str[1] - '0', str[0] - 64)) {
        interface.PrintSunk();
        ++(player.points);
      } else {
        interface.PrintInjure();
      }
    } else {
      Opponent(player).field.own_field[str[1] - '0'][str[0] - 64].condition = "beaten_empty";
      player.field.opp_field[str[1] - '0'][str[0] - 64].condition = "beaten_empty";
      interface.PrintMissed();
      player.move = false;
      Opponent(player).move = true;
      change_move = true;
    }
    correct = false;
  }
  if (change_move) {
    bool correct = true;
    while (correct) {
      std::string password;
      interface.PrintReadPassword(Opponent(player).name);
      interface.EnterPassword(password);
      if (password == Opponent(player).password) {
         correct = false;
      } else {
        interface.PrintIncorrectPassword(Opponent(player).name);
      }
    }
  }
}

void Game::SeaBattle() {
  interface.PrintInfo();
  std::string first_player_name;
  std::string second_player_name;
  std::string first_password;
  std::string second_password;
  interface.PrintFirstPresentation();
  interface.EnterName(first_player_name);
  first.name = first_player_name;
  interface.PrintPassword(first.name);
  interface.AddPassword(first_password);
  first.password = first_password;
  interface.PrintSecondPresentation();
  interface.EnterName(second_player_name);
  second.name = second_player_name;
  interface.PrintPassword(second.name);
  interface.AddPassword(second_password);
  second.password = second_password;
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
      interface.PrintField(first.field);
      Move(first);
      if (first.points == 10) {
        Interface::PrintEnd(first.name);
        game = false;
      }
    } else {
      interface.PrintField(second.field);
      Move(second);
      if (second.points == 10) {
        interface.PrintEnd(second.name);
        game = false;
      }
    }
  }
}


