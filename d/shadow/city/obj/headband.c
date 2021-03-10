inherit "/std/armour";

void create() {
    ::create();
    set_name("headband");
    set_id(({ "headband","head band","lace headband","lace head band" }));
    set_short("%^BOLD%^%^WHITE%^a t%^RESET%^at%^BOLD%^ter%^RESET%^e%^BOLD%^d "+
	"la%^RESET%^c%^BOLD%^e h%^RESET%^e%^BOLD%^a%^RESET%^db%^BOLD%^a%^RESET%^n%^BOLD%^d%^RESET%^");
    set_long("%^BOLD%^Made to fit the head of a lady, this %^RESET%^%^MAGENTA%^headband "+
	"%^BOLD%^%^WHITE%^was once quite fetching. Time and neglect has watched it "+ 
	"%^RESET%^%^ORANGE%^w%^WHITE%^ith%^ORANGE%^e%^WHITE%^r %^BOLD%^and %^RESET%^fa%^ORANGE%^d%^WHITE%^e "+ 
	"%^BOLD%^though, and so it is merely a %^RESET%^ghost %^BOLD%^of its former beauty. "+ 
	"The borders are lined with tiny %^MAGENTA%^p%^WHITE%^e%^RESET%^ar%^BOLD%^l%^MAGENTA%^s%^WHITE%^, "+ 
	"some of which are now missing. The intricate lacing of the band is %^RESET%^tattered %^BOLD%^and "+ 
	"%^RESET%^torn %^BOLD%^in parts, but it was once a very delicate and pretty floral pattern.%^RESET%^");
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
    set_type("clothing","jewelry");
    set_limbs( ({ "head" }) );
    set_ac(0);
	set_property("enchantment",1);
}