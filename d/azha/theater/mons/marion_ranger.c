#include <std.h>
#include "../theater.h"

inherit "std/monster";
     	void create(){
      object obj;
      ::create();
	set_name("ranger marionette");
	set_id(({"marionette","ranger","ranger marionette","+
		""male marionette","theater_mon"}));
	set_short("A male masked marionette clad in leather");
	set_long("%^GREEN%^Standing about four feet high, this small mari"+
		"onette figure is made from %^YELLOW%^oak wood%^RESET%^%^GREEN%^. "+
		" The jointed figure is clad in a leather breastplate that covers "+
		"his cotton shirt.  His pants are covered with leather chaps.  The"+
		" face of this marionette is hidden behind a fearsome mask.  While"+
		" most marionettes have strings attached to their bodies, this one"+
		" is oddly without any.  A pair of jade claws are strapped to each"+
		" arm.%^RESET%^");
	set_race("construct");
	set_gender("male");
	set_body_type("human");
	set_hd(21,0);
	set_overall_ac(11);
	set_size(2);
	set_class("ranger");
	set_class("cleric");
	set_mlevel("ranger",21);
	set_mlevel("cleric",21);
	set_level(21);
	set_guild_level("ranger",21);
	set_guild_level("cleric",21);
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",18);
	set_stats("charisma",12);
	set_stats("constitution",16);
	set_stats("wisdom",14);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/ranger");
	add_search_path("/cmds/cleric");
	set_diety("silvanus");
	set_spell_chance(20);
	set_property("add kits",3);
	set_spells( ({ "limb attack","hold person"}) );
	obj = new("/d/laerad/obj/bracers3");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj = new("/d/common/obj/armour/leather.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",3);
	obj->move(TO);
	obj=new(OBJ"jadeclaws");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"jadeclaws");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"menshirt");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj = new("/d/shadow/room/meadows/obj/r_pants.c");
	obj->move(TO);
		switch(random(8)){
case 0..3:
	obj=new(OBJ"tigermask");
	obj->move(TO);
	command("wear mask");
break;
default:
	obj=new(OBJ"griffonmask");
	obj->move(TO);
	command("wear mask");
break;
		}
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	command("wield claws");
	command("wield claws 2");
	force_me("wearall");
	add_money("electrum",random(50)+170);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(40)+375);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
      set_exp(random(500)+3000);
	  set_max_level(15);
	set_languages( ({ "common"}) );
	force_me("message in stalks in slowly");
      force_me("message out slowly stalks $D");
   set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl"
   }));
   set_funcs(({"whirlit"}));
   set_func_chance(30);
}
void die(object ob) {
    new(OBJ"handcrank")->move(TO);
    ::die(ob);
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}
