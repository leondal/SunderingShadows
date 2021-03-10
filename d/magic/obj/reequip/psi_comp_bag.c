#include <std.h>
inherit "/d/magic/psi_comp_bag";

void create() {
   ::create();
   set_id(({"satchel", "leather satchel", "crystal satchel", "components satchel"}));
   set_long("%^ORANGE%^This is a slender satchel made of soft leather, lined with %^BOLD%^%^BLACK%^velvet "
"%^RESET%^%^ORANGE%^to protect crystals from scratches.  The satchel is decorated with faint etchings of "
"crystals in various shapes and features a leather thong that serves as a drawstring to close the "
"satchel.  %^YELLOW%^Only the bare minimum of crystals are within, as it is a temporary satchel only.  You "
"are unable to add or remove components to this bag.\n\n"
"     To check what is in the satchel type <crystals>.\n");
}

int produce(string str) {
        if(!str) return notify_fail("Produce what?\n");
        tell_object(TP,"This is only a temporary satchel, you cannot take crystals out of it!");
        return 1;
}

int query_value(){ return 0; }