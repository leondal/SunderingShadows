#include <std.h>
#include "../tomb.h"

inherit "/std/spell_vend.c";

create()
{
    ::create();
    set_name("shiza");
    set_id( ({ "shiza" ,"clerk", "shop keeper", "shopkeeper"}) );
    set_short("%^BOLD%^%^BLACK%^Shiza, %^ORANGE%^el%^RESET%^%^ORANGE%^d%^BOLD%^%^ORANGE%^est %^ORANGE%^sc%^RESET%^%^ORANGE%^r%^BOLD%^%^ORANGE%^i%^RESET%^%^ORANGE%^b%^BOLD%^%^ORANGE%^e%^RESET%^");
    set("aggressive", 0);
    set_level(20);
    set_property("undead",1);
    set_long("%^RED%^This mesmerizing beauty smiles sharply, exposing her long fangs. She stands behind counter dressed into a simple yet elegant gown. Her hand neatly holds a cup with red liquid she sips in between moments.
%^BOLD%^<help shop>%^RESET%^ will get you a list of shop commands.");
    set_gender("female");
    set_alignment(6);
    set_race("elf");
    set_hd(60,6);
    set_class("mage");
    set_mlevel("mage",65);
    set_guild_level("mage",65);
    set_overall_ac(-75);
    set_stats("intelligence",28);
    set_stats("wisdom",26);
    set_stats("strength",26);
    set_stats("charisma",12);
    set_stats("dexterity",16);
    set_stats("constitution",22);
    set_new_exp(60,"boss");
    set_property("magic resistance",70);
    set_property("spell damage resistance",10);
    set_max_hp(1500);
    set_hp(query_max_hp());
    set_spells(({"mind fog",
                    "globe of invulnerability",
                    "greater ruin",
                    "boneshaker",
                    "boneshatter"}));
    set_spell_chance(100);

    set_spells_sold(gen_spells_sold(35));
}
