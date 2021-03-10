//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include <move.h>

#include "../tecqumin.h"
#include <move.h>


inherit MONSTER;

object * orogs;
nosave int BEAT, heartcount;

int is_squad_member(object orog);
int check_grouped();
void regroup();
void goto_field();

void create(){
      ::create();
   set_true_invis();
   set_property("no detect",1);
        set_name("archer squad");
        set_id(({"xxarchersquadxx"}));
      set_property("not random monster", 1);
        set_short( (: TO, "short_desc" :) );
        set_race("no_race");
      set_speed(0);
      orogs = ({});
      set_no_clean(1);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

void check_my_heart()
{
    if (heartcount>300){
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

string short_desc(){
  if (TP->query_true_invis() || wizardp(TP)){
    return "An archer squad object, filename: " + base_name(TO);
  } else {
    return "An archer squad object you shouldn't be seeing. Please make a bug report";
  }
}

int is_squad_member(object orog){
  if (member_array(orog, orogs)!=-1){
    return 1;
  }
  return 0;
}
int clean_up(){return 1;}

int count_orogs(){
  return sizeof(orogs);
}

void add_orog(object orog){
  orogs = orogs + ({orog});
}

void remove_orog(object orog){
  orogs -= ({orog});
}

void log(string str){
  object battler, *kids;
  int i;
  kids = children(TABAXOBJ + "tabaxi_battler.c");
  if (sizeof(kids)>0){
    for (i=0;i<sizeof(kids);i++){
      if (objectp(kids[i])){ 
        battler = kids[i];
        break;
      }
    }
  }
  if (objectp(battler)){
    battler->log(str);
  }
}

void set_orogs(object * or){
  orogs = or;
}

object * query_orogs(){
  return orogs;
}

int force_me(string str) {
  int i;
  object ram;
  string * exits;
  if (sizeof(orogs)>0){
    log ("SQUAD:  forcing " + sizeof(orogs) + " orogs to: " + str);
    for (i=0;i<sizeof(orogs);i++){
      if (!objectp(ETO) ||!objectp(orogs[i]) || !present(orogs[i], ETO)){
        continue;
      }
      orogs[i]->force_me(str);
    }
  }
  return ::force_me(str);
}


void regroup(){  // for getting the squad back together if they get separated
  int i;
  object env;
  mapping dests;
  string where_squad, where_orog;
  if (!objectp(ETO)){
    return;
  }
  if (sizeof(orogs)<1){
    return;
  }
  where_squad = file_name(ETO);
  log ("SQUAD -- Regrouping to: " + where_squad);
  dests = DESTINATIONS_D->query_waystations(where_squad);
  if (sizeof(dests)<1){
    DESTINATIONS_D->generate_waystations(where_squad,2, 3);
  }
  for (i=0;i<sizeof(orogs);i++){
    if (!objectp(orogs[i])){
      continue;
    }
    env = environment(orogs[i]);
    if (objectp(env)){
      where_orog = file_name(env);
    }
    if (where_orog != where_squad){
      orogs[i]->start_walking(where_squad);
      stop_walking();
    } 
  }
}



int orog_arrives(object orog){
  string where;
  if (!objectp(orog)){
    return 0;
  }
  log("ARCHER SQUAD: Archer arrives at regroup point");
  if (check_grouped()>0){
    goto_field();
  }
}

int check_grouped(){
  int i;
  object room;
  if (sizeof(orogs)<1 || !objectp(ETO)){
    log ("SQUAD: Environment invalid or no orogs left on a grouping check. Dissolving squad");
    remove();
    return -1;
  }
  for (i=0;i<sizeof(orogs);i++){ 
    if (!objectp(orogs[i])){
      continue;
    }
    room = environment(orogs[i]);
    if (room != ETO){
      return 0;
    }
  }
  return 1;
}

void halt(){
  int i;
  object orog;
  if (sizeof(orogs)>0){
    for (i=0;i<sizeof(orogs);i++){
      orog = orogs[i];
      if (objectp(orog)){
        orog->stop_walking();
        orog->set_speed(0);
      }
    }
  }
}

int reach_destination(){
  string where, * room_names, field;
  object * battlers, * rooms, room;
  int i, num;
  if (check_grouped()<1){
    regroup();
  }
  where = file_name(ETO);
  log("SQUAD - Destination reached: " + where);
  switch(where){
  case TABAXROOM + "main_field":
    field = " main field";
    break;
  case  TABAXROOM + "low_field": 
    field = " low field";
    break;
  case TABAXROOM + "high_field":
    field = " high field";
    break;
  }
  switch (where){
  case TABAXROOM + "main_field": // deliberately falling through
  case TABAXROOM + "low_field": // deliberately falling through
  case TABAXROOM + "high_field":
    rooms = ({}); 
    room_names = ({TABAXROOM + "watchtower", TABAXROOM + "battlement1", 
             TABAXROOM + "battlement2", TABAXROOM + "battlement3", 
             TABAXROOM + "battlement4", TABAXROOM + "battlement5", 
             TABAXROOM + "battlement6", TABAXROOM + "battlement7"});
    num = sizeof(room_names);
    for (i=0;i<num;i++){
      room = find_object_or_load(room_names[i]);
      if (objectp(room)){
        tell_room(room, "A squad of orog archers arrives in the "
         + field + " and starts preparing to fire on the defenders!");
      }
    }
    break;
  }
  return 0;
}

void goto_field(){
  int i;
  string field_name, where;
  mapping dests;
  i = random(3);
  switch(i){
  case 0:
    field_name = TABAXROOM  + "main_field";
    break;
  case 1:
    field_name = TABAXROOM  + "low_field";
    break;
  case 2:
    field_name = TABAXROOM  + "high_field";
    break;
  }
  dests = DESTINATIONS_D->query_waystations(field_name);
  if (sizeof(dests)<1){
    DESTINATIONS_D->generate_waystations(field_name,4, 3);
  }
  start_walking(field_name);
  return;
}

void volley(){
  int i, num;
  object room, * removes;
  string * room_names, env_name;
  if (!objectp(TO) || !objectp(ETO)){ return;}
  removes = ({});
  room_names = ({ TABAXROOM + "battlement1", TABAXROOM + "battlement2",
    TABAXROOM + "battlement3", TABAXROOM + "battlement4", TABAXROOM + "battlement5",
    TABAXROOM + "battlement6", TABAXROOM + "battlement7", TABAXROOM + "battlement8",
    TABAXROOM + "watchtower"  });
  env_name = file_name(ETO);
  num = sizeof(room_names);
  for (i=0;i<num;i++){
    room = find_object_or_load(room_names[i]);
    if (objectp(room)){
      tell_room(room, "%^MAGENTA%^Orog archers loose a volley against the"
                     +" battlements from " + (string)ETO->query_short()); 
    } else {
      ::force_me("tell lujke %^BOLD%^%^RED%^The room called " + room_names[i] + " isn't valid");
    }
  }
  num = sizeof(orogs);
  for (i=0;i<num;i++){
    if (!objectp(orogs[i])){
      removes += ({orogs[i]});
      continue;
    }
    orogs[i]->force_me("shoot at battlement");
  }
  if (sizeof(removes)>0){
    orogs -= removes;
  }
}

void heart_beat(){
  int i;
  object * removes;
  string room;
  ::heart_beat();
  removes = ({});
  for (i=0;i<sizeof(orogs);i++){
    if (!objectp(orogs[i])){
      removes += ({orogs[i]});
    }
  }
  orogs -= removes;
  if (random(4)<2){
    if (objectp(ETO)){
      ETO->set_had_players(2);
      room = file_name(ETO);
      if (room == TABAXROOM + "main_field" ||
          room == TABAXROOM + "high_field" ||
          room == TABAXROOM + "low_field"  ) {
        volley();
      }
    }
  } 
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

void retreat(){
  object room;
  string * dests;
  room = TABAXROOM + "orog_entry";
  dests = DESTINATIONS_D->query_waystations(room);
  if (sizeof(dests)<1){
    DESTINATIONS_D->generate_waystations(room,2, 4);
  }
  start_walking(room);
}

