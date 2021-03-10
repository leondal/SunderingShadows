//updated a bit to current code ~Circe~ 8/17/19
#include <std.h>
inherit "/d/common/obj/weapon/giant_club.c";


void create() {
   ::create();
   set_id(({ "bone", "club", "giant bone", "Giant Bone" }));
   set_name("giant bone");
   set_short("%^RESET%^%^BOLD%^%^WHITE%^A g%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^ant bo%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^WHITE%^e%^RESET%^");
   set_long("%^RESET%^%^BOLD%^%^WHITE%^This club is nothing more then the gi%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^nt bo%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^WHITE%^e of some unfortunate beast that someone decided would be good for bashing other things with. A %^RESET%^%^ORANGE%^st%^RESET%^%^WHITE%^r%^RESET%^%^ORANGE%^ip of leat%^RESET%^%^WHITE%^h%^RESET%^%^ORANGE%^er %^RESET%^%^BOLD%^%^WHITE%^is wrapped around one end of the bo%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^WHITE%^e to provide a grip that doesn't slip as much. The 'business end' has nicks, scratches, and gnaw marks.%^RESET%^");
   set_property("enchantment",random(2) + 1);
}
