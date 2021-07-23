#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("burning hands");
	set_id(({ "glove", "red leather glove", "burning hands", "fire glove" }));
	set_short("%^BOLD%^%^RED%^B%^RESET%^u%^BOLD%^r%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^RESET%^%^ORANGE%^ H%^RED%^a%^ORANGE%^n%^RED%^d%^ORANGE%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^fiery red leather glove%^RESET%^");
	set_long("%^BOLD%^%^RED%^Fiery thick red leather is used in the "+
	   "creation of this glove.  The glove is heavily padded across "+
	   "the knuckles and the back of the hand, giving it some solid "+
           "weight.  %^YELLOW%^Brass%^RED%^ spikes are imbedded across the "+
	   "knuckles, adding a deadly touch to these gloves.  A chaotic "+
	   "pattern of flames in various shades of %^RESET%^%^RED%^r%^BOLD%^"+
	   "e%^RESET%^%^RED%^d%^BOLD%^, %^RESET%^%^ORANGE%^orange%^BOLD%^"+
	   "%^RED%^, and %^YELLOW%^yellow%^RED%^ are imbedded into the "+
	   "leather.  While the glove is fingerless, strips of %^YELLOW%^"+
	   "bronze%^RED%^ are imbedded into the leather around each "+
	   "opening, sealing off the leather.%^RESET%^");
   set_value(0);
	set_lore("%^RED%^Manufactured by the Monks of Ibrandul, the "+
	   "Burning Hands glove adds some leather fiery damage to their "+
	   "attacks.  The gloves seem to center around one paticular monk, "+
	   "Oredel the Brash.  There are a couple stories about how Oredel "+
	   "took it upon himself to hunt down followers of Shar after the "+
	   "goddess slew the god Ibrandul.  With his burning fists, Oredel "+
	   "was relentless in slaying any Sharrans he could find.  His life "+
	   "though came to an end when we tried to assassinate an archbishop "+
	   "of the Mistress of the Night's faith in the winter of 513.");
	set_property("lore difficulty",26);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("attack bonus",3);
      set_item_bonus("damage bonus",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
	set_overallStatus(220);
    set_property("no disenchant",1);
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" pulls on the leather glove around "+ETO->QP+" hand.  %^YELLOW%^Golden runes%^RED%^ flare to life across the back of the hand.  An instant later "+ETO->QP+" hand is surrounded with a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^BOLD%^%^RED%^ effigy.",ETO);
	tell_object(ETO,"%^RED%^You pull on the leather gloves tightly around your hand, suddenly %^YELLOW%^golden runes%^RED%^ flare to life on the back of your fist.  A fiery effigy rises from the runes to wrap your hands in %^B_RED%^%^YELLOW%^flames%^RESET%^%^RED%^!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RED%^The flames around "+ETOQCN+"'s hand dissipates, as "+ETO->QS+" pulls the glove off.",ETO);
	tell_object(ETO,"%^RED%^The flames around your hand dissipate, allowing you to remove the glove.");
	return 1;
}
int hit_func(object targ){
      if(!objectp(targ)) return 0;
      if(!objectp(ETO)) return 0;	
      targ = ETO->query_current_attacker();
	if(random(1000) < 250){
          tell_room(EETO,"%^BOLD%^%^RED%^The flames around "+ETO->QCN+"'s hand grow brighter and more intense just before "+ETO->QS+" pummels "+targ->QCN+" with a fiery blow.",({ETO,targ}));
	    tell_object(ETO,"%^BOLD%^%^RED%^The flames grow more intense, flaring in a fiery burst, delivering their burning rage onto "+targ->QCN+".");
	    tell_object(targ,"%^BOLD%^%^RED%^The flames around "+ETO->QCN+"'s hand grows brighter and more intense just before "+ETO->QS+" pummels you with a fiery blow.");
          return roll_dice(2,4)+2;
	}
}