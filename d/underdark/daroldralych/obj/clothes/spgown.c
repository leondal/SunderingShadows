#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^BLACK%^smokey gray","%^RESET%^%^RED%^dark crimson","%^RESET%^%^MAGENTA%^dusky violet","%^RESET%^%^BLUE%^midnight blue","%^BOLD%^%^BLACK%^ebony black","%^BLACK%^%^BOLD%^pale gray","%^RESET%^%^RED%^dusky scarlet","%^RESET%^%^MAGENTA%^rich amethyst","%^RESET%^%^BLUE%^dark cobalt","%^BOLD%^%^BLACK%^jet black","%^BLACK%^%^BOLD%^dark charcoal","%^RESET%^%^RED%^blood red","%^RESET%^%^MAGENTA%^deep purple","%^RESET%^%^BLUE%^deep sapphire","%^BOLD%^%^BLACK%^deep onyx","%^BLACK%^%^BOLD%^shadowy gray","%^RESET%^%^RED%^deep carnelian","%^RESET%^%^MAGENTA%^dark lilac","%^RESET%^%^BLUE%^stormy blue","%^BOLD%^%^BLACK%^raven black"})

#define STYLES ({"tunic","gown","robe","shirt","skirt","pants","vest","cloak"})

void create() {
   int i,k;
   ::create();
   i = random(sizeof(STYLES));
   k = random(sizeof(STYLES));
   set_name("spidersilk "+STYLES[k]+"");
   set_short("%^RESET%^%^CYAN%^a fine "+COLORS[i]+"%^RESET%^%^CYAN%^ "+STYLES[k]+" of spidersilk%^RESET%^");
   set_size(2);
   if(!random(30) && (STYLES[k] != "skirt") && (STYLES[k] != "pants")) {
     while ((int)TO->query_property("enchantment") != 1) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",1);
     }
   }

   switch(STYLES[k]) {
     case "tunic":
     set_id(({"tunic","spidersilk tunic","tunic of spidersilk","fine tunic","randclothx"}));
     set_long("%^BOLD%^%^BLACK%^This gown is soft and sheer, cut snugly to fit against the frame of the wearer.  "
"The sleeves are long, designed to drape down past the hands in a style more for show than any sort of "
"practical use.  The gown itself is low-cut, obviously not created with modesty in mind, and formed of several "
"layers of the cloth known as spidersilk, prized for its durability and light weight.  Most of the spidersilk "
"used is of a %^RESET%^pure jet-black hue%^BOLD%^%^BLACK%^, so dark that it seems to soak in the light around "
"it, although the color is broken in a few places by dark hints of %^RESET%^%^MAGENTA%^violet spidersilk "
"%^BOLD%^%^BLACK%^intermingled with the rest of the material.  It is most definitely a rare and probably "
"expensive masterwork of tailoring.%^RESET%^\n");
     set_weight(8);
     set_value(4000);
     break;

     case "gown":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "robe":
     set_id(({"robe","spidersilk robe","robe of spidersilk","fine robe","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "shirt":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "skirt":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "pants":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "vest":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;

     case "cloak":
     set_id(({"gown","spidersilk gown","gown of spidersilk","fine gown","randclothx"}));
     set_long("\n");
     set_weight(8);
     set_value(4000);
     break;
   }
}
