// no animate comp bag
// coded 12/7/09 by hades
#include <std.h>
#include <move.h>
#include <components.h>

inherit "/d/magic/comp_bag";

void create() {
   ::create();
   comp = ([]);
   set_weight(10);
   set_value(0);
   set_id(({"componenter", "bag","leather bag", "components bag", "compx"}));
   set_name("no animate bag");
   set_short("%^BOLD%^A %^BLUE%^r%^WHITE%^u%^BLUE%^ne c%^WHITE%^o%^BLUE%^vered%^WHITE%^ leather bag%^RESET%^");
   set_property("no animate",1); // mages will love this
   
   set_long(
        "This is a small to medium-sized leather bag.  It is\n"
        "only in this bag that you store the material components\n"
        "for casting your spells.  \n"
        "There are several %^BOLD%^%^BLUE%^Glowing Runes%^RESET%^ on it.\n\n"

        "To check what is in the bag type <components>.\n"
        "To put a component into the bag type:\n"
        "<put [component name] into components bag>\n"
        "To retrieve components from the bag type:\n"
        "<produce [quantity] [component name]>\n"
        "<produce [all] [component name]>\n");
    set_property("no disenchant",1);
}
