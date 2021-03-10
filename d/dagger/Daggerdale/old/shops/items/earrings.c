#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("moonstone earrings");
   set_short("A pair of %^BOLD%^%^WHITE%^moonstone%^RESET%^ earrings");
   set_id(({"dagger_jewelry","earrings","moonstone earrings","pair of earrings","pair of moonstone earrings"}));
   set_long("This is a pair of %^BOLD%^%^WHITE%^moonstone%^RESET%^ earrings that are fashioned"+
   " of silver. They dangle down a ways, with a bead of %^MAGENTA%^amethyst%^RESET%^ at"+
   " the very top, followed by two smaller beads of %^BOLD%^moonstone%^RESET%^, and"+
   " then a larger teardrop shaped %^BOLD%^moonstone%^RESET%^. The earrings have hooks"+
   " in the back of them that you can put in your ears if they are"+
   " pierced.");
   set_weight(1);
   set_value(50);
   set_cointype("silver");
   set_type("ring");
   set_limbs(({"head"}));
   set_wear("You carefully slip the hook of the moonstone earrings through your ear.");
   set_remove("You slip the silver hook out and remove your earrings.");
}
