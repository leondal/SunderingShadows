//sigring.c
#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("signet ring");
   set_id(({"ring","signet ring","silver ring"}));
   set_short("A silver ring");
   set_long("%^BOLD%^%^WHITE%^This ring is crafted of smooth silver flattened into a "+
      "darkened oval on top.  Engraved there is a crest - a shepherd's "+
      "crook slanted over a backdrop of mountain peaks.%^RESET%^");
   set_lore("This ring is a symbol of Kildare Glen.  It bears the "+
      "crest of the once-quiet community that is now plagued "+
      "by the foul perytons.");
   set_property("lore difficulty",4);
   set_weight(2);
   set_value(15);
   set_type("ring");
   set_ac(0);
   set_limbs(({"right hand","left hand"}));
}
