// updated con bonus from the new system. Nienne, 09/07.
#include <std.h>
#include "../ruins.h"
inherit "/std/armour";

void create()
{
	::create();
   set_obvious_short("%^YELLOW%^A bright yellow silk cloak%^RESET%^");
	set_name("Cloak of Valor");
	set_short("%^YELLOW%^Cloak of %^WHITE%^V%^YELLOW%^a%^WHITE%^l%^YELLOW%^o%^WHITE%^r%^RESET%^");
	set_id(({"cloak","cloak of valor","valor cloak","Cloak of Valor"}));
   set_long(
	"%^YELLOW%^This cloak has been woven from the finest of silks, and seems"+
	" imbued with a magical enchantment. It has an aura about it that leaves"+
	" you in awe, though you can't quite say why. The cloak itself is the"+
	" color of the sun at high noon, it even seems to dispel the shadows"+
	" around you.%^RESET%^"
	);
   //set_long("This cloak has been woven from the finest of silks and has been dyed an incredible shade of brilliant yellow.");
	set_lore("Of elven make, the Cloak of Valor is said to have"+
		" been woven from the finest silks in the lands.  Infused"+
		" with rays of sunshine, via elven magic, this yellow "+
		"cloak is a prized possession by many.  The Cloak of Valor"+
		" was once a typical cloak worn by the elves as they "+
		"adventured out in the lands.  Though as the elves began"+
		" to interact more with humans, the cloaks were given as"+
		" gifts to those who aided to protect the forest and the"+
		" elven way of life.  The nature of the cloak is said to "+
		"repel anyone with a selfish or cruel heart from ever "+
		"being able to wear it.");
	set_property("lore",12);
	set_weight(5);
	set_type("clothing");
	set_limbs(({"neck"}));
   set_ac(0);
	set_property("enchantment",3);
	set_item_bonus("constitution",1);
	set_item_bonus("sight bonus",1);
	set_value(300);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"%^YELLOW%^The cloak rejects one with your evil nature!");
		return 0;
	}
	if((int)ETO->query_lowest_level() < 20) {
		tell_object(ETO,"%^YELLOW%^The cloak seems to want one more experienced"+
		" than yourself.");
		return 0;
	}
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The cloak refuses to be worn while you are using such evil items!");
      return 0;
   }
	tell_object(ETO,"%^YELLOW%^You feel comfortable and confident as you fasten"+
	" the cloak about your neck.");
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" seems more"+
   " sure of "+ETO->query_objective()+"self as "+ETO->QS+""+
	" fastens the cloak about "+ETO->QP+" neck.",ETO);
   ETO->set_property("good item",1);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^You miss the feel of the cloak the moment it leaves"+
	" your shoulders.");
	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" swings the"+
	" cloak off "+ETO->QP+" shoulders with a sigh.",ETO);
   ETO->set_property("good item",-1);
	return 1;
}
