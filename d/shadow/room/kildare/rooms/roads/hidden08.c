//hidden08.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
   set_name("a hidden copse");
   set_short("A Hidden Copse");
   set_long(
      "%^ORANGE%^A small grove of %^GREEN%^trees %^ORANGE%^stands here "+
      "in the middle "+
      "of the %^RESET%^foothills%^ORANGE%^.  A quiet calm rests within "+
      "the %^GREEN%^grove%^ORANGE%^, and "+
      "the trees form a protective ring around a %^BOLD%^%^GREEN%^lone "+
      "oak tree %^RESET%^%^ORANGE%^growing "+
      "in the center of the circle.  That tree splits fairly low to "+
      "the ground, forming a natural %^BOLD%^%^BLUE%^bowl %^RESET%^%^ORANGE%^"+
      "into which %^CYAN%^rainwater %^ORANGE%^has "+
      "collected.  Growing outward somehow from the trunk of the oak just "+
      "below the font is a %^BOLD%^%^CYAN%^unicorn's head %^RESET%^%^ORANGE%^"+
      "with %^GREEN%^ivy vines %^ORANGE%^for the mane "+
      "and sparkling %^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r%^BLUE%^es "+
      "%^RESET%^%^ORANGE%^set within the eyes.  The %^YELLOW%^horn %^RESET%^%^ORANGE%^glitters "+
      "golden in the light.  The grass here is short, as if it has "+
      "been recently trimmed, and the ground is kept free of fallen "+
      "leaves.\n"
   );
   set_items(([
      "grass" : "%^BOLD%^%^GREEN%^The grass here is a vibrant green and is very "+
      "soft to the touch, providing a pleasant padding for the grove.  It "+
      "seems to be kept short year round and never grows brown.",
      (({"trees","grove","copse"})) : "The grove of trees here is made up "+
      "of a ring of deciduous trees.  Ashes, elms, and the like grow close "+
      "together, protecting the lone oak tree growing strong in the center.",
      (({"tree","oak tree","center tree"})) : "The strong tree in the "+
      "center of the grove is an aged oak.  It would be quite tall, were "+
      "it not for the split not far from the ground, which forms a small "+
      "font that has collected rainwater.  It has a unicorn's head growing "+
      "from just below the basin.",
      (({"rainwater","font","water","basin","bowl"})) : "%^BOLD%^%^CYAN%^The "+
      "brown basin formed by the oak tree has been filled with pure "+
      "water captured from the rain.  It is clean and clear, and the "+
      "surface never seems disturbed by the breeze.",
      (({"unicorn's head","head","unicorn"})) : "%^BOLD%^%^WHITE%^The "+
      "oak trunk has somehow grown into the shape of a stunning "+
      "%^CYAN%^unicorn's head%^WHITE%^.  The long, flowing mane is "+
      "made of delicate %^GREEN%^ivy%^WHITE%^,while the long, curving "+
      "horn seems to be encased in %^YELLOW%^gold%^WHITE%^.  Set deep "+
      "within the eyes are two large, round %^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r%^BLUE%^es "+
      "%^WHITE%^that sparkle and gleam in the light."
      ]));
   set_smell("default","A clean, pure scent of the outdoors rests in the air.");
   set_listen("default","Silence prevails here in the grove.");
   set_property("fill waterskin",1);
   set_exits(([
      "southeast" : ROADS"hidden07"
      ]));
}

void init() {
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to drink?");
      return 0;
   }
   if(str != "water from font" && str != "from font" && str != "rainwater" && str != "water from basin" && str != "water from bowl" && str != "water from the font") {
      tell_object(TP,"Try drinking water from the font.");
      return 0;
   }
   if(!TP->add_quenched(20))
      return notify_fail("Your stomach is sloshing already!\n");
   tell_object(TP,"You lift some the cool water from the font to your "+
      "lips and feel at peace.");
   tell_room(TO,TPQCN+" drinks some of the cool water from the font.",TP);
   return 1;
}
