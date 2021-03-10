//Coded by Lujke

#include <std.h>
#include "../../tecqumin.h"
#include <party.h>
#include <daemons.h>
#define HITLOCS ({"through the eye", "in the chest", "in its neck",\
       "to the stomach", "in the leg", "in the face", "in the groin"})
#define SQUADNAME ({"Petros", "Frulannan", "Trakas", "Udokul",\
      "Xanril", "Panben", "Hortiln", "Horven", "Udoben", "Darkeyes",\
      "Panhand", "Walian", "Fruven", "Moogul", "Gar'dal", "Negal",\
      "Kazil", "Kag'ar", "Zserub", "Augraz", "Khiva","Krelsha",\
      "Arlka", "Wa'shan", "Eshtrul", "Loogie", "Urklan"})
#define CRITTERS ({"orog", "orog_squad", "archer_squad", "tabaxi",\
       "tabaxi_archer", "tabaxi_warrior"})
inherit OBJECT;


int timer;
int start_ladders(object room, object * orogs);
int count_tabaxi();
void marshall();
void ground_attack();
void broadcast(string str, object * rooms);
void end_attack();
void remove_orogs();
void advance_squads();
void start_attack(object who);
string * def_names;
string meth;


object * defenders;


int start_time, ram_tried;
void create() {
    ::create();
    timer = 300;
    set_name("Tabaxi battle organiser");
    set_id( ({"battler", "organiser","battle organiser","tabaxi battle organiser",}));

    set_short("Tabaxi battle organiser");
    set_weight(4);
    set_long("This is a device for organising battles. For the tabaxi. The"
            +" clue is in the title, really.");
    meth = "It just happened. In the tabaxi battler";
    set_heart_beat(1);  
}

void log(string str){
  log_file("battler" , day(time()));
  log_file("battler" , ", " + date(time()));
  log_file("battler" , " " + month(time()));
  log_file("battler", " " + hour(time()));
  log_file("battler", ":" + minutes(time()));
  log_file( "battler", "  " + str + "  ");
}

object * query_defenders(){
  return defenders;
}

string * query_def_names(){
  return def_names;
}

void set_meth(string end_meth){
  meth = end_meth;
}

void postpone_cleanup(){
  string * rooms;
  object room;
  int i, num;
  rooms = ({ TABAXROOM + "", TABAXROOM + "northeast_corner",
            TABAXROOM + "stockade", TABAXROOM + "northeast_corner",
            TABAXROOM + "foodhall", TABAXROOM + "northwest_corner",
            TABAXROOM + "granary", TABAXROOM + "main_field",
            TABAXROOM + "high_field", TABAXROOM + "low_field",
            TABAXROOM + "kitchen", TABAXROOM + "north_section",
            TABAXROOM + "southeast_corner", TABAXROOM + "southwest_corner",
            TABAXROOM + "stockwall1", TABAXROOM + "stockwall2",
            TABAXROOM + "stockwall3", TABAXROOM + "training",
            TABAXROOM + "watchtower", TABAXROOM + "west_section",
            TABAXROOM + "treetop_base1", TABAXROOM + "treetop_base2",
            TABAXROOM + "treetop_base3", TABAXROOM + "treetop1",
            TABAXROOM + "treetop2", TABAXROOM + "treetop3",
            TABAXROOM + "smithy"  });
  num = sizeof(rooms);
  for (i=0;i<num;i++){
    room  = find_object_or_load(rooms[i]);
    if (objectp(room)){
      room->set_had_players(8);
    }
  }
}

void init(){
  ::init();
  add_action("kick_off", "start");
  add_action("deploy_defenders","deploy");
}

int kick_off(string str){
  start_attack(TP);
}

int deploy_defenders(string str){
  int i;
  string where;
  object tabaxi, room;
  for(i=1;i<9;i++){
    tabaxi = new(MOB + "tabaxi_archer");
    where = TABAXROOM + "battlement" + i;
    room = find_object_or_load(where);
    if (objectp(room)){
      tabaxi->move(room);
      tabaxi->force_me("target orog in field");
    }
  }
  for(i=1;i<4;i++){
    tabaxi = new(MOB + "tabaxi_warrior");
    where = TABAXROOM + "northeast_corner";
    room = find_object_or_load(where);
    if (objectp(room)){
      tabaxi->move(room);
    }
  }
  tabaxi->force_me("block down");
}

void reset_waystations(){
  string * destinations, destination, * removals;
  mapping map;
  int i, length;
  object lujke;
  lujke = find_player("lujke");
  map = DESTINATIONS_D->query_destinations();
  destinations = keys(map);
  removals = ({});
  length = strlen(TABAXROOM)-1;
  if (sizeof(destinations)>0){
    for (i=0;i<sizeof(destinations);i++){
      destination = destinations[i];
      if (destination[0..length] == TABAXROOM[0..length]){
        removals += ({destination});
      }
    }
  }
  if (sizeof(removals)>0){
    for (i=0;i<sizeof(removals);i++){
      destination = removals[i];
      DESTINATIONS_D->remove_destination(destination);
    }
  }
  map = DESTINATIONS_D->query_destinations();
  destinations = keys(map);
  if (objectp(lujke) && sizeof(destinations)>0){
    tell_object(lujke, "%^BOLD%^%^YELLOW%^These are the current destinations in the daemon:");
    for (i=0;i<sizeof(destinations);i++){
      tell_object(lujke, destinations[i]);
    }
  }
  DESTINATIONS_D->generate_waystations(TABAXROOM + "granary" , 2, 2);
}

reset_tabaxi(){
  int i, j, count;
  string * mob_types;
  object * tabaxi, room, tab;
  mob_types = ({MOB + "tabaxi", MOB + "tabaxi_archer", MOB + "tabaxi_blacksmith", MOB + "tabaxi_warrior"});
  for (i=0;i<sizeof(mob_types);i++){
    tabaxi = children(mob_types[i]);
    count = sizeof(tabaxi);
    if (count>0){
      for (j=count-1;j>=0;j--){
        room= environment(tabaxi[j]);
        tabaxi[j]->remove();
        if (objectp(room)){
          tab = new(mob_types[i]);
          tab->move(room);
        }
      }
    }
  }
}

void report(string what){
  "/daemon/reporter_d"->report("lujke", "%^BOLD%^%^GREEN^%Tabaxi battler reports:%^RESET%^ " + what);
}

void end_attack(){
  int i, j;
  object granary, * tabaxi;
  string * mob_types;
  if (sizeof(defenders)<1){
    return;
  }
  meth = "a method that has generated an error. Please make a bug report about it.";
  granary = find_object_or_load(TABAXROOM + "granary");
  if (objectp(granary)){
    meth = granary->query_entry_method();
  }
  meth =  "The battle is lost! The orogs have destroyed the tabaxi's crops. They burned the whole lot."
          +" They gained entry by " + meth;
  report ("Checking for defenders to record event for");
  if (sizeof(defenders)>0){
    for (i=0;i<sizeof(defenders);i++){
      if (objectp(defenders[i])){
        tell_object(defenders[i], meth);
        report("Recording failure for " + defenders[i]->query_name());
        EVENT_RECORDS_D->record_event(defenders[i]->query_name(), "Failed to protect the Tabaxi", time());
      }
    }
  } else {
    report ("No defenders to record event for");
  }
  reset_tabaxi();
}

string query_meth(){
   return meth;
}

void victory(){
  object * squads, nobacherie, defender, elder_room, *removes;
  int i;
  string name, * quests;
  if (sizeof(defenders)<1){ return; }
  removes = ({});
  for (i=0;i<sizeof(defenders);i++){
    defender = defenders[i];
    if (!objectp(defender)){ 
      removes += ({defender});
    }
  }
  if (sizeof(removes)>0){
    for (i=0;i<sizeof(removes);i++){
      defender = removes[i];
      defenders -= ({defender});
    }
  } 
  elder_room = find_object_or_load(TABAXROOM + "elder");
  if (objectp(elder_room)) nobacherie = present("nobacherie", elder_room);
  if (!objectp(nobacherie)) nobacherie = find_object_or_load(MOB + "nobacherie");
  if (sizeof(defenders)>0){
    for (i=0;i<sizeof(defenders);i++){
      defender = defenders[i];
      tell_player(defender, "The attack is over! The remaining"
        +" orogs are withdrawing in disarray The Tabaxi are saved!");
      quests = defender->query_mini_quests();
      if(member_array("Tabaxi Defender", quests)!=-1){
        defender->remove_mini_quest("Tabaxi Defender");
      }
      if (objectp(nobacherie)) nobacherie->remove_greeted_object(defender);
      if(member_array("Great Defender of the Tabaxi", quests)==-1){
        defender->set_mini_quest("Great Defender of the Tabaxi");
      }
      EVENT_RECORDS_D->record_event(defender->query_name(), "Defended the"
        +" Tabaxi grain stores", time());
    }
  }
  squads = children("/realms/lujke/tecqumin/mons/orog_squad");
  if (sizeof(squads)>0){
    for (i=0;i<sizeof(squads);i++){
      squads[i]->retreat();
    }
  }
  squads = children("/realms/lujke/tecqumin/mons/archer_squad");
  if (sizeof(squads)>0){
    for (i=0;i<sizeof(squads);i++){
      squads[i]->retreat();
    }
  }
}

void defeat(){
  object nobacherie, defender, *removes;
  int i;
  string name, * quests;
  if (sizeof(defenders)<1){ return; }
  removes = ({});
  for (i=0;i<sizeof(defenders);i++){
    defender = defenders[i];
    if (!objectp(defender)){ 
      removes += ({defender});
    }
  }
  if (sizeof(removes)>0){
    for (i=0;i<sizeof(removes);i++){
      defender = removes[i];
      defenders -= ({defender});
    }
  } 
  if (sizeof(defenders)>0){
    for (i=0;i<sizeof(defenders);i++){
      defender = defenders[i];
      tell_player(defender, "%^BOLD%^%^RED%^You have failed in your quest to aid the Tabaxi. /n"
                     +"%^RESET%^%^BLUE%^Perhaps you should retreat and try again another day.");
      quests = defender->query_mini_quests();
      if(member_array("Tabaxi Defender", quests)!=-1){
        defender->remove_mini_quest("Tabaxi Defender");
      }
      if(member_array("Great Defender of the Tabaxi", quests)==-1 &&
         member_array("Failed Defender of the Tabaxi", quests)==-1){
        defender->set_mini_quest("Failed Defender of the Tabaxi");
      }
    }
  }
  reset_tabaxi();
  move("/d/shadowgate/void");
  remove();
}

void heart_beat(){
  object * orogs, * archers;
  if (random(10)==9){
    if (time()>start_time + 1200){
      victory();
      set_heart_beat(0);
      return;
    }
  }
  orogs = children(MOB + "orog.c");
  archers = children(MOB + "orog_archer.c");
  if (sizeof(orogs) + sizeof(archers) < 3){
    victory();
    set_heart_beat(0);
    return;
  }
  timer --;
  if (timer<0){
    timer = 300;
    if (sizeof(defenders)>0){
      postpone_cleanup();
    }
  }
  return;
}

int query_timer(){
  return timer;
}

void set_start_time(int t){
  start_time = t;
}

int query_start_time(){
  return start_time;
}


void broadcast(string str, object * rooms){
  int i;
  object room;
  if (sizeof(rooms)>0){
    for (i=0;i<sizeof(rooms);i++){
      room = find_object_or_load(rooms[i]);
      if (objectp(room)){
        tell_room(room, str);
      }
    }
  }
  log (str);
}

int clean_up(){
  object room, * obs;
  int i, num;
  room = find_object_or_load(TABAXROOM + "stockade");
  obs = all_inventory(room);
  num = sizeof(obs);
  if (num>0){
    for (i=0;i<num;i++){
      obs[0]->remove();
    }
  }
}

int remove_defenders(){
  object * tabaxi;
  int i, num;
  tabaxi = children(MOB + "tabaxi_archer");
  num = sizeof(tabaxi);
  if (num>0){
    for (i=0;i<num;i++){
      tabaxi[0]->remove();
    }
  }
  tabaxi = children(MOB + "tabaxi");
  num = sizeof(tabaxi);
  if (num>0){
    for (i=0;i<num;i++){
      tabaxi[0]->remove();
    }
  }
  tabaxi = children(MOB + "tabaxi_warrior");
  num = sizeof(tabaxi);
  if (num>0){
    for (i=0;i<num;i++){
      tabaxi[0]->remove();
    }
  }
  clean_up();
  return  1;
}

int setup_defence(object defender){
  object tabaxi, room, ob, weapon, * critters;
  int i, j, num; 
  string roomname;
  // clear away tabaxi and orogs
  for (i=0;i<6;i++){
    critters = children(MOB + CRITTERS[i]);
    num = sizeof(critters);
    if (num>0){
      for (j=0;j<num;j++){
        critters[0]->move("/d/shadowgate/void");
      }
    }
  }
  //put archers & warriors on battlement
  for (i=1;i<9;i++){
    roomname = TABAXROOM + "battlement" + i;
    room = find_object_or_load(roomname);
    if (objectp(room)){
      tabaxi = new(MOB + "tabaxi_archer");
      if (objectp(tabaxi)){
        tabaxi->move(room);
        tabaxi->set_commander(defender);
        tabaxi->force_me("target orog in field");
      }
      if (random(3)<1){
        tabaxi = new (MOB + "tabaxi_warrior");
        if (objectp(tabaxi)){
          tabaxi->move(room);
          tabaxi->set_commander(defender);
          weapon = new ("/d/common/obj/weapon/spear_lg");
          weapon->move(tabaxi);
          tabaxi->force_me("wield spear");
        }
      }     
    }
  }
  // put warriors by gate 
  room = find_object_or_load(TABAXROOM + "stockade");
  if (objectp(room)){
    for (i=0;i<4;i++){
      tabaxi = new (MOB + "tabaxi_warrior");
      tabaxi->move(room);
      tabaxi->set_commander(defender);
      weapon = new ("/d/common/obj/weapon/spear_lg");
      weapon->move(tabaxi);
      tabaxi->force_me("wield spear");
    }
  }
  // prepare catapult & crew
  room = find_object_or_load(TABAXROOM + "southeast_corner");
  ob = present("catapult", room);
  ob->set_overallStatus(100);
  for (i=0;i<3;i++){
    ob = new(MOB + "tabaxi");
    ob->move(room);
    ob->set_commander(defender);
    ob = new(TABAXOBJ + "rocks");
    ob->move(room); 
  }
  //put pits in fields
  room = find_object_or_load(TABAXROOM + "main_field");
  if (objectp(room)){
    room->set_pitted(3);
  }
  room = find_object_or_load(TABAXROOM + "high_field");
  if (objectp(room)){
    room->set_pitted(2);
    room->add_item("ground", "The ground has been disturbed a bit here.");
    room->set_search("ground", "A careful scan of the ground identifies several areas where it appears that"
                        +" pits have been dug and then covered over and " + CAMOUFLAGED + "");
  }
    room = find_object_or_load(TABAXROOM + "low_field");
  if (objectp(room)){
    room->set_pitted(4);
    room->add_item("ground", "The ground has been disturbed a bit here.");
    room->set_search("ground", "A careful scan of the ground identifies several areas where it appears that"
                        +" pits have been dug and then covered over and " + CAMOUFLAGED + "");
  }
  
}

void start_attack(object who){
  string party , room_name, name, squad_names, *mob_types;
  object * orogs, * squads, squad, rooms, room, lujke, orog, high_lvl_player, * tabaxi;
  int num, i, j, k, l, tactic, tac_mod, count, original_lvl, modifier, original_ac;
  tac_mod = 0;
  start_time = time();
  if (!objectp(who)){
    return;
  }
  room =find_object_or_load(TABAXROOM + "orog_entry"); // to ensure there are ladders available
  postpone_cleanup();
  squad_names = SQUADNAME;
  def_names = ({});
  lujke= find_player("lujke");
  room = find_object_or_load("orog_entry"); // to make sure the ram is loaded into memory
  ram_tried = 0;
  start_time = time();
  party = who ->query_party();
  if (stringp(party)){
    def_names = ({});
    defenders = (object *)PARTY_OB->query_party_members(party);
  }
  if (sizeof(defenders)<1){
    defenders = ({who});
  }
  high_lvl_player = defenders[0];
  for (i=0;i<sizeof(defenders);i++){
    if (defenders[i]->query_level() > high_lvl_player->query_level()){
      high_lvl_player = defenders[i];
    }
    name = defenders[i]->query_true_name();
    def_names += ({name});
  }
  broadcast("%^BOLD%^%^BLACK%^Dark shapes%^RESET%^%^GREEN%^ move in the %^BOLD%^%^GREEN%^j%^RESET%^"
           +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ at"
           +" the edges of the settlement as a force of %^BOLD%^%^BLACK%^Orogs%^RESET%^%^GREEN%^"
           +" arrive, preparing an attack.",
           ({TABAXROOM + "watchtower", TABAXROOM + "main_field",TABAXROOM + "low_field",
             TABAXROOM + "high_field", TABAXROOM + "battlement1", TABAXROOM + "battlement2",
             TABAXROOM + "battlement3", TABAXROOM + "battlement4", TABAXROOM + "battlement5",
             TABAXROOM + "battlement6", TABAXROOM + "battlement7", TABAXROOM + "battlement8"
             }));
  room_name = TABAXROOM + "entry";
  room = find_object_or_load(room_name);
//  num = 5;  //temporary fix, while checking something
  num =  3 + sizeof(defenders) + random (sizeof(defenders));
  orogs = ({});
  l = random(sizeof(squad_names));
  for (i=0;i<num;i++){
    squad = new(MOB + "orog_squad" );
    squad->move(room);
    k=random(4)+3;
    squad->set_speed(0);
    squad->set_no_clean(1);
    squad->set_property("squad name", squad_names[l]);
    l ++;
    if (l>sizeof(squad_names)-1){
      l=0;
    }
    if(objectp(lujke)){
      tell_object(lujke, "Orog squad number " + (i+1) + " created and named "
                   + squad_names[l] + " squad.");
    }
    switch(random(5)){
    case 0:
      room_name = TABAXROOM + "entry";
      break;
    case 1:
      room_name = TABAXROOM + "jungle26";
      break;
    case 2:
     room_name = TABAXROOM + "treetop_base3";
      break; 
    case 3: 
      room_name = TABAXROOM + "orog_entry";
      break; 
    case 4: 
      room_name = TABAXROOM + "jungle02";
      break; 
    }
    room = find_object_or_load(room_name);
    if (objectp(room)){
      squad->move(room);
      for (j=0;j<k;j++){
        orog = new(MOB + "orog");
        "/daemon/alternative_world_d.c"->setup_alt_monster(orog, high_lvl_player);
        orog->set_short((string)squad->query_property("squad name") + " squad Orog warrior" );
        orog->move(room);
        squad->add_orog(orog);
      }
      if (random(3)){
        orog = new(MOB + "orog_berserker");
        orog->set_short((string)squad->query_property("squad name") + " squad Orog berserker" );
        orog->move(room);
        squad->add_orog(orog);
      }
      if (i <1){
        tactic  = RAM;  //only one squad at a time trying to use the RAM
      } else{
      tactic = 1 + random (3);  
      }
      squad->set_tactic(tactic);
      squad->review_tactic();
    }else {
      if (objectp(lujke)){
        tell_object(lujke, "****ERROR - FAILED TO LOAD ROOM: " + room_name + "******/n");
      }
    }
  } 
  log ("++++FINISHED CREATING SQUADS. NOW CREATING ARCHERS++++\n");
  for (i=0;i<num;i++){
    squad = new(MOB + "archer_squad" );
    squad->set_property("squad name", squad_names[l]);
    l++;
    if (l>sizeof(squad_names)){
      l=0;
    }
    switch(random(5)){
    case 0:
      room_name = TABAXROOM + "entry";
      break;
    case 1:
      room_name = TABAXROOM + "jungle26";
      break;
    case 2:
      room_name = TABAXROOM + "treetop_base3";
      break; 
    case 3: 
      room_name = TABAXROOM + "orog_entry";
      break; 
    case 4: 
      room_name = TABAXROOM + "jungle02";
      break; 
    }
    room = find_object_or_load(room_name);
    if (objectp(room)){
      squad->move(room);
      k = 4 + random (2);
      for (j=0;j<k;j++){
        orog = new(MOB + "orog_archer");
        "/daemon/alternative_world_d.c"->setup_alt_monster(orog, high_lvl_player);
        orog->move(room);
        squad->add_orog(orog);        
      }
    }else {
      if (objectp(lujke)){
        tell_object(lujke, "****ERROR - FAILED TO LOAD ROOM: " + room_name + "******/n");
      }
    }
    squad->goto_field();
    k = squad->count_orogs();
    if(objectp(lujke)){
      tell_object(lujke, "Orog archer squad number " + (i+1) + " created, containing " 
             + k + " archers and named " + squad_names[l] + " squad.");
    }
  }
  //FINISHED SETTING UP OROGS - NOW BALANCING TABAXI LEVELS
  mob_types = ({MOB + "tabaxi", MOB + "tabaxi_archer", MOB + "tabaxi_blacksmith", MOB + "tabaxi_warrior"});
    for (i=0;i<sizeof(mob_types);i++){
    tabaxi = children(mob_types[i]);
    count = sizeof(tabaxi);
    if (count>0){
      for (j=0;j<count;j++){
        original_ac = tabaxi[i]->query_level();
        original_lvl = tabaxi[i]->query_level();
        tabaxi[i]->set_property("original level", original_lvl);
        tabaxi[i]->set_property("original ac", original_ac);
        modifier = -2;
        if (i==0){
          modifier = -5;
        }
        MOB_MODIFIER_D->modify_mob(tabaxi[i], high_lvl_player, modifier); 
      }
    }
  }
}
/*
void advance_squads(){
  object * squads, room, *group, * rooms;
  int i, count, j;
  string * k, room_name, stockade, * room_names;
  mapping whos_where;
  whos_where = ([]);
  log ("^^^^^^^^^^^^^^ADVANCING squadS ^^^^^^^^^^^^^/n");
  stockade = ({TABAXROOM + "battlement1", TABAXROOM + "battlement2", 
                 TABAXROOM + "battlement3", TABAXROOM + "battlement4",
                 TABAXROOM + "battlement5", TABAXROOM + "battlement6",
                 TABAXROOM + "battlement7", TABAXROOM + "battlement8", 
                 TABAXROOM + "watchtower", TABAXROOM + "training", 
                 TABAXROOM + "centre", TABAXROOM + "east_section", 
                 TABAXROOM + "foodhall", TABAXROOM + "north_section", 
                 TABAXROOM + "northeast_corner", TABAXROOM + "southeast_corner", 
                 TABAXROOM + "south_section", TABAXROOM + "southwest_corner", 
                 TABAXROOM + "west_section", TABAXROOM + "northwest_corner" });
  squads = children(MOB + "orog_squad");
  if (sizeof(squads)>0){
    room_name = TABAXROOM + "entry";
    room_names = ({TABAXROOM + "watchtower",TABAXROOM + "battlement1",TABAXROOM + "battlement2", 
                   TABAXROOM + "battlement3", TABAXROOM + "battlement4", TABAXROOM + "battlement5", 
                   TABAXROOM + "battlement6", TABAXROOM + "battlement7", TABAXROOM + "battlement8"});
    rooms = ({});
    for (i=0;i<sizeof(room_names);i++){
      room = find_object_or_load(room_names[i]);
      if (objectp(room)){
        rooms += ({room});
      }
    }
    for (i=0;i<sizeof(squads);i++){
      if (!objectp(squads[i])|| (int)squads[i]->count_orogs()<1){
        continue;
      }
      room = environment(squads[i]);
      if (!objectp(room)){
        continue;
      }
      room_name = file_name(room);
      if (file_name(room) == TABAXOBJ + "ram_interior"){
        continue;
      }
    }
    if (member_array(room_name, stockade)!= -1){  // checks whether these orogs are already in the
      for (i=0;i<count;i++){                      // stockade
        if (objectp(squads[i])){
          squads[i]->start_walking(TABAXROOM + "granary");
        }
      }
    }
  }  else {   // If there are no orogs left, proclaim victory
    for (i=0;i<sizeof(defenders);i++){
      if (objectp(defenders[i])){
        tell_object(defenders[i], "%^B_BLUE%^%^BOLD%^%^RED%^The orogs are defeated! You have won the"
                                 +" battle!" );
        victory();
      }
    }
  }
} */



void remove_obs(object * ob){
  int i, num;
  num = sizeof(ob);
  if (num>0){
    for (i=0;i<num;i++){
      ob[0]->remove();
    }
  }
}

void remove_orogs(){
  object * orogs, * archers, * squads;
  orogs = children(MOB + "orog");
  archers = children(MOB + "orog_archers");
  squads = children(MOB + "orog_squads");
  if (sizeof(orogs)>0){
    remove_obs(orogs);
  }
  if (sizeof(archers)>0){
    remove_obs(archers);
  }
  if (sizeof(squads)>0){
    remove_obs(squads);
  }
}




string query_number(object * countables){
  switch(sizeof(countables)){
  case 0:
    return "no";
    break;
  case 1:
    return "one";
    break;
  case 2:
    return "two";
    break;
  case 3:
    return "three";
    break;
  case 4:
    return "four";
    break;
  case 5..7:
    return "several";
    break;
  case 8..12:
    return "lots of";
    break;
  default:
    return "many";
    break;
  }
}

int start_ladders(object room, object * orogs){
  int i;
  string num;
  object ladder, * rooms;
  if (sizeof(orogs)<1){
    return 0;
  }
  log ("*******STARTING LADDERS************");
  rooms = ({find_object_or_load(TABAXROOM + "watchtower") }) ;
  rooms += ({ (object)room->query_battlement() });
  num = query_number(orogs);
  tell_room(room, capitalize(num) + " orogs arrive bearing seige ladders and begin moving toward the"
             +" stockade wall" );
  for (i=0;i<sizeof(rooms);i++){
    tell_room(rooms[i], capitalize(num) + " orogs carrying seige ladders arive in the " 
        + (string)room->query_name() + " and begin moving toward the stockade fence");
  }
  for (i=0;i<sizeof(orogs);i++){
    if (!objectp(orogs[i])){
      continue;
    }
    ladder = new (TABAXOBJ + "ladder");
    ladder->move(orogs[i]);
    orogs[i]->force_me("approach fence");
  }
}

int climb_trees(object room, object * orogs){
  int i;
  string num;
  object ladder, * rooms;
  if (sizeof(orogs)<1){
    return 0;
  }
  log ("*******STARTING LADDERS************");
  rooms = ({find_object_or_load(TABAXROOM + "watchtower") }) ;
  rooms += ({ (object)room->query_battlement() });
  num = query_number(orogs);
  tell_room(room, capitalize(num) + " orogs arrive bearing seige ladders and begin moving toward the"
             +" stockade wall" );
  for (i=0;i<sizeof(rooms);i++){
    tell_room(rooms[i], capitalize(num) + " You see movement as dark shapes swarm up the trees to the north of the stockade.");
  }
  for (i=0;i<sizeof(orogs);i++){
    orogs[i]->force_me("climb tree");
  }
}
/*
void orog_volley(object room){
  string  msg;
  object * archers, watchtower, lujke;
  int i, flag;
  lujke = find_player("lujke");
  log( "****FIRING VOLLEY****");
  if (!objectp(room)||!present("orog archer", room)){
    return;
  }
  flag = 0;
  archers = all_living(room);
  if (sizeof(archers)<1){
    return;
  }
  for (i=0;i<sizeof(archers);i++){
    if (archers[i]->id("orog archer")){
      archers[i]->force_me("fire at battlement");
      flag ++;
    }
  }
  if (flag >0){
    watchtower = find_object_or_load(TABAXROOM + "watchtower");
    if (flag == 1){
      msg = "A lone Orog crossbowman launches off a shot at the battlement from ";
      msg += room->query_name();
    } else {
      msg = "A squad of " + flag + " Orog crossbowmen launch off a volley at the battlement from ";
      msg += room->query_name();
      if (objectp(watchtower)){
        tell_room(watchtower, msg);
      }
    }
  }
  call_out("orog_volley", 2 + random(4), room);
}*/



//Stages of the attack:
//Orogs arrive in the forest, at the edges of the area.
//Orogs attack in waves:
//Orog crossbowmen fire at the battlements.
//Tabaxi return fire
//Orog charge the walls
//At random points:
//Ram is wheeled in to attack
//Orogs sneak round to attack from the northern jungle
