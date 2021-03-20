#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QTimer>

int main(int argc, char **argv) {

   QCoreApplication app(argc, argv);

   QTextStream out(stdout);

   QDate cd = QDate::currentDate();
   QTime ct = QTime::currentTime();

   QDate dt1(2015, 4, 12);
   out << "The date is " << dt1.toString() << endl;
   out << "Current date is: " << cd.toString() << endl;
   out << "Today is " << cd.toString("yyyy-MM-dd") << endl;

   QTime tm1(17, 30, 12, 55);
   out << "The time is " << tm1.toString("hh:mm:ss.zzz") << endl;
   out << "Current time is: " << ct.toString() << endl;

   QList<int> years({2010, 2011, 2012, 2013, 2014, 2015, 2016});

   foreach (int year, years) {
      out << "Is year: " << year << endl;
    }

   QList<QString> months;

   months.append("January");
   months.append("February");
   months.append("March");
   months.append("April");
   months.append("May");
   months.append("June");
   months.append("July");
   months.append("August");
   months.append("September");
   months.append("October");
   months.append("November");
   months.append("December");

   out << "Today is " << cd.day() << " " << months.at(cd.month()-1) << " " << cd.year() << endl;


   QTimer::singleShot(3000,&app,SLOT(quit()));
   return app.exec();
}
