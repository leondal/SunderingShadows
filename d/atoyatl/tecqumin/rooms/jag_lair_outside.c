#include <std.h>
#include <move.h>
#include "../../tecqumin.h"
inherit JUNG_ROOM + "jung_base.c";

void create(){
  ::create();
  set_exits(([ "down": JUNG_ROOM + "jaguar_lair_ground" ]));
  set_name("In the branches");
  set_short("%^GREEN%^In the %^ORANGE%^branches");
  set_exits( (["down" : JUNG_ROOM + "jag_lair_ground",
                                      "enter": JUNG_ROOM + "jaguar_lair"]) );
  set_invis_exits( ({"crawl along branch"}) );
  add_item(({"treehouse", "hidden treehouse"}), "%^ORANGE%^The"
    +" %^RESET%^treehouse %^ORANGE%^is a sizeable structure, which only"
    +" remains hidden due to its cunning %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^"
    +"o%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ou%^BOLD%^%^GREEN%^r%^RESET%^"
    +"%^GREEN%^at%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^on %^ORANGE%^and the"
    +" density of %^GREEN%^leaves %^ORANGE%^and %^GREEN%^v%^BOLD%^%^GREEN%^"
    +"i%^RESET%^%^GREEN%^nes %^ORANGE%^in the %^BOLD%^%^GREEN%^c%^RESET%^"
    +"%^GREEN%^an%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^py %^ORANGE%^surrounding"
    +" the tree. An %^BOLD%^%^BLACK%^arched entryway%^RESET%^%^ORANGE%^"
    +" leads inside."); 
}

void init(){
  object room, lair_entry;
  int entry;
  ::init();
  room = find_object_or_load(TECSTORE);
    if ((int)room->query_jag_entry() == -1){
    lair_entry = find_object_or_load(JUNG_ROOM4 + "jag_lair_entry");
    lair_entry->setup_entry();   
  }
  entry = room->query_jag_entry();
  switch(entry){
  case CLIMB:
    add_action("leap_across", "leap");
    add_action("leap_across", "jump");
    break;
  }
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
    +" %^ORANGE%^loop around branches before dropping back toward the ground. "
    +" There is a hidden %^RESET%^treehouse%^ORANGE%^ here, built against the"
    +" bole of the tree and"
    +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^m%^RESET%^"
    +"%^GREEN%^o%^BOLD%^%^GREEN%^fl%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^g"
    +"%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^d%^RESET%^%^ORANGE%^ against the"
    +" colours of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^n"
    +"%^RESET%^%^GREEN%^gl%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^.";
}

int leap_across(string str){
  if (str != "across" && str != "to next tree" 
       && str != "toward the next tree" && str != "next tree"){
    return notify_fail("leap where?");
  }
  tell_room(TO, TPQCN + " makes a mighty leap toward a branch on the next tree."
             , TP);
  tell_object(TP, "You make a mighty leap toward a branch on the next tree.");
  if (TP->query_skill("athletics") + random(35)< 34) {
    call_out("fall", 2, TP);
  } else {
    call_out("leap2", 2, TP);
  }
  return 1;
}

void fall(object ob){
  int i, trackable;
  if (!objectp(ob) || !present(ob, TO)){
    return;
  }
  tell_room(TO, ob->QCN + " sails briefly through the %^BOLD%^%^CYAN%^air%^RESET%^,"
    +" but falls short of " + ob->QP + " target and crashes to the"
    +" %^ORANGE%^ground%^RESET%^.", ob);
  tell_object(ob, "You sail briefly through the %^BOLD%^%^CYAN%^air%^RESET%^,"
    +" but fall short of your target and crash to the %^ORANGE%^ground%^RESET%^.");
  trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)ob->query_property("untrackable")){
    trackable = ob->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  ob->move(JUNG_ROOM + "jag_lair_ground");
  ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(1, 50) + 99, "bludgeoning");
  ob->force_me("look");
  if (trackable >0){
    ob->set_property("untrackable", trackable);   
  } else {
    ob->remove_property("untrackable");
  }
  tell_room(environment(ob), ob->QCN + " crashes to the %^ORANGE%^ground%^RESET%^"
    +" from above.", ob);
  TO->add_tracks(ob,"tell story", "leaped toward the next tree"); 
  environment(ob)->add_tracks(ob,"tell story", " fell from above");
}

void leap2(object ob){
  int i, trackable;
  trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)ob->query_property("untrackable")){
    trackable = ob->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  ob->move(JUNG_ROOM + "jag_tree2");
  ob->force_me("look");
  if (trackable >0){
    ob->set_property("untrackable", trackable);   
  } else {
    ob->remove_property("untrackable");
  }
  tell_object(ob, "You land on a branch in the next tree.");
  tell_room(environment(ob), ob->QCN + " jumps across from another tree.", ob);
  TO->add_tracks(ob,"tell story", "jumped across to the next tree"); 
  environment(ob)->add_tracks(ob,"tell story", "jumped across to the next tree");
}
