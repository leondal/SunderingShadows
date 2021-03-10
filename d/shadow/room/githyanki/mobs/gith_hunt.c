// Githyanki Hunter  - LoKi - 01-02-2008 ((gith_hunt.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("githyanki");
    set_id(({"githyanki","monster","hunter","githyanki hunter"}));
    set_race("githyanki");
    set_gender("male");
    set_short("%^BLACK%^%^BOLD%^githyanki hunter%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^This humanoid is tall, gaunt,"+
        " and almost elven in its lithe movements. It has "+
        "%^RESET%^%^ORANGE%^rough y%^RESET%^%^YELLOW%^e%^RESET%^%^ORANGE%^llow"+
        " %^RESET%^%^YELLOW%^s%^RESET%^%^ORANGE%^kin %^RESET%^%^MAGENTA%^and "+
        "its entire form is covered in a %^RESET%^%^BOLD%^%^BLACK%^flow%^RESET%^"+
        "%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^ng black %^RESET%^%^WHITE%^r%^RESET%^"+
        "%^BOLD%^%^BLACK%^obe %^RESET%^%^MAGENTA%^that seems to suck in the light. "+
        "He wields a %^RESET%^%^BOLD%^%^WHITE%^silver sword %^RESET%^%^MAGENTA%^in "+
        "one hand and a dagger "+
        "%^MAGENTA%^in the other. His movements are fluid and fast%^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(17);
    set_hd(17,2);
    add_money("gold",random(500));
    add_money("silver",random(200));
    add_money("electrum",random(300));
    set_max_hp(random(50)+150);
    set_hp(query_max_hp());
    set_overall_ac(-1);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
      
    set_class("thief");
    
    set_class("psion");
    set_mlevel("thief",20);
    set_mlevel("psion",17);
    set_guild_level("psion",17);
    add_search_path("/cmds/thief");
    set_thief_skill("move silently", 80);
    set_thief_skill("hide in shadows", 80);
    set_scrambling(1);

    set_exp(8000);
    set_max_level(25);

    set_spell_chance(10);
    set_spells(({"energy bolt"}));

    set_body_type("human");
		
		
    ob = new(OBJ"lesser_silver_sword");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield sword");
    
    ob = new (OBJ"silver_dagger");
    ob->move(TO);
    if(random(5)){
	
        ob->set_property("monsterweapon",1);
    }
    command("wield dagger");
    
    ob = new("/d/common/obj/armour/robe");
    ob->move(TO);
    ob->set_short("%^BLACK%^%^BOLD%^flowing black robe%^RESET%^");
    ob->set_property("enchantment",2);
    ob->set_property("monsterweapon",1);
    command("wear robe");
		
    set("aggressive","agg_func");
    set_emotes(3,({"%^BLACK%^%^BOLD%^The hunter prowls%^RESET%^"}),0);
    set_achats(10,({"%^BLACK%^%^BOLD%^The hunter fights silently%^RESET%^"}));
}

void agg_func() {
    if (TP->query_invis()) {return;}
    if(!TO->query_property("prescience")){
        new("/cmds/spells/p/_prescience.c")->use_spell(TO,TO,17,100,"psion");
    }
    force_me("emoteat "+TPQN+ " %^BLACK%^%^BOLD%^The $M silently leaps at $N.%^RESET%^");
    force_me("stab "+TP->query_name());
    
return;
}
