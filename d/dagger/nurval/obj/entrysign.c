#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("Sign Post");
    set_id( ({"sign", "sign post", "warning", "warning sign"}) );
    set_short("%^BOLD%^%^WHITE%^A Warning sign%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Welcome to %^BLACK%^The Tomb of Nurval%^BLUE%^, free city where everyone is welcome, living or not, by the graces of %^WHITE%^Nurval%^BLUE%^, with the blessing of %^BLACK%^Nilith%^BLUE%^.

%^BOLD%^%^WHITE%^The Laws are as follows:

%^BLUE%^1. %^WHITE%^Violence will be punished with permanent discorporation.
   All exists by Nurval's mercy. Only he can end your misery.

%^BLUE%^2. %^WHITE%^Theft will be punished with permanent discorporation.
   All belongs to Nurval. To take from others is to take from him

%^BLUE%^3. %^WHITE%^Slavery will be punished with permanent discorporation.
   All are slaves to Nurval. To claim otherwise is to steal from him.

Pests such as angels and nymps will not be tolerated and are to be slain on sight.

%^BOLD%^Living must take northernmost path less they wish to experience Nurval's blessing.");
    set_weight(10000);
    set_value(0);
}

int __Read(string str)
{
    if(str == "sign")
    {
        TP->force_me("look sign");
        return 1;
    }
}
