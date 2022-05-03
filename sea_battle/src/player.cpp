#include "../headers/player.h"

bool Player::operator==(Player other) {
  return (name == other.name);
}

bool Player::IsCorrect(int x, int y, Field& field) {
  for (int i = x - 1; i <= x + 1; ++i) {
    if (field.own_field[i][y].condition == "ship") {
      return false;
    }
  }
  for (int i = y - 1; i <= y + 1; ++i) {
    if (field.own_field[x][i].condition == "ship") {
      return false;
    }
  }
  return true;
}

void Player::Arrangement(int length) {
  std::string str;
  bool correct = true;
  while (correct) {
    Field old_field = field;
    std::cin >> str;
    if (length == 1) {
      if (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8') {
        interface.PrintIncorrectArrangement(str);
        continue;
      }
      if (IsCorrect(str[1] - '0', str[0] - 64, field)) {
        field.own_field[str[1] - '0'][str[0] - 64].condition = "ship";
        correct = false;
      } else {
        interface.PrintIncorrectArrangement(str);
      }
    } else if (str[0] == str[3]) {
      correct = false;
      if (length == 2 && str[4] - str[1] != 1 || length == 3 && str[4] - str[1] != 2
      || length == 4 && str[4] - str[1] != 3 || str[1] < '1' || str[1] > '8' || str[0] < 'A' || str[0] > 'H'
      || str[4] < '1' || str[4] > '8') {
        interface.PrintIncorrectArrangement(str);
        correct = true;
        continue;
      }
      for (int i = 0; i < length; ++i) {
        if (IsCorrect(str[1] - '0' + i, str[0] - 64, old_field)) {
          field.own_field[str[1] - '0' + i][str[0] - 64].condition = "ship";
        } else {
          interface.PrintIncorrectArrangement(str);
          field = old_field;
          correct = true;
          break;
        }
      }
    } else if (str[1] == str[4]) {
      correct = false;
      if (length == 2 && str[3] - str[0] != 1 || length == 3 && str[3] - str[0] != 2
      || length == 4 && str[3] - str[0] != 3 || str[1] < '1' || str[1] > '8' || str[0] < 'A' || str[0] > 'H'
      || str[3] < 'A' || str[3] > 'H') {
        interface.PrintIncorrectArrangement(str);
        correct = true;
        continue;
      }
      for (int i = 0; i < length; ++i) {
        if (IsCorrect(str[1] - '0', str[0] - 64 + i, old_field)) {
          field.own_field[str[1] - '0'][str[0] - 64 + i].condition = "ship";
        } else {
          interface.PrintIncorrectArrangement(str);
          field = old_field;
          correct = true;
          break;
        }
      }
    } else {
      interface.PrintIncorrectArrangement(str);
    }
  }
}

void Player::PlayerArrangement() {
  interface.PrintSingleDeck(name);
  for (int i = 0; i < 4; ++i) {
    Arrangement(1);
  }
  interface.PrintField(field);
  interface.PrintTwoDeck(name);
  for (int i = 0; i < 3; ++i) {
    Arrangement(2);
  }
  interface.PrintField(field);
  interface.PrintThreeDeck(name);
  for (int i = 0; i < 2; ++i) {
    Arrangement(3);
  }
  interface.PrintField(field);
  interface.PrintFourDeck(name);
  Arrangement(4);
}
