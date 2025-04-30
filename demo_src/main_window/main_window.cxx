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

    auto * subTitleDesc = new QLabel(this);
    subTitleDesc->setText("Subtitle · 副标题: ");
    configLayout->addWidget(subTitleDesc, 2, 0);

    subTitleEdit = new QLineEdit(this);
    subTitleEdit->setText("Default subtitle(示例副标题)");
    configLayout->addWidget(subTitleEdit, 2, 1);

    auto * contentDesc = new QLabel(this);
    contentDesc->setText("Content · 内容: ");
    configLayout->addWidget(contentDesc, 3, 0);

    contentEdit = new QLineEdit(this);
    contentEdit->setText("Default content(示例内容)");
    configLayout->addWidget(contentEdit, 3, 1);

    auto * logLevelDesc = new QLabel(this);
    logLevelDesc->setText("logLevel · 内容: ");
    configLayout->addWidget(logLevelDesc, 4, 0);

    logLevelEdit = new QComboBox(this);
    logLevelEdit->addItem("Info");
    logLevelEdit->addItem("OK");
    logLevelEdit->addItem("Warning");
    logLevelEdit->addItem("Error");
    logLevelEdit->setCurrentText("Info");
    configLayout->addWidget(logLevelEdit, 4, 1);

    //auto * widgetSpacerV = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    //widgetLayout->addSpacerItem(widgetSpacerV);

    auto * instruction = new QLabel(this);
    instruction->setText("Please check your IDE or terminal for log output.\n请检查您的IDE或者终端以获取日志");
    widgetLayout->addWidget(instruction);

    logViewer = new QTextEdit(this);
    logViewer->setAcceptRichText(true);
    logViewer->setReadOnly(true);
    widgetLayout->addWidget(logViewer);

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
    buttonLayout->addWidget(generateLogBtn);

    this->setWindowTitle("Null Log Library Demo");
    this->resize(400, 300);
}