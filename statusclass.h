#ifndef STATUSCLASS_H
#define STATUSCLASS_H

#include <QObject>

class StatusClass
{
    Q_GADGET
public:
    // Enumerated types with enum class
    //http://www.cplusplus.com/doc/tutorial/other_data_types/
    enum class StatusClassValue //: //char
    {	Normal,
        //pseudo-Special Condition
        Wait,
        //Special Conditions
        Paralized,
        Poisoned,
        Asleep,
        Confused,
        Burned,
        Frozen,
        Noxious
    };
    Q_ENUM(StatusClassValue)

private:
    explicit StatusClass();
};

typedef StatusClass::StatusClassValue Status;

#endif // STATUSSCLASS_H
