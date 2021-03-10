#include <std.h>
inherit OBJECT;

void create() 
{
    ::create();
    set_id( ({ "crystal","small crystal","light crystal", "small yellow crystal"}) );
    set_name("Light Crystal");
    set_short("%^RESET%^%^BOLD%^a small cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^");
   
    set_long("%^RESET%^%^BOLD%^This is a small "
        "cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^%^BOLD%^ "
        "not much larger than a gold piece.  It is naturally formed into "
        "an elongated octagonal shape which comes to a point at each end.  ");

    set_weight(1);
    set("value", 5);
}

