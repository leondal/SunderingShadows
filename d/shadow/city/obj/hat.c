inherit "/std/armour";

void create() {
    ::create();
    set_name("top hat");
    set_id(({ "hat","tophat","top hat" }));
    set_short("%^BOLD%^%^BLACK%^a %^RESET%^d%^ORANGE%^e%^BOLD%^%^BLACK%^n%^RESET%^t%^ORANGE%^e%^BOLD%^%^BLACK%^d "+
	"%^RESET%^t%^ORANGE%^o%^BOLD%^%^BLACK%^p%^RESET%^h%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This striped tophat is a bit faded on the outside and has a large "+ 
	"%^RESET%^dent %^BOLD%^%^BLACK%^upon the crown that is impossible to pop out. The inside is "+ 
	"lined with fine silk the color of %^RED%^blo%^RESET%^%^RED%^o%^BOLD%^d%^BLACK%^. The lining "+ 
	"is now a bit %^RESET%^torn %^BOLD%^%^BLACK%^and %^RESET%^tattered%^BOLD%^%^BLACK%^, and "+ 
	"%^RESET%^%^RED%^s%^ORANGE%^p%^BOLD%^%^BLACK%^ott%^RESET%^%^ORANGE%^e%^RED%^d %^BOLD%^%^BLACK%^with "+ 
	"what is, hopefully, just dirt. The hat is striped in "+ 
	"b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^k and "+ 
	"b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^n, the colors now "+ 
	"fading and running together. The %^RESET%^black trim %^BOLD%^%^BLACK%^of the hat is "+ 
	"%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^iscolo%^RESET%^r%^ORANGE%^e%^BOLD%^%^BLACK%^d and "+ 
	"%^RESET%^c%^ORANGE%^u%^BOLD%^%^BLACK%^rlin%^RESET%^%^ORANGE%^g %^BOLD%^%^BLACK%^in on itself. %^RESET%^");
	set_lore("%^RESET%^%^CYAN%^The Plague Rats were a ragtag, impoverished troupe of street performers that were "+
	"largely based out of Shadow, but with influences straying as far north as Torm and "+ 
	"as far south as Tabor. It is unknown who the founder of the troupe was, nor is there "+ 
	"any accurate recording of the performers as they seemed to come and go on a whim. "+ 
	"The Rats were known to bring a variety of performances to the streets, including "+ 
	"singing, dancing, storytelling, fire eating, juggling and acrobatics. Relying upon the "+ 
	"generosity of passersby to fill their coffers, the performers were often left cold and hungry. "+ 
	"Many years have passed since the name 'The Plague Rats' faded from memory. Some say a "+ 
	"majority of members fell to, ironically, a plague, leaving the few remaining members to "+ 
	"scurry off into obscurity. Other rumors suggest that the performers found themselves in the "+ 
	"midst of a territory war with the local thieves guild and were methodically picked off.\n");
    set_property("lore difficulty",9);
    set_weight(4);
    set_value(7);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(0);
	set_property("enchantment",1);
}