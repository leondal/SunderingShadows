#include <std.h>

inherit "/std/monster";

create() {
   object scroll;
    ::create();
	set_name("hobgoblin");
       set_id (({"hobgoblin", "hobgoblin king", "king"}));
	set("race", "hobgoblin");
	set_gender("male");
	set("short", "Hobgoblin King");
        set("long","Hobgoblins are bigger and meaner relatives of goblins.\n"+
                   "This one looks bigger than most, and even more smelly\n"+
                   "and ugly than the others.");
	set_level(7);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
        set_hd(7,3);
   	set_stats("intelligence",12);
   	set_stats("wisdom",12);
   	set_stats("strength",16);
   	set_stats("charisma",10);
   	set_stats("dexterity",12);
   	set_stats("constitution",15);
   	set_max_mp(0);
        set_hp(random(15)+60);
        set_exp(125);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/trident")->move(TO);
        command("wield trident");
        new("/d/common/obj/armour/shield")->move(TO);
     scroll = new("/d/magic/scroll");
     scroll->set_spell(2);
	scroll->move(TO);
        command("wear shield");
	add_money("gold",random(50));
   
}
