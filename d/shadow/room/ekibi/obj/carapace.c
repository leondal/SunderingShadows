//carapace.c - by Circe 3/11/05.  Random drop from cockroaches
#include <std.h>
inherit "/d/common/obj/armour/leather_plate";

void create() {
    ::create();
    set_name("insect carapace");

    set_id(({"armor","plate","breastplate","carapace","insect carapace", "armour"}));
    set_short("%^RESET%^%^ORANGE%^Insect Carapace%^RESET%^");
    set_long("This unusual breastplate has been fashioned from the "+
       "carapace of a huge insect!  There are simple leather straps "+
       "attached to allow the wearer to adjust it for a more "+
       "comfortable fit.  There seems to have been no fashioning "+
       "of the carapace - it is left in its natural hardened state.  "+
       "It looks as if it could be worn over the chest to provide "+
       "some protection while allowing for freedom of arm movement.");
    set_value(50);
    set_size(random(3)+1);
}
