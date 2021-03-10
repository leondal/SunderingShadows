#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  	::create();
  	set_id(({"war lizard","lizard","giant lizard","steed","mount"}));
  	set_name("war lizard");
  	set_short("%^GREEN%^Giant War Lizard%^RESET%^");
  	set_long(
@DIEGO
This giant lizard seems to have been domesticated.  Although 
he is ridden those rows of sharp teeth look like they could 
still deal much damage as well as the clawed front feet.  He 
does not look very fast, but looks can be deceiving.
DIEGO
  	);
  	set_property("water breather",1);
  	set_level(12);
  	set_value(1000);
  	set_race("lizard");
  	set_stats("strength",16);
      set_riding_level(20);
  	set_gender("neuter");
  	set_body_type("quadruped");
  	set_size(3);
  	set_max_hp(175);
  	set_hd(10,2);
  	set_hp(200);
  	set_overall_ac(-6);
  	set_exp(2700);
  	set_max_distance(20);
  	set_enter_room("plods in");
  	set_exit_room("leaves riding a Giant war lizard.");
  	set_vehicle_short("giant war lizard");
  	set_attack_limbs(({"right claw","left claw","teeth"}));
  	set_attacks_num(3);
  	set_damage(2,10);
  	set_emotes(1,({
		"The %^RED%^war %^GREEN%^lizard %^RESET%^flickers his tongue in and out.",
		"The %^RED%^war %^GREEN%^lizard %^RESET%^hisses softly.",
 		"The %^RED%^war %^GREEN%^lizard %^RESET%^swings his tail back and forth.",
		"The %^RED%^war %^GREEN%^lizard %^RESET%^tests the air with his forked tongue.",
		"The %^RED%^war %^GREEN%^lizard %^RESET%^claws at the ground.",
            "The %^RED%^war %^GREEN%^lizard %^RESET%^blinks its huge reptilian eyes "+
			"slowly.",
		"The %^RED%^war %^GREEN%^lizard %^RESET%^licks his huge eye slowly "+
			"and deliberately."
    	}),0);

    set_riding_level(20);
}
