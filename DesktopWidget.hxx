#ifndef DESKTOP_WIDGET_H
#define DESKTOP_WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QVector>
class DesktopPanel;

class DesktopWidget : public QWidget
{
  Q_OBJECT

  public:
    DesktopWidget();

    struct Wallpaper
    {
      QString fileName, mode;
      QColor color;
      QPixmap pixmap;
    };

  protected:
    virtual void paintEvent(QPaintEvent *event);

  private slots:
    void loadSettings();
    void placePanel();
    void desktopChanged();
    void configureWallpaper();
    void configureDisplay();

  private:
    DesktopPanel *panel;

    QVector<Wallpaper> wallpapers;
    int currentDesktop = -1;
};

#endif
