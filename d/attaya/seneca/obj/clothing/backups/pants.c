#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("breeches");
    set_id(({"breeches","pants","fine breeches"}));
    set_short("fine breeches");
    set_long("This pair of breeches is finely crafted, and made to fit "+
       "you perfectly.  The material is strong, yet airy and lightweight.  "+
       "These breeches are a brownish color.");
    set_type("clothing");
    set_limbs(({"right leg","left leg"}));
    set_weight(2);
    set_value(2);
}
