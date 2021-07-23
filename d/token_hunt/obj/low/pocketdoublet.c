#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("doublet");
	set_id(({ "doublet", "doeskin doublet", "noble's doublet", "nobles doublet", "pocketed doublet" }));
	set_short("%^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^o%^RESET%^c%^ORANGE%^ke%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d d%^BOLD%^%^BLACK%^o%^RESET%^u%^ORANGE%^bl%^RESET%^e%^ORANGE%^t%^RESET%^");
	set_obvious_short("%^RESET%^a finely tailored %^ORANGE%^d%^BLACK%^%^BOLD%^o%^RESET%^e%^ORANGE%^sk%^RESET%^i%^BOLD%^%^BLACK%^n %^RESET%^doublet");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^Worn over a white cotton shirt with generous sleeves that chinch at the wrists, this stylish doublet has been crafted out of thin, highly detailed %^RESET%^%^ORANGE%^d%^BLACK%^%^BOLD%^o%^RESET%^e%^ORANGE%^sk%^RESET%^i%^BOLD%^%^BLACK%^n %^WHITE%^of a pale gold-white coloring.  Lined with %^BLACK%^black silk %^WHITE%^and trimmed with %^RESET%^ivory brocade%^BOLD%^%^WHITE%^, the garment tapers to a narrow waist with a series of %^RESET%^%^ORANGE%^gold buttons %^BOLD%^%^WHITE%^lacing up the chest.  Stitched about the waist are a quartet of short peplums that give a dynamic flare as they lay over the upper hips.  Though sleeveless, the doublet is fitted with a pair of sleeve caps that feature the same %^RESET%^ivory brocade %^BOLD%^%^WHITE%^trim as the collar and decorative peplums.  A nobleman's garment, the peplums are designed in such a way that they conceal small %^BLACK%^pockets %^WHITE%^were a few valuables could be tucked away. %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR

Finely made garments are always in demand and those which are both beautiful and functional items are highly prized.  Many a nobleman has been known to seek garments which can conceal a few small vices, such a snuffbox or a smoking pipe and tobacco, all without loosing the trim look of the garment.  Those tailors that turn their skills to such efforts are often rewarded with repeat business and fame of their own as word spreads about their exceptional talent with cloth and leather. 

AVATAR
	);
	set_property("lore difficulty",8);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" dusts a bit of imaginary dust away from their finely made doublet.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You dust a few specs of imaginary dust away from the breast of your%^RESET%^ "+query_short()+"%^YELLOW%^.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" slides their doublet off and folds it up neatly.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You remove your doublet, neatly folding it up so that it'll be ready for its next use.%^RESET%^");
	return 1;
}