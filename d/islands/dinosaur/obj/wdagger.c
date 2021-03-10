#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit WEAPON;

void create(){
    ::create();
    set_name("dagger");
    set_short("%^BOLD%^%^CYAN%^Water Dagger%^RESET%^");
    set_id( ({"dagger", "water dagger", "Water Dagger", "water", "wdagger"}) );
    set_long(
      "This small blue dagger has a normal looking hilt, but as you examine the blade, it seems as if it is moving, in an almost fluid manner.  The blade actually seems soft to the touch on the sides, but the edges are very sharp and biting."
    );
      set_wc(1,6);
    set_large_wc(2,4);
    set_value(300);
    set_weight(3);
    set_size(1);
    set_type("piercing");
    set_property("enchantment", 2);
    set_wield( (:TO, "extra_wield":) );
    set_hit( (:TO, "extra_hit":) );
}

int extra_hit(object targ){
    object here, holder;

    if(!objectp(query_wielded())) return 0;
    if(!objectp(targ)) return 1;
    here = environment(query_wielded());
    if(!objectp(here)) return 0;
    holder = query_wielded();

    if(!random(5)){
      tell_room(here, "%^CYAN%^The dagger slides easily into "+targ->query_cap_name()+"'s chest!", ({targ, holder}));
      tell_object(targ, "%^CYAN%^The dagger slides effortlessly into your chest!");
      tell_object(holder, "%^CYAN%^The dagger slides effortlessly into "+targ->query_cap_name()+"'s chest!");
      targ->do_damage("torso", roll_dice(3,10));
      if(random(5)){
        tell_object(targ, "%^RED%^You feel somthing very painful seep into your blood!!");
        targ->add_poisioning(100);
      }
    }
    return 1;
}

int extra_wield(){
    if(!objectp(ETP)) return 1;
    if(ETP->query_property("underwater")) return 1;
    tell_object(TP, "%^CYAN%^The dagger pulls some of the water from your body to sustain itself!");
    set_property("magic", 1);
    TP->do_damage("torso", 5);
    remove_property("magic");
    return 1;
}
