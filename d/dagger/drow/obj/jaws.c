#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id (({"jaws"}));
    set_name ("jaws");
    set_short ("%^BLUE%^Jaws%^RESET%^");
set_long ("The jaws of the giant gar.");
    set_weight (25);
    set_size (2);
    set_value (1);
    set_property ("monsterweapon",1);
    set_wc (5,5);
set_type ("piercing");
}
