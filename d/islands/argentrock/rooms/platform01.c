//Refuge entrance -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"outdoors.c";

void create(){
  ::create();
  set_long((:TO,"long_desc":));
  set_items(([
    ({"platform", "branch", "floor" }):
      "%^ORANGE%^A large branch emerges from the tree and forms the "
      "floor of the platform.%^RESET%^",

    ({"trunk", "tree" }):
      "%^ORANGE%^You cannot identify what kind of tree this is. It is "
      "like nothing you have ever seen before, with a diameter "
      "of at least twenty feet and a %^RESET%^cool gray color%^ORANGE%^ with "
      "smooth bark.%^RESET%^",

    ({"ground", "below", "forest" }):
      "%^GREEN%^A small and overgrown path runs through the forest below "
      "with some flowers and mushrooms, that you cannot make "
      "out from here, growing by the base of the %^ORANGE%^trees%^RESET%^"
      "%^GREEN%^.%^RESET%^",

    ({"rope", "ladder", "rope ladder" }):
      "%^RED%^A high quality rope ladder made from a strange %^RESET%^gray "
      "material%^RED%^ that seems as strong as %^CYAN%^steel%^RED%^.",

    ({"branches", "canopy" }):
      "%^ORANGE%^Thick, stout branches are %^GREEN%^growing%^ORANGE%^ from "
      "the trunk at evenly spaced intervals encircling the tree at a forty-five "
      "degree angle. They esentially form %^GREEN%^living%^ORANGE%^ steps "
      "to ascend to the platforms above.%^RESET%^"
  ]));
  set_exits(([
    "up" : PATH+"platform15",
    "down" : PATH+"argpath11",
  ]));
  set_pre_exit_functions(({"down"}),({"go_down"}));
  set_post_exit_functions(({"down"}),({"went_down"}));
}

string long_desc(){
  return
    "%^BOLD%^%^GREEN%^A hidden platform in the trees of Argentrock Forest%^RESET%^\n"
    "%^ORANGE%^You are standing on a small platform which serves as an "
    "excellent vantage point of the %^GREEN%^forest%^ORANGE%^ below. Emerging proudly "
    "from the trunk of the great tree is a large branch that "
    "seems to have grown for the very purpose of being a floor. "
    "A rope %^RED%^ladder%^ORANGE%^ lays coiled near the base of the branch that "
    "can easily be tossed to the %^CYAN%^ground%^ORANGE%^ to allow quick access "
    "from below. Several smaller branches sprout from the trunk "
    "and form steps to the %^GREEN%^canopy%^ORANGE%^ above.";
}

int go_down() {
  tell_object(TP,
    "%^ORANGE%^You toss the rope %^RED%^ladder%^ORANGE%^ over the edge of the "
    "platform and carefully climb down to the %^CYAN%^ground%^ORANGE%^ "
    "below.%^RESET%^");
  tell_room(TO,
    "%^ORANGE%^"+TPQCN+" tosses the rope %^RED%^ladder%^ORANGE%^ over the edge "
    "of the platform and carefully climbs down to the %^CYAN%^ground%^ORANGE%^ "
    "below.%^RESET%^",TP);
  return 1;
}

void went_down() {
  tell_room(ETP,
    "%^ORANGE%^"+TPQCN+" tosses a rope %^RED%^ladder%^ORANGE%^ down from the "
    "trees above and carefully climbs down to the %^CYAN%^ground%^ORANGE%^."
    "%^RESET%^",TP);
}

void reset(){
  ::reset();
  if(!present("outpostmon")) {
    new(MON+"ambusher.c")->move(TO);
    new(MON+"ambusher.c")->move(TO);
    present("outpostmon")->set_speed(0);
    present("outpostmon 2")->set_speed(0);
  }
}

