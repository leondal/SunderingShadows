//Healer for elven refuge -- Yves
#include <std.h>
#include "../argabbr.h"
inherit NPC;

void create() {
    ::create();
    set_id(({
        "healer",
        "hasas",
        "lucliden",
        "hasas lucliden",
        "herbalist"
    }));
    set_name("Hasas");
    set_short("Hasas Lucliden, Healer and Herbalist");
    set_long((:TO,"long_desc":));
    set_hd(35,10);
    set("aggressive", 0);
    set_level(35);
    set_gender("male");
    set_class("cleric");
    set_mlevel("cleric", 35);
    set_guild_level("cleric",35);
    set_alignment(1);
    set_race("elf");
    add_money("gold", random(25));
    set_body_type("human");
    set_mob_magic_resistance("average");
    set_overall_ac(-20);
    set_stats("strength",12);
    set_stats("intelligence",14);
    set_stats("wisdom",19);
    set_stats("dexterity",15);
    set_stats("constitution",16);
    set_stats("charisma",15);
    set_max_hp(350+random(50));
    set_hp(query_max_hp());
    set_exp(100);
    set_spell_chance(80);
    set_spells(({
        "cause blindness",
        "dispel magic",
        "hold person",
        "dispel magic",
        "dispel magic",
        "dispel magic",
        "thorn spray",
        "animate object"
        "sticks into snakes"
        "limb attack"
        "cause critical wounds"
    }));
    set_property("swarm",0);
    force_me("speech speak calmly and slowly");
}

string long_desc(){
    return
        "Hasas carries himself like that of a person who is %^RED%^stubborn%^CYAN%^ and "
        "%^BLUE%^unchanging%^CYAN%^. His movements are %^GREEN%^slow%^CYAN%^ and %^ORANGE%^purposeful%^CYAN%^, without "
        "a hint of any hesitation. He has long %^YELLOW%^pale yellow hair%^RESET%^%^CYAN%^ which is "
        "styled naturally, and large %^ORANGE%^ha%^GREEN%^z%^ORANGE%^el%^CYAN%^ eyes filled with an eternity "
        "of %^BOLD%^%^WHITE%^wisdom%^RESET%^%^CYAN%^. His %^RED%^gaunt%^CYAN%^ features show noticeable signs of aging "
        "which are not normally seen in %^MAGENTA%^elves%^CYAN%^, and his frame is covered "
        "in a simple %^RESET%^gray robe%^CYAN%^. He will sell his services to %^RED%^outsiders%^CYAN%^, "
        "though it won't be cheap.%^RESET%^";
}
