#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

class QImage;
class FractalWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    FractalWidget *m_fractalWidget;
    QImage *m_image[2];
    int m_activeImage;
    QPoint m_mousePosition;
    int m_mouseButtons;
    int m_keyCombination;

    void readSettings();
    void writeSettings();

    static QKeySequence::StandardKey keyForItem(const QString &name);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void updateMouse(QMouseEvent *event);
    void updateMouse(QWheelEvent *event);
    void addKey(QKeyEvent *event);
    void removeKey(QKeyEvent *event);
    void activateMenuItem();
    void updateSize();

 public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createImages();
    void destroyImages();

    char *imageBuffer1();
    char *imageBuffer2();
    int imageBytesPerLine();
    QSize imageSize();

    void switchActiveImage();
    void redrawImage();

    QPoint mousePosition();
    int mouseButtons();
    int keyCombination();

    void showMessage(const QString &message);
    void showError(const QString &error);
    void setCursorType(int type);

    void buildMenu(struct uih_context *uih, const char *name);
    void buildMenu(struct uih_context *uih, const char *name, QMenu *parent);
    void popupMenu(struct uih_context *uih, const char *name);
    void toggleMenu(struct uih_context *uih, const char *name);

    void showDialog(struct uih_context *uih, const char *name);
};

#endif // MAINWINDOW_H