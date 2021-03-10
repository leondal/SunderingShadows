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
  add_action("leap_across", "leap");
  add_action("leap_across", "jump");
}

string long_desc(){
  return "%^ORANGE%^You are on the outer edge of a low branch in a great"
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

int crawl_along(string str){
  int i, trackable;
  if (str != "along branch"){
    return notify_fail("Crawl where?");
  }
  tell_room(TO, TPQCN + " crawls along the branch, toward the bole of the"
    +" tree.", TP);
  tell_object(TP, "You crawl along the branch, toward the bole of the"
    +" tree.");
  trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)TP->query_property("untrackable")){
    trackable = TP->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  TP->move(JUNG_ROOM + "jag_tree1");
  TP->force_me("look");
  if (trackable >0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  tell_room(ETP, TPQCN + " crawls in along the branch.", TP);
  TO->add_tracks(TP,"tell story", "crawled along the branch"); 
  ETP->add_tracks(TP,"tell story", "crawled in along the branch");
  tell_room(ETP, TPQCN + " crawls in along the branch.", TP);
  return 1;
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
  if (trackable > 0){
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
  ob->move(JUNG_ROOM + "jag_lair_outside");
  ob->force_me("look");
  if (trackable >0){
    ob->set_property("untrackable", trackable);   
  } else {
    ob->remove_property("untrackable");
  }
  tell_object(ob, "You land on a branch in the next tree. There is a hidden"
    +" treehouse here, built around the bole of the tree.");
  tell_room(environment(ob), ob->QCN + " jumps across from another tree.", ob);
  TO->add_tracks(ob,"tell story", "jumped across to the next tree"); 
  environment(ob)->add_tracks(ob,"tell story", "jumped across to the next tree");
}

