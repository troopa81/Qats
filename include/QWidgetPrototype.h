/****************************************************************************
**
** Copyright (C) 2015 Cabieces Julien
** Contact: https://github.com/troopa81/Qats
**
** This file is part of Qats.
**
** Qats is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Qats is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with Qats. If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef _QWIDGETPROTOTYPE_
#define _QWIDGETPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QWidget>
#include "QObjectPrototype.h"

namespace qats
{

class QWidgetPrototype : public QObjectPrototype
{
Q_OBJECT

public:

QWidgetPrototype(QObject* parent = 0):QObjectPrototype(parent){}
public slots:

int devType()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->devType();
}
WId winId()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->winId();
}
void createWinId()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->createWinId();
}
inline WId internalWinId()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->internalWinId();
}
WId effectiveWinId()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->effectiveWinId();
}
QStyle * style()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->style();
}
void setStyle(QStyle * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setStyle(param0);
}
bool isTopLevel()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isTopLevel();
}
bool isWindow()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isWindow();
}
bool isModal()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isModal();
}
Qt::WindowModality windowModality()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowModality();
}
void setWindowModality(Qt::WindowModality windowModality)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowModality(windowModality);
}
bool isEnabled()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isEnabled();
}
bool isEnabledTo(const QWidget * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isEnabledTo(param0);
}
bool isEnabledToTLW()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isEnabledToTLW();
}
void setEnabled(bool param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setEnabled(param0);
}
void setDisabled(bool param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setDisabled(param0);
}
void setWindowModified(bool param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowModified(param0);
}
QRect frameGeometry()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->frameGeometry();
}
const QRect & geometry()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->geometry();
}
QRect normalGeometry()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->normalGeometry();
}
int x()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->x();
}
int y()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->y();
}
QPoint pos()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->pos();
}
QSize frameSize()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->frameSize();
}
QSize size()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->size();
}
inline int width()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->width();
}
inline int height()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->height();
}
QRect childrenRect()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->childrenRect();
}
QRegion childrenRegion()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->childrenRegion();
}
QSize minimumSize()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->minimumSize();
}
QSize maximumSize()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->maximumSize();
}
int minimumWidth()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->minimumWidth();
}
int minimumHeight()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->minimumHeight();
}
int maximumWidth()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->maximumWidth();
}
int maximumHeight()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->maximumHeight();
}
void setMinimumSize(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMinimumSize(param0);
}
void setMinimumSize(int minw,int minh)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMinimumSize(minw,minh);
}
void setMaximumSize(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMaximumSize(param0);
}
void setMaximumSize(int maxw,int maxh)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMaximumSize(maxw,maxh);
}
void setMinimumWidth(int minw)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMinimumWidth(minw);
}
void setMinimumHeight(int minh)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMinimumHeight(minh);
}
void setMaximumWidth(int maxw)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMaximumWidth(maxw);
}
void setMaximumHeight(int maxh)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMaximumHeight(maxh);
}
QSize sizeIncrement()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->sizeIncrement();
}
void setSizeIncrement(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setSizeIncrement(param0);
}
void setSizeIncrement(int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setSizeIncrement(w,h);
}
QSize baseSize()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->baseSize();
}
void setBaseSize(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setBaseSize(param0);
}
void setBaseSize(int basew,int baseh)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setBaseSize(basew,baseh);
}
void setFixedSize(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFixedSize(param0);
}
void setFixedSize(int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFixedSize(w,h);
}
void setFixedWidth(int w)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFixedWidth(w);
}
void setFixedHeight(int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFixedHeight(h);
}
QPoint mapToGlobal(const QPoint& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapToGlobal(param0);
}
QPoint mapFromGlobal(const QPoint& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapFromGlobal(param0);
}
QPoint mapToParent(const QPoint& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapToParent(param0);
}
QPoint mapFromParent(const QPoint& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapFromParent(param0);
}
QPoint mapTo(const QWidget * param0,const QPoint& param1)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapTo(param0,param1);
}
QPoint mapFrom(const QWidget * param0,const QPoint& param1)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mapFrom(param0,param1);
}
QWidget * window()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->window();
}
QWidget * nativeParentWidget()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->nativeParentWidget();
}
inline QWidget * topLevelWidget()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->topLevelWidget();
}
const QPalette & palette()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->palette();
}
void setPalette(const QPalette& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setPalette(param0);
}
void setBackgroundRole(QPalette::ColorRole param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setBackgroundRole(param0);
}
QPalette::ColorRole backgroundRole()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->backgroundRole();
}
void setForegroundRole(QPalette::ColorRole param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setForegroundRole(param0);
}
QPalette::ColorRole foregroundRole()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->foregroundRole();
}
const QFont & font()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->font();
}
void setFont(const QFont& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFont(param0);
}
QFontMetrics fontMetrics()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->fontMetrics();
}
QFontInfo fontInfo()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->fontInfo();
}
QCursor cursor()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->cursor();
}
void setCursor(const QCursor& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setCursor(param0);
}
void unsetCursor()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->unsetCursor();
}
void setMouseTracking(bool enable)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMouseTracking(enable);
}
bool hasMouseTracking()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->hasMouseTracking();
}
bool underMouse()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->underMouse();
}
void setMask(const QBitmap& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMask(param0);
}
void setMask(const QRegion& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setMask(param0);
}
QRegion mask()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->mask();
}
void clearMask()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->clearMask();
}
void render(QPaintDevice * target,const QPoint & targetOffset = QPoint(),const QRegion & sourceRegion = QRegion(),QWidget::RenderFlags renderFlags = QWidget::RenderFlags(QWidget::DrawWindowBackground|QWidget::DrawChildren))
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->render(target,targetOffset,sourceRegion,renderFlags);
}
void render(QPainter * painter,const QPoint & targetOffset = QPoint(),const QRegion & sourceRegion = QRegion(),QWidget::RenderFlags renderFlags = QWidget::RenderFlags(QWidget::DrawWindowBackground|QWidget::DrawChildren))
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->render(painter,targetOffset,sourceRegion,renderFlags);
}
Q_INVOKABLE QPixmap grab(const QRect & rectangle)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->grab(rectangle);
}
QGraphicsEffect * graphicsEffect()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->graphicsEffect();
}
void setGraphicsEffect(QGraphicsEffect * effect)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setGraphicsEffect(effect);
}
void grabGesture(Qt::GestureType type,Qt::GestureFlags flags = Qt::GestureFlags())
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->grabGesture(type,flags);
}
void ungrabGesture(Qt::GestureType type)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->ungrabGesture(type);
}
void setWindowTitle(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowTitle(param0);
}
void setStyleSheet(const QString & styleSheet)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setStyleSheet(styleSheet);
}
QString styleSheet()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->styleSheet();
}
QString windowTitle()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowTitle();
}
void setWindowIcon(const QIcon & icon)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowIcon(icon);
}
QIcon windowIcon()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowIcon();
}
void setWindowIconText(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowIconText(param0);
}
QString windowIconText()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowIconText();
}
void setWindowRole(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowRole(param0);
}
QString windowRole()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowRole();
}
void setWindowFilePath(const QString & filePath)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowFilePath(filePath);
}
QString windowFilePath()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowFilePath();
}
void setWindowOpacity(qreal level)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowOpacity(level);
}
qreal windowOpacity()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowOpacity();
}
bool isWindowModified()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isWindowModified();
}
void setToolTip(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setToolTip(param0);
}
QString toolTip()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->toolTip();
}
void setToolTipDuration(int msec)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setToolTipDuration(msec);
}
int toolTipDuration()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->toolTipDuration();
}
void setStatusTip(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setStatusTip(param0);
}
QString statusTip()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->statusTip();
}
void setWhatsThis(const QString& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWhatsThis(param0);
}
QString whatsThis()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->whatsThis();
}
QString accessibleName()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->accessibleName();
}
void setAccessibleName(const QString & name)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setAccessibleName(name);
}
QString accessibleDescription()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->accessibleDescription();
}
void setAccessibleDescription(const QString & description)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setAccessibleDescription(description);
}
void setLayoutDirection(Qt::LayoutDirection direction)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setLayoutDirection(direction);
}
Qt::LayoutDirection layoutDirection()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->layoutDirection();
}
void unsetLayoutDirection()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->unsetLayoutDirection();
}
void setLocale(const QLocale & locale)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setLocale(locale);
}
QLocale locale()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->locale();
}
void unsetLocale()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->unsetLocale();
}
inline bool isRightToLeft()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isRightToLeft();
}
inline bool isLeftToRight()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isLeftToRight();
}
inline void setFocus()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->setFocus();
}
bool isActiveWindow()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isActiveWindow();
}
void activateWindow()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->activateWindow();
}
void clearFocus()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->clearFocus();
}
void setFocus(Qt::FocusReason reason)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFocus(reason);
}
Qt::FocusPolicy focusPolicy()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->focusPolicy();
}
void setFocusPolicy(Qt::FocusPolicy policy)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFocusPolicy(policy);
}
bool hasFocus()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->hasFocus();
}
void setTabOrder(QWidget * param0,QWidget * param1)
{
QWidget::setTabOrder(param0,param1);
}
void setFocusProxy(QWidget * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setFocusProxy(param0);
}
QWidget * focusProxy()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->focusProxy();
}
Qt::ContextMenuPolicy contextMenuPolicy()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->contextMenuPolicy();
}
void setContextMenuPolicy(Qt::ContextMenuPolicy policy)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setContextMenuPolicy(policy);
}
void grabMouse()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->grabMouse();
}
void grabMouse(const QCursor& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->grabMouse(param0);
}
void releaseMouse()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->releaseMouse();
}
void grabKeyboard()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->grabKeyboard();
}
void releaseKeyboard()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->releaseKeyboard();
}
int grabShortcut(const QKeySequence & key,Qt::ShortcutContext context = Qt::WindowShortcut)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->grabShortcut(key,context);
}
void releaseShortcut(int id)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->releaseShortcut(id);
}
void setShortcutEnabled(int id,bool enable = true)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setShortcutEnabled(id,enable);
}
void setShortcutAutoRepeat(int id,bool enable = true)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setShortcutAutoRepeat(id,enable);
}
QWidget * mouseGrabber()
{
return QWidget::mouseGrabber();
}
QWidget * keyboardGrabber()
{
return QWidget::keyboardGrabber();
}
inline bool updatesEnabled()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->updatesEnabled();
}
void setUpdatesEnabled(bool enable)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setUpdatesEnabled(enable);
}
QGraphicsProxyWidget * graphicsProxyWidget()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->graphicsProxyWidget();
}
void update()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->update();
}
void repaint()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->repaint();
}
inline void update(int x,int y,int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->update(x,y,w,h);
}
void update(const QRect& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->update(param0);
}
void update(const QRegion& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->update(param0);
}
void repaint(int x,int y,int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->repaint(x,y,w,h);
}
void repaint(const QRect& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->repaint(param0);
}
void repaint(const QRegion& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->repaint(param0);
}
void setVisible(bool visible)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setVisible(visible);
}
void setHidden(bool hidden)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setHidden(hidden);
}
void show()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->show();
}
void hide()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->hide();
}
void showMinimized()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->showMinimized();
}
void showMaximized()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->showMaximized();
}
void showFullScreen()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->showFullScreen();
}
void showNormal()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->showNormal();
}
bool close()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->close();
}
void raise()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->raise();
}
void lower()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->lower();
}
void stackUnder(QWidget * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->stackUnder(param0);
}
void move(int x,int y)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->move(x,y);
}
void move(const QPoint& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->move(param0);
}
void resize(int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->resize(w,h);
}
void resize(const QSize& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->resize(param0);
}
inline void setGeometry(int x,int y,int w,int h)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->setGeometry(x,y,w,h);
}
void setGeometry(const QRect& param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setGeometry(param0);
}
QByteArray saveGeometry()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->saveGeometry();
}
bool restoreGeometry(const QByteArray & geometry)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->restoreGeometry(geometry);
}
void adjustSize()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->adjustSize();
}
bool isVisible()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isVisible();
}
bool isVisibleTo(const QWidget * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isVisibleTo(param0);
}
inline bool isHidden()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isHidden();
}
bool isMinimized()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isMinimized();
}
bool isMaximized()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isMaximized();
}
bool isFullScreen()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isFullScreen();
}
Qt::WindowStates windowState()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowState();
}
void setWindowState(Qt::WindowStates state)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowState(state);
}
void overrideWindowState(Qt::WindowStates state)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->overrideWindowState(state);
}
QSize sizeHint()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->sizeHint();
}
QSize minimumSizeHint()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->minimumSizeHint();
}
QSizePolicy sizePolicy()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->sizePolicy();
}
void setSizePolicy(QSizePolicy param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setSizePolicy(param0);
}
inline void setSizePolicy(QSizePolicy::Policy horizontal,QSizePolicy::Policy vertical)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->setSizePolicy(horizontal,vertical);
}
int heightForWidth(int param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->heightForWidth(param0);
}
bool hasHeightForWidth()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->hasHeightForWidth();
}
QRegion visibleRegion()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->visibleRegion();
}
void setContentsMargins(int left,int top,int right,int bottom)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setContentsMargins(left,top,right,bottom);
}
void setContentsMargins(const QMargins & margins)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setContentsMargins(margins);
}
void getContentsMargins(int * left,int * top,int * right,int * bottom)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->getContentsMargins(left,top,right,bottom);
}
QMargins contentsMargins()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->contentsMargins();
}
QRect contentsRect()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->contentsRect();
}
QLayout * layout()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->layout();
}
void setLayout(QLayout * param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setLayout(param0);
}
void updateGeometry()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->updateGeometry();
}
void setParent(QWidget * parent)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setParent(parent);
}
void setParent(QWidget * parent,Qt::WindowFlags f)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setParent(parent,f);
}
void scroll(int dx,int dy)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->scroll(dx,dy);
}
void scroll(int dx,int dy,const QRect& param2)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->scroll(dx,dy,param2);
}
QWidget * focusWidget()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->focusWidget();
}
QWidget * nextInFocusChain()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->nextInFocusChain();
}
QWidget * previousInFocusChain()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->previousInFocusChain();
}
bool acceptDrops()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->acceptDrops();
}
void setAcceptDrops(bool on)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setAcceptDrops(on);
}
void addAction(QAction * action)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->addAction(action);
}
void addActions(QList<QAction *> actions)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->addActions(actions);
}
void insertAction(QAction * before,QAction * action)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->insertAction(before,action);
}
void insertActions(QAction * before,QList<QAction *> actions)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->insertActions(before,actions);
}
void removeAction(QAction * action)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->removeAction(action);
}
QList<QAction *> actions()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->actions();
}
QWidget * parentWidget()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->parentWidget();
}
void setWindowFlags(Qt::WindowFlags type)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setWindowFlags(type);
}
inline Qt::WindowFlags windowFlags()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowFlags();
}
void overrideWindowFlags(Qt::WindowFlags type)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->overrideWindowFlags(type);
}
inline Qt::WindowType windowType()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowType();
}
QWidget * find(WId param0)
{
return QWidget::find(param0);
}
inline QWidget * childAt(int x,int y)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->childAt(x,y);
}
QWidget * childAt(const QPoint & p)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->childAt(p);
}
void setAttribute(Qt::WidgetAttribute param0,bool on = true)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setAttribute(param0,on);
}
inline bool testAttribute(Qt::WidgetAttribute param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->testAttribute(param0);
}
QPaintEngine * paintEngine()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->paintEngine();
}
void ensurePolished()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->ensurePolished();
}
bool isAncestorOf(const QWidget * child)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->isAncestorOf(child);
}
bool autoFillBackground()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->autoFillBackground();
}
void setAutoFillBackground(bool enabled)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setAutoFillBackground(enabled);
}
QBackingStore * backingStore()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->backingStore();
}
QWindow * windowHandle()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->windowHandle();
}
QWidget * createWindowContainer(QWindow * window,QWidget * parent = 0,Qt::WindowFlags flags = 0)
{
return QWidget::createWindowContainer(window,parent,flags);
}
QVariant inputMethodQuery(Qt::InputMethodQuery param0)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->inputMethodQuery(param0);
}
Qt::InputMethodHints inputMethodHints()
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
return object->inputMethodHints();
}
void setInputMethodHints(Qt::InputMethodHints hints)
{
QWidget *object = qscriptvalue_cast<QWidget*>(thisObject());
object->setInputMethodHints(hints);
}
};
}

#endif
