/*****************************************************************************
 * QtVlc - C++ bindings for libVLC using Qt awesomeness
 * Copyright (C) 2013 Orochimarufan <orochimarufan.x3@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef VLCVIDEOWIDGET_H
#define VLCVIDEOWIDGET_H

#include <QtWidgets/QFrame>

#include <QtVlc/VlcMediaPlayer.h>

/**
 * @brief The VlcVideoWidget class
 * A simple IVlcVideoDelegate implementation in qt
 */
class VlcVideoWidget : public QFrame, public IVlcVideoDelegate
{
    Q_OBJECT
public:
    explicit VlcVideoWidget( QWidget *parent = 0, QWidget *default_widget = nullptr);
    virtual ~VlcVideoWidget();

    WId request(bool, unsigned int, unsigned int);
    void release();
    void sync();

protected:
    virtual QPaintEngine *paintEngine() const { return nullptr; }

private:
    QWidget *stable;
    QLayout *layout;
    QWidget *default_widget;

signals:
    void sizeChanged(unsigned int, unsigned int);

public slots:
    void setSize(unsigned int, unsigned int);
};


/**
 * @brief The VlcPrimitiveBackgroundWidget class
 * A simple Widget for use as VlcVideoWidget's default_widget
 */
class VlcPrimitiveBackgroundWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VlcPrimitiveBackgroundWidget(QString path, QWidget *parent = 0);
    virtual ~VlcPrimitiveBackgroundWidget();

    QString path() const;

protected:
    void paintEvent(QPaintEvent *);
    bool b_expandPixmap = false;

public slots:
    void setPath(QString);

private:
    QString _path;
};

// inline
inline QString VlcPrimitiveBackgroundWidget::path() const
{
    return _path;
}

#endif // VLCVIDEOWIDGET_H
