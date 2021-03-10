 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
set_name("");
set_id(({""}));
set("race","");
        set_gender("male");
set_short("");
set_long("");
	set_level(15);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",13);
        set_stats("charisma",3);
        set_stats("dexterity",8);
        set_stats("constitution",7);
        set_max_mp(0);
        set_mp(query_max_mp());
	set_hd(15,1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(WEAPONDIR+"halberd")->move(this_object());
        command("wield halberd in right hand and left hand");
        new(ARMORDIR+"chain.c")->move(this_object());
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
