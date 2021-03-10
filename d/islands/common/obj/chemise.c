//designed by Shar.  Circe 4/26/04
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^RESET%^%^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y%^RESET%^",\
"%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^",\
"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^",\
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y",\
 "%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^u%^BOLD%^r%^RESET%^%^CYAN%^q%^BOLD%^u%^RESET%^%^CYAN%^o%^BOLD%^i%^RESET%^%^CYAN%^s%^BOLD%^e%^RESET%^",\
 "%^BOLD%^%^MAGENTA%^pink%^RESET%^",\
"%^RESET%^%^MAGENTA%^violet%^RESET%^"})

void create(){
      int j;
	string str, COLOR;
	::create();
      j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("white chemise ");
	set_id(({ "chemise", "shirt","maiden's chemise","maiden chemise" }));
	set_short("%^BOLD%^%^WHITE%^Maiden's Chemise%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white silk chemise with a "+COLOR+" %^BOLD%^basque%^RESET%^");
	set_long(
         "%^BOLD%^%^WHITE%^Thin white silk of the finest quality is "+
         "used in the creations of this loose fitting shirt.  The "+
         "chemise, a womans shirt, fits loose from the body and has "+
         "long sleeves.  The sleeves are gathered at the cuff, to keep "+
         "the excess fabric in check and out of the way.  Threaded "+
         "through the upper part of the chemise is a ribbon, inside a "+
         "casing.  Typically a chemise is worn off the shoulders, though "+
         "a woman may tighten the ribbon to bring the garment up higher.  "+
         "Over the chemise is a  basque.  A basque is a low cut, tight "+
         "fitting bodice that typically women wore over their chemises.  "+
         "This one is made from suede and features a myriad swirls of "+
         ""+COLOR+"%^BOLD%^%^WHITE%^, "+
         "in every shade and hue imaginable.%^RESET%^\n");
	set_weight(4);
	set_value(678);
	set_lore(
         "The Maiden's Chemise was made for a long forgotten noblewoman "+
         "or princess of some ancient kingdom.  The garment they say was "+
         "her favorite and she was often seen with it.  Though sages "+
         "dismiss such a claim, for how would people know if they cannot "+
         "recall who wore it.  There is a rumor that the chemise was "+
         "among the loot of some grave robbers not to long ago.  The "+
         "mysterious chemise seemes to have had quite a history "+
         "travelling around the lands and showing up in a variety of "+
         "people's hands (and bodies).");
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
    set_item_bonus("charisma",2);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
   if((string)ETO->query_gender() == "female"){
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" slips into the "+
         "chemise and laces up the basque over the garment up",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip into the chemise "+
         "and lace up the basque.");
   return 1;
   }
   tell_object(ETO,"You fumble blindly with the laces.  Why in the "+
      "realms would women wear these things??");
   tell_room(EETO,""+ETOQCN+" looks really silly as "+ETO->QS+" tries "+
      "to wear a woman's garment.",ETO);
   return 0;
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" unlaces "+
         "the basque over her chemise and begins to slip it off over "+
         "her head.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You unlace the basque and "+
         "slip out of the chemise.");
	return 1;
}

void init() {
   ::init();
   // some copies from callista inflated enchant too high (up to +8!)
   // this should resolve existing player items to cap out at +5. N, 01/11
   if((int)TO->query_property("enchantment") > 5) {
     while((int)TO->query_property("enchantment") != 5) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",5);
     }
   }
}
