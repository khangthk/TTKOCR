#include "ocrbackgroundmanager.h"

void OCRBackgroundManager::addObserver(QObject *object)
{
    m_observer << object;
    connect(this, SIGNAL(backgroundChanged()), object, SLOT(backgroundChanged()));
}

void OCRBackgroundManager::removeObserver(QObject *object)
{
    m_observer.removeAll(object);
    disconnect(this, SIGNAL(backgroundChanged()), object, SLOT(backgroundChanged()));
}

void OCRBackgroundManager::setBackgroundUrl(const QString &path)
{
    m_background = path;
}

QString OCRBackgroundManager::backgroundUrl() const
{
    return m_background;
}
