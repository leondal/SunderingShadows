//coded by Shar.  Replacing white smock along with white bliaut
//Circe 4/26/04
//removed references to old gods and fixed typos ~Circe~ 7/30/19
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("golden jerkin");
   set_id(({ "jerkin", "golden jerkin" }));
   set_short("%^ORANGE%^G%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n Jerkin%^RESET%^");
   set_obvious_short("%^YELLOW%^A golden jerkin%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This snug fitting sleeveless jerkin is made of the finest grade of cashmere wool.  The soft cashmere has been dyed a rich antique gold color, giving the fabric added depth and warmth.  A set of %^YELLOW%^gold%^RESET%^%^ORANGE%^ engraved buttons, in the images of a ram's head, run down the front of the jerkin.  The inside of the jerkin is lined with a %^YELLOW%^golden fleece%^RESET%^%^ORANGE%^, which spills out of the arms in a wild chaotic fashion, looking quite handsome.  The jerkin seems to be treated with magic to protect it from dirt and filth, never seeming to stain.%^RESET%^");
   set_weight(4);
   set_value(2000);
   set_lore("The Golden Jerkin was an artifact of a minor noble house of Asgard, the Ithetheskans.   The Ithetheskans were a noble house that traded in fabric, cloth, and odd magical artifacts.  The golden ram was a symbol of the house.  Rumors speak that the succesful noble house was blessed by the Lady of Light with a ram whose fleece was made of pure gold.  The house of Ithestheskans fell into decline after the heir to their empire, Utheran, was kidnapped for ransom and never recovered.");
   set_type("clothing");
   set_limbs(({ "torso" }));
   set_size(2);
   set_property("enchantment",2);
   set_item_bonus("damage bonus",2);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

int wear_func(){
   if((string)ETO->query_gender() == "male"){
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" slides into a jerkin that molds itself to his body, accentuating every muscle of his torso.",ETO);
      tell_object(ETO,"%^ORANGE%^You slide yourself into the handsome jerkin, feeling the soft warmth of the golden fleece and cashmere against your skin.");
      return 1;
   }
   tell_object(ETO,"Try as you might, you just can't seem to fit the cashmere jerkin to your form.");
   return 0;
}

int remove_func(){
	tell_room(EETO,"%^ORANGE%^"+ETOQCN+" slides off the golden jerkin and lets out a slight sigh.",ETO);
	tell_object(ETO,"%^ORANGE%^You remove the snug fitting jerkin, feeling the strength of the ram slip from your body.");
	return 1;
}
