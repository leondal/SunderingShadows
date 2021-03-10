#include <std.h>
#include "../theater.h"

inherit "std/monster";
     void create(){
      object obj; 
      ::create();
	set_name("thief marionette");
	set_id(({"marionette", "thief","thief marionette" , "+
		""male marionette","theater_mon"}));
	set_short("A male marionette clad in leather");
	set_long("%^GREEN%^Standing about four feet high, this small "+
		"marionette figure is made from %^YELLOW%^cypress%^RESET%^"+
		"%^GREEN%^ wood.  The jointed figure is clad in a leather "+
		"breastplate that covers his %^BOLD%^%^BLACK%^dark suit"+
		"%^RESET%^%^GREEN%^.  A fuzzy hood with cat like ears covers"+
		" his head, hiding his hair.  With his %^BLUE%^deep blue "+
		"%^GREEN%^eyes, his smirk seems charming.  While most marionettes"+
		" have strings attached to their bodies, this one is oddly withou"+
		"t any.  A pair of daggers are clutched in his wooden hands.%^RESET%^");
	set_race("construct");
	set_gender("male");
	set_body_type("human");
	set_hd(18,4);
	set_overall_ac(6);
	set_size(2);
	set_class("thief");
// tuned down from L21, the change to stab has made it a bit broken. N, 5/18.
	set_mlevel("thief",18);
	set_level(18);
	set_guild_level("thief",18);
	set_property("full attacks",1);
	add_search_path("/cmds/thief");
	set_stats("strength",17);
	set_stats("intelligence",10);
	set_stats("dexterity",18);
	set_stats("charisma",16);
	set_stats("constitution",16);
	set_stats("wisdom",12);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	set_scrambling(1);
	add_attack_bonus(3);
      set_property("add kits",3);
	obj = new("/d/common/obj/armour/leather_plate.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",3);
	obj->move(TO);
	obj = new("/d/laerad/obj/bracers3");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"roguesuit");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"cathood");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"r_shoes");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj = new(OBJ"moonshadow");
	if(random(4)){
	obj->set_property("monsterweapon",1);
	}
	obj->move(TO);
	obj = new("/d/islands/pirates/obj/sawdagger.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield dagger");
	command("wield sword");
	force_me("wearall");
	add_money("electrum",random(50)+70);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(30)+250);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive","do_stuff"); 
	set_invis();
	set_exp(random(500)+3000);
	set_max_level(15);
	set_languages("common");
	force_me("message in tumbles in");
      force_me("message out tumbles $D");
    set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes"
    }));     
}
void do_stuff(){
        if(interactive(TP) && !TP->query_invis()){
                set("aggressive",17);
                call_out("attack",5,TP);
        }
}       
void attack(object targ){
        if(!objectp(targ) && !objectp(TO))  return;
        if(targ->query_invis())   return;
        command("stab "+targ->query_name());
        set_invis();
}

void die(object ob){
	if(!random(3)) {
		new(OBJ"cathood")->move(TO);
    		}
	::die(ob);
}