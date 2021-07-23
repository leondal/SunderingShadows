#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silk stockings");
	set_id(({ "tights", "stockings", "web tights", "web stockings", "silk tights", "silk stockings" }));
	set_short("%^BOLD%^%^BLACK%^sp%^RESET%^i%^BOLD%^%^BLACK%^d%^RED%^"+
	   "e%^BLACK%^r%^RESET%^s%^BOLD%^i%^RESET%^lk %^BOLD%^%^BLACK%^st"+
	   "%^WHITE%^o%^BOLD%^%^BLACK%^ck%^WHITE%^i%^BLACK%^ngs%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^g%^RESET%^o%^BOLD%^ss%^RESET%^a"+
	   "%^BOLD%^mer %^BOLD%^%^BLACK%^stockings%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^These %^RESET%^wispy %^BOLD%^%^BLACK%^"+
	   "stockings are spun of a %^WHITE%^silky soft gossamer "+
	   "webbing%^BLACK%^. The web pattern of the stockings themselves "+
	   "are as intricate and myriad in design as one woven by an "+
	   "actual sp%^RED%^i%^BLACK%^der. A %^RESET%^soft %^BOLD%^glow "+
	   "%^BLACK%^surrounds the stockings themselves as %^BOLD%^"+
	   "%^WHITE%^light trails%^BLACK%^ course through the %^WHITE%^"+
	   "silvery %^BLACK%^material, providing a stunning %^WHITE%^"+
	   "highlighting %^BLACK%^effect. The stockings are extremely "+
	   "form fitting and obviously not intended to conceal much of "+
	   "anything.%^RESET%^");
	set("read",
@AVATAR
 %^RED%^As you gaze into the myriad designs of this fabric you realize that words seem to be forming within them before your eyes....
               %^BOLD%^%^BLACK%^The Queen of Spiders sees all within the darkness
AVATAR
	);
    set("langage","drow");	
	set_weight(1);
   set_value(0);
	set_lore("%^BOLD%^%^BLACK%^These tights were said to have been spun "+
	   "by one of Lolth's hunting spiders as a reward for the High "+
	   "Priestess Solizantia. Her beauty was unsurpassed in the city "+
	   "of Aurachnolus, and it was said that where she went, the will "+
	   "of Lolth followed. In the end though, the luminesce nature of "+
	   "her gift managed to make her the obvious target in a raid on "+
	   "one of her trade expeditions through the Underdark. It is "+
	   "whispered that such was the intent behind Lolth's gift..the "+
	   "Lady of Chaos is a fickle mistress.");
	set_property("lore difficulty",28);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("charisma",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_item_bonus("charisma",2);
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wear_func(){
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" shivers as gossamer webbing slides smoothly up "+ETO->QP+" legs.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The gossamer webbing slides smoothly up your legs.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes darken as "+ETO->QS+" slips the clinging fabric from "+ETO->QP+" legs.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You are filled with a strange foreboding as you remove the clinging fabric.%^RESET%^");
	return 1;
}