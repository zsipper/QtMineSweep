#include "mainwindow.h"
#include "minesweep.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget *parent)
  : QMainWindow (parent), ui (new Ui::MainWindow)
{
  ui->setupUi (this);

  connect (ui->beginner, SIGNAL (clicked()), this, SLOT (hide ()));
  connect (ui->intermediate, SIGNAL (clicked()), this, SLOT (hide ()));
  connect (ui->expert, SIGNAL (clicked()), this, SLOT (hide ()));

  connect (ui->beginner, SIGNAL (clicked ()), this, SLOT(handleBeginnerClicked()));
  connect (ui->intermediate, SIGNAL (clicked()), this, SLOT (handleIntermediateClicked()));
  connect (ui->expert, SIGNAL (clicked()), this, SLOT (handleExpertClicked()));
}

MainWindow::~MainWindow () { delete ui; }

void MainWindow::handleBeginnerClicked()
{
  MineSweep* game = new MineSweep (MineSweep::Difficulty::Beginner);
  game->show();
}

void MainWindow::handleIntermediateClicked()
{
  MineSweep* game = new MineSweep (MineSweep::Difficulty::Intermediate);
  game->show();
}

void MainWindow::handleExpertClicked()
{
  MineSweep* game = new MineSweep (MineSweep::Difficulty::Expert);
  game->show();
}

