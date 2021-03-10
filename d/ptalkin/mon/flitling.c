 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
set_name("%^GREEN%^flitterling");
set_id(({"flitterling"}));
set("race", "elf");
set_gender("female");
set_short("%^GREEN%^a flitterling");
set_long("%^CYAN%^
Flitterlings are small silver coloured humanoids about 1/4 inch long
and look like small pixies armed with silver swords.  Flitterlings
live in old hollow tree trunks or in a specially hollowed out mushroom.
Their homes are always surrounded by rings of magical mushrooms of
various colours, which the flitterlings tend.  The flitterlings will
fight to the death to defend their mushroom rings.
%^RESET%^");
set_level(10);
	set_body_type("human");
	set_class("fighter");
	set("aggressive", 0);
	set_alignment(8);
set_property("swarm", 1);
set_size(1);
set_overall_ac(6);
	set_property("wimpy", 25);
set_stats("intelligence", 10);
set_stats("wisdom", 10);
set_stats("srength", 10);
	set_stats("charisma", 10);
set_stats("dexterity", 15);
set_stats("constitution", 10);
set_hd(10,2);
	set_hp(75);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
new("/realms/svaha/weapons/flsword")->move(this_object());
command("wield sword in right hand");
new("/realms/svaha/weapons/flsword")->move(this_object());
command("wield sword in left hand");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
