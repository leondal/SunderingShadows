#include <std.h>
inherit "/std/monster";

create() {
   object scroll;
    ::create();
	set_name("gnome");
	set_id( ({ "gnome","citizen" }) );
    set("race", "gnome");
//  set_property("no attack",1);
	set_gender("male");
	set("short", "Gnome citizen");
   set("long"," Similar to their larger cousins, dwarves, this "
                   "creature's hair is medium white with grayish blue eyes.");
	set_level(6);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(1);
        set_hd(6,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(50);
        set_hp(random(10)+35);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
  new("/d/common/obj/weapon/shortsword")->move(TO);
      	command("wield sword");
   set_overall_ac(6);
   remove_property("swarm");
   if(!random(5)) {
     scroll = new("/d/magic/scroll");
     scroll->set_spell(3);
     scroll->move(this_object());
   }
}
