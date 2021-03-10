// Imperial Spell Seeker
// Thorn@ShadowGate
// 000921 
// Imperial Army of Tsarven
// seeker.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

// Delay HBs between reinforcements being called in.
#define DELAY 5

inherit "/d/azha/std/wander";

int build, reload, force_delay, timer;
int rift_uses, patrol_timer;
string *outs,*exit_dir;
string *blacklist;
object start, to, from;

void do_seeking();
void self_preservation();
void flee();
int open_rift();
int close_rift();

int count;

create() {  
  object ob;
  
  ::create();
  set_name("Elven spell seeker");
  set_id( ({"imperial spell seeker", "seeker", "spell seeker" }) );
  set("race", "elf");
  set_gender("male");
  set("short", "Imperial Spell Seeker");
  set_long(
@TSARVEN
  This is an Elven spell seeker of the Tsarvani Imperial Army.  While
humans make up the great majority of the Imperial Army, specially
trained elves are taught some skills of divining and interrupting
certain magical abilities. As these types of soldier are extremely
valuable, they are always kept invisible and never engage in battle if
they can avoid it. 
TSARVEN
  );
  set_class("mage"); 
  set_level(20);  
  set_hd(20,0);     
  set_exp(2000);
  set_body_type("elf");  
  set_alignment(1);  
  set_size(2);  
  set_mob_magic_resistance("average");
  set_stats("intelligence",16);  
  set_stats("wisdom",12);  
  set_stats("strength",10);  
  set_stats("charisma",10);  
  set_stats("dexterity",15);  
  set_stats("constitution",12);
  set_max_hp(40);
  set_hp(query_max_hp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );  
  ob = new(ARMORDIR+"robe");
  ob->set_property("monsterweapon", 1);
  ob->move(this_object());  
  command("wear robe");  
  ob = new("/d/azha/obj/rift_key");
  ob->set_property("monsterweapon", 1);
  ob->move(this_object());  
  command("wear key");  
  add_money("silver",random(10));  
  add_money("gold",random(10));  
  add_money("copper",random(20));  
  enable_commands();
  set_invis();
  blacklist = ({ });
  rift_uses = 4;
}

void start_heart(){   
    set_heart_beat(1);
}
    
void heart_beat(){
  object ob;
  if(ETO && !start) {
  	start = ETO;
	if(ob = present("key")) ob->riftgate("set");
  }
  count++;
  if(force_delay) force_delay--;
  self_preservation();
  do_seeking();
  timer++;
  patrol_timer++;
  if(timer > 25){
    timer = 0;
    if(!query_invis()){
      if(query_attackers() == ({}) ){
        set_invis();
      }
    }
  }
  if(patrol_timer > 90){
    if(rift_uses < 4) rift_uses++;
    patrol_timer = 0;
    if(ETO != start){
      TO->move(start);
    }
  }
  ::heart_beat();
}

void do_seeking(){
  int y,z;
  object *inven, *living_bad, trooper;
  string *exits;

  living_bad = ({ });  
  if(ETO){
    inven = all_inventory(ETO);
    z = sizeof(inven);
    
    for(y=0;y<z;y++) {
      if(interactive(inven[y]) && (member_array((string)inven[y]->query_name(), blacklist) != -1)){
        living_bad += ({inven[y]});
		if(!force_delay) {
		  command("yell Enemy detected in the area!!  Sound the alarm!");
		}
      }
      else if(living(inven[y]) && ((string)inven[y]->query_race() == "drow") &&
	         (!inven[y]->query_invis())){
		if(!force_delay) {
		  command("yell Drow detected in the area!!  To arms!!");
		}
      }
    }
    if(sizeof(living_bad) && !force_delay){
      force_delay = DELAY;
	  "/cmds/spells/d/_dispel_magic"->use_spell(TO, 0, 20, 100, "mage");
	  flee();
	}
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

void self_preservation() {
  object *inven;
  int i,j;
  string *exits;
  
  if(!objectp(TO)) return;
  if(!ETO) return;
  if(!sizeof(inven = query_attackers())) return;
  flee();
  return;
}

void flee() {
  object *inven;
  object key;
  int i,j;
  string *exits;
  
  if(!objectp(TO)) return;
  if(!ETO) return;
  j = sizeof(exits = ETO->query_exits());
  if(!j) {
	  if(start = ETO) return;
    if(key = present("rift key")) {
	  if(!rift_uses) {
		key->remove();
		return;
      }
      tell_room(ETO,
        "%^BOLD%^Finding no other way out the Seeker's hand moves to a key at his neck!%^RESET%^");
      if (start->query_property("no teleport")) return;
      else{
		to = start;
		from = ETO;
        open_rift();
		command("rift");
        close_rift();	
      }
	}
	else return;
  }
  else {
    i = random(j);
    tell_room(ETO,
      "%^BOLD%^The seeker flees from the battle!%^RESET%^");
    cease_all_attacks();
    reset_hunted();
	force_me("riftgate set");
    command(exits[i]);
  }
  cease_all_attacks();
  reset_hunted();
  return;
}

int open_rift(){
   if(!random(5)){
      write("The rift gate sputters and blows up in your hand.");
      TP->cause_typed_damage(TP, "torso", random(25), "force");
      TO->remove();
   }
   tell_room(from, TO->query_cap_name()+" taps thin air with a little key and a rift portal appears from nowhere!",({TO}));
   tell_room(to, "A bright point of light appears from nowhere and suddenly it opens into a shimmering rift portal!!");
   to->add_exit(base_name(from), "rift");
   from->add_exit(base_name(to), "rift");
   rift_uses--;
   return 1;
}

int close_rift(){
   tell_room(from, "The rift gate rapidly shrinks and collapses into nothingness!");
   tell_room(to, "The dimensional rift gate in front of you flashes and then shrinks into oblivion!");
   to->remove_exit("rift");
   from->remove_exit("rift");
   return 1;
}
