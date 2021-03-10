// Imperial Provost
// Thorn@ShadowGate
// 010326
// Imperial Army of Tsarven
// provost.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

// Delay HBs between reinforcements being called in.
#define DELAY 20;

// Name of bow that this archer uses
#define MY_BOW_NAME "Tsarvani light recurved bow"

// Forbidden races
#define BAD_RACES ({ "half-drow", "orc", "goblin", "gnoll", "kobold", "ogre", "half-orc" })

inherit "/d/azha/std/wander";

int build, reload, force_delay, timer, patrol_timer, in_enforcement;
string *outs,*exit_dir;
string *blacklist;
object *platoon;
object start;

void set_blacklist(string *list);
void add_blacklist(string name);
string *query_blacklist();
int is_hunting_me(object agg);
void do_patrol();
void be_nice();
int warning(string which, object who);

int count;

init() {
  ::init();
}
  
create() {  
  ::create();
  set_name("provost");
  set_id( ({"imperial provost", "provost" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Imperial Provost");
  set_long(
@TSARVEN
This is an Imperial soldier from Tsarven who wears the uniform of a 
provost, or military police guard.  His duties are usually to police 
troops, but they are also called upon to act as a police force in 
occupied areas.  They will enforce the law as it is required.
TSARVEN
  );
  set_class("fighter"); 
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
  new("/d/azha/equip/scimitar")->move(this_object());  
  new("/d/azha/equip/scimitar")->move(this_object());  
  command("wield scimitar in right hand");  
  command("wield scimitar 2 in left hand");  
  new(ARMORDIR+"chain")->move(this_object());  
  command("wear armor");  
  add_money("electrum",random(10));  
  add_money("silver",random(10));  
  add_money("gold",random(40));  
  add_money("copper",random(20));  
  enable_commands();
  blacklist = ({ });
  platoon = ({ });
  add_action("unwield", "unwield");
}

void start_heart(){   
    set_heart_beat(1);
}
    
void heart_beat(){
  do_patrol();
  ::heart_beat();
}

void do_patrol(){
	int y,z,x;
	object *inven, *living_bad, trooper, *weapon;
	string *exits, race;

	living_bad = ({ });  
	if(ETO){
		inven = all_inventory(ETO);
		z = sizeof(inven);
		
		if(in_enforcement) return;
		for(y=0;y<z;y++) {
			if(!interactive(inven[y])) continue;
			if(!newbiep(inven[y])) continue;
			
			// No drow in Shadow allowed
			race = inven[y]->query_race();
			if(race == "drow" && !present("safe-conduct", inven[y])) {
				warning("drow", inven[y]);
				in_enforcement = 1;
				return;
			}
			
			// Shadow outlawed races
			race = inven[y]->query_race();
			if(member_array(race, BAD_RACES) > -1) {
				warning("badrace", inven[y]);
				in_enforcement = 1;
				return;
			}
      
			// Shadow no weapons decree
			if(weapon = inven[y]->query_wielded() && 
				!present("imperial warrant", inven[y])) {
				for(x=0;x<sizeof(weapon);x++) {
					if(objectp(weapon[x]) && weapon[x]->is_weapon()) {
						if(warning("noweapons", inven[y])) {
							in_enforcement = 1;
							continue;
						}
					}
				}
			}
		}
	}
	return;
}

int warning(string which, object who) {
	switch(which) {
		case "drow":
			TO->force_me("yell Drow in the city!  To Arms!");
			break;
		case "noweapons":
			TO->force_me("say Please unwield your weapons in the city.");
			TO->force_me("say Make sure I see you do it, or I'll arrest you!");
			break;
		case "badraces":
			TO->force_me("say Get out of the city, scum!");
			break;
	}
	return 1;
}
		
object *make_backup(string type) {
	object *backup = ({ });
	
	switch(type) {
		case "arrest":
		case "kill":
	}
	return backup;
}

int unwield(string str) {
	object *weaps;
	int x;
	
	weaps = TP->query_wielded();
	for(x=0;x<sizeof(weaps);x++) {
		if(objectp(weaps[x]) && weaps[x]->is_weapon()) {
			TO->force_me("say Let's get them all unwielded.");
			return 0;
		}
	}
	TO->force_me("say Thank you for your cooperation with the decree.");
	return 0;
}

//int warning(string which, object who) {
//	switch(which) {
//		case "drow":
//			if(present("safe-conduct", who)) {
//				TO->force_me("emote looks at the pass.");
//				TO->force_me("say You may pass... drow.");
//				TO->force_me("growl");
//				break;
//			}
//			TO->force_me("yell Drow in the city!  To arms!");
//			call_out("back_up", 10, who);
//			pursue_kill(who);
//			break;
//		case "badraces":
//			if(present("safe-conduct", who)) {
//				TO->force_me("say You may pass....");
//				TO->force_me("frown");
//				break;
//			}
//			TO->force_me("point "+who->query_name());
//			TO->force_me("say Please leave the city, now.  I will escort you out.");
//			call_out("pursue_kill", 20, who);
//			break;
//		case "noweapon":
//			}
//			
//						
//	return 0;
//}

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

