//Octothorpe (12/4/08)
//Underdark Mining Caverns, Gnomish Mage Robes

#include <std.h>
inherit PARMOUR;

void create(){
   ::create();
   set_name("robe of the stone wardens");
   set_id(({"robe","robe of stone wardens","wardens","robe of stone"}));
   set_short("%^BOLD%^%^WHITE%^R%^RESET%^o%^BOLD%^b%^RESET%^e %^BOLD%^"+
      "of the St%^RESET%^o%^BOLD%^n%^RESET%^e %^BOLD%^W%^RESET%^a"+
      "%^BOLD%^rd%^RESET%^e%^BOLD%^ns%^RESET%^");
   set_obvious_short("%^RESET%^sl%^BOLD%^at%^RESET%^e-gray robe");
   set_long("%^RESET%^The texture of this robe feels remarkably similar "+
      "to actual %^BOLD%^limestone %^RESET%^in the Underdark. The actual "+
      "material that this robe is made of is hard to discern, yet it "+
      "most likely is made out of magically-imbued cloth. Upon touching "+
      "the robe, a small amount of ca%^BOLD%^lc%^RESET%^ite dust falls "+
      "off of the robe, but does not mar the appearance of the cloth at "+
      "all. Two deep pockets are found in the lining of the robe to "+
      "hold a spellbook and components bag.");
   set_lore("Robes such as these are common among the illusionist members "+
      "of the Stone Wardens. The Stone Wardens are a religious military "+
      "order within the faith of Callarduran Smoothhands tasked with "+
      "defending holy sites. Rumors abound regarding the unusual "+
      "physical properties of the material. One of the most "+
      "long-lived rumors states that the robes are prepared "+
      "during a special ritual where a simple cloth robe phases "+
      "into solid limestone. At the end of the ritual, the priest "+
      "elevates the robe out of the earth through the use of divine "+
      "magic.\n");
   set_property("lore",19);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(5);
   set_size(1);
   set_value(1950+random(1000));
   set_property("enchantment",3);
   set_max_internal_encumbrance(21);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"strike_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 15){
      tell_room(EETO,"The fabric of the robe becomes completely "+
         "unmovable as "+ETOQCN+" tries to don it.",ETO);
      tell_object(ETO,"As you try to put on the robe, the ca%^BOLD%^"+
         "lc%^RESET%^ite within the fabric hardens in the midst of "+
         "your efforts, causing the garment to retain an unwearable, "+
         "rigid form.");
      return 1;
   }
   tell_room(EETO,"%^BOLD%^Some %^RESET%^ca%^BOLD%^lc%^RESET%^ite "+
      "%^BOLD%^dust falls to "+ETOQCN+"'s feet as they put on the "+
      "mage robes.",ETO);
   tell_object(ETO,"%^BOLD%^Some %^RESET%^ca%^BOLD%^lc%^RESET%^ite "+
      "%^BOLD%^dust falls to your feet as you put on the robe.%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" seems more vulnerable as they "+
      "remove their mage robes.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^You miss the strength of stone around you "+
      "as you remove the robe.%^RESET%^");
   return 1;
}

int strike_fun(){
   if(ETO->query_stoneSkinned()) return 0;
   if(!random(5)){
      new("/cmds/spells/s/_stoneskin.c")->use_spell(ETO,ETO,12,100,"mage");
      tell_object(ETO,"%^BOLD%^The robe reacts to the hit, causing "+
         "it to harden into stone itself!%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s robe reacts to the attack "+
         "and magically hardens itself into stone!%^RESET%^",ETO);
      return 1;
   }
}
