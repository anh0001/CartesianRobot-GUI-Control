#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QRegularExpression>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    isArduinoConnected(false)  // Set nilai awal
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(readPositionYFromArduino()));
    // Set interval waktu sesuai kebutuhan (misalnya, 100 ms untuk pembacaan lebih sering)
    timer->start(10);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_lineEdit_returnPressed()));
    connect(&arduino, SIGNAL(readyRead()), this, SLOT(readPositionYFromArduino()));

     ui->pushButton_10->setStyleSheet("background-color: red; color: white;");

    updateSerialPorts();
}

MainWindow::~MainWindow()
{
    if (arduino.isOpen()) {
        arduino.close();
    }
    delete ui;
}

void MainWindow::updateSerialPorts() {
    ui->comboBox->clear(); // Clear existing items
    ui->comboBox_2->clear(); // Clear existing items for baudrate

    // Get the list of available serial ports
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    // Add each port name to the comboBox
    for (const QSerialPortInfo &port : ports) {
        ui->comboBox->addItem(port.portName());
    }

    // Add baudrate options to comboBox_2
    QStringList baudrateOptions = {"4800", "9600", "19200", "31250", "38400", "57600", "74880", "115200"};
    ui->comboBox_2->addItems(baudrateOptions);
}

void MainWindow::updateStatusLabel(const QString &text)
{
    ui->statusLabel->setText(text);

}

void MainWindow::updateStatusLabelX(const QString &text)
{
    ui->label->setText(text);
}

void MainWindow::updateStatusLabelY(const QString &text)
{
    ui->label_2->setText(text);
}

void MainWindow::updateStatusLabelZ(const QString &text)
{
    ui->label_3->setText(text);
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray data;
    data.append('w');
    arduino.write(data);
    updateStatusLabel("Sent 'w' to Arduino");
}

void MainWindow::on_pushButton_2_clicked()
{
    QByteArray data;
    data.append('s');
    arduino.write(data);
    updateStatusLabel("Sent 's' to Arduino");
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray data;
    data.append('a');
    arduino.write(data);
    updateStatusLabel("Sent 'a' to Arduino");
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray data;
    data.append('d');
    arduino.write(data);
    updateStatusLabel("Sent 'd' to Arduino");
}

void MainWindow::on_pushButton_5_clicked()
{
    on_lineEdit_returnPressed();
}

void MainWindow::on_pushButton_6_clicked()
{
    QByteArray data;
    data.append('r');
    arduino.write(data);
    updateStatusLabel("Sent 'r' to Arduino");
}

void MainWindow::on_pushButton_7_clicked()          //Z+
{
    QByteArray data;
    data.append('z', '+');

    arduino.write(data);
    updateStatusLabel("Sent 'Z+' to Arduino");
}


void MainWindow::on_pushButton_8_clicked()          //Z-
{
    QByteArray data;
    data.append('z');
    data.append('-');
    arduino.write(data);
    updateStatusLabel("Sent 'Z-' to Arduino");
}

void MainWindow::on_pushButton_9_clicked() {
    if (arduino.isOpen()) {
        // Disconnect from the Arduino and close the serial port
        arduino.close();
        qDebug() << "Serial port closed.";
        updateStatusLabel("Serial port closed.");

        // Enable the Connect button after disconnecting
        ui->pushButton_9->setEnabled(true);

        // Reset the button color
        ui->pushButton_9->setStyleSheet(""); // Reset the style sheet

        // Update the connection status
        isArduinoConnected = false;

        // Set the color of pushButton_10 to red when disconnected
        ui->pushButton_10->setStyleSheet("background-color: red; color: white;");
    } else {
        QString selectedPort = ui->comboBox->currentText();

        // Set the port name in the arduino object
        arduino.setPortName(selectedPort);

        // Try to open the selected serial port
        if (arduino.open(QIODevice::ReadWrite)) {
            qDebug() << "Serial port opened successfully.";
            updateStatusLabel("Serial port opened successfully.");

            // Connect the readyRead signal to the readPositionYFromArduino slot
            connect(&arduino, SIGNAL(readyRead()), this, SLOT(readPositionYFromArduino()));

            // Disable the Connect button after successfully connecting
            ui->pushButton_9->setEnabled(false);

            // Change the button color to indicate successful connection
            ui->pushButton_9->setStyleSheet("background-color: green; color: white;"); // Adjust the colors as needed

            // Update the connection status
            isArduinoConnected = true;

            // Set the color of pushButton_10 to white when connected
            ui->pushButton_10->setStyleSheet("");
        } else {
            qDebug() << "Error opening serial port:" << arduino.errorString();
            updateStatusLabel("Error opening serial port: " + arduino.errorString());

            // Optionally, you can reset the button color if the connection fails
            ui->pushButton_9->setStyleSheet(""); // Reset the style sheet

            // Update the connection status
            isArduinoConnected = false;

            // Set the color of pushButton_10 to red when disconnected
            ui->pushButton_10->setStyleSheet("background-color: red; color: white;");
        }
    }
}

void MainWindow::on_pushButton_10_clicked() {
    if (arduino.isOpen()) {
        // Disconnect from the Arduino and close the serial port
        arduino.close();
        qDebug() << "Serial port closed.";
        updateStatusLabel("Serial port closed.");

        // Enable the Connect button after disconnecting
        ui->pushButton_9->setEnabled(true);

        // Reset the button color
        ui->pushButton_9->setStyleSheet(""); // Reset the style sheet

        // Update the connection status
        isArduinoConnected = false;

        // Set the color of pushButton_10 to red when disconnected
        ui->pushButton_10->setStyleSheet("background-color: red; color: white;");
    } else {
        // If the port is already closed, inform the user
        updateStatusLabel("Serial port is already closed.");
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString input = ui->lineEdit->text().toLower();  // Convert to lowercase for case-insensitive comparison

    // Deklarasi ekspresi reguler (QRegularExpression) untuk mendeteksi format x, y, z
    QRegularExpression rx("([xyz][\\+-]?\\d+\\s?)+|(z[\\+-]?)");

    // Mengecek format input
    if (rx.match(input).hasMatch()) {
        // Format valid, kirim data ke Arduino
        QByteArray data;
        data.append(input.toLatin1());
        arduino.write(data);

        updateStatusLabel("Sent '" + input + "' to Arduino");

        // Mengosongkan QLineEdit setelah pengiriman data
        ui->lineEdit->clear();
    } else {
        // Format tidak valid
        updateStatusLabel("Invalid input format. Please enter valid format (e.g., 'x10', 'y20', 'z+', 'x10 y20', 'x10 z-').");
    }
}

void MainWindow::readPositionYFromArduino() {
    if (arduino.isOpen() && arduino.isReadable()) {
        // Membaca satu baris (sampai newline) dari buffer serial
        QByteArray data = arduino.readLine();
        qDebug() << "Received data from Arduino:" << data;

        QString receivedData(data);

        // Proses data posisi stepper X dan Y
        if (receivedData.startsWith("X = ")) {
            // Proses data posisi stepper X
            int positionX = receivedData.mid(4).toInt();
            qDebug() << "Position X:" << positionX;
            QString formattedString = QString("%1").arg(positionX);
            updateStatusLabelX(formattedString);
        } else if (receivedData.startsWith("Y = ")) {
            // Proses data posisi stepper Y
            int positionY = receivedData.mid(4).toInt();
            qDebug() << "Position Y:" << positionY;
            QString formattedString = QString("%1").arg(positionY);
            updateStatusLabelY(formattedString);
        } else if (receivedData.startsWith("Z = ")) {
            // Extract the command (assuming it is the part of the string after "Z = ")
            QString command = receivedData.mid(4).trimmed().toLower(); // Trim spaces and convert to lowercase for case-insensitive comparison
            updateStatusLabelZ(command);
            //            if (command == "up") {
            //                qDebug() << "Move Z Up";
            //                // Perform actions for moving Z axis up
            //                updateStatusLabelZ(command);
            //            } else if (command == "down") {
            //                qDebug() << "Move Z Down";
            //                updateStatusLabelZ(command);
            //                // Perform actions for moving Z axis down
            //            } else {
            //                qDebug() << "Invalid command received.";
            //                updateStatusLabelZ(command);
            //            }
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    Q_UNUSED(index); // Untuk menghilangkan peringatan kompilasi tentang parameter yang tidak terpakai

    // Dapatkan baudrate yang dipilih dari comboBox_2
    QString baudrateString = ui->comboBox_2->currentText();
    int baudrate = baudrateString.toInt(); // Konversi ke integer

    // Set baudrate pada objek arduino
    arduino.setBaudRate(baudrate);

    qDebug() << "Baudrate changed to:" << baudrate;
}




