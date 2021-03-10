#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

create() {
    ::create();
    set_id(({"spear","mithril spear","mithril medium spear"}));
    set_name("mithril spear");
    set_short("A mithril spear");
    set_long("%^BOLD%^This short spear is tipped with"+
        " a bright silvery mithril spearhead.  It was "+
        "forged by the Dwarves of Mt. Sholkum in the "+
        "Dagger Reaches.  Dwarven runes line the center"+
        " of the spearhead and the long oak shaft is "+
        "polished to a high shine.  Engraved on the shaft"+
        " is the crest of the Army of the Dagger Reaches.");
   //set_weight(7);
   //set_prof_type("medium spear");
   //set_size(2);
   set_value(100);
   //set_wc(1,8);
   //set_large_wc(1,12);
   //set_type("piercing");
   set_property("enchantment", 1);
}
