#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^RESET%^%^BOLD%^%^RED%^L%^RED%^a%^RED%^v%^RED%^a%^RESET%^ %^RED%^r%^RED%^i%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^RED%^r%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^RED%^L%^RED%^a%^RED%^v%^RED%^a%^RESET%^ %^RED%^r%^RED%^i%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^RED%^r%^RESET%^
%^RESET%^%^BOLD%^%^RESET%^%^RED%^A molten river of %^BOLD%^%^RED%^l%^RED%^a%^RED%^v%^RED%^a%^RESET%^%^RED%^ rages across the beach here and into the ocean as the island is in a state off upheaval! Atop a nearby %^BOLD%^%^BLACK%^m%^RED%^o%^RED%^u%^RED%^n%^BLACK%^t%^RED%^a%^RED%^i%^BLACK%^n,%^RESET%^%^RED%^ jagged, and forbidding, you can see a %^BOLD%^%^WHITE%^b%^WHITE%^e%^RESET%^%^WHITE%^autifu%^BOLD%^%^WHITE%^l%^RESET%^ %^BOLD%^%^WHITE%^c%^WHITE%^r%^WHITE%^y%^RESET%^%^WHITE%^s%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^al %^WHITE%^t%^BOLD%^%^WHITE%^ower%^RESET%^%^WHITE%^!%^RED%^ It is far away but you feel an eerie calling from there.%^RESET%^
");

     set_listen("default","The lava whistles as it pours into the cold ocean.");
 
    set_exits(([
       "south" : "/d/attaya/beach27",
    ] ));
    set_items(([
      "mountain" : "It is impossible to discern the true size of the mountain.  If it is not an optical illusion caused by the rising heat, the mountain and tower are of a grand scale nearly unbelievable!",
      "lava" : "A river of molten metals and rock rushes past you to the north.",
     "river" : "A river of molten metals and rock rushes past you to the north.",
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
