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
    %^ORANGE%^You are standing on the b%^BOLD%^ea%^RESET%^%^ORANGE%^c%^BOLD%^h%^RESET%^%^ORANGE%^. On an island to the south of you is the city of %^MAGENTA%^S%^BOLD%^e%^RESET%^%^MAGENTA%^n%^BOLD%^ec%^RESET%^%^MAGENTA%^a. %^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^m %^BOLD%^t%^RESET%^%^GREEN%^re%^BOLD%^es %^RESET%^%^ORANGE%^are present every now and then. A cool breeze can be felt here in the shade. There is a %^WHITE%^s%^BOLD%^m%^RESET%^a%^BOLD%^l%^RESET%^l cl%^BOLD%^if%^RESET%^f %^ORANGE%^coming out of the beach that blocks off passage to the north. Due to that fact this part of the beach is rather isolated from the rest. To the west you can see the beach edge up against the %^GREEN%^jungle%^ORANGE%^. The %^CYAN%^w%^BOLD%^a%^RESET%^%^CYAN%^v%^BOLD%^e%^RESET%^%^CYAN%^s %^ORANGE%^crash onto the beach just south of you. You can hear little except for the bellowing of the wind, and the crash of the waves.%^RESET%^
");

     set_listen("default","The wind gusts loudly here and "+
                "and the waves crash loudly.");
 
    set_exits(([

       "east" : ROOMS+"senbeach2",
       "west" : ROOMS+"senbeach4"

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
    ] ));
}
