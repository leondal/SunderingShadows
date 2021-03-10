//horned_helm - standard item sold in new Seneca
//cosmetic update to the common one.  ~Circe~ 12/15/07
#include <std.h>

inherit "/d/common/obj/armour/helm";

void create(){
   ::create();
   set_name("horned helm");
   set_id(({"helm","helmet","great helm","horned helm"}));
   set_short("%^BOLD%^%^BLACK%^a %^WHITE%^horned %^BLACK%^helm%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Crafted from blackened steel, this "+
      "helm features square cheek guards edged with %^RESET%^silver "+
      "plating %^BOLD%^%^BLACK%^that leave an open area for the "+
      "wearer's mouth and eyes, granting a wide field of vision.  "+
      "A %^RESET%^silver stripe %^BOLD%^%^BLACK%^begins just above "+
      "the wearer's nose and continues to the topknot of black "+
      "horsehair that tops the helm.  The hair is left long, extending "+
      "well down one's back, and it is braced on either side by "+
      "%^WHITE%^ivory horns %^BLACK%^that curve upward, the tip "+
      "of each blackened.%^RESET%^");
   set_value(150);
   set_wear("You settle the helm on your head and feel the "+
      "ferocity of battle rising up inside you.");
}