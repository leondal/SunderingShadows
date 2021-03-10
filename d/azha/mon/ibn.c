// Governor Samir ibn Shiraz
// Thorn@ShadowGate
// 12/7/95
// Azha Garrison
// ibnshiraz.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int flag;

create() {
	int level;
	
	::create();
	set_name("Governor ibn Shiraz");
	set_id(({ "shiraz", "ibn shiraz", "governor", "samir" }));
	set_short("Samir ibn Shiraz, Governor of Azha");
	set_long(
@TSARVEN
	Governor ibn Shiraz is an elderly man of about 70 years.  This is
his final post in the service of the Empire before retiring to his
home in Tsarven.  He is a thin man, somewhat frail looking, with
white hair and a matching beard.  At first glance, he seems to be
very unthreatening and weak.  Another glance, though, will hint at
something that is a bit more formidable in this old man.
TSARVEN
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_overall_ac(2);
	set_class("mage");
	level = 35;
	set_hd(level, 4);
	set_exp(15000);
	set_hp(query_max_hp());
	set_guild_level("mage", level);
	set_stats("strength", 9);
	set_stats("constitution", 12);
	set_stats("wisdom", 15);
	set_stats("charisma", 12);
	set_stats("intelligence", 16);
	set_stats("dexterity", 13);
	set_spells(({ "magic missile", "finger of death", "monster summoning vi", "amimate dead" }));
	set_spell_chance(75);
	add_search_path("/cmds/mortal");
	set_wielding_limbs(({ "right hand", "left hand" }));
  new(AEQUIP+"stun_staff")->move(TO); 
  force_me("wield staff in right hand");
}

heart_beat() {
  object atkr,ob;

  ::heart_beat();
   if(!objectp(TO)) return;
  atkr = TO->query_current_attacker();
  if(!atkr) {
  flag = 0;
  if(ob=present("ring of regeneration 2", TO))
    if(!ob->remove()) destruct(ob);
  return;
  }
  if(ob=present("ring of regeneration", TO))
    force_me("wear ring of regeneration");
  if(!query_stoneSkinned()) 
    "cmds/spells/s/_stoneskin"->use_spell(TO,"samir",35, 100, "mage");
  if(flag) return;
  ob=new("/d/azha/obj/regen_ring");
  ob->move(TO);
  flag = 1;
}


