#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <QList>

class MineField
{
public:


  // named Ctors for different game difficulties
  static MineField *
  createBeginner ()
  {
    return new MineField (8, 8, 10);
  }
  static MineField *
  createIntermediate ()
  {
    return new MineField (16, 16, 40);
  }
  static MineField *
  createExpert ()
  {
    return new MineField (16, 30, 99);
  }

  int getRows() const;

  int getColumns() const;

  int getFieldValue(int row, int column) const { return field[row][column]; }

private:
  int rows;
  int columns;
  int numMines;
  QList<QList<int>> field;

  MineField (int rows, int columns, int numMines);

  // increments all the cells surrounding the given co-ords
  void incrementSurrounding(int row, int column);
};

#endif // MINEFIELD_H
