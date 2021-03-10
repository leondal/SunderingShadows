#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("seer");
    set_id(({"seer", "seer of the damned"}));
    set_short("%^RED%^Seer of the Damned%^RESET%^");
    set_long("Before you stands perhaps the most hideous dwarf you have ever laid "
        "eyes upon. Not merely in the physical sense, but in the spiritual sense as "
        "well.  For as the tail goes the Seer used to be a noble Dwarven Lord, who "
        "was corrupted into betraying his king during a major battle. Kartakass was "
        "impressed with the ruthlessness of this dwarf warrior, and so he offered to "
        "let the Seer join his ranks. As a sick offering to his new master the Seer "
        "ripped out is own eyes and placed them upon his holy symbol which he wore as "
        "a necklace");
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_hd(30,8);
    set_damage_bonus(7);
    set_size(2);
    set_overall_ac(-5);
    set_class("fighter");
    set_mlevel("fighter",30);
    set_hp(900);
    set_property("swarm",1);
    set_property("full attacks",1);
    set_stats("strength",19);
    set_stats("dexterity",16);
    set_stats("constitution",19);
    set("aggressive",25);
    set_mob_magic_resistance("average");
    set_exp(30000);
    set_new_exp(25,"boss");
    set_alignment(9);
    set_emotes(3,({"%^BOLD%^The Seer gazes at you and seems to see through your very soul.",
        "%^BOLD%^%^BLUE%^The Seer looks at a pair of eye balls on a necklace.",
        "%^MAGENTA%^The Seer taunts you into battle.",}),0);
    new(OBJS"dwarf_lords_plate.c")->move(TO);
    command("wear plate");
    new(OBJS"chaos_blade.c")->move(TO);
    command("wield sword");
    new(OBJS"necklace_of_eyes.c")->move(TO);
    command("wear necklace");
}

void init()
{
    if(TP->query_true_invis()) { return; }
    
    if(TP->query_invis())
    {
        tell_room(ETO,"%^BOLD%^The Seer's eyeless sockets glow with a mystic light and he "
            "appears to see you clearly.");
        TP->set_vis();
        kill_ob(TP,1);
    }

    force_me("say %^MAGENTA%^You scum! You may have defeated the Master but "
        "you will not leave here alive!");
	TP->kill_ob(TO,0);
}

void die(object ob) 
{
    tell_room(ETO,"%^RED%^The Seer falls upon his sword in a vain attempt to regain some "
        "of the honor he's lost over the years.",TO);
    ::die(TO);
    return;
}

