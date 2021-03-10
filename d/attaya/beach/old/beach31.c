#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Lava river.");
    set_long("
    %^RED%^You can go no further...
    A molten river of lava rages across the beach here and into the ocean as the island is in a state off upheaval!  Atop a nearby mountain, jagged, and forbidding, you can see a beautiful crystal tower!  It is far away but you feel a calling from there...
");

     set_listen("default","The lava whistles as it pours into the cold ocean.");
 
    set_exits(([
       "south" : "/d/attaya/beach30",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
      "mountain" : "It is impossible to discern the true size of the mountain.  If it is not an optical illusion caused by the rising heat, the mountain and tower are of a grand scale nearly unbelievable!",
      "lava" : "A river of molten metals and rock rushes past you to the north.",
     "river" : "A river of molten metals and rock rushes past you to the north.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "rocks" : "They form a natural reef around the eastern side of the island.  They are black with oil or tar.",
    ] ));
}
void init() {
  ::init();
  add_action("look", "look");
}
int look(string str) {
  if(str=="tower" || str == "crystal tower") {
  write("You look up at the tower.  Suddenly, a great overpowering feeling comes over you and you feel yourself drifting away.\n");
 tell_room(TO,(string)TPQCN+" looks up at the tower...  .\n", TP);
  this_player()->move_player("/d/attaya/story");
  return 1;
}
  return 0;
}
