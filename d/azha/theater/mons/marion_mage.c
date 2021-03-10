#include <std.h>
#include "../theater.h"

inherit "std/monster";
      void create(){
      object obj; 
      ::create();
	set_name("sorceress marionette");
	set_id(({"marionette","sorceress","sorceress marionette","+
		""female marionette","mage","mage marionette""+
		", "theater_mon"}));
	set_short("A female marionette wearing a velvet dress");
	set_long("%^GREEN%^Standing about four feet high, this sm"+
		"all marionette figure is made from %^BLUE%^willow wood"+
		"%^GREEN%^.  The jointed figure is clothed in a flowing"+
		" velvet dress. Her%^BOLD%^%^WHITE%^ silvery %^YELLOW%^"+
		"blonde%^RESET%^%^GREEN%^ hair has been braided into a sin"+
		"gle thick braid.  Her %^RESET%^cloudy gray%^GREEN%^ eyes"+
		" seem mysterious yet powerful at the same time.  While mo"+
		"st marionettes have strings attached to their bodies, thi"+
		"s one is oddly without any.  In her wooden hand and finge"+
		"rs she holds a colorful %^RESET%^");
	set_race("construct");
	set_gender("female");
	set_body_type("human");
	set_hd(21,0);
	set_class("mage");
	set_mlevel("mage",21);
	set_level(21);
	set_guild_level("mage",21);
	set_overall_ac(6);
	set_size(2);
	set_stats("strength",17);
	set_stats("intelligence",18);
	set_stats("dexterity",18);
	set_stats("charisma",15);
	set_stats("constitution",10);
	set_stats("wisdom",14);
	set_alignment(5);
	set_mob_magic_resistance("average");
	add_search_path("/cmds/mage");
	set_spell_chance(95);
	set_spells( ({"prismatic spray",
	"ball lightning",
      "acid orb",
      "acid breath",
      "cone of cold",
	"scorcher",
      "scorcher",
      "acid orb"}) );
	obj = new("/d/laerad/obj/bracers2");
	obj->move(TO);
	obj=new(OBJ"lunarfan");
if(random(2))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new("/d/common/obj/rand/randrobe.c");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);

	command("wield fan");
	force_me("wearall");
	add_money("electrum",random(50)+170);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(30)+300);
    set_hp(query_max_hp());
    set_property("swarm",1);
	set_property("add kits",3);
    set("aggressive","aggfunc");
    set_exp(random(500)+3000);
	set_max_level(15);
	set_languages( ({ "common"}) );
}
int aggfunc() {
	if(!TP->query_true_invis()) kill_ob(TP,1);
		call_out("spell_effect",1);
      	force_me("kill "+TPQN+ "");
		return 1;
}

void die(object ob) {
    new(OBJ"marbleflute")->move(TO);
    ::die(ob);
}
int spell_effect(){
   force_me("watch");
   		command("cast blink");
   		command("cast stoneskin on marionette");
   		command("cast monster summoning v");
}
