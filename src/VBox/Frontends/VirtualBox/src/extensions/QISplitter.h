/** @file
 *
 * VBox frontends: Qt GUI ("VirtualBox"):
 * VirtualBox Qt extensions: QISplitter class declaration
 */

/*
 * Copyright (C) 2009-2010 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef _QISplitter_h_
#define _QISplitter_h_

/* Global includes */
#include <QSplitter>

class QISplitter : public QSplitter
{
    Q_OBJECT;

public:

    enum Type { Native, Shade };

    QISplitter(QWidget *aParent = 0);
    QISplitter(Qt::Orientation orientation = Qt::Horizontal, QWidget *pParent = 0);

    void setHandleType(Type type) { m_type = type; }
    Type handleType() const { return m_type; }
private:

    bool eventFilter(QObject *aWatched, QEvent *aEvent);
    void showEvent(QShowEvent *aEvent);

    QSplitterHandle* createHandle();

    QByteArray mBaseState;

    bool mPolished;
    Type m_type;
};

#endif /* _QISplitter_h_ */

