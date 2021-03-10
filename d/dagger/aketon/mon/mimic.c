#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int flag;

void create(){
	::create();
	set_name("mimic");
	set_short("%^BOLD%^%^MAGENTA%^A large chest");
   set_id(({"mimic","chest"}));
	set_long(
		"%^WHITE%^"+
		"You see a large chest.  It appears to be made of wood and iron and "+
		"is large enough to hold much treasure or other items.  The lock "+
		"appears to be built into the front of the chest.%^RESET%^"
	);
	set_property("no bows",1);
	set_race("mimic");
	set_gender("neuter");
	set_body_type("snake");
	set_hd(25,10);
	set_max_hp(250 + random(100));
	set_hp(query_max_hp());
	set_alignment(9);
	set_overall_ac(-10);
	set_class("fighter");
	set_mlevel("fighter",25);
	set_level(25);
	set_property("full attacks",1);
	set_max_level(25);
	set_exp(10000);
	set_stats("strength",15 + random(4));
	set_stats("intelligence",random(3) + 2);
	set_stats("wisdom",random(3) + 2);
	set_stats("dexterity",12 + random(7));
	set_stats("constitution",12 + random(7));
	set_stats("charisma",random(5) +1);
	set("aggressive",0);
	set_property("weapon resistance",1);
	remove_limb("head");
	remove_limb("tail");
	add_limb("right pseudopod","torso",0,0,0);
	add_limb("left pseudopod","torso",0,0,0);
	add_limb("teeth","mouth",0,0,0);
	set_attack_limbs(({
		"right pseudopod",
		"left pseudopod",
		"teeth",
		"right pseudopod",
		"left pseudopod"
	}));
	set_attacks_num(5);
	set_damage(3,4);
	set_base_damage_type("bludgeoning");
	set_funcs(({"chomp"}));
    	set_func_chance(25);
    	flag = 0;

}
void init(){
	string mrace=TP->query_race();
	::init();
	add_action("pick_em","pick");
	add_action("get_em","get");
	add_action("open_em","open");
	add_action("move_em","move");
	add_action("kill_em","kill");
	add_action("stab_em","stab");
	add_action("rush_em","rush");
	ETO->add_item("chest","%^WHITE%^You see a large chest.  "+
		"It appears to be made of wood and iron and is large enough to hold "+
		"much treasure or other items.  The lock appears to be built into "+
		"the front of the chest.%^RESET%^");
	ETO->add_item("large chest","%^WHITE%^You see a large chest.  "+
		"It appears to be made of wood and iron and is large enough to hold "+
		"much treasure or other items.  The lock appears to be built into "+
		"the front of the chest.%^RESET%^");
	force_me("watch");
}
int pick_em(string str) {
  	if(str == "lock on chest" || str == "chest" || str == "large chest" || str == "lock on large chest"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int get_em(string str) {
  	if(str == "chest" || str == "large chest"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int kill_em(string str) {
  	if(str == "chest" || str == "large chest" ||str == "mimic"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int stab_em(string str) {
  	if(str == "chest" || str == "large chest" ||str == "mimic"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int rush_em(string str) {
  	if(str == "chest" || str == "large chest" ||str == "mimic"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int move_em(string str) {
  	if(str == "chest" || str == "large chest"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
int open_em(string str) {
  	if(str == "chest" || str == "large chest"){
    		call_out("hurt_em", 0, TP);
		return 0;
      }
      return 0;
}
void chomp(object targ){
	int dex,para;
	dex = targ->query_stats("dexterity");
	if(random(20) > dex) {
		tell_object(targ,"%^RED%^The mimic bites down hard on your arm!%^RESET%^");
		tell_room(ETO,"%^RED%^The mimic bites down "+
			"on "+targ->query_cap_name()+"'s arm.%^RESET%^",targ);
		targ->do_damage("arm", roll_dice(3,10));
		targ->add_attacker(TO);
		targ->continue_attack();
		para = random(8) + 3;
	     	targ->set_paralyzed(para,"%^CYAN%^You are held fast in the mimic's mouth!");
	}else {
		tell_object(targ,"%^CYAN%^The mimic snaps at you, but "+
			"you move just in time.");
		tell_room(ETO,"%^CYAN%^The mimic tries to "+
			"bite "+targ->query_cap_name()+", but misses.",targ);
	}
}
void hurt_em(object targ){
	int para;
	if(flag == 0){
		flag = 1;
		force_me("watch");
		tell_object(targ,"%^BOLD%^%^RED%^You touch the chest and become "+
			"stuck fast.\nThe chest grows two club-like appendages and "+
			"starts beating you with them while opening it's huge, toothy "+
			"maw hungrily.");
		targ->force_me("emote gasps and looks worried");
		tell_room(ETO,"%^RED%^"+targ->query_cap_name()+" touches the chest and "+
			"it comes alive.\nTwo club-like appendages grow from the chest and "+
			"start beating "+targ->query_cap_name()+" in an effort to "+
			"get "+targ->query_objective()+" into the chest's large toothy maw.",targ);
		ETO->remove_item("large chest");
		ETO->remove_item("chest");
		set_long("The chest has changed colors and is now speckled grey and "+
			"looks like it is made of stone.  Two club-like pseudopods wave "+
			"about menacingly and a large toothy maw appears in the center.  "+
			"How could anyone have mistaken this ugly beast for a locked chest?");
	}else{
		tell_object(targ,"%^BOLD%^%^RED%^You touch the chest and become "+
			"stuck fast.\nThe chest bites at you hungrily.");
		targ->force_me("emote gasps!");
		tell_room(ETO,"%^RED%^"+targ->query_cap_name()+" touches the chest and "+
			"it comes alive.\nThe chest starts "+
			"beating "+targ->query_cap_name()+" in an effort to "+
			"get "+targ->query_objective()+" into the chest's large toothy maw.",targ);
	}
	force_me("kill "+targ->query_name());
	para = random(20) + 10;
	targ->set_paralyzed(para,"You are stuck in strong glue coating the chest.");
}
void heart_beat(){
  	object atkr;

  	if(!objectp(TO)) return;
  	::heart_beat();
  	if(flag == 0)return;
  	atkr = query_current_attacker();
  	if(!atkr) {
		tell_room(ETO,"The mimic quiets and slowly changes "+
  			"colors and shape until it once again resembles "+
  			"a large innocent looking chest.");
  		set_long("%^WHITE%^You see a large chest.  It appears to be made of wood "+
			"and iron and is large enough to hold much treasure or "+
			"other items.  The lock appears to be built into the "+
			"front of the chest.%^RESET%^");
		ETO->add_item("large chest","%^WHITE%^You see a large chest.  "+
			"It appears to be made of wood and iron and is large enough to hold "+
			"much treasure or other items.  The lock appears to be built into "+
			"the front of the chest.%^RESET%^");
		ETO->add_item("chest","%^WHITE%^You see a large chest.  "+
			"It appears to be made of wood and iron and is large enough to hold "+
			"much treasure or other items.  The lock appears to be built into "+
			"the front of the chest.%^RESET%^");
		flag = 0;
    		return;
  	}
}
void die(object ob){
	ETO->remove_item("large chest");
	ETO->remove_item("chest");
	::die(ob);
}
