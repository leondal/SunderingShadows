#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("imp");
    set_id(({"imp"}));
    set_short("%^RED%^leathery imp");
    set_long("%^RED%^A small imp with leathery skin and %^BOLD%^%^BLACK%^dark wings %^RESET%^%^RED%^with clawlike fingers at the ends.  It has %^BOLD%^beady red eyes %^RESET%^%^RED%^, small pointed leathery ears, and a perpetual smirk on its face."
    );
    set_race("imp");
    set_gender("male");
    set_hd(25,16);
    set_size(1);
    set_overall_ac(-4);
    set_class("fighter");
    set_hp(150);
    set_max_hp(query_hp());
    set_body_type("human");
    set_property("full attacks",1);
    set_stats("strength",10);
    set_stats("dexterity",25);
    set_stats("constitution",17);
    set_mob_magic_resistance("average");
    set_exp(500);
    set_alignment(9);
}

void die(object ob) {
    tell_room(ETO, "%^RED%^The imp vanishes in a flash of light and smoke.");
    TO->move("/d/player_stores/poffices/pobackroom");
    :: die(ob);
}