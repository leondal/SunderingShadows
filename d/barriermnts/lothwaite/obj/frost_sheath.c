//sheath for Frostbrand Circe 6/15/04
#include <std.h>

inherit "/d/common/obj/sheath/sheath_large";

void create(){
   ::create();
   set_name("frost sheath");
   set_id(({"sheath", "large sheath","large sheaths","large Sheaths","large Sheath", "weapsheath", "frost sheath","frost brand sheath","Frost Sheath" }));
   set_short("%^BOLD%^Frost Sheath%^RESET%^");
   set_long("%^BOLD%^This sheath is made of leather tanned and "+
      "dyed to an almost silver sheen to match the fantastic "+
      "blade known as %^BOLD%^%^BLUE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^BLUE%^t"+
      "%^CYAN%^b%^WHITE%^r%^CYAN%^a%^BLUE%^n%^CYAN%^d%^WHITE%^.  "+
      "The tip of the sheath is reinforced by a mystical %^CYAN%^"+
      "snowflake %^WHITE%^made of %^RESET%^platinum%^BOLD%^, and "+
      "the top of the sheath bears a swirling %^RESET%^platinum "+
      "%^BOLD%^designed with scattered %^CYAN%^snowflakes %^WHITE%^"+
      "made of %^BLUE%^sapp%^CYAN%^h%^BLUE%^ires%^WHITE%^.  Several "+
      "adjustable straps are fitted to the back of the sheath, so "+
      "that it may be worn at several different places on the body.%^RESET%^\n");
   set_lore("This sheath was made to house %^BOLD%^%^BLUE%^F%^CYAN%^r"+
      "%^WHITE%^o%^CYAN%^s%^BLUE%^t%^CYAN%^b%^WHITE%^r%^CYAN%^a%^BLUE%^"+
      "n%^CYAN%^d%^RESET%^, a sword that became as legendary as its "+
      "wielder during the winter of 342 SG.  This beautiful "+
      "sheath was made as a gift from the people of Lothwaite at "+
      "the coronation of their new king, Celyddon.  It is said that "+
      "Celyddon never went without the sword, even sleeping in it - "+
      "if rumors are to be believed.");
   set_property("lore difficulty",15);
}