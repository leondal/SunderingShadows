//coded by Shar.  Replacing white smock along with white bliaut
//Circe 4/26/04
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;
int mybonus;
void create(){
	::create();
	set_name("golden jerkin");
	set_id(({ "jerkin", "golden jerkin" }));
	set_short("%^ORANGE%^G%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d"+
         "%^RESET%^%^ORANGE%^e%^YELLOW%^n Jerkin%^RESET%^");
	set_obvious_short("%^YELLOW%^A golden jerkin%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This snug fitting sleeveless jerkin is made of the finest grade of cashmere wool.  The soft cashmere has been dyed a rich antique gold color, giving the fabric added depth and warmth.  A set of %^YELLOW%^gold%^RESET%^%^ORANGE%^ engraved buttons, in the images of a ram's head, run down the front of the jerkin.  The inside of the jerkin is lined with a %^YELLOW%^golden fleece%^RESET%^%^ORANGE%^, which spills out of the arms in a wild chaotic fashion, looking quite handsome.  The jerkin seems to be treated with magic to protect it from dirt and filth, never seeming to stain.

AVATAR
	);
	set_weight(4);
	set_value(2000);
	set_lore(
@AVATAR
The Golden Jerkin was an artifact of a minor noble house of Asgard, the Ithetheskan's.   The Ithetheskan's were a noble house that traded in fabric, cloth, as well as odd magical artifacts.  The golden ram was a symbol of the house.  Rumors speak that the succesful noble house was blessed by the Morninglord with a ram who's fleece was made of pure gold.  The fate of the Ithestheskan's house though feel into decline after the heir to their empire, Utheran, was kidnapped for ransom and never recovered.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set("chabonus",1);
}
int wear_func(){
    mybonus = (random(3));
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"This jerkin is too fine for you!");
      return 0;
   }
   if((string)ETO->query_gender() == "male"){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slides into a jerkin that molds itself to his body, accentuating every muscle of his torso.",ETO);
	tell_object(ETO,"%^ORANGE%^You slide yourself into the handsome jerkin, feeling the soft warmth of the golden fleece and cashmere against your skin.");
	ETO->add_attack_bonus(mybonus);
	return 1;
   }
   tell_object(ETO,"Try as you might, you just can't seem to fit "+
      "the cashmere jerkin to your form.");
   return 0;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slides off the golden jerkin and lets out a slight sigh.",ETO);
	tell_object(ETO,"%^ORANGE%^You remove the snug fitting jerkin, feeling the strength of the ram slip from your body.");
	ETO->add_attack_bonus(-1 * mybonus);
	return 1;
}
