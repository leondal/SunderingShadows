#include <std.h>

inherit "/std/flying_mount.c"; 
void create() {    
    ::create();
    set_name("dire owl");
    set_id( ({"owl","dire owl","mount","animal"}) );
    set_short("%^RESET%^%^BOLD%^Dire Owl%^RESET%^");
    set_long("%^RESET%^%^BOLD%^This owl is huge.  It is obviously a "+
	"dire owl and the head of this winged creature sits nearly six "+
    "feet above the ground.  It has white wings and a "+
	"black beak.  Two large black eyes peer at the "+
	"surroundings.  The owl appears tame.  It has "+
	"no saddle so riding it will be quite difficult.  ");
    set_level(20);
    set_riding_level(25);  
    set_value(30000);
    set_race("owl");
	if (random(2))
     set_gender("male");
	else
	 set_gender("female");
    set_body_type("bird");
    set_size(2);
	set_hd(10,10);
    set_max_hp(700);
    set_hp(700);

    set_overall_ac(5);
    set_exp(10);
    set_max_distance(200);
    set_enter_room("rides in.");
    set_exit_room("leaves riding an owl.");
    set_vehicle_short("%^RESET%^%^BOLD%^Dire Owl%^RESET%^");
    set_attacks_num(3);
    set_damage(1,6);
	 set_base_damage_type("piercing");
   

set_flight_delay(900); 
    set_flying_prof(30);  
    set_ward_pass(15);   
}
