#include <std.h>
inherit ~INHERIT~;

void create(){
    int theac, theweight, thevalue;
    ::create();
    set_name(~NAME~);
    set_id(~ID~);
    set_short(~SHORT~);
    set_long(~LONG~);
    set_size(~SIZE~);
    theac = ((::query_ac() * ~QUALITY~) /16);
    theweight = (::query_weight() * 2) - ((::query_weight() * ~QUALITY~) /16);
    thevalue = roll_dice((~QUALITY~+1),::query_value());
    set_ac(theac);
    set_weight(theweight);
    set_value(thevalue);
    set_property("creator",~CREATOR~);
    set_property("quality",~QUALITY~);
}