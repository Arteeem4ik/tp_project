#include "../headers/field.h"

bool Field::IsDied(int i, int j) {
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

