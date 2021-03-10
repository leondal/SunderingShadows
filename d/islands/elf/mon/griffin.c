#include <std.h>

inherit "/std/flying_mount.c"; 
void create() {    
    ::create();
    set_name("Snow Griffin");
    set_id( ({"Griffin","snow griffin","mount"}) );
    set_short("%^RESET%^%^BOLD%^Snow Griffin%^RESET%^");
    set_long("%^RESET%^%^BOLD%^This a large white griffin."+
	"   Griffins are said to be legendary creatures "+
	"with the body of a lion and the head and wings"+
	" of an eagle.  It looks quite noble and powerful.  It has "+
        "no saddle so riding it will be quite difficult.  ");
    set_level(20);
    set_riding_level(25);  
    set_value(30000);
    set_race("griffin");
        if (random(2))
     set_gender("male");
        else
         set_gender("female");
    set_body_type("hippogriff");
    set_size(2);
        set_hd(10,10);
    set_max_hp(700);
    set_hp(700);
    set_overall_ac(5);
    set_max_distance(200);
    set_enter_room("treads in, talons clicking on the ground.");
    set_exit_room("exits leaving talon marks in the ground $D.");
    set_vehicle_short("%^RESET%^%^BOLD%^Snow Griffin%^RESET%^");
    set_attacks_num(3);
    set_damage(2,6);
	set_base_damage_type("slashing");
   

set_flight_delay(900); 
    set_flying_prof(30);  
    set_ward_pass(15);   
}