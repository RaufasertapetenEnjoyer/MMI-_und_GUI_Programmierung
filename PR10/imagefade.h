#ifndef IMAGEFADE_H
#define IMAGEFADE_H

#include "QThread"
#include "QImage"
#include "QUrl"
#include "QDir"
#include "QPainter"
#include "QString"

#include <QObject>

class ImageFade : public QObject
{

Q_OBJECT

signals:
    void updateBar(qreal percentage);
    void stillRunning(bool running);
    void sendMessage(QString message);

public:

    explicit ImageFade(QObject *parent = nullptr);

    Q_INVOKABLE void run(const QImage& source, const QImage& target, const QUrl& dest, int steps) {
        emit updateBar(0);

        emit stillRunning(true);
        qDebug() << "Running thread" << QThread::currentThreadId();
        for (int i = 0; i < steps; ++i) {
            QDir outputDir(dest.toLocalFile());
            if(!outputDir.exists()){
                qDebug() << "Directory doesn't exists!";
            }

            qreal alpha = static_cast<qreal>(i) / steps;

            QImage blendedImage(source.size(), QImage::Format_A2RGB30_Premultiplied);
            QPainter painter(&blendedImage);
            painter.setOpacity(1.0 - alpha);
            painter.drawImage(0, 0, source);
            painter.setOpacity(alpha);
            painter.drawImage(0, 0, target);
            painter.end();

            QString fileName = QString("blend_step%1.png").arg(i);
            blendedImage.save(outputDir.filePath(fileName));
            emit sendMessage("Image " + QString::number(i+1) + " of " + QString::number(steps) + " generated: " + fileName);
            emit updateBar(alpha * 100);
            qDebug() << alpha;
            QThread::sleep(5);
        }

        emit updateBar(100);
        emit stillRunning(false);
        emit sendMessage("Program ended successfully.");
    }
};

#endif // IMAGEFADE_H
