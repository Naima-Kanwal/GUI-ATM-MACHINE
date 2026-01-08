#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable ATM buttons before login
    ui->balanceButton->setEnabled(false);
    ui->depositButton->setEnabled(false);
    ui->withdrawButton->setEnabled(false);
    ui->logoutButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    int pin = ui->pinLineEdit->text().toInt();

    if (userAccount.verifyPin(pin)) {
        QMessageBox::information(this, "Login", "Login Successful!");

        ui->balanceButton->setEnabled(true);
        ui->depositButton->setEnabled(true);
        ui->withdrawButton->setEnabled(true);
        ui->logoutButton->setEnabled(true);

        ui->loginButton->setEnabled(false);
    }
    else {
        QMessageBox::warning(this, "Error", "Wrong PIN!");
    }
}

// ================= LOGOUT BUTTON =================
void MainWindow::on_logoutButton_clicked()
{
    QMessageBox::information(this, "Logout", "Logged out successfully!");

    // Clear PIN
    ui->pinLineEdit->clear();

    // Disable ATM buttons
    ui->balanceButton->setEnabled(false);
    ui->depositButton->setEnabled(false);
    ui->withdrawButton->setEnabled(false);
    ui->logoutButton->setEnabled(false);

    // Enable login button again
    ui->loginButton->setEnabled(true);
}


void MainWindow::on_balanceButton_clicked()
{
    double bal = userAccount.getBalance();

    QMessageBox::information(this, "Balance",
                             QString("Your balance is: %1").arg(bal, 0, 'f', 2));
}


void MainWindow::on_depositButton_clicked()
{
    bool ok;
    double amount = QInputDialog::getDouble(
        this,
        "Deposit",
        "Enter amount to deposit:",
        1000,
        1,
        1000000,
        2,
        &ok
        );

    if (ok) {
        userAccount.deposit(amount);
        QMessageBox::information(
            this,
            "Deposit",
            QString("%1 Deposited Successfully!").arg(amount)
            );
    }
}

// ================= WITHDRAW =================
void MainWindow::on_withdrawButton_clicked()
{
    bool ok;
    double amount = QInputDialog::getDouble(
        this,
        "Withdraw",
        "Enter amount to withdraw:",
        500,
        1,
        1000000,
        2,
        &ok
        );

    if (ok) {
        if (userAccount.withdraw(amount)) {
            QMessageBox::information(
                this,
                "Withdraw",
                QString("%1 Withdrawn Successfully!").arg(amount)
                );
        }
        else {
            QMessageBox::warning(this, "Error", "Insufficient Balance!");
        }
    }
}
