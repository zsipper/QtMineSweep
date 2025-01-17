#ifndef MINESWEEP_H
#define MINESWEEP_H

#include "minefield.h"
#include "minefieldwidget.h"

#include <QWidget>

namespace Ui
{
class MineSweep;
}

class MineSweep : public QWidget
{
  Q_OBJECT

public:
  enum Difficulty
  {
    Beginner,
    Intermediate,
    Expert
  };
  Q_ENUM (Difficulty);

  explicit MineSweep (Difficulty difficulty, QWidget *parent = nullptr);
  ~MineSweep ();

private:
  Ui::MineSweep *ui;
  const Difficulty difficulty;
  int score;
  MineField *field;
  MineFieldWidget* fieldWidget;
};

#endif // MINESWEEP_H
