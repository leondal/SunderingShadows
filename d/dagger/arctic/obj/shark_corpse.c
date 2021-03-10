#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create() 
{
    set_id( ({"corpse", "shark corpse"}) );
    set_name("the corpse of Dire Shark");
    set_short("%^MAGENTA%^the corpse of Dire Shark");
    set_weight(1000000);
    set_long("%^BOLD%^%^RED%^This is the dead body of a male shark.  In life it looked something like:%^RESET%^\n"
        "This massive shark is over fifty feet long.  Its skin is a sleek, "
        "glistening gray and it moves with disturbing agility.  The massive dorsal "
        "fin along its back is the size of the sail on a small ship, and its jaws "
        "look as if they could swallow a full grown giant with ease.  The shark has "
        "huge black eyes that are absent any pupils. %^YELLOW%^ The belly of the shark is "
        "full and rounded, perhaps you could cut your way inside?%^RESET%^");
    set_max_internal_encumbrance(500);
    set_no_clean(1);
}
