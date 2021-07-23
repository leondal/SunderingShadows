// no animate schattel
// coded 4/4/10 by hades
#include <std.h>
#include <move.h>
#include <components.h>
inherit "/d/magic/psi_comp_bag";

void create() {
   ::create();
   comp = ([]);
    set_value(0);
   set_name("no animate satchel");
   set_short("%^BOLD%^%^BLACK%^bl%^WHITE%^ac%^BLACK%^k ve%^WHITE%^lv%^BLACK%^et%^WHITE%^ leather satchel%^RESET%^%^RESET%^");
   set_long(
"%^ORANGE%^This satchel is made of %^RESET%^%^BOLD%^%^BLACK%^black velvet%^RESET%^%^ORANGE%^ fabric " 
"which have been flawlessly created by a master craftsman. It is decorated with small "
"%^RESET%^%^BOLD%^%^BLACK%^onyx%^RESET%^%^ORANGE%^ and dark %^BLUE%^sapphires%^ORANGE%^, " 
"creating an intricate design. The satchel appears to be large enough to hold various gems, "
"but still able to be concealed under a layer of clothing. %^RESET%^\n"

      "     To put a crystal into the satchel type:\n"+
      "     <put [crystal name] into crystal satchel>\n"+
      "     To retrieve crystals from the satchel type:\n"+
      "     <produce [quantity] [crystal name]>\n"+
        "     <produce [all] [crystal name]>\n"+
      "     This satchel will only hold those crystals needed for \n"+
      "     manifesting psionic powers.\n" );
	set_property("no animate",1); // psion will love this
    set_property("no disenchant",1);
}
