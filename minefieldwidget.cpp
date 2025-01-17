#include "minefieldwidget.h"

#include <QAction>

MineFieldWidget::MineFieldWidget(MineField* field, QWidget *parent)
  : QWidget{parent},
    _field(field)
{
  grid = new QGridLayout(this);
  buildGridChildren();
}

MineFieldWidget::~MineFieldWidget()
{
  delete _field;
  delete grid;
  for (QPushButton* btn: _buttons) {
    delete btn;
  }
}

void MineFieldWidget::buildGridChildren()
{
  for (int i=0; i<field()->getRows(); i++) {
    for (int j=0; j<field()->getColumns(); j++) {
      QPushButton* btn = new QPushButton();
      btn->connect(btn, &QPushButton::clicked, this, [this, i, j] { handleBtnClicked(i, j); });
      _buttons.push_back(btn);
      grid->addWidget(btn, i, j);
    }
  }
}

void MineFieldWidget::handleBtnClicked(int row, int column) {
  QPushButton* btn = dynamic_cast<QPushButton*>(sender());
  int value = field()->getFieldValue(row, column);
  btn->setText(QString::number(value));
  btn->setDisabled(true);

  // if zero, check for surrounding zeros
  if (value == 0) {
    for (int i=-1; i<=1; i++) {
      for (int j=-1; j<=1; j++) {
        int rowPeek = row + i;
        int columnPeek = column + j;

        // case [row][column] cell skip
        if (rowPeek == row && columnPeek == column) continue;
        // case rowPeek out-of-bounds
        else if (rowPeek < 0 || rowPeek >= field()->getRows()) continue;
        // case columknPeek is out-of-bounds
        else if (columnPeek < 0 || columnPeek >= field()->getColumns()) continue;
        // click surrounding
        else {
          QPushButton* tmp = dynamic_cast<QPushButton*>(grid->itemAtPosition(rowPeek, columnPeek)->widget());
          if (tmp != nullptr) tmp->click();
        }
      }
    }
  }
}
