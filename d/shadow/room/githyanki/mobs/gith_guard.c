// Githyanki Guard  - LoKi - 01-02-2008 ((gith_guard.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("githyanki");
    set_id(({"githyanki","monster","guard","githyanki guard"}));
    set_race("githyanki");
    set_gender("male");
    set_short("%^RESET%^%^MAGENTA%^githyanki guard%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This humanoid is tall, gaunt, and almost"+ 
	    " elven in its lithe movements. It has ro%^RESET%^%^YELLOW%^u%^RES"+
		"ET%^%^ORANGE%^gh %^RESET%^%^YELLOW%^y%^RESET%^%^ORANGE%^e%^RESET"+
		"%^%^YELLOW%^llow %^RESET%^%^ORANGE%^skin and %^RESET%^%^RED%^rus"+
		"%^RESET%^%^ORANGE%^s%^RESET%^%^RED%^et %^RESET%^%^ORANGE%^hair t"+
		"hat flows freely down its back. It's ears are long and mostly po"+
		"inted, and its eyes seem to hold a %^RESET%^%^BOLD%^%^WHITE%^g%^"+
		"RESET%^%^BOLD%^%^BLACK%^l%^RESET%^%^BOLD%^%^WHITE%^imm%^RESET%^%"+
		"^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^r %^RESET%^%^ORANGE%^of somet"+
		"hing malign. It wears a set of %^RESET%^%^BOLD%^%^WHITE%^bracers "+
		"%^RESET%^%^ORANGE%^and brandishes a %^RESET%^%^BLACK%^%^BOLD%^barb "+
        "%^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^WHITE%^sword %^RE"+
        "SET%^%^ORANGE%^with obvious skill%^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(17);
    set_hd(17,2);
    set_max_hp(random(50)+150);
    set_hp(query_max_hp());
    set_overall_ac(2);
     // set_speed(20);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
      
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set_class("psion");
    set_mlevel("fighter",20);
    set_mlevel("psion",17);
    set_guild_level("psion",17);

    set_exp(8000);
    set_max_level(25);

    add_money("gold",random(500));
    add_money("silver",random(200));
    add_money("electrum",random(300));

    set_spell_chance(10);
    set_spells(({"power leech"}));

    set_body_type("human");
		
		
    ob = new(OBJ"lesser_silver_sword");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield sword");
    
    ob = new (OBJ"tiamat_barb");
    ob->move(TO);
    if(random(4)){
	
        ob->set_property("monsterweapon",1);
    }
    command("wield barb");
    
    ob = new("/d/common/obj/armour/bracers");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear bracers");
		
    set("aggressive","agg_func");
    set_emotes(10,({"%^BLACK%^%^BOLD%^The guard shifts his weight from foot to"+
" foot%^RESET%^","%^BLACK%^%^BOLD%^The guard tilts his head, as if listening "+
"to an unheard voice"}),0);
    set_achats(10,({"%^BLACK%^%^BOLD%^The guard screams in some "+
"unknown language as they rush at you%^RESET%^","%^BLACK%^%^BOLD%^The "+
"guard presses his advantage%^RESET%^"}));
}

void agg_func() {
    if (TP->query_invis()) {return;}
    force_me("emoteat "+TPQN+ " %^BLACK%^%^BOLD%^With an evil glint in $M's eyes, $M rushes $N.%^RESET%^");
    force_me("kill "+TP->query_name());
    force_me("rush "+TP->query_name());
return;
}
