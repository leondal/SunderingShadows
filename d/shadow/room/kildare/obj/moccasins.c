#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("moccasins");
   set_id(({"moccasins","moccasin","shoes","boots"}));
   set_short("%^RESET%^%^ORANGE%^A pair of suede moccasins%^RESET%^");
   set_long(
@CIRCE
Brushed suede from sheep has been used to craft this pair 
of comfortable moccasins.  They are soft, heelless leather 
boots that just cover the ankles.  The sole of the shoe is 
brought up the side of the foot and over the toes, where it 
is joined with a puckered seam to a U-shaped piece that covers 
the top of the foot.  The seam is made with a slender strip of 
leather, and the boots are lined with soft wool.
CIRCE
   );
   set_lore("This is a finely-tailored pair of moccasins made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(4);
   set_value(40);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_size(random(3)+1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme() {
   tell_object(ETO,"%^YELLOW%^You pull on the moccasins and feel your "+
      "feet relax.%^RESET%^");
   return 1;
}

int unwearme() {
   tell_object(ETO,"%^RED%^You can almost hear your feet groan as you take off the moccasins.");
   return 1;
}
