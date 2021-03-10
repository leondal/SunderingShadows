#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit "/d/common/obj/armour/shield.c";
int is_metal() { return 0; }

void create(){
    ::create();
    set_name("Ivory Shield");
    set_id( ({"shield", "ivory shield", "ivory"}) );
    set_short("%^RESET%^%^BOLD%^Ivory Shield%^RESET%^");
    set_long(
      "This finely crafted shield has been made of ivory from the bones and teeth of slain dinosaurs.  A finely crafted design depicting a Tyrannosaurus Rex standing and roaring is on its raised on its front.  You can feel a strange power flow through it."
    );
    set_ac(0);
    set_type("shield");
    set_limbs( ({"right hand"}) );
     set_property("enchantment", 3);
    set_size(2);
    set_weight(13);
    set_value(2750);
}
