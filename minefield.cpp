#include "minefield.h"

#include <QRandomGenerator>
#include <QString>
#include <QDebug>

int MineField::getRows() const
{
  return rows;
}

int MineField::getColumns() const
{
  return columns;
}

MineField::MineField (int rows, int columns, int numMines)
  : rows (rows), columns (columns), numMines (numMines)
{
  this->field = QList<QList<int>>(rows, QList<int>(columns, 0));

  // generate the mines, and increment surrounding
  for (int i = 0; i < numMines; i++)
  {
    bool mineNotPlaced = true;
    while (mineNotPlaced)
    {
      int row = QRandomGenerator::global()->bounded (rows);
      int column = QRandomGenerator::global()->bounded (columns);

      if (field[row][column] != -1)
      {
        field[row][column] = -1;
        incrementSurrounding(row, column);
        mineNotPlaced = false;
      }
    }
  }
}

void MineField::incrementSurrounding(int row, int column)
{
  // offset for row
  for(int i = -1; i<=1; i++)
  {
    // offset for column
    for (int j=-1; j<=1; j++)
    {
      int rowPeek = row + i;
      int columnPeek = column + j;

      // case [row][column] cell, skip
      if (rowPeek == row && columnPeek == column) continue;
      // case rowPeek out-of-bounds
      else if (rowPeek < 0 || rowPeek >= this->rows) continue;
      // case columnPeek out-of-bounds
      else if (columnPeek < 0 || columnPeek >= this->columns) continue;
      // case cell is mine
      else if (field[rowPeek][columnPeek] == -1) continue;
      // case valid cell
      else field[rowPeek][columnPeek] += 1;
    }
  }
}
