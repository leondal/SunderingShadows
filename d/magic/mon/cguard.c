#include "summoned_monster.h"

#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " caravan guard");
        set("long", "This is a mangy looking mercenary hired by cheap traders to guard caravans.\n");
        set_level(4);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 8);
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
        set_hd(4, 1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(CWEAP"longsword")->move(TO);
        command("wield longsword");
        new(CARMOR"leather")->move(TO);
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
