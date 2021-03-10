//updated to current code 10/5/19 ~Circe~
// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/d/common/obj/armour/field.c";

void create(){
   ::create();
   set_name("half plate");
   set_id(({ "half plate","plate","armor","armour","half-plate"}));
   set_short("%^RESET%^A suit of half plate armor");
   set_obvious_short("%^RESET%^A suit of half plate armor%^RESET%^");
   set_long("This suit of half plate armor looks rather mundane and average.  An undershirt of dull chain mail offers protection to the areas that the plate mail fails to cover.  A breastplate made from a dull metal covers the torso.  The metal is shaped to angle to the left side of the body, leaving the right exposed.  A round shoulder plate curves over the left joint of the armor, giving additional protection to the vital organs. A cloth band overlaps the seam of the armor as it angles to the left, helping to support to the weight of the armor evenly. Chain mail and metal plates have been woven together to create a sleeve to protect the left arm.  Plates of metal over lay the chain mail under shirt on the outside of either thigh, further protecting the wearer from harm.");
   set_weight(45);
   set_value(1100);
   set_lore("The stars and celestial events have long moved and inspired the races across the world.  One such gnomish mage by the name of Hollindaise Badgerjowels was so facinated by the way the sky changed throughout the day that he worked to create a suit of armor that would mirror the dawn, dusk, and midnight.  Hollinadie's process to enchant a suit of half-plate armor he had found was successful, somewhat.  A hasty replacement of a key ingredient to the spell instead grounded the changes of the armor to the ethos and morals of the wearer, instead of shifting through the day as the gnome wanted. - Why Gnomes Should Not Practice Magic - Ohdelgar Rarelthic");
   set_property("lore difficulty",15);
   set_size(2);
   set_property("enchantment",3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_item_bonus("dexterity",1);
}

int wear_func(){
   int align = ETO->query_alignment();
   if((int)ETO->query_highest_level() < 20){
      notify_fail("%^CYAN%^The armor just falls off of you!");
      return 0;
   }
   switch(align){
      case 1: case 4: case 7:
         tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s armor transforms into a gleaming suit of platinum.%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^The metal transforms into gleaming platinum as you straps the armor on.%^RESET%^");
         set_short("%^BOLD%^%^WHITE%^Plate of %^RED%^D%^YELLOW%^a%^RED%^w%^MAGENTA%^n%^RED%^'%^YELLOW%^s %^WHITE%^Triumph%^RESET%^");
         set_obvious_short("%^BOLD%^%^WHITE%^A suit of platinum half-plate armor%^RESET%^");
         set_long("This suit of half plate armor is crafted from gleaming %^BOLD%^platinum%^RESET%^.  An undershirt of %^YELLOW%^gold%^RESET%^ chain mail offers protection to the areas that the plate mail fails to cover.  A breastplate made from %^BOLD%^platinum%^RESET%^ covers the torso.  The metal is shaped to angle to the left side of the body, leaving the right exposed. A %^RED%^scarlet%^RESET%^ silk band overlaps the seam of the armor as it angles to the left, helping to support to the weight of the armor evenly. The %^RED%^scarlet%^RESET%^ silk it shot through with %^YELLOW%^gold%^RESET%^ threads, which catch the light.  A round smooth shoulder plate curves over the left joint of the armor, giving additional protection to the vital organs.  The %^BOLD%^platinum%^RESET%^ shoulder plate is edged with %^YELLOW%^gold%^RESET%^.  A %^YELLOW%^golden%^RESET%^ disk of a sunburst overlaps the cloth and shoulder plate. Chain mail and metal plates have been woven together to create a sleeve to protect the left arm.  Plates of %^BOLD%^platinum%^RESET%^ over lay the %^YELLOW%^gold%^RESET%^ chain mail under shirt on the outside of either thigh, further protecting the wearer from harm.%^RESET%^");
         return 1;
      case 2: case 5: case 8:
         tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s armor transforms into a smooth suit of polished steel.%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^The metal transforms into polished steel as you straps the armor on.%^RESET%^");
         set_short("%^BOLD%^%^BLUE%^Plate of T%^RESET%^%^CYAN%^w%^GREEN%^i%^MAGENTA%^l%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^g%^GREEN%^h%^MAGENTA%^t%^CYAN%^'%^GREEN%^s%^BOLD%^%^BLUE%^ Endeavor%^RESET%^%^RESET%^");
         set_obvious_short("%^CYAN%^A suit of polished steel half-plate armor%^RESET%^");
         set_long("This suit of half plate armor is crafted from polished %^CYAN%^steel%^RESET%^.  An undershirt of %^BOLD%^mithril%^RESET%^ chain mail offers protection to the areas that the plate mail fails to cover.  A breastplate made from %^CYAN%^steel%^RESET%^ covers the torso.  The metal is shaped to angle to the left side of the body, leaving the right exposed. A %^BLUE%^blue linen%^RESET%^ band overlaps the seam of the armor as it angles to the left, helping to support to the weight of the armor evenly. The %^BLUE%^blue%^RESET%^ linen is shot through with %^BOLD%^silver%^RESET%^ threads, which catch the light.  A round smooth shoulder plate curves over the left joint of the armor, giving additional protection to the vital organs.  The%^CYAN%^ steel%^RESET%^ shoulder plate is edged with %^BOLD%^mithril%^RESET%^.  A %^BOLD%^mithril%^RESET%^ disk of a sunburst with a crescent moon inside overlaps the cloth and shoulder plate. Chain mail and metal plates have been woven together to create a sleeve to protect the left arm.  %^CYAN%^Steel%^RESET%^ plates overlay the %^BOLD%^mithril%^RESET%^ chain mail under shirt on the outside of either thigh, further protecting the wearer from harm.%^RESET%^");
         return 1;
      case 3: case 6: case 9:
         tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s armor transforms into a smooth suit of titanium.%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^The metal transforms into smooth titantium as you straps the armor on.%^RESET%^");
         set_short("%^RESET%^%^BLUE%^Plate of M%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t%^RESET%^%^BLUE%^'%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^ Struggle%^RESET%^");
         set_obvious_short("%^BOLD%^%^BLACK%^A suit of titantium half-plate armor%^RESET%^");
         set_long("This suit of half plate armor is crafted from smooth %^BLUE%^titanium%^RESET%^.  An undershirt of %^BOLD%^%^BLACK%^adamantium%^RESET%^ chain mail offers protection to the areas that the plate mail fails to cover.  A breastplate made from %^BLUE%^titanium%^RESET%^ covers the torso.  The metal is shaped to angle to the left side of the body, leaving the right exposed. A %^BOLD%^%^BLACK%^black wool%^RESET%^ band overlaps the seam of the armor as it angles to the left, helping to support to the weight of the armor evenly. The %^BOLD%^%^BLACK%^black wool%^RESET%^ is shot through with %^BOLD%^white gold%^RESET%^ threads, which catch the light.  A round smooth shoulder plate curves over the left joint of the armor, giving additional protection to the vital organs.  The %^BLUE%^titanium %^RESET%^shoulder plate is edged with %^BOLD%^%^BLACK%^adamantium%^RESET%^.  An %^BOLD%^%^BLACK%^adamantium%^RESET%^ disk of a crescent moon overlaps the cloth and shoulder plate. Chain mail and metal plates have been woven together to create a sleeve to protect the left arm.  Plates of %^BLUE%^titanium%^RESET%^ overlay the %^BOLD%^%^BLACK%^adamantium %^RESET%^chain mail under shirt on the outside of either thigh, further protecting the wearer from harm.%^RESET%^");
         return 1;
      default:
         tell_object(ETO,"%^B_MAGENTA%^%^BOLD%^%^MAGENTA%^Oh dear!  Something's wrong with your alignment.  Please find a wiz to have them look at it.%^RESET%^");
         return 0;
   }
}

int remove_func(){
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" removes pulls off the armor, and it transforms back into a mundane suit of half-plate.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^You remove the armor and it transforms back into a mundane looking suit of armor.%^RESET%^");
   set_short("%^RESET%^A suit of half plate armor%^RESET%^");
   set_obvious_short("%^RESET%^A suit of half plate armor%^RESET%^");
   set_long("This suit of half plate armor looks rather mundane and average.  An undershirt of dull chain mail offers protection to the areas that the plate mail fails to cover.  A breastplate made from a dull metal covers the torso.  The metal is shaped to angle to the left side of the body, leaving the right exposed.  A round shoulder plate curves over the left joint of the armor, giving additional protection to the vital organs. A cloth band overlaps the seam of the armor as it angles to the left, helping to support to the weight of the armor evenly. Chain mail and metal plates have been woven together to create a sleeve to protect the left arm.  Plates of metal over lay the chain mail under shirt on the outside of either thigh, further protecting the wearer from harm.");
   return 1;
}