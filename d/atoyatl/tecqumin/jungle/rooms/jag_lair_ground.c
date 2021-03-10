#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "up": JUNG_ROOM + "jag_lair_outside" ]);
  set_basic_exits();
  r_path = JUNG_ROOM4 + "j_maze";
}

void eject(){
  return; // This room does not need to eject people when it is not part of a maze
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
  case SCRAMBLE:
    add_action("scramble_under", "scramble");
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
  TP->move(JUNG_ROOM4 + "jag_lair_entry");
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
  TP->move(JUNG_ROOM4 + "jag_lair_entry");
  TP->force_me("look");
  if (trackable >0){
    TP->set_property("untrackable", trackable);   
  } else {
    TP->remove_property("untrackable");
  }
  TO->add_tracks(TP, "tell story", "squeezed through a thicket");
  ETP->add_tracks(TP, "squeezed in through a thicket");
  return 1;
}
