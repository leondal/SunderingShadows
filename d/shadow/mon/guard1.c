#include "./melnmarn.h";

inherit MONSTER;

void create() {
    ::create();
	set_name("guard");
   set_overall_ac(5);
        set_id( ({"guard","city guard","cityguard"}) );
	set("race", "human");
	set_gender("male");
   set_short("City guard");
   set_long("An elite soldier assigned to protect the town folks.");
   set_level(30);
	set_body_type("human");
	set_class("fighter");
  	set("aggressive", 0);
  	set_alignment(7);
   set_hd(30,8);
   set_max_hp(300);
   set_hp(300);
   set_exp(1);
  	set_size(2);
        set_stats("intelligence",16);
        set_stats("wisdom",14);
        set_stats("strength",22);
       set_stats("charisma",10);
        set_stats("dexterity",22);
        set_stats("constitution",16);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_sp(query_hp());
 	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(WEAPONDIR+"halberd")->move(this_object());
      	command("wield halberd in right hand and left hand");
        new(ARMORDIR+"banded")->move(this_object());
      	command("wear armor");
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
   set_property("full attacks",1);
   set_property("magic",1);
}
