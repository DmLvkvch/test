#include "mainwindowsettings.h"
#include "mainwindowsettingsgrid.h"


#include <QDialog>
#include <QVBoxLayout>
MainWindowSettings::MainWindowSettings(QWidget* parent): QDialog(parent)
{
    setMinimumSize(200, 200);
    tabWidget = new QTabWidget;
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    tabWidget->addTab(new MainWindowSettingsGrid(), tr("Grid view"));
    tabWidget->addTab(new QWidget(), tr("Something else"));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Settings"));
}

