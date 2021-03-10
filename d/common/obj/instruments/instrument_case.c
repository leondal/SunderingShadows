//for bard instruments - adapted from the pouch for gems on Tonerra
//Circe 6/14/04
// changed to use the setting for items allowed and lowered weight a little *Styx 5/21/06
// removed components bag functionality, inheriting both causes issues --Yves 11/18
#include <std.h>
#include <move.h>
#define BARD_COMP "/d/magic/store_comp"

inherit "/d/common/obj/sheath/sheath_inherit.c";

#include <spellcomponents.h>
//inherit "/d/magic/comp_bag.c";

void create()
{
    ::create();

    remove_property("can_hold");
    set_property("can_hold",({ "instrument",}));
    remove_property("can_wear_limbs");
    set_property("can_wear_limbs",({ "torso" }));
    remove_property("sheath_size");
    remove_property("original_weight");
    set_property("sheath_size",2);
    set_property("original_weight",2);
    set_name("medium blade sheath");

    set_id(({"case","instrument case"}));
    set_name("instrument case");
    set_short("%^RESET%^%^ORANGE%^leather instrument case%^RESET%^");
    set_long("This case is made from %^RESET%^%^ORANGE%^supple "+
        "leather %^RESET%^water-proofed "+
        "and tanned to protect its contents.  It has been specially "+
        "made to carry instruments, and it includes several pockets "+
        "inside for things like %^BOLD%^polish%^RESET%^, %^YELLOW%^"+
        "oil%^RESET%^, extra strings, and "+
        "the like that entertainers often find themselves in need of.  "+
        "The top of the case overhangs the lower portion and "+
        "closes securely with toggles made of wood.  The case has "+
        "a long, padded strap that may be stretched across the "+
        "entertainer's chest to keep the beloved instrument close at "+
        "hand.");
    set_max_internal_encumbrance(20);
    set_value(650);
    set_weight(5);  // was 10
    set_property("repairtype",({ "armorsmith" }));
}

int is_instrument_case() { return 1; }









/*

inherit PARMOUR;

void create(){
   ::create();
   set_name("instrument case");
   set_short("%^RESET%^%^ORANGE%^leather instrument case%^RESET%^");
   set_long("This case is made from %^RESET%^%^ORANGE%^supple "+
      "leather %^RESET%^water-proofed "+
      "and tanned to protect its contents.  It has been specially "+
      "made to carry instruments, and it includes several pockets "+
      "inside for things like %^BOLD%^polish%^RESET%^, %^YELLOW%^"+
      "oil%^RESET%^, extra strings, and "+
      "the like that entertainers often find themselves in need of.  "+
      "The top of the case overhangs the lower portion and "+
      "closes securely with toggles made of wood.  The case has "+
      "a long, padded strap that may be stretched across the "+
      "entertainer's chest to keep the beloved instrument close at "+
      "hand.");
   set_id(({"case","instrument case"}));
   set_max_internal_encumbrance(20);
   set_limbs(({"torso"}));
   set_type("ring");
   set_weight(5);  // was 10
   set_value(650);
   set_property("repairtype",({ "armorsmith" }));
}

int item_allowed(object item) {
   if(item->is_instrument()) {
      return 1;
   }
   write("This is meant for instruments only.");
   return 0;
}



*/
