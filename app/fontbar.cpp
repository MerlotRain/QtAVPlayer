#include "fontbar.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QFontComboBox>
#include <QHBoxLayout>
#include <QToolButton>

FontBar::FontBar(QFont f, QWidget *parent)
    : QFrame(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint), m_f(f)
{
    setFixedSize(800, 48);
    QHBoxLayout *h = new QHBoxLayout(this);

    QFontComboBox *fontComboBox = new QFontComboBox(this);
    QComboBox *sizeComboBox = new QComboBox(this);
    sizeComboBox->addItems(QStringList() << "8"
                                         << "9"
                                         << "10"
                                         << "11"
                                         << "12"
                                         << "14"
                                         << "16"
                                         << "18"
                                         << "20"
                                         << "22"
                                         << "24"
                                         << "26"
                                         << "28"
                                         << "36"
                                         << "48");
    QFrame *line1 = new QFrame(this);
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);

    QToolButton *boldButton = new QToolButton(this);
    boldButton->setCheckable(true);
    QToolButton *italicButton = new QToolButton(this);
    italicButton->setCheckable(true);
    QToolButton *underlineButton = new QToolButton(this);
    underlineButton->setCheckable(true);
    QToolButton *strikeOutButton = new QToolButton(this);
    strikeOutButton->setCheckable(true);

    QFrame *line2 = new QFrame(this);
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);

    QButtonGroup *alignGroup = new QButtonGroup(this);
    connect(alignGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled),
            [&](int id, bool clicked) {
                for (auto &b: alignGroup->buttons())
                {
                    b->setChecked(alignGroup->id(b) == id ? clicked : !clicked);
                }
            });
    QToolButton *leftAlign = new QToolButton(this);
    leftAlign->setCheckable(true);
    alignGroup->addButton(leftAlign, 0);
    QToolButton *midAlign = new QToolButton(this);
    midAlign->setCheckable(true);
    alignGroup->addButton(midAlign, 1);
    QToolButton *rightAlign = new QToolButton(this);
    rightAlign->setCheckable(true);
    alignGroup->addButton(rightAlign, 2);

    QFrame *line3 = new QFrame(this);
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Sunken);

    QCheckBox *checkBox = new QCheckBox(this);
    checkBox->setText(tr("Full Background"));
}

FontBar::~FontBar()
{
}

void FontBar::onFontFamilyChange(const QString &family)
{
}

void FontBar::onFontSizeChange(int size)
{
}

void FontBar::onBoldChange(bool b)
{
}

void FontBar::onItalicChange(bool b)
{
}

void FontBar::onUnderLineChange(bool b)
{
}

void FontBar::onStrikeOutChange(bool b)
{
}

void FontBar::onAlignChange(Qt::AlignmentFlag algn)
{
}

void FontBar::onFullBackgroundChange(bool b)
{
}
