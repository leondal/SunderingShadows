#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
   ::create();
   set_name("tiara");
   set_id(({"tiara","tarnished tiara","cracked tiara"}));
   set_short("%^RESET%^%^MAGENTA%^F%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^d%^WHITE%^e%^MAGENTA%^d %^WHITE%^p%^BOLD%^%^CYAN%^r%^RESET%^%^WHITE%^in%^BOLD%^%^CYAN%^c%^RESET%^%^WHITE%^ess %^MAGENTA%^Tiara%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^A d%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^amo%^BOLD%^%^CYAN%^n%^RESET%^%^MAGENTA%^d studded, c%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ack%^WHITE%^e%^MAGENTA%^d tiara%^RESET%^");
   set_lore("Cerilana was an half-elf of a strange legend."+
   "   Both her human family and her elven family were "+
   "ruined during the war.  Stories are told to make "+
   "children behave that at night she can be heard "+
   "wailing in mourning for her loss outside the "+
   "town.   It looks like there is some truth behind these tales. ");
   set_property("lore difficulty",30);
   set_long("%^BOLD%^%^WHITE%^S%^BLACK%^i%^WHITE%^l%^BLACK%^v%^WHITE%^e%^BLACK%^r %^RESET%^%^MAGENTA%^and %^WHITE%^M%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^h%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^l %^MAGENTA%^as old as time itself make up the body of this peice of jewelry. Two narrow fingers reach into the hair of the young lady whom wears this, vanishing into her mane, holding the crown of the tiara in place high on the forehead. Ripped peices of frayed, faded %^BLUE%^silk %^MAGENTA%^cling to the underside, a veil fastend to it lost long ago. A swirling pattern reach up from either temple, reaching their dull spire above the center of the forehead. The swirls of the tiara have many blank fastenings, only a few of its original dozens of %^BOLD%^%^WHITE%^d%^CYAN%^i%^WHITE%^amon%^CYAN%^d%^WHITE%^s %^RESET%^%^MAGENTA%^remain, the tiny prongs bent or broken from the wear of time.%^RESET%^");
  
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",4);
   set_item_bonus("will save",2);
}
int wear_me(){
  tell_object(ETO,"%^MAGENTA%^You don the tiara on your head.");
  return 1;
}
