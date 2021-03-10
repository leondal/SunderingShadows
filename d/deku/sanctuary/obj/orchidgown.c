//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
	::create();
	set_name("%^MAGENTA%^orchid gown%^RESET%^");
	set_id(({ "gown", "orchid gown", "silk gown", "violet gown" }));
	set_short("%^RESET%^%^MAGENTA%^O%^BOLD%^r%^RESET%^%^MAGENTA%^ch%^BOLD%^i%^RESET%^%^MAGENTA%^d Gown%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^An orchid violet silk gown%^RESET%^");
	set_long("%^MAGENTA%^This gown has been dyed a lovely shade of violet called"+
		" orchid.  The sleeveless gown is cut in a simple style, more likely to"+
		" play up the unusual fabric.  The cut of the gown features curved seams"+
		" that run down the front and back of the dress, helping to give the wearer"+
		" a feminine shape.  Cut short, the hem of the gown drapes at one's knees."+
		"  The silk feels luxurious and fine, showing it to be a high quality fabric"+
		" that is rarely seen in these parts.  Etched into the violet colored silk "+
		"is a small repetitive pattern of an orchid.  The exotic flower's petals use"+
		" the silk as a backdrop for the %^YELLOW%^yellow%^RESET%^%^MAGENTA%^ and "+
		"%^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^ streaks that dot each petal, "+
		"emerging from the center.  There are a few %^GREEN%^green leaves%^MAGENTA%^ "+
		"and some %^BOLD%^%^WHITE%^white tendrils%^RESET%^%^MAGENTA%^ attached to "+
		"each blossom still.  The dress carries the exotic and sensual scent of "+
		"orchids with it, as if the fragrance was infused with the gown.%^RESET%^\n");
	set_weight(5);
	set_value(2000);
      set_max_internal_encumbrance(21);
	set_lore(
@AVATAR
The Orchid Gown is a magical dress that is made from the flower the same exotic flower.  Through some secret ritual a coven of enchantresses called the "Daughters of the Flowers" infuse the sensual and exotic fragrance of the orchid with fine silk. In the process the gown is all enchanted with unnatural strength.  Some say that comes in part from the spider silk that they use to weave such fine silk.  The Daughters of the Flowers are rumored to have made other gowns from flowers and through magic have pres

AVATAR
	);
	set_property("lore",8);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
        set_property("enchantment",3+random(2));
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
string long;
	if(!interactive(ETO)) return 1;
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slips into the silken gown"+
			" as the exotic sensual perfume of an orchid tickles your nose.",ETO);
	tell_object(ETO,"%^MAGENTA%^You slip into the fine silken gown and inhale the"+
			" exotic sensual perfume of the orchid that seems to be "+
                        "infused with the gown.\n%^GREEN%^Hidden in the pattern you"+
				" find a pair of pockets!");
	long = ETO->query_long();
      ETO->set("long","%^MAGENTA%^The exotic sensual aroma of an orchid rolls off of"+
			" "+ETO->QO+".");

	return 1;
}
int remove_func(){
string long;
	if(!interactive(ETO)) return 1;
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slips out of the silk gown."+
		"  The air fills with the exotic sensual perfume of an orchid.",ETO);
	tell_object(ETO,"%^MAGENTA%^You slip out of the silk gown, filling the air"+
		" with more of the heavenly perfume of the orchid.");
	long = ETO->query_long();
	ETO->set("long");
	return 1;
}
