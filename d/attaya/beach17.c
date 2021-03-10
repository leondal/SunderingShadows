#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^");
    set_long("%^YELLOW%^%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^%^RESET%^
%^ORANGE%^Several small buildings lie on the northern side of a road that begins here and curves around a fence. The fence starts here and extends eastward until the road reconnects to the beach and fades away. You are standing on the beach. The sand is very dry here and the ocean is a fair distance to the south. Dunes back the fence to the north.
");

     set_listen("default","The waves pound against the rocky coastline much further south coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/seneca1",
       "west" : "/d/attaya/beach16",

       "east" : "/d/attaya/beach18",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
          "fence" : "It is a worn wooden fence with chipping white paint.",
          "dunes" : "They are about five feet high, and covered with sea oats.",
          "buildings" : "They appear well kept.",
    ] ));
}
