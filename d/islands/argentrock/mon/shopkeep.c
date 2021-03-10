//General store vendor for elven refuge -- Yves
#include <std.h>
#include "../argabbr.h"
inherit VENDOR;

void create() {
    ::create();
    set_id(({
        "shopkeep",
        "shopkeeper",
        "denule",
        "ihhariel",
        "denule ihhariel",
        "provisioner"
    }));
    set_name("Denule");
    set_short("Denule Ihhariel, Provisioner of Supplies");
    set_long((:TO,"long_desc":));
    set_hd(35,10);
    set("aggressive", 0);
    set_level(35);
    set_gender("male");
    set_class("ranger");
    set_mlevel("ranger", 35);
    set_guild_level("ranger",35);
    set_alignment(4);
    set_race("elf");
    add_money("gold", random(25));
    set_body_type("human");
    set_mob_magic_resistance("low");
    set_overall_ac(-20);
    set_stats("strength",19);
    set_stats("intelligence",12);
    set_stats("wisdom",18);
    set_stats("dexterity",19);
    set_stats("constitution",17);
    set_stats("charisma",13);
    set_max_hp(350+random(50));
    set_hp(query_max_hp());
    set_exp(100);
    set_spell_chance(35);
    set_spells(({
        "cause blindness",
        "dispel magic",
        "hold person",
        "dispel magic",
        "dispel magic",
        "dispel magic",
        "thorn spray",
    }));
    set_property("swarm",0);
    set_storage_room(PATH+"gstorage.c");
    force_me("speech speak with melodic tones");
}

string long_desc(){
    return
        "%^RESET%^Denule has %^ORANGE%^c%^BOLD%^o%^RESET%^%^ORANGE%^p%^BOLD%^%^RED%^p%^ORANGE%^e%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^y%^RESET%^ %^BOLD%^%^RED%^red hair%^RESET%^ pulled back into a ponytail and his "
        "%^GREEN%^deep green eyes%^RESET%^ seem %^BOLD%^%^BLACK%^saddened%^RESET%^ by the plight of his people. "
        "Although his sharp features are %^BOLD%^fair%^RESET%^ and he is in excellent "
        "shape, you can't help but notice a general %^BOLD%^%^BLACK%^fatigue%^RESET%^ about him. "
        "He is wearing a %^ORANGE%^brown tunic%^RESET%^ with %^GREEN%^forest green leggings%^RESET%^ and a "
        "soft gray cloak. Denule is the provisioner of common "
        "supplies here and while he will not give away his wares for "
        "free, he is open to %^RED%^selling%^RESET%^ or %^CYAN%^buying%^RESET%^ most merchandise.";
}
