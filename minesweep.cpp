#include "minesweep.h"
#include "ui_minesweep.h"

#include <QMetaEnum>

MineSweep::MineSweep (Difficulty difficulty, QWidget *parent)
  : QWidget (parent), ui (new Ui::MineSweep), difficulty (difficulty),
    score (0)
{
  // init the mine field
  switch (difficulty)
  {
  case Beginner:
    this->field = MineField::createBeginner ();
    break;
  case Intermediate:
    this->field = MineField::createIntermediate ();
    break;
  case Expert:
    this->field = MineField::createExpert ();
    break;
  }

  // ui stuff below
  ui->setupUi (this);
  // QMetaEnum meta = QMetaEnum::fromType<MineSweep::Difficulty> ();
  //ui->difficultyDisplay->setText (meta.valueToKey (this->difficulty));

  // adding the grid
  MineFieldWidget* fieldWidget = new MineFieldWidget(this->field, this);
  // ui->verticalLayout->addWidget(fieldWidget);
}

MineSweep::~MineSweep ()
{
  delete ui;
  delete field;
  delete fieldWidget;
}
