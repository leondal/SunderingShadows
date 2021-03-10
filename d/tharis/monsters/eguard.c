#include "std.h"

inherit MONSTER;
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short", "guard");
        set("long", "This thug is guarding the door leading to the office behind the exchanger's office.\n");
        set_level(6);
        set_body_type("human");
        set_class("fighter");
      set_property("swarm",1);
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
 	set_hd(6,1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/club")->move(TO);
// 	     command("wield club in right hand and left hand"); 
      command("wield club");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
}
