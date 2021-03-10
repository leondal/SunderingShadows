#include <std.h>
#include "../theater.h"
inherit "std/monster";
        void create(){
          object obj;
        ::create();
	set_name("bard marionette");
	set_id(({"marionette","bard","bard marionette","+
		""female marionette","theater_mon"}));
	set_short("A dark haired female marionette");
	set_long("%^GREEN%^Standing about four feet high, this"+
		" small marionette figures is made from %^YELLOW%^chest"+
		"nut wood%^RESET%^%^GREEN%^.  The jointed figure is wea"+
		"ring a stylish leather breastplate over her flowing ve"+
		"lvet dress.  Her %^BOLD%^%^BLACK%^raven black%^RESET%^"+
		"%^GREEN%^ hair spirals in tight curls around her face,"+
		" adding to her classical beauty.  Her large %^ORANGE%^"+
		"coffee brown%^GREEN%^ eyes give her a look of innocenc"+
		"e.  While most marionettes have strings attached to th"+
		"eir bodies, this one is oddly without any.  In her woo"+
		"den hand she holds a darksteel rapier. %^RESET%^");
	set_race("construct");
	set_gender("female");
	set_body_type("human");
	set_hd(21,0);
	set_class("mage");
	set_mlevel("mage",21);
	set_level(21);
	set_guild_level("mage",21);
	set_overall_ac(8);
	set_size(1);
	set_stats("strength",15);
	set_stats("intelligence",16);
	set_stats("dexterity",18);
	set_stats("charisma",18);
	set_stats("constitution",14);
	set_stats("wisdom",12);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/mage");
	set_spell_chance(50);
	set_spells( ({"shout",
	"sonic orb",
      "sonic orb",
      "hideous laughter",
      "sonic shield"}) );
	set_property("add kits",3);
	obj = new("/d/laerad/obj/bracers2");
	obj->move(TO);
	switch(random(12)){
		case 0..4:
			obj=new(OBJ"frogsuit");
			obj->move(TO);
		break;
		case 5..8:
			obj=new(OBJ"squirrelsuit");
			obj->move(TO);
		break;
		default:
			obj=new(OBJ"tabbycatsuit");
			obj->move(TO);
		break;
		}
	obj=new(OBJ"bardchoker");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/rand/randrobe.c");
if(random(2))
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
	obj=new(OBJ"songblade");
	obj->move(TO);
	command("wield rapier");
	force_me("wearall");
	add_money("electrum",random(50)+70);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(30)+300);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set("aggressive","aggfunc");
    set_exp(random(500)+3000);
	set_max_level(15);
	set_languages( ({ "common"}) );
	}
int aggfunc() {
	if(!TP->query_true_invis()) kill_ob(TP,1);
		call_out("spell_effect",1);
		force_me("kill "+TPQN+"");
}
int spell_effect(){
		force_me("watch");
   		command("cast blink");
   		command("cast stoneskin on marionette");
   		command("cast monster summoning ii");
		return 1;
}

void die(object ob) {
    new(OBJ"marblelute")->move(TO);
	if(!random(3)) {
		new(OBJ"bardchoker")->move(TO);
    		}
    ::die(ob);
}
