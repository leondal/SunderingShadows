#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("gnome");
	set_id( ({ "gnome","gnome city guard","city guard","guard" }) );
	set("race", "gnome");
	set_gender("male");
	set("short", "Gnome city guard");
        set("long"," Similar to their larger cousins, dwarves, this "
                   "creature's hair is medium white with grayish blue eyes.");
	set_level(6);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(2);
  	set_size(1);
        set_hd(6,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(50);
        set_hp(random(15)+45);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
  new("/d/common/obj/weapon/pick")->move(TO);
      	command("wield pick");
	add_money("silver",random(10));
	add_money("copper",random(20));
   set_overall_ac(7);
   
}
