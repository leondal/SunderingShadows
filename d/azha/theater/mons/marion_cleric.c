#include <std.h>
#include "../theater.h"

inherit "std/monster";
      void create(){
      object obj;
      ::create();
	set_name("cleric marionette");
	set_id(({"marionette","cleric","cleric marionette","+
		""female marionette","theater_mon"}));
	set_short("A female marionette clad in scalemail");
	set_long("%^GREEN%^Standing about four feet high, this small mar"+
		"ionette figure is made from %^RESET%^birch wood%^GREEN%^.  The j"+
		"ointed figure is clad in a %^BOLD%^%^WHITE%^pleated scalemail%^RESET%^"+
		"%^GREEN%^ that covers her velvet dress.  Her head is left unadorned,"+
		" with her %^RED%^dark red hair%^GREEN%^ fixed in a tight bun at the"+
		" base of her neck.  Her %^BOLD%^%^CYAN%^cold blue eyes%^RESET%^%^GREEN%^"+
		" gaze out at the world with a sour look on her face.  While most mari"+
		"onettes have strings attached to their bodies, this one is oddly with"+
		"out any.  An ebony and ivory flail is clutched in her hands.%^RESET%^");
	set_race("construct");
	set_gender("female");
	set_body_type("human");
	set_hd(21,0);
	set_class("cleric");
	set_mlevel("cleric",21);
	set_level(21);
	set_guild_level("cleric",21);
	set_overall_ac(9);
	set_size(2);
	set_stats("strength",17);
	set_stats("intelligence",10);
	set_stats("dexterity",15);
	set_stats("charisma",15);
	set_stats("constitution",16);
	set_stats("wisdom",18);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/cleric");
	set_diety("loviatar");
	set_spell_chance(55);
	set_spells( ({ "kiss of torment",
	"wave of pain",
      "flame strike",
 	"kiss of torment",
      "flame strike",
      "dispel magic",
      "wave of pain"}) );
	set_funcs(({ "turnit"}));
	set_func_chance(30);
    set_property("add kits",3);
	obj = new("/d/common/obj/armour/scale.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",4);
	obj->move(TO);
	obj=new(OBJ"chessflail");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"womendress");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"steelshield");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	command("wield flail");
	force_me("wearall");
	add_money("electrum",random(50)+70);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(40)+250);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set("aggressive",18);
    set_exp(random(500)+3000);
	set_max_level(15);
	set_languages( ({ "common" }) );
    set_monster_feats(({
	   "shieldbash",
	   "shieldwall",
	   "deflection",
	   "reflection",
	   "counter"
    }));
}

int turnit(){
	command("turn undead");
	return 1;
}

void bashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shieldbash "+targ->query_name());
}
