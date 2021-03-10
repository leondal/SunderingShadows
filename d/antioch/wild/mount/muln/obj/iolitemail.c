#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
    ::create();
    set_name("chainmail");
    set_id(({"chainmail","chain mail", "mail", "chain", "chainshirt","hide","crystal breastplate","crystals","crystal","crystal hide","crystal chainmail"}));
    set_short("%^BOLD%^%^CYAN%^I%^BOLD%^%^BLUE%^ol%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^te %^BLUE%^Chainmail%^RESET%^");
    set_obvious_short("%^RESET%^%^BLUE%^Cr%^BOLD%^%^CYAN%^y%^RESET%^%^BLUE%^s%^BOLD%^%^CYAN%^t%^RESET%^%^BLUE%^al Ch%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^inm%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^il%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This suit of armor is rather odd, but a remarkable feat of craftsmanship."+
	  " Instead of typical metal links being forged together this suit has somehow been shaped from "+
	  "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^et%^WHITE%^ crystals with tinges of %^BOLD%^%^CYAN%^sky blue%^WHITE%^"+
	  " streaking through each crystal. The crystals sh%^MAGENTA%^i%^WHITE%^ft in color depending on your angle of view. One view of the" 
	  " crystals are a %^RESET%^%^MAGENTA%^violet-blue%^BOLD%^%^WHITE%^, while from another perspective they are as translucent as "
	  "%^RESET%^%^CYAN%^water%^BOLD%^%^WHITE%^. An aerial view of each crystal gives them a %^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^o"
	  "%^RESET%^%^ORANGE%^ney-yellow %^BOLD%^%^WHITE%^gl%^BOLD%^%^ORANGE%^o%^BOLD%^%^WHITE%^w in appearance.");
    set_lore("%^BOLD%^%^BLUE%^Archdruid Sandenvanos stumbled upon these Iolite crystals entirely by circumstance as she wandered around a %^BOLD%^%^WHITE%^winter%^BLUE%^"+
             " isle. She came to realize that they were the prized possession of %^CYAN%^Muln - %^WHITE%^an ancient white dragon%^BOLD%^%^BLUE%^. The only reason"+
             " Muln allowed her to leave was Sandenvanos's connection to %^BOLD%^%^BLUE%^A%^CYAN%^u%^BLUE%^r%^CYAN%^i%^BLUE%^l. Legends speaks of Sandenvanos"+
             " ability to withstand %^BOLD%^%^BLACK%^death magic%^BLUE%^, however she couldn't withstand %^CYAN%^Muln%^BLUE%^ when she came to collect her"+
             " gems after their prearranged bargain had expired. The druid had merged the crystals into a %^BOLD%^%^CYAN%^crystalline chainmail%^BLUE%^,"+
             " preventing anyone else, including the dragon from using the gems in a different capacity. %^RESET%^%^CYAN%^From a passage of"+
             " history about Dragon Treasure by %^MAGENTA%^Kellan Te'Mil Vespar");
    set_value(2000);
    set_size(2);
    set_property("enchantment",4);
    set_item_bonus("magic resistance",2);
    set_item_bonus("damage resistance",4);
    set_property("lore diffculty",40);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}


int wear_func(){
      tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^cr%^CYAN%^y%^BLUE%^sta%^CYAN%^l%^BLUE%^s%^WHITE%^ glow an intense"+
                      " %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^t%^WHITE%^.%^RESET%^  ");
      tell_room(EETO, "The Crystals composing " +ETOQCN + "'s suit %^BOLD%^%^YELLOW%^glow%^RESET%^ as "+ETO->QS+ " dons the armor.",ETO);
	  ETO->add_temporary_feat("death ward"); 
	  return 1;}

int remove_func(){
    tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^cr%^CYAN%^y%^BLUE%^sta%^CYAN%^l%^BLUE%^s%^WHITE%^ %^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^des as you remove the chainmail.%^RESET%^");
    tell_room(EETO, ETOQCN + "'s chainmail dims as "+ETO->QS+ " removes it.", ETO);
    ETO->remove_temporary_feat("death ward"); 
	return 1;}
	
    
int is_metal() { return 0; } //not metal


