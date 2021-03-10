//updated with new description and lore to bring up to current standards ~Circe~ 7/30/19

#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
   ::create();
   set_name("kather armor");
   set_obvious_short("studded leather armor");
   set_short("%^RESET%^%^ORANGE%^studded k%^YELLOW%^a%^RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^%^ORANGE%^e%^YELLOW%^r %^RESET%^%^ORANGE%^armor%^RESET%^");
   set_id(({"studded","armor","studded kather armor","kather","leather","studded leather","studded leather armor"}));
   set_long("%^RESET%^%^ORANGE%^This tough leather is studded with c%^GREEN%^o%^ORANGE%^p%^GREEN%^p%^YELLOW%^e%^RESET%^%^ORANGE%^r and %^YELLOW%^brass %^RESET%^%^ORANGE%^and dyed dark brown.  The leather is somewhat rougher than usual and has a dark finish that reflects less light, making it ideal for darker places.%^RESET%^");
   set_lore("None, except perhaps the derro, knows why this leather is called kather. Rumors abound that the name refers to the type of finish or perhaps the maker's name ... or even a terrifying creature that lives deep in the earth that young derro must kill before earning the hide to make their own armor.");
   set_value(200);
   set_size(1);
   set_property("enchantment",3);
}
