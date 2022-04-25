#ifndef TP_SEA_BATTLE__FIELD_H_
#define TP_SEA_BATTLE__FIELD_H_
#include "square.h"

class Field {
 public:
  Square own_field[10][10]{};
  Square opp_field[10][10]{};

  bool IsDied(int i, int j);
};

#endif //TP_SEA_BATTLE__FIELD_H_
