#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("Trident");
    set_short("Merman's Trident");
    set_id( ({"trident", "Trident", "mermans trident", "merman's trident"}) );
    set_long(
      "This trident was made by Mermen and Mermaids for underwater use.  It is designed specially to be able to move through water fluidly, easing the task of underwater combat."
    );
    set_weight(10);
    set_size(2);
    set("value", 50);
    set_wc(1,6);
    set_large_wc(3,4);
    set_type("pierce");
    set_prof_type("underwater fork");
    set_weapon_speed(7);
    set_hit((:this_object(), "extra_hit":));
}

int extra_hit(object targ){
    object here, holder;

    here = environment(query_wielded());
    holder = query_wielded();
    if(!environment(query_wielded())->query_property("underwater")) return 1;

    if(!random(5)){
      tell_object(holder, "%^BOLD%^%^CYAN%^The trident moves easily through the water slamming into "+targ->query_cap_name()+".");
      tell_object(targ, "%^BOLD%^%^CYAN%^"+holder->query_cap_name()+" pierces you with the trident!");
      tell_room(here, "%^BOLD%^%^CYAN%^"+holder->query_cap_name()+" pierces "+targ->query_cap_name()+" with the trident!", ({holder, targ}));
      targ->do_damage("torso", roll_dice(3,5));
      return random(15);
    }
    return 1;
}
