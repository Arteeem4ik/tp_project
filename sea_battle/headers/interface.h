#ifndef TP_SEA_BATTLE__INTERFACE_H_
#define TP_SEA_BATTLE__INTERFACE_H_

#include <string>
#include "field.h"

class Interface {
 public:
  static void PrintField(Field& field);

  static void PrintIncorrectArrangement(std::string str);

  static void PrintSingleDeck(std::string name);

  static void PrintTwoDeck(std::string name);

  static void PrintThreeDeck(std::string name);

  static void PrintFourDeck(std::string name);

  static void PrintMove(std::string name);

  static void PrintIncorectMove();

  static void PrintIncorrectShoot();

  static void PrintInfo();

  static void PrintInjure();

  static void PrintMissed();

  static void PrintSunk();

  static void PrintReadPassword(std::string name);

  static void PrintFirstPresentation();

  static void PrintSecondPresentation();

  static void PrintEnd(std::string name);

  static void PrintIncorrectPassword(std::string name);

  static void PrintPassword(std::string name);

  static void EnterName(std::string& name);

  static void EnterPassword(std::string& password);

  static void AddPassword(std::string& password);

  static void EnterMove(std::string& move);

  static void PrintUsedSpecialMove();

  static void PrintIncorrectSpecialMove();

  static void PrintHit();
};

#endif //TP_SEA_BATTLE__INTERFACE_H_
