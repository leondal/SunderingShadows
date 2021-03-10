#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^ORANGE%^Several small %^MAGENTA%^buildings%^ORANGE%^ lie on the northern side of a road that begins here and curves around a %^WHITE%^fence%^ORANGE%^. The fence starts here and extends westward until the road reconnects to the %^WHITE%^beach%^ORANGE%^ and fades away. You are standing on the beach. The sand is very dry here and the ocean is a fair distance to the south. The city of Seneca can be seen across a channel of water. A wooden bridge spans the beach to the west and runs into the ocean to the south. %^WHITE%^Dunes%^ORANGE%^ back the fence to the north. Some %^GREEN%^trees%^ORANGE%^ grow here.%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/seneca4",
       "west" : "/d/attaya/senund/rooms/beach19",

       "northeast" : "/d/attaya/beach21",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
          "fence" : "It is a worn wooden fence with chipping white paint.",
          "dunes" : "They are about five feet high, and covered with sea oats.",
          "buildings" : "They appear well kept.",
    ] ));
}
