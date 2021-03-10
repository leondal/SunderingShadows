#include <std.h>
#include "../../inherit/keep.h"
inherit OBJ2+"quest_staff";

void create() 
{
    ::create();
    set_name("translucent orb");
    set_id(({"orb","translucent orb","staff-part-1"}));
    set_short("%^RESET%^%^CYAN%^a translucent orb%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This orb appears to be made of translucent "
    "glass.  It is perfectly smooth and spherical, although a few marks are "
    "scratched upon it in strategic places, like something once held it.  It "
    "seems incomplete, as if it were only part of a whole.  You could %^BOLD%^"
    "%^WHITE%^assemble%^RESET%^%^CYAN%^ it if you could find the other pieces"
    ".%^RESET%^");
    set_weight(1);
    set_value(0);
    set_mypart("orb");
}

