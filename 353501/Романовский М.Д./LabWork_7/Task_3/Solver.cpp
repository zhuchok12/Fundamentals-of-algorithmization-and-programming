#include "Solver.h"
#include <climits>
#include <qframe.h>
#include <qnamespace.h>
#include <qtablewidget.h>

const QString alpha =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

QString randString() {
  QString str;
  for (int i = 0; i < 11; i++) {
    if (i % 4 == 3)
      str += '_';
    else
      str += alpha[rand() % alpha.size()];
  }
  return str;
}

Solver::Solver() : HashMap<QString>(255) {
  randomize();
}

void Solver::randomize() {
  clear();
  for (int i = 0; i < 1024; i++) {
    insert(rand(), randString());
  }
}

Solver::~Solver() {}

void Solver::fillEnties(QTableWidget *table) {
  table->setRowCount(0);
  for (int i = 0; i < size; i++) {
    Entry *entr = entries[i];
    if (entr == nullptr)
      continue;

    int firstRow = table->rowCount();
    int spannedRows = 0;
    while (entr != nullptr) {
      int row = table->rowCount();
      table->insertRow(row);
      table->setItem(row, 1, new QTableWidgetItem(QString::number(entr->key)));
      table->setItem(row, 2, new QTableWidgetItem(entr->val));
      entr = entr->next;
      spannedRows++;
    }

    table->setItem(firstRow, 0, new QTableWidgetItem(QString::number(i)));
    if (spannedRows > 1)
      table->setSpan(firstRow, 0, spannedRows, 1);
  }
}

long Solver::findTotalLen() {
  long res = LONG_MAX;
  for (int i = 0; i < size; i++) {
    Entry *entr = entries[i];
    while (entr != nullptr) {
      if (entr->key < res)
        res = entr->key;
      entr = entr->next;
    }
  }
  return res;
}