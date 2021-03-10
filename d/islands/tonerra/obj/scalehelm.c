//scalehelm.c - random drop from the gargantua
//coded by Circe 6/13/04
#include <std.h>
inherit "/d/common/obj/armour/helm";

void create() {
    ::create();
    set_name("gargantua helm");
    set_id(({"helm","helmet","gargantua helm","scale helmet","scale helm"}));
    set_obvious_short("a rocky scale helmet");
    set_short("%^BOLD%^%^BLACK%^Ga%^RESET%^r%^BOLD%^%^BLACK%^gan%^RESET%^tu%^BOLD%^"+
       "%^BLACK%^a helm%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This helm is shaped just like the "+
       "head of a reptilian gargantua.  It is made of rocky scales "+
       "that seem to shift in color from ebony through %^RESET%^"+
       "%^GREEN%^mo%^BOLD%^%^BLACK%^tt%^RESET%^%^GREEN%^led green "+
       "%^BOLD%^%^BLACK%^with small flakes of %^WHITE%^pure white "+
       "%^BLACK%^as well.  The mouth of the helm is opened wide, "+
       "allowing the wearer to peer through the rows of %^RESET%^"+
       "steel 'teeth' %^BOLD%^%^BLACK%^fitted into the jaws.%^RESET%^");
    set_value(250);
    set_property("enchantment",3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"unwearme":));
}

int wearme(){
   tell_object(ETO,"%^GREEN%^You cannot help but roar as you put "+
      "on the helm.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" roars ferociously as "+ETO->QS+" "+
      "puts on the helm.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^GREEN%^You feel the strength of the beast "+
      "leave you as you take off the helm.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" looks more like "+ETO->QO+"self "+
      "as "+ETO->QS+" takes off the helm.",ETO);
   return 1;
}

int is_metal() { return 0; }