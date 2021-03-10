#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("emerald eye");
    set_id(({"eye","Eye","Emerald Eye","emerald eye","emerald","Emerald"}));
    set_obvious_short("%^BOLD%^%^GREEN%^emerald%^RESET%^");
    set_short("%^BOLD%^%^GREEN%^emerald%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^This is a small oddly shaped emerald.  "+
    "It almost resembles the "+
    "eye of a reptillian creature.%^RESET%^");
    set_value(400);
    set_weight(8);
}
 
int isMagic()
{
    int y;
    y = ::isMagic();
    y = y + 1;
    return y;
}
	