#ifndef MINEFIELDWIDGET_H
#define MINEFIELDWIDGET_H

#include "minefield.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QList>

class MineFieldWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MineFieldWidget(MineField* field, QWidget *parent = nullptr);
  ~MineFieldWidget();

  MineField* field() { return this->_field; }
signals:

public slots:
  void handleBtnClicked(int row, int column);

private:
  MineField* _field;
  QGridLayout* grid;
  QList<QPushButton*> _buttons;

  void buildGridChildren();
};

#endif // MINEFIELDWIDGET_H
