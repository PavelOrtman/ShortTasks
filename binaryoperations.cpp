#include <QDebug>

QString getBinaryString(QString in)
{
    QString out;
    for (qint8 i = in.count()-1; i >= 0; --i) {
        out.prepend(in.at(i));
        if (out.count() == 4 || out.count() == 9 || out.count() == 14) out.prepend(" ");
    }

    while (out.count() < 19) {
        if (out.count() == 4 || out.count() == 9 || out.count() == 14) out.prepend(" ");
        out.prepend("0");
    }

    return out;
}

int main(int argc, char *argv[])
{

    // http://informatics.mccme.ru/mod/book/view.php?id=578&chapterid=306
    // (A) Дано число n<32. Запишите число 2n, то есть число, у которого n-й бит равен 1, а остальные – нули.
    qDebug() << "-- task A 2^n--";
    quint32 n = 6;
    qDebug() << "Input:  " << getBinaryString(QString::number(n, 2)) << "Dec:" << n;
    quint32 t = 1;
    t = t << n;
    qDebug() << "Output: " << getBinaryString(QString::number(t, 2)) << "Dec:" << t;
    qDebug() << "------------";

    // (B) Даны два неравных числа: n и m, не превосходящие 31. Вычислите 2n+2m.
    qDebug() << "-- task B 2^n+2^m--";
    n = 1;
    quint32 m = 2;
    qDebug() << "Input n: " << getBinaryString(QString::number(n, 2)) << "Dec:" << n;
    qDebug() << "Input m: " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    t = 1;
    n = t << n;
    t = 1;
    m = t << m;    
    if(n == m) m = m << 1;
    else{
        m = m ^ n;
    }
    qDebug() << "Output:  " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    qDebug() << "------------";

    // (C) Дано целое число A и натуральное число i. Обнулите у числа A его последние i бит и выведите результат.
    qDebug() << "-- task C --";
    m = 442;    // A
    n = 4;      // i
    qDebug() << "Input m: " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    m = m >> n;
    m = m << n;
    qDebug() << "Output:  " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    qDebug() << "------------";

    // (D) Дано целое число A и натуральное число i. Выведите число, которое получается из числа A установкой значения i-го бита равному 1.
    qDebug() << "-- task D --";
    m = 442;    // A
    n = 3;      // i
    qDebug() << "Input m: " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    t = 1;
    t = t << n;
    m = m | t;
    qDebug() << "Output:  " << getBinaryString(QString::number(m, 2)) << "Dec:" << m;
    qDebug() << "------------";
    return 0;
}
