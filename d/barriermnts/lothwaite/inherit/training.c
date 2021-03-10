//Training ground for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_indoors(0);
   set_light(2);
   set_name("Training Ground");
   set_short("Training Ground");
   set_long("%^BOLD%^%^GREEN%^This large grassy area is bounded on "+
      "all sides by a %^RESET%^%^ORANGE%^tall wooden fence%^BOLD%^"+
      "%^GREEN%^.  Here inside the fence, the grass is broken in "+
      "places by %^RESET%^%^ORANGE%^mud puddles %^BOLD%^%^GREEN%^"+
      "caused by a combination of the practicing warriors and the "+
      "%^RESET%^%^CYAN%^river's mist%^BOLD%^%^GREEN%^.  Rising up "+
      "to the far eastern side of the field is a magnificent "+
      "%^WHITE%^chapel%^GREEN%^, while the town %^RESET%^%^RED%^"+
      "smithy %^BOLD%^%^GREEN%^stands to the northwest.");
   set_items(([
      ({"building","smithy","stone building"}) : "The squat smithy "+
         "seems almost short compared to the other buildings of the "+
         "town, though it still rises fifteen feet tall.  Three "+
         "stone chimneys crowd its rooftop, all pouring smoke.",
      ({"ground","field","mud","puddles","mud puddles","grass"}) : "The "+
         "ground is mostly grass, though here and there a mud puddle "+
         "stands to make footing treacherous for those practicing.",
      ({"chapel","church"}) : "Even from here, the high rising "+
         "chapel is awe-inspiring.  The %^YELLOW%^s%^GREEN%^t%^CYAN%^"+
         "a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
         "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
         "%^YELLOW%^s%^GREEN%^s %^RESET%^windows glitter in the light, "+
         "be it night or day.",
      "forge" : "You can just make out the corner of the forge to the "+
         "northwest.",
      ({"fence","wooden fence","gate"}) : "The wooden fence stands "+
         "around six feet tall and encompasses the training grounds.  "+
         "The northern side of the fence has a gate in the middle "+
         "that leads out to a path.",
      ({"mist","river's mist"}) : "%^CYAN%^A light mist often hangs in "+
         "the air here, causing it to be chilly and the ground to be "+
         "a little slippery."
   ]));
   set_smell("default","You smell a slight dank scent on the air.");
   set_listen("default","The occasional clang of metal on metal rises over the wind.");
}

void reset(){
   object obj;
   ::reset();
   if(obj = present("firbolg citizen")){
      obj->move("/d/shadowgate/void");
      destruct(obj);
      return;
   }
}