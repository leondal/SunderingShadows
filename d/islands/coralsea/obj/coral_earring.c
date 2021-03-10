#include <std.h>
#include "../defs.h"
inherit ARMOUR;

// Coral Sea Area - Created January 2009 by Ari

int CHARGES;

void init(){
    ::init();
	set_size(TP->query_size());
    add_action("use_magic","understand");
}

void create() {
    ::create();
		CHARGES = roll_dice(2,2);
		set_name("copper earring");
		set_id(({"copper earring","earring","earring of copper",
			"cscopperriin"}));
		set_short("%^RESET%^%^ORANGE%^c%^YELLOW%^o%^BLACK%^p%^RESET%^"+
			"%^ORANGE%^p%^GREEN%^e%^ORANGE%^r e%^BOLD%^%^BLACK%^a"+
			"%^RESET%^%^GREEN%^r%^ORANGE%^ri%^YELLOW%^n%^RESET%^"+
			"%^ORANGE%^g%^RESET%^");
		set_long("%^RESET%^%^ORANGE%^This simple band looks almost "+
			"like a cast off piece of metal that has been exposed "+
			"to the elements for too long.  Its c%^YELLOW%^o%^BLACK%^"+
			"p%^RESET%^%^ORANGE%^p%^GREEN%^e%^ORANGE%^r surface is "+
			"tarnished and aged with flecks of oxidization clear in "+
			"the green and black splotches. Still visible though are "+
			"a few words that were once neatly impressed into the "+
			"surface.  Worn on the ear, by pinching the ring closed "+
			"over the earlobe, the ring has a small slit that can be "+
			"adjusted to allow it to fit the wearer.%^RESET%^");
		set("language","common");
		set_read("\n%^YELLOW%^Fair are the words they speak,\n"+
			"to %^GREEN%^understand%^YELLOW%^ them, use me.%^RESET%^");
		set_value(300);
		set_lore("Little more then a trinket, these earrings were a "+
			"popular device that many sailors wore when traveling "+
			"to distant ports to ensure that they could understand "+
			"the people at their various ports of call.  Enchanted "+
			"with a popular language translating spell, the right "+
			"command had to be but given and the spells within "+
			"would be invoked.  Unfortunately such items were rarely "+
			"designed for longevity and often gave out after a few "+
			"uses, thus insuring the sailor returned to the crafter "+
			"again and again.");
		set_property("lore difficulty",5);
                set_type("clothing");
		set_limbs(({"head"}));
		set_size(2);
}

int use_magic(string str){
	object ob;
	
	if(!str){ 
		return notify_fail("Who or what did you want to use the "+
			"trinket's power on?"); 
	}
	
	if(!TO->query_worn()){
        tell_object(TP,"%^YELLOW%^It probably wont work till you "+
			"are wearing the earring.%^RESET%^");
    return 1;
    }
	
	if(!CHARGES){
		tell_object(TP,"%^YELLOW%^The earring glows faintly "+
			"then just as quickly grows dark and crumbles into "+
			"dust.%^RESET%^");
		TP->force_me("remove cscopperriin");
		TO->remove();
		return 1;
	}
	
	tell_room(ETO,"%^YELLOW%^"+TP->QCN+" runs their "+
		"finger over the earring's smooth surface.%^RESET%^");
	new("cmds/spells/t/_tongues.c")->use_spell(TP,str,20,100,"mage");
	CHARGES--;
	return 1;	
}
