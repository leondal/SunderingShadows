// to give to gnome
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("mithril cog");

   set_id(({"cog","mithral cog"}));
   set_short("%^CYAN%^large cog%^RESET%^");
   set_long("%^CYAN%^This is a rather large cog"+
   " it is likely used in some kind of machine."+
   "  There is a big hole in the middle large enough "+
   "to fit one's arm through.%^RESET%^");
      
   set_weight(2);
   set_value(1700);
   set_type("ring");
   set_limbs(({"right arm"}));
   set_size(2);
   set_property("enchantment",0);
}
