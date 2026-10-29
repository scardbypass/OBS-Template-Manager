#include <obs-module.h>
#include <obs-frontend-api.h>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QMessageBox>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-template-manager", "en-US")

static QWidget *dockWidget = nullptr;

static QWidget *makeTab(const QString &description, const QString &action)
{
    auto *tab = new QWidget;
    auto *layout = new QVBoxLayout(tab);
    auto *label = new QLabel(description);
    label->setWordWrap(true);
    layout->addWidget(label);
    auto *button = new QPushButton(action);
    layout->addWidget(button);
    layout->addStretch();
    QObject::connect(button, &QPushButton::clicked, tab, [tab]() {
        QMessageBox::information(tab, "OBS Template Manager",
            "This feature is planned but not implemented yet. No OBS settings were changed.");
    });
    return tab;
}

bool obs_module_load(void)
{
    dockWidget = new QWidget;
    dockWidget->setObjectName("obsTemplateManagerDock");
    auto *layout = new QVBoxLayout(dockWidget);
    auto *title = new QLabel("<b>OBS Template Manager</b>  <small>v0.1.0</small>");
    layout->addWidget(title);

    auto *tabs = new QTabWidget;
    tabs->addTab(makeTab("Browse and download templates from a verified catalog.", "Browse library"), "Library");
    tabs->addTab(makeTab("Manage installed template collections.", "View installed"), "My Templates");
    tabs->addTab(makeTab("Export a scene collection and its local media assets.", "Export template"), "Creator");
    tabs->addTab(makeTab("Create and restore backups before template changes.", "Backup settings"), "Backup");
    layout->addWidget(tabs);

    // Ownership of the widget is transferred to the OBS dock on success.
    if (!obs_frontend_add_dock_by_id("obs-template-manager", "Template Manager", dockWidget)) {
        delete dockWidget;
        dockWidget = nullptr;
        blog(LOG_ERROR, "[obs-template-manager] Failed to register dock");
        return false;
    }
    blog(LOG_INFO, "[obs-template-manager] Dock registered");
    return true;
}

void obs_module_unload(void)
{
    // OBS owns the registered dock widget. Do not delete it here.
    dockWidget = nullptr;
}
