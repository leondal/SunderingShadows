#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Cobbled road."
  );
  set_long(
  "Cobbled road.\n"
  "  This hard cobbled road looks like its had a lot of heavy use."
  "  Many wagons and travelers have passed this way and your happy its set with paving stones or else it would be a wreck like most roads you've seen."
  "\n"
  );
  set_smell("default",
  "You smell the far way smells of farm animals."
  );
  set_listen("default",
  "The sounds of your travel echo on the paving stones."
  );
  set_items(([
  "road":"Hard packed paving stones line the well kept road.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  ]));
  set_exits(([
  "south":ROOMS"v2.c",
  ]));
  set_pre_exit_functions(({"north"}),({"stick_em"}));
}
int stick_em(){
  if((string)TP->query_race()== "pig" || "cow" || "undead" ){
  tell_room(TO,"%^BOLD%^The "+TP->query_race()+" drops to the ground and disolves into mush as it tries to leave this cursed area!.");
  TP->do_damage("torso",1000);
  return 0;
  }
}
