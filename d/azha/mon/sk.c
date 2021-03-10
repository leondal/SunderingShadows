// Imperial Skirmisher v1.2
// Thorn@ShadowGate
// 001013
// Imperial Army of Tsarven
// skirmisher.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

// Delay HBs between reinforcements being called in.
#define DELAY 20;

// Name of bow that this archer uses
#define MY_BOW_NAME "Tsarvani light recurved bow"

inherit "/d/azha/std/wander";

int build, reload, force_delay, timer, patrol_timer;
string *outs,*exit_dir;
string *blacklist;
object *platoon;
object start;

void set_blacklist(string *list);
void add_blacklist(string name);
string *query_blacklist();
int is_hunting_me(object agg);
void do_scouting();
void do_check();
void do_bow();
void be_nice();
int stab(string targ);
int rush(string targ);

int count;

init() {
  ::init();
  add_action("stab","stab");
  add_action("rush","rush");
}
  
create() {  
  ::create();
  set_name("skirmisher");
  set_id( ({"imperial skirmisher", "skirmisher" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Imperial Skirmisher");
  set_long(
@TSARVEN
  This is a skirmisher of the Tsarvani Imperial Army.  A Skirmisher is a
special type of light infantry that specializes in remaining in the
shadows to do front-line scouting and harassment of the enemy.
Skirmishers, like the light archers, are adept at the use of the
Tsarvani light recurved bow and the scimitar.  It is likely that your
first clue that one is in the area is arrows hitting you from the ambush
that he has called in.
TSARVEN
  );
  set_class("ranger"); 
  set_level(24);  
  set_hd(24,0);     
  set_exp(6000);
  set_body_type("human");  
  set_property("full attacks",1);
  add_search_path("/cmds/fighter");
  set_property("no steal",1);
  set_property("knock unconscious",1);
  set_scrambling(1);
  set("aggressive", 1);  
  set_alignment(7);  
  set_size(2);  
  set_stats("intelligence",12);  
  set_stats("wisdom",12);  
  set_stats("strength",18);  
  set_stats("charisma",10);  
  set_stats("dexterity",18);  
  set_stats("constitution",16);
  set_skill("recurved bow", 200);  
  set_max_hp(270);
  set_hp(query_max_hp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );  
  new(LRWEAPONDIR+"arrows")->move(this_object());  
  new("/d/azha/equip/recurved_bow")->move(this_object());  
  command("wield bow in right hand and left hand");  
  new("/d/azha/equip/scimitar")->move(this_object());  
  new("/d/azha/equip/scimitar")->move(this_object());  
  new(ARMORDIR+"chain")->move(this_object());  
  command("wear armor");  
  add_money("electrum",random(10));  
  add_money("silver",random(10));  
  add_money("gold",random(40));  
  add_money("copper",random(20));  
  enable_commands();
  set_invis();
  blacklist = ({ });
  platoon = ({ });
}

void start_heart(){   
    set_heart_beat(1);
}
    
void heart_beat(){
  if(ETO && !start) start = ETO;
  count++;
  if(force_delay) force_delay--;
  do_check();
  if(objectp(query_weapon("right hand")))
    if((string)query_weapon("right hand")->query_name() != "scimitar" && count > 5)
  do_bow();
  be_nice();
  do_scouting();
  timer++;
  patrol_timer++;
  if(timer > 25){
    timer = 0;
	if(sizeof(query_hunted())) {
	  reset_hunted();
	  command("chuckle");
	}
    if(!query_invis()){
      if(query_attackers() == ({}) ){
      set_invis();
      }
    }
  }
  if(patrol_timer > 120){
    patrol_timer = 0;
    if(ETO != start){
      TO->move(start);
    }
  }
  ::heart_beat();
}

void do_bow(){
  int i,j, y,z;
  object ob, *inven, *living_bad;
  string exit,*paths, *ids; 
  living_bad = ({});
  if(ETO){
    paths = ETO->query_destinations();
    if(j = sizeof(paths)){
      for(i=0;i<j;i++){
        
        if(ob = find_object_or_load(paths[i])){
          
          inven = all_inventory(ob);
          z = sizeof(inven);
          
          for(y=0;y<z;y++)
            if(is_hunting_me(inven[y])){
              living_bad += ({inven[y]});
          }     
          if(z = sizeof(living_bad)){
            y = random(z);
            exit = ETO->query_direction(paths[i]);
            if(!interactive(living_bad[y])){    
              ids = living_bad[y]->query_id();
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
            }
            else
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
           break;
          }
        }
      }
    }
  }
  count = 0;
}

void do_check(){
  object *weapons;
  int i;
  
  weapons = TO->query_wielded();
  if(sizeof(weapons)){
    if((string)weapons[0]->query_name() != MY_BOW_NAME){
      if((object *)TO->query_attackers() == ({})){
        command("unwield sword");
        command("unwield sword 2");
        command("wield bow in right hand and left hand");
      }
    }
    else 
      if((string)weapons[0]->query_name() == MY_BOW_NAME){
        if((object *)TO->query_attackers() != ({})){
        command("unwield bow");
        command("wield scimitar in right hand");
        command("wield scimitar 2 in left hand");
        }
      }
  }
  if(!present("arrows"))
  new("/d/shadow/obj/lrweapon/arrows")->move(TO);
}

void do_scouting(){
  int y,z;
  object *inven, *living_bad, trooper;
  string *exits;

  living_bad = ({ });  
  if(ETO){
    inven = all_inventory(ETO);
    z = sizeof(inven);
    
    for(y=0;y<z;y++) {
      if(interactive(inven[y]) &&
	  (member_array((string)inven[y]->query_name(), blacklist) != -1) &&
	  ((!inven[y]->query_invis()))){
        living_bad += ({inven[y]});
        if(!force_delay) inven[y]->set_paralyzed(15,"%^BOLD%^You've been ambushed!%^RESET%^");
      }
      else if(living(inven[y]) && ((string)inven[y]->query_race() == "drow") &&
	         (!inven[y]->query_invis()) && (inven[y]->query_level() > 14)){
		command("yell Drow in the area!!  To arms!!");
      }
    }
    if(sizeof(living_bad) && !sizeof(platoon) && !force_delay){
      exits = ETO->query_exits();
      force_delay = DELAY;
      trooper = new("/d/azha/mon/larcher");
      platoon += ({ trooper });
      trooper = new("/d/azha/mon/larcher");
      platoon += ({ trooper });
      trooper = new("/d/azha/mon/larcher");
      platoon += ({ trooper });
      trooper = new("/d/azha/mon/larcher");
      platoon += ({ trooper });
      trooper = new("/d/azha/mon/larcher");
      platoon += ({ trooper });
      for(y=0;y<sizeof(platoon);y++) {
        platoon[y]->move(ETO);
        platoon[y]->set_attackers(living_bad);
        platoon[y]->force_me("unwield bow");
        platoon[y]->force_me("wield scimitar in right hand");
        platoon[y]->force_me("wield scimitar 2 in left hand");
        platoon[y]->force_me("protect skirmisher");
        if(y < sizeof(exits))
		  platoon[y]->force_me("block "+exits[y]);
      }
      TO->set_attackers(living_bad);
      TO->force_me("unwield bow");
      TO->force_me("wield scimitar in right hand");
      TO->force_me("wield scimitar 2 in left hand");
	  if(exits[0]) TO->force_me("block "+exits[0]);
    }
    else if(!sizeof(living_bad) && sizeof(platoon) && !sizeof(TO->query_attackers())){
      for(y=0;y<sizeof(platoon);y++) {
        if(platoon[y]) platoon[y]->move("/d/shadowgate/void");
        platoon[y]->remove();
      }
      tell_room(ETO,
        "%^BOLD%^The archers melt back into the background.%^RESET%^");
      force_delay = 0;
    }
  else if(!present("light archer", ETO) && platoon) platoon = ({ });
  }
}

void set_blacklist(string list) {
  if(!list) {
    blacklist = ({ });
        return;
  }
  blacklist = "/daemon/data_lists"->query_list(list);
}

void add_blacklist(string name) {
  blacklist = blacklist + ({ name });
}

string *query_blacklist() {
  return blacklist;
}

int is_hunting_me(object agg) {
  object *hunted;
  
  if(!living(agg)) return 0;
  hunted = agg->query_hunted();
  if((member_array(TO, hunted) != -1) && (agg->query_level() > 14) && !agg->query_invis()) return 1;
  return 0;
}

die() {
  int y;
  if(sizeof(platoon)) {
    for(y=0;y<sizeof(platoon);y++) {
      if(platoon[y]) platoon[y]->move("/d/shadowgate/void");
      if(platoon[y]) platoon[y]->remove();
    }
    tell_room(ETO,
      "%^BOLD%^The archers melt back into the background.%^RESET%^");
    force_delay = 0;
  }
  ::die();
}

void be_nice() {
  object *inven;
  int i,j;
  string skill;
  
  if(!objectp(TO)) return;
  if(!sizeof(inven = query_attackers())) return;
  j = sizeof(inven);
  for(i=0;i<j;i++) {
    if(inven[i]->query_highest_level() < 15){
      force_me("laugh");
      force_me("say You're certainly brave, I'll give you that "+inven[i]->query_cap_name()+".  I don't believe in slaughtering amateurs though.");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      cease_all_attacks();
      continue;
    }
  }
  // END for()
}

int stab(string targ) {
  string *ids;
  
  if(!targ) return 0;
  ids = TO->query_id();
  if(member_array(targ, ids) == -1) return 0;
  if(TP->query_highest_level() < 15){
    force_me("snicker "+TP->query_name());
    force_me("say Why don't you come back and try that when you actually have a chance of succeding, "+TP->query_cap_name()+".");
    return 1;
  }
  if((((((int)TP->query_lowest_level())-15)*5) < random(100)) || !random(100)) {
    write("%^BOLD%^You attempt to land a deep blow...%^RESET%^");
    TP->force_me("gasp skirmisher");
    write("%^BOLD%^...but the skirmisher was ready for you.%^RESET%^");
    tell_room(ETO, "%^BOLD%^"+
      TP->query_cap_name()+
      " attempts to backstab the skirmisher, but the skirmisher was prepared for it!",
      ({ TO, TP }));
    tell_room(ETO, "%^BOLD%^RED%^"+
      "The skirmisher turns rapidly and executes a vicious upper cut to the face of "+
      TP->query_cap_name()+"!%^RESET%^",
      ({ TO, TP }));
    write("%^BOLD%^RED%^The skirmisher turns rapidly and executes a vicious upper cut to your face!%^RESET%^");
    TP->cause_typed_damage(TP, "head", roll_dice(1, 20), "bludgeoning");
    command("unwield bow");
    command("wield scimitar in right hand");
    command("wield scimitar 2 in left hand");
    TP->kill_ob(TO);
    return 1;
  }
  return 0;    
}

int rush(string targ) {
  string *ids;
  
  if(!targ) return 0;
  ids = TO->query_id();
  if(member_array(targ, ids) == -1) return 0;
  if(TP->query_highest_level() < 15){
    force_me("chuckle "+TP->query_name());
    force_me("say Why don't you come back and try that when you actually have a chance of succeding, "+TP->query_cap_name()+".");
    return 1;
  }
  if((((((int)TP->query_lowest_level())-15)*5) < random(100)) || !random(100)) {
    write("%^BOLD%^You break from combat and then rush weapon first into "+TO->query_cap_name()+"!%^RESET%^");
    TP->force_me("gasp skirmisher");
    tell_room(ETO, "%^BOLD%^"+
      TP->query_cap_name()+
      " attempts to rush the skirmisher, but the skirmisher was prepared for it!",
      ({ TO, TP }));
    TO->force_me("say Oldest trick in the book.");
    TO->force_me("laugh");
    tell_room(ETO, "%^BOLD%^RED%^"+
      "The skirmisher steps aside and his leg juts out, tripping up "+
      TP->query_cap_name()+"!%^RESET%^",
      ({ TO, TP }));
    write("%^BOLD%^As you rush into the skirmisher, he steps aside and catches his foot between your legs!%^RESET%^");
    write("%^BOLD%^RED%^You trip and fall, hitting the ground hard.%^RESET%^");
    TP->cause_typed_damage(TP, "torso", roll_dice(1, 5), "bludgeoning");
    TP->set_paralyzed(10);
    command("unwield bow");
    command("wield scimitar in right hand");
    command("wield scimitar 2 in left hand");
    TO->force_me("say You just *got* to get some better moves.");
    TP->kill_ob(TO);
    return 1;
  }
  return 0;    
}
