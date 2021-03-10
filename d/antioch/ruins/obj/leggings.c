//Added Lore - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/std/armour";

void create()
{
	::create();
   set_obvious_short("%^YELLOW%^A pair of tan leather leggings%^RESET%^");
	set_name("leggings of fortitude");
	set_short("%^YELLOW%^Leggings of Fortitude%^RESET%^");
    	set_id(({"leggings","leggings of fortitude","Leggings of Fortitude"}));
 	set_long(
	"%^ORANGE%^These leggings are made out of a very supple hide that has"+
	" been carefully tanned. It is so soft and light you could easily have"+
	" mistaken it for cotton. It is very light in color, but doesn't appear"+
	" to have been dyed."
	);
	set_lore("The Leggings of Fortitude were said to have been a gift "+
		"from a female enchantress to a ranger of Mielikki that she was"+
		" in love with.  Crafted from the soft hide of a deer, Hestia spent"+
		" over a year alone in the creation of the leggings themselves.  "+
		"After the leggings were sewn together, Hestia called upon her "+
		"arcane might to infuse magic into the leather leggings.  "+
		"Enchanting them to protect as well as aid the battle readiness"+
		" of the wearer, Hestia spent over three months in the enchantment"+
		" process.  With her gift finally done, she finally left her tower "+
		"to search for the ranger Liam.  It was said that Liam was so shocked"+
		" and surprised by the fine gift that Hestia had made for him, that "+
		"he nearly wept.  The two started to spend more and more time together,"+
		" till they were married three years later.  Some claim that during "+
		"the enchantment process, unknowing to Hestia an additional enchantment"+
		" was added to the leggings, the power to reject those with cruel, "+
		"violent, or selfish thoughts from ever wearing them.");
	set_property("lore",12);  
	set_weight(2);
	set_type("clothing");
	set_limbs(({"right leg","left leg"}));
	set_ac(0);
	set_property("enchantment",2);
	set_item_bonus("attack bonus",1);
	set_item_bonus("constitution",1);
	set_value(500);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
   if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"The leggings reject someone of your evil nature!");
      return 0;
   }
   if(ETO->query_lowest_level() < 15) {
      tell_object(ETO,"You are too inexperienced to wear such fine leggings.");
      return 0;
   }
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The leggings refuse to be worn while you're using such evil items.");
      return 0;
   }
	tell_object(ETO,"%^YELLOW%^As you pull up the leggings, you realize that"+
	" even though they are comfortable, they will also offer some protection.");
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" pulls"+
	" on a pair of soft leggings.",ETO);
   ETO->set_property("good item",1);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^ORANGE%^You remove your wonderful leggings, immediately"+
	" missing their soft feel against your legs.");
	tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" removes"+
	" "+ETO->query_possessive()+" soft leather leggings.",ETO);
   ETO->set_property("good item",-1);
	return 1;
}
