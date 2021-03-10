#include <std.h>
inherit "/d/common/obj/armour/horseshoes";

void create() {
   ::create();
   set_name("silver horseshoes");
   set_id(({"horseshoes","horse shoes","silver horseshoes","lucky horseshoes"}));
   set_obvious_short("%^BOLD%^%^WHITE%^silver horseshoes%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Lucky Horseshoes%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A gleaming pair of %^BOLD%^%^WHITE%^s%^RESET%^il%^BOLD%^%^BLACK%^v%^RESET%^er"
"%^BOLD%^%^WHITE%^y %^BOLD%^%^BLACK%^horseshoes, each forms a perfect arc to fit the underside of a hoof.  "
"An indented ridge runs along the flat side, following the curve of the metal exactly.  Certainly it seems "
"they might be %^RESET%^%^CYAN%^ornamental %^BOLD%^%^BLACK%^rather than functional, as there are no holes "
"for nails, and such a soft metal as %^RESET%^silver %^BOLD%^%^BLACK%^would surely not be particularly "
"durable.%^RESET%^\n");
   set_lore("Such an item as these horseshoes lie somewhere between a traditional gift and a running joke.  "
"With horseshoes being seen by some cultures as a lucky token, they are usually kept as a memento or a charm "
"rather than a functional day-to-day item for use.  A group of well-meaning halflings of the meadows once "
"bestowed such to a clan of centaurs from the nearby darkwood forest for their aid in defending their homelands, "
"imbued with minor magic to protect their wearers.  The centaurs, taking the gift in good humour, wore them as a "
"token of pride.  The story, the friendship, and the fondness for such unusual hoof-wear, have been passed on by "
"both races to the generations that followed.  Though occasionally, less savory sorts, such as passing minotaurs "
"or the wereboars who stalk the meadows to this day, manage to get hold of such items as well...");
   set_property("lore difficulty",10);
   set_value(120);
   set_property("enchantment",1);
   set_wear("The gleaming horseshoes adhere themselves to your hooves.");
   set_remove("You separate the horseshoes from your hooves.");
   set_size(3);
}
