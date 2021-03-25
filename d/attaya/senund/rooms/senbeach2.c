#include <std.h>

inherit ROOM;
#include "../areadefs.h"

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("outdoors",1);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^");
    set_long("
    %^ORANGE%^You are standing on the b%^BOLD%^ea%^RESET%^%^ORANGE%^c%^BOLD%^h%^RESET%^%^ORANGE%^. On an island to the south of you is the city of %^MAGENTA%^S%^BOLD%^e%^RESET%^%^MAGENTA%^n%^BOLD%^ec%^RESET%^%^MAGENTA%^a. %^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^m %^BOLD%^t%^RESET%^%^GREEN%^re%^BOLD%^es %^RESET%^%^ORANGE%^are present every now and then. A cool breeze can be felt here in the shade.  The beach is very wide here.  The sand gives way beneath your feet making your ankles grow tired quickly. The %^CYAN%^c%^BOLD%^oa%^RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^l%^BOLD%^in%^RESET%^%^CYAN%^e %^ORANGE%^of the beach continues to the west here. You can here little except for the bellowing of the wind.%^RESET%^
");

     set_listen("default","The wind gusts loudly here.");

    set_exits(([

       "northeast" : ROOMS+"beach19",
       "west" : ROOMS+"senbeach3"

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
    ] ));
}
