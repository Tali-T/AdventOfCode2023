#include <QCoreApplication>
#include <QFile>
#include <QRegularExpression>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "=====Starting=====";

    const QString input_Filename = "input_data.txt";
    const static QRegularExpression regex_NumbersOnly(QString("[^0-9]+"));

    QFile input_File(input_Filename);
    input_File.open(QIODevice::ReadOnly | QIODevice::Text);

    int accumilator = 0;
    while (!input_File.atEnd()) {
        QByteArray line = input_File.readLine();
        QString lineStr = QString(line);
        QString lineStr_NumbersOnly = lineStr.split(regex_NumbersOnly, Qt::SkipEmptyParts).join("").replace("\n","");

        QString first_Number = lineStr_NumbersOnly.first(1);
        QString last_Number = lineStr_NumbersOnly.last(1);
        QString line_Result = first_Number + last_Number;

        accumilator += line_Result.toInt();

        qDebug() << QString("[%1] to [%2] and got [%3 + %4 = %5]").arg(lineStr, lineStr_NumbersOnly, first_Number, last_Number, line_Result);
    }

    qDebug() << QString("Final Result: %1").arg(QString::number(accumilator));

    return a.exec();
}
