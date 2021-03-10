//ghostboots.c - for Lothwaite, Circe 4/24/04
//Added weight and changed the stat bonus 
//based on talk with styx - cythera 6/06
#include <std.h>
inherit ARMOUR;
int FLAG;

void create() {
   ::create();
   set_id(({"shoes","leather shoes","shoes of vigor","vigor shoes"}));
   set_name("leather shoes");
   set_short("%^RESET%^%^ORANGE%^Shoes of Vigor%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A pair of leather shoes%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^These dark brown leather shoes are "+
      "made with a thick leather sole boiled and hardened to "+
      "protect the wearer's feet.  The upper portion of the shoe "+
      "has been left open and consists of several curved flaps of "+
      "soft suede, three on each side.  Each of the flaps has a "+
      "small hole through which a leather thong runs.  The shoes "+
      "reach just above the wearer's ankles, and the two ends of the "+
      "thong may be gathered and tied to secure the shoes.%^RESET%^"
   );
   set_lore("The Shoes of Vigor are a remnant of the "+
      "might of the great Shaman Helgatha Rothmar of the village "+
      "of Lothwaite in the Barrier Mountains.  These shoes, styled "+
      "as peasant shoes, were actually made for a great warrior "+
      "skilled in tracking.  The shoes were said to leave no tracks, "+
      "although this seems to be merely legend.  There is no doubt, "+
      "however, that the shoes grant stamina to those who wear them.");
   set_property("lore difficulty",11);
   set_value(750);
   set_type("clothing");
   set_property("enchantment",2);
   set_ac(0);
   set_weight(3);
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"strikeme":));
 FLAG=0;
}

int wearme(){
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if((string)ETO->query_gender() == "female"){
      tell_object(ETO,"%^ORANGE%^You try to put on the shoes and "+
         "realize there is no way they will stay on your little feet!");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" looks like a jester as "+
         "she tries to wear shoes that are way too big for her.",ETO);
      return 0;
   }
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"%^ORANGE%^The shoes are too robust "+
         "for your feet!");
      return 0;
   }
   tell_object(ETO,"%^ORANGE%^You feel an age-old strength spread "+
      "through your body as you tie the shoes.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" looks a little more rugged "+
      "as he ties the shoes.",ETO);
   if((int)ETO->query_lowest_level() > 24) set_item_bonus("constitution",1);
   else set_item_bonus("constitution",0);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^ORANGE%^You untie the shoes and feel a little "+
      "tired all of a sudden.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" looks a little pale and weak "+
      "as he unties the shoes.",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^CYAN%^"+
           ""+ETOQCN+" suddenly looks more energetic.",ETO);
        tell_object(ETO,"%^CYAN%^You feel a strange burst of energy "+
           "that seems to be coming from your shoes!");
        ETO->do_damage("torso",-1*random(10)+5);
//return damage;  }
return 0;  }
}
