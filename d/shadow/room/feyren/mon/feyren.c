#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    int chance;
    object ob;
    ::create();
	
    set_name("feyren");
    set_id(({ "feyren", "feyren the insane", "half-orc", "halforc"}));
    set_short("%^BOLD%^%^RED%^Feyren, a m%^BOLD%^%^BLUE%^"+
    "a%^BOLD%^%^RED%^ss%^BOLD%^%^BLUE%^i%^BOLD%^%^RED%^"+
    "v%^BOLD%^%^BLUE%^e %^BOLD%^%^RED%^half-orc with one eye%^RESET%^");
    set("aggressive",25);

    set_long("%^BOLD%^%^RED%^This massive creature is near "+
    "seven feet tall and his body is swollen with muscle. "+
    "His head is massive and his mouth is locked into an "+
    "eternal grimace. One of his eyes is missing and there is "+
    "a grotesque empty socket stuffed with a piece of wood in its "+
    "place. His remaining eye is an empty cold blue. His shoulders "+
    "are exceptionally broad and toned. His arms are longer than "+
    "normal for his kind and they end in massive hands that look "+
    "as if they have seen a tremendous amount of toil. They are calloused "+
    "and wounded, offering open sores that are infected or very "+
    "close it. His legs are monstrous, the left one bent oddly, "+
    "perhaps from some accident long ago. His feet are large and jut "+
    "out unevenly with the toes of the right one swollen and "+
    "black.%^RESET%^");

    set_hd(16,3);
    set_class("fighter");
    set_mlevel("fighter",16);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_alignment(9);
    set_stats("intelligence",12);
    set_stats("wisdom",8);
    set_stats("strength",19);
    set_stats("charisma",3);
    set_stats("dexterity",14);
    set_stats("constitution",19);
    set_race("half-orc");
    set_gender("male");
    set_overall_ac(-4);
    set_new_exp(14,"very high");
    set_max_hp(185 + random(75));
    set_hp(query_max_hp());
    
    //add_money("gold",random(200)+10);
    set_property("full attacks",1);
    add_search_path("/cmds/fighter");

    set_monster_feats(({
        "parry", "flash", "medium armor proficiency",
    }));
    set_funcs(({"rage"}));
    set_func_chance(25); 
    command("speak common");
    command("speech growl insanely");
    TO->set_languages("common", 100);
    chance = 2;
    if(!random(chance))
    {
        new(FFOB+"dark_helm")->move(TO);
        chance += 2;
    }
    if(!random(chance)) 
    {
        new(FFOB+"breastplate")->move(TO);
        chance += 2;
    }
    if(!random(chance)) 
    {
        new(FFOB+"bitter_harvest")->move(TO);
        chance += 2;
    }
    if(!present("helm", TO)) 
    {
        ob = new("/d/common/obj/armour/helm");
        ob->set_property("enchantment", random(3));
        ob->move(TO);
    }
    if(!present("breastplate", TO)) 
    {
        ob = new("/d/common/obj/armour/breastplate");
        ob->set_property("enchantment", random(3));
        ob->move(TO);
    }
    if(!present("scythe", TO))
    {
        ob = new("/d/common/obj/weapon/scythe");
        ob->set_property("enchantment", random(3));
        ob->move(TO);
    }
    command("wear helm");
    command("wear breastplate");
    command("wield scythe");
}

void rage(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    TO->force_me("say I was once a proud man with my own land but THEY "+
    "took it from me and destroyed all that I held dear!  NOW YOU WILL "+
    "PAY!");
    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ flies into an insane "+
    "rage, launching a quick series of attacks!%^RESET%^");
    TO->execute_attack();
    TO->execute_attack();
    TO->execute_attack();
}
