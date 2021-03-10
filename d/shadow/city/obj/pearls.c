inherit "/std/armour";

void create() {
    ::create();
    set_name("pearl necklace");
    set_id(({"necklace","pearl necklace","pearls"}));
    set_short("%^BOLD%^%^WHITE%^a pretty %^RESET%^pearl%^BOLD%^%^WHITE%^ necklace%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This long string of pearls has been scratched and scraped, and yet it still remains "+
	"in tact and generally unphased. There is a %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^lden cla%^RESET%^%^ORANGE%^s%^BOLD%^p "+ 
	"%^WHITE%^that still works quite well. Turned somewhat %^RESET%^dull %^BOLD%^over time, these sturdy pearls "+ 
	"still have some life in them, and would likely fetch a fair price, if not brighten the day "+ 
	"of a young girl or a working class woman.%^RESET%^");
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
    set_type("jewelry");
    set_limbs( ({ "neck" }) );
    set_ac(0);
	set_property("enchantment",1);
	set_item_bonus("charisma",1);
	set_wear((:TO,"wear_fun":));
    set_remove((:TO,"remove_fun":));
}
int wear_fun() {
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" carefully fastens a delicate old string of pearls around "+ETO->QS+" neck.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully fasten the old string of pearls around your neck and feel prettier.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" removes the fragile string of pearls.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You unhook the clasp and remove the long string of pearls.%^RESET%^");
   return 1;
}