#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(SLICK_FLOOR);
    set_short("Creaky pier in a rough sea.");
    set_long("
    Thunderous surf crashes around you as you struggle to stand upon this creaky pier amidst an onslaught of waves.  Although this one is recently constructed, the waves pound it mercilessly.  All around you is moving water, giving you the sensation of motion. It is as if the pier itself is hurtling away from the island through the sea as the water crashes around you, parting reluctantly for the wooden and stone structure upon which you stand so uneasily.
    A sandy beach lies to the west.  To the southwest you can see a city rising above the beach.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
   set_smell("default","The spray off the ocean burns your nose.");
 
    set_exits(([
       "west" : "/d/attaya/beach23",
    ] ));
    set_items(([
      "beach" : "The beach here is rippled from the effects of a recent tide.  "
        "The sand is very finely granulated.",
      "rocks" : "They form a natural reef around the eastern side of the island."
        "  They are black with oil or tar.",
      ({"dock", "pier"}) : "A new pier has been built out over and past the "
        "rocks, far enough to allow boats to dock.  Perhaps the citizens of "
        "Seneca are hoping for more visitors to help against the invasions "
        "from Intruder's minions." 
    ] ));
}

void reset(){
   ::reset();
    if(!present("profile"))
      new("/d/attaya/obj/profile")->move(this_object());
}
