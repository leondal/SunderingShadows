#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;
int spiked, screened, pitted, trenched;

void add_critters();
string long_desc();

void create() {
  ::create();
  pitted = 0;
  screened = 0;
  spiked = 0;
  trenched = 0;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A jungle clearing");
  set_short("%^GREEN%^A %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
           +"%^GREEN%^ng%^RESET%^%^GREENl%^BOLD%^%^GREEN%^e%^RESET%^"
           +" %^GREEN%^clearing%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([({"platform", "wooden platform"}): "The platform circles the"
          +" treetrunk, about 30 feet above the ground. It is constructed"
          +" from %^ORANGE%^living wood%^RESET%^ that appears to have been"
          +" woven together, rather than cut and hammered into shape. A"
          +" railing around the side makes it look as though it would be"
          +" more or less impossible to climb up to.",
               ({"hatch"}) : "The hatch appears to be hinged at one end,"
          +" with a support rope securing the other end to one of the"
          +" branches above it.",
                ({"rope", "support rope"}):  "A single rope is attached to"
          +" the hatch at one end, holding it up from above"  ]));
  set_search("platform","Looking up at the platform from below, you can"
          +" make out a rectangular area that looks like a hatch of some"
          +" sort");
  set_search("wooden platform","Looking up at the platform from below, you"
          +" can make out a rectangular area that looks like a hatch of"
          +" some sort");
  set_search("rope","If you were a very good shot, it might just be"
             +" possible to hit the rope with a missile weapon");
  set_search("support rope","If you were a very good shot, it might just"
             +" be possible to hit the rope with a missile weapon");
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  set_climb_exits(([
    "descend":({ROOMS  + "platform01",2,0, 30}),
    "climb":({ROOMS  + "crowsnest",2,0, 30}),
  ]));
  add_critters();
}
void init() {
   ::init();
   add_action("shoot_rope", "shoot");
   add_action("throw_rope", "throw");
   add_action("fly_platform", "fly");
   add_action("climb", "climb");
}


void add_critters(){
  int i, num;
  object sprite;
  if (present("sprite 3", TO));
  num = 3+ random(2)+ random(3);
  for (i=0;i<num;i++){ 
    sprite = new(MOB + "sprite");
    sprite->move(TO);
  }
}

string long_desc(){
  string desc;
  desc =  "You are in the middle of the canopy of a mighty%^ORANGE%^"
         +" higureon tree%^RESET%^, above the platform erected around the"
         +" lower part of the treetrunk. A lookout post has been placed"
         +" even higher up in the %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o"
         +"%^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge"
         +"%^RESET%^.";
  return desc;
}
