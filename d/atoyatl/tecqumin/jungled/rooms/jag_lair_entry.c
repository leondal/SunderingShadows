#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

int route;

//scramble under a fern //climb tree //squeeze through thicket

void setup_entry(){
  object ob, room;
  string dowhat;
  ob = new ("/std/living.c");
  ob->set_race("jaguar");
  room = find_object_or_load(TECSTORE);
  switch (random(3)){
  case 0:
    if ((int)room->query_jag_entry() == -1){
      room->set_jag_entry(SCRAMBLE);
    }
    dowhat = "scrambled under a bed of ferns";
    break;
  case 1:
    if ((int)room->query_jag_entry() == -1){
      room->set_jag_entry(CLIMB);
    }
    dowhat = "scaled a tree";
    break;
  case 2:
    dowhat = "squeezed through a thicket";
    if ((int)room->query_jag_entry() == -1){
      room->set_jag_entry(SQUEEZE);
    }
    break;
  }
  add_tracks(ob, "tell story", dowhat);
}

void create() {
  r_path = JUNG_ROOM4;
  ::create();
  setup_entry();
}

void init(){
  object room;
  int entry;
  ::init();
  room = find_object_or_load(TECSTORE);
  if ((int)room->query_jag_entry() == -1){
    setup_entry();   
  }
  entry = room->query_jag_entry();
  switch(entry){
  case SCRAMBLE:
    add_action("scramble_under", "scramble");
    break;
  case CLIMB:
    add_action("climb_tree", "climb");
    add_action("climb_tree", "scale");
    break;
  case SQUEEZE:
    add_action("squeeze_through", "squeeze");
    break;
  }
}

int scramble_under(string str){
  int trackable;
  if (str != "under ferns" && str != "under a bed of ferns"
      && str != "under bed of ferns" && str != "under fern"){
    return notify_fail("Scramble where?");
  }
  tell_room(TO, TPQCN + " scrambles under a bed of ferns"
      , TP);
  tell_object(TP, "You scramble under a bed of ferns");
    trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)TP->query_property("untrackable")){
    trackable = TP->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  TP->move(JUNG_ROOM + "jag_lair_ground");
  TP->force_me("look");
  if (trackable >0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  TO->add_tracks(TP, "tell story", "scrambled under a bed of ferns");
  ETP->add_tracks(TP, "scrambled in from under a bed of ferns");
  return 1;
}

int climb_tree(string str){
  int trackable;
  if (str != "tree" && str != "up tree"){
    return notify_fail("Climb where?");
  }
  tell_room(TO, TPQCN + " climbs rapidly up a tree"
      , TP);
  tell_object(TP, "You climb up the tree");
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
  TO->add_tracks(TP, "tell story", "climbed up a tree");
  ETP->add_tracks(TP, "climbed up from below");
  return 1;
}

int squeeze_through(string str){
  int trackable;
  if (str != "through thicket"){
    tell_object(TP, "Squeeze where?");
    return -1;
  }
  tell_room(TO, TPQCN + " leaves by squeezing through a thicket"
      , TP);
  tell_object(TP, "You squeeze through a thicket");
    trackable = 0;  // All the stuff with the trackable variable is to stop
                  // an "X appeared" track being formed in the destination room
  if ((int)TP->query_property("untrackable")){
    trackable = TP->query_property("untrackable");
  }
  TP->set_property("untrackable", 1);
  TP->move(JUNG_ROOM + "jag_lair_ground");
  TP->force_me("look");
  if (trackable > 0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  TO->add_tracks(TP, "tell story", "squeezed through a thicket");
  ETP->add_tracks(TP, "squeezed in through a thicket");
  return 1;
}
