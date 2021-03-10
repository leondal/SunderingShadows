//ghostsandals.c - for Lothwaite, Circe 4/24/04
//Added weight and a check for level to get the 
//stat increases based on talks with Styx - 6/06 Cythera
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_id(({"sandals","shoes","golden sandals","sandals of rejuvenation","rejuvenation sandals"}));
   set_name("golden sandals");
   set_short("%^YELLOW%^Sandals of Rejuvenation%^RESET%^");
   set_obvious_short("%^YELLOW%^A pair of golden sandals%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^These sandals are simply made, consisting "+
      "of a leather sole fitted with a narrow leather upper that just "+
      "covers the wearer's toes.  To save the sandals from being plain, "+
      "%^YELLOW%^"+
      "plaited gold %^RESET%^%^ORANGE%^has been affixed to the leather, "+
      "giving them an elegant appearance.  Small %^YELLOW%^topaz"+
      "%^RESET%^%^ORANGE%^, %^BOLD%^%^RED%^ruby%^RESET%^%^ORANGE%^, "+
      "%^BOLD%^%^BLUE%^sapphire%^RESET%^%^ORANGE%^, and %^BOLD%^"+
      "%^GREEN%^emerald %^RESET%^"+
      "%^ORANGE%^chips are scattered among the strands of gold, adding "+
      "a touch of color.  Rising from the backs of the sandals are "+
      "long, narrow leather thongs that may be crisscrossed up the "+
      "wearer's calves and tied at the knees.%^RESET%^"
   );
   set_lore("The Sandals of Rejuvenation are a remnant of the "+
      "might of the great Shaman Helgatha Rothmar of the village "+
      "of Lothwaite in the Barrier Mountains.  The sandals were "+
      "made originally as a gift for the king's daughter, "+
      "Celawyn on her fifteenth birthday.  Later, lesser pairs "+
      "were made, but it is said that the original had the power "+
      "to heal all wounds, keeping the princess young and vibrant "+
      "all her days.");
   set_property("lore difficulty",11);
   set_value(750);
   set_type("clothing");
   set_property("enchantment",2);
   set_ac(0);
   set_weight(2);
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"strikeme":));
}

int wearme(){
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if((string)ETO->query_gender() == "male"){
      tell_object(ETO,"%^ORANGE%^You fumble with the leather "+
         "thongs and cannot get them on.  How the hell do "+
         "women wear these things?");
      tell_room(EETO,"%^ORANGE%^You can't help but laugh as "+
         ""+ETOQCN+" fumbles with the thongs of the sandals.",ETO);
      return 0;
   }
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"%^YELLOW%^The golden sandals are too fine "+
         "for your feet!");
      return 0;
   }
   tell_object(ETO,"%^YELLOW%^You tie the leather thongs up your "+
      "calves and feel dainty and beautiful.");
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" ties the leather thongs "+
      "up her calves, enhancing the beauty of her legs.",ETO);
   if((int)ETO->query_lowest_level() > 24) set_item_bonus("charisma",1);
   else set_item_bonus("charisma",0);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^ORANGE%^You untie the sandals and immediately "+
      "miss the way they make your feet look.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" unties her sandals with a "+
      "pouty look on her face.",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+
           ""+ETOQCN+" looks refreshed as a strange mist swirls "+
           "around her.",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^A fine mist rises from the "+
           "sandals, leaving you feeling refreshed.");
        ETO->do_damage("torso",-1*random(10)+5);
//return damage;  }
return 0;  }
}
