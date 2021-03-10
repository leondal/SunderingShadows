#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("pirate");
    set_id(({"yarik","pirate","human pirate"}));
    set_short("Emistil Darkeyes");
    set_long("
Yarik is a lazy and cowardly villain with little regard for the welfare of
others.  His only ambition is to become rich and live like the fat, gold-
touting merchants he sees on city streets.  Yarik has a morbid sense of 
humor and little sense of personal hygiene. His thin build and oily black
hair give him a distinctive, ratlike appearance.");
    set_race("human");
    set_gender("male");
    set_hd(12,4);
    set_size(2);
    set_overall_ac(1);
    set_class("thief");
    set_guild_level("thief",10);
    set_max_hp(120);
    set_hp(120);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no bump",1);
    set_stats("strength",16);
    set_stats("dexterity",18);
    set_stats("constitution",9);
    set_stats("intelligence", 15);
    set_mob_magic_resistance("average");
    set_exp(1300);
    set_alignment(9);
    set("aggressive","aggfunc");
    new("/d/dragon/obj/weapon/shsword")->move_object(this_object());
    command("wield shortsword in right hand");
    new("/d/dragon/obj/armor/leather")->move_object(this_object());
    command("wear leather");
    add_money("gold", 250);
}

void aggfunc() {
  force_me("say So you are trying to steal my little treasure.");
  this_player()->kill_ob(this_object(), 0);
}

