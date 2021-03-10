#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("robe of silk");
   set_id( ({"robe","silk robe","robe of silk"}) );
   set_short("%^RESET%^%^YELLOW%^Robe of silk%^RESET%^");
   set_obvious_short("flowing silk robe");
   
   set_long("%^BOLD%^%^YELLOW%^This shiny golden robe is made of finest quality "+
   "silk. When worn it is actually quite poofy, as if it was made to practically "+
   "conceal the body of the wearer from view. The stitches on the robe are very visible "+
   "and make the entire robe look as if it was sewn together in a dramatic hurry. "+
   "The only really remarkable thing about it, save for the quality of the silk, is "+
   "the %^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^mbl%^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^m %^BOLD%^%^YELLOW%^"+
   "embroidered on the back of it. The %^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^mbl%^BOLD%^%^WHITE%^e"+
   "%^BOLD%^%^RED%^m %^BOLD%^%^YELLOW%^vaguely resembles a large wolf head. It has been "+
   "sewn much more carefully and you think that the tailor must have slowed down and took "+
   "his time with creating it.%^RESET%^");
   
   set_property("lore difficulty", 20);
   set_lore("%^BOLD%^%^YELLOW%^Rumors suggest that this robe was tailored for Lord Hawk. "+
   "The tailor, who was not working of his own freewill, did not do such a good job with the "+
   "creation. After presenting it to Lord Hawk, who imbued it with some magic, the tailor was "+
   "forced to add the emblem. He was never seen again. Some assume that the Lord had him killed "+
   "but there has never been any proof of this.%^RESET%^");
   
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_ac(1);
   set_item_bonus("magic resistance",1);
   set_property("enchantment",2);
   set_value(100+random(3)*100);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   tell_object(ETO,"%^ORANGE%^You feel the softness and warmth of the silk.");
   return 1;
}

int remove_func() {
   tell_object(ETO,"%^ORANGE%^You want to experience that silky feeling again soon.");
   return 1;
}
