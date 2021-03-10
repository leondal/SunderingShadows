//changed to common inherit by Circe to help with maintenance and balance.  12/14/03
//added lore - Circe 5/28/04
#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create(){
    ::create();
//    set_short("Bracers of Defense");
    set_value(3000);
//    set_ac(3); taken care of in the inherit
    set_property("enchantment",3);
    set_lore("These bracers are known as bracers of defense, as they "+
       "create a magical force around the wearer that makes him "+
       "harder to hit.  They were once called 'Bracers of "+
       "Repelling' by the magi who created them, but since they have "+
       "become more widespread, the common folk have taken to calling "+
       "them bracers of defense after the most obvious benefit they "+
       "have.  The magical force around them was also once known to "+
       "repel larger objects, such as arrows and sling bullets flying "+
       "at the wearer, sometimes even hurling them back!  That magic, "+
       "however, drains much from the mage at the time of creation, "+
       "and now bracers such as those are extremely rare.");
}
