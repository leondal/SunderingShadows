//Coded by Bane//
//Changed the price and lowered the carry weight a bit - Cythera 3/05  Price was 200 internal weight was 100 carrying weight was 1 lb
#include <std.h>

inherit "/std/bag_logic";

int timer;

void create() {
    	::create();
    	set_id(({"bag","sack","bag of holding"}));
    	set_name("bag of holding");
    	set_short("%^BOLD%^%^BLUE%^Bag of Holding");
    	set_obvious_short("%^BOLD%^%^BLUE%^A blue bag%^RESET%^");
	set_weight(5);
//	set_weight(1);
    	set_long("%^BOLD%^%^BLUE%^This is a magical bag of holding."+
		"  The bag holds things in a small "+
		"pocket dimension, therefore allowing you to put"+
		" an incredible amount "+
		"of things into it.  However take note that this"+
		" item is not permenant "+
                "and its magic fades when you log out.%^RESET%^");
	set_lore("The Bags of Holdings were first crafted by the"+
		" Brotherhood of the Sixteen Sigils, an order of mages"+
		" specialized in conjuration/summoning and transmutation."+
		"  The Brotherhood was able to become very rich from the "+
		"useful magical items and trinkets that they created.  "+
		"With their newfound wealth, the Brotherhood was able to "+
		"devote more energy and time to the study of magic.  "+
		"Though after one of their experiments released a Balor"+
		" in the city of Asgard, the Brotherhood was force to "+
		"disband under threat of death.");
    	set_value(5000);
//      set_value(200);
        set_property("no animate",1);
	set_max_internal_encumbrance(100);
}

init()
{
    ::init();
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && !timer) { timer = time() + 14400; }
}

void save_me(string file)
{
    if(timer && time() < timer) { return ::save_me(file); }
    else { return 1; }
}

// need this so it doesn't break on login
void delayed_delete_me()
{
    TO->move("/d/shadowgate/void");
    TO->remove();
    return;
}



void restore_me(string file)
{
    ::restore_me(file);
    if(timer && time() > timer) 
    { 
        call_out("delayed_delete_me",2);
        return 1; 
    }
}

int isMagic(){
 	int x;
 	x = ::isMagic();
 	x = x+1;
 	return x;
}
