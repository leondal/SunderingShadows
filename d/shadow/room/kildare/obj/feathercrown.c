#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("crown of feathers");
	set_id(({"crown","crown of feathers","leaf crown","peryton crown","white crown"}));
set_short("%^BOLD%^%^WHITE%^Crown of Feathers%^RESET%^");
	set_long(
         "%^BOLD%^%^WHITE%^This crown is woven of stark white feathers.  "+
         "The feathers are quite soft and have been carefully molded "+
         "together and woven so that no other material was needed "+
         "in the crown's construction.  A strange power seems "+
         "to radiate from the crown, making it feel heavier than "+
         "it probably should." 
	);
      set_lore("This crown is taken from the king of the foul "+
         "beasts known as perytons.  The crown is made from the "+
         "feathers of all the perytons the king had to slay to "+
         "become king himself.  These ruthless creations have no "+
         "regard for life - especially their own - and live "+
         "only to hunt and kill, hoping for a release from this world.");
      set_property("lore difficulty",11);
	set_size(2);
	set_weight(5);
	set_value(300);
	set_type("clothing");
	set_limbs(({"head"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_ac(0);
	set_item_bonus("magic resistance",1);
}

int wearme()
{
	if(ETO->query_lowest_level() < 10) {
		tell_object(ETO,"You are not yet experienced enough to use this equipment.");
		return 0;
	}
      tell_object(ETO,"%^BOLD%^You feel a strange sense of power as "+
         "you settle the crown upon your head.");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" puts on a crown of feathers "+
         "and looks a little...well, like a bird.",ETO);
      return 1;
}

int removeme()
{
   tell_object(ETO,"%^BOLD%^You feel the strange presence leave "+
      "you as you take off the crown.");
   return 1;
}
