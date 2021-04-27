#include <std.h>
inherit "/d/common/obj/armour/hide.c";

void create(){
   ::create();
   set_name("voadkyn's pride");
   set_short("%^RESET%^%^GREEN%^Pride of the %^ORANGE%^Voadkyn%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^A steel mesh shirt%^RESET%^");
   set_id(({"chain","chainmail","chain mail","mail","mesh shirt","steel shirt","voadkyn chain"}));
   set_long(
@OLI
   %^GREEN%^This is the a special suit of chain mail. It is made from steel
very similiar to that of elven steel, light and strong. It is cut
exactly to match the contours of the voadkyn body, slim like an elf,
but longer and taller. The tight links of the chain mesh to cover
almost everything. Even a rapier would have a difficult time weaving
through the links.%^RESET%^
OLI
   );
   set_value(1400);
   set_size(3);
   set_property("enchantment",2);
   set_wear((:TO,"wearme":));
   set_struck((:TO,"strikeme":));
}

int wearme(){
   write("%^GREEN%^The armour fits you well.");
   tell_room(ETP,"%^GREEN%^You hear the click of the chains as the conform to the contours of "+ETO->QCN+"'s body.",TP);
   return 1;
}

int strikeme(int damage, object what, object who){
   if(!random(1)){
      if(objectp(what)){

	 tell_object(ETO,"The chainmail clinks as its struck by the "+what->query_name()+".");
      } else {

	 tell_object(ETO,"The chainmail clinks as its struck by "+who->query_cap_name()+".");
      }
      tell_object(who,"The chainmail worn by "+ETO->query_cap_name()+" clinks as you strike it.");
      tell_room(environment(query_worn()),"The chainmail clinks as it obsorbs the blow from "+who->query_cap_name()+".",({who,ETO}));
      return damage/2;
   }
   return damage;
}
