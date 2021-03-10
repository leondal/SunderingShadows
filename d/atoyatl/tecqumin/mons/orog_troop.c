//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include <move.h>

#include "../tecqumin.h"

#define WAIT 0
#define SWING 1
#define RAM 2
#define LADDER 3
#define STOPPED 4
#define ARCHERY 5
#define WALK_IN 6

inherit MONSTER;
#define WEAPONS ({"/d/common/obj/weapon/lucern_hammer",\
                  "/d/common/obj/weapon/flail", "/d/common/obj/weapon/spear_lg",\
                  "/d/common/obj/weapon/battle_axe","/d/common/obj/weapon/large_battle_axe",\
                  "/d/common/obj/weapon/warhammer","/d/common/obj/weapon/bastard",\
                  "/d/common/obj/weapon/shortsword"})
#define ARROWDEATH ({ " an orog takes an arrow in the eye and dies",\
                      " an orog catches an arrow in the throat and dies", " an orog falls, under a hail of arrows",\
                      " an orog gets impaled by an arrow from above",\
                      " an orog looks shocked as an arrow ends its life",\
                      " an orog dies swiftly from an arrow in the groin",\
                      " an orog takes an arrow in the thigh and falls, arterial blood pumping from its leg",\
                      " an orog somersaults backwards, gurgling horribly as an arrow takes it in the throat" })

int tactic, flag;
int crashed, climbing;
nosave int BEAT, heartcount;
string entry_method;

void remove_orog();
void review_tactic();
string query_number(int num);
void climb_ladder();

void create()
{
      object ob;
      int i;
      ::create();
      crashed = 0;
      set_property("not random monster", 1);
        set_name("Troop of orogs");
        set_id(({"orog", "humanoid", "orog warrior", "squad", "orog squad"}));
        set_short( (:TO, "short_desc" :) );
      switch (random(2)){
        case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      set_long((: TO, "long_desc" :) );
        set_race("orog");
        set_body_type("humanoid");
        set_hd(35,12);
        set_size(3);
        set("aggressive",25);
        set_class("fighter");
        set_mlevel("fighter",27);
        set_level(27);
        set_guild_level("fighter",27);
        set_class("thief");
        set_mlevel("thief",27);
        set_guild_level("thief",27);
      set_thief_skill("climb walls", 95);
        set_max_hp((random(30)+200)*20);
        set_hp(query_max_hp());
        set_exp(11000);
        set_max_level(27);
        set_property("swarm",1);
        set_overall_ac(-22);
        set_alignment(4);
      set_property("full attacks",1);
      entry_method = "teleported magically right to the granary. WOW, that's magic!";
      set_property("troop name", "no name set");
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

init(){
  ::init();
  if (objectp(ETO) && present("tabaxi", ETO)){
    force_me ("kill tabaxi");
  }
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

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

int set_tactic(int tac){
  tactic = tac;
}

int query_climbing(){
  return climbing;
}

int count_orogs(){
  int num;
  num = 1 + (query_hp()*7)/query_max_hp();
  return num;
}

string short_desc(){
  string desc;
  if (count_orogs()==1){
    desc = "A massive orog warrior";
  } else {
    desc = "troop of " + count_orogs() + " orog warriors";
  }
  return desc;
}

string long_desc(){
  string desc;
  if (count_orogs() ==1){
    desc =       "A massive orog warrior. It has the facial features of an orc; a jutting"
                +" forehead and tusk-like %^RESET%^canine teeth%^GREEN%^, with pointed, wolflike ears"
                +" and a broad snout for a nose. It's eyes glow dully %^RED%^red%^GREEN%^ in the dark."
                +"\n%^GREEN%^Unlike an orc, however, this creature stands nearly 6 and a half feet"
                +" tall and has an olympian build, with powerful limbs, broad chest and back and a"
                +" narrow waist. It looks fit, lithe and dangerous.";
  }
  desc = "A squad of " + count_orogs() + " orog warriors. They have facial features of orcs;"
                +" jutting foreheads and tusk-like %^RESET%^canine teeth%^GREEN%^, with pointed, "
                +"wolflike ears and broad snouts for a noses. Their eyes glow dully %^RED%^red%^GREEN%^"
                +" in the dark."
                +"\n%^GREEN%^Unlike orcs, however, these creatures stand nearly 6 and a half feet"
                +" tall and haven olympian build, with powerful limbs, broad chests and backs and"
                +" narrow waists. They look fit, lithe and dangerous.";
  return desc;
}

int move(mixed dest){
  // this should stop these mobs being cleaned up by the cleanup daemon
  int result;
  object room;
  result = ::move(dest);
  if (result == MOVE_OK) {
    room = ETO;
    if (room->query_had_players()<1){
      room->set_had_players(2);
    }
  }
  return result;
}

int do_damage(string limb, int damage){
  int result, num_alive, num_deaths;
  num_deaths = 1 + (query_hp()*20)/query_max_hp();
  result = ::do_damage(limb, damage);
  num_alive = 1 + (query_hp()*20)/query_max_hp();
  num_deaths = num_deaths - num_alive;
  if (objectp(ETO)){
    switch(num_deaths){
    case 0:
      break;
    case 1:
      tell_room(ETO, "%^BOLD%^%^RED%^An orog falls in battle!", TO);
      break;
    default:
      tell_room(ETO, "%^BOLD%^%^RED%^" + num_deaths + " orogs fall in battle!", TO);
    }
  }
  return result;
}


void set_entry_method(string str){
  entry_method = str;
}

string query_entry_method(){
  return entry_method;
}

string * query_walk_path(){
  return path;
}


void set_crashed(int i){
  crashed = 1;
}

void ram_roll(){
  if((string)ETO->query_exit("out")== TABAXROOM + "main_field"){
    force_me("batter gate");
    force_me("approach gate");
    return;
  }
}


void crash_recover(){
  int i;
  object * critters;
  critters = all_present(ETO);
  if (sizeof(critters)>1){
    for (i=0;i<sizeof(critters);i++){
      if (!critters[i]->ID("orog") || critters[i] == TO){ continue; }
      critters[i]->set_tell_caught(1);
      critters[i]->set_crashed(0);
    }
  }
}

int split(int num){
  object troop;
  int new_hp;
  if (count_orogs()<num){
    num = count_orogs()-1;
  }
  if (num<1){
    return 0;
  }
  troop = new(MOB + "orog_troop");
  new_hp = (int)troop->query_max_hp()/20;
  new_hp = new_hp*num;
  set_hp(query_hp()-new_hp);
  troop->set_hp(new_hp);
  troop->move(ETO);
}

combine(object orogs){
  int additional_hp;
  additional_hp = orogs->query_hp();
  set_hp(query_hp() + additional_hp);
  orogs->remove();
}

int start_ladders(object room){
  int i;
  string num;
  object ladder, * rooms;
  if (count_orogs()<1){
    return 0;
  }
  log ("*******STARTING LADDERS************");
  rooms = ({find_object_or_load(TABAXROOM + "watchtower") }) ;
  rooms += ({ (object)room->query_battlement() });
  num = query_number(count_orogs());
  tell_room(room, capitalize(num) + " orogs arrive bearing seige ladders and begin moving toward the"
             +" stockade wall" );
  for (i=0;i<sizeof(rooms);i++){
    tell_room(rooms[i], capitalize(num) + " orogs carrying seige ladders arive in the "
        + (string)room->query_name() + " and begin moving toward the stockade fence");
  }
  ladder = new (TABAXOBJ + "ladder");
  ladder->move(TO);
  force_me("approach fence");
}



void start_fire(){
  object wood, * attackers;
  int i;
  if (file_name(ETO) != TABAXROOM + "granary"){
    start_walking(TABAXROOM + "granary");
    return;
  }
  attackers = query_attackers();
  if (sizeof(attackers)>0){
    i = random(sizeof(attackers));
    force_me("emote tries to get to the firewood to start a fire, but can't get"
            +" past" + attackers[i]->QCN);
    call_out("start_fire", 3 + random(4));
  }
  if(!present("wood", ETO )&& !present("firewood", ETO)){
    wood = new ("/d/common/obj/misc/wood.c");
    wood->move(TO);
    force_me("drop wood");
  }
  force_me("light fire");
//  force_me("tell lujke starting a fire");
  remove_property("posed");
  call_out("go_to_gate", 2);
}

void go_to_gate(){
  string where;
  where = TABAXROOM + "stockade";
  start_walking(where);
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
  if (sizeof(dests)>0){
    DESTINATIONS_D->remove_destination(field_name);
  }
  DESTINATIONS_D->generate_waystations(field_name,3, 4);
  if (is_walking>0){
    return;
  }
  start_walking(field_name);
  return;
}

void review_tactic(){
  int i, flag;
  string room;
  object * rams, * battlers, ram, newenv, field;
  mapping dests;
  if (!objectp(ETO)){
    return;
  }
  field = find_object_or_load(TABAXROOM + "main_field");
  if (objectp(field)){
    if ((string)field->query_exit("north") == TABAXROOM + "stockade"){
      tactic = WALK_IN;
      start_walking(TABAXROOM + "granary");
      return;
    }
  }
  switch(tactic){
  case WAIT:
    if (random(4) <3){
      return;
    } else {
      set_tactic(random(4));
      return;
    } // deliberately falling through
  case SWING:
    dests = DESTINATIONS_D->query_waystations(TABAXROOM + "treetop_base1");
    if (sizeof(dests)>0){
      DESTINATIONS_D->remove_destination(TABAXROOM + "treetop_base1");
    }
    DESTINATIONS_D->generate_waystations(TABAXROOM + "treetop_base1",4, 4);
    start_walking(TABAXROOM + "treetop_base1");
    break;
  case LADDER:
    if (!objectp(ETO)||sizeof(count_orogs())<1){
      remove();
      break;
    }
    goto_field();
    break;
  case RAM:
    if (objectp(ETO) && present("ram", ETO)){
      force_me("enter ram");
    }
    if (file_name(ETO) == TABAXOBJ + "ram_interior"){
      if (objectp(EETO) && file_name(EETO) == TABAXROOM + "main_field"){
        force_me("batter gate");
        return;
      }
      ram = (object)ETO->query_ram();
      if (!objectp(ram)){
      //  if ((int)ETO->reset_ram()<1){
          tell_room(ETO, "There's been a technical error with the ram. Please tell a wiz, or make a"
                        +" bug report, quoting 'orog squad error number 1337: Lujke is an idiot'");
          return;
      //  }
      }
      if ((int)ram->query_walking()<1){
        dests = DESTINATIONS_D->query_waystations(TABAXROOM + "main_field");
        if (sizeof(dests)>0){
          DESTINATIONS_D->remove_destination(TABAXROOM + "main_field");
        }
        DESTINATIONS_D->generate_waystations(TABAXROOM + "main_field",4, 4);
        ram->start_walking(TABAXROOM + "main_field");
        return;
      }
    }
    rams = children(MOB + "ram_mob");
    flag = -1;
    if (sizeof(rams)>1){
      for (i=0;i<sizeof(rams);i++){
        if (objectp(rams[i])){
          if (rams[i]->query_hp()>1 && objectp(environment(rams[i]))){
            flag = i;
          }
        }
      }
    }
    if (flag <0 || !objectp(environment(rams[flag]))){
      broadcast_area(TABAXROOM,"%^BOLD%^%^RED%^A howl of %^GREEN%^anguish%^RED%^ rises through the"
                    +"
%^RESET%^%^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l"
                    +"%^RESET%^%^GREEN%^e as the %^BOLD%^%^BLACK%^orogs %^RED%^realise their"
                    +" %^RESET%^%^ORANGE%^battering ram %^BOLD%^%^RED%^is broken!");
      switch(random(3)){
      case 0:
        tactic = SWING;
         break;
      case 1:
        tactic = WAIT;
        break;
      case 2:
        tactic = LADDER;
        break;
      }
      return;
    }
    room = file_name(environment(rams[flag]));
    dests = DESTINATIONS_D->query_waystations(room);
    if (sizeof(dests)>0){
      DESTINATIONS_D->remove_destination(room);
    }
    DESTINATIONS_D->generate_waystations(room,4, 4);
    start_walking(room);
    break;
  case STOPPED:
    return;
  case ARCHERY:
    room = file_name(ETO);
    if (room == TABAXROOM + "high_field" || room == TABAXROOM + "main_field"
                                         || room == TABAXROOM + "low_field"){
      if (random(3)>0){
        battlers = children(TABAXOBJ + "tabaxi_battler");
        if (sizeof(battlers)>0){
          for (i=0;i<sizeof(battlers);i++){
            if (objectp(battlers[i])){
              battlers[i]->orog_volley(ETO);
//              ::force_me("tell lujke %^BOLD%^%^YELLOW%^Firing a blooming volley!");
              break;
            }
          }
        }
      }
    } else {
      goto_field();
    }
    break;
  case WALK_IN:
    if (!query_walking()){
      start_walking(TABAXROOM + "granary");
    }
  default:
    tactic = random(4);
  }
}

string query_number(int num){
  switch(num){
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

void climb_tree(){
  object orog, ladder;
  string troop_name;
  remove_orog();
  orog = new(MOB + "orog");
  orog->move(ETO);
  troop_name = query_property("troop name");
  orog->set_property("troop name", troop_name);
  orog->force_me("climb tree");
  switch(count_orogs()){
  case 0:
    tell_room(ETO, "The last orog of the troop sets off up a ladder");
    remove();
    return;
    break;
  default:
    tell_room(ETO, "An orog breaks off from the troop and sets off up a tree");
  }
  call_out("climb_tree", 2+ random (2));
}


int reach_destination(){
  string where;
  mapping dests;
  object * battlers,battler, ram, lujke, field, * rooms, * attackers, wood, orog;
  int i, num;
//  lujke = find_player("lujke");
  where = file_name(ETO);
  switch (where){
  case TABAXROOM + "treetop_base1":
    if (tactic == SWING){
      switch(random(3)){
      case 0:
        break;
      case 1:
        force_me("west");
        break;
      case 2:
        force_me("emote breaks into a run");
        force_me("west");
        force_me("west");
      break;
      }
//      ::force_me("tell lujke Starting tree climbing and swinging");
      climb_tree();
      return 1;
      break;
    }
    break;
  case TABAXROOM + "treetop_base2":
  case TABAXROOM + "treetop_base3":
    climb_tree();
    break;
  case TABAXROOM + "granary":
    attackers = query_attackers();
    if (sizeof(attackers)>0){
      call_out("reach_destination", 9);
      return 1;
    }
    wood = new ("/d/common/obj/misc/wood.c");
    wood->move(ETO);
    force_me("emote quickly starts spreading out wood around the grain stores");
    set_property("posed", "spreading firewood around the grain stores");
    call_out("start_fire", 5);
    break;
  case TABAXROOM + "stockade":
    force_me("pull lever");
    break;
  case TABAXROOM + "main_field": // deliberately falling through
  case TABAXROOM + "low_field": // deliberately falling through
  case TABAXROOM + "high_field":
    if ((string)ETO->query_exit("north")== TABAXROOM + "stockade"){
      set_entry_method("Walking right in through the open gate.");
      start_walking(TABAXROOM + "granary");
      break;
    }
    if (tactic == LADDER){
      force_me("approach_fence");
    } else {
//      ::force_me("tell lujke arrived at a field, but the tactic was NOT ladders");
    }
    return 1;
    break;
  }
//  ::force_me("tell lujke %^BOLD%^%^YELLOW%^Checking to see whether a"
//                 +" ram is present at %^RESET%^" + ETO->query_name());
  ram = present("ram", ETO);
  if (objectp(ram)){
//    ::force_me("tell lujke Ram present. Checking whether there are"
//                        +" orogs available");
    if (count_orogs()>0){
      field = find_object_or_load(TABAXROOM + "main_field");
//      ::force_me("tell lujke Orogs present. Entering Ram");
      force_me("enter ram");
      review_tactic();
      return 1;
    }
  }
  return 0;
}

void remove_orog(){
  set_hp(query_hp() - query_max_hp()/7);
}

void add_orog(){
  set_hp(query_hp() + query_max_hp()/7);
}

void transfer_orog(object other_troop){
  if (!objectp(other_troop)){
    return;
  }
  other_troop->add_orog();
  remove_orog();
}

void climb_ladder(){
  object orog, ladder;
  string troop_name;
  if ((int)ETO->query_position(TO) < 10){
    force_me("approach fence");
    return;
  }
  orog = new(MOB + "orog");
  orog->move(ETO);
  troop_name = query_property("troop name");
  orog->remove_property("troop name");
  orog->set_property("troop name", troop_name);
  ETO->set_position(orog, 10);
  remove_orog();
  if (!present("ladder", ETO)){
    ladder = new (TABAXOBJ + "ladder");
    ladder->move(orog);
    orog->force_me("raise ladder");
  }
  orog->force_me("climb ladder");
  switch(count_orogs()){
  case 0:
    tell_room(ETO, "The last orog of the troop sets off up a ladder");
    remove();

    break;
  default:
    tell_room(ETO, "An orog breaks off from the troop and sets off up a ladder");
  }
  call_out("climb_ladder", 3+ random (4));
}
