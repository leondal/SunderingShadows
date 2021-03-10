inherit "/std/armour";

void create() {
    ::create();
    set_name("gentleman's cravat");
    set_id(({ "cravat","gentleman's cravat" }));
    set_short("%^BOLD%^%^BLACK%^a %^RESET%^%^ORANGE%^g%^WHITE%^e%^ORANGE%^n%^BOLD%^%^BLACK%^tle%^RESET%^%^ORANGE%^m%^WHITE%^a%^ORANGE%^n%^BOLD%^%^BLACK%^'s "+
	"cr%^RESET%^%^ORANGE%^a%^WHITE%^v%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is a fine cravat made from woven silk. Once it was a flawless shade "+
	"of %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^, but now it is fading to "+ 
	"%^WHITE%^gr%^BOLD%^%^BLACK%^a%^RESET%^y%^ORANGE%^. The borders are striped "+ 
	"%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^k "+ 
	"%^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^n "+ 
	"%^RESET%^%^ORANGE%^and are now slightly frayed and tattered, not that anyone would notice with "+ 
	"some clever arranging. A cravat is worn knotted about the neck like a scarf, and is often "+ 
	"accented with a pin. This one is no exception, although the %^BOLD%^b%^RESET%^%^ORANGE%^r%^BOLD%^ass "+ 
	"%^RESET%^%^ORANGE%^bird-shaped pin could use a good p%^GREEN%^o%^ORANGE%^lishing.");
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
	set_weight(2);
    set_value(250);
    set_type("clothing");
    set_limbs( ({ "neck" }) );
    set_ac(0);
	set_property("enchantment",1);
	set_item_bonus("charisma",1);
	set_wear((:TO,"wear_fun":));
    set_remove((:TO,"remove_fun":));
}
int wear_fun(){
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" carefully ties the cravat around "+ETO->QS+" neck.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^You carefully arrange the soft cravat around neck and feel like a true gentleman.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" removes a silk cravat.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^You untie the silk cravat and set it aside for now.%^RESET%^");
   return 1;
}