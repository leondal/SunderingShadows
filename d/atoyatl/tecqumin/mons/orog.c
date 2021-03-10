//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include <move.h>

#include "../tecqumin.h"
inherit MONSTER;
#define WEAPONS ({"/d/common/obj/weapon/lucern_hammer",\
                  "/d/common/obj/weapon/flail", "/d/common/obj/weapon/spear_lg",\
                  "/d/common/obj/weapon/battle_axe","/d/common/obj/weapon/large_battle_axe",\
                  "/d/common/obj/weapon/warhammer","/d/common/obj/weapon/bastard",\
                  "/d/common/obj/weapon/shortsword"})
#define ARROWDEATH ({ " takes an arrow in the eye and dies",\
                      " catches an arrow in the throat and dies", " falls, under a hail of arrows",\
                      " gets impaled by an arrow from above",\
                      " looks shocked as an arrow ends its life",\
                      " dies swiftly from an arrow in the groin",\
                      " takes an arrow in the thigh and falls, arterial blood pumping from its leg",\
                      " somersaults backwards, gurgling horribly as an arrow takes it in the throat" })

int clinging, tell_caught;
nosave int BEAT, heartcount;
string entry_method;
object clinger;

void create()
{
      object ob;
      int i;
      ::create();
      set_property("not random monster", 1);
        set_name("orog warrior");
        set_id(({"orog", "humanoid", "orog warrior"}));
        set_short( "brutal orog warrior");
      switch (random(2)){
        case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      set_long("%^GREEN%^This fearsome orog warrior has the facial features of an orc; a jutting"
                +" forehead and tusk-like %^RESET%^canine teeth%^GREEN%^, with pointed, wolflike ears"
                +" and a broad snout for a nose. It's eyes glow dully %^RED%^red%^GREEN%^ in the dark."
                +"\n%^GREEN%^Unlike an orc, however, this creature stands nearly 6 and a half feet"
                +" tall and has an olympian build, with powerful limbs, broad chest and back and a"
                +" narrow waist. " + capitalize(QS) +" looks fit, lithe and dangerous.");

        set_race("orog");
        set_body_type("humanoid");
        set_class("fighter");
        set_mlevel("fighter",53);
        set_guild_level("fighter",53);
        set_hp(random(1000)+800 + random(400));
        set_max_level(49);
        set_property("swarm",1);
        set_overall_ac(-69);
      set_size(2);
      set_attack_bonus(67);
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "shatter",
        "sunder",
        "daze",
      }));
      set_stats("strength",30);
      set_stats("intelligence",10);
      set_stats("dexterity",30);
      set_stats("charisma",6);
      set_stats("wisdom",20);
        set_size(3);
        set("aggressive",(:TO, "aggro_me":));
      set_skill("athletics", 45);
      set_skill("stealth", 45);
      set_skill("perception", 40);
        set_alignment(4);
      set_property("full attacks",1);
      ob = new(WEAPONS[random(sizeof(WEAPONS))]);
      ob->set_property("enchantment", 6);
      if (random(15)>0){
        ob->set_property("monsterweapon",1);
      }
      force_me("wield weapon");
      ob->move(TO);
      entry_method = "teleported magically right to the granary. WOW, that's magic!";
      set_funcs(({"swarm_em", "rush", "shatter", "sunder"}));
      set_func_chance(30);
      clinging = 0;
      tell_caught = 0;
      set_skill("athletics", 45);
      set_property("no random treasure", 1);
      set_new_exp(49, "normal");
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

void report(string str){
  "/daemon/reporter_d.c"->report("lujke", str);
}

void init(){
  ::init();
  if (sizeof(TO->query_wielded())<1
      && file_name(all_inventory(TO)[0])[0..20]== "/d/common/obj/weapon/"){
    force_me("wield " + all_inventory(TO)[0]->query_name());
  }
  if (objectp(ETO) && present("tabaxi", ETO)){
    force_me ("kill tabaxi");
  }
}

void aggro_me(){
  if (!TP->query_true_invis() && !TP->id("orog") && !TP->id("ram")){
    force_me("kill " + TP->query_race());
  }
}

void check_my_heart()
{
    if (heartcount>1000){
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

int query_clinging(){
  return clinging;
}

int clean_up(){return 1;}

void set_clinger(object cl){
  clinger = cl;
}

void set_clinging(int cling){
  clinging = cling;
}

void cling(object ob){
  object clinger;
  if (!objectp(ETO) || !present(ob, ETO)){
    return;
  }
  report ("Orog making a new clinger");
  clinger = new(TABAXOBJ + "clinging_orog");
  clinger->set_orog(TO);
  clinger->move(ob);
  clinger->cling(ob);
  set_clinger(clinger);
}

void reach_top(){
  object * squads, squad;
  string squadname;
  int i, num;
  squads = children("/realms/lujke/tecqumin/mons/orog_squad");
  squadname = TO->query_property("squad name");
  num = sizeof(squads);
  if (sizeof(squads)>0){
    for(i=0;i<num;i++){
      if ((string)squads[i]->query_property("squad name") == squadname){
        squad = squads[i];
        break;
      }
    }
  }
  if (!objectp(squad)){
    squad = new(MOB + "orog_squad");
    squad->set_property("squad name", squadname);
    squad->move(ETO);
  }

  if ((int)squad->check_grouped()==1){
    squad->start_walking(TABAXROOM + "granary");
    return;
  }
}


void sunder(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("sunder " + who);
}

void shatter(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("shatter " + who);
}

void rush(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("rush " + who);
}


void swarm_em(object targ){
  object * critters, * orogs, critter;
  int i;
  if (!objectp(ETO) || clinging == 1){
    return;
  }
  critters = all_living(ETO);
  if (sizeof(critters)<1){
    return;
  }
  orogs = ({});
  for (i=0;i<sizeof(critters);i++){
    critter = critters[i];
    if (objectp(critter) && (string)critter->query_race()=="orog"){
      if ((int)critter->query_clinging() == 0){
        orogs += ({critter});
      }
    }
  }
  if (sizeof(orogs)> 3){
    if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-45)){
      cling(targ);
    } else {
      tell_object(targ, "%^BOLD%^%^YELLOW%^You skip nimbly aside as an orog tries to "
                       +"grab hold of you");
      tell_room(ETO, "%^BOLD%^%^YELLOW%^" + targ->QCN + " skips nimbly aside as an orog"
                   +" tries to grab " + targ->QO, targ);
    }
  }
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

void set_entry_method(string str){
  entry_method = str;
}

string query_entry_method(){
  return entry_method;
}

string * query_walk_path(){
  return path;
}

void set_tell_caught(int i){
  tell_caught = i;
}

void catch_all(){
  int i;
  object * critters;
  critters = all_present(ETO);
  if (sizeof(critters)>1){
    for (i=0;i<sizeof(critters);i++){
      if (!critters[i]->ID("orog") || critters[i] == TO){ continue; }
      critters[i]->set_tell_caught(1);
    }
  }
}

void climb_fence(){
  if (present("ladder", ETP)){
    force_me("climb ladder");
    set_entry_method("scaled a seige ladder to get onto the battlements");
    return;
  } else {
    if (present("ladder", TP)){
      force_me("raise ladder");
      call_out("climb_fence", 3);
      return;
    }
    force_me("climb fence");
    set_entry_method("scaled the fence to get onto the battlements");
  }
  return;
}
void ram_roll(){
  catch_all();
  if((string)ETO->query_exit("out")== TABAXROOM + "main_field"){
    force_me("batter gate");
    force_me("approach gate");
    return;
  }
}

object query_squad(){
  object * squads, squad;
  int i, squad_size;
  string squad_name;
  squad_name = query_property("squad name");
  squads = children(MOB + "orog_squad");
  squad_size = sizeof(squads);
  if (squad_size>0){
    for (i=0;i<squad_size;i++){
      if ((string)squads[i]->query_property("squad name")== squad_name){
        return squads[i];
        break;
      }
    }
  }
  squad = new(MOB + "orog_squad") ;
  squad->move(ETO);
  squad->set_hp(-1);
  squad->remove_property("squad name");
  squad->set_property("squad name", squad_name);
  return squad;
}

void clamber_battlements(){
  object squad, field, * critters, critter;
  string squad_name, message;
  int i, flag;
  squad_name = query_property("squad name");
  critters = all_present("orog squad", ETO);
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      if ((string)critters[i]->query_property("squad name")== squad_name){
        squad = critters[i];
        break;
      }
    }
  }
  if (!objectp(squad)){
    force_me("tell lujke No squad with my name on it here. Making a new one");
    squad = new(MOB + "orog_squad");
    squad->move(ETO);
    squad->set_hp(-1);
    squad->remove_property("squad name");
    squad->set_property("squad name", squad_name);
  }
  squad->add_orog();
  field = ETO->query_field();
  critters = all_living(field);
  flag = 0;
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      critter = critters[i];
      if((string)critter->query_property("squad name")== squad_name){
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0){
    squad->start_walking(TABAXROOM + "granary");
    squad->set_entry_method("scaled a seige ladder to get over the fence and onto the battlements");
  }
  TO->move("/d/shadowgate/void");
  TO->remove();
}

void swing_in(){
  object squad, treetop_base, * critters, critter, squad_room;
  string squad_name, message;
  int i, flag, num, count;
  if(!objectp(ETO)){
    return;
  }
  squad_name = query_property("squad name");
  critters = children(MOB + "orog_squad");
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      if (!objectp(critters[i]) || !clonep(critters[i])){
        continue;
      }
      if ((string)critters[i]->query_property("squad name")== squad_name){
        squad = critters[i];
        break;
      }
    }
  }
  squad_room = environment(squad);
  if (!objectp(squad)){
    force_me("tell lujke %^BOLD%^%^RED%^No squad with my name on it. Making a new one");
    squad = new(MOB + "orog_squad");
    squad->move(ETO);
    squad->set_hp(-1);
    squad->remove_property("squad name");
    squad->set_property("squad name", squad_name);
    critters = children(MOB + "orog");
    critters += children(MOB + "orog_berserker");
    count = sizeof(critters);
    if(count>0){
      for (i=0;i<count;i++){
        if ((string)critter->query_property("squad name") == squad_name){
          squad->add_orog(critters[i]);
        }
      }
    }
  }
  critters =children (MOB + "orog");
  critters +=  children(MOB + "orog_berserker");
  flag = 0;
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      critter = critters[i];
      if((string)critter->query_property("squad name")== squad_name){
        flag = 1;
        force_me("tell lujke there's one of my buddies still out there. No-one left behind");
        break;
      }
    }
  }
  if (flag == 0){
    squad->move(ETO);
    squad->start_walking(TABAXROOM + "granary");
    squad->set_entry_method("swung on vines over the fence from the trees to the north to get onto the battlements");
  }
  //TO->move("/d/shadowgate/void");
  //TO->remove();
}

void bow_hit(object ob, int dam){
  if (random(8)==0){
    tell_room(ETO, query_short() + ARROWDEATH[random(sizeof(ARROWDEATH))]);
    call_out("die", 1,TO);
  } else {
    do_damage(return_target_limb(),dam);
  }
}

void die (object ob){
  object ladder, orog;
  ladder = present("ladder", TO);
  if (objectp(ladder)){
    force_me("emote drops the %^ORANGE%^seige ladder%^ORANGE%^ as " + QS + " dies.");
    ladder->move(ETO);
    orog = present("orog", ETO);
    if (orog == TO){
      orog = present("orog 2", ETO);
    }
    if (objectp("orog")){
      orog->force_me("emote grabs the ladder from " + QP + " fallen colleague.");
      orog->force_me("get ladder");
    }
  }
  ::die(ob);
}

void rejoin_squad(){
  object * critters, critter;
  string squad_name;
  int i;
  squad_name = query_property("squad name");
  critters = all_living(ETO);
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      critter = critters[i];
      if (critter->id("xxsquadxx") && (string)critter->query_property("squad name")==squad_name){
          if (!critter->is_squad_member(TO)){
            critter->add_orog(TO);
          }
          critter->receive_orog();
        force_me("emote rejoins squad");
        return;
      }
    }
  }
}

void reach_destination(){
  object wood, squad, * attackers;
  squad = present("xxsquadxx", ETO);
  if (objectp(squad)){
    if ((int)squad->is_squad_member(TO)==1){
      squad->orog_arrives(TO);
    }
  }
  switch(file_name(ETO)){
  case TABAXROOM + "granary":
    attackers = query_attackers();
    if (sizeof(attackers)>0){
      call_out("reach_destination", 9);
      return;
    }
    switch (ETO->query_burned()){
    case 1..6:
      force_me("emote retreats from the %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes");
      force_me("up");
      force_me("emote stands guard over the entrance to the granary");
      force_me("block down");
      return;
    case 7:
      return;
    }
    wood = new ("/d/common/obj/misc/wood.c");
    wood->move(TO);
    force_me("emote starts spreading out wood around the grain stores");
    set_property("posed", "spreading firewood around the grain stores");
    call_out("start_fire", 5);
    break;
  case TABAXROOM + "stockade":
    if ((string)(ETO)->query_exit("south") == "/d/shadowgate/void"){
      force_me("pull lever");
    }
    break;
  }
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
  if(!present("wood", ETO )){
    if (!present("firewood", ETO)){
      wood = new ("/d/common/obj/misc/wood.c");
      wood->move(TO);
    }
    force_me("drop wood");
  }
  force_me("light fire");
  force_me("tell lujke starting a fire");
  remove_property("posed");
  call_out("reach_destination", 2);
}

void go_to_gate(){
  string where;
  where = TABAXROOM + "stockade";
  start_walking(where);
}

void heart_beat(){
  object room;
  string where, test, * exits;
  ::heart_beat();
  if (!objectp(TO) || !objectp(ETO)){
    return;
  }
  if (random(5)>0){
    return;
  }
  room = ETO;
  if (objectp(room)){
    where = file_name(room);
    test = TABAXROOM + "treetop";
    if (where[0..strlen(test)-1] == test[0..strlen(test)-1]){ //This is to allow the orogs to recognize
      force_me("swing to south");                            // several locations they can swing from
      set_entry_method("swinging on vines over the fence from the trees to the north to get onto the battlements");
    }
    test = "northeast_corner";
    if (interact(test, where)==1)
    {
      if (sizeof(ETP->query_exits()) ==0 || member_array("down", ETP->query_exits()) ==-1 ||ETP->query_exit("down") =="/d/shadowgate/void")
      {
        force_me("say Way is blocked. Have to dig");
        force_me("dig down");
      }
    }
    test = "east_section";
    if (interact(test, where)==1)
    {
      if (sizeof(ETP->query_exits()) ==0 || member_array("north", ETP->query_exits()) ==-1 ||ETP->query_exit("north") =="/d/shadowgate/void")
      {
        force_me("say Way is blocked. Have to dig");
        force_me("dig north");
      }
    }
    test = "north_section";
    if (interact(test, where)==1)
    {
      if (sizeof(ETP->query_exits()) ==0 || member_array("east", ETP->query_exits()) ==-1 ||ETP->query_exit("east") =="/d/shadowgate/void")
      {
        force_me("say Way is blocked. Have to dig");
        force_me("dig east");
      }
    }


    if (present("player", room)){
      heartcount = 0;
    }
  }
  if (clinging)
  {
    if (!objectp(clinger)) clinging = 0;
    clinger->shake_off();
  }
}
