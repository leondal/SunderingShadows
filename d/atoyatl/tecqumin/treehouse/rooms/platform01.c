#include <std.h>
#include "../../tecqumin.h"
inherit PLAT_BASE;
int open;

string long_desc();

void create() {
  ::create();
  set_items(([ ({"platform", "wooden platform"}):"The platform circles the"
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
  set_exits( ([ "southwest" : TREEHOUSE + "/rooms/"+ "platform08",
                       "east" : TREEHOUSE + "/rooms/"+ "platform02"]) );
}
void init() {
   ::init();
   add_action("lower_ladder", "lower");
   add_action("lower_ladder", "open");
   add_action("raise_ladder", "raise");
   add_action("raise_ladder", "close");
}

int lower_ladder(string str){
  object room;
  string verb;
  verb = query_verb();
  if (stringp(str)){ str = lower_case(str); }
  if (verb == "lower"){
    if (str =="" || !interact("ladder", str)){
      tell_object(TP, "Did you want to %^BOLD%^%^YELLOW%^lower"
                   +" ladder%^RESET%^?");
      return 1;
    }
  }
  if (verb == "open"){
    if(str == "" || !interact("hatch", str)){
      return 0;
    }
  }
  if ((string)TO->query_exit("down") != "/d/shadowgate/void"){
    tell_object(TP, "The ladder is already lowered");
    return 1;
  }
  room = find_object_or_load(ROOMS + "t_house_base");
  if (!objectp(room)){
    tell_object(TP, "Error identifying the exit room. Please tell a WIZ");
    return 1;
  }
  tell_object(TP, "You open the hatch and lower the rope ladder");
  tell_room(TO, TPQCN + " opens the hatch and lowers the rope ladder", TP);
  tell_room(room, "Someone opens a hatch in the platform and lowers a rope"
                 +" ladder");
  add_exit(ROOMS + "t_house_base", "down");
  room->add_exit(ROOMS + "platform01", "up");
  return 1;
}

int raise_ladder(string str){
  string verb;
  object room;
  verb = query_verb();
  if (stringp(str)){ str = lower_case(str); }
  if (verb == "raise"){
    if(str == ""){
      return 0;
    } 
    if (!interact("ladder", str)){
      return 0;
    }
  }
  if (verb == "close"){
    if (str=="" || !interact("hatch", str)){
      return 0;
    }
  }
  room = find_object_or_load(ROOMS + "t_house_base");
  if (!objectp(room)){
    tell_object(TP, "Error identifying the exit room. Please tell a WIZ");
    return 1;
  }
  tell_object(TP, "You pull the ladder up and close the hatch");
  tell_room(TO, TPQCN + " pulls the ladder up and closes the hatch", TP);
  tell_room(room, "Someone pulls the rope ladder up and closes the hatch");
  remove_exit("down");
  room->remove_exit("up");
  return 1;
}