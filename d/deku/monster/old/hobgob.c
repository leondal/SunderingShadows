
#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("hobgoblin");
   set_id(({"hobgoblin","smelly hobgoblin"}));
	set("race", "hobgoblin");
	set_gender("male");
	set("short", "A smelly hobgoblin");
	set("long", "A very smelly and ugly hobgoblin.\n");
	set_level(6);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
        set_hd(6,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",12);
   	set_stats("constitution",12);
   	set_max_mp(0);
        set_hp(random(10)+50);
        set_exp(50);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/short")->move(this_object());
        command("wield shortsword in right hand");
	add_money("copper",random(20));
}
