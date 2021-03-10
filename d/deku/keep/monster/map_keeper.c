#include <std.h>
#include <daemons.h>
#include "../keep.h"
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

void create() 
{
    object ob;
    ::create();
    set_name("The map keeper");
    set_id(({"figure","shadow", "shadowy figure", "salvirius", "keeper", "map keeper"}));
    set_race("lich");
    set_gender("male");
    set_short("%^BOLD%^%^BLACK%^Salvirius Enagmus Malt%^BOLD%^%^WHITE%^oo%^RESET%^"+
    "%^BOLD%^%^BLACK%^re, The Map Keeper%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The man before you is obviously centuries old.  "+
    "His body is twisted and decayed, his face almost skeletal, with only "+
    "a few pieces of rotted flesh hanging from it.  His eyes are a "+
    "terrifying dark red that seem to stare into your very soul.  "+
    "You are unable to witness the majority of his flesh, for the very "+
    "shadows cloak most of him, though you assume that the rest of him is just "+
    "like his face.  His body is much longer than it is wide and he "+
    "stands almost seven feet tall.  An aura of darkness surrounds him, "+
    "pulsing outward in constant rythme from his chest.  He carries, "+
    "a black scythe with dreadful ease.%^RESET%^");
    set_body_type("humanoid");
    set_alignment(9);
    set_property("full attacks", 1);
    set_class("mage");
    set_mlevel("mage", 30);
    set_guild_level("mage", 30);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_guild_level("fighter", 30);
    set_size(3);
    set_stats("dexterity", 18);
    set_stats("strength", 20);
    set_stats("intelligence", 30);
    set_property("swarm", 1);
    set_property("spell penetration", 50);
    set_mob_magic_resistance("average");
    set_hp(1550 + random(51));
    set_max_hp(query_hp());
    set_new_exp(20, "boss");
    set_max_level(25);
    set_overall_ac(-12);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    command("speech utter without emotion");
    command("speak wizish");
    set_lang("wizish", 100);
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/mage");
    set_monster_feats(({
      "parry",
      "powerattack",
      "shatter",
	  "sunder",
	  "rush"
    }));
    set_funcs(({"rushit","flashit","flashit","aide_me"}));
    set_func_chance(30);   	
    set_spells(({"fireball","scorcher","acid arrow",
    "meteor swarm", "powerword stun"}));
    set_spell_chance(45);
    set_property("undead", 1);
    set_property("no kill", 1);
    ob = new("/d/deku/hhouse/ob/blackthornscythe.c");
    ob->remove_property("enchantment");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    command("wield scythe");
    new(KEEPO+"map")->move(TO);
    //new(KEEPO+"shadow_orb")->move(TO);
    //command("wield orb");
}

void heart_beat() 
{
    object *liv;
    int x, max;
    //he eats fodder 6 for breakfast every heartbeat :P - Saide
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    liv = all_living(ETO);
    liv -= ({TO});
    max = 0;
    for(x = 0;x < sizeof(liv);x++)
    {
        if(max >= 6) return;
        if(!objectp(liv[x])) continue;
        if(liv[x] == TO) continue;
        if(liv[x]->id("deku_skel_assassin")) continue;
        if(userp(liv[x])) continue;
        if(liv[x]->id("blackthornshadowguard")) continue;
        if(liv[x]->id("retainer")) continue; //dont want to insta-kill paladin followers
        tell_object(liv[x], "%^BOLD%^%^BLACK%^A massive black tendril "+
        "jumps from the map keeper and embraces you, absorbing your very soul!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^BLACK%^A massive black tendril "+
        "jumps from the map keeper and embraces "+liv[x]->QCN+ "%^BOLD%^%^BLACK%^ "+
        "absorbing "+liv[x]->QP+"%^BOLD%^%^BLACK%^ very soul!%^RESET%^", liv[x]);
        liv[x]->die();
        TO->add_hp(5);
        max++;
        continue;
    }
	
    return;
}

void init() 
{
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(TO)) return;
    if(TP->query_true_invis()) return;
    if(TP->id("blackthornshadowguard")) return;
    if(!userp(TP) && !TP->id("retainer")) return;
    command("say I have waited for so long to defend the map... "+
    "I have not had an intruder in centuries.  I will enjoy adding you "+
    "to my collection.");
    command("rush "+TPQN);
    if(!TO->query_parrying()) 
    {
        command("parry");
    }
}

void tendril_attack(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    tell_room(ETO, "%^BOLD%^%^BLACK%^A massive black tendril jumps from the "+
    "map keeper and embraces "+targ->QCN+"!%^RESET%^", ({targ, TO}));
    tell_object(targ, "%^BOLD%^%^BLACK%^Before you can comprehend what is "+
    "happening a massive black tendril jumps from the map keeper, "+
    "embracing you, and absorbing some of your life force!%^RESET%^");
    targ->do_damage("torso", roll_dice(2,8));
    if(targ->will_save(30)) 
    {
        tell_object(targ, "%^BOLD%^%^BLACK%^The tendril latches onto your "+
        "torso, holding you in its cold embrace!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^BLACK%^The tendril latches onto "+
        targ->QCN+"%^BOLD%^%^BLACK%^'s torso, holding "+targ->QO+ 
        " in its cold embrace!%^RESET%^", ({targ, TO}));
        targ->set_paralyzed(40, "%^BOLD%^%^BLACK%^You are held "+
        "in the embrace of the cold black tendril!%^RESET%^");
        return;
    }
    tell_object(targ, "%^BOLD%^%^BLACK%^With quick thinking you manage "+
    "to knock the tendril away before it can latch on!%^RESET%^");
    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ manages to knock the tendril "+
    "away before it can latch on!%^RESET%^", ({targ, TO}));
    return;
}

void aide_me(object targ) 
{
    object guard;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!present("deku_skel_assassin", ETO)) 
    {
        tell_room(ETO, "%^BOLD%^%^GREEN%^The map keeper points casually at "+
        "one of the skeletons on the floor and mumbles something in an "+
        "ancient language.%^RESET%^", TO);
        guard = new(KEEPM+"skeletal_assassin");
        guard->remove_property("no kill");
        guard->set_moving(0);
        guard->set_speed(0);
        guard->remove_property("no paralyze");
        guard->remove_property("no hold");		
        guard->move(ETO);
        return;
    }
    else
    {
        tendril_attack(targ);
        return;
    }
}


