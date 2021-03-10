// Githyanki Captain  - LoKi - 01-02-2008 ((gith_guard.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("githyanki");
    set_id(({"githyanki","monster","captain","githyanki guard","Pakek'Tin","Pakek'Tin Githyanki Captain"}));
    set_race("githyanki");
    set_gender("male");
    set_short("%^RESET%^%^RED%^Pa%^RESET%^%^BOLD%^%^RED%^k%^RESET%^%^RED%^ek"+
"'T%^RESET%^%^BOLD%^%^RED%^i%^RESET%^%^RED%^n, Gi%^RESET%^%^BOLD%^%^BLACK%^"+
"t%^RESET%^%^RED%^hyanki Capta%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^"+
"n%^RESET%^");
    set_long("%^RESET%^%^RED%^Dressed in %^RESET%^%^ORANGE%^studded armor "+
"%^RESET%^%^RED%^and a set of %^RESET%^%^BOLD%^%^BLACK%^bracers"+
"%^RESET%^%^RED%^, this githyanki is an almost gaunt elven figure. He stands"+
" like a lord in the stables, looking over the racks of %^RESET%^%^BOLD%^"+
"%^BLACK%^tack %^RESET%^%^RED%^and %^RESET%^%^ORANGE%^saddles %^RESET%^"+
"%^RED%^with a master's eye. He wields %^RESET%^%^BOLD%^%^WHITE%^two silver"+
" swords %^RESET%^%^RED%^and is obviously comfortable with thier use. %^RESET%^"+
"%^ORANGE%^Long sable hair %^RESET%^%^RED%^flows down to his feet, tied in "+
"several places with %^RESET%^%^ORANGE%^leather ties%^RESET%^%^RED%^. A %^RESET%^"+
"%^BOLD%^%^WHITE%^glowing symbol %^RESET%^%^RED%^hangs around his neck%^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(20);
    set_hd(20,2);
    set_max_hp(random(50)+400);
    set_hp(query_max_hp());
    set_overall_ac(0);
	set_speed(0);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
      
    set_class("ranger");
    add_search_path("/cmds/ranger");
    set_mlevel("ranger",20);
    set_guild_level("ranger",20);

    set_exp(15000);
    set_max_level(25);

    set_body_type("human");
		
		
    ob = new(OBJ"lesser_silver_sword");
       ob->move(TO);
       ob->set_property("monsterweapon",1);
       command("wield sword");
    
    ob = new(OBJ"lesser_silver_sword");
       ob->move(TO);
       command("wield sword");
    
    ob = new("/d/common/obj/armour/bracers");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear bracers");

    ob = new("/d/common/obj/armour/studded");
       ob->move(TO);
       ob->set_property("enchantment",1);
       ob->set_property("monsterweapon",1);
       command("wear studded");

    ob = new(OBJ"gith_symbol.c");
    ob->move(TO);

    set_property("add kits",random(15)+15);

    set("aggressive","agg_func");
    set_emotes(10,({"%^BLACK%^%^BOLD%^Pakek'Tin looks over the stables"+
" and nods%^RESET%^","%^BLACK%^%^BOLD%^Pakek'Tin rests his swords on his"+
" shoulders%^RESET%^"}),0);
    set_achats(10,({"%^BLACK%^%^BOLD%^Pakek'Tin brings both swords to b"+
"ear%^RESET%^","%^BLACK%^%^BOLD%^Pakek'Tin lunges at you%^RESET%^"}));
}

void agg_func() {
    if (TP->query_invis()) {return;}
        new("/cmds/spells/s/_sticks_into_snakes.c")->use_spell(TO,TO,17,100,"cleric");
    force_me("emoteat "+TPQN+ " %^BLACK%^%^BOLD%^With an evil glint in $M's"+
" eyes, $M rushes $N.%^RESET%^");
    force_me("kill "+TP->query_name());
    force_me("whirl");
return;
}

void heart_beat(){
        ::heart_beat();
  
        if(!objectp(TO) || !objectp(ETO)) return;
        if(query_hp()< 140 && present("vial",TO)){
            force_me("quaff vial");
            force_me("quaff vial");
            force_me("quaff vial");

        }
}
