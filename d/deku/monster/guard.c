#include <std.h>
inherit "/std/monster";
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short","Bank guard");
        set("long","This guard stands erect by the exit of the\n"+
                   "Bank of Verbobone.  He carries an overall uninterested\n"+
                   "look on his face.\n");
	set_level(15);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",16);
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
  new("/d/common/obj/weapon/longsword")->move(TO);
        command("wield longsword in right hand");
        new("/d/deku/armours/chain")->move(TO);
        command("wear chainmail");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
      set_hp(140);
      set_exp(500); /* was 2600 from defaults from HD */
} 
