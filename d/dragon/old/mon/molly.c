#include <std.h>

inherit "/std/townsman.c";

void create() {
    ::create();
	set_name("molly");
	set_id( ({ "molly", "herbalist" }) );
	set("race", "human");
	set_gender("female");
        set("short", "Molly Kerwig, the herbalist");
        set("long","Molly is an expert herbalist.  Her natural potions \n"+
                   "are relatively inexpensive to prepare.  Her personal\n"+
                   "ethics forbid her from making poisons and other detrimental\n"+
                   "concoctions.\n");
	set_level(5);
	set_body_type("human");
	set_class("fighter");
  	set("aggressive", 0);
  	set_alignment(7);
        set_hd(5,1);
  set_max_hp(30);
  set_hp(30);
  	set_size(2);
   	set_stats("intelligence",17);
   	set_stats("wisdom",15);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
 	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	add_money("gold",random(5));
}






