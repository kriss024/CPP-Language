#include <QTextStream>

int main(void) {

  QTextStream out(stdout);

  QString str = "There are many stars.";

  foreach (QChar qc, str) {
    out << qc << " ";
  }

  out << endl;

  for (QChar *it=str.begin(); it!=str.end(); ++it) {
    out << *it << " " ;
  }

  out << endl;

  for (int i = 0; i < str.size(); ++i) {
    out << str.at(i) << " ";
  }

  out << endl;


  QString s1 = "12";
  QString s2 = "15";
  QString s3, s4;

  out << s1.toInt() + s2.toInt() << endl;

  int n1 = 30;
  int n2 = 40;

  out << s3.setNum(n1) + s4.setNum(n2) << endl;


  return 0;
}
