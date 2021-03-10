#include <std.h>

inherit ARMOUR;

void create()
{
    ::create();	    
    set_name("ring");
    set_id(({"ring","bone ring","bone key ring"}));
    set_obvious_short("bone ring");
    set_short("%^BOLD%^%^WHITE%^bone ring%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This ring is made from what "+
    "appears to be a bone fragment.  It is remarkably simple "+
    "with a lone word etched into the underside of the "+
    "band.%^RESET%^");
    set_type("ring");
    set_read("BlackTongue");
    set_language("common");
    set_ac(0);
    set_weight(1);
    set_value(10);
    set_limbs(({"left hand","right hand"}));
}

int isMagic(){
    int x;
    x = ::isMagic();
    x = x+1;
    return x;
}





