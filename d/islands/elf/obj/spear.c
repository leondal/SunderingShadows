//coded 1/7/13 thanks to zathery for help with descs
#include <std.h>
#include "../elf.h"

inherit "/d/common/obj/weapon/mspear.c";

void create(){
    ::create();
    set_name("%^RESET%^%^ORANGE%^In%^MAGENTA%^n%^ORANGE%^ithali's l%^MAGENTA%^a%^ORANGE%^nce%^RESET%^");
    set_id( ({"spear", "driftwood spear", "innithali's lance"}) );
    set_obvious_short("%^RESET%^%^ORANGE%^Driftwood Spear%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^In%^MAGENTA%^n%^ORANGE%^ithali's l%^MAGENTA%^a%^ORANGE%^nce%^RESET%^");
    set_long("%^ORANGE%^Carved from a single piece of once majestic"+
	" birch, this spear has aged in %^CYAN%^seawater%^ORANGE%^, the pale "+
	"wood curving and buckling as salt water drained all"+
	" its moisture but left a weapon harder than %^CYAN%^steel%^ORANGE%^."+
	" The leather that once wrapped its handle has "+
	"vanished, but the wood seems to have aged around "+
	"its once legendary owner's grip, offering a perfect "+
	"grip against the wood. %^CYAN%^Faded runes%^ORANGE%^ decorate the "+
	"spear along its four foot length before reaching"+
	" its tip, a sharpened sapphire gem that glints as if untouched by age.  %^RESET%^");
    
        
    set_lore("The favored and legendary weapon of Innithali."+
		" Called an Elven pirate this captain of a swift elven"+
		" warship coasted the shores and sea near her homelands."+
		" Her rumors of piracy spread by Humans and others whom"+
		" intruded on the Elven waters and were swiftly "+
		"dispatched. Her ultimate fate is unknown  beyond "+
		"that she one day set out with her crew on stormy "+
		"waters, her skill too great to be lost to a storm. "+
		"This spear would have made a fine trophy, and was "+
		"never seen again, leading to rumors she simply sailed off into open waters.");
        set_property("lore",30);
        set_value(10000);
        set_hit((:TO,"hitme":));
        set_property("enchantment",4);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 20) {
      tell_object(ETO,"%^ORANGE%^You can't seem to figure out this weapon.");
        return 0;
}
        tell_object(ETO,"%^ORANGE%^Your fingers fit into the molded form "+
		"of the wooden handle as the runes along the spear's "+
		"shaft light up and blaze with Golden light.");
		tell_room(EETO,"%^ORANGE%^Taking the spear in hand, "+ETO->QCN+
		" becomes illuminated in the golden light the runes emit along its shaft.",ETO);
        return 1;
}
int unwield_func(string str) {
        tell_object(ETO,"%^ORANGE%^With a heavy sigh you release your grip "+
		"on the spear, its runes fading, barely noticeable.");
		tell_room(EETO,"%^ORANGE%^As "+ETO->QCN+" releases "+ETO->QP+" grip on the spear, its runes fade.",ETO);
        return 1;
}

int hitme(object targ)
{ 
 
   if(!random(16)) {
      tell_object(ETO,"%^ORANGE%^Using the curve of the spear you slam it into "+targ->QCN+
	  "'s side, spinning "+targ->QP+" around and using that momentum to "+
	  "slam the handle of the spear into "+targ->QP+" back.");
      tell_object(targ,"%^ORANGE%^"+ETO->QCN+"'s"+
                " spear slams into your side and spins you around, "+
				"allowing a follow through attack.");
      tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"'s spear slams into "+targ->QCN+
	  "'s side and spins "+targ->QO+" around, allowing a follow through attack.",({ETO,targ}));             
      ETO->execute_attack();
        return random(8)+5;
   }
   else if(!random(50)) {

     tell_object(ETO,"%^ORANGE%^As you jab the spear into "+targ->QCN+" the "+
	 "runes light up, blazing into your foe's eyes."); 
	 tell_object(targ,"%^ORANGE%^As "+ETO->QCN+" jabs the spear into you,"+
	 " the runes along it flare up, blanketing your vision in"+
	 " golden light and blinding you.");
     tell_room(EETO,"%^ORANGE%^As"+ETO->QCN+""+
          " jabs the spear into "+targ->QCN+" the runes flare up brightly.",({ETO,targ}));
     targ->set_blind(1);                   
        return 1;
   }
   return 1;
}
