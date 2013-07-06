/** @file
 *
 * VBox frontends: Qt GUI ("VirtualBox"):
 * UIPopupPaneTextPane class declaration
 */

/*
 * Copyright (C) 2013 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef __UIPopupPaneTextPane_h__
#define __UIPopupPaneTextPane_h__

/* Qt includes: */
#include <QWidget>

/* GUI includes: */
#include "QIWithRetranslateUI.h"

/* Forward declarations: */
class QLabel;
class QCheckBox;
class UIAnimation;

/* Popup-pane text-pane prototype class: */
class UIPopupPaneTextPane : public QIWithRetranslateUI<QWidget>
{
    Q_OBJECT;
    Q_PROPERTY(QSize collapsedSizeHint READ collapsedSizeHint);
    Q_PROPERTY(QSize expandedSizeHint READ expandedSizeHint);
    Q_PROPERTY(QSize minimumSizeHint READ minimumSizeHint WRITE setMinimumSizeHint);

signals:

    /* Notifiers: Parent propagation stuff: */
    void sigFocusEnter();
    void sigFocusLeave();

    /* Notifier: Layout stuff: */
    void sigSizeHintChanged();

public:

    /* Constructor: */
    UIPopupPaneTextPane(QWidget *pParent = 0);

    /* API: Text stuff: */
    void setText(const QString &strText);

    /* API: Desired-width stuff: */
    void setDesiredWidth(int iDesiredWidth);

    /* API: Auto-confirmation stuff: */
    void setProposeAutoConfirmation(bool fPropose);
    bool autoConfirmationProposed() const;
    bool isAutoConfirmed() const;

    /* API: Layout stuff: */
    QSize minimumSizeHint() const;
    void setMinimumSizeHint(const QSize &minimumSizeHint);
    void layoutContent();

private slots:

    /* Handlers: Focus stuff: */
    void sltFocusEnter();
    void sltFocusLeave();

private:

    /* Helpers: Prepare stuff: */
    void prepare();
    void prepareContent();

    /* Helper: Translate stuff: */
    void retranslateUi();

    /* Helper: Layout stuff: */
    void updateSizeHint();

    /* Property: Focus stuff: */
    QSize collapsedSizeHint() const { return m_collapsedSizeHint; }
    QSize expandedSizeHint() const { return m_expandedSizeHint; }

    /* Variables: Layout stuff: */
    const int m_iLayoutMargin;
    const int m_iLayoutSpacing;
    QSize m_labelSizeHint;
    QSize m_checkBoxSizeHint;
    QSize m_collapsedSizeHint;
    QSize m_expandedSizeHint;
    QSize m_minimumSizeHint;

    /* Variables: Widget stuff: */
    QLabel *m_pLabel;
    int m_iDesiredLabelWidth;
    QCheckBox *m_pAutoConfirmCheckBox;
    bool m_fProposeAutoConfirmation;

    /* Variables: Focus stuff: */
    bool m_fFocused;
    UIAnimation *m_pAnimation;
};

#endif /* __UIPopupPaneTextPane_h__ */