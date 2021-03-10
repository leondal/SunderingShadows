#include <std.h>
inherit "/std/armour";

int x;

void create()
{
   ::create();
   set_name("spider necklace");
   set_short("An amber necklace");
   set_id(({"necklace","amber necklace","spider necklace"}));
   set_long("The necklace has a %^BOLD%^silver chain%^RESET%^ from"+
   " which hangs a large, polished piece of %^ORANGE%^amber%^RESET%^."+
   " Encased in the center of the %^ORANGE%^amber%^RESET%^ is a spider"+
   " that has been trapped for eternity. It is a %^BOLD%^%^BLACK%^black"+
   " widow%^RESET%^, you can tell by the %^RED%^red hourglass%^RESET%^"+
   " on its back. Its eight legs are outstretched and it is pointed"+
   " upwards.");
   set_weight(5);
   set_property("enchantment",3);
   x = query_property("enchantment");
   set_type("clothing");
   set_limbs(({"neck"}));
   set_value(1500);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme()
{
   if(ALIGN->is_good(TP)) {
      tell_object(TP,"The necklace feels oddly cold to you and it sends"+
      " uncomfortable shivers down your spine.");
      tell_room(ETP,""+TPQCN+" shivers as "+TP->query_subjective()+""+
      " puts the amber necklace on.",TP);
      while(query_property("enchantment") != x-2) {
         remove_property("enchantment");
         set_property("enchantment",x-2);
      }
      return 1;
   }
   if(ALIGN->is_evil(TP)) {
      tell_object(TP,"%^ORANGE%^There is a soothing aura about the amber"+
      " necklace and you believe it will protect you well.");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" smiles slightly as "+TP->query_subjective()+""+
      " slips on the amber necklace.",TP);
      return 1;
   }
   return 1;
}

int removeme()
{
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"%^BOLD%^You remove the spider necklace and"+
      " feel more at ease.");
      return 1;
   }
   if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"%^ORANGE%^You remove the necklace and feel"+
      " much more vulnerable.");
      return 1;
   }
   return 1;
}

void init()
{
   ::init();
   if(query_worn()) return;
   while(query_property("enchantment") != x) {
      remove_property("enchantment");
      set_property("enchantment",x);
   }
}
