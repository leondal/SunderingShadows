#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;
int open;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A jungle clearing");
  set_short("%^GREEN%^A %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
           +"%^GREEN%^ng%^RESET%^%^GREENl%^BOLD%^%^GREEN%^e%^RESET%^"
           +" %^GREEN%^clearing%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"platform", wooden platform}): "The platform circles the"
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
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
}
void init() {
   ::init();
   add_action("lower_ladder", "lower");
   add_action("raise_ladder", "raise");
}

string long_desc(){
  string desc;
  desc =  "%^ORANGE%^You are on a platform constructed around the trunk of"
         +" an enormous tree, about thirty feet above the ground. The tree"
         +" rises high overhead, with branches radiating from the trunk on"
         +" all sides.\n";
  if (TO->query_exits("down") != "/d/shadowgate/void"){
    desc += "%^RESET%^A small hatch is open in the platform, and a rope"
         +" ladder is swinging down.\n"
  }
  return desc;
}

int lower_ladder(string str){
  object room;
  str = lower_case(str);
  if (!interact("ladder", str)){
    tell_object(TP, "Did you want to %^BOLD%^%^YELLOW%^lower"
                   +" ladder%^RESET%^?");
    return 1;
  }
  if (TO->query_exits("down") != "/d/shadowgate/void"){
    tell_object(TP, "The ladder is already lowered");
    return 1;
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  if (!objectp(room)){
    tell_object(TP, "Error identifying the exit room. Please tell a WIZ");
    return 1;
  }
  add_exit(ROOMS + "t_house_base", "down");
  room->add_exit(TREEHOUSE + "/rooms/" + "platform1", "up");
  return 1;
}

int raise_ladder(string str){
  object room;
  str = lower_case(str);
  if (!interact("ladder", str)){
    return 0;
  }
  if (TO->query_exits("down") == "/d/shadowgate/void"){
    tell_object(TP, "The ladder is already raised");
    return 1;
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  if (!objectp(room)){
    tell_object(TP, "Error identifying the exit room. Please tell a WIZ");
    return 1;
  }
  remove_exit("down");
  room->remove_exit("up");
}