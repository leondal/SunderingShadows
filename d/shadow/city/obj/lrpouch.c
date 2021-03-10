#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "cartridges","cartridge","pouch","leather pouch" }));
   set_name("leather cartridge pouch");
   set_short("%^RESET%^%^ORANGE%^A sturdy leather pouch%^RESET%^");
   set_long("%^ORANGE%^This is a sturdy leather pouch especially created to hold gun cartridges. "+
   "It can easily be worn on your belt, providing easy access to the cartridges inside. "+ 
   "A small flap closes over the pouch, and can be tucked inside a %^BOLD%^%^BLACK%^black leather "+ 
   "loop %^RESET%^%^ORANGE%^in order to keep the contents safe and dry. Embossed into the pouch is the image of a "+ 
   "%^BOLD%^%^BLACK%^s%^RESET%^ha%^BOLD%^%^BLACK%^r%^RESET%^p-t%^BOLD%^%^BLACK%^o%^RESET%^ot%^BOLD%^%^BLACK%^he%^RESET%^d "+ 
   "r%^BOLD%^%^BLACK%^a%^RESET%^t%^ORANGE%^. Inside are small paper cartridges. "+ 
   "A %^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^o%^BOLD%^xi%^RESET%^%^GREEN%^c s%^BOLD%^ce%^RESET%^%^GREEN%^n%^BOLD%^t "+ 
   "%^RESET%^%^ORANGE%^fills the air around the pouch.%^WHITE%^");
   set_ammo_type("cartridge");
   set_weight(1);
   set_shots(-1);
   set_value(1);
   set_wc(1,4);
   set_large_wc(1,4);
   set_poisoning(8);
}