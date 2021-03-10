#include <std.h>
inherit "std/monster";

create() {
    ::create();
	set_name("goblin");
        set_id(({"goblin","guard"}));
	set("race", "goblin");
	set_gender("male");
        set("short", "Goblin guard");
    set("long", "A very ugly and stinky goblin with the usual dirty green skin.\n");
	set_level(5);
	set_body_type("human");
  	set("aggressive",0);
        set_hd(5,1);
  	set_alignment(5);
  	set_size(1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
  new("/d/common/obj/weapon/dagger")->move(TO);
      	command("wield dagger");
        set_exp(50);
        set_hp(35);
}
