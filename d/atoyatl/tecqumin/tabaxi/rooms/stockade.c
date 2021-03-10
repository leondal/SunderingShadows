#include <std.h>
#include <move.h>
#include <daemons.h>
#include <party.h>
#include "../../tecqumin.h"
#define DEST "/daemon/destinations_d.c"
#define OTHERSIDE "main_field"

inherit VAULT;

int pulled;
int check_open();

void create() {
  ::create();
  DEST->add_waystation( file_name(TO), file_name(TO), 1);
  DEST->add_waystation( file_name(TO), TABAXROOM + "centre", 2);
  DEST->add_waystation( file_name(TO), TABAXROOM + "northwest_corner", 2);
  DEST->add_waystation( file_name(TO), TABAXROOM + "southeast_corner", 2);
  DEST->add_waystation( file_name(TO), TABAXROOM + "southwest_corner", 2);
  set_short("Inside the stockade");
  set_long("You are inside the %^ORANGE%^stockade%^RESET%^, standing before the main %^ORANGE%^gateway%^RESET%^. Just to"
          +" the side of the gate is the lever that activates the gate mechanism. You could use it to"
          +" open or close the gate. North, you can see the central area of the stockade. Further"
          +" north appears to be the main living area. To the east there is an area that looks like"
          +" it has been out of use for a while. To the west and north there appears to be a communal"
          +" eating area.");
  set_exits( ([ "west": TABAXROOM + "southwest_corner",
               "east": TABAXROOM + "southeast_corner",
               "north": TABAXROOM + "centre",
               "watch" : TABAXROOM + "watchtower",
               "bt5"   : TABAXROOM + "battlement5",
               "bt6"   : TABAXROOM + "battlement6",
               "bt7"   : TABAXROOM + "battlement7"
             ]) );
  pulled = 0;
  if (check_open() == 1){
    add_exit(TABAXROOM + OTHERSIDE, "south");
  }
  set_items(([  ({"lever", "mechanism"}) : "A heavy lever controls a counterweighted mechanism to open"
                                          +" or close the gate.",
                   ({"gate", "gateway"}) : (:TO, "gate_desc" :) 
                                    ]));
  set_invis_exits( ({"watch", "bt7", "bt6","bt5" }) );
  set_pre_exit_functions( ({"watch", "bt7", "bt6", "bt5"}),({"go_on", "go_on", "go_on", "go_on" }) );
}

void init(){
  ::init();
  add_action("open_gate", "pull");
  set_had_players(3);
  add_action("knock_gate", "knock");
}


string query_granary_dir(){
  return "north";
}

int query_pulled(){
  return pulled;
}

int query_gate_open(){
  if (query_exit("south")==TABAXROOM + OTHERSIDE){
    return 1;
  }
  return 0;
}

string gate_desc(){
  object room;
  string desc;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  desc = "The %^ORANGE%^stockade gate%^RESET%^ is tall, and robust looking, built from the strongest"
        +" timbers of the %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
        +"%^GREEN%^e%^RESET%^ trees. It is designed to open outwards";
  if (objectp(room)){
    desc += room->query_gate_condition();
  }
  if (query_exit("south")==TABAXROOM + OTHERSIDE){
    desc += " The gate is currently open, allowing you to head south out of the stockade";
  }
  return desc;
}

int knock_gate(string str){
  object * party;
  string party_name;
  if (str != "gate" && str != "on gate"){
    notify_fail("Knock on what?");
    return 0;
  }
  if (query_exit("south") == TABAXROOM + OTHERSIDE){
    tell_object(TP, "You don't need to"
                   +" knock, you can just walk south.");
    return 1;
  }
  party_name = TP->query_party();
  if (stringp(party_name)){
    party = (object *)PARTY_OB->query_party_members(party);
  }
  if (sizeof(party)<1){
    party = ({TP});
  }
  tell_room(TO, TPQCN + " knocks on the gate.", TP);
  tell_object(TP, "You knock on the gate.");
  call_out("usher", 2, party);
  return 1;
}

void usher (object * party){
  object mover, room;
  int i;
  tell_room(TO, "The gate swings open");
  if (sizeof(party)<1){
    return;
  }
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  if (!objectp(room)){
    tell_room(TO, "Error with destination room when you knocked on the gate."
                +" Please tell someone that Lujke is a silly lizard. Or make"
                +" a bug report or something");
    return;
  }
  for (i=0;i<sizeof(party);i++){
    mover = party[i];
    if (objectp(mover) && present(mover, TO)){
      tell_object(mover, "You are ushered through the gate");
      tell_room(TO, (string)mover->QCN + " is ushered through the gate", mover);
      mover->move(room);
      mover->force_me("look");
    }
  }
  tell_room(TO, "The gate swings closed again");
}

int open_gate(string str){
  object room;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  if (str != "lever"){
    return notify_fail("pull what?");
  }
  if (pulled ==1){
    return notify_fail("The mechanism is already working");
  }
  if (objectp(room)){
    if ((int)room->query_gate()< 1){
      tell_room(TO, TPQCN + " pulls on the gate mechanism lever, but the gate"
                   +" is too damaged to respond", TP);
      tell_object(TP, "You pull on the gate mechanism lever, but the gate is"
                   +" too damaged to respond");
      return 1;
    }
  }
  pulled = 1;
  switch(query_gate_open()){
  case 0:
    tell_room(TO, TPQCN + " pulls on the lever to open the gate", TP);
    tell_object(TP, "You pull on the lever, which will open the gate");
    call_out("open_gate2", 3);
    break;
  case 1:
    tell_room(TO, TPQCN + " pulls on the lever to close the gate", TP);
    tell_object(TP, "You pull on the lever, which will close the gate");
    call_out("close_gate", 3);
    break;
  }
  return 1;
}

void open_gate2(){
  object room,* orogs, * squads, squad, granary;
  int i, num;
  string where, whereto, *dests;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  tell_room(TO, "%^ORANGE%^With a slight groan, the stockade gate creaks open.");
  add_exit( TABAXROOM + OTHERSIDE, "south");
  if (objectp(room)){
    room->gate_opens();
  }
  pulled = 0;
  if (objectp(room)){
    granary = find_object_or_load(TABAXROOM + "granary");
    if (objectp(granary)){
      orogs = children(MOB + "orog");
      if (granary->query_burned()>6){
        dests = DESTINATIONS_D->query_waystations(TABAXROOM + "orog_entry");
        if (sizeof(dests)>0){
          DESTINATIONS_D->remove_destination(TABAXROOM + "orog_entry");
        }
        DESTINATIONS_D->generate_waystations(TABAXROOM + "orog_entry",4, 3);
        num = sizeof(orogs);
        if (num>0){
          for (i=0;i<num;i++){ 
            if (objectp(orogs[i])){
              orogs[i]->start_walking(TABAXROOM + "orog_entry");
            }
          }
        }
        return;
      }
      if (granary->query_burned()>0){
        dests = DESTINATIONS_D->query_waystations(TABAXROOM + "northeast_corner");
        if (sizeof(dests)>0){
          DESTINATIONS_D->remove_destination(TABAXROOM + "northeast_corner");
        }
        DESTINATIONS_D->generate_waystations(TABAXROOM + "northeast_corner",4, 3);
        num = sizeof(orogs);
        if (num>0){
          for (i=0;i<num;i++){ 
            if (objectp(orogs[i])){
              orogs[i]->start_walking(TABAXROOM + "northeast_corner");
            }
          }
        }
        return;
      }
    }     
  }
  squads = children(MOB + "orog_squad");
  for (i=0;i<sizeof(squads);i++){
    squad = squads[i];
    if (objectp(squad)){
      squad->set_entry_method("Walking right in through the open gate.");
      room = environment(squad);
      where = file_name(room);
      if (where[0..strlen(TABAXROOM+"battlement")-1] == TABAXROOM + "battlement" 
      || where == TABAXROOM + "stockade" || where == TABAXROOM + "centre" 
      || where == TABAXROOM + "east_section" || where == TABAXROOM + "elder" 
      || where == TABAXROOM + "foodhall" || where == TABAXROOM + "granary" 
      || where == TABAXROOM + "kitchen" || where == TABAXROOM + "north_section" 
      || where == TABAXROOM + "northeast_corner"||where == TABAXROOM + "northwest_corner" 
      || where == TABAXROOM + "smithy" || where == TABAXROOM + "southeast_corner" 
      || where == TABAXROOM + "southwest_corner" || where == TABAXROOM + "training" 
      || where == TABAXROOM + "watchtower" || where == TABAXROOM + "west_section"){
        squad->start_walking(TABAXROOM + "granary");  
      } else {
        squad->start_walking(TABAXROOM + "main_field");
        squad->change_tactic(6); // 6 = WALK_IN
      }
    }
  }
}

void close_gate(){
  object room;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  tell_room(TO, "%^ORANGE%^With a slight groan, the stockade gate creaks closed.");
  remove_exit("south");
  pulled =0;
  if (objectp(room)){
    room->gate_closes();
  }
}

int check_open(){
  object room;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  if (objectp(room)){
    return room->query_gate_open();
  } else {
    return 0;
  }
}

int go_on(){
  return 0;
}

