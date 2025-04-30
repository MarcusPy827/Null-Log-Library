#include "main_window.hxx"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    auto * widgetLayout = new QVBoxLayout(this);
    widgetLayout->setContentsMargins(16, 16, 16, 16);
    widgetLayout->setSpacing(8);
    this->setLayout(widgetLayout);

    auto * configLayout = new QGridLayout(this);
    configLayout->setContentsMargins(0, 0, 0, 0);
    configLayout->setSpacing(8);
    widgetLayout->addLayout(configLayout);

    auto * tagDesc = new QLabel(this);
    tagDesc->setText("TAG · 标签: ");
    configLayout->addWidget(tagDesc, 0, 0);

    tagEdit = new QLineEdit(this);
    tagEdit->setText("NULL Log Library");
    configLayout->addWidget(tagEdit, 0, 1);

    auto * titleDesc = new QLabel(this);
    titleDesc->setText("Title · 标题: ");
    configLayout->addWidget(titleDesc, 1, 0);

    titleEdit = new QLineEdit(this);
    titleEdit->setText("Default title(示例标题)");
    configLayout->addWidget(titleEdit, 1, 1);

    auto * contentDesc = new QLabel(this);
    contentDesc->setText("Content · 内容: ");
    configLayout->addWidget(contentDesc, 2, 0);

    contentEdit = new QLineEdit(this);
    contentEdit->setText("Default content(示例内容)");
    configLayout->addWidget(contentEdit, 2, 1);

    auto * logLevelDesc = new QLabel(this);
    logLevelDesc->setText("logLevel · 内容: ");
    configLayout->addWidget(logLevelDesc, 3, 0);

    logLevelEdit = new QComboBox(this);
    logLevelEdit->addItem("Info");
    logLevelEdit->addItem("OK");
    logLevelEdit->addItem("Warning");
    logLevelEdit->addItem("Error");
    logLevelEdit->setCurrentText("Info");
    configLayout->addWidget(logLevelEdit, 3, 1);

    auto * widgetSpacerV = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    widgetLayout->addSpacerItem(widgetSpacerV);

    auto * instruction = new QLabel(this);
    instruction->setText("Please check your IDE or terminal for log output. Some IDEs (like CLion) may require extra steps to make colored output.\n请检查您的IDE或者终端以获取日志，某些IDE（比如CLion）可能需要额外设置以正确显示颜色");
    widgetLayout->addWidget(instruction);

    auto * buttonLayout = new QHBoxLayout(this);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    buttonLayout->setSpacing(8);
    widgetLayout->addLayout(buttonLayout);

    useColor = new QCheckBox(this);
    useColor->setText("Colored output · 彩色输出");
    useColor->setCheckState(Qt::CheckState::Checked);
    buttonLayout->addWidget(useColor);

    auto * widgetSpacerH = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonLayout->addSpacerItem(widgetSpacerH);

    generateLogBtn = new QPushButton(this);
    generateLogBtn->setText("Generate log · 生成日志");
    connect(generateLogBtn, SIGNAL(clicked(bool)), this, SLOT(generateLog()));
    buttonLayout->addWidget(generateLogBtn);

    this->setWindowTitle("Null Log Library Demo");
    this->resize(400, 300);
}

void MainWindow::generateLog() {
    QString tag = tagEdit->text();
    QString title = titleEdit->text();
    QString content = contentEdit->text();

    if(title.isEmpty()) NullLog::info(tag, content);
    else NullLog::info(tag, title, content);
}