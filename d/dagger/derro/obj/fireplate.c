//cleaned up code a bit and brought to current standards ~Circe~ 7/30/19

#include <std.h>
inherit "/d/common/obj/armour/fullplate";

object ob;

void create(){
   ::create();
   set_name("plate");
   set_id(({"plate","armor","red plate","gilded red plate"}));
   set_short("%^RED%^Gilded Red Plate%^RESET%^");
   set_long("%^BOLD%^%^RED%^This armor is meant for a truly huge creature.  It's easily twelve feet around the chest and looks on the scale of a giant dwarf.  Its crimson surface bears detailed gold trim, with blackened patches that look scorched as if by intense heat.  This is somehow mirrored by the feel of the armor itself, each plate pleasantly warm to the touch.%^RESET%^");
   set_lore("This massive set of fullplate is intimidating in every way.  Once worn by Rahvas, King of the Firegiants, it seems to contain at least some of his essence, making you wonder if it has enough sentience to seek revenge for his death. Surely not...");
   set_value(10000);
   set_property("enchantment",4);
}