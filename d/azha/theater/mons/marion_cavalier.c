//Added feats - Octothorpe 7/7/10
#include <std.h>
#include "../theater.h"

inherit "std/monster";
      void create(){
      object obj; 
      ::create();
	set_name("cavalier marionette");
	set_id(({"marionette", "cavalier","cavalier marionette""+
		" , "male marionette", "theater_mon"}));
	set_short("A blonde male marionette clad in platemail");
	set_long("Standing about four feet high, this small"+
		" marionette figure is made from %^YELLOW%^pine"+
		"%^RESET%^%^GREEN%^.  The jointed figure is dressed "+
		"in a %^BOLD%^%^WHITE%^silvery %^BLUE%^blue%^RESET%^"+
		"%^GREEN%^ breastplate over his cotton shirt.  Over "+
		"his pants steel plates and graves offer added prote"+
		"ction. A %^ORANGE%^regal crown%^GREEN%^ rests on "+
		"his curly %^YELLOW%^blonde%^RESET%^%^GREEN%^ head."+
		"  His %^BOLD%^bright green %^RESET%^%^GREEN%^eyes set"+
		" off the golden luster of his hair"+
		"  While most marionettes have strings attached to "+
		"their bodies, this one is oddly without any.  With"+
		" a shield in one hand and a flail in the other, th"+
		"is little marionette looks majestic upon his woode"+
		"n horse. %^RESET%^");
	set_race("construct");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(9);
	set_hd(20,0);
	set_class("cavalier");
	set_mlevel("cavalier",20);
	set_level(20);
	set_guild_level("cavalier",20);
	set_size(2);
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",15);
	set_stats("charisma",15);
	set_stats("constitution",18);
	set_stats("wisdom",12);
	set_alignment(5);
      set_property("add kits",3);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/cavalier");
	obj = new(OBJ"malebplate");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"regalcrown");
if(random(2))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"menshirt");
	obj->move(TO);
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj = new(OBJ"chessflail");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj = new(OBJ"steelshield");
	obj->move(TO);
	obj = new("/d/shadow/room/meadows/obj/r_pants.c");
	obj->move(TO);
	command("wield flail");
	force_me("wearall");
	add_money("electrum",random(50)+70);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(50)+320);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
	set_parrying(1);
	set_exp(random(500)+3000);
	set_max_level(15);
	set_languages( ({ "common", "wizish" }) );
	force_me("message in rides in on a wooden horse");
    force_me("message out rides the wooden horse $D");
	call_out("do_horse",1);
	set_monster_feats(({
	   "shieldbash",
	   "shieldwall",
	   "deflection",
	   "reflection",
	   "counter",
	   "parry",
	   "mounted combat",
	   "indomitable",
	   "ride-by attack",
	   "charge",
	   "force of personality"
   }));	 
   set_funcs(({
      "bashit",
	  "charge"
   }));
   set_func_chance(30);
}

void do_horse(){
  	object horse;
  	if(!objectp(ETO)) return;
  		horse=new(MOB"woodenhorse");
  		horse->set_owner(TO);
  		horse->move(ETO);
 		command("mount horse");
}

void bashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shieldbash "+targ->query_name());
}

void chargeit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("charge "+targ->query_name());
}