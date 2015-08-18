#ifndef DARKSILKADDRESSVALIDATOR_H
#define DARKSILKADDRESSVALIDATOR_H

#include <QValidator>

/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
 */
class DarkSilkAddressValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DarkSilkAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 128;
};

#endif // DARKSILKADDRESSVALIDATOR_H
