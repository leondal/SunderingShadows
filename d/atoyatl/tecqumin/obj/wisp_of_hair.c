//Coded by Lujke


#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("wisp of hair");
    set_id( ({"hair","wisp","wisp of hair" }) );
    set_short("%^BOLD%^%^BLACK%^A %^RESET%^wisp %^BOLD%^%^BLACK%^of black"
             +" hair");
    set_weight(1);
    set_long("%^BOLD%^%^BLACK%^A few strands of %^RESET%^wispy%^BOLD%^"
            +"%^BLACK%^ black hair, bound together at one end by what"
            +" looks rather disgustingly like a patch of leathery black"
            +" skin.");
}


