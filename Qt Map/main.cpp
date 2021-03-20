#include <QTextStream>
#include <QMap>

int main(void) {

    QTextStream out(stdout);

    QMap<QString, int> items = { {"coins", 5}, {"books", 3} };

    items.insert("bottles", 7);

    out << "Values:" << endl;

    QList<int> values = items.values();

    for (int val : values) {
        out << val << endl;
    }


    out << "Keys:" << endl;

    QList<QString> keys = items.keys();

    for (QString key : keys) {
        out << key << endl;
    }

    QMapIterator<QString, int> it(items);

    out << "Pairs:" << endl;

    while (it.hasNext()) {
        it.next();
        out << it.key() << ": " << it.value() << endl;
    }
}
