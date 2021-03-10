//~Circe~ 10/29/07
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("conch shell bracelet");
   set_id(({"bracelet","conch bracelet","shell bracelet","conch shell bracelet"}));
   set_short("%^BOLD%^%^WHITE%^a delicate %^MAGENTA%^conch shell%^WHITE%^ bracelet%^RESET%^");
   set_long("Several flawless %^BOLD%^%^WHITE%^white "+
      "con%^MAGENTA%^c%^WHITE%^h sh%^MAGENTA%^e%^WHITE%^lls "+
      "%^RESET%^with %^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^o"+
      "%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^ centers "+
      "have been strung end-to-end on a delicate %^YELLOW%^"+
      "golden chain%^RESET%^.  Each %^BOLD%^shell %^RESET%^"+
      "has been outlined in %^YELLOW%^gold%^RESET%^, "+
      "curving along the swooping open edges.  Much time and "+
      "care has clearly been taken in the creation of this "+
      "beautiful reminder of the ocean.");
   set_type("ring");
   set_limbs(({"right arm","left arm"}));
   set_weight(1);
   set_value(150+random(11));
}