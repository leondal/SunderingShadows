// Imperial Sentry
// Thorn@ShadowGate
// 000915
// Imperial Army of Tsarven
// sentry.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

// Delay HBs between reinforcements being called in.
#define DELAY 10;

inherit MONSTER;

int build, reload, force_delay, timer, skirm_allow;
string *outs,*exit_dir;
string *blacklist;
string exit_to_block;
object *platoon;
object start;

void set_blacklist(string *list);
void set_exit_to_block(string exit);
void add_blacklist(string name);
string *query_blacklist();
int is_hunting_me(object agg);
void do_scouting();

int count;

create() {  
  ::create();
  set_name("soldier");
  set_id( ({"imperial soldier", "soldier", "sentry" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Imperial Foot Soldier");
  set_long(
@TSARVEN
This is a member of the Tsarvani Imperial Army.  Soldiers of the
Imperial Army are well-trained, well-equipped and numerous.  They
fight to protect the Empire and to promote the causes of justice
that the Empire seeks to promote.
TSARVEN
  );
  set_class("fighter"); 
  set_level(15);  
  set_hd(15,0);     
  set_exp(1000);  
  set_body_type("human");  
  set_property("full attacks",1);
  set("aggressive", 1);  
  set_alignment(7);  
  set_size(2);  
  set_stats("intelligence",12);  
  set_stats("wisdom",12);  
  set_stats("strength",25);  
  set_stats("charisma",10);  
  set_stats("dexterity",14);  
  set_stats("constitution",16);
  set_skill("recurved bow", 200);  
  set_max_mp(0);  
  set_mp(query_max_mp());  
  set_max_hp(150);
  set_max_sp(query_hp());  
  set_sp(query_max_sp());   
  set_wielding_limbs( ({ "right hand", "left hand" }) );  
  new("/d/azha/equip/scimitar")->move(this_object());  
  new(ARMORDIR+"chain")->move(this_object());  
  command("wear armor");  
  add_money("silver",random(10));  
  add_money("gold",random(10));  
  add_money("copper",random(20));  
  enable_commands();
  blacklist = ({ });
  platoon = ({ });
  exit_to_block = "west";
  skirm_allow = 0;
}

void start_heart(){   
    set_heart_beat(1);
}
    
void heart_beat(){
  if(ETO && !start) start = ETO;
  count++;
  if(force_delay) force_delay--;
  do_scouting();
  timer++;
  if(skirm_allow) skirm_allow--;
  ::heart_beat();
}

void do_scouting(){
  int y,z;
  object *inven, *living_bad, trooper;
  object ob;
  string *exits;

  living_bad = ({ });  
  if(ETO){
    inven = all_inventory(ETO);
    z = sizeof(inven);
    
    for(y=0;y<z;y++) {
      if(interactive(inven[y]) && (member_array((string)inven[y]->query_name(), blacklist) != -1)){
        living_bad += ({inven[y]});
        if(!force_delay) {
          TO->force_me("block "+exit_to_block);
          command("yell To arms!!!  To arms!!!  Rally to me!");
          if(!skirm_allow) {
              skirm_allow = 600;
              trooper = new("/d/azha/mon/skirmisher");
              trooper->add_blacklist(inven[y]->query_name());
              if(ob = find_object_or_load(exit_to_block)) trooper->move(ob);
              else trooper->remove();
          }
        }
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
        platoon[y]->set_hunted(living_bad);
        platoon[y]->force_me("unwield bow");
        platoon[y]->force_me("wield scimitar in right hand");
        platoon[y]->force_me("wield scimitar 2 in left hand");
        platoon[y]->force_me("protect sentry");
    if(y < sizeof(exits))
          platoon[y]->force_me("block "+exit_to_block);
      }
      TO->set_attackers(living_bad);
      TO->force_me("unwield bow");
      TO->force_me("wield scimitar in right hand");
      TO->force_me("wield scimitar 2 in left hand");
      tell_room(ETO,
        "%^BOLD%^The sentry calls for aid to protect his position!%^RESET%^");
    }
    else if(!sizeof(living_bad) && sizeof(platoon) && !sizeof(TO->query_attackers())){
      for(y=0;y<sizeof(platoon);y++) {
        if(platoon[y]) {
          platoon[y]->move("/d/shadowgate/void");
          platoon[y]->remove();
        }
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
  if(member_array(TO, hunted) != -1) return 1;
  return 0;
}

void set_exit_to_block(string exit) {
  exit_to_block = exit;
}
