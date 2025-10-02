#pragma once
#include <QString>

class User {
private:
    int id;
    QString name;
    QString email;
    QString role;
public:
    User(int id, const QString& name, const QString& email, const QString& role);
    int getId() const;
    QString getName() const;
    QString getEmail() const;
    QString getRole() const;
    void setRole(const QString& role);
};
