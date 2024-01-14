
#ifndef IMAGEFADE_H
#define IMAGEFADE_H

#include "QThread"
#include "QImage"
#include "QUrl"
#include "QDir"
#include "QPainter"



class ImageFade : public QThread
{

private:
    QImage m_source;
    QImage m_target;
    QUrl m_destination;
    int m_steps;

public:    
    ImageFade(const QImage& source, const QImage& target, const QUrl& dest, int steps) : m_source(source), m_target(target), m_destination(dest){
        m_steps = steps;
    };

protected:
    void run() override{
        for (int i = 0; i < m_steps; ++i) {
            QDir outputDir(m_destination.toLocalFile());
            if(!outputDir.exists()){
                qDebug() << "Directory doesn't exists!";
            }

            qreal alpha = static_cast<qreal>(i) / m_steps;

            QImage blendedImage(m_source.size(), QImage::Format_A2RGB30_Premultiplied);
            QPainter painter(&blendedImage);
            painter.setOpacity(1.0 - alpha);
            painter.drawImage(0, 0, m_source);
            painter.setOpacity(alpha);
            painter.drawImage(0, 0, m_target);
            painter.end();

            QString fileName = QString("blend_step%1.png").arg(i);
            blendedImage.save(outputDir.filePath(fileName));
            QThread::sleep(5);
        }
    }
};

#endif // IMAGEFADE_H
