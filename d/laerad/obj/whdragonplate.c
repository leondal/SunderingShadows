#include <std.h>
inherit "/d/common/obj/armour/fullplate";

int OWNED;
string owned;

void create(){
	::create();
    	set_name("white dragon plate");
     	set_id(({ "white dragon plate", "plate","dragon plate","+
		""armor","armour"}));
      set_short("%^BOLD%^%^WHITE%^White Dragon Plate%^RESET%^");
     	set_long( "%^BOLD%^%^WHITE%^Crafted from the hide and "+
		"scales of a White Dragon, this plate has an "+
		"impressive look to it.  The breastplate of this"+
		" armor is created by attaching overlapping scales"+
		" over a steel shell.  Underneath the breastplate,"+
		" a suit of molded white dragon leather lays.  This"+
		" leather suit offers additional protection to the "+
		"wearer as well as some comfort from the metal, and"+
		" to cushion blows.  The impressive breastplate has"+
		" one large single %^BOLD%^%^CYAN%^i%^BLUE%^c%^CYAN%^y"+
		" blue%^WHITE%^ eye of a dragon magically attached to "+
		"the left breast.  This unblinking dragon's eyes has "+
		"been perfectly preserved, never to rot or spoil. A "+
		"skirt of pleated scaled dragon hide falls from "+
		"underneath the breastplate, offering protection to "+
		"the legs of the wearer.  The skirt is split open in "+
		"the front, for ease in riding.  A second section of "+
		"scaled white dragon hide lays under the split of the "+
		"skirt, serving as a protective shield for vital areas."+
		"  A layer of %^CYAN%^frost%^WHITE%^ cakes the armor, "+
		"giving it a chilling apperance.%^RESET%^\n");
     	set_value(13500);
	set_property("enchantment",3);
     	set_lore( "The White Dragon Plate was fashioned from Wynter,"+
		" the eldest son of Muln.  Wynter was slain by a "+
		"traveling dragonslayer, who some claim has ties to"
		" Azha.  The dragonslayer took his prize from Wynter"+
		" and had this armor fashioned out the dragon's scales"+
		". - A Cold Wynter's Tale - Freesia Greenmore");
     	set_property("lore difficulty",14);
	set_size(-1);
      set_wear((:TO,"wearit":));
      set_remove((:TO,"remove_func":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == ETO && !OWNED) {
                owned = TPQN;
                OWNED = 1;
        }
}

int wearit() {
	{
	if((int)ETO->query_highest_level() < 17) {
   		notify_fail("%^BLUE%^%^BOLD%^The plate mail armor "+
			"rejects someone as weak as you!");
				set_property("magic",1);
      			ETO->do_damage("torso",random(5)+20);
      			ETO->add_attacker(TO);
      			ETO->continue_attack();
      			ETO->remove_attacker(TO);
      			remove_property("magic");
	return 0;
	}
   	if((string)ETO->query_diety() == "kreysneothosies") {
      	tell_object(ETO,"%^BOLD%^You feel strange"+
			" and uncomfortable in this armor.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
			"looks uncomfortable after strapping on the"+
			" armor.",ETO);
				set_item_bonus("armor bonus",-1);
      return 1;
   	}
   	if((string)ETO->query_diety() == "lord shadow") {
      	tell_object(ETO,"%^BOLD%^You strap on the White"+
			" Dragon Plate and feel protection of "+
			"winter fall on you.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
			" swells with pride as "+ETO->QS+" strap on the "+
			"White Dragon Plate.",ETO);
				set_item_bonus("armor bonus",1);
	return 1;
	}
	else{
   		tell_object(ETO,"%^BOLD%^You strap yourself into the platemail armor.");
   		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
   			" straps on the White Dragon Plate.",ETO);
				set_item_bonus("armor bonus",0);
   	return 1;
	}
}
}
int remove_func(){
	if((string)ETO->query_diety() == "kreysneothosies") {
      	tell_object(ETO,"%^BOLD%^You feel relieved to be out "+
			"of that cold suit of armor.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
			"scrambles quickly out of the armor, looking"+
			" relieved to be out of it.",ETO);
      return 1;
   	}
   	if((string)ETO->query_diety() == "lord shadow") {
      	tell_object(ETO,"%^BOLD%^You feel the protection of "+
			"the winter fall away as you remove the plate.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
			"gives a heavy sigh upon removal of the armor.",ETO);
	return 1;
	}
	else{
   		tell_object(ETO,"%^BOLD%^You remove the armor.");
   		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
   			" removes the armor.",ETO);
   	return 1;
	}
}
