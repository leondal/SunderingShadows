#include <std.h>

inherit"/std/armour";

void create(){
::create();

set_name("Leather Coif");
set_id(({"coif","leather coif","helm","helmet","leather"}));
set_obvious_short("a leather coif");
set_short("%^RESET%^%^ORANGE%^Leather Coif%^RESET%^");
/*
set_long("This looks to be a durable leather coif. "+
"It looks like it could provide half decent protection. "+
"It seems to have some sort of enchantment to keep it free of dirt and lice.");
Original Description
*/
set_long("%^RESET%^%^ORANGE%^This durable coif has been fashioned from "+
   "thick leather.  The coif curves around the face, fastening under "+
   "the chin with a single strap.  The coif looks as though it would "+
   "provide half-decent protection, though it certainly isn't much "+
   "to look at.  Strangely, dirt and other debris seems to simply "+
   "fall from it, leaving it pristine.%^RESET%^");
set_lore("This coif looks much like what it is - a simple item for "+
   "protection made by those who value stealth and flexibility over "+
   "the clanging of metal.  This particular coif has been embroidered "+
   "with a stylized 'K' - though you are not yet sure what that means.");
set_type("leather");
set_limbs(({"head"}));
set_ac(1);
set_property("enchantment",1);
set_weight(2);
set_value(20);
}
