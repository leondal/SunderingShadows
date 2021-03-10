#include <std.h>
#include "../piratedefs.h"
inherit OBJECT;

void create(){
    ::create();
    set_id(({"container","container of venom","venom"}));
    set_name("Container of Venom");
    set_short("Container of Venom");
    set_long("This is a slender vial of %^GREEN%^dull green liquid%^RESET%^, used specifically for the "
"dagger of venom.  You must have this container present to <refill> the dagger.");
    set_value(5000);
    set_weight(3);
}
