//gloves for the archers
#include <std.h>
inherit "/d/common/obj/clothing/gloves";

void create(){
   ::create();
   set_name("gloves of accuracy");
   set_id(({"gloves","gloves of accuracy","glove"}));
   set_short("%^ORANGE%^Gloves of Accuracy%^RESET%^");
   set_obvious_short("%^ORANGE%^leather gloves%^RESET%^");
   set_lore("The gloves appear to be of elven craftsmanship."+
   "  They seems to come from a lost tribe of gold elves.  "+
   "The magic rune on the palm is something that looks to "+
   "increase the accuracy of the wearer's attacks.  Something"+
   " like this would be popular with archers.");
   set_property("lore difficulty",30);
   set_long("%^ORANGE%^These soft leather gloves are masterful in "+
   "craftsmanship.  They are a soft brown and have a strap on the"+
   " wrist to adjust them tight.  There is a single flowing rune "+
   "drawn on the palm of the glove that glows brightly with magic.%^RESET%^");
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",3);
   set_item_bonus("attack bonus",4);
}
int wear_me(){
  tell_object(ETO,"You feel more accurate.  "+
   "Like you could strike through your enemies defenses better.");
  return 1;
}
