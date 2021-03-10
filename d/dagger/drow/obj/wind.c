#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id (({"wind"}));
    set_name ("wind");
    set_short ("%^CYAN%^Wind");
set_long ("The wind of the air elemental.");
    set_weight (10);
    set_size (3);
    set_value (1);
    set_property ("monsterweapon",1);
    set_wc (2,10);
set_type ("piercing");
}
