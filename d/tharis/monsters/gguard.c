#include "/d/common/common.h";
#include "std.h"

inherit MONSTER;
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " gate guard");
        set("long", "This guard is standing by the gates. He carries an overall uninterested look on his face.");
        set_hd(15,2);
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
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_overall_ac(7);
        new(CWEAP"halberd")->move(TO);
        command("wield halberd in right hand and left hand");
        new(CARMOR"chain")->move(TO);
        command("wear armor");
        set_exp(800);
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
