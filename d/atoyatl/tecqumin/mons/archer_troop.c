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

#define ARROWDEATH ({ " an orog archer takes an arrow in the eye and dies",\
                      " an orog archer catches an arrow in the throat and dies", " an orog falls, under a hail of arrows",\
                      " an orog archer gets impaled by an arrow from above",\
                      " an orog archer looks shocked as an arrow ends its life",\
                      " an orog archer dies swiftly from an arrow in the groin",\
                      " an orog archer takes an arrow in the thigh and falls, arterial blood pumping from its leg",\
                      " an orog archer somersaults backwards, gurgling horribly as an arrow takes it in the throat",\
                      " an orog archer spins on the spot, then dies as an arrow takes it in the neck" })

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
      set_property("not random monster", 1);
      crashed = 0;
  	set_name("Squad of orog archers");
  	set_id(({"orog", "humanoid", "orog archer", "squad", "orog squad"}));
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

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
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
    desc = "squad of " + count_orogs() + " orog archers";
  }
  return desc;
}

string long_desc(){
  string desc;
  if (count_orogs() ==1){
    desc =     "%^GREEN%^This orog crossbowman stands just over six feet in height, with a more"
              +"  upright posture than " + QP+ " orcish cousins. " + capitalize(QS) + " has a broad,"
              +" powerful back and chest and thick, muscular limbs. " + capitalize (QP) + " face is"
              +" thoroughly orcish in origin though, with a broad snout and large, tusklike canines.";
  }
  desc = "A squad of " + count_orogs() + " orog archers. They stand just over six feet in height, with a more"
              +"  upright posture than their orcish cousins. They hav broad,"
              +" powerful backs and chests and thick, muscular limbs. Their faces are"
              +" thoroughly orcish in origin though, with broad snouts and large, tusklike canines.";
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
      tell_room(ETO, "%^BOLD%^%^RED%^An orog archer falls in battle!", TO);
      break;
    default:
      tell_room(ETO, "%^BOLD%^%^RED%^" + num_deaths + " orog archers fall in battle!", TO);
    }
  }
  return result;
}




string * query_walk_path(){
  return path;
}


void catch_tell(string str){
  object * squads, * orogs, squad, room;
  int i;
  string where;
  str = FILTERS_D->filter_colors(str);
  if (interact("out of nowhere hits you!", str)){
    force_me("tell lujke The orog has been hit!");
    if (random(6)>1){
      tell_room(ETO, ARROWDEATH[random(sizeof(ARROWDEATH))]);
      remove_orog();
      if (count_orogs()<1){
        move("/d/shadowgate/void");
        remove();
        return;
      }
    }
  }
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

int reach_destination(){
  string where;
  mapping dests;
  object * battlers,battler, ram, lujke, field, * rooms, * attackers, wood, orog;
  int i, num;
  lujke = find_player("lujke");
  where = file_name(ETO);
  switch (where){
  case TABAXROOM + "main_field": // deliberately falling through
  case TABAXROOM + "low_field": // deliberately falling through
  case TABAXROOM + "high_field":
    call_out("volley", 5);
    return 1;
    break;
  default:
    goto_field();
    break;
  }
  return 0;
}

void volley(){
  int i;
  string where;
  object bolt, bow, room, battlement;
  room = ETO;
  where = file_name(room);
  if (interact("field", where)==0){
    goto_field();
    return;
  }
  battlement= room->query_battlement();
  where=file_name(battlement);
  bolt = new ("/d/common/obj/lrweapon/hquarrels");
  bow = new("/d/common/obj/lrweapon/hcrossbow");
  bow->set_property("enchantment", 2);
  bolt->move(TO);
  bow->move(TO);
  force_me("wield bow");
  move(TABAXROOM + "archery_platform");
  ETO->add_exit( where, "upwards" );
  for (i=0;i<count_orogs()/2;i++){
    force_me("shoot at battlement");
    bow->heart_beat();
  }
  move(room);
  force_me("unwield bow");
  bow->remove();
  bolt->remove();
  tell_room(ETO, "%^RED%^The orog archers fire off a volley toward the battlement!");
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
