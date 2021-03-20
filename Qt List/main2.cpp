#include <QList>
#include <QDebug>

int main()
{
  QList<int> values;
  values << 1 << 10 << 5 << 6 << 7 << 3;
  qSort(values);

  QList<int>::iterator i;
  for (i = values.begin(); i != values.end(); i++)
  qDebug() << *i;

  return 0;
}
