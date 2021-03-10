//Minor difficulty update - Octothorpe 12/18/09
#include <std.h>
#include "../marsh.h"

inherit MONSTER;

int level;

void create()
{
    ::create();
    set_name("istvan");
    set_id(({"uncle","istvan","uncle istvan"}));
    set_short("%^RESET%^%^GREEN%^Uncle Istvan, Guardian of the Marsh%^RESET%^");
    set_long("%^BLUE%^The being that stands before you is a humanoid creature that "
	    "appears to be half human, half giant. He stands ready and willing to "
	    "drive off anyone who dares enter into the realm of his marshlands. "
	    "He is bundled up in raggedy old farmer clothes and is missing half his teeth. "
	    "His eyes are filled with black hate.");
    set("race", "giant" );
    set_property("magic", 1);
    set_property("add kits",15);
    set_class("fighter");

    level = roll_dice(1,6) + 30;

    set_hd(level,12);
    set_property ("magic resistance",level);
    set_level(level);
    set_body_type("human");
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(15-level);
    set_alignment(6);
    set_property("not random monster", 1); //added by saide in order to prevent these from spawning in alternative worlds
    set_guild_level("fighter",level);
    set_mlevel("fighter",level);
    add_search_path("/cmds/fighter");
    set_max_hp(level * 25);
    set_hp(query_max_hp());
    set_new_exp(level+6,"boss");
    set_max_level(36);
    set_property("full attacks",1);
    new("/d/dagger/marsh/tower/obj/axe.c")->move(TO);
    command("wield axe in left hand");
    set_funcs(({
	   "special",
	   "kdit",
	   "rushit",
	   "shatterit",
	   "sunderit"
	}));
    set_func_chance(50);
    set_monster_feats(({
	   "toughness",
	   "improved toughness",
	   "damage resistance",
	   "improved damage resistance",
	   "regeneration",
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush",
	   "knockdown"
	}));
    set("aggressive","attack_fun");
    set_emotes(1,({"%^MAGENTA%^Uncle Istvan says:%^RESET%^ Die you damn maggot!",}),1);
    set_speed(50);
    set_moving(1);
    set_stats("strength",25);
    set_stats("dexterity",25);
    set_stats("constitution",25);
    set_stats("intelligence",25);
    set_stats("wisdom",25);
    set_stats("charisma",25);
    set_property("no tripped",1);
    set_property("no paralyze",1);
    add_attack_bonus(roll_dice(1,6));
    add_damage_bonus(roll_dice(1,6));
}

void init()
{
    ::init();
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(TP)) { return; }
    if(TP->query_true_invis()) { return; }
    if(TP->query_invis()) { return; }

    call_out("do_kill",10,TP);
}

void special(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }

    command("say We 'ate your kine 'round here!");
	command("say Take dis ya shun of a biyatch!!!");
    TO->force_me("rush "+targ->query_name());
    TO->force_me("knockdown "+targ->query_name());
}

void do_kill(object ob)
{
    if(!objectp(TO)) { return; }
    if(!objectp(ob)) { return; }
    //new("/cmds/wizard/_dispel_magic.c")->use_spell(TO,"",level,100);
	new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,"",level,100,"mage");
    call_out("do_kill",20,0);
}

int attack_fun()
{
    if(!objectp(TO)) { return 0; }
    if(!objectp(TP)) { return 0; }

    TO->force_me("say What the livin hell are you doing in my swamp fool?!?");
    TO->force_me("say Take this you friggin rodent spawn she-runt!!!");
    TO->force_me("rush "+TP->query_name());
    return 1;
}

void kdit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("knockdown "+targ->query_name());
    return;
}

void rushit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("rush "+targ->query_name());
    return;
}

void sunderit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("sunder "+targ->query_name());
    return;
}

void shatterit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("shatter "+targ->query_name());
    return;
}
