#include "/d/common/common.h"
#include "std.h"
#include <daemons.h>

inherit MONSTER;
void create() {
    ::create();
        set_name("patrol");
          set_id( ({ "patrol","deputy"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " city patrol deputy");
        set("long", "This is one of the deputies in charge of those who patrol the streets.\n");
   set_level(8);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 20);
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
   set_hd(8,8);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
          new(CWEAP"two_hand_sword")->move(TO);
        command("wield sword in right hand and left hand");
        new(CARMOR"chain")->move(TO);
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(10));
        add_money("copper",random(20));
        set_wimpy(50);
        set_emotes(10,({"Blasted villians\n",
  	"Bloody rebels\n",
	"Horrid, You are the cause of all that is evil in this city.\n"}),1);
}
