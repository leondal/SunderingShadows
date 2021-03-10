//updated by Circe 6/1/04 with new desc, lore, etc by Shar
#include <std.h>

inherit "/d/common/obj/armour/schain.c";
void create() {
    ::create();
    set_name("chain");
    set_id(({"armor","chainmail","chainmail armor"}));
    set_short("Chainmail armor");
    set_long(
@CIRCE
Crafted from scavenged suits of chain mail, this tunic would seem to offer some protection.   Though because the armor was not tailored to the wearer and has had to be modified (rather poorly) you can't tell for sure how well it will protect.  Many of the links are coated with rust.  Still, it's got to be better than nothing.
CIRCE
    );
    set_lore("Goblins are scavengers by nature.  From weapons to armor "+
       "to everything else they need.  So it is no surprise that the "+
       "goblins make use of what they can find or steal.  If only "+
       "their craftsmanship was up to par with their brutal and savage "+
       "nature.  Wait! That is a good thing for everyone else.");
    set_property("enchantment",1);
    set_value(25);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    tell_object(ETO,"The ill-crafted chainmail settles uncomfortably "+
       "around your form.");
    return 1;
}

int removeit() {
    tell_object(ETO,"You carefully begin to remove the chainmail, "+
       "cursing as a ring falls off.");
    tell_room(EETO,""+ETOQCN+" curses "+ETO->QS+" takes off the "+
       "chainmail and a rusty ring falls off.",ETO);
    return 1;
}
