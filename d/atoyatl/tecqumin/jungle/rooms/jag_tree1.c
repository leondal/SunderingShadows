#include <std.h>
#include <move.h>
#include "../../tecqumin.h"
inherit JUNG_ROOM + "jung_base.c";

void create(){
  ::create();
  set_name("In the branches");
  set_short("%^GREEN%^In the %^ORANGE%^branches");
  set_exits( (["crawl along branch" : JUNG_ROOM + "jag_tree_room2"]) );
  set_invis_exits( ({"crawl along branch"}) );
}

void init(){
  ::init();
  add_action("crawl_along", "crawl");
  add_action("climb_down", "climb");
}

string long_desc(){
  return "%^ORANGE%^You are resting on one of the lower branches of a great"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^tree%^ORANGE%^. The solid,"
    +" sturdy limb supports your weight easily. %^GREEN%^Le%^BOLD%^%^GREEN%^a"
    +"%^RESET%^%^GREEN%^ves%^ORANGE%^, wet from the %^BLUE%^humidity"
    +" %^ORANGE%^of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
    +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
    +" %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^, brush against you, and"
    +" %^GREEN%^trailing v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes"
    +" %^ORANGE%^loop around branches before dropping back toward the ground.";
}

int climb_down(string str){
  int trackable;
  if (str != "down" && str != "down tree"){
    return notify_fail("Climb where?");
  }
  tell_room(TO, TPQCN + " down to the ground", TP);
  tell_object(TP, "You down to the ground");
    trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)TP->query_property("untrackable")){
    trackable = TP->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  TP->move(JUNG_ROOM4 + "jag_lair_entry");
  TP->force_me("look");
  if (trackable >0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  TO->add_tracks(TP, "tell story", "climbed down the tree");
  ETP->add_tracks(TP, "climbed down from above");
  return 1;
}

int crawl_along(string str){
  int i, trackable;
  if (str != "along branch"){
    return notify_fail("Crawl where?");
  }
  tell_room(TO, TPQCN + " crawls along the branch, away from the bole of the"
    +" tree.", TP);
  tell_object(TP, "You crawl along the branch, away from the bole of the"
    +" tree.");
  trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)TP->query_property("untrackable")){
    trackable = TP->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  TP->move(JUNG_ROOM + "jag_tree2");
  TP->force_me("look");
  if (trackable >0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  tell_room(ETP, TPQCN + " crawls in along the branch.", TP);
  TO->add_tracks(TP,"tell story", "crawled along the branch"); 
  ETP->add_tracks(TP,"tell story", "crawled in along the branch"); 
  return 1;
}
