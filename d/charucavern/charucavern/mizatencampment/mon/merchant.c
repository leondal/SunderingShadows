#include <std.h>
#include "../inherits/area_stuff.h"

inherit VENDOR;

void create() 
{  
    object ob;
    ::create();  
    
    set_race("gnome");    
    
    set_id( ({ "gnome", "fizzlebit", "fizzlebit blinkenstein", "fizzle", "merchant", "The Healer"}) );
    set_body_type("gnome");
    set_class("sorcerer");
    set_alignment(5);
    set_hd(30,12);
    set_hp(750);
    set_max_hp(query_hp());    
    
    set_stats("strength", 15 + random(3));
    set_stats("constitution", 18 + random(4));
    set_stats("dexterity", 11 + random(3));
    set_stats("wisdom", 25 + random(3));
    set_stats("intelligence", 26 + random(3));
    set_stats("charisma", 17 + random(3));
    set_overall_ac(-10);
    set_mob_magic_resistance("average");
    set_property("damage resistance", 10);
    set_gender("male");
    set_name("fizzlebit");
    
    set_short("%^BOLD%^%^WHITE%^F%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^zzl%^BOLD%^%^CYAN%^e"+
    "%^BOLD%^%^WHITE%^b%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^t Bl%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^"+
    "nk%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^nst%^BOLD%^%^CYAN%^ei%^BOLD%^%^WHITE%^n, "+
    "M%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^rchant H%^BOLD%^%^CYAN%^ea%^BOLD%^%^WHITE%^"+
    "l%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r Extraordinaire%^RESET%^");
    
    /*of The M%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^"+
    "z%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^t %^BOLD%^%^BLACK%^E%^BOLD%^%^WHITE%^nc%^BOLD%^%^BLACK%^"+
    "a%^BOLD%^%^WHITE%^mpm%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^nt%^RESET%^");*/
       
    set_long("%^BOLD%^%^WHITE%^This small gnome has almost perfectly tan skin. It is completely "+
    "smooth and you are unsure if he is very young or simply takes amazing care of himself. He "+
    "has %^RESET%^%^ORANGE%^light brown%^BOLD%^%^WHITE%^ hair and very %^BOLD%^%^BLUE%^deep "+
    "azure%^BOLD%^%^WHITE%^ eyes which sparkle with an insatiable curiosity. He stands approximately "+
    "three feet tall and is possessed of seemingly boundless energy. He moves about his shop constantly "+
    "cleaning and polishing, as if he is not quite satisifed with his work so far. When he notices you "+
    "he stops only for a brief instant, flashing a warm and inviting smile, that portrays a deep "+
    "kindness and acceptance.%^RESET%^");   
    
    ob = new("/d/common/obj/armour/srobe.c");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    ob->set_item_bonus("caster level", 1);
    
    if(random(4)) ob->set_property("monsterweapon", 1);
    
    command("wear robe");
    
    
    set_new_exp(30, "normal");        
    set_monster_feats(({"perfect caster", "toughness", "improved toughness", "resistance", "deathward", "spellpower",
    "magic arsenal","improved spell power"}));
    
    set_spells(({"meteor swarm", "prismatic spray",
    "cone of cold"}));
    set_spell_chance(90);
    ob = new("/d/charucavern/diseases/deep_flu");
    ob->move(TO);
    ob->set_incubation_period(0);
    ob->set_infected(TO);
    set_items_allowed("all");
    set_storage_room(MINH+"merchant_storage");
} 



