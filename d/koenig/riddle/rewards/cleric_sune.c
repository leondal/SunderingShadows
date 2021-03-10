//cleric_sune.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NHIDE;

void create(){
   ::create();
   	set_name("ruby rose bracers");
   	set_id(({"bracers","ruby rose bracers","gold bracers","rose bracers"}));
   	set_obvious_short("%^YELLOW%^A pair of gold bracers%^RESET%^");
	set_short("%^RESET%^%^RED%^R%^BOLD%^%^RED%^u%^RESET%^%^RED%^b%^BOLD%^"+
		"%^RED%^y%^RESET%^%^RED%^ R%^BOLD%^%^RED%^o%^RESET%^%^RED%^s"+
		"%^BOLD%^%^RED%^e%^YELLOW%^ Bracers%^RESET%^");
   	set_long("%^BOLD%^%^WHITE%^The aesthetically pleasing bracers "+
		"have been crafted out of pure %^YELLOW%^gold%^BOLD%^%^WHITE%^."+
		"  The seamless bracers extend from wrists to mid-forearms, "+
		"offering plenty of protection.  Set into the center of the "+
		"bracers is a large %^BOLD%^%^RED%^rose%^BOLD%^%^WHITE%^ shaped"+
		" %^RESET%^%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^b%^BOLD%^"+
		"%^RED%^y%^BOLD%^%^WHITE%^.  Cut into multiple facets the ruby"+
		" rose %^BOLD%^%^RED%^shimmers%^BOLD%^%^WHITE%^ and %^RESET%^"+
		"%^RED%^shines%^BOLD%^%^WHITE%^ with a dazzling brilliance in "+
		"the light.  Elegant and detailed %^YELLOW%^filigree%^BOLD%^"+
		"%^WHITE%^ scrollwork has been cut into the bracers, adding to"+
		" their beauty.  Radiating outwards from the %^RESET%^%^RED%^"+
		"r%^BOLD%^%^RED%^u%^RESET%^%^RED%^b%^BOLD%^%^RED%^y%^BOLD%^"+
		"%^WHITE%^ rose, the scrollwork has an organic feel to it.  "+
		"The open design of the bracers allows the wearer's flesh to "+
		"serve as a backdrop for the harmonious image.%^RESET%^");
   	set_lore("The Ruby Rose Bracers were first formed and enchanted by a "+
		"half-elven wizard-priest of Sune by the name Darntello.  Seeking"+
		" to find a balance between optimum protection and a striking "+
		"appearance Darntello found a way to craft a pair of bracers "+
		"that would protect him as well most armors he could find.  The"+
		" ruby heart is crafted in a way that it looks as if it is made"+
		" up one single large ruby, but in truth each heart is made up "+
		"of nine perfectly formed rubies.  While enchanting the bracers,"+
		" Darntello found a way for them to create a slight barrier "+
		"around the wearer, similar to how mages can protect themselves"+
		" with a piece of blessed leather.  Though Darntello's creation "+
		"as beautiful as it is, was inherently flawed.  For while they "+
		"did offer some protection to the wearer, Darntello found he and"+
		" other mages were unable to perform arcane magic while wearing "+
		"the bracers.");  
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
        tell_object(ETO,"%^RED%^You feel the warm protection of the bracers"+
		" fade away, leaving you vulnerable.");
        return 1;
}
