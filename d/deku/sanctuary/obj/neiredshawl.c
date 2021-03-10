//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit ARMOUR;
#define MAXUSES 15

int uses;

void create(){
	::create();
	set_name("nereid shawl");
	set_id(({ "shawl", "nereid shawl","water shawl" }));
	set_short("%^BOLD%^%^WHITE%^The %^CYAN%^N%^BLUE%^e"+
		"%^RESET%^%^CYAN%^r%^BLUE%^e%^BOLD%^i%^CYAN%^d"+
		"%^RESET%^%^BLUE%^'%^CYAN%^s%^BOLD%^ %^WHITE%^"+
		"Shawl%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A watery shawl%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This white shawl is made of a colorless material that seems almost white. As you touch the shawl, a wave of ripples dots the surface, as if it was made of water? The shawl is sheer, with the ends fringed with five long strands of the fluid material. Looking through the scarf tends to distort images on the other side. It is cool and clammy to the touch.

AVATAR
	);
      
	set_language("common");
	set_weight(2);
	set_value(400);
	set_lore(
@AVATAR
The Nereid Shawl comes from a Nereid, a water nymph. The water nymphs are helpless to those that hold control of their shawls, that is why they will do anything in their power to get it back. If the shawl is destroyed, then so is the nereid, but oddly enough the reverse does not seem to hold true.

AVATAR
	);
	set_property("lore",13);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
        set_ac(0);
        set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" slips on a white shawl over "+ETO->query_possessive()+" head and about "+ETO->query_possessive()+" shoulders, looking refreshed.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You drape the shawl over your head and about your shoulders, and feel the urge to %^BOLD%^%^CYAN%^breathe%^BOLD%^%^WHITE%^.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" slips off the shawl from around "+ETO->query_possessive()+" head and shoulder.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip off the cool shawl.");
	return 1;
}

void init() {
   ::init();
   add_action("breathe","breathe");
}

int breathe() {
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You have to wear the shawl first.");
   if(uses < MAXUSES) {
      tell_room(ETP, "%^BOLD%^%^CYAN%^"+TPQCN+" starts to breathe deeply.",TP);
      new("/cmds/spells/w/_water_breathing")->use_spell(TP,TP,15,100,"mage");
      uses +=1;
      return 1;
      }
   else{
      set_value(0);
      tell_object(TP, "The shawl is out of charges.");
   }
   return 1;
}
