#include <std.h>
inherit "/d/common/obj/armour/banded.c";

// Coral Sea Area - Created January 2009 by Ari

void create() {
    ::create();
    set_name("banded mail");
	set_id(({"banded","bandedmail","banded mail","mail","coral mail",
		"coral colored mail","coral colored banded mail",
		"coralscape","armor"}));
	set_short("%^RESET%^%^ORANGE%^C%^BOLD%^%^BLACK%^o%^YELLOW%^r"+
		"%^RESET%^%^ORANGE%^als%^BOLD%^%^BLACK%^c%^YELLOW%^a"+
		"%^RESET%^%^ORANGE%^pe%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^coral %^RESET%^colored "+
		"%^ORANGE%^banded %^RESET%^mail%^RESET%^");
	
	set_long("%^RESET%^This suit of banded mail has the oddest of "+
		"appearances.  Once made of %^CYAN%^steel%^RESET%^, the metal "+
		"has %^BOLD%^%^BLACK%^oxadized %^RESET%^and become pourous "+
		"but rather then breaking down and rusting away, creating a "+
		"perfect bed for %^ORANGE%^coral %^RESET%^to grow upon.  "+
		"Eventually replacing the metal completely and creating a "+
		"hardend shell of preseved %^ORANGE%^coral%^RESET%^.  "+
		"Newer looking fixtures of complementing %^CYAN%^steel "+
		"%^RESET%^have been attached to make the armor movable, "+
		"while the plates themselves have been left as is.  Each a "+
		"unique piece of art forged by the sea.%^RESET%^");
    
	set("value",500);
    set_property("enchantment",3);
	
	set_lore("Coral is such a flakey material that it is almost "+
		"inconceivable that it could harden into anything as useful "+
		"as armor, yet this suit of banded mail appears to be proof "+
		"that such is possible.  It is only upon close inspection "+
		"that the markings, hidden and sometimes enhanced by the "+
		"coral, start to reveal the tale.  A tale of a long "+
		"forgotten land, lost to the world hundreds of years ago.  "+
		"This land, ruled by a young prince of little note, held "+
		"one thing of importance, that being the mage Usiean.  As "+
		"the markings of this wizard become clear so does the "+
		"reason for its enduring strength.  Usiean's magic items "+
		"are said to be self repairing.");
	set_property("lore difficulty",15);
	
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
    set_struck((:TO,"strikeme":));
}

int wearme(){
	tell_object(TP,"%^YELLOW%^A fine dusting of coral falls from "+
		"the armor revealing newly grown coral below.%^RESET%^");
	tell_room(ETO,"%^YELLOW%^For a moment, the air tastes of the "+
		"%^RESET%^%^CYAN%^sea%^YELLOW%^ as "+ETOQCN+" dons their "+
		"armor.",TP);
	TO->set_overallStatus(100);
	return 1;
}

int removeme(){
	tell_object(ETO,"%^YELLOW%^You feel like you've been for a "+
		"swim in the ocean as you remove the armor.%^RESET%^");
	tell_room(EETO,"%^YELLOW%^There is the brief sound of the %^RESET%^"+
		"%^CYAN%^ocean's roar%^YELLOW%^ in the air as "+ETOQCN+" "+
		"removes their armor.%^RESET%^",TP);
	return 1;
}

int strikeme(int damage, object what, object who){	
	if(random(1000) < 150){
		tell_room(EETO,"%^YELLOW%^Coral dust explodes "+
		"from "+ETOQCN+"'s armor, blinding "+who->QCN+"!",({ETO,who}));
			who->set_paralyzed(5,"%^YELLOW%^You are "+
				"trying to remove the coral dust from your "+
				"eyes!%^RESET%^");
		tell_object(ETO,"%^YELLOW%^An explosion of coral dust "+
			"errupts from "+who->QCN+"'s armor blinding you!");
		tell_object(who,"%^YELLOW%^Coral dust explodes in a shower "+
			"of dust from "+ETOQCN+"'s armor, blinding you!");
	}
}
