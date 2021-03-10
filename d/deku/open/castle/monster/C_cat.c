// The Marleen Castle cat
// 05/03/95
// Pator@Shadowgate

#include <std.h>

inherit "/std/monster";

void create() {
     
      ::create();
    set_name("castle cat");
	set_id( ({ "cat", "castle cat" }) );
    set("race","cat");
	set_gender("male");
	set("short", "A castle cat");
    set("long","A cat living in Marleen's castle.  It is well fed by the "+
   "cook's maid.");
	set_level(1);
	set_body_type("quadruped");
  	set("aggressive", 0);
  	set_size(1);
        set_stats("strength",3);
	set_stats("dexterity",3);
	set_stats("charisma",2);	
   	set_max_mp(0);
   	set_mp(0);
	set_hd(1,0);
        set_hp(10);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
 	set_sp(10);
	set_emotes(5, ({"The cat makes cat-like noises.",
                        "The cat looks at you with sleepy eyes."}),0);
	set_achats(5, ({"The cat makes blowing noises.",
			"The cat makes a high back and has his tail high up"}));

}
