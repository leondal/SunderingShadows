#include <std.h>
#include "/realms/grendel/grendel.h"

inherit ARMOUR;

void create(){
    ::create();
    set_name("Masking Amulet");
    set_short("Rainbow Amulet");
    set_id( ({"amulet", "colored amulet"}) );
    set_long(
      "This beautiful teardrop shaped amulet shimmers with the colors of the rainbow as you hold it softly in your hand.  You can feel its magic pulsing in the gem in its center as you hold it.  The longer you hold it, the stronger feeling of dread and terror fill you as the colors across its surface shimmer in beautiful chaos, but as you watch, the dread fades as the chaos slowly forms exquisite patterns, but never stops moving."
    );
    set_ac(0);
    set_weight(3);
    set_value(1000);
    set_property("magic", 1);
    set_type("clothing");
    set_limbs( ({"neck"}) );
    set_property("my align", random(11)+1);
    set_wear( (:TO, "wear_me":) );
    set_remove( (:TO, "remove_me":) );
}

void init(){
    ::init();
    add_action("change_mask", "concentrate");
}

int wear_me(){
    if(!interactive(ETO)) return 1;

    if(query_property("my align") == 10){
      ETO->set_property("align mask", random(9) + 1);
      return 1;
    }

    if(query_property("my align") == 11)
      return 1;

    ETO->set_property("align mask", query_property("my align"));
    return 1;
}

int remove_me(){
    ETO->remove_property("align mask");
    return 1;
}

int change_mask(string str){
    int algn;

    if(!query_worn() || !interactive(query_worn()))
      return 0;

    if(query_property("my align") != 11)
      return 0;

    algn = align_to_num(str);
    if(algn == 0)
      return notify_fail("Not a valid selection.\n");

    ETO->set_property("align mask", algn);
    tell_object(query_worn(), "You feel a tingle.");
    return 1;
}
