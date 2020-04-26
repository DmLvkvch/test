#include "mainwindowsettings.h"
#include "mainwindowsettingsgrid.h"


#include <QDialog>
#include <QVBoxLayout>
MainWindowSettings::MainWindowSettings(QWidget* parent): QDialog(parent)
{
    setMinimumSize(200, 200);
    tabWidget = QSharedPointer<QTabWidget>(new QTabWidget);
    buttonBox =QSharedPointer<QDialogButtonBox>(new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel));
    connect(buttonBox.get(), &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox.get(), &QDialogButtonBox::rejected, this, &QDialog::reject);
    tabWidget->addTab(new MainWindowSettingsGrid(), tr("Grid view"));
    tabWidget->addTab(new QWidget(), tr("Something else"));
    mainLayout = QSharedPointer<QVBoxLayout>(new QVBoxLayout);
    mainLayout->addWidget(tabWidget.get());
    mainLayout->addWidget(buttonBox.get());
    setLayout(mainLayout.get());
    setWindowTitle(tr("Settings"));
}

MainWindowSettings::~MainWindowSettings()
{

}
