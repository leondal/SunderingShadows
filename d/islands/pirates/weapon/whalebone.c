#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
    set_id(({"whalebone dagger","whalebone","dagger"}));
    set_name("whalebone dagger");
    set_short("whalebone dagger");
set_long("This is a dagger carved from the bones of a whale. It is quite sturdy.");
    set_wc(1,5);
    set_large_wc(1,5);
    set_weight(2);
    set_size(1);
    set("value",1000);
    set_type("piercing");
    set_hit((: TO,"extra_hit" :));
    set_prof_type("small blades");
}
int extra_hit(object victem){
    victem = ETO->query_current_attacker();
    if((roll_dice(1,20))>17){
    tell_object(ETO,"%^BOLD%^%^BLUE%^You stab "+victem->query_cap_name()+" with the force of the deep!%^RESET%^");
	tell_object(victem,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" stabs you with the force of the deep!%^RESET%^");
	message("other_action","%^BOLD%^%^BLUE%^" +ETO->query_cap_name()+ " stabs "+victem->query_cap_name()+" with the force of the deep!%^RESET%^" "",environment(victem),(({ETO,victem})));
	victem->do_damage("torso",(random(5)+5));
	return 1;
    }else return 1;
}
