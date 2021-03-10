#include <std.h>

inherit "/std/flying_mount.c"; 
void create() {    
    ::create();
    set_name("Pterodactyl");
    set_id( ({"dino","Pterodactyl","pterodactyl","mount"}) );
    set_short("%^RESET%^%^GREEN%^Pter%^ORANGE%^o%^GREEN%^dac%^ORANGE%^t%^GREEN%^yl%^RESET%^");
    set_long("%^GREEN%^This winged dinosaur looks much bigger"+
	" because of its %^BOLD%^giant wingspan.%^RESET%^%^GREEN%^ "+
	"It has a pointed head and stands in a semi erect posture"+
	" with most of its body hunched forward.  It has a "+
	"%^BOLD%^%^GREEN%^long tale%^RESET%^%^GREEN%^ that drags "+
	"behind it while on the ground.  The dinosaurs' eyes are beady."+
	"  Combined this with the long rows of sharp teeth make the "+
	"creature look a bit intimidating.  ");
    set_level(20);
    set_riding_level(25);  
    set_value(10000);
    set_race("dragon");
    set_gender("neuter");
    set_body_type("dragon");
    set_size(3);
    set_max_hp(700);
    set_hp(700);
    set_hd(10,10);
    set_hp(700);
    set_overall_ac(5);
    set_exp(10);
    set_max_distance(200);
    set_enter_room("rides in.");
    set_exit_room("leaves riding a winged dinosaur.");
    set_vehicle_short("%^RESET%^%^GREEN%^Pter%^ORANGE%^o%^GREEN%^dac%^ORANGE%^t%^GREEN%^yl%^RESET%^");
    set_attacks_num(3);
    set_damage(1,6);
    // stuff below here necessary for flying mounts -Ares

set_flight_delay(900); 
    set_flying_prof(30);  
    set_ward_pass(10);   
}
