#include <std.h>
#include "../defs.h"
inherit VENDOR;

void create() {
        ::create();
        set_items_allowed("misc");
        set_name("Clancy");
        set_short("%^RESET%^%^CYAN%^Clancy DeFleur, Instrument Maker%^WHITE%^");

        set_id(({"clancy","Clancy","crafter","maker","instrument maker","bard"}));
        set_long("%^RESET%^%^MAGENTA%^Clancy is a %^CYAN%^flamboyant "+
		"%^MAGENTA%^fellow and eager to make a sale. He has a "+ 
		"%^BOLD%^boyish charm %^RESET%^%^MAGENTA%^about him, from "+ 
		"his dimpled smile to the twinkle in his "+ 
		"%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e "+ 
		"ey%^RESET%^%^CYAN%^e%^BOLD%^s%^RESET%^%^MAGENTA%^. He wears his "+ 
		"%^BOLD%^%^BLACK%^long dark hair %^RESET%^%^MAGENTA%^pulled "+ 
		"out of his face. While most of his appearance speaks of a "+ 
		"laidback, fun lifestyle, he has the %^WHITE%^calloused hands "+ 
		"%^MAGENTA%^of a laborer, and it is obvious that he puts much "+ 
		"love into every %^BOLD%^instrument %^RESET%^%^MAGENTA%^he makes. "+ 
		"He wanders through the streets, peddling his wares and "+ 
		"whistling cheerfully.%^WHITE%^");
        set_race("human");
        set_gender("male");
        set_alignment(5);
        set_hd(19,2);
        set_max_hp(200);
        set_hp(200);
        set_exp(10);
		set_storage_room(STOR"instrument_storage");
}