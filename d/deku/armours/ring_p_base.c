//updated by Circe 5/22/04 to have new descriptions to add a little variety
#include <std.h>
inherit DAEMON;

#define GEMS ({"%^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x","%^YELLOW%^top%^RESET%^%^ORANGE%^a%^YELLOW%^z","%^BOLD%^%^MAGENTA%^ame%^RESET%^%^MAGENTA%^t%^BOLD%^hyst","%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y","%^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^ra%^RESET%^%^GREEN%^l%^BOLD%^d","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^WHITE%^r%^BLUE%^e","%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l","%^BOLD%^%^WHITE%^dia%^CYAN%^m%^WHITE%^ond","%^CYAN%^aqu%^BOLD%^a%^RESET%^%^CYAN%^ma%^BOLD%^r%^RESET%^%^CYAN%^ine","%^RESET%^%^CYAN%^la%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^is %^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^az%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^li"})

void create() {
    ::create();
}

void create_ring(object obj){
int i;
string str, GEM, X;
    i = random(sizeof(GEMS));
       GEM = GEMS[i];
	if(GEM == "%^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x" || GEM == "%^BOLD%^%^MAGENTA%^ame%^RESET%^%^MAGENTA%^t%^BOLD%^hyst" || GEM == "%^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^ra%^RESET%^%^GREEN%^l%^BOLD%^d" || GEM == "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l" || GEM == "%^CYAN%^aqu%^BOLD%^a%^RESET%^%^CYAN%^ma%^BOLD%^r%^RESET%^%^CYAN%^ine") {
		X = "An";
	}
	else {
		X = "A";
	}
    obj->set_name(""+X+" "+GEM+" ring%^RESET%^");
    obj->set_id(({"ring of protection", "ring","protection",""+GEM+" ring"}));
    obj->set_obvious_short(""+X+" "+GEM+" ring%^RESET%^");
    obj->set_short(""+X+" "+GEM+" ring of protection%^RESET%^");
    obj->set_long("%^BOLD%^%^WHITE%^This beautiful %^YELLOW%^ring "+
       "%^WHITE%^is crafted from a solid piece "+
       "of flawless "+GEM+"%^BOLD%^%^WHITE%^.  Completely "+
       "smooth and free "+
       "of any %^RESET%^%^ORANGE%^marking%^BOLD%^%^WHITE%^, the "+
       ""+GEM+" %^BOLD%^%^WHITE%^looks to have been "+
       "magically fashioned and reinforced to be %^CYAN%^"+
       "unbreakable%^BOLD%^%^WHITE%^.  The "+GEM+" %^BOLD%^"+
       "%^WHITE%^ring is cool to the touch, never "+
       "%^RESET%^%^RED%^warming %^BOLD%^%^WHITE%^even when cast "+
       "into a %^RED%^f%^YELLOW%^i%^RED%^re%^WHITE%^.%^RESET%^");
    obj->set_lore("These fantastic rings have been fashioned "+
       "throughout the ages by wizards who understand the "+
       "secrets of protection magic...and of making such "+
       "magic permanent.  Such a ring is not to be taken lightly, "+
       "as years of crafting went into each one.");
    obj->set_property("lore difficulty",9);
    obj->set_type("ring");
    obj->set_ac(0);
    obj->set_weight(2);
    obj->set_value(250+random(250));
    obj->set_limbs(({"right hand","left hand"}));
    obj->set_property("enchantment",1);
    obj->set_wear((:TO,"do_wear":));
}