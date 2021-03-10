#include <std.h>
inherit "/d/common/obj/armour/leather.c";

// Coral Sea Area - Created January 2009 by Ari

int tracker;
string owner;

void init(){
	::init();
		add_action("magicthem","call");
		if(stringp(owner)) return;
		if(interactive(TP) && TP == ETO){
			owner = TPQN;
			set_size(TP->query_size());
	}
}

void create() {
    ::create();
    set_name("leather");
	set_id(({"leather","kelpwrap","papery leather","armor","wrap",
		"kelp","kelp wrap"}));
	set_short("%^RESET%^%^CYAN%^K%^GREEN%^e%^CYAN%^lp%^RED%^w"+
		"%^ORANGE%^r%^CYAN%^ap%^RESET%^");
	set_obvious_short("%^RESET%^a suit of %^ORANGE%^papery"+
		"%^RESET%^ leather");
	
	set_long("%^RESET%^%^CYAN%^This armor is amazingly light and "+
		"appears to be equally fragile.  A %^GREEN%^deep green "+
		"%^CYAN%^color overall, there are slashes of %^ORANGE%^"+
		"brown%^CYAN%^, %^RED%^red %^CYAN%^and even little hints "+
		"of %^YELLOW%^yellow %^RESET%^%^CYAN%^and %^WHITE%^white "+
		"%^CYAN%^throughout.  Strips of what appears to be thick, "+
		"wrinkly paper reveal themselves as leaves of %^GREEN%^"+
		"seaweed %^CYAN%^laced together into a suit of leather-like "+
		"armor.  Hundreds of leaves have been used and the weaving "+
		"has made it actually rather %^RED%^sturdy %^CYAN%^and not "+
		"as papery as one might first think.  Added to its "+
		"%^YELLOW%^protection%^RESET%^%^CYAN%^, the many shades "+
		"of color cause it to blend well with %^ORANGE%^dark "+
		"places %^CYAN%^including the depths from which the "+
		"material originally came.%^RESET%^");
 
	set("value",500);
	set_property("enchantment",2);
	set_size(2);
	
	set_lore("Said to have been created by the mermaids of the "+
		"Saakrune Sea, this armor is most often gifted to those "+
		"sailors which the mermaids favored.  It is rumored that "+
		"such armor carries useful gifts imbued within them, "+
		"though only the one given the gift is said to know all "+
		"the powers that the armor holds.");
	set_property("lore difficulty",15);
	
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme(){
	if(interactive(TP) && owner != (string)TPQN){
		tell_object(ETO,"%^BOLD%^%^CYAN%^This suit of armor just "+
			"doesn't feel comfortable.%^RESET%^");
    return 0;
	}
	tell_object(TP,"%^RESET%^%^CYAN%^You hear the sound of the "+
		"ocean and a %^MAGENTA%^woman's%^CYAN%^ voice tells you: "+
		"%^MAGENTA%^To clear the fog call on %^CYAN%^Aunoe's aid. "+
		"%^MAGENTA%^To summon it, call for %^CYAN%^Celie"+
		"%^MAGENTA%^.%^RESET%^");
	return 1;
}

int removeme(){
	tell_object(ETO,"%^RESET%^%^CYAN%^The sound of the ocean "+
		"fades away.%^RESET%^");
	return 1;
}

/* Once per 4 real life hours, this thing should cast either 
invisibility or detect invisiblity.  It's a +2 armor in a 20-23
area, so with that functionality it should be on par for 
balance.  ~hope~ */

int magicthem(string str){
        if(TP->query_bound() || TP->query_unconscious()){
                TP->send_paralyzed_message("info",TP);
        return 1;
        }
        if(!TO->query_worn()){
                notify_fail("%^BOLD%^%^BLUE%^How can you hear the "+
					"song of the ocean if you're not wearing your "+
					"armor?");
        return 1;
        }
        if(!str){
                notify_fail("You need to learn the ocean's song!");
        return 1;
        }
        if(str != "aunoe" && str != "celie"){
                notify_fail("Try listening to the ocean's song when you "+
					"wear your armor.");
        return 1;
        }
        if(tracker > time()){
                tell_object(TP,"The sirens have already aided you "+
					"today.");
        return 1;
        }
        
        tracker = time() + 14400;
			if(str == "celie"){
				tell_object(TP,"The song of the sea surrounds you "+
					"revealing the truth from the hidden.");
                new("/cmds/spells/i/_invisibility")->use_spell(TP,TP,20,100,"mage");
				return 1;
			}
			if(str == "aunoe"){
			   	tell_object(TP,"The song of the sea surrounds you "+
					"and you feel yourself drifting away.");
                new("/cmds/spells/d/_detect_invisibility")->use_spell(TP,0,20,100,"mage");
				return 1;
			}
        return 1;
}

