#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_short("%^RESET%^%^MAGENTA%^Sm%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^l %^MAGENTA%^woode%^BOLD%^%^WHITE%^n%^RESET%^%^MAGENTA%^ %^MAGENTA%^plank %^MAGENTA%^road%^BOLD%^%^WHITE%^.%^RESET%^%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^Sm%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^l %^MAGENTA%^woode%^BOLD%^%^WHITE%^n%^RESET%^%^MAGENTA%^ %^MAGENTA%^plank %^MAGENTA%^road%^BOLD%^%^WHITE%^.%^RESET%^%^RESET%^
%^RESET%^%^ORANGE%^The road leads south and west from here. A small hut lies to the north. The sea oats whisper to you as they rustle. Some %^GREEN%^tr%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^es%^ORANGE%^ grow here. The %^BOLD%^%^WHITE%^b%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^MAGENTA%^h%^ORANGE%^ lies south and north from here.%^RESET%^");

     set_listen("default","The nearby ocean waves cast a rhythmic roar that seems almost soothing at this distance.");
 
    set_exits(([

       "north" : "/d/attaya/seneca8",
       "south" : "/d/attaya/beach20",

       "west" : "/d/attaya/seneca3",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
