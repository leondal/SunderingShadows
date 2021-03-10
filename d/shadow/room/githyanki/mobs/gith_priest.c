// Githyanki Priest  - LoKi - 01-02-2008 ((gith_hunt.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("githyanki");
    set_id(({"githyanki","monster","priestess","githyanki priestess"}));
    set_race("githyanki");
    set_gender("female");
    set_short("%^RESET%^%^CYAN%^githyanki priestess%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This humanoid is tall, %^RESET%^%^"+
"ORANGE%^gaunt%^RESET%^%^CYAN%^, and almost elven in its lithe mov"+
"ements. It has %^RESET%^%^YELLOW%^rou%^RESET%^%^ORANGE%^g%^RESET%^"+
"%^YELLOW%^h yell%^RESET%^%^ORANGE%^o%^RESET%^%^YELLOW%^w skin %^RESET%^"+
"%^CYAN%^and %^RESET%^%^RED%^russ%^RESET%^%^BOLD%^%^RED%^e%^RESET%^"+
"%^RED%^t %^RESET%^%^CYAN%^hair that flows freely down its back. It's"+ 
"ears are long and mostly pointed, and its eyes seem to hold a glimmer"+
" of something %^RESET%^%^BOLD%^%^BLACK%^malign%^RESET%^%^CYAN%^. It "+
"wears %^RESET%^%^BOLD%^%^BLACK%^half-plate %^RESET%^%^CYAN%^and wields"+
" a set of %^RESET%^%^RED%^wicked claws%^RESET%^%^CYAN%^. A %^RESET%^"+
"%^BOLD%^%^WHITE%^glowing symbol %^RESET%^%^CYAN%^hangs from it's "+
"neck.%^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(20);
    set_hd(20,2);
    set_max_hp(random(50)+150);
    set_hp(query_max_hp());
    set_overall_ac(-1);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",18);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
    
    set_class("cleric");
    set_mlevel("cleric",20);
    set_guild_level("cleric",20);

    set_exp(9000);
    set_max_level(25);

    set_spell_chance(30);
    set_spells(({"confusion", 
"limb attack", 
"cause serious wounds", 
"flame strike"}));

    set_body_type("human");
		
		
    ob = new("/d/common/obj/armour/plate.c");
    ob->move(TO);
    ob->set_short("%^BLACK%^%^BOLD%^obsidion half-plate%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear plate");
    
    ob = new ("/d/common/obj/weapon/claw.c");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment",2);
    command("wield claw");
    
    ob = new(OBJ"gith_symbol.c");
    ob->move(TO);
    
    set("aggressive","agg_func");
    set_emotes(3,({"%^BLACK%^%^BOLD%^The priest wanders, seemingly"+
" lost in meditation%^RESET%^"}),0);
    set_achats(10,({"%^RED%^%^BOLD%^The priest steps back and "+
"chants%^RESET%^"}));
}

void agg_func() {
    if (TP->query_invis()) {return;}
    if(!TO->query_property("blight")){
        new("/cmds/spells/b/_blight.c")->use_spell(TO,TO,17,100,"cleric");
    }
    force_me("emoteat "+TPQN+ " %^BLACK%^%^BOLD%^The $M starts "+
"chanting and screams at $N!%^RESET%^");
    force_me("kill "+TP->query_name());
    
return;
}
