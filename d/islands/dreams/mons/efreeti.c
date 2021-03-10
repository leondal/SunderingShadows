#include <std.h>
#include "../defs.h"
inherit "std/monster";
     	create(){
     	object obj; 
	::create();
	set_name("efreeti genie");
	set_id(({"efreeti","genie"}));
  	set_short("%^BOLD%^%^RED%^An efreeti genie%^RESET%^");
  	set_long("%^ORANGE%^This efreeti is a hulking figure "+
		"standing twelve feet tall.  His dark %^MAGENTA%^purple"+
		"%^ORANGE%^ skin ripples with an excess of muscle.  A"+
		" shaggy mane of burnt orange hair flows over his thick"+
		" neck and wide shoulders.  A pair of pointed "+
		"%^BOLD%^%^WHITE%^ivory%^RESET%^%^ORANGE%^ horns rise"+
		" from his brow.  His %^BOLD%^%^RED%^fiery red%^RESET%^"+
		"%^ORANGE%^ eyes seem to burn deep into your soul as he "+
		"meets your gaze.  Dressed in a suit of half-plate armor,"+
		"this genie looks intimidating.");
  	set_race("efreeti");
  	set_body_type("human");
  	set_gender("male");
  	set_size(3);
  	set_hd(35,2);
  	set("aggressive",1);
  	set_class("cleric");
  	set_mlevel("cleric",35);
  	set_hp(random(150)+870);
	set_max_level(40);
      	set_mob_magic_resistance("average");
  	set_exp(8000);
  	set_overall_ac(5);
  	set_funcs(({"spells"}));
  	set_func_chance(65);
  	set_alignment(9);
	obj = new("/d/dagger/derro/obj/flameblade.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"halfplate");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield sword");
	command("wearall");
    if(!random(15)) {
      obj = new("/d/common/obj/brewing/herb_special_inherit");
      obj->set_herb_name("dream fragment");
      obj->move(TO);
    }
}

void spells(object targ)
{
  switch(random(100))
  {
    case 0..20:
	new("/cmds/spells/f/_fireball")->use_spell(TO,targ,20,100,"mage");
	break;
    case 21..60:
	new("/cmds/spells/s/_scorcher")->use_spell(TO,targ,20,100,"mage");
	break;
    case 61..80:
	new("/cmds/spells/f/_fire_storm")->use_spell(TO,targ,20,100,"cleric");
	break;
    case 81..99:
	new("/cmds/spells/f/_flame_strike")->use_spell(TO,targ,20,100,"cleric");
	break;
  }
}

void die(object ob)
{
	
  	new(OBJ"rcryst")->move(TO);
	new(OBJ"halfplate")->move(TO);	
	tell_room(ETO,"%^RED%^From within the flames a red crystal falls.");
  	::die(ob);
}
