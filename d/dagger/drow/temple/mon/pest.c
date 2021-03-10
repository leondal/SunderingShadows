#include <std.h>
inherit "std/monster";
 
object owner;
int FLAG;
void create() {
    :: create();
    set_name("spider");
    set_id(({
        "spider","black spider","pest"
    }));
    set_short("%^RED%^Small spider%^RESET%^");
    set_long(
        "A small black spider which seems to enjoy climbing on "
	"you.%^RESET%^"
    );
    set_gender("male");
    set_level(5);
    set_weight(30);
    set_overall_ac(-9);
    set_body_type("arachnid");
    set_race("spider");
    set_class("fighter");
    set_stats("strength",10);
    set_stats("constitution",10);
    set_stats("dexterity",10);
    set_stats("wisdom",15);
    set_stats("intelligence",15);
    set_stats("charisma",5);
    set_exp(1100);
    set_max_hp(60);
    set_hp(60);
    set("aggressive","aggfunc");
    set_emotes(2,({
        "%^GREEN%^The spider climbs up your leg.%^RESET%^",
	"%^GREEN%^The spider climbs up your arm.%^RESET%^",
	"%^GREEN%^The spider climbs inside your clothes.%^RESET%^",
	"%^GREEN%^The spider climbs across your neck.%^RESET%^",
	"%^GREEN%^The spider climbs into your hair.%^RESET%^",
	"%^GREEN%^The spider climbs across your back.%^RESET%^",
	"%^GREEN%^The spider tries to climb into your ear.%^RESET%^"
    }),0);	
}
void aggfunc() {
    if(FLAG == 0) {
	owner = TP;
        FLAG = 1;
	write(
	    "%^GREEN%^The small spider clambers up your "
	    "leg.%^RESET%^"
	);
    }
}
    
void heart_beat() {
    object env;
    ::heart_beat();
    
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    env = environment(this_object());
    if(!owner) return;
    if(FLAG == 0) return;
    if(owner->query_ghost()) {
	FLAG == 0;
        TO->remove();
        return;
    }
    if(present(owner,env)) {
        if(random(10) < 3) {
            owner->add_hp(-(random(4)+1));
	    owner->add_poisoning(2);
            this_object()->add_hp(5);
            return;
	} else {
            return;
        }
    } else {        
        if(environment(TO) !=environment(owner)) {
	    tell_room(environment(TO), 
	        "The spider wanders after "
	        +owner->query_cap_name()+".\n"
	    );
            tell_room(environment(owner), 
	        "A small spider enters.\n"
	    );
            move_object(environment(owner));
      	    return;
        } 
    } 
}
