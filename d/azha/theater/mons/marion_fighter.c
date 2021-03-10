#include <std.h>
#include "../theater.h"

inherit "std/monster";
     	void create(){
     	object obj; 
      ::create();
	set_name("fighter marionette");
	set_id(({"marionette", "fighter","fighter marionette""+
		" , "male marionette", "theater_mon"}));
	set_short("A male marionette clad in platemail");
	set_long("%^GREEN%^Standing about four feet high, this small"+
		" marionette figure is made from %^RED%^cherry wood%^GREEN%^."+
		"  The jointed figure is clad in a %^CYAN%^steel breastplate"+
		"%^GREEN%^ that covers his long sleeved shirt.  His cotton "+
		"pants are covers with graves and leg plates.  Covering the"+
		" marionette's head is a visorless steel helmet.  His%^BOLD%^"+
		" bright green%^RESET%^%^GREEN%^ eyes seem to leap off of the"+
		" dark wood.  While most marionettes have strings attached to"+
		" their bodies, this one is oddly without any.  His wooden fi"+
		"ngers and hands are wrapped around a large axe that is nea"+
		"rly twice his size. %^RESET%^");
	set_race("construct");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(7);
	set_hd(20,0);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_guild_level("fighter",20);
	set_size(1);
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",16);
	set_stats("charisma",12);
	set_stats("constitution",18);
	set_stats("wisdom",12);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	obj = new(OBJ"malebplate");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"runeaxe");
	obj->set_property("monsterweapon",1);
	obj->set_size(1);
	obj->move(TO);
	obj=new("/d/common/obj/rand/rand_shirts.c");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->add_property("enchantment",1);
	obj->move(TO);
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj = new("/d/common/obj/armour/helm.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",1);
	obj->move(TO);
	obj = new("/d/shadow/room/meadows/obj/r_pants.c");
	obj->move(TO);
	command("wield axe");
	force_me("wearall");
	set_property("add kits",3);
	add_money("electrum",random(50)+70);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(50)+320);
      set_hp(query_max_hp());
      set_property("swarm",1);
	set("aggressive",18);
	set_parrying(1);
	set_funcs(({"rushit","flashit","flashit"}));
	set_func_chance(30);
    set_exp(random(500)+3000);
	set_max_level(15);
	set_languages( ({ "common"}) );
	force_me("message in walks in dragging a large sword");
      force_me("message out drags his sword $D");
    set_monster_feats(({
      "parry",
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));	  
}
void rushit(object targ) {
	TO->force_me("say %^GREEN%^Come, join our little performance.");
  	TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  TO->force_me("flash "+targ->query_name());
}
