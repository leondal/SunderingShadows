//Coded by Lujke
#define SURFACE_AREA 1000
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
#define DEST "/daemon/destinations_d.c"
#define MELEE 1
#define RANGED 2
#define TARGETSPELL 3
#define AREASPELL 4
#define DEST "/daemon/destinations_d.c"
inherit WEAPONLESS;

object relay_room, * clones;
int * tentacle_hps, empress_moves, spirits_absorbed, countdown, invincible, last_summoned;
mapping targeters, seized, exits_used, victory;
string * destinations_visited, *path_trod;
int mucus, frozen_mucus, skin, tentacles_withdrawn, relaying, power_absorbed, last_move, absorbing, reporting;
nosave int BEAT, heartcount;

void grant_quest(object slayer, string quest, int exp, string explanation, int must_be_near);
void distribute_attacks();
void set_master(object m);
object query_master();
void add_clone(object clone);
object * query_clones();
object * query_all_attackers();
void set_clones(object * cl);
void throw();
void throw2();
string slime_desc();
string skin_desc();
int target_limb(string str);
string query_seizing_tentacle_name(object seizee);


void create(){
    object rent;
    ::create();
//    set_name("genericmob");
//    set_id(({"mob"}));
//    set_short("a generic mob");
//    set_long("It's just a mob");
      exits_used = ([]);
    invincible = 1;
    path_trod = ({});
    countdown = 0;
    empress_moves = 0;
    power_absorbed = 0;
    set_name("unfettered");
    set_id(({ "unfettered"}));
    set_short("%^BLUE%^The %^RESET%^%^MAGENTA%^Un%^BLUE%^f"
        +"%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^"
        +"ed");
    set_long( (:TO, "long_desc":) );
    set_gender("neuter");
    set_race("outsider");
    set_body_type("humanoid");
    set_hd(55,2);
    set_level(65);
    set_class("psion");
    set_mlevel("psion", 65);
    set_hp(14000);
    tentacle_hps = ({1000,1000,1000,1000,1000,1000,1000});
    seized = ([]);
    spirits_absorbed = 0;
    set_new_exp("boss", 70);
    set_property("swarm", 1);
    set_property("cast and attack",1);
    set_stats("strength", 30);
    set_stats("dexterity",18);
    set_stats("intelligence",28);
    set_stats("wisdom",30);
    set_stats("constitution",30);
    set_stats("charisma",30);
    set_attacks_num(8);
    set_property("no disarm", 1);
    set_property("no hold", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_property("full attacks", 1);
    set_property("no crit", 1);
    set_property("no tripped", 1);
    set_overall_ac(-220);
    add_attack_bonus(85);
    set_overall_ac(-95);
    destinations_visited = ({});
    set_emotes(2,({
           "%^GREEN%^A bubble of foul smelling gas bursts from the"
           +" %^BOLD%^%^GREEN%^slime%^RESET%^%^GREEN%^ on the"
           +" surface of the elder god",

           "%^MAGENTA%^A giant %^RED%^maw%^MAGENTA%^ opens up in the"
          +" body of the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
          +"%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^MAGENTA%^."
          +" Jagged fangs are clearly visible"
          +" for a few moments before it closes again and vanishes"
          +" beneath the %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^l%^BOLD%^"
          +"%^GREEN%^im%^RESET%^%^GREEN%^e%^MAGENTA%^."
    }),0);
    set_damage(8,4);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 10);
    set_size(4);
    set_base_damage_type("bludgeoning");
    set_fake_limbs(({"torso", "first tentacle", "second tentacle",
      "third tentacle", "fourth tentacle", "fifth tentacle",
      "sixth tentacle", "seventh tentacle", "maw", "bloodshot eye"}));
    set_attack_limbs( ({ "maw","first tentacle", "second tentacle",
      "third tentacle", "fourth tentacle", "fifth tentacle",
      "sixth tentacle", "seventh tentacle" }) );
    set("aggressive", 0);
    set_overall_ac(69);
    set_alignment(4);
    set_funcs(({"throw", "throw", "tent_monster", "sweep", "sweep", "sweep", }));
    set_func_chance(30);
    set_emotes(10,({

    }),1);
    set_spells( ({"microcosm","ultrablast", "true metabolism",
                                                      "hostile empathic transfer" }) );
    set_spell_chance(30);
    set_attacks_num(7);
    mucus = SURFACE_AREA;
    frozen_mucus = 0;
    tentacles_withdrawn = 0;
    skin = SURFACE_AREA;
    set_property("vacuum breather", 1);
    set_property("resist vacuum", 1);
    rent = new(OBJ + "void");
    rent->move(ETO);
    relaying = 0;
    clones = ({});
    targeters = ([]);
    paralyze("There's nothing you can do for now; wait until you can act!");
    last_move = 0;
    BEAT = 0;
    heartcount = 0;
    last_summoned = 0;
    victory = 0;
    reporting = 0;
    check_my_heart();
}

void set_reporting(int r){
  reporting = r;
}

int query_reporting(){
  return reporting;
}

void init(){
  ::init();
  add_action("target_limb", "target");
  distribute_attacks();
}

int target_limb(string str){
  string * limbs, name, targeters_names, target;
  if (!stringp(str)){
    return notify_fail("Do you want to <target>"
      +" a particular part of the creature? Maybe its"
      +" <tentacles>, <eyes>, or"
      +" <maw>?");
  }
  target = "none";
  if (str == "maw"){
    tell_object(TP, "You focus your attacks on the creature's"
      +" %^BOLD%^%^RED%^m%^MAGENTA%^a%^RED%^w");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's %^BOLD%^%^RED%^m%^MAGENTA%^a%^RED%^w", TP);
    target = "maw";
  }
  if (str == "eye" || str == "eyes"){
    tell_object(TP, "You focus your attacks on the creature's"
      +" %^BOLD%^%^WHITE%^e%^BLUE%^y%^RED%^e%^WHITE%^s");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's %^BOLD%^%^WHITE%^e%^BLUE%^y%^RED%^e%^WHITE%^s", TP);
    target = "eye";
  }
  if (str == "first tentacle" || str == "1st tentacle" || str == "tentacle 1"){
    tell_object(TP, "You focus your attacks on the creature's first"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's first %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);
    target = "first tentacle";
  }
  if (str == "second tentacle" || str == "2nd tentacle" || str == "tentacle 2"){
    target = "second tentacle";
    tell_object(TP, "You focus your attacks on the creature's second"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's second %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);

  }
  if (str == "third tentacle" || str == "3rd tentacle" || str == "tentacle 3"){
    tell_object(TP, "You focus your attacks on the creature's third"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's third %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);

    target = "third tentacle";
  }
  if (str == "fourth tentacle" || str == "4th tentacle" || str == "tentacle 4"){
    tell_object(TP, "You focus your attacks on the creature's fourth"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's fourth %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);

    target = "fourth tentacle";
  }
  if (str == "fifth tentacle" || str == "5th tentacle" || str == "tentacle 5"){
    tell_object(TP, "You focus your attacks on the creature's fifth"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's fifth %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);

    target = "fifth tentacle";
  }
  if (str == "sixth tentacle" || str == "6th tentacle" || str == "tentacle 6"){
    tell_object(TP, "You focus your attacks on the creature's sixth"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's sixth %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);
    target = "sixth tentacle";
  }
  if (str == "seventh tentacle" || str == "7th tentacle" || str == "tentacle 7"){
    tell_object(TP, "You focus your attacks on the creature's seventh"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cle");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's seventh %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cle", TP);
    target = "seventh tentacle";
  }
  if (str == "tentacle" || str == "tentacles"
                 || (target == "none" && interact ("tentacle", str))){
    tell_object(TP, "You focus your attacks on the creature's"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^BLUE%^a%^BOLD%^%^BLACK%^cles");
    tell_room(ETO, TPQCN + " focusses " + TP->QP + " attacks on the"
      +" creature's %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
      +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cles", TP);
    target = "tentacle";
  }
  if (target == "none"){
    return notify_fail("Do you want to %^BOLD%^%^YELLOW%^target"
      +" %^RESET%^a particular part of the creature? Maybe its"
      +" %^YELLOW%^tentacles%^RESET%^, %^YELLOW%^eyes%^RESET%^, or"
      +" %^YELLOW%^maw%^RESET%^?");
  }
  targeters_names = keys(targeters);
  name = TP->query_name();
  if (member_array(name, targeters_names)!=-1){
    map_delete(targeters, name);
  }
  targeters += ([name: target]);
  return 1;
}

void summon_help(){
  object * critters, room, critter;
  string * mob_names;
  int * killed_mob, i, count;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  mob_names = ({"taluc", "epithon", "guamansuri", "empress"});
  for (i=0;i<count;i++)
  {
    killed_mob[i] = EVENT_RECORDS_D->has_anyone_here_killed(ETO, MOB + mob_names[i], 2400*10*7);
    if (present(mob_names[i], ETO)) continue;
    if (!killed_mob[i])
    {
      critter = find_object_or_load(MOB + mob_names[i]);
      if (!objectp(critter)) continue;
      room = environment(critter);
      if (objectp(room))
      {
        tell_room(room, critter->QCN + "%^RESET%^ looks around in sudden alarm, and vanishes");
        critter->move(ETO);
        tell_room(ETO, critter->QCN + " %^BOLD%^%^CYAN%^appears in a %^BOLD%^%^WHITE%^flash");
        critters[i]->join_unfettered_battle();
      }
    }
  }
}

mapping query_targeters(){
  return targeters;
}

int * query_seized_numbers(object ob){
  object * seizees;
  seizees = keys (query_seized());
  if (member_array(ob, seizees)==-1){
    return -1;
  }
  return query_seized()[ob];
}

void seize2(object targ){
  string * save_msgs, * save_verbs;
  int evasion_roll;
  if (!objectp(targ) || !objectp(ETO) || !present(targ, ETO)){
    return;
  }
  save_verbs = ({"%^BOLD%^%^YELLOW%^d%^RESET%^%^ORANGE%^i%^BOLD%^"
    +"%^YELLOW%^ve", "%^BOLD%^%^CYAN%^ex%^RESET%^%^CYAN%^e%^BOLD%^"
    +"c%^RESET%^%^CYAN%^u%^BOLD%^te", "%^BOLD%^%^BLUE%^t%^RESET%^"
    +"%^BLUE%^u%^BOLD%^mb%^RESET%^%^BLUE%^l%^BOLD%^e", "%^BOLD%^"
    +"%^GREEN%^d%^RESET%^%^GREEN%^o%^BOLD%^dg%^RESET%^%^GREEN%^e"
    +"%^BOLD%^", "%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^u%^BOLD%^"
    +"%^BLACK%^ck"});
  save_msgs = ({" %^RESET%^to one side of",
     " %^RESET%^a clever %^BOLD%^%^CYAN%^sh%^RESET%^%^CYAN%^i"
        +"%^BOLD%^mm%^RESET%^%^CYAN%^y%^RESET%^ to evade",
     " %^RESET%^out the way of", " %^RESET%^away from",
     " %^RESET%^underneath"});
  if(targ->reflex_save(45)){
    evasion_roll = random(sizeof(save_verbs));
    tell_object(targ, "You " + save_verbs[evasion_roll]
      + save_msgs[evasion_roll] + " the %^BOLD%^%^BLACK%^t"
      +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
      +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s%^RESET%^ grasp!");
    tell_room(ETO, targ->QCN + " " + save_verbs[evasion_roll] + "s"
      + save_msgs[evasion_roll] + " the %^BOLD%^%^BLACK%^t"
      +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
      +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s%^RESET%^ grasp!"
        , targ);
  } else {
    actually_seize(targ);
  }
}

void actually_seize(object targ){
  tell_object(targ, "The %^BOLD%^%^BLACK%^t"
    +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
    +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s%^RESET%^ seizes"
    +" you and lifts you up high!");
  tell_room(ETO, "The %^BOLD%^%^BLACK%^t"
    +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
    +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s%^RESET%^ seizes "
    + targ->QCN + " and lifts " + targ->QO + " up high!");
  targ->set_paralyzed(60, "You're in the grip of a hideous"
    +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
    +"%^BLUE%^a%^BOLD%^%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^!", targ);
  add_seized(targ);
}

void release_seized(object seizee){
  really_release_seized(seizee);
}

void really_release_seized(object seizee){
  object * seizees;
  if (!objectp(seizee)){
    return;
  }
  tell_room(ETO, "Really releasing " + seizee->QCN);
  seizees = keys (query_seized());
  if (sizeof(seizees)<1 || member_array(seizee, seizees)== -1){
    return;
  }
  m_delete(seized, seizee);
  seizee->remove_property("posed");
  seizee->remove_paralyzed();
}

string query_tentacle_name(int tentacle){
  string tentacle_name;
  switch(tentacle){
  case 1:
    tentacle_name = "first tentacle";
    break;
  case 2:
    tentacle_name = "second tentacle";
    break;
  case 3:
    tentacle_name = "third tentacle";
    break;
  case 4:
    tentacle_name = "fourth tentacle";
    break;
  case 5:
    tentacle_name = "fifth tentacle";
    break;
  case 6:
    tentacle_name = "sixth tentacle";
    break;
  case 7:
    tentacle_name = "seventh tentacle";
    break;
  }
  return tentacle_name;
}

void add_seized(object seizee){
  really_add_seized(seizee);
}

void really_add_seized(object seizee){
  object * seizees;
  string tentacle_name;
  int when, tentacle, * free_tentacles, used_tentacles, i,* res;
  if (!objectp(seizee)){
    return;
  }
  seizees = keys (query_seized());
  if (sizeof(seizees)>6 || (member_array(seizee, seizees)!= -1)){
    return;
  }
  free_tentacles = ({1,2,3,4,5,6,7});
  if (sizeof(seizees)>0){
    for (i=0;i<sizeof(seizees);i++){
      res = query_seized()[seizees[i]];
      tentacle = res[1];
      if (sizeof(free_tentacles)>0 && member_array(tentacle, used_tentacles)!=-1){
        free_tentacles -= ({tentacle});
      }
    }
  }
  tentacle = free_tentacles[random(sizeof(free_tentacles))];
  tentacle_name = query_tentacle_name(tentacle);
  when = time() + 20 + random(40);
  seized[seizee] = ({when, tentacle});
  seizee->set_property("posed", "In the grip of the %^BLUE%^U%^MAGENTA%^"
    +"nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d's"
    +" %^RESET%^" + tentacle_name );
}

string query_seizing_tentacle_name(object seizee){
  object * seizees;
  int * res, tent_num;
  seizees = keys(query_seized());
  if (sizeof(seizees)<1 || member_array(seizee, seizees)==-1){
    return "none";
  }
  res = query_seized()[seizee];
  tent_num = res[1];
  return query_tentacle_name(tent_num);
}

void remove_seized(object seizee){
  object * seizees;
  if (!objectp(seizee)){
    return;
  }
  seizees = keys (query_seized());
  if (sizeof(seizees)<1 ||(member_array(seizee, seizees)== -1)){
    return;
  }
  m_delete(seized, seizee);
}

void seize(object targ){
  if (!objectp(targ) || !objectp(ETO) || !present(targ, ETO)){
    return;
  }
  tell_object(targ, "One of the %^BLUE%^flailing %^BOLD%^%^BLACK%^t"
    +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
    +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^ sweeps down"
    +" to grab at you.");
  tell_room(ETO, "One of the %^BLUE%^flailing %^BOLD%^%^BLACK%^t"
    +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
    +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^ sweeps down"
    +" to grab at " + targ->QCN, targ);
  call_out("seize2", 1, targ);
}

mapping query_all_seized(){
  return seized;
}

void add_clone(object clone){
  clones += ({clone});
}

object * query_clones(){
  return clones;
}

void set_clones(object * cl){
  clones = cl;
}

void really_cause_typed_damage(object victim,string limb,int damage,string damage_type){
  ::cause_typed_damage(victim, limb, damage, damage_type);
}

void set_skin(int sk){
  skin = sk;
}

void set_mucus(int m){
  mucus = m;
}

void set_frozen(int f){
  frozen_mucus = f;
}

void relay_typed_damage(object victim,string limb, int damage,string damage_type, object origin_room){
  if (objectp(origin_room)){
    relaying = 1;
    relay_room = origin_room;
    tell_room(relay_room, "This room successfully set as relay room. About to cause damage.");
  }
  cause_typed_damage(victim, limb, damage, damage_type);
  tell_room(ETO, "The %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt"
    +"%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d%^RESET%^ takes damage"
    +" from elsewhere!");
}

object * query_unseized_attackers(){
  object * critters;
  critters = query_attackers();
  if (sizeof(seized)>0){
    critters = critters - seized;
  }
  if (sizeof(critters)<1){
    return ({});
  }
  return critters;
}

object * filter_for_pcs(object * obs){
  int i, count;
  object * res;
  count = sizeof(obs);
  if (count<1){
    return ({});
  }
  res = ({});
  for (i=0;i<count;i++){
    if (interactive(obs[i])&& !obs[i]->query_true_invs()){
      res += ({obs[i]});
    }
  }
  return res;
}

object * query_pcs_outside_rift(){
  object * critters, room;
  string room_name;
  room = find_object_or_load(TECVOID + "inner_void0");
  room_name = room->query_exit("out");
  if (room_name == "/d/shadowgate/void"){
    return ({});
  }
  room = find_object_or_load(room_name);
  if (!objectp(room)){
    return ({});
  }
  critters = all_living(room);
  critters = filter_for_pcs(critters);
  return critters;
}

void withdraw_tentacles(){
  object start_room, unfettered, rift, destination;
  string rm_name;
  int i;
  if ( tentacles_withdrawn == 1 || !objectp(ETO)
           || file_name(ETO)!= TECVOID + "inner_void0" ){
    return;
  }
  start_room = find_object_or_load(ETO->query_exit("out"));
  if (objectp(start_room)){
    tell_room(start_room, "The %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^"
      +"ntacl%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^ jerk in apparent%^RED%^"
      +" pain%^RESET%^, and release their grip on the edges of the"
      +" %^BOLD%^%^BLACK%^rift%^RESET%^ before withdrawing into the"
      +" %^BLUE%^void%^RESET%^.");
    tell_void("%^BLUE%^The %^RESET%^%^MAGENTA%^Un%^BLUE%^f"
      +"%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed%^RESET%^"
      +" jerks in %^RED%^pain%^RESET%^ and pulls its %^BOLD%^%^BLACK%^t"
      +"%^RESET%^e%^BOLD%^%^BLACK%^ntacl%^RESET%^e%^BOLD%^%^BLACK%^s"
      +" %^RESET%^back from the %^BOLD%^%^BLACK%^rift%^RESET%^, retreating"
      +" further back into the %^BLUE%^void%^RESET%^.");
  }
  tentacles_withdrawn = 1;
  for (i=0;i<9;i++){
    rm_name = TECVOID + "inner_void" + i;
    start_room= find_object_or_load(rm_name);
    if (objectp(start_room)){
      unfettered = present("unfettered", start_room);
      rift = present("rent", start_room);
      if (objectp(unfettered)){
        rm_name = TECVOID + "inner_void10" + i;
        destination = find_object_or_load(rm_name);
        unfettered->move(destination);
        if (i==0){
          if (objectp(rift)){
            rift->move(start_room);
          }
        } else {
          rift = present("rent", destination);
          if (objectp(rift)){
            rift->remove();
          }
        }
      }
    }
  }
}

int query_tentacles_withdrawn(){
  return tentacles_withdrawn;
}

void set_tentacles_withdrawn(int withdrawn){
  tentacles_withdrawn = withdrawn;
}

int move(mixed dest){
  object rent, room, start_room;
  string rm_name;
  int hold;
  if (objectp(ETO)){
    rent = present("void", ETO);
    start_room = ETO;
  }
  hold = ::move(dest);
  if (objectp(ETO)){
    ETO->set_had_players(3);
  }
  if (start_room!=(ETO))
  {
    tell_room(start_room, "The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e"
      +"%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^"
      +"d%^RESET%^ uses its grasping %^BOLD%^%^BLACK%^t"
      +"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^MAGENTA%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e"
      +"%^BOLD%^%^BLACK%^s%^RESET%^ to pull itself along,"
      +" dragging the %^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^i"
      +"%^BOLD%^%^BLACK%^ft with it");
    tell_room(ETO, "The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e"
      +"%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^"
      +"d%^RESET%^ moves by using its grasping %^BOLD%^%^BLACK%^t"
      +"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
      +"%^MAGENTA%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e"
      +"%^BOLD%^%^BLACK%^s%^RESET%^ to drag itself,"
      +" pulling the %^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^i"
      +"%^BOLD%^%^BLACK%^ft it emerges from along with it");
  }
  if (objectp(ETO) && !present("void", ETO)
            && file_name(ETO)!= JUNG_ROOM + "inter_void"){
    if (!objectp(rent) ){
      rent = new(OBJ + "void");
    }
    rm_name = file_name(ETO);
    rent->move(ETO);
    room = find_object_or_load(JUNG_ROOM + "inter_void");
    if (objectp(room)){
      room->remove_exit("out");
      room->add_exit(rm_name, "out");
    }
  }
  return hold;

}

string seized_desc(){
  object * seizees;
  int i, count, tent_num;
  string result, tent_name;
  seizees = keys(query_seized());
  count = sizeof(seizees);
  result = "";
  if (count>0){
    for (i=0;i<count;i++){
      if (!objectp(seizees[i])){
        continue;
      }
      tent_name = query_seizing_tentacle_name(seizees[i]);
      result += seizees[i]->QCN  + " is held in its " + tent_name;
    }
  }
  return result;
}

mapping query_exits_used(){
  return exits_used;
}

string * query_path_trod(){
  return path_trod;
}

void wander_when_lost(){
  mapping exits;
  string * ks, room_name, barred_exits, temp_exits, exit;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  barred_exits = ({});
  room_name = base_name(ETO);
  if (sizeof(exits_used)<1){
    barred_exits = ({});
  } else {
    ks = keys(exits_used);
    if (member_array(room_name, ks)!= -1){
      barred_exits += exits_used[room_name];
    } else {
      barred_exits = ({});
    }
  }
  exits = ETO->query_exits();
  count = sizeof(exits);
  if (count>0){
    for (i=0;i<count;i++){
      if (interact("ropebridge1", ETO->query_exit(exits[i]))
        || interact("j_link5", ETO->query_exit(exits[i])) ){
        tell_room(ETO, "Can't go " + exits[i] + ": leads to " + ETO->query_exit(exits[i]) );
        barred_exits += ({exits[i]});
      }
    }
  }
  if (sizeof(barred_exits)>0){
    exits -= barred_exits;
  }
  if (sizeof(exits)<1){
    tell_room(ETO, "No unused exits available. Retracing steps");
    retrace_steps();
    return;
  }
  path_trod += ({base_name(ETO)});
  exit = exits[random(sizeof(exits))];
  if (sizeof(ks) >0 && member_array(base_name(ETO), ks)!=-1){
    temp_exits = exits_used[base_name(ETO)];
  } else {
    temp_exits = ({});
  }
  temp_exits += ({exit});
  exits_used[base_name(ETO)] = temp_exits;
  force_me(exit);
  if (objectp(ETO)){
    ETO->short_desc();
  }
}

string reverse_direction(string direction){
  switch(direction){
  case "up":
    return "down";
  case "down":
    return "up";
  case "north":
    return "south";
  case "northeast":
    return "southwest";
  case "east":
    return "west";
  case "southeast":
    return "northwest";
  case "south":
    return "north";
  case "southwest":
    return "northeast";
  case "west":
    return "east";
  case "northwest":
    return "southeast";
  case "in":
    return "out";
  case "out":
    return "in";
  }
}

void retrace_steps(){
  string last_step, dir, * exits;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  if (sizeof(path_trod)<1){
    tell_room(ETO, "I've run out of steps to retrace. Nowhere left to run to, baby. Nowhere to go.");
    return;
  }
  last_step = path_trod[sizeof(path_trod)-1];
  exits = ETO->query_exits();
  count = sizeof(exits);
  if (count<1){
    return;
  }
  for (i=0;i<count;i++){
    if (ETO->query_exit(exits[i])==last_step){
      force_me(exits[i]);
      if (objectp(ETO)){
        ETO->short_desc();
      }
      if (base_name(ETO)== last_step){
        path_trod = path_trod[0..sizeof(path_trod)-2];
      }
      return;
    }
  }
}

string long_desc(){
  string desc, slime_desc, skin_desc, seized_desc;
  desc = "%^BOLD%^%^BLACK%^This is the legendary %^RESET%^%^MAGENTA%^Un"
        +"%^BLUE%^f%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^"
        +"ed%^BOLD%^%^BLACK%^, a %^RESET%^m%^BOLD%^%^WHITE%^a%^RESET%^le"
        +"%^BOLD%^%^BLACK%^v%^RESET%^ol%^BOLD%^%^WHITE%^e%^RESET%^nt"
        +" %^BOLD%^%^BLACK%^entity from %^RESET%^%^BLUE%^Elsewhere"
        +"%^BOLD%^%^BLACK%^. Its huge shifting %^RESET%^%^MAGENTA%^p"
        +"%^RED%^u%^MAGENTA%^rp%^BLUE%^l%^BOLD%^%^MAGENTA%^i%^RESET%^"
        +"%^MAGENTA%^sh m%^BLUE%^a%^MAGENTA%^ss %^BOLD%^%^BLACK%^is hard"
        +" to look at. From the glances you can manage,  you gain an"
        +" impression of %^RESET%^%^BLUE%^nightmarish tentacles"
        +" %^BOLD%^%^BLACK%^, covered with%^RESET%^%^BLUE%^ impenetrably"
        +" %^BOLD%^%^BLACK%^thick, rubbery sk%^RESET%^%^MAGENTA%^i"
        +"%^BOLD%^%^BLACK%^n.";
  if (objectp(ETO) && !ETO->is_vacuum()){
    desc+= " They emerge from an %^BOLD%^%^WHITE%^i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e"
        +"%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^BOLD%^%^BLACK%^.";
  }
  desc += " A %^RESET%^%^MAGENTA%^g%^BOLD%^%^RED%^a%^RESET%^%^MAGENTA%^"
        +"ping %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w %^BOLD%^"
        +"%^BLACK%^can be seen within the void. Ugly,%^RESET%^ %^RED%^"
        +"red r%^BOLD%^%^RED%^i%^RESET%^%^RED%^mmed %^BOLD%^"
        +"%^WHITE%^e%^BLUE%^y%^WHITE%^es %^BOLD%^%^BLACK%^float in and"
        +" out of view. A violent sense of %^BOLD%^%^RED%^m%^RESET%^"
        +"%^RED%^a%^BOLD%^%^RED%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^ce"
        +" %^BOLD%^%^BLACK%^erupts from within. %^RESET%^";
  if (objectp(ETO) && ETO->is_vacuum()){
    desc+= " Now revealed within the %^BOLD%^%^WHITE%^i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e"
        +"%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^, the creature is truly %^RED%^"
        +"e%^BOLD%^%^RED%^n%^RESET%^%^RED%^or%^BOLD%^m%^RESET%^%^RED%^ou"
        +"%^BOLD%^s%^RESET%^. Its bulk stretches into the %^BLUE%^void"
        +" %^RESET%^in all directions.";
  }
  desc = desc +"
";
  desc = desc + "%^RESET%^The creature is so large, you could choose to"
    +" %^BOLD%^%^YELLOW%^<target>%^RESET%^ a specific one of its limbs"
    +" with your attacks.";
  slime_desc = slime_desc();
  skin_desc = skin_desc();
  seized_desc = seized_desc();
  desc = desc + "
" + slime_desc + "
" + skin_desc + "
" + seized_desc;
  return desc;
}

void throw2(){
  object * critters, room, harness;
  int i, j, count, exit_count, damage, flag;
  string * exits, rm_name, direction, h_name;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  critters -= ({keys(seized)});
  critters -= ({TO});
  count = sizeof(critters);
  remove_paralyzed();
  set_property("no paralyze", 1);
  if (count > 1){
    tell_room(ETO, "%^BOLD%^%^BLUE%^The U%^RESET%^%^BLUE%^n"
    +"%^BOLD%^%^BLACK%^f%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^tt%^RESET%^"
    +"%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^d"
    +" %^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^xpl%^BOLD%^%^YELLOW%^o%^RED%^des"
    +" %^BOLD%^%^BLUE%^outwards, slamming tentacles into everything"
    +" nearby");
    exits = ETO->query_exits();
    exit_count = sizeof(exits);
    for (i=0;i<count;i++){
      if (critters[i]->query_true_invis() || critters[i]->id("unfettered")){
        tell_object(critters[i], "The Unfettered fails to affect your"
          +" %^BOLD%^%^WHITE%^immortal%^RESET%^ awesomeness");
        continue;
      }
      if (!objectp(critters[i])){
        continue;
      }
      flag = 0;
      for (j=1;j<6;j++){
        h_name = "harness " + j;
        harness= present(h_name, critters[i]);
        direction = exits[random(exit_count)];
        if (objectp(harness) && harness->query_worn() == critters[i]){
          if (harness->pre_exit_function(direction)){
            flag = 1;
            break;
          }
        }
      }
      if (flag ==1){
        tell_object(critters[i], "Your vine harness saves you from"
          +" being thrown any further");
      }
      direction = exits[random(exit_count)];
      rm_name = ETO->query_exit(direction);
      room = find_object_or_load(rm_name);
      if (objectp(room)){
        tell_object(critters[i], "%^BOLD%^%^YELLOW%^A%^BOLD%^%^BLUE%^"
          +" tentacle %^BOLD%^%^YELLOW%^catches you and throws you into the"
          +" next room!");
        tell_room(room, critters[i]->QCN + "%^BOLD%^%^WHITE%^flies in from"
          +" the next room");
        critters[i]->move(room);
        tell_room(ETO, "%^CYAN%^" + critters[i]->QCN + "%^BOLD%^%^WHITE%^"
          +" is thrown off to the %^BOLD%^%^YELLOW%^" + direction );
        if ((int)critters[i]->query_property("flying")==1){
          tell_object (critters[i], "You manage to catch your"
            +" %^BOLD%^%^WHITE%^flight%^RESET%^ and %^BOLD%^%^CYAN%^swoop"
            +" %^RESET%^upwards before you hit the %^ORANGE%^ground%^RESET%^"
            +".");
        } else {
          tell_object(critters[i], "%^ORANGE%^You %^BOLD%^%^RED%^slam"
            +" %^RESET%^%^ORANGE%^into the ground.");
          damage = (int)critters[i]->query_max_hp() * (30 + random(30))/100;
          critters[i]->do_damage(critters[i]->return_target_limb(),damage/3
                                                          + random(damage));
          critters[i]->add_attacker(TO);
          critters[i]->continue_attack();
          critters[i]->force_me("look");
        }
      }
    }
  }
}

int query_mucus(){
  return mucus;
}

int query_frozen_mucus(){
  return frozen_mucus;
}

void target(object targ){
  if (!objectp(targ)||objectp(ETO)||!present(targ, ETO)){
    return;
  }
  tell_object(targ, "The many %^BOLD%^%^WHITE%^e%^BLUE%^y%^RED%^e"
    +"%^WHITE%^s%^RESET%^ of %^BLUE%^the %^RESET%^%^MAGENTA%^Un"
    +"%^BLUE%^f%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^"
    +"ed%^RESET%^ lock gaze with you, and your mind is %^RED%^a"
    +"%^BOLD%^ss%^RESET%^%^RED%^au%^BOLD%^lt%^RESET%^%^RED%^ed"
    +"%^RESET%^ with a %^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^au%^BOLD%^"
    +"s%^RESET%^%^BLUE%^e%^GREEN%^a%^BOLD%^t%^RESET%^%^MAGENTA%^i"
    +"%^BOLD%^%^GREEN%^ng%^RESET%^ wave of %^BLUE%^h%^BOLD%^%^BLACK%^"
    +"o%^RESET%^%^BLUE%^rr%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^r"
    +"%^RESET%^!");
  tell_room(ETO, targ->QCN + " reels backwards, recoiling in %^BLUE%^"
    +"h%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^rr%^BOLD%^%^BLACK%^o"
    +"%^RESET%^%^BLUE%^r%^RESET%^ from the %^BOLD%^%^GREEN%^n"
    +"%^RESET%^%^GREEN%^au%^BOLD%^s%^RESET%^%^BLUE%^e%^GREEN%^a"
    +"%^BOLD%^t%^RESET%^%^MAGENTA%^i%^BOLD%^%^GREEN%^ng%^RESET%^ gaze"
    +" of %^BLUE%^the %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e"
    +"%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed%^RESET%^!", targ);

}

void tent_monster(){
  object * critters, monster, target, *targets;
  int i, count;

  if (!objectp(ETO) || ETO->is_vacuum()){
    return;
  }
  summon_help();
  if ( present("tentacle monster", ETO)){
    return;
  }
  critters = query_attackers();
  if (sizeof(critters)<1){
    return;
  }
  count = 0;
  targets = ({});
  for (i=0;i<sizeof(critters);i++){
    monster = present("tentacle monster", ETO);
    if (objectp(monster)){
      count ++;
    } else {
      targets += ({critters[i]});
    }
  }
  if (count > 0 && count > sizeof(critters) - 2){
    return;
  }
  target = targets[random(sizeof(targets))];
  tell_room(ETO, "%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^small,"
    +" %^BOLD%^%^BLACK%^tentacled %^RESET%^%^MAGENTA%^sq%^BOLD%^"
    +"%^CYAN%^u%^GREEN%^i%^RESET%^%^MAGENTA%^dl%^BOLD%^%^BLUE%^i"
    +"%^RESET%^%^MAGENTA%^ke monster %^BOLD%^%^BLACK%^flies in"
    +" from the %^RESET%^%^BLUE%^void%^BOLD%^%^BLACK%^"
    +" surrounding the U%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^f"
    +"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^tt%^RESET%^%^MAGENTA%^"
    +"e%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^d, and"
    +" attaches itself to %^RESET%^" + target->QCN + "'s %^BOLD%^"
    +"%^BLACK%^face", target);
  tell_object(target, "%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^small,"
    +" %^BOLD%^%^BLACK%^tentacled %^RESET%^%^MAGENTA%^sq%^BOLD%^"
    +"%^CYAN%^u%^GREEN%^i%^RESET%^%^MAGENTA%^dl%^BOLD%^%^BLUE%^i"
    +"%^RESET%^%^MAGENTA%^ke monster %^BOLD%^%^BLACK%^flies in"
    +" from the %^RESET%^%^BLUE%^void%^BOLD%^%^BLACK%^"
    +" surrounding the U%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^f"
    +"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^tt%^RESET%^%^MAGENTA%^"
    +"e%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^d, and"
    +" attaches itself to your %^BOLD%^%^BLACK%^face");
  monster = new(OBJ + "tentacle_monster");
  monster->move(target);
  monster->cling(target);
}

object * query_all_attackers(){
  object * clones, *critters, *result, m;
  int i, count;
  m = query_master();
  result = m->query_attackers();
  clones = children(MOB + "unfettered_clone");
  count = sizeof(clones);
  for (i=0;i<count;i++){
    if (!objectp(clones[i])){
      continue;
    }
    critters = clones[i]->query_attackers();
    result += critters;
  }
  return result;
}

void scream(){
  object * critters;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  critters -= ({TO});
  count = sizeof(critters);
  if (count > 0){
    tell_room(ETO, "%^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d%^RESET%^ SCREAMS telepathically right into your brain!");
  }
}

void fling(){
  object flingee, target, * clones, * critters, * pcs, *flingees;
  if (sizeof(seized)<1){
    return;
  }
  flingees = keys(seized);
  flingee = flingees[random(sizeof(flingees))];
  if (!objectp(flingee)){
    tell_room(ETO, "There was a problem with the thing I was trying to fling");
    return;
  }
  critters = query_all_attackers();
  pcs = query_pcs_outside_rift();
  critters += pcs;
  critters -= ({flingee});
  pcs = filter_for_pcs(critters);
  if (sizeof(pcs)>0){
    target = pcs[random(sizeof(pcs))];
  } else {
    if (sizeof(critters)>0){
      target = critters[random(sizeof(critters))];
    }else {
      tell_room("There're no targets to fling anything at");
    }
  }
  if (!objectp(target)){
    fling_out_of_rift(flingee);
    return;
  }
  tell_object(flingee, "The %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^"
    +"%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^c%^RESET%^l"
    +"%^BOLD%^%^BLACK%^e%^RESET%^ swings back wildly before flinging"
    +" you toward " + target->QCN);
  if (objectp(environment(flingee)) && objectp(environment(target))
                      && environment(target) == environment(flingee)){
    tell_room( environment(flingee), "The %^BOLD%^%^BLACK%^t%^RESET%^"
      +"e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^c"
      +"%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^ holding " + flingee->QCN
      +" %^RESET%^swings back wildly before flinging " + flingee->QO
      +" toward " + target->QCN, flingee, target);
  } else {
    if (objectp(environment(flingee))){
      tell_room(environment(flingee), "%^BOLD%^%^RED%^"+flingee->QCN
        +" flies off toward " + target->QCN, flingee );
    }
    if (objectp(environment(target))){
      tell_room(environment(target),"%^BOLD%^%^RED%^" + flingee->QCN
        +" %^BOLD%^%^RED%^flies in from elsewhere!");
      flingee->move(environment(target));
      tell_object(flingee, "%^BOLD%^%^RED%^You are flung into another"
        +" place!");
    }
  }
  if (target->reflex_save(46)){
    tell_object(target, "%^BOLD%^%^YELLOW%^You dive out the way as "
      + flingee->QCN + " %^BOLD%^%^YELLOW%^hurtles toward you!");
    tell_object(flingee, "%^BOLD%^%^YELLOW%^" + target->QCN+ " dives"
      +" out of the way as you hurtle toward " + target->QO + "!");
    if (objectp(environment(flingee))){
      tell_room(environment(flingee), "%^BOLD%^%^YELLOW%^"
        + target->QCN + " %^BOLD%^%^YELLOW%^dives out of the way as "
        + flingee->QCN + " %^BOLD%^%^YELLOW%^hurtles toward "
        + target->QO + "!", target, flingee);
    }
    tell_object(flingee, "You %^BOLD%^%^RED%^crash%^RESET%^ into the"
      +" %^ORANGE%^ground%^RESET%^!");
    flingee->set_paralyzed(15, "You're dazed from the impact!");
    if (objectp(environment(flingee))){
      tell_room(environment(flingee), flingee->QCN + "%^BOLD%^%^RED%^"
        +" crashes %^RESET%^into the %^ORANGE%^ground%^RESET%^!"
        , flingee);
    }
    flingee->cause_typed_damage(TO, flingee->return_target_limb(),
      400, "bludgeoning");
  } else {
    tell_object(flingee, "You %^BOLD%^%^RED%^SLAM%^RESET%^ into "
      + target->QCN + " %^RESET%^and fall to the floor in a%^GREEN%^"
      + " tangle%^RESET%^ of limbs");
    tell_object(target, flingee->QCN + " %^BOLD%^%^RED%^SLAMS%^RESET%^"
      +" into you and you both fall to the floor in a %^GREEN%^tangle"
      +" %^RESET%^of limbs");
    if (objectp(environment(target))){
      tell_room(environment(target), flingee->QCN + "%^BOLD%^%^RED%^"
      +" SLAMS%^RESET%^ into " + target->QCN + " and they fall to the"
      +" floor in a %^GREEN%^tangle%^RESET%^ of limbs", flingee, target);
    }
    flingee->cause_typed_damage(TO, flingee->return_target_limb(),
      300, "bludgeoning");
    target->cause_typed_damage(TO, target->return_target_limb(),
      300, "bludgeoning");
    target->set_paralyzed(10, "You are dazed from the impact!");
    flingee->set_paralyzed(10, "You are dazed from the impact!");
    target->set_tripped(1, "You are struggling to get up");
    flingee->set_tripped(1, "You are struggling to get up");
  }
  flingee->remove_property("posed");
}

void sweep(){
  object * critters;
  int i, count, dc;
  if (!objectp(ETO)){
    return;
  }
  summon_help();
  tell_room(ETO, "A %^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^u%^BOLD%^"
    +"%^BLACK%^bb%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ry t%^RESET%^e"
    +"%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^c%^RESET%^l"
    +"%^BOLD%^%^BLACK%^e %^RESET%^sweeps across the room at ankle"
    +" height!");
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1){
    return;
  }
  dc = random(12) + 37;
  for (i=0;i<count;i++){
    if (critters[i]->query_true_invis() || critters[i]==TO){
      continue;
    }
    if (critters[i]->reflex_save(dc)){
      tell_object(critters[i], "You jump over the %^BOLD%^%^BLACK%^t"
        +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
        +"%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^e %^RESET%^and stay on"
        +" your feet.");
      tell_room(ETO, critters[i]->QCN + " %^RESET%^jumps over the"
        +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
        +"%^BLUE%^a%^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^e"
        +" %^RESET%^and stays on " + critters[i]->QP + " feet."
        , critters[i]);
    } else {
      tell_object(critters[i], "%^BOLD%^%^BLUE%^The %^BOLD%^%^BLACK%^t"
        +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
        +"%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^e %^BLUE%^knocks you"
        +" off your feet!");
      tell_room(ETO, "%^BOLD%^%^BLUE%^The %^BOLD%^%^BLACK%^t%^RESET%^"
        +"e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^c"
        +"%^RESET%^l%^BOLD%^%^BLACK%^e %^BLUE%^knocks "
        + critters[i]->QCN +" off " + critters[i]->QP + " feet."
        , critters[i]);
      critters[i]->set_tripped(1);
    }
  }
}

void throw(){
  if (!objectp(ETO)|| ETO->is_vacuum()){
    return;
  }
  summon_help();
  tell_room(ETO, "%^BOLD%^%^BLACK%^The U%^RESET%^%^BLUE%^n"
    +"%^BOLD%^%^BLACK%^f%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^tt%^RESET%^"
    +"%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^d"
    +" draws in on itself, pulling all its %^RESET%^%^BLUE%^tentacles"
    +" %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^en%^BOLD%^%^YELLOW%^e"
    +"%^RESET%^%^MAGENTA%^rg%^BOLD%^%^WHITE%^i%^MAGENTA%^e%^RESET%^"
    +"%^MAGENTA%^s%^BOLD%^%^BLACK%^ inwards");
  remove_property("no paralyze");
  set_paralyzed(5, "You are drawing in your energies");
  call_out("throw2", 2);
}

void retreat4(object room){
  object * critters;
  int i, count;
  report ("retreat4 called");
  critters = all_living(room);
  count = sizeof(critters);
  for (i=0;i<count;i++){
    critters[i]->remove_paralyzed();
  }
  // Put in code to do ONE of the following:
  //  * summon Mehac to encourage the heroes to seal the Unfettered in / warn them against going after it
  //    (if they are working for her and none of them has killed her since starting the quest)
  //  * summon Taluc and/or Epithon to attack them - if one or both yet live.
}

void retreat3(object room){
  int i;
  string void_name;
  object destination, rift, ob, cln, inner_rift;
  report ("%^BOLD%^%^CYAN%^retreat3 called");
  tell_room(room, "%^BOLD%^%^RED%^As " + query_short() +" %^BOLD%^"
    +"%^RED%^retreats into the %^RESET%^%^BLUE%^void%^BOLD%^%^RED%^,"
    +" its %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^a"
    +"%^BOLD%^%^BLACK%^cles %^RESET%^%^BLUE%^slithering%^BOLD%^%^RED%^"
    +" rapidly back, grab at the edges of the %^BOLD%^%^BLACK%^r"
    +"%^RESET%^i%^BOLD%^%^BLACK%^ft %^BOLD%^%^RED%^and beginning to drag"
    +" it shut!");
  set_funcs(({"throw", "throw", "sweep", "sweep", "sweep" }));
  report ("finding destination");
  destination = find_object_or_load(TECVOID + "inner_void0");
  if (objectp(destination)){
    report ("found destination");
    rift = present("inner rent", destination);
    if(!objectp(rift))
    {
      rift = new (OBJ + "void");
      rift->move(ETO);
    }
    rift->set_exit_room(file_name(destination));
    report ("inner rift exit set");
    report ("setting up inner voids");
    for (i=1;i<9;i++){
      void_name=TECVOID + "inner_void" + i;
      inner_rift = find_object_or_load(void_name);
      if (objectp(inner_rift)){
        inner_rift->set_had_players(3);
        cln = new(MOB + "unfettered_clone");
        if (objectp(cln)){
          cln->set_master(TO);
          cln->move(inner_rift);
          add_clone(cln);
          if (present("rift", inner_rift)){
            present("rift", inner_rift)->move("/d/shadowgate/void");
          }
        }
        switch(i){
        case 1:
          cln->set_short("The upper left portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 2:
          cln->set_short("The upper portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 3:
          cln->set_short("The upper right portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 4:
          cln->set_short("The left portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 5:
          cln->set_short("The right portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 6:
          cln->set_short("The lower left portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 7:
          cln->set_short("The lower portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        case 8:
          cln->set_short("The lower right portion of %^BLUE%^The"
            +" %^RESET%^%^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^"
            +"tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed");
          break;
        }
      }
    }
    report("inner voids set. Moving to destination");
    move(destination);
    set_short("The central portion of %^BLUE%^The%^RESET%^"
      +" %^MAGENTA%^Un%^BLUE%^f%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e"
      +"%^BLUE%^r%^MAGENTA%^ed");
    report ("Moved okay. Correcting exit from new location");
    destination->remove_exit("out");
    destination->add_exit(file_name(room), "out");
//    ob = new(OBJ + "inner_void");
//    ob->move(ETO);
//    ob->set_exit_room(file_name(room));
  }
  rift = present("outer rent", ETO);//Move the rift back to where it was,
  if (objectp(rift)){     //because it will have followed the Unfettered
    report ("moving rift back to original room");
    rift->move(room);
    report ("rift moved to: " + base_name(room));
  }
  ETO->set_had_players(1);
  call_out("retreat4", 2, room);
}

void retreat2(object room){
  object * critters;
  int i, count;
  report ("%^BOLD%^%^CYAN%^retreat2 called");
  if (!objectp(room))
  {
     report ("problem with the room object in retreat2()");
  }
  tell_room(room, query_short() + ", clearly injured, scrabbles"
        +" back into the %^BOLD%^%^WHITE%^"
        +"i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
        +"%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a"
        +"%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^BOLD%^%^BLACK%^");
  critters = all_living(ETO);
  count = sizeof(critters);
  for (i =0; i<count;i++){
    if (critters[i]==TO || critters[i]->query_true_invis()){
      continue;
    }
    critters[i]->cease_all_attacks();
    critters[i]->set_paralyzed(40, "%^BOLD%^%^CYAN%^You are stunned from"
      +" the deafening screech!");
  }
  call_out("retreat3", 4, room);
}

void retreat(){
  object * critters, attacker, v, *drv;
  int i, count;
  string * names;
  report ("%^BOLD%^%^YELLOW%^Trying to retreat");
  tell_room(ETO, query_short() + "%^BOLD%^%^RED%^"
    +" %^CYAN%^SCREECHES %^RED%^with %^RESET%^%^RED%^rage%^BOLD%^%^RED%^"
    +" and %^RESET%^%^RED%^pain%^BOLD%^%^RED%^.");
  attacker = query_current_attacker();
  report ("Attacker is: " + attacker->QCN);
  if (objectp(attacker)){
    grant_quest(attacker, "Drove %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf"
      +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
      +" %^RESET%^back into the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^"
      +"%^BLACK%^d%^RESET%^!", 2000000, "You have driven %^MAGENTA%^The"
      +" %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
      +"%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d %^RESET%^back into the%^BOLD%^"
      +"%^BLACK%^ vo%^RESET%^i%^BOLD%^%^BLACK%^d%^RESET%^. A mighty deed,"
      +" indeed! Dare you follow it and finish the job? Or perhaps it would"
      +" just to accept that it is banished, for now?", 1);
    report ("Quest granted to attacker");
  } else {
    if (objectp(ETO)){
      tell_room(ETO, "There seems to have been an ERROR with whoever"
      +" landed the last blow against %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^"
      +"nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
      +"%^RESET%^. Please make a bug report, preferably including a log"
      +" of the last few lines of the fight.");
    }
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  for (i =0; i<count;i++){
    critters[i]->cease_all_attacks();
    if (critters[i]==TO || critters[i]->query_true_invis()){
      continue;
    }
    critters[i]->set_paralyzed(40, "%^BOLD%^%^CYAN%^You are stunned from"
      +" the deafening screech!");
  }
  v = present("rent", ETO);
  if (objectp(v)){
    names = ({});
    drv = query_all_attackers();
    count = sizeof(drv);
    if (count>0){
      for (i=0;i<count;i++){
        names += ({drv[i]->query_name()});
      }
    }
    v->set_drivers(names);
  } else {
    report ("There was no rent in the room");
  }
  report("Calling out retreat2");
  call_out("retreat2", 5, ETO);
//  move(JUNG_ROOM + "inter_void");
}

void die(){
  defeat6();
}

int categorize_incoming_attack(object attacker){
  int result, attack_type;
  object prev_ob,* weapons;
  string attacker_name, prev_ob_name;
  prev_ob = previous_object();
//  tell_room(ETO, "I was damaged by: " + file_name(prev_ob));
//  tell_room(ETO, "My attacker was: " + attacker->query_name());
//  tell_room(ETO, "Its file name is: " + file_name(attacker));
  attacker_name = attacker->query_name();
  // Work out what sort of attack it was, to determine what feat would affect the chances of targetting the attack
  tell_room(ETO, "My attacker is targetting one of my limbs");
  attack_type =0;
  if (!objectp(attacker)){
    tell_room(ETO, "ERROR with attacking object. Not taking damage. Please make a bug report");
    return;
  }
  if (attacker->is_wielding("lrweapon")){
//    tell_room(ETO, "Attack type: Ranged");
    attack_type = RANGED;
  } else {
    if (attacker->is_wielding("weapon")){
//    tell_room(ETO, "Attack type: melee");
      attack_type = MELEE;
    }
  }
  prev_ob_name = file_name(prev_ob);
  if (interact("/cmds/spells/", prev_ob_name)){ //This would mean that the attack was a spell
    if ( (string)prev_ob->get_save()=="reflex"){
//      tell_room(ETO, "Attack type: Area spell");
      attack_type = AREASPELL;
    } else {
//      tell_room(ETO, "Attack type: targetted spell");
      attack_type = TARGETSPELL;
    }
  } else {
//    tell_room(ETO, "The attack seems not to have been a spell");
  }
  return attack_type;
}

int check_accuracy_feat(object attacker, int attack_type){
  tell_room(ETO, "Checking for relevent accuracy feat");
  switch(attack_type){
  case MELEE:
    if (FEATS_D->can_use_feat(attacker, "lethal strikes")){
      tell_room(ETO, "%^BOLD%^%^RED%^Attacker has the right feat to target a limb");
      return 1;
    } else {
      tell_room(ETO, "%^BOLD%^%^BLUE%^Attacker DOESN'T have the right feat to target a limb");
      return 0;
    }
  case RANGED:
    if (FEATS_D->can_use_feat(attacker, "deadeye")){
      tell_room(ETO, "%^BOLD%^%^RED%^Attacker has the right feat to target a limb");
      return 1;
    } else {
      tell_room(ETO, "%^BOLD%^%^BLUE%^Attacker DOESN'T have the right feat to target a limb");
      return 0;
    }
  case TARGETSPELL:
    if (FEATS_D->can_use_feat(attacker, "perfect caster")){
      tell_room(ETO, "%^BOLD%^%^RED%^Attacker the right feat to target a limb");
      return 1;
    } else {
      tell_room(ETO, "%^BOLD%^%^BLUE%^Attacker DOESN'T have the right feat to target a limb");
      return 0;
    }

  case AREASPELL:
    return 0;
  }
}

void hurt_tentacle(string limb, int damage){
  object * seizees;
  int i, count, tent_num, seized_num, * nums, release_time;
  seizees = keys(query_seized());
  if (sizeof(seizees)>0){
    for(i=0;i<count;i++){
      nums = query_seized_numbers(seizees[i]);
      seized_num = nums[1];
      switch(limb){
      case "first tentacle":
        tent_num = 1;
        break;
      case "first tentacle":
        tent_num = 2;
        break;
      case "second tentacle":
        tent_num = 3;
        break;
      case "third tentacle":
        tent_num = 4;
        break;
      case "fourth tentacle":
        tent_num = 5;
        break;
      case "fifth tentacle":
        tent_num = 6;
        break;
      case "sixth tentacle":
        tent_num = 7;
        break;
      }
      if (seized_num == tent_num){
        release_time = nums[0];
        if (damage >20){
          damage = 20;
        }
        seized[seizees[i]]=({release_time - damage, seized_num});
        tell_object(seizees[i], "%^ORANGE%^The %^BOLD%^%^BLACK%^t"
          +"%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
          +"%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s %^RESET%^"
          +"%^ORANGE%^hold on you is %^BLUE%^weakened%^RESET%^!");
        if (objectp(environment(seizees[i]))){
          tell_room(environment(seizees[i]), "%^ORANGE%^The %^BOLD%^"
            +"%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^"
            +"%^BLUE%^a%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^'s"
            +" %^RESET%^%^ORANGE%^hold on " + seizees[i] + "%^RESET%^"
            +" %^ORANGE%^is %^BLUE%^weakened%^RESET%^!", seizees[i]);
        }
        if (release_time - damage <= time()){
           release_seized(seizees[i]);
        }
      }
    }
  }
}

mapping query_seized(){
  return seized;
}

void release_all(){
  int i, count;
  object * seizees;
  seizees = keys(query_seized());
}

void cause_typed_damage(victim,limb,damage,damage_type){
  int result, ratio, flag, start_hp, len, attack_type, tentacle_no;
  object attacker, main_room, prev_ob,* weapons;
  string how_much, room_name, targeted_limb, attacker_name, * targeter_names, prev_ob_name;
  attacker = query_current_attacker();
  tentacle_no = 0;
  report ("Taking typed damage. Limb: " + limb +"  Damage: " + damage + "  Type: " + damage_type);
  if (!objectp(attacker)){
    attacker = victim;
  }
  if (!objectp(attacker)){
    tell_room(ETO, "Error with damage processing function: attacker does not exist. Please make a bug report.");
    return;
  }
  attacker_name = attacker->query_name();
//  tell_room(ETO, "Attacker name is : " + attacker_name);
  targeter_names = keys(targeters);
  attack_type = categorize_incoming_attack(attacker);
//  check_accuracy_feat(attacker, attack_type);//PROBABLY SHOULDN'T NEED THIS LINE
  if (member_array(attacker_name, targeter_names)!=-1){
    if (attack_type == AREASPELL){
      tell_object(attacker, "You can't target that spell precisely");
    }
  }
  if (member_array(attacker_name, targeter_names)!=-1 && attack_type != AREASPELL){
    targeted_limb = targeters[attacker_name];
    switch(targeted_limb){
    case "maw":
//attackers with the relevant accuracy feat can hit the maw 40% of the time. Others hit
//the maw 25% of the time. Otherwise sticks with randomly determined limb
      if ((check_accuracy_feat(attacker, attack_type) && random(10)>4) || !random(4)){
        limb = "maw";
      }
      break;
    case "eye":
//attackers with the relevant accuracy feat can hit an eye 60% of the time. Others hit
//the right limb 35% of the time. Otherwise sticks with randomly determined limbd
      if ((check_accuracy_feat(attacker, attack_type) && random(10)>3) || random(100)<35){
        limb = "eye";
      }
      break;
    case "first tentacle":
      if (tentacle_no == 0)
        tentacle_no = 1;
    case "second tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 2;
    case "third tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 3;
    case "fourth tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 4;
    case "fifth tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 5;
    case "sixth tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 6;
    case "seventh tentacle"://deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = 7;
    case "tentacle":  //deliberately falling through
      if (tentacle_no == 0)
        tentacle_no = random(7)+1;
//attackers with melee accuracy can hit a tentacle 90% of the time. Others hit
//the right limb 66% of the time. Otherwise sticks with randomly determined limb
      if ((check_accuracy_feat(attacker, attack_type) && random(10)) || random(3)){
        switch (tentacle_no){
        case 1:
          limb = "first tentacle";
          break;
        case 2:
          limb = "second tentacle";
          break;
        case 3:
          limb = "third tentacle";
          break;
        case 4:
          limb = "fourth tentacle";
          break;
        case 5:
          limb = "fifth tentacle";
          break;
        case 6:
          limb = "sixth tentacle";
          break;
        case 7:
          limb = "seventh tentacle";
          break;
        }
      }
    }
  }
  attacker_name = attacker->query_name();
  if (!objectp(ETO)){
    move("/d/shadowgate/void");
    return;
  }
  if (relaying ==1 && objectp(relay_room)){
    main_room = relay_room;
  } else {
    main_room = ETO;
  }
  result = damage;
  if (main_room->is_vacuum()){
    switch(limb){
    case "maw":
      switch(damage_type){
      case "cold":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^cold%^RESET%^"
          +" %^BOLD%^%^WHITE%^freezes%^RESET%^ the creature's"
          +" %^RED%^m%^MAGENTA%^a%^RED%^w%^RESET%^.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s all focus on " + attacker->QCN, attacker) ;
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^RED%^e%^WHITE%^s%^RESET%^ all focus on you!");
        call_out("target", 2, victim);
        break;
      case "electricity":
        tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ streaks"
        +" through the i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e"
        +"%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i"
        +"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^ and strikes the creature's"
        +" %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s all focus on " + attacker->QCN, attacker) ;
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^RED%^e%^WHITE%^s%^RESET%^ all focus on you!");
        call_out("target", 2, victim);
        break;
      case "fire":
        tell_room(main_room, "The %^BOLD%^%^RED%^fire%^RESET%^ partly%^BOLD%^"
        +" %^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^"
        +"%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^"
        +"%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ in the i%^RESET%^n%^BOLD%^%^WHITE%^t"
        +"%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o"
        +"%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^"
        +"%^BLUE%^void%^RESET%^.");
        result = result *3/4;
        break;
      case "acid":
        tell_room(main_room, "The %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i"
        +"%^BOLD%^%^GREEN%^d%^RESET%^ flies into the i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r"
        +"%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^"
        +"%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i"
        +"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^"
        +"%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^ and %^BOLD%^"
        +"%^GREEN%^burns%^RESET%^ the creature's %^BOLD%^%^RED%^m"
        +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^w.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^RED%^e%^WHITE%^s%^RESET%^ all focus on "
        + attacker->QCN, attacker);
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^RED%^e%^WHITE%^s%^RESET%^ all focus on you!");
        call_out("target", 2, attacker);
        break;
      case "sonic":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^sound%^RESET%^ %^BOLD%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^"
        +"%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^"
        +"%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ in the i%^RESET%^n%^BOLD%^%^WHITE%^t"
        +"%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o"
        +"%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^"
        +"%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "untyped"://
      case "force"://
      case "bludgeoning"://
      case "piercing"://
      case "slashing"://deliberately falling through
        tell_room(main_room, attacker->QCN + "'s attack strikes the"
        +" creature in its %^BOLD%^%^RED%^m%^RESET%^%^MAGENTA%^a"
        +"%^BOLD%^%^RED%^w%^RESET%^.", attacker);
        tell_object(attacker, "Your attack strikes the creature in"
        +" its %^BOLD%^%^RED%^m%^RESET%^%^MAGENTA%^a%^BOLD%^%^RED%^w"
        +"%^RESET%^.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s%^RESET%^ all focus on "
        + attacker->QCN, attacker);
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^RED%^e%^WHITE%^s%^RESET%^ all focus on you!");
        call_out("target", 2, attacker);
        break;
      case "mental":
        tell_object(attacker, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        attacker->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, attacker->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + victim->QP + "head with both hands.", attacker);
        attacker->cause_typed_damage(TO, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    case "eye":
      switch(damage_type){
      case "cold":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^cold%^RESET%^ %^BOLD%^%^WHITE%^"
          +"freezes%^RESET%^ the creature's %^BOLD%^%^WHITE%^e%^BLUE%^y"
          +"%^BOLD%^%^WHITE%^e%^RESET%^.");
        break;
      case "electricity":
        tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ streaks"
        +" through the i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e"
        +"%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i"
        +"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^ and strikes the creature's"
        +" %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e%^RESET%^.");
        call_out("target", 2, attacker);
        break;
      case "fire":
        tell_room(main_room, "The %^BOLD%^%^RED%^fire%^RESET%^ partly"
        +" %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^"
        +"%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^%^BLUE%^a"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^s%^RESET%^ in"
        +" the i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^"
        +"%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^.");
        result = result *3/4;
        break;
      case "acid":
        tell_room(main_room, "The %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^"
        +"%^GREEN%^d%^RESET%^ flies into the i%^RESET%^n%^BOLD%^%^WHITE%^t"
        +"%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^"
        +"%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^"
        +"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^"
        +"a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^ and %^BOLD%^"
        +"%^GREEN%^burns%^RESET%^ the creature's %^BOLD%^%^WHITE%^e%^BLUE%^"
        +"y%^BOLD%^%^WHITE%^e%^RESET%^.");
        break;
      case "sonic":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^sound%^RESET%^ %^BOLD%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^s"
        +"%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^%^BLUE%^a%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^s%^RESET%^ in the"
        +" i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^"
        +"%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "untyped"://
      case "force"://
      case "bludgeoning"://
      case "piercing"://
      case "slashing"://deliberately falling through
        tell_room(main_room, attacker->QCN + "'s attack strikes the creature in"
        +" its %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e%^RESET%^."
                                                              , attacker);
        tell_object(attacker, "Your attack strikes the creature in its"
        +" %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e");
        break;
      case "mental":
        tell_object(attacker, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        victim->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, attacker->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + attacker->QP + "head with both hands.", attacker);
        attacker->cause_typed_damage(attacker, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    case "first tentacle":  //
    case "second tentacle": //
    case "third tentacle":  //
    case "fourth tentacle": //
    case "fifth tentacle":  //
    case "sixth tentacle":  //
    case "seventh tentacle":// deliberately falling through
      switch (damage_type){
      case "fire":
        tell_room(main_room, "The %^BOLD%^%^RED%^fire%^RESET%^ partly %^BOLD%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^s"
        +"%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^%^BLUE%^a%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^s%^RESET%^ in the"
        +" i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
        +"%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a"
        +"%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = result*3/4;
        break;
      case "cold":
        if (mucus >0){
          tell_room(main_room, "%^BOLD%^%^CYAN%^The %^WHITE%^cold%^CYAN%^ creeps"
          +" into %^GREEN%^sl%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^m%^BLACK%^e"
          +" %^CYAN%^coating the %^BOLD%^%^BLACK%^tentacle%^CYAN%^,"
          +" fr%^WHITE%^ee%^CYAN%^z%^RESET%^i%^BOLD%^%^CYAN%^ng it!");
          if (result > mucus){
            result -= mucus;
            frozen_mucus += mucus;
            mucus = 0;
            tell_room(main_room, "%^BOLD%^%^GREEN%^The%^RESET%^%^MAGENTA%^ mucus"
              +"%^BOLD%^%^GREEN%^ is completely %^BOLD%^%^CYAN%^fr%^BOLD%^"
              +"%^WHITE%^o%^CYAN%^z%^WHITE%^e%^CYAN%^n%^GREEN%^!");
          } else {
            mucus -= result;
            frozen_mucus += result;
            result = 0;
            ratio = frozen_mucus*100 / (frozen_mucus + mucus);
            if (ratio<=25){
              how_much = "less than a quarter";
            }
            if (ratio >25 && ratio <=50){
              how_much = "nearly half";
            }
            if (ratio >50 && ratio <=75){
              how_much = "more than half";
            }
            if (ratio >75){
              how_much = "almost completely";
            }
            tell_room(main_room, "%^BOLD%^%^GREEN%^The%^RESET%^%^MAGENTA%^ mucus"
              +"%^BOLD%^%^GREEN%^ is "+ how_much + " %^BOLD%^%^CYAN%^fr"
              +"%^BOLD%^%^WHITE%^o%^CYAN%^z%^WHITE%^e%^CYAN%^n%^GREEN%^!");
          }
        }
        break;
      case "electricity":
        if (mucus/10 > result){
          tell_room(main_room, "%^BOLD%^%^GREEN%^The %^BOLD%^%^YELLOW%^electricity"
            +" %^RESET%^disperses %^BOLD%^%^GREN%^harmlessly through the"
            +" %^RESET%^%^GREEN%^sl%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^my"
            +" %^RESET%^%^MAGENTA%^mucus");
          result = 0;
        }
        if (mucus > 0){
          result -= mucus/10;
          tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ is"
            +" partially dispersed by the %^RESET%^%^GREEN%^sl%^BOLD%^"
            +"%^GREEN%^i%^RESET%^%^GREEN%^my %^RESET%^%^MAGENTA%^mucus");
        }
        if (skin/10 > result){
          tell_room(main_room, "%^BOLD%^%^BLACK%^The %^BOLD%^%^YELLOW%^"
            +"electricity %^BOLD%^%^BLACK%^is absorbed by the creature's"
            +" thick, %^RESET%^%^MAGENTA%^rubbery"
            +" sk%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n");
          result = 0;
        }
        if (skin > 0){
          result -= skin/10;
          tell_room(main_room, "The %^BOLD%^%^YELLOW%^eletricity"
            +" %^RESET%^is partially absorbed by the creature's thick,"
            +" %^RESET%^%^MAGENTA%^rubbery sk%^BOLD%^%^BLACK%^i%^RESET%"
            +"^%^MAGENTA%^n");
        }
        break;
      case "acid":
        if (mucus >0){
          if (mucus - result < 0){
            result -= mucus;
            mucus = 0;
            tell_room(main_room,"%^ORANGE%^The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
              +"%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^eats away the last"
              +" of the %^GREEN%^sl%^BOLD%^i%^RESET%^%^GREEN%^my%^RESET%^"
              +" %^MAGENTA%^mucus%^RESET%^%^ORANGE%^ covering the"
              +" creature's skin.");
          } else {
            mucus -= result;
            result = 0;
            tell_room(main_room,"The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
              +"%^BOLD%^%^BLACK%^d %^RESET%^eats away at"
              +" the %^GREEN%^sl%^BOLD%^i%^RESET%^%^GREEN%^my%^RESET%^"
              +" %^MAGENTA%^mucus%^RESET%^ covering the"
              +" creature's skin.");
          }
        }
        if (random(SURFACE_AREA)<=skin){
          tell_room(main_room, "The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
            +"%^BOLD%^%^BLACK%^d %^RESET%^eats away at"
            +" the creature's thick, %^BOLD%^%^BLACK%^rubbery %^RESET%^"
            +"%^MAGENTA%^s%^BOLD%^%^BLACK%^k%^RESET%^%^MAGENTA%^i"
            +"%^BOLD%^%^BLACK%^n%^RESET%^.");
          if (skin >result){
            skin -= result;
            result = 0;
          } else {
            skin = 0;
            result = 0;
            tell_room(main_room, "The last of the %^BOLD%^%^BLACK%^sk%^RESET%^"
              +"%^MAGENTA%^i%^BOLD%^%^BLACK%^n %^RESET%^has %^GREEN%^d"
              +"%^BOLD%^i%^RESET%^%^GREEN%^ss%^BOLD%^o%^RESET%^%^GREEN%^"
              +"lv%^BOLD%^e%^RESET%^%^GREEN%^d%^RESET%^!");
          }
        } else {
          tell_room(main_room, "The %^BOLD%^%^BLACK%^ac%^GREEN%^i%^BOLD%^"
            +"%^BLACK%^d %^RESET%^runs into gaps in the creature's skin,"
            +" and it %^BOLD%^%^CYAN%^flinches%^RESET%^ in %^BOLD%^"
            +"%^RED%^pain");
        }
        break;
      case "sonic":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^sound%^RESET%^ %^BOLD%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^s"
        +"%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^%^BLUE%^a%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^s%^RESET%^ in the"
        +" i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^"
        +"%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "untyped":
      case "force":
      case "bludgeoning":
        if (frozen_mucus>0){
          if (random(SURFACE_AREA)<=frozen_mucus){
            if (result >= frozen_mucus){
              result -= frozen_mucus;
              frozen_mucus = 0;
              tell_room(main_room, "%^BOLD%^%^CYAN%^The last of the%^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^flies off, as " + victim->QCN + "%^BOLD%^"
                +"%^CYAN%^'s attack smashes it off the creature's"
                +" %^BOLD%^%^BLACK%^tentacle%^CYAN%^!", victim);
              tell_object(victim, "%^BOLD%^%^CYAN%^The last of the"
                +" %^BOLD%^%^WHITE%^frozen%^RESET%^%^MAGENTA%^ mucus"
                +" %^BOLD%^%^CYAN%^flies off, as your attack smashes"
                +" it off the creature's %^BOLD%^%^BLACK%^tentacle"
                +"%^CYAN%^!");
            } else {
              frozen_mucus -= result;
              result = 0;
              tell_room(main_room, "%^BOLD%^%^CYAN%^Shards of %^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^fly off, as " + victim->QCN + "%^BOLD%^"
                +"%^CYAN%^'s attack smashes it from the creature's"
                +" %^BOLD%^%^BLACK%^tentacle%^CYAN%^!", victim);
              tell_object(victim, "%^BOLD%^%^CYAN%^Shards of %^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^fly off, as your  attack smashes it from"
                +" the creature's %^BOLD%^%^BLACK%^tentacle"
                +"%^CYAN%^!");
            }
          }
          if (random(SURFACE_AREA)<= skin){
            tell_room("The attack bounces off the creature's %^BOLD%^"
              +"%^BLACK%^thick, rubbery sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^");
            result = 0;
          }
        }
        break;
      case "piercing"://
      case "slashing"://
      case "silver"://
      case "cold iron"://deliberately falling through
        if (random(SURFACE_AREA)<=mucus){
          tell_room(main_room, victim->QCN + "'s attack is clogged up in the"
            +" %^MAGENTA%^putrid %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
            +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^s"
            +"%^RESET%^ covering the creature's %^BOLD%^%^BLACK%^sk"
            +"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n%^RESET%^."
              , victim);
          tell_object(victim,  "Your attack is clogged up in the"
            +" %^MAGENTA%^putrid %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
            +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^s"
            +"%^RESET%^ covering the creature's %^BOLD%^%^BLACK%^sk"
            +"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n%^RESET%^.");
          result = 0;
        } else {
          if (result > skin / 10){
            tell_room(main_room, victim->QCN + "'s attack cuts through the"
              +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^, damaging the %^BOLD%^"
              +"%^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^e"
              +"%^MAGENTA%^sh %^RESET%^beneath.", victim);
            tell_object(victim, "Your attack cuts through the"
              +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^, damaging the %^BOLD%^"
              +"%^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^e"
              +"%^MAGENTA%^sh %^RESET%^beneath.");
            skin -= result;
            if (skin > 0){
              result -= skin/10;
            } else {
              tell_room(main_room, "%^BOLD%^%^GREEN%^The last of the"
                +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^"
                +"i%^BOLD%^%^BLACK%^n %^RESET%^falls away");
              skin = 0;
            }
          } else {
            tell_room(main_room, victim->QCN + "'s attack bounces off the"
              +" creature's thick, %^BOLD%^%^BLACK%^rubbery%^RESET%^"
              +" %^MAGENTA%^skin");
            result = 0;
          }
        }
        break;
      case "positive energy":
        tell_room(main_room, "The creature recoils from the %^BOLD%^"
          +"%^WHITE%^positive energy%^RESET%^, but seems mostly"
          +" unharmed");
          result = result/2;
        break;
      case "negative energy":
        tell_room(main_room, "The creature seems almost entirely"
          +" unaffected by the %^BOLD%^%^BLACK%^negative energy"
          +"%^RESET%^.");
          result = result/4;
        break;
      case "divine":
        tell_room(main_room, "As a being from %^BLUE%^Elsewhere%^RESET%^,"
          +" the creature seems %^BOLD%^%^BLUE%^resistant%^RESET%^ to"
          +" the power of the %^MAGENTA%^Gods%^RESET%^ of this"
          +" universe!");
          result = result/2;
        break;
      case "mental":
        tell_object(victim, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        victim->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, victim->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + victim->QP + "head with both hands.", victim);
        victim->cause_typed_damage(TO, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    }
  } else {
    switch(limb){
    case "maw":
      switch(damage_type){
      case "cold":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^cold%^RESET%^ heads toward the"
        +" creature's %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w"
        +"%^RESET%^, but simply %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^"
        +"%^BLUE%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p"
        +"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ as it crosses into the i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n"
        +"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
        +"%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "electricity":
        tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ streaks"
        +" into the i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e"
        +"%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i"
        +"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^ and strikes the creature's"
        +" %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s all focus on " + attacker->QCN, attacker) ;
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^"
        +"y%^RED%^e%^WHITE%^s all focus on you!");
        call_out("target", 2, victim);
        break;
      case "fire":
        tell_room(main_room, "The %^BOLD%^%^RED%^fire%^RESET%^ heads toward the"
        +" creature's %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w"
        +"%^RESET%^, but simply %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^"
        +"%^BLUE%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p"
        +"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ as it crosses into the i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n"
        +"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
        +"%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "acid":
        tell_room(main_room, "The %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^"
        +"%^GREEN%^d%^RESET%^ flies into the i%^RESET%^n%^BOLD%^%^WHITE%^t"
        +"%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^"
        +"%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^"
        +"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^"
        +"a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^ and %^BOLD%^"
        +"%^GREEN%^burns%^RESET%^ the creature's %^BOLD%^%^RED%^"
        +"m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s all focus on " + attacker->QCN, attacker);
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^"
        +"y%^RED%^e%^WHITE%^s all focus on you!");
        call_out("target", 2, attacker);
        break;
      case "sonic":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^sound%^RESET%^ %^BOLD%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^s"
        +"%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p%^BOLD%^%^BLUE%^a%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^s%^RESET%^ in the"
        +" i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
        +"%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^"
        +"%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
        +"%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "untyped"://
      case "force"://
      case "bludgeoning"://
      case "piercing"://
      case "slashing"://deliberately falling through
        tell_room(main_room, attacker->QCN + "'s attack penetrates the i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^"
        +"%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void"
        +"%^RESET%^ to strike the creature in its %^BOLD%^%^RED%^m"
        +"%^RESET%^%^MAGENTA%^a%^BOLD%^%^RED%^w%^RESET%^.", attacker);
        tell_object(attacker, "Your attack penetrates the i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^"
        +"%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void"
        +"%^RESET%^ to strike the creature in its %^BOLD%^%^RED%^m"
        +"%^RESET%^%^MAGENTA%^a%^BOLD%^%^RED%^w%^RESET%^.");
        tell_room(main_room, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^y"
        +"%^RED%^e%^WHITE%^s all focus on " + attacker->QCN, attacker);
        tell_object(attacker, "The creature's many %^BOLD%^%^WHITE%^e%^BLUE%^"
        +"y%^RED%^e%^WHITE%^s all focus on you!");
        call_out("target", 2, attacker);
        break;
      case "mental":
        tell_object(attacker, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        attacker->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, attacker->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + victim->QP + "head with both hands.", attacker);
        attacker->cause_typed_damage(TO, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    case "eye":
      switch(damage_type){
      case "cold":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^cold%^RESET%^ heads toward the"
        +" creature's %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e"
        +"%^RESET%^, but simply %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^"
        +"%^BLUE%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p"
        +"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ as it crosses into the i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n"
        +"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
        +"%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "electricity":
        tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ streaks"
        +" into the i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e"
        +"%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
        +"%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i"
        +"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
        +" %^RESET%^%^BLUE%^void%^RESET%^ and strikes the creature's"
        +" %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e%^RESET%^.");
        call_out("target", 2, attacker);
        break;
      case "fire":
        tell_room(main_room, "The %^BOLD%^%^RED%^fire%^RESET%^ heads toward the"
        +" creature's %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^w"
        +"%^RESET%^, but simply %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^"
        +"%^BLUE%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p"
        +"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ as it crosses into the i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n"
        +"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
        +"%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "acid":
        tell_room(main_room, "The %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^"
        +"%^GREEN%^d%^RESET%^ flies into the i%^RESET%^n%^BOLD%^%^WHITE%^t"
        +"%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^"
        +"%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^"
        +"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^"
        +"a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^ and %^BOLD%^"
        +"%^GREEN%^burns%^RESET%^ the creature's %^BOLD%^%^WHITE%^e%^BLUE%^"
        +"y%^BOLD%^%^WHITE%^e%^RESET%^.");
        break;
      case "sonic":
        tell_room(main_room, "The %^BOLD%^%^CYAN%^sound%^RESET%^ heads toward the"
        +" creature's %^BOLD%^%^WHITE%^e%^BLUE%^y%^BOLD%^%^WHITE%^e"
        +"%^RESET%^, but simply %^BOLD%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^BOLD%^"
        +"%^BLUE%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^p"
        +"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^e%^BOLD%^"
        +"%^WHITE%^s%^RESET%^ as it crosses into the i%^RESET%^n%^BOLD%^"
        +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d"
        +"%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n"
        +"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
        +"%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.");
        result = 0;
        break;
      case "untyped"://
      case "force"://
      case "bludgeoning"://
      case "piercing"://
      case "slashing"://deliberately falling through
        tell_room(main_room, attacker->QCN + "'s attack penetrates the i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^"
        +"%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void"
        +"%^RESET%^ to strike the creature in its %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^BOLD%^%^WHITE%^e%^RESET%^.", attacker);
        tell_object(attacker, "Your attack penetrates the i%^RESET%^n"
        +"%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^"
        +"%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^"
        +"%^BLUE%^n%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^"
        +"%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void"
        +"%^RESET%^ to strike the creature in its %^BOLD%^%^WHITE%^e"
        +"%^BLUE%^y%^BOLD%^%^WHITE%^e");
        break;
      case "mental":
        tell_object(attacker, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        victim->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, attacker->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + attacker->QP + "head with both hands.", attacker);
        attacker->cause_typed_damage(attacker, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    case "first tentacle":  //
    case "second tentacle": //
    case "third tentacle":  //
    case "fourth tentacle": //
    case "fifth tentacle":  //
    case "sixth tentacle":  //
    case "seventh tentacle":// deliberately falling through
      switch (damage_type){
      case "fire":
      case "cold":
        if (mucus >0){
          tell_room(main_room, "%^BOLD%^%^CYAN%^The %^WHITE%^cold%^CYAN%^ creeps"
          +" into %^GREEN%^sl%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^m%^BLACK%^e"
          +" %^CYAN%^coating the %^BOLD%^%^BLACK%^tentacle%^CYAN%^,"
          +" fr%^WHITE%^ee%^CYAN%^z%^RESET%^i%^BOLD%^%^CYAN%^ng it!");
          if (result > mucus){
            result -= mucus;
            frozen_mucus += mucus;
            mucus = 0;
            tell_room(main_room, "%^BOLD%^%^GREEN%^The%^RESET%^%^MAGENTA%^ mucus"
              +"%^BOLD%^%^GREEN%^ is completely %^BOLD%^%^CYAN%^fr%^BOLD%^"
              +"%^WHITE%^o%^CYAN%^z%^WHITE%^e%^CYAN%^n%^GREEN%^!");
          } else {
            mucus -= result;
            frozen_mucus += result;
            result = 0;
            ratio = frozen_mucus*100 / (frozen_mucus + mucus);
            if (ratio<=25){
              how_much = "less than a quarter";
            }
            if (ratio >25 && ratio <=50){
              how_much = "nearly half";
            }
            if (ratio >50 && ratio <=75){
              how_much = "more than half";
            }
            if (ratio >75){
              how_much = "almost completely";
            }
            tell_room(main_room, "%^BOLD%^%^GREEN%^The%^RESET%^%^MAGENTA%^ mucus"
              +"%^BOLD%^%^GREEN%^ is "+ how_much + " %^BOLD%^%^CYAN%^fr"
              +"%^BOLD%^%^WHITE%^o%^CYAN%^z%^WHITE%^e%^CYAN%^n%^GREEN%^!");
          }
        }
        break;
      case "electricity":
        if (mucus/10 > result){
          tell_room(main_room, "%^BOLD%^%^GREEN%^The %^BOLD%^%^YELLOW%^electricity"
            +" %^RESET%^disperses %^BOLD%^%^GREN%^harmlessly through the"
            +" %^RESET%^%^GREEN%^sl%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^my"
            +" %^RESET%^%^MAGENTA%^mucus");
          result = 0;
        }
        if (mucus > 0){
          result -= mucus/10;
          tell_room(main_room, "The %^BOLD%^%^YELLOW%^electricity%^RESET%^ is"
            +" partially dispersed by the %^RESET%^%^GREEN%^sl%^BOLD%^"
            +"%^GREEN%^i%^RESET%^%^GREEN%^my %^RESET%^%^MAGENTA%^mucus");
        }
        if (skin/10 > result){
          tell_room(main_room, "%^BOLD%^%^BLACK%^The %^BOLD%^%^YELLOW%^"
            +"elextricity %^BOLD%^%^BLACK%^is absorbed by the creature's"
            +" thick, %^RESET%^%^MAGENTA%^rubbery"
            +" sk%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n");
          result = 0;
        }
        if (skin > 0){
          result -= skin/10;
          tell_room(main_room, "The %^BOLD%^%^YELLOW%^eletricity"
            +" %^RESET%^is partially absorbed by the creature's thick,"
            +" %^RESET%^%^MAGENTA%^rubbery sk%^BOLD%^%^BLACK%^i%^RESET%"
            +"^%^MAGENTA%^n");
        }
        break;
      case "acid":
        if (mucus >0){
          if (mucus - result < 0){
            result -= mucus;
            mucus = 0;
            tell_room(main_room,"%^ORANGE%^The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
              +"%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^eats away the last"
              +" of the %^GREEN%^sl%^BOLD%^i%^RESET%^%^GREEN%^my%^RESET%^"
              +" %^MAGENTA%^mucus%^RESET%^%^ORANGE%^ covering the"
              +" creature's skin.");
          } else {
            mucus -= result;
            result = 0;
            tell_room(main_room,"The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
              +"%^BOLD%^%^BLACK%^d %^RESET%^eats away at"
              +" the %^GREEN%^sl%^BOLD%^i%^RESET%^%^GREEN%^my%^RESET%^"
              +" %^MAGENTA%^mucus%^RESET%^ covering the"
              +" creature's skin.");
          }
        }
        if (random(SURFACE_AREA)<=skin){
          tell_room(main_room, "The %^BOLD%^%^BLACK%^ac%^GREEN%^i"
            +"%^BOLD%^%^BLACK%^d %^RESET%^eats away at"
            +" the creature's thick, %^BOLD%^%^BLACK%^rubbery %^RESET%^"
            +"%^MAGENTA%^s%^BOLD%^%^BLACK%^k%^RESET%^%^MAGENTA%^i"
            +"%^BOLD%^%^BLACK%^n%^RESET%^.");
          if (skin >result){
            skin -= result;
            result = 0;
          } else {
            skin = 0;
            result = 0;
            tell_room(main_room, "The last of the %^BOLD%^%^BLACK%^sk%^RESET%^"
              +"%^MAGENTA%^i%^BOLD%^%^BLACK%^n %^RESET%^has %^GREEN%^d"
              +"%^BOLD%^i%^RESET%^%^GREEN%^ss%^BOLD%^o%^RESET%^%^GREEN%^"
              +"lv%^BOLD%^e%^RESET%^%^GREEN%^d%^RESET%^!");
          }
        } else {
          tell_room(main_room, "The %^BOLD%^%^BLACK%^ac%^GREEN%^i%^BOLD%^"
            +"%^BLACK%^d %^RESET%^runs into gaps in the creature's skin,"
            +" and it %^BOLD%^%^CYAN%^flinches%^RESET%^ in %^BOLD%^"
            +"%^RED%^pain");
        }
        break;
      case "sonic":
        tell_room(main_room, "%^BLUE%^The %^RESET%^sound%^BLUE%^ is%^RESET%^"
          +" absorbed harmlessly%^BLUE%^ by the creature's %^BOLD%^"
          +"%^BLACK%^tentacles%^RESET%^");
        result = 0;
        break;
      case "untyped":
      case "force":
      case "bludgeoning":
        if (frozen_mucus>0){
          if (random(SURFACE_AREA)<=frozen_mucus){
            if (result >= frozen_mucus){
              result -= frozen_mucus;
              frozen_mucus = 0;
              tell_room(main_room, "%^BOLD%^%^CYAN%^The last of the%^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^flies off, as " + victim->QCN + "%^BOLD%^"
                +"%^CYAN%^'s attack smashes it off the creature's"
                +" %^BOLD%^%^BLACK%^tentacle%^CYAN%^!", victim);
              tell_object(victim, "%^BOLD%^%^CYAN%^The last of the"
                +" %^BOLD%^%^WHITE%^frozen%^RESET%^%^MAGENTA%^ mucus"
                +" %^BOLD%^%^CYAN%^flies off, as your attack smashes"
                +" it off the creature's %^BOLD%^%^BLACK%^tentacle"
                +"%^CYAN%^!");
            } else {
              frozen_mucus -= result;
              result = 0;
              tell_room(main_room, "%^BOLD%^%^CYAN%^Shards of %^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^fly off, as " + victim->QCN + "%^BOLD%^"
                +"%^CYAN%^'s attack smashes it from the creature's"
                +" %^BOLD%^%^BLACK%^tentacle%^CYAN%^!", victim);
              tell_object(victim, "%^BOLD%^%^CYAN%^Shards of %^BOLD%^"
                +"%^WHITE%^ frozen%^RESET%^%^MAGENTA%^ mucus%^BOLD%^"
                +" %^CYAN%^fly off, as your  attack smashes it from"
                +" the creature's %^BOLD%^%^BLACK%^tentacle"
                +"%^CYAN%^!");
            }
          }
          if (random(SURFACE_AREA)<= skin){
            tell_room("The attack bounces off the creature's %^BOLD%^"
              +"%^BLACK%^thick, rubbery sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^");
            result = 0;
          }
        }
        break;
      case "piercing"://
      case "slashing"://
      case "silver"://
      case "cold iron"://deliberately falling through
        if (random(SURFACE_AREA)<=mucus){
          tell_room(main_room, victim->QCN + "'s attack is clogged up in the"
            +" %^MAGENTA%^putrid %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
            +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^s"
            +"%^RESET%^ covering the creature's %^BOLD%^%^BLACK%^sk"
            +"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n%^RESET%^."
              , victim);
          tell_object(victim,  "Your attack is clogged up in the"
            +" %^MAGENTA%^putrid %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
            +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^s"
            +"%^RESET%^ covering the creature's %^BOLD%^%^BLACK%^sk"
            +"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n%^RESET%^.");
          result = 0;
        } else {
          if (result > skin / 10){
            tell_room(main_room, victim->QCN + "'s attack cuts through the"
              +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^, damaging the %^BOLD%^"
              +"%^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^e"
              +"%^MAGENTA%^sh %^RESET%^beneath.", victim);
            tell_object(victim, "Your attack cuts through the"
              +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^, damaging the %^BOLD%^"
              +"%^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^e"
              +"%^MAGENTA%^sh %^RESET%^beneath.");
            skin -= result;
            if (skin > 0){
              result -= skin/10;
            } else {
              tell_room(main_room, "%^BOLD%^%^GREEN%^The last of the"
                +" creature's %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^"
                +"i%^BOLD%^%^BLACK%^n %^RESET%^falls away");
              skin = 0;
            }
          } else {
            tell_room(main_room, victim->QCN + "'s attack bounces off the"
              +" creature's thick, %^BOLD%^%^BLACK%^rubbery%^RESET%^"
              +" %^MAGENTA%^skin");
            result = 0;
          }
        }
        break;
      case "positive energy":
        tell_room(main_room, "The creature recoils from the %^BOLD%^"
          +"%^WHITE%^positive energy%^RESET%^, but seems mostly"
          +" unharmed");
          result = result/2;
        break;
      case "negative energy":
        tell_room(main_room, "The creature seems almost entirely"
          +" unaffected by the %^BOLD%^%^BLACK%^negative energy"
          +"%^RESET%^.");
          result = result/4;
        break;
      case "divine":
        tell_room(main_room, "As a being from %^BLUE%^Elsewhere%^RESET%^,"
          +" the creature seems %^BOLD%^%^BLUE%^resistant%^RESET%^ to"
          +" the power of the %^MAGENTA%^Gods%^RESET%^ of this"
          +" universe!");
          result = result/2;
        break;
      case "mental":
        tell_object(victim, "As you turn your power toward the"
          +" %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e"
          +"%^MAGENTA%^r%^BLUE%^ed%^RESET%^, your mind is %^BOLD%^"
          +"%^RED%^assaulted%^RESET%^ with %^BOLD%^%^GREEN%^h"
          +"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^"
          +"o%^BOLD%^%^GREEN%^rs%^RESET%^ beyond your imagining.");
        victim->set_paralyzed(10+ random(10), "%^BOLD%^%^YELLOW%^"
          +"Your mind is reeling!");
        tell_room(main_room, victim->QCN + " %^BOLD%^%^RED%^reels back,"
          +" holding " + victim->QP + "head with both hands.", victim);
        victim->cause_typed_damage(TO, "head", result, "mental");
        result = 0;
        break;
      }
      break;
    }
  }
  start_hp = query_hp();
  report ("Final damage taken: " + result + " Limb:  " + limb);
  report ("starting hp: " + start_hp);
  do_damage(limb,result);
  relaying = 0;
  relay_room = 0;
}

int do_damage(string limb, int damage){
  int result, start_hp, len;
  string room_name;
  object main_room;
  start_hp = query_hp();
  report ("Do damage. Start hp: " + start_hp);
  result = ::do_damage(limb, damage);
  if (interact("tentacle", limb)){
    report ("ouchie tentacle!");
    hurt_tentacle(limb, result);
  }
//  ::cause_typed_damage(victim, limb , result, damage_type);
  if (relaying ==1){
    report ("relaying damage");
    main_room = relay_room;
  } else {
    report ("direct damage");
    main_room = ETO;
  }
  len = strlen(TECVOID + "inner_void");
  room_name = file_name(main_room);
  report ("Final hp: " + query_hp());
  if (start_hp >= query_max_hp()/2 && query_hp() < query_max_hp()/2
    && (strlen(room_name)>=len
    && room_name[0..len-1] != TECVOID + "inner_void"||strlen(room_name)<len)){
    report ("%^BOLD%^%^MAGENTA%^I have taken lots of damage. Time to %^GREEN%^RETREAT");
    retreat();
  }  else {
    report ("No need to retreat!");
    report("start hp: " + start_hp + "  max_hp: " + query_max_hp() + "strlen(room_name): " + strlen(room_name) + "  room_name: " + room_name);
 }
  if (strlen(room_name)>=len
        && room_name[0..len-1] != TECVOID + "inner_void"){
    if(start_hp >= query_max_hp()/4){
      if (query_hp() < query_max_hp()/4){
        if (tentacles_withdrawn == 0){
          withdraw_tentacles();
        }
      }
    }
  }

  if (start_hp >= 2600 && query_hp() < 2600){
    defeat1();
  }
  if (start_hp >= 2200 && query_hp() < 2200){
    defeat2();
  }
  if (start_hp >= 1900 && query_hp() < 1900){
    defeat3();
  }
  if (start_hp >= 1600 && query_hp() < 1600){
    defeat4();
  }
  if (start_hp >= 1300 && query_hp() < 1300){
    defeat5();
  }
  if (start_hp >= 1000 && query_hp() < 1000){
    defeat6();
  }

}

void tell_void(string str){
  object inner_void, outer_void;
  string rm_name;
  int i;
  for (i=0;i<16;i++){
    if (i<9){
      rm_name = TECVOID + "inner_void" + i;
      inner_void = find_object_or_load(rm_name);
      if (objectp(inner_void)){
        tell_room(inner_void, str);
      }
    }
    if (i>0){
      rm_name = TECVOID + "outer_void" + i;
      outer_void = find_object_or_load(rm_name);
      if (objectp(outer_void)){
        tell_room(outer_void, str);
      }
    }
  }
}

void distribute_attacks(){
  object clone, *attackers;
  int i, count, num_attackers, total_attackers, attacks;
  count = sizeof(clones);
  if (!objectp(ETO) || !ETO->is_vacuum()){
    set_attacks_num(7);
    return;
  }
  if (count<1){
    set_attacks_num(12);
    return;
  }
  attackers = query_attackers();
  total_attackers = sizeof(attackers);
  for (i=0;i<count;i++){
    if (objectp(clones[i])){
      attackers = clones[i]->query_attackers();
      num_attackers = sizeof(attackers);
      total_attackers += num_attackers;
    }
  }
  attackers = query_attackers();
  num_attackers = sizeof(attackers);
  if (num_attackers>=total_attackers){
    return;
  }
  attacks = (num_attackers*12/total_attackers) +1;
  set_attacks_num(attacks);
  for(i=0;i<count;i++){
    if (!objectp(clones[i])){
      continue;
    }
    attackers = clones[i]->query_attackers();
    num_attackers = sizeof(attackers);
    if (num_attackers<1){
      continue;
    }
    attacks = (num_attackers*12/total_attackers) +1;
    clones[i]->set_attacks_num(attacks);
  }
}


void defeat(object targ){
  object who, * party_members, owner;
  string party;
  int i, count;
  who = query_current_attacker();
  owner = who->query_property("minion");
  if (objectp(owner)){
    who = owner;
  }
  party = PARTY_D->party_member(who);
  if (stringp(party)){
    party_members = PARTY_D->query_party_members(party);
  }
  tell_void("With a final, defeated scream, " + query_short()
    + " starts to fade, backing up further into the void than you can"
    + " reach.");
  ::die(targ);
  return;
}

void defeat9(object room, string* exits){
  object rift;
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^WHITE%^More and more %^ORANGE%^tentacles"
  +" %^WHITE%^reach from the darkness, swarming over the %^RESET%^"
  +"%^RESET%^%^B_BLUE%^%^MAGENTA%^U%^BOLD%^%^BLACK%^n"
  +"%^RESET%^%^B_BLUE%^%^MAGENTA%^f%^BOLD%^%^BLACK%^e%^RESET%^"
  +"%^B_BLUE%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^"
  +"%^MAGENTA%^r%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^%^MAGENTA%^d"
  +"%^WHITE%^'s weakened, struggling"
  +" form. The mass writhes as a whole as the tentacles appear to be"
  +" ripping chunks of the %^RESET%^%^B_BLUE%^%^MAGENTA%^U%^BOLD%^%^BLACK%^n"
  +"%^RESET%^%^B_BLUE%^%^MAGENTA%^f%^BOLD%^%^BLACK%^e%^RESET%^"
  +"%^B_BLUE%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^"
  +"%^MAGENTA%^r%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^%^MAGENTA%^d"
  +"%^WHITE%^'s %^BOLD%^%^MAGENTA%^fl%^RESET%^%^B_BLUE%^%^ORANGE%^"
  +"e%^BOLD%^%^MAGENTA%^sh %^RESET%^%^B_BLUE%^%^WHITE%^from its body in an"
  +" apparent feeding frenzy.");
  if (objectp(room)){
    room->set_had_players(1);
    rift = present("rent", room);
    if (objectp(rift)){
      tell_void(room, "With a %^BOLD%^%^BLUE%^rush%^RESET%^, the %^BOLD%^"
        +"%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ft%^RESET%^ opens up again!");
      tell_void("With a %^BOLD%^%^BLUE%^rush%^RESET%^, the %^BOLD%^"
        +"%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ft%^RESET%^ opens up again!"
        +" The %^BOLD%^%^WHITE%^a%^CYAN%^i%^WHITE%^r %^RESET%^rushes out of"
        +" the %^BLUE%^void%^RESET%^!");
      rift->set_closed(0);
      ETO->add_exit(file_name(room), "out");
      ETO->set_vacuum(1);
    }
  }
}

void defeat8(object room, string* exits){
  if (objectp(room)){
    room->set_had_players(1);
  }
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^WHITE%^The temporary %^BLACK%^silence%^WHITE%^"
    +" is broken, and the %^B_BLUE%^%^BOLD%^%^WHITE%^hooting, hollering"
    +" voices%^RESET%^%^B_BLUE%^%^WHITE%^ erupt in a maddening%^YELLOW%^"
    +" cacophony %^RESET%^%^B_BLUE%^%^WHITE%^of sound. A %^ORANGE%^tentacle"
    +" %^WHITE%^appears from the darkness, its suckers attaching to the"
    +" %^RESET%^%^B_BLUE%^%^MAGENTA%^U%^BOLD%^%^BLACK%^n"
    +"%^RESET%^%^B_BLUE%^%^MAGENTA%^f%^BOLD%^%^BLACK%^e%^RESET%^"
    +"%^B_BLUE%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^"
    +"%^MAGENTA%^r%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^%^MAGENTA%^d%^WHITE%^'s"
    +" wounded form. Then another does the same. And another.");
  call_out("defeat9", 3, room);
}

void defeat7(object room, string* exits){
  if (objectp(room)){
    room->set_had_players(1);
  }
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void(
    "%^B_BLUE%^The %^RESET%^%^B_BLUE%^%^MAGENTA%^U%^BOLD%^%^BLACK%^n"
    +"%^RESET%^%^B_BLUE%^%^MAGENTA%^f%^BOLD%^%^BLACK%^e%^RESET%^"
    +"%^B_BLUE%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^"
    +"%^MAGENTA%^r%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^%^MAGENTA%^d"
    +" %^BOLD%^%^WHITE%^retreats out of range of your attacks, its"
    +" %^RED%^e%^BLUE%^y%^WHITE%^e%^RED%^s %^BOLD%^%^WHITE%^roving"
    +" desperately in every direction.");

  call_out("defeat8", 3, room);
}

void defeat6(){
  object * critters, ob, room, rift, attacker;
  string * exits;
  int i, count;
  if (!objectp(ETO)) return;
  invincible = 1;
  if (file_name(ETO)==JUNG_ROOM + "void"){
    room = find_object_or_load(ETO->query_exit("out"));
    if (objectp(room)){
      rift = present("rent", room);
      if (objectp(rift)){
        tell_void("A %^BOLD%^%^CYAN%^gust%^RESET%^ of %^BOLD%^%^WHITE%^"
          +"a%^CYAN%^i%^WHITE%^r%^RESET%^ whooshes into the %^BLUE%^void"
          +" %^RESET%^as the %^BOLD%^%^BLACK%^r%^BOLD%^%^YELLOW%^i%^BOLD%^"
          +"%^BLACK%^ft %^CYAN%^winks%^RESET%^ shut!");
        tell_void(room, "A %^BOLD%^%^CYAN%^gust%^RESET%^ of %^BOLD%^%^WHITE%^"
          +"a%^CYAN%^i%^WHITE%^r%^RESET%^ whooshes into the %^BLUE%^void"
          +" %^RESET%^as the %^BOLD%^%^BLACK%^r%^BOLD%^%^YELLOW%^i%^BOLD%^"
          +"%^BLACK%^ft %^CYAN%^winks%^RESET%^ shut!");
        ETO->remove_exit("out");
        ETO->set_vacuum(0);
        rift->set_closed(100);
      }
    }
  }
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void(
     "%^B_BLUE%^%^BOLD%^%^WHITE%^A sudden %^RESET%^%^B_BLUE%^"
    +"%^BLACK%^hush %^BOLD%^%^WHITE%^descends as the hoots and hollers"
    +" fall silent.");
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1) return;
  remove_property("no paralyze");
  for (i=0;i<count;i++){
    if (critters[i]->query_true_invis()){ continue; }
    critters[i]->cease_all_attacks();
    critters[i]->set_paralyzed(30, "%^BOLD%^%^CYAN%^Things are afoot!"
      +" Time seems to have stopped for you!");
    ob = present("suff_ob", critters[i]);
    if (objectp(ob)){
      ob->remove();
    }
    attacker = query_current_attacker();
    grant_quest(attacker, "%^RED%^Defeated %^RESET%^%^BLUE%^The"
     +"%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt"
     +"%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d", 21000000,
      "%^BOLD%^%^BLUE%^You gained experience for the%^RED%^"
     +" astonishing %^BLUE%^feat of driving %^RESET%^%^BLUE%^The"
     +" %^MAGENTA%^U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt"
     +"%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d%^BOLD%^%^BLUE%^"
     +" back into the %^RESET%^i%^BLUE%^n%^RESET%^ter%^BOLD%^"
     +"%^BLACK%^d%^WHITE%^i%^RESET%^%^BLUE%^m%^RESET%^en%^BOLD%^"
     +"%^BLACK%^s%^WHITE%^i%^RESET%^on%^BOLD%^%^BLACK%^a%^WHITE%^l"
     +" %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d%^BLUE%^ from"
     +" which it came, following it there and defeating it. The"
     +" %^RESET%^%^MAGENTA%^Realms %^BOLD%^%^BLUE%^are safer, and the"
     +" %^RESET%^%^ORANGE%^Gods %^BOLD%^%^BLUE%^themselves are"
     +" grateful to you.", 1);
  }
  count = sizeof(seized);
  if (count>0){
    for (i=0;i<count;i++){
      if (objectp(seized[i])){
        seized[i]->remove_property("posed");
      }
    }
  }


  call_out("defeat7", 3, room);
}
void defeat5(){
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_RED%^%^BLACK%^Another %^ORANGE%^tentacle%^BLACK%^"
    +" reaches out of the blackness, this one questing out to briefly"
    +" attach to the %^RESET%^%^B_RED%^%^BLUE%^U%^BLACK%^n%^RESET%^"
    +"%^B_RED%^%^BLUE%^f%^BLACK%^e%^RESET%^%^B_RED%^%^BLUE%^tt%^BLACK%^e"
    +"%^RESET%^%^B_RED%^%^BLUE%^r%^BLACK%^e%^RESET%^%^B_RED%^%^BLUE%^d"
    +"%^BLACK%^'s central mass. It %^BOLD%^%^RED%^%^FLASH%^pulses"
    +"%^RESET%^%^B_RED%^%^BLACK%^, as if tasting something.");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^BOLD%^%^WHITE%^The hoots grow louder yet,"
    +" sounding %^FLASH%^excited %^RESET%^%^B_BLUE%^%^BOLD%^%^WHITE%^and"
    +" %^FLASH%^frenzied.");
}

void defeat4(){
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_RED%^%^BLACK%^From out of the blackness, a %^RESET%^"
    +"%^B_RED%^%^ORANGE%^tentacle%^BLACK%^ reaches out and swipes across"
    +" the body of the %^RESET%^%^B_RED%^%^BLUE%^U%^BLACK%^n%^RESET%^"
    +"%^B_RED%^%^BLUE%^f%^BLACK%^e%^RESET%^%^B_RED%^%^BLUE%^tt%^BLACK%^e"
    +"%^RESET%^%^B_RED%^%^BLUE%^r%^BLACK%^e%^RESET%^%^B_RED%^%^BLUE%^d");
}

void defeat3(){
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^BOLD%^%^WHITE%^The %^RED%^e%^BLUE%^y"
    +"%^WHITE%^e%^RED%^s %^WHITE%^of the %^RESET%^%^B_BLUE%^%^MAGENTA%^U"
    +"%^BOLD%^%^BLACK%^n%^RESET%^%^B_BLUE%^%^MAGENTA%^f%^BOLD%^%^BLACK%^e"
    +"%^RESET%^%^B_BLUE%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^e%^RESET%^"
    +"%^B_BLUE%^%^MAGENTA%^r%^BOLD%^%^BLACK%^e%^RESET%^%^B_BLUE%^"
    +"%^MAGENTA%^d %^RESET%^%^B_BLUE%^%^MAGENTA%^BOLD%^%^WHITE%^seem to"
    +" search around in %^YELLOW%^alarm %^WHITE%^as the weird hoots and"
    +" hollers get LOUDER and CLOSER.");
}

void defeat2(){
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^BOLD%^%^WHITE%^The weird hoots and hollers"
    +" reaching through the void are growing LOUDER.");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_RED%^%^BLUE%^The U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^"
    +"tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^ed%^RESET%^%^B_RED%^ %^BOLD%^"
    +"%^WHITE%^retreats%^RESET%^%^B_RED%^ further back into the"
    +" %^BOLD%^%^BLACK%^void%^RESET%^%^B_RED%^!");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  withdraw_tentacles();
}

void defeat1(){
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("                                                        "
    +"                   ");
  tell_void("%^B_BLUE%^%^BOLD%^%^WHITE%^Through the blackness of the"
    +" void, echoes of weird hoots and hollers somehow reach your ears.");
}

void heart_beat(){
  int i, count, when, * seize_nums, waytime, mazetime, fin;
  object * seizees, * releasees, * rooms, dest_room, waystation;
  string * path, * finalpath, dest, middle_room;
  ::heart_beat();
  report ("%^BOLD%^%^CYAN%^Starting heartbeat");
  if (objectp(ETO)){
    if (present("player", ETO)){
      heartcount = 0;
    }
    ETO->set_had_players(2);
  } else {
    report("Unfettered environment is broken");
  }
  if ((objectp(ETO)&&!(int)ETO->is_vacuum()) && !random(7)){
    ooze_mucus();
  }
  report ("%^BOLD%^%^CYAN%^HEARTBEAT STAGE 2");

  if (objectp(ETO) && base_name(ETO) == TECVOID + "inner_void0"
                                             && tentacles_withdrawn == 0){
    if(random(5)>2){
      close_rift();
    }
  }
  seizees = keys(query_seized());
  count = sizeof(seizees);
  if (count>0){
    releasees = ({});
    for (i=0;i<count;i++){
      seize_nums = query_seized()[seizees[i]];
      when = time();
      if (when > seize_nums[0]){
        releasees += ({ seizees[i] });
      }
    }
  }
//  report ("dealing with seizures");
  count = sizeof(releasees);
  if (count >0){
    for (i = 0;i<count;i++){
      if (objectp(releasees[i])){
        tell_object(releasees[i], "You squirm free of the"
          +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^"
          +"nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cl"
          +"%^RESET%^e!");
        if (objectp(environment(releasees[i]))){
          tell_room(environment(releasees[i]), releasees[i]->QCN
            + " squirms free of the %^BOLD%^%^BLACK%^t%^RESET%^"
            +"e%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^"
            +"%^BLACK%^cl%^RESET%^e!", releasees[i]);
        }
      }
      release_seized(releasees[i]);
    }
  }
  if (sizeof(seizees)>0){
    return 1;  //So that he won't just wander off if he is or has been holding someone
  }
  report ("%^BOLD%^%^CYAN%^HEARTBEAT STAGE 3");
  if (last_move <time()-1){
    go_somewhere();
    last_move = time();
  }
  report ("%^BOLD%^%^BLUE%^END OF HEARTBEAT REACHED");
}

void countdown(){
  object room;
  if (!objectp(ETO)){
    return;
  }
  switch(countdown){
  case 0:
    paralyze();
    tell_room(ETO, "A %^MAGENTA%^r%^BOLD%^%^BLACK%^u%^MAGENTA%^bb%^BOLD%^%^BLACK%^"
      +"e%^MAGENTA%^ry%^RESET%^, %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u%^BOLD%^c"
      +"%^RESET%^%^GREEN%^u%^BOLD%^s-sl%^RESET%^%^GREEN%^i%^BOLD%^m"
      +"%^RESET%^%^GREEN%^e%^BOLD%^d %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e"
      +"%^BOLD%^%^BLACK%^nt%^RESET%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e"
      +"%^RESET%^ emerges from the %^MAGENTA%^rift%^RESET%^ and curls around the"
      +" edge");
    countdown ++;
    break;
  case 1:
    tell_room(ETO, "A second %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^"
      +"nt%^RESET%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e%^RESET%^ emerges, also"
      +" hooking itself around the edge of the %^BOLD%^%^BLACK%^opening%^RESET%^.");
    countdown ++;
    break;
  case 2:
    tell_room(ETO, "More and more %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e"
      +"%^BOLD%^%^BLACK%^nt%^RESET%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e"
      +"%^BOLD%^%^BLACK%^s%^RESET%^ appear, some hooking around the edges of the"
      +" %^MAGENTA%^rift%^RESET%^, and others beginning to explore the environment.");
    countdown ++;
    break;
  case 3:
    tell_room(ETO, "The %^MAGENTA%^rift%^RESET%^ begins to widen as the"
      +" %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt%^RESET%^a"
      +"%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^ push the"
      +" edges apart");
    countdown ++;
    break;
  case 4:
    tell_room(ETO, "You glimpse the astonishing bulk of the creature to whom the"
      +" %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt%^RESET%^a"
      +"%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^ belong,"
      +" lurking behind the %^MAGENTA%^rift%^RESET%^ %^BOLD%^%^BLACK%^opening%^RESET%^,"
      +" too big to pass through for now");
    countdown ++;
    break;
  case 5:
    tell_room(ETO, "As the %^MAGENTA%^rift%^RESET%^ widens further, a malevolent,"
      +" %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^i%^BOLD%^mm"
      +"%^RESET%^%^RED%^e%^BOLD%^d %^BOLD%^%^RED%^e%^BLUE%^y%^RED%^e%^RESET%^ can be"
      +" made out on the other side. While you are looking into the%^BOLD%^%^BLACK%^"
      +" abyss%^RESET%^, the %^BOLD%^%^BLACK%^abyss%^RESET%^ is staring back at you.");
    countdown ++;
    break;
  case 6:
    tell_room(ETO, "The expansion of the %^MAGENTA%^rift%^RESET%^ comes to a halt, as"
      +" if it has reached some kind of limit. It is still too small for the vast"
      +" creature on the other side to get through, but that is not a complete comfort."
      +" The %^MAGENTA%^gruesome%^RESET%^ %^BOLD%^%^RED%^e%^BLUE%^y%^RED%^e%^RESET%^"
      +" fixes on you and the %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^"
      +"nt%^RESET%^a%^BOLD%^%^BLACK%^cl%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^"
      +" attack!");
    countdown ++;
    break;
  case 7:
    unparalyze();
    set("aggressive", 31);
    invincible = 0;
    countdown ++;
    return;
    break;
  case 8:
    if (sizeof(query_attackers())<1){
      set("aggressive", 31);
      invincible = 0;
      room = find_object_or_load(ETO->query_exit("up"));
      if (objectp(room)){
        room->short_desc();
      }
      force_me("up");
    }
  }
}

void paralyze(string msg){
  object * critters;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count>0){
    for (i=0;i<sizeof(critters);i++){
      if (critters[i]==TO){
        continue;
      }
      if (critters[i]->query_true_invis()){
        tell_object(critters[i], "You are unaffected by the paralysing power of the unfolding events");
        continue;
      }
      critters[i]->set_paralyzed(500, msg);
    }
  }
}

void unparalyze(){
  object * critters;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count>0){
    for (i=0;i<sizeof(critters);i++){
      if (critters[i]==TO){
        continue;
      }
      critters[i]->remove_paralyzed();
    }
  }
}

void set_invincible(int i){
  invincible = i;
}

int query_invincible(){
  return invincible;
}

int is_invincible(){
  return invincible;
}

void report(string str){
  if (objectp(ETO) && reporting == 1){ //this is necessary, or I get reports from the base object
     "/daemon/reporter_d"->report("lujke", str);
  }
}

void go_somewhere(){
  string path, name, target_path, target_name;
  int mazetime, waytime;
  object waystation;
  report ("%^BOLD%^%^GREEN%^Go somewhere 1");
  if (!objectp(ETO) || !interact("main", base_name(TO))){
    return;
  }
  if (base_name(ETO)== "/d/shadowgate/void"){
    report ("I'm in a void. STOPPING");
    return;
  }
  if (base_name(ETO) == ROOMS + "zigzenith"){
    if (ETO->query_sacrificing()>0){
      return;
    }
    summon_spirits();
    return;
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 2");
  if (interact("city", base_name(ETO))){
    path = CITY_ROOM;
    name = base_name(ETO)[strlen(CITY_ROOM)..strlen(base_name(ETO))-1];
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 3");

  if (interact("ropebridge", base_name(ETO))){
    path = JUNG_ROOM5;
    name = "ropebridge";
    force_me("west");
    report ("exiting go_somewhere");
    return;
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 4");

  if (interact("cavern", base_name(ETO))){
    path = ROOMS;
    name = "cavern";
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 5");

  if (interact("ziggurat", base_name(ETO))){
    path = ROOMS;
    name = "ziggurat";
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 6");

  if (!stringp(path)){
    path = ETO->get_path();
    name = ETO->get_name();
  }
  report ("%^BOLD%^%^GREEN%^Go somewhere 7");

  report ("I am in a room with path: " + path + " and name: " + name);
  switch(path){
  case ROOMS:
    report ("In a ROOMS room");
    switch(name){
    case "cavern":
      report ("doing countdown");
      countdown();
      return;
      break;
    case "ziggurat":
      report ("In ziggurat room");
      target_path = ROOMS;
      target_name = "zigzenith";
    }
    report ("ERROR - I am in an unknown room. I don't know where to go!");
    return;
    break;
  case JUNG_ROOM10:
    report ("In a JUNG_ROOM10 room");
    switch(name){
    case "j_link10a":
      report ("In j_link10a");
      force_me("north");
      report ("In j_link10a");
      return;
      break;
    default:
      report ("Not in j_link10a");
      target_path = path;
      target_name = "j_link10a";
    }
    break;
  case JUNG_ROOM9:
    report ("In a JUNG_ROOM9 room");
    switch(name){
    case "j_link9a":
      report ("In j_link9a");
      force_me("west");
      report ("Exiting go_somewhere");
      return;
      break;
    default:
      report("Not in j_link9a");
      target_path = path;
      target_name = "j_link9a";
    }
    break;
  case JUNG_ROOM5:
    report ("In a JUNG_ROOM5 room");
    switch(name){
    case "j_link4a":
      report ("in j_link4a");
      force_me("west");
      report ("Exiting go_somewhere");
      return;
      break;
    default:
      report ("not in j_link4a");
      target_path = path;
      target_name = "j_link4a";
    }
    break;
  case JUNG_ROOM4:
    report ("In a JUNG_ROOM4 room");
    switch(name){
    case "city_jung14":
      report ("in city_jung14");
      force_me("southeast");
      report ("Exiting go_somewhere");
      return;
      break;
    default:
      target_path = path;
      target_name = "city_jung14";
      report ("Not in city_jung14");
    }
    break;
  case CITY_ROOM:
    report ("In a CITY_ROOM room");
    switch(name){
    case "plaza":
      report ("in plaza");
      target_path = path;
      target_name = "zigzenith";
      break;
    default:
      report ("not in plaza");
      target_path = path;
      target_name = "plaza";
      break;
    }
  }
  if (interact("jungle", path)){
    report ("path is a jungle room");
    report ("Doing short_desc");
    ETO->short_desc();
    report ("Updating exits");
    ETO->update_exits();
    mazetime = MAZE_D->query_timing(target_path);
    waytime = DEST->query_timing(target_path+target_name);
    if (waytime == 0 || mazetime>waytime ){
      report ("Waystations toward " + target_path + target_name + " either not made or not up to date. Resetting");
      report ("Waytime: " + waytime + " mazetime: " + mazetime);
      DEST->clear_waystations(target_path + target_name);
      report ("waystations cleared");
      MAZE_D->generate_waystations(target_path, target_name, 20, 3);
      report ("Waystations remade");
    }
    report ("Finding waystation");
    waystation = "/daemon/pathfinder_d"->find_waystation(ETO, target_path + target_name, 5);
    if (!objectp(waystation)){
      report ("Can't find waystation for path: " + target_path + "  target_name: " + name);
      target_name = MAZE_D->get_middle_room(target_path);
      waystation = "/daemon/pathfinder_d"->find_waystation(ETO, target_path + target_name, 5);
      if (!objectp(waystation)){
        report ("ERROR - can't find a waystation to the main target or the middle room");
        report ("Path: " + target_path + " middle room: " + target_name);
        return;
      }
    }
  } else {
    waytime = DEST->query_timing(target_path+target_name);
    if (waytime == 0) {
      DEST->clear_waystations(target_path+target_name);
      DEST->generate_waystations(target_path+target_name, 6, 3);
    }
    waystation = "/daemon/pathfinder_d"->find_waystation(ETO, target_path + target_name, 5);
    if (!objectp(waystation)){
      report ("ERROR - can't find a waystation towards " + target_path+ target_name);
      report ("Current room: " + base_name(ETO));
      return;
    }
  }
  report ("Starting walking to path: " + target_path + " name: " + target_name);
  start_walking(target_path + target_name);
  report ("End of go_somewhere");
}


void damage_spirits(){
  object * critters, * enders;
  int i, count, flag, hp;
  if (!objectp(ETO) || base_name(ETO) != ROOMS + "zigzenith"){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1){
    return;
  }
  flag = 0;
  enders = ({});
  for (i=0;i<count;i++){
    if (critters[i]->id("tecqumin") || critters[i]->id("ghost")){
      flag = 1;
      hp = critters[i]->query_hp();
      if (hp<250){
        enders += ({critters[i]});
      } else {
        critters[i]->set_hp(hp-250);
      }
    }
  }
  if (flag ==1){
    tell_room(ETO, "%^BOLD%^%^BLACK%^All the %^CYAN%^spirits%^BOLD%^%^BLACK%^"
      +" present fl%^RESET%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^r"
      +" and are %^BOLD%^%^WHITE%^diminished%^BOLD%^%^BLACK%^ as the"
      +" %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^"
      +"e%^BLUE%^d %^RESET%^absorbs a portion of their power.");
  }
  count = sizeof(enders);
  if (count<1){
    return;
  }
  for (i=0;i<count;i++){
    enders[i]->set_hp(0);
    enders[i]->die();
  }
}

void enhance(){
  int hp;
  if (victory>0){
    return;
  }
  if (objectp(ETO)){
    tell_room(ETO, "The %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r"
        +"%^MAGENTA%^e%^BLUE%^d%^RESET%^ %^RED%^pulses%^RESET%^ and grows in power.");
  }
  set_hp(query_hp() + 200);
  spirits_absorbed += 1;
  if (spirits_absorbed>29){
    victory = 1;
    victory();
  }
}

void summon_more_spirits(int how_many){
  int i, j, rnd;
  string * room_names, *excluded_locations;
  object room, ghost;
  report ("summoning MORE spirits");
  if (how_many<1){
    report ("How_many < 1. Not summoning any spirits");
    return;
  }
  excluded_locations = ({CITY_ROOM + "ragged_road01",
      CITY_ROOM + "city_jung01", CITY_ROOM + "city_jung02",
      CITY_ROOM + "canalbank01", CITY_ROOM + "canalbank03" });
  room_names = get_dir(CITY_ROOM);
  room_names -= excluded_locations;
  for (i=0;i<how_many;i++){
    report ("Summoning spirit " + i);
    while (!objectp(room) && j<10){
      rnd = random(sizeof(room_names));
      report ("Trying to load room: " + room_names[rnd]);
      room = find_object_or_load(CITY_ROOM + room_names[rnd]);
      j++;
    }
    if (!objectp(room)){
      report ("Couldn't find a room to put it in.");
      continue;
    }
    ghost = present("ghost", room);
    if (!objectp(ghost) || ghost->is_walking()){
      ghost = present("ghost 2", room);
    }
    if (!objectp(ghost) || ghost->is_walking()){
      ghost = present("ghost 3", room);
    }
    if (!objectp(ghost) || ghost->is_walking()){ //Make new ghost if all the ones in the room are already heading to the zenith
      if (i%2 >0){
        ghost = new (MOB + "ghost_warrior");
      } else {
        ghost = new (MOB + "ghost_priest");
      }
    }
    ghost->move(room);
    ghost->er(0);
    ghost->start_walking(ROOMS + "zigzenith");
    room  = 0;
    j= 0;
  }
}

void absorb_spirit3(object spirit){
  string emote;
  if (!objectp(ETO)||!objectp(spirit)||!present(spirit, ETO)){
    absorbing = 0;
    absorb_spirit();
    return;
  }
  spirit->force_me("emote %^CYAN%^gives a despairing cry as its %^BOLD%^%^BLUE%^essence%^RESET%^%^CYAN%^ is sucked into "+ query_short() + "%^RESET%^%^CYAN%^ and absorbed");
  power_absorbed ++;
  set_hp(query_hp() + 150);
  if (query_hp()>query_max_hp()){
    set_hp( query_max_hp());
  }
  spirit->move("/d/shadowgate/void");
  absorbing = 0;
  if(power_absorbed>30){
    victory(); //Muahahaha
  }
}

void absorb_spirit2(object spirit){
  string emote;
  if (!objectp(ETO)||!objectp(spirit)||!present(spirit, ETO)){
    absorbing = 0;
    absorb_spirit();
    return;
  }
  switch (lower_case(spirit->query_name())){
  case "jontar":
    emote = "'s%^RESET%^%^CYAN%^ eyes widen as his form blurs and stretches as it seems to be sucked toward " + query_short() + ". %^BOLD%^%^CYAN%^'Oh, '%^RESET%^%^CYAN%^ he says. %^BOLD%^'So this is what it is like...'";
    break;
  case "mehaq":
    emote = "%^RESET%^%^CYAN%^ draws herself up straight and appears to fight against a force that tries to stretch her form toward " + query_short() + "%^RESET%^%^CYAN%^. But it is no use...";
    break;
  case "taluc":
    emote = "'s%^RESET%^%^CYAN%^ eyes widen in alarm as his form blurs and stretches as it seems to be sucked toward " + query_short() + ". %^BOLD%^%^BLUE%^'My Lord! No!'%^RESET%^%^CYAN%^ he cries. %^BOLD%^%^BLUE%^'Not me, you promised! The others, not MEEEeeee...'";
    break;
  case "epithon":
    emote = "'s %^RESET%^%^CYAN%^face curls into a snarl as his form blurs and stretches as it seems to be sucked toward " + query_short() + "%^RESET%^%^CYAN%^. He grits his teeth and appears to be trying to resist, to no avail...";
  case "apothecary":
    emote = "%^RESET%^%^CYAN%^ whimpers quietly as his form blurs and stretches, seeming to be sucked toward " + query_short() + "%^RESET%^%^CYAN%^.";
    break;
  case "guamansuri":
    emote = "%^RESET%^%^CYAN%^ braces himself as his form blurs and stretches, seeming to be sucked toward " + query_short() + "%^RESET%^%^CYAN%^. As it becomes obviously inevitable, he gives up and launches himself sword first toward it.";
  default:
    emote = "%^RESET%^%^CYAN%^ gives a cry of anguish as its form blurs and stretches as it seems to be sucked toward " + query_short();
    break;
  }
  tell_room(ETO, spirit->query_short() + emote);
  absorbing  = 2;
  call_out( "absorb_spirit3", 2, spirit);
}

void absorb_spirit(){
  object spirit;
  if (!objectp(ETO)){
    return;
  }
  if (absorbing >0){
    return;
  }
  spirit = present("ghost", ETO);
  if (!objectp(spirit)){
    spirit = present("tecqumin", ETO);
  }
  if (!objectp(spirit)){
    force_me("emote looks disappointed");
    return;
  }
  tell_room(ETO, query_short() + "%^RESET%^%^RED%^ casts the gaze of one of its many r%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^mm%^RESET%^%^RED%^e%^BOLD%^d %^WHITE%^e%^BLUE%^y%^WHITE%^es %^RESET%^%^RED%^upon " + spirit->query_short() + "%^RESET%^%^RED%^ and starts drawing " + spirit->QO + " towards it");
  absorbing = 1;
  call_out("absorb_spirit2", 2, spirit);
}

void summon_spirits(){
  int i, num,  count, num_to_summon, num_existing, num_to_create;
  object npc, room, room2, * tecqumin, * npcs;
  string * npc_names, * npc_locations, *dead_npcs;
  if (spirits_absorbed>30){
    return;
  }
  if (present("ghost", ETO) || present("tecqumin", ETO)){
    absorb_spirit();
     return;
  }
  if (last_summoned > 0 && time()<last_summoned + 7){
    return;
  }
  if (last_summoned > time() - 500){
    summon_more_spirits(6);
    last_summoned = time();
    return;
  }
  tell_room(ETO, query_short() + " %^MAGENTA%^lets out a %^BOLD%^%^CYAN%^quivering%^RESET%^%^MAGENTA%^, %^BOLD%^high pitched%^RESET%^%^MAGENTA%^ sound of calling");
  last_summoned = time();
  report ("summoning some spirits");
  tecqumin = children(MOB + "ghost_warrior");
  tecqumin += children(MOB + "ghost_priest");
  npc_names = ({"jontar", "taluc", "empress", "apothecary", "epithon"});
  npc_locations = ({CITY_ROOM + "throne_room",
     CITY_ROOM + "taluc_room", CITY_ROOM + "mehaq_room",
     CITY_ROOM + "grand_interior02", ROOMS + "jontar_room"});
  npcs = ({});
  dead_npcs = ({});
  count = sizeof(npc_names);
  for (i=0;i<count;i++){
    report ("loading mob: " + npc_names[i]);
    npc = find_object(MOB + npc_names[i]);
    if (objectp(npc)){
      report ("mob: " + npc_names[i] + " is loaded");
      room = environment(npc);
      if (objectp(room)){  //check if they are somewhere in the city; if not, move them back to their start room.
        report ("mob: " + npc_names[i] + " is in valid environment: " + base_name(room));
        if (!interact("city", base_name(room)) && !interact("zig", base_name(room))
             && !interact("step", base_name(room))){
          room2 = find_object_or_load(npc_locations[i]);
          if (!objectp(room2)){
            report (npc_locations[i] + " is not a valid room");
            continue;
          } else {
            report ("moving " + npc->query_name() + " to " + base_name(room));
            tell_room(room, "the %^BOLD%^%^WHITE%^spirit%^RESET%^ of "
              + npc->query_name() + " %^RESET%^fl%^BOLD%^%^WHITE%^i%^RESET%^ckers"
              +" and disappears");
            tell_room(room2, npc->query_name() +"%^RESET%^ appears from nowhere");
            npc->move(room2);
          }
        }
        report ("Adding " + npc->query_name() + " to list of npcs");
        tecqumin += ({npc});
      } else {
        report ("Adding " + npc_names[i] + " to list of DEAD NPCs");
        dead_npcs += ({ npc_names[i]});
      }
    } else {
      report ("Adding " + npc_names[i] + " to list of DEAD NPCs");
      dead_npcs += ({ npc_names[i]});
    }
  }
  count = sizeof(dead_npcs);
  if (count>0){
    report ("There is at least one dead npc on the list");
    for (i=0;i<count;i++){
      num = member_array(dead_npcs[i], npc_names);
      room = find_object_or_load(npc_locations[num]);
      if (!objectp(room)){
        continue;
      }
      report ("Making a new " + dead_npcs[i]);
      npc = new (MOB + dead_npcs[i]);
      if (objectp(npc)){
        report ( dead_npcs[i] + " being moved to " + base_name(room));
        npc->move(room);
        npcs += ({npc});
      } else {
        report ("Dead npc failed to load: " + MOB + dead_npcs[i]);
      }
    }
  }
  tecqumin += npcs;
  count = sizeof(tecqumin);
  if (count>0){
    report ("There is at least one npc to get walking");
    for (i=0;i<count;i++){
      report ("Starting " + tecqumin[i]->query_name() + " walking to " + ROOMS + "zigzenith");
      tecqumin[i]->start_walking(ROOMS + "zigzenith");
    }
  }
  if (count < 10){
    summon_more_spirits(5);
  }
}

void relocate(){
  object room;
  int r;
  r = random(40)+1;
  room = find_object_or_load(JUNG_ROOM5 + "j_maze" + r);
  if (objectp(room)){
    tell_room(ETO, "The Unfettered, baffled by its location, crawls back into its rift, closing it off before reappearing somewhere in the nearby area");
    move(room);
  }
 // call_out("relocate", 1);
}

string choose_destination(){
  string * poss_dests, dest, *path, *finalpath, dest_name;
  int i, count, waytime, mazetime;
  object * rooms, dest_room, waystation;
//  report ("Choosing destination");
  poss_dests = ({ JUNG_ROOM5 + "j_maze10", JUNG_ROOM5+ "j_maze20", JUNG_ROOM5 + "j_maze30", JUNG_ROOM5 + "j_maze40"  });
  count = sizeof(poss_dests);
  dest_name = "j_link4a";
  dest = JUNG_ROOM5 + dest_name;
  waytime = DEST->query_timing(dest);
  mazetime = MAZE_D->query_timing(JUNG_ROOM5);
//  report( "Waytime: ");
//  report (""+ waytime);
//  report ( " Mazetime: ");
//  report (""+ mazetime);
  if (waytime == 0 || mazetime >= waytime){
//    tell_room(ETO,  "regenerating waystations");
    // Above check makes sure the next lag inducing maneuvre only happens
    // if the maze has been reset since the waystations were set up
//    tell_room(ETO,  "Generating new waystations to : " + dest);
    DEST->clear_waystations(dest);
    MAZE_D->generate_waystations(JUNG_ROOM5, dest_name, 20, 3);
  } else {
//    tell_room(ETO, "%^BOLD%^%^YELLOW%^No need to update waystations");
  }

  cleanse_waystations(dest);
  waystation = "/daemon/pathfinder_d.c"->find_waystation(ETO, dest,5);
  if (objectp(waystation)){
//    tell_room(ETO, "Successfully found a waystation towards " + dest + ": " + base_name(waystation));
    return dest;
  }

//  tell_room(ETO, "%^BOLD%^%^RED%^No waystation available to: %^RESET%^" + dest + ". %^BOLD%^%^BLUE%^Looking for middle room");

  dest_name = MAZE_D->get_middle_room(JUNG_ROOM5);
  dest = JUNG_ROOM5 + dest_name;

  waytime = DEST->query_timing(dest);
  mazetime = MAZE_D->query_timing(JUNG_ROOM5);

//  report( "Waytime: ");
//  report (""+ waytime);
//  report ( " Mazetime: ");
//  report (""+ mazetime);
  if (waytime == 0 || mazetime >= waytime){
//    tell_room(ETO,  "regenerating waystations");
    // Above check makes sure the next lag inducing maneuvre only happens
    // if the maze has been reset since the waystations were set up
//    tell_room(ETO,  "Generating new waystations to : " + dest);
    DEST->clear_waystations(dest);
    MAZE_D->generate_waystations(JUNG_ROOM5, dest_name,20, 3);
  } else {
//    tell_room(ETO, "%^BOLD%^%^YELLOW%^No need to update waystations");

  }

//  tell_room(ETO, "%^BOLD%^%^RED%^No waystation available to: %^RESET%^" + dest + ". %^BOLD%^%^BLUE%^Looking for next location");

  dest = JUNG_ROOM5 + MAZE_D->get_middle_room(JUNG_ROOM5);
  cleanse_waystations(dest);
  waystation = "/daemon/pathfinder_d.c"->find_waystation(ETO, dest,5);
  if (objectp(waystation)){
//    tell_room(ETO, "Successfully found a waystation towards " + dest + ": " + base_name(waystation));
    return dest;
  }

  for (i=0;i<count;i++){
    tell_room(ETO, "Checking potential destination: ");
    tell_room(ETO, poss_dests[i]);
    if (member_array(poss_dests[i], destinations_visited)==-1){
///      tell_room(ETO, poss_dests[i] + " not already visited");
      destinations_visited += ({poss_dests[i]});
      dest = poss_dests[i];
      waytime = DEST->query_timing(dest);
      mazetime = MAZE_D->query_timing(JUNG_ROOM5);
      if (intp(waytime)) tell_room(ETO, "waytime is an integer");
      if (intp(mazetime)) tell_room(ETO, "mazetime is an integer");
      if (mapp(waytime)) tell_room(ETO, "waytime is a mapping");
      if (mapp(mazetime)) tell_room(ETO, "mazetime is a mapping");
 //     tell_room(ETO, "Waytime: " + waytime + "  Mazetime: " + mazetime);
      if (waytime == 0 || mazetime >= waytime){
     // Above check makes sure the next lag inducing maneuvre only happens
      // if the maze has been reset since the waystations were set up
        tell_room(ETO, "%^BOLD%^%^YELLOW%^Generating new waystations to : " + dest);
        DEST->clear_waystations(dest);
        dest_name = dest[strlen(JUNG_ROOM5)..strlen(dest)-1];
        MAZE_D->generate_waystations(JUNG_ROOM5, dest_name ,20 , 3);
      } else {
 //       tell_room(ETO, "%^BOLD%^%^GREEN%^No need to generate new waystations to : " + JUNG_ROOM5 + dest_name);
      }
      cleanse_waystations(dest);
      waystation = "/daemon/pathfinder_d.c"->find_waystation(ETO, dest,5);
      if (!objectp(waystation)){
 //       tell_room(ETO, "%^BOLD%^%^RED%^No waystation available to: %^RESET%^" + dest + ". %^BOLD%^%^BLUE%^Looking for next location");
        continue;
      }
      return dest;
    }
  }
//  report("Unable to select a destination.");
  stop_walking();
//  wander_when_lost();
}

void cleanse_waystations(string dest){
  int i, count;
  mapping map;
  string * ks;
  map = DEST->query_waystations(dest);
  ks = keys(map);
  count = sizeof(ks);
  for(i=count-1;i>=0;i--){
    if (interact("ropebridge1", ks[i])
     || interact("ropebridge2", ks[i])
     || interact("ropebridge3", ks[i])
     || interact("ropebridge4", ks[i])
     || interact("ropebridge5", ks[i])
     || interact("ropebridge6", ks[i])
     || interact("canyon_path", ks[i])){
//      tell_room(ETO, "deleting " + ks[i]);
      map_delete(map, ks[i]);
    } else {
//      tell_room(ETO, ks[i] + " does not contain ropebridge");
    }
  }
  DEST->set_waystations(dest, map);
}

int clean_up(){
  return 1;
}

close_rift(){
  object room, rift;
  if (objectp(ETO) && file_name(ETO) == TECVOID + "inner_void0"
       && tentacles_withdrawn == 0 && !query_paralyzed()){
    if (ETO->query_exit("out")=="/d/shadowgate/void"){
      return;
    }
    room= find_object_or_load(ETO->query_exit("out"));
    if (objectp(room)){
      rift = present("rift", room);
      if (objectp(rift)){
        rift->close();
        tell_void("%^BLUE%^The %^MAGENTA%^U%^BLUE%^n%^MAGENTA%^f"
          +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e"
          +"%^MAGENTA%^d's %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^"
          +"%^BLACK%^nt%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cles"
          +"%^RESET%^ drag the %^BLUE%^rift%^RESET%^ a litle further"
          +" closed.");
      }
    }
  }
}

void ooze_mucus(){
  mucus += 150;
  tell_room(ETO, "%^BOLD%^%^GREEN%^The %^RESET%^%^MAGENTA%^Un"
    +"%^BLUE%^f%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r"
    +"%^MAGENTA%^ed%^BOLD%^%^GREEN%^ oozes m%^RESET%^%^GREEN%^u"
    +"%^BOLD%^c%^RESET%^%^GREEN%^u%^BOLD%^s from its %^BOLD%^"
    +"%^BLACK%^tentacles");
  if (mucus > SURFACE_AREA){
    mucus = SURFACE_AREA;
    tell_room(ETO, "%^BOLD%^%^GREEN%^M%^RESET%^%^GREEN%^u%^BOLD%^c"
      +"%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^ dr%^BOLD%^i%^RESET%^"
      +"%^GREEN%^ps to the %^ORANGE%^ground%^GREEN%^.");
  }
  if (mucus + frozen_mucus > SURFACE_AREA){
    frozen_mucus = SURFACE_AREA - mucus;
    tell_room(ETO, "%^GREEN%^Some of the %^BOLD%^%^CYAN%^fr%^WHITE%^"
      +"o%^CYAN%^z%^WHITE%^e%^CYAN%^n%^GREEN%^ m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^flakes"
      +" %^RESET%^%^GREEN%^off as further %^BOLD%^m%^RESET%^"
      +"%^GREEN%^u%^BOLD%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^RESET%^"
      +"%^GREEN%^oozes out from underneath it");
  }
}

varargs void grant_quest(object slayer, string quest, int exp,
                              string explanation, int must_be_near){
  object leader, * party, found_thing;
  string name, party_name;
  int i, count;
  if (!objectp(slayer)){
    return;
  }
  leader = slayer->query_property("minion");
  if (objectp(leader)){
     slayer = leader;
  }
  party_name = "/adm/daemon/party_d.c"->party_member(slayer);
  party = "/adm/daemon/party_d.c"->query_party_members(party_name);
  count = sizeof(party);
  if (count>0){
    for (i=0;i<count;i++){
      name = party[i]->query_name();
      found_thing = PATHFINDER_D->far_present(ETO, name, 4);
      if (must_be_near && !objectp(found_thing)){
        continue;
      }
      party[i]->set_quest(quest);
      "/realms/lujke/daemon/congratulations_d.c"->congratulate(party[i]);
      party[i]->add_exp(exp);
      tell_object( party[i],explanation);
    }
  }
}

string slime_desc(){
  string slime, slime_desc, freeze_desc;
  int ratio, freeze_ratio;
  if (mucus >= SURFACE_AREA){
    if (objectp(ETO) && !ETO->is_vacuum()){
     slime = "%^GREEN%^A thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me %^RESET%^%^GREEN%^oozes continuously"
       +" from its skin, and drips to the ground all around it.";
    } else {
      slime = "%^GREEN%^A thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me covers its %^BOLD%^%^BLACK%^t%^RESET%^"
       +"%^GREEN%^e%^BOLD%^%^BLACK%^ntacl%^RESET%^e%^BOLD%^"
       +"%^BLACK%^s.";
    }
    return slime + "%^RESET%^";
  }
  ratio = mucus * 100/SURFACE_AREA;
  freeze_ratio = frozen_mucus * 100/SURFACE_AREA;
  slime = "";
  freeze_desc = "";
  if (ratio >= 90){
    if (objectp(ETO) && !ETO->is_vacuum()){
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^almost completely %^GREEN%^covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me, %^RESET%^%^GREEN%^which oozes"
       +" continuously and drips to the ground.";
    } else {
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^almost completely %^GREEN%^covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me.";
    }
  }
  if (ratio >= 75 && ratio <90){
    if (objectp(ETO) && !ETO->is_vacuum()){
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^more than three quarters %^GREEN%^"
       +"covered in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me, %^RESET%^%^GREEN%^which oozes"
       +" continuously and drips to the ground.";
    } else {
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^more than three quarters %^GREEN%^"
       +"covered in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me.";
    }
  }
  if (ratio >=50 && ratio <75){
    if (objectp(ETO) && !ETO->is_vacuum()){
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^more than half %^GREEN%^covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me, %^RESET%^%^GREEN%^ which oozes"
       +" continuously from its skin, and drips to the ground.";
    } else {
      slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^more than half %^GREEN%^covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me.";
    }
  }
  if (ratio >= 25 && ratio <50){
    slime_desc = "%^GREEN%^More than %^RESET%^a quarter of the"
       +" %^BOLD%^%^BLACK%^tentacles%^RESET%^ %^GREEN%^are covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me%^RESET%^%^GREEN%^.";
  }
  if (ratio >=10 && ratio <25){
    slime_desc = "%^GREEN%^The %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" %^GREEN%^are %^RESET%^less than a quarter %^GREEN%^covered"
       +" in a thick %^MAGENTA%^mucus%^GREEN%^ of %^BLUE%^p"
       +"%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r%^MAGENTA%^i"
       +"%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^i"
       +"%^BOLD%^%^GREEN%^me.";
  }
  if (ratio <10){
    slime_desc = "%^GREEN%^Only a %^RESET%^very little bit%^GREEN%^"
       +" of the surface of the %^BOLD%^%^BLACK%^tentacles%^RESET%^"
       +" is %^GREEN%^coated in a thick %^MAGENTA%^mucus%^GREEN%^ of"
       +" %^BLUE%^p%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^t%^BOLD%^r"
       +"%^MAGENTA%^i%^RESET%^%^BLUE%^d %^BOLD%^%^GREEN%^sl%^RESET%^"
       +"%^GREEN%^i%^BOLD%^%^GREEN%^me.";
  }
  if (freeze_ratio >= 90){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^nearly all %^BOLD%^%^CYAN%^of the%^BOLD%^%^BLACK%^"
      +" tentacles%^CYAN%^.";
  }
  if (freeze_ratio >= 75 && freeze_ratio <90){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^more than three quarters %^BOLD%^%^CYAN%^of the"
      +" %^BOLD%^%^BLACK%^tentacles%^CYAN%^.";
  }
  if (freeze_ratio >=50 && freeze_ratio <75){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^more than half %^BOLD%^%^CYAN%^of the%^BOLD%^%^BLACK%^"
      +" tentacles%^CYAN%^.";
  }
  if (freeze_ratio >= 25 && freeze_ratio <50){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^nearly half %^BOLD%^%^CYAN%^of the%^BOLD%^%^BLACK%^"
      +" tentacles%^CYAN%^.";
  }
  if (freeze_ratio >=10 && freeze_ratio <25){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^less than a quarter %^BOLD%^%^CYAN%^of the"
      +" %^BOLD%^%^BLACK%^tentacles%^CYAN%^.";
  }
  if ( freeze_ratio >0 && freeze_ratio <10 ){
    freeze_desc =  "%^BOLD%^%^CYAN%^A crust of fr%^BOLD%^%^WHITE%^o%^CYAN%^"
      +"z%^RESET%^e%^BOLD%^%^CYAN%^n %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^u%^BOLD%^s %^CYAN%^covers"
      +" %^RESET%^a tiny bit %^BOLD%^%^CYAN%^of the%^BOLD%^%^BLACK%^"
      +" tentacles%^CYAN%^.";
  }
  if (frozen_mucus ==0){
    freeze_desc = "";
  }
  return slime_desc + " " + freeze_desc + "%^RESET%^";
}

string skin_desc(){
  string desc;
  int ratio;
  if (skin == SURFACE_AREA){
    return "";
  }
  ratio = skin * 100 / SURFACE_AREA;
  if (ratio >=90){
    desc = "  The %^BOLD%^%^BLACK%^th%^RESET%^i%^BOLD%^%^BLACK%^ck,"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^ on the %^BOLD%^%^BLACK%^tentacles"
      +" %^RESET%^has been slightly damaged and has a few"
      +" %^MAGENTA%^g%^BOLD%^%^RED%^a%^MAGENTA%^p%^RESET%^%^MAGENTA%^s"
      +" %^RESET%^in it.";
  }
  if (ratio >=75 && ratio <90){
    desc = "  The %^BOLD%^%^BLACK%^th%^RESET%^i%^BOLD%^%^BLACK%^ck,"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^ on the %^BOLD%^%^BLACK%^tentacles"
      +" %^RESET%^has been damaged and has a quite a few"
      +" %^MAGENTA%^g%^BOLD%^%^RED%^a%^MAGENTA%^p%^RESET%^%^MAGENTA%^s"
      +" %^RESET%^in it.";
  }
  if (ratio >=50 && ratio <75){
    desc = "  The %^BOLD%^%^BLACK%^th%^RESET%^i%^BOLD%^%^BLACK%^ck,"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^ on the %^BOLD%^%^BLACK%^tentacles"
      +" %^RESET%^has been badly damaged and has a lots of"
      +" %^MAGENTA%^g%^BOLD%^%^RED%^a%^MAGENTA%^p%^RESET%^%^MAGENTA%^s"
      +" %^RESET%^in it.";
  }
  if (ratio >=25 && ratio <50){
    desc = "  More than half of the %^BOLD%^%^BLACK%^tentacles'"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^"
      +" %^RESET%^has been striped away, exposing %^MAGENTA%^vulner"
      +"%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^ble %^BOLD%^%^MAGENTA%^f"
      +"%^BOLD%^%^RED%^l%^MAGENTA%^e%^RESET%^%^RED%^s%^MAGENTA%^h"
      +" %^RESET%^underneath";
  }
  if (ratio >=10 && ratio <25){
    desc = "  The %^BOLD%^%^BLACK%^th%^RESET%^i%^BOLD%^%^BLACK%^ck,"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^ on the %^BOLD%^%^BLACK%^tentacles"
      +" %^RESET%^has been cut to ribbons and has %^MAGENTA%^g%^BOLD%^"
      +"%^RED%^a%^RESET%^%^MAGENTA%^p%^BOLD%^i%^RESET%^%^MAGENTA%^ng"
      +" %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^n%^RED%^ts"
      +" %^RESET%^in it.";
  }
  if (ratio <10){
    desc = "  The %^BOLD%^%^BLACK%^th%^RESET%^i%^BOLD%^%^BLACK%^ck,"
      +" r%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^bbery sk%^RESET%^%^MAGENTA%^i"
      +"%^BOLD%^%^BLACK%^n%^RESET%^ on the %^BOLD%^%^BLACK%^tentacles"
      +" %^RESET%^has been %^BOLD%^%^RED%^shredded%^RESET%^, and only a"
      +" few %^RED%^ragged %^BOLD%^%^BLACK%^str%^RESET%^%^RED%^i%^BOLD%^"
      +"%^BLACK%^p%^RED%^s %^RESET%^remain";
  }
  if (skin == 0){
    desc = "The %^BOLD%^%^BLACK%^sk%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n"
    +" %^RESET%^has been flayed from the %^BOLD%^%^BLACK%^tentacles"
    +"%^RESET%^, and all that is left is the %^BOLD%^%^RED%^r%^RESET%^"
    +"%^RED%^a%^BOLD%^%^RED%^w, %^RESET%^%^RED%^e%^MAGENTA%^x%^RED%^p"
    +"%^BOLD%^o%^RESET%^%^RED%^se%^BOLD%^d %^MAGENTA%^m%^RESET%^"
    +"%^MAGENTA%^u%^BOLD%^sc%^RED%^l%^MAGENTA%^e%^RESET%^ and %^BOLD%^"
    +"%^RED%^s%^YELLOW%^i%^RED%^n%^MAGENTA%^e%^RED%^w %^RESET%^beneath.";
  }
  return desc;
}

void goto_bridge(){
  int waytime, mazetime;
  string dest;
  dest = JUNG_ROOM5 + "ropebridge5";
//  dest = JUNG_ROOM + "j_link9a";
  waytime = DEST->query_timing(dest);
  mazetime = MAZE_D->query_timing(JUNG_ROOM5);
  if (mazetime == 0 || mazetime > waytime){
  // Above check makes sure the next lag inducing maneuvre only happens
  // if the maze has been reset since the waystations were set up
    DEST->clear_waystations(dest);
    DEST->generate_waystations(dest,6, 4);
  }
  start_walking(dest);
  hurry();
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

void reach_destination(){
  string roomname, envname, pplname;
  int i, count, flag;
  object * empresses, empress, * ppl, room;
  report ("%^BOLD%^%^MAGENTA%^reached destination: " + base_name(ETO));
  ::reach_destination();
  if (!objectp(ETO)){
    return;
  }
  roomname = file_name(ETO);
  switch (roomname){
  case JUNG_ROOM + "ropebridge5":
    ETO->tell_bridge("The entire %^ORANGE%^bridge%^RESET%^ shakes as"
      +" the %^BLUE%^creature%^RESET%^ known as %^MAGENTA%^The"
      +" U%^MAGENTA%^nfe%^MAGENTA%^tte%^MAGENTA%^re%^MAGENTA%^d%^RESET%^"
      +" arrives at the eastern end!");
    //check whether anyone online on the tecqumin continent has killed the empress lately
    ppl = children("/std/user.c");
    count = sizeof(ppl);
    if (count<1){
      return;
    }
    flag = 0;
    for (i=0;i<count;i++){
      if (!objectp(ppl[i])||ppl[i]->query_true_invis()){
        continue;
      }
      room = environment(ppl[i]);
      if (!objectp(room)){
        continue;
      }
      envname = base_name(room);
      if (interact("tecqumin", envname)){
        pplname = ppl[i]->query_name();
        if (EVENTS_D->has_killed(pplname, MOB + "empress", DAY * 7)!=-1){
          return;  //If someone online on this continent has killed the empress recently, don't have her give her warning
        }
      }
    }
    call_out("empress_warning", 1);
    break;
  case JUNG_ROOM4 + "city_jung14":
    goto_plaza();
    break;
  case CITY_ROOM + "plaza":
    goto_zigzenith();
    break;
  case ROOMS + "zigzenith":
    do_finale();
    break;
  }
}

void goto_plaza(){
  object waystation;
  string dest_name;
  int waytime, uptime;
  dest_name = CITY_ROOM + "plaza";
  waytime = "/daemon/destinations_d"->query_timing(dest_name);
  if (waytime<time()-uptime()){
    "/daemon/destinations_d"->clear_waystations(dest_name);
    "/daemon/destinations_d"->generate_waystations(dest_name, 4,3);
  }
  waystation = "/daemon/pathfinder_d"->find_waystation(ETO, dest_name, 5);
  if(!objectp(waystation)){
    //Look up an alternate city room to go to.
  } else {
    start_walking(dest_name);
  }
}

varargs void paralyze_all(string msg){
  object * usrs, * rooms, * critters, room;
  int i, j, count1, count2;
  rooms = ({});
  usrs = children("/std/user.c");
  count1 = sizeof(usrs);
  if (count1<1){
    return;
  }
  for(i=0;i<count1;i++){
    room = environment(usrs[i]);
    if(objectp(room) && interact("tecqumin", base_name(room))){
      rooms += ({room});
    }
  }
  count1 = sizeof(rooms);
  if (!stringp(msg)){
    msg = "Events are afoot. You cannot act.";
  }
  for (i=0;i<count1;i++){
    critters = all_living(rooms[i]);
    count2 = sizeof(critters);
    if (count2<1){
      continue;
    }
    for(j=0;j<count2;j++){
      if (critters[j]->query_true_invis()){
        continue;
      }
      critters[j]->remove_property("no paralyze");
      critters[j]->set_paralyzed(1000, msg);

    }
  }
}

void kill_all(){
  object * usrs, * rooms, * critters, room;
  int i, j, count1, count2;
  rooms = ({});
  usrs = children("/std/user.c");
  count1 = sizeof(usrs);
  if (count1<1){
    return;
  }
  for(i=0;i<count1;i++){
    room = environment(usrs[i]);
    if(objectp(room) && interact("tecqumin", base_name(room))){
      rooms += ({room});
    }
  }
  count1 = sizeof(rooms);
  for (i=0;i<count1;i++){
    critters = all_living(rooms[i]);
    count2 = sizeof(critters);
    if (count2<1){
      continue;
    }
    for(j=0;j<count2;j++){
      if (critters[j]->query_true_invis() || critters[j]==TO){
        continue;
      }
      critters[j]->set_hp(-20);
      critters[j]->die();

    }
  }
}




void goto_zigzenith(){
  object waystation;
  string dest_name;
  int waytime, uptime;
  dest_name = ROOMS + "zigzenith";
  waytime = "/daemon/destinations_d"->query_timing(dest_name);
  if (waytime<time()-uptime()){
    "/daemon/destinations_d"->clear_waystations(dest_name);
    "/daemon/destinations_d"->generate_waystations(dest_name, 4,3);

  }
  waystation = "/daemon/pathfinder_d"->find_waystation(ETO, dest_name, 5);
  if(!objectp(waystation)){
    //Look up an alternate city room to go to.
  } else {
    start_walking(dest_name);
  }
}

varargs void tell_continent(string str, string alignment){
  object * users;
  int i, count;
  string where, who;
  users = children("/std/user");
  count = sizeof(users);
  if (count<1){
    return;
  }
  for (i=0;i<count;i++){
    if (users[i]->query_true_invis()){
      if (stringp(alignment)){
        who = alignment + " aligned characters in the %^CYAN%^Tecqumin%^RESET%^ area";
      } else {
        who = "all characters in the %^CYAN%^Tecqumin%^RESET%^ area";
      }
      tell_object(users[i], who + " hear a message that: " + str);
      continue;
    }
    if (!objectp(environment(users[i])) || !interact("tecqumin", base_name(environment(users[i]))) ){
      continue;
    }
    if (!stringp(alignment) || (alignment == "evil" && users[i]->is_evil()) || (alignment == "good" && users[i]->is_good()) || (alignment == "neutral" && users[i]->is_neutral()) ){
      tell_object(users[i], str);
    }
  }
}

void do_finale2(){
  power_absorbed ++;
  tell_continent("A strange, high pitched %^BOLD%^%^CYAN%^keening%^RESET%^ sound filters through the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^, slipping between %^ORANGE%^trees%^RESET%^ and under %^GREEN%^r%^ORANGE%^oo%^GREEN%^t%^ORANGE%^s%^RESET%^ to appeal to your ears with a deliciously %^BOLD%^%^BLACK%^ent%^MAGENTA%^i%^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng %^BOLD%^%^MAGENTA%^promise %^RESET%^of %^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rk r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^rds^. It seems to be coming from the direction of the ziggurat at the centre of the %^CYAN%^Tecqumin%^RESET%^ lost city.", "evil");
  tell_continent("A strange, high pitched %^BOLD%^%^CYAN%^keening%^RESET%^ sound filters through the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^, slipping between %^ORANGE%^trees%^RESET%^ and under %^GREEN%^r%^ORANGE%^oo%^GREEN%^t%^ORANGE%^s%^RESET%^ with an %^BOLD%^%^BLUE%^ins%^GREEN%^i%^BLUE%^d%^GREEN%^i%^CYAN%^o%^BLUE%^us%^RESET%^, %^GREEN%^s%^BOLD%^i%^RESET%^%^GREEN%^ck%^BOLD%^e%^RESET%^%^GREEN%^n%^BOLD%^i%^RESET%^%^GREEN%^ng%^RESET%^ appeal to %^BLUE%^base desires%^RESET%^ for %^BOLD%^%^YELLOW%^power%^RESET%^ and %^BOLD%^%^MAGENTA%^self satisfaction%^RESET%^. It seems to be coming from the direction of the ziggurat at the centre of the %^CYAN%^Tecqumin%^RESET%^ lost city.", "good");
  tell_continent("A strange, high pitched %^BOLD%^%^CYAN%^keening%^RESET%^ sound filters through the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^, slipping between %^ORANGE%^trees%^RESET%^ and under %^GREEN%^r%^ORANGE%^oo%^GREEN%^t%^ORANGE%^s%^RESET%^ to reach your ears with an appeal to whatever there is in you that is %^BOLD%^%^GREEN%^selfish%^RESET%^ and %^BOLD%^%^BLUE%^desirous%^RESET%^ of %^BOLD%^%^YELLOW%^power%^RESET%^ and %^MAGENTA%^thrall%^RESET%^ over others. It seems to be coming from the direction of the ziggurat at the centre of the %^CYAN%^Tecqumin%^RESET%^ lost city.", "neutral");

  set_property("finale", 2);

}

void absorb_power(int how_much){
  power_absorbed += how_much;
}

void lose_power(int how_much){
  power_absorbed -= how_much;
}

int query_power_absorbed(){
  return power_absorbed;
}

void do_finale1(){
  power_absorbed ++;
  force_me("emote emits a high pitched keening sound that is at once %^GREEN%^na"
    +"%^BLUE%^u%^GREEN%^se%^CYAN%^a%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^ing%^RESET%^"
    +" and almost %^BOLD%^%^WHITE%^irresistably%^RESET%^ appealing");
  set_property("finale", 2);

}

void do_finale0(){
  power_absorbed ++;
  force_me("emote uses its tentacles to drag itself and the rift it resides in forward to settle in between the two bloodstained altars at the top of the ziggurat");
  set_property("finale", 1);
}


void empress_warning(){
  object * empresses, empress, * ppl, room;
  empresses = children(MOB + "empress");
  if (sizeof(empresses)<1){
    empress = new(MOB + "empress");
  } else {
    if (empress_moves >2){
      return;
    }
    empress = empresses[0];
    empress_moves ++;
    if (objectp(environment(empress))){
      tell_room(environment(empress), "The %^CYAN%^spirit%^RESET%^ of%^MAGENTA%^"
        +" Empress Mehaq%^RESET%^ %^BOLD%^%^CYAN%^fl%^WHITE%^i%^CYAN%^ck%^RESET%^"
        +"%^CYAN%^e%^BOLD%^rs%^RESET%^, and disappears");
    }
  }
  room = find_object_or_load(JUNG_ROOM + "ropebridge3");
  empress->move(room);
  room->tell_bridge("The %^CYAN%^spirit%^RESET%^ of%^MAGENTA%^"
        +" Empress Mehaq%^RESET%^ appears in the centre of the bridge");
  "/d/atoyatl/bridge_monitor_d.c"->set_PosDir(empress, ({29, 0, 1}));
  call_out("empress_warning2", 1, empress);
}

void empress_warning2(object empress){
  object room;
  if (!objectp(empress)){ return;}
  room = environment(empress);
  if (!objectp(room)){
    empress_warning();
    return;
  }
  if (base_name(room)!= JUNG_ROOM + "ropebridge0" && base_name(room)!= JUNG_ROOM + "ropebridge1"
   && base_name(room)!= JUNG_ROOM + "ropebridge2" && base_name(room)!= JUNG_ROOM + "ropebridge3"
   && base_name(room)!= JUNG_ROOM + "ropebridge4" && base_name(room)!= JUNG_ROOM + "ropebridge5"){
    empress_warning();
    return;
  }
  empress_moves = 0;
  room->tell_bridge("%^RESET%^%^MAGENTA%^Empress Mehaq%^BOLD%^%^CYAN%^ cries out: %^BOLD%^%^WHITE%^The creature is trying to reach the city of the Tecqumin! ");
  call_out("empress_warning3", 2, empress);
}

void empress_warning3(object empress){
  object room;
  if (!objectp(empress)){ return;}
  room = environment(empress);
  if (!objectp(room)){
    empress_warning();
    return;
  }
  if (base_name(room)!= JUNG_ROOM + "ropebridge0" && base_name(room)!= JUNG_ROOM + "ropebridge1"
   && base_name(room)!= JUNG_ROOM + "ropebridge2" && base_name(room)!= JUNG_ROOM + "ropebridge3"
   && base_name(room)!= JUNG_ROOM + "ropebridge4" && base_name(room)!= JUNG_ROOM + "ropebridge5"){
    empress_warning();
    return;
  }
  empress_moves = 0;
  room->tell_bridge("%^RESET%^%^MAGENTA%^Empress Mehaq%^BOLD%^%^CYAN%^ cries out: %^BOLD%^%^WHITE%^If it reaches the %^RESET%^zenith %^BOLD%^%^WHITE%^of the %^RESET%^ziggurat%^BOLD%^%^WHITE%^, it will have access to great power! ");
  call_out("empress_warning4", 2, empress);
}

void empress_warning4(object empress){
  object room;
  if (!objectp(empress)){ return;}
  room = environment(empress);
  if (!objectp(room)){
    empress_warning();
    return;
  }
  if (base_name(room)!= JUNG_ROOM + "ropebridge0" && base_name(room)!= JUNG_ROOM + "ropebridge1"
   && base_name(room)!= JUNG_ROOM + "ropebridge2" && base_name(room)!= JUNG_ROOM + "ropebridge3"
   && base_name(room)!= JUNG_ROOM + "ropebridge4" && base_name(room)!= JUNG_ROOM + "ropebridge5"){
    empress_warning();
    return;
  }
  empress_moves = 0;
  room->tell_bridge("%^RESET%^%^MAGENTA%^Empress Mehaq%^BOLD%^%^CYAN%^ cries out: %^BOLD%^%^WHITE%^It must be stopped! DO NOT LET IT CROSS THE BRIDGE!");
}

void catch_tell(string str){
  string obstacle, article;
  if (interact("You can't go any further west at the moment; ", str)){
    sscanf (str, "You can't go any further west at the moment; %s %s is in the way.", article, obstacle);
    if (stringp(obstacle)){
      tell_room(ETO, "The %^BLUE%^Un%^MAGENTA%^fe%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d lashes out with a tentacle");
      call_out("push_obstacle", 1, obstacle);
    }
  }
}

void push_obstacle(string obstacle){
  force_me("push " + obstacle + " off bridge");
}

void stop_combat(){
  object * critters, room, * attackers;
  int i, j, count, count2;
  room = ETO;
  if (!objectp(room)){
    return;
  }
  critters = all_living(room);
  count = sizeof(critters);
  if (count<1){
    return;
  }
  for (i=0;i<count;i++){
    critters[i]->cease_all_attacks();
    attackers = critters[i]->query_attackers();
    count2 = sizeof(attackers);
    if (count2<1){
      continue;
    }
    for(j=0;j<count;j++){
      critters[i]->remove_attacker(attackers[j]);
    }
  }
}

void tell_world(string msg){
  object * ppl;
  int i, j, count;
  ppl = children("user.c");
  count = sizeof(ppl);
  if (count<1){
    return;
  }
  for(i=0;i<count;i++){
    if (!ppl[i]->query_true_invis()){
      continue;
    }
    tell_object(ppl[i], msg);
  }
}

void the_end(){
  move("/d/shadowgate/void");
}

void victory7(){
  tell_world("\n\n");
  tell_world("%^B_RED%^%^BOLD%^%^WHITE%^All tremble at the knowledge that War is coming");
  tell_world("\n\n");
  call_out("the_end", 1);
}
void victory6(){
  tell_world("\n\n");
  tell_world("%^B_RED%^%^BOLD%^%^WHITE%^The creature known as the Unfettered has been"
    +" released by foolhardy adventurers, and has gathered power to aid its eventual"
    +" war against the Gods.");
  tell_world("\n\n");
   call_out("victory7", 3);
}
void victory5(){
  /////Make world broadcast
  tell_world("\n\n\n\n\n");
  tell_world("%^B_RED%^%^BOLD%^%^WHITE%^A darkness falls over the continent of Danger");
  tell_world("\n\n\n\n\n");
   call_out("victory6", 3);
}

void victory4(){
  paralyze_all();
  tell_continent("\n\n\n\n\n\n");
  tell_continent("%^B_BLACK%^%^BOLD%^%^WHITE%^As the light and life fade from"
    +" your eyes, you know that the world is at risk, and the final victory of the"
    +" %^RESET%^%^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e"
    +"%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^BOLD%^%^WHITE%^ is made closer");
  call_out("victory5", 2);
}
void victory3(){
  paralyze_all();
  tell_continent("\n\n\n\n\n\n");
  tell_continent("%^B_BLACK%^%^BOLD%^%^WHITE%^The %^RESET%^%^CYAN%^air %^BOLD%^%^WHITE%^thins and you fall to your knees as the %^MAGENTA%^life%^BOLD%^%^WHITE%^ is drawn out of you towards the malevolant force of the %^RESET%^%^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^BOLD%^%^WHITE%^, unleashed upon the world by adventurers too proud to acknowledge the slim chances of their success");
  call_out("victory4", 2);
}
void victory2(){
  paralyze_all();
  if (objectp(ETO)){
    tell_room(ETO, "The air rushes out of the room as the Unfettered pushes more of its massive bulk out of the huge rift it has torn in the sky.");
  }
  call_out("victory3", 2);
}

void fail_all(){
  object * ppl, room;
  int i, count;
  ppl = children("/std/user.c");
  count = sizeof(ppl);
  if (count<1)
  {
    return;
  }
  for (i=0;i<count;i++)
  {
    room = environment(ppl[i]);
    if (ppl[i]->query_true_invis() || !objectp(room) || !interact ("tecqumin", base_name(room)))
    {
      continue;
    }
    EVENT_RECORDS_D->record_event(ppl[i]->query_name(), "Failed to stop the Unfettered", time());
  }
}


void victory(){
  //First, paralyze everyone on the continent
  paralyze_all("You are in the grip of the %^GREEN%^horror%^RESET%^ of the events unfolding. You cannot move.");
  //Add a 'failed to stop the Unfettered' event for everyone on the continent
  fail_all();
  //next, stop all combat in the room
  stop_combat();
  tell_continent("\n\n\n\n\n");
  tell_continent("%^B_BLACK%^%^BOLD%^%^RED%^A massive BOOMING %^BOLD%^%^WHITE%^shockwave %^RED%^hits you as the sky overhead is %^CYAN%^TORN APART");
  call_out("victory2", 2);
}
