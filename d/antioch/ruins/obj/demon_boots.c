#include <std.h>
#include <move.h>
//Added lore - Cythera 4/05
//#include "../ruins.h"
// inherit "/realms/styx/pocketarmour.c"; was for testing
inherit PARMOUR;

void create()
{
	::create();
   	set_obvious_short("%^RESET%^%^RED%^A pair of dark red boots%^RESET%^");
	set_name("demonskin boots");
	set_short("%^RESET%^%^RED%^D%^BOLD%^e%^BLACK%^m%^RESET%^%^RED%^o"+
		"%^BOLD%^n%^BLACK%^s%^RESET%^%^RED%^k%^BOLD%^i%^BLACK%^n"+
		"%^RESET%^%^RED%^ Boots%^RESET%^");
	set_id(({"boots","demon boots","demonskin boots","Demonskin Boots"}));
	set_long(
	"%^RED%^These boots are made from the leathery hide of an unfortunate"+
	" demon. They are a deep reddish shade, almost the color of dried blood."+
	" Despite the toughness of the hide, the inside of the boots are quite"+
	" comfortable, having been padded with %^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ satin.%^RESET%^ "
	);
	set_lore("Stitched from the hide of a balor, the demonskin "+
		"boots are a prized possession by many who serve the "+
		"Dark Gods.  There are those that believe by wearing the"+
		" skin of a balor, their strength and power is increased"+
		" tenfold.  More intelligent folk though find these rumors"+
		" to be nothing more that old wives tales at best.  The "+
		"boots, crafted by soaking the balor's flesh in a three "+
		"part mixture of defiled water from one of the Gods of "+
		"Light, the blood of a virgin elven child -maidens preferred"+
		"-, and the sweat of a Maralith.  The mixture and the hide "+
		"are allowed to boil together in a ritual that grants them "+
		"their unnatural qualities.  The boots are then lined with "+
		"black satin, though this seems more for comfort than anything."+
		"  There are some rumors that some rogues and assassins have "+
		"found a way to house a dagger within the boots.");
	set_property("lore",12);
	set_weight(5);
	set_type("clothing");
        set_limbs(({"right foot","left foot"}));
	set_ac(0);
	set_property("enchantment",2);
	set_value(50);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_max_internal_encumbrance(20);
}

int wearme()
{
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"You refuse to put on such evil boots!");
      return 0;
   }
	if(ETO->query_lowest_level() < 20) {
		tell_object(ETO,"The boots refuse to be worn by someone as lowly as yourself.");
		return 0;
	}
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The boots refuse to be worn while you are using such goodly items!");
      return 0;
   }
   if((int)ETO->query_alignment() == 2 || (int)ETO->query_alignment() == 5 || (int)ETO->query_alignment() == 8) {
      set_ac(-1);
   }
	if(!random(3)) {
		if(ETO->is_class("thief") || ETO->is_class("bard")) {
			tell_object(ETO,"%^BOLD%^%^RED%^As you slip your feet into the boots"+
			" you realize there is a spot where you could hide a dagger on the"+
			" inside of one of them.");
         ETO->set_property("evil item",1);
			return 1;
		}
	}
	tell_object(ETO,"%^RED%^The demonskin boots slide smoothly onto your feet.");
   ETO->set_property("evil item",1);
	return 1;
}

int removeme()
{
   if((int)ETO->query_alignment() == 2 || (int)ETO->query_alignment() == 5 || (int)ETO->query_alignment() == 8) {
      set_ac(0);
   }
   tell_object(ETO,"%^RED%^You slip your feet out of the comfortable boots.");
   ETO->set_property("evil item",-1);
   return 1;
}

int item_allowed(object item) {
	if(!item->is_weapon()) {
	  write("This is meant for daggers only.\n");
	  return 0;
       	}
	if(sizeof(all_inventory(TO)) > 0) {
	   write("There is already a dagger in the boot.\n");
	   return 0;
	}
	if(item->query_size() > 1 || !item->id("dagger")) {
 	   write("That is a little large, this is meant for daggers only.\n");
	   return 0;
	}
    return 1;
}

/* fixing it so we don't have dual maintenance (there was a lighting problem that was fixed in /std/container) - DO NOT DUPLICATE whole functions of lib code, either call the super or use a function designed for the situation (see item_allowed() added above)!!!  *Styx*  11/25/04
	int res, i, silly;
	object ths, tht, *inv;
	string this, that;

	if((total_light(TP))+(int)(TP)->query_sight_bonus() < -1) {
		notify_fail("It is too dark.\n");
		return 0;
	}
	if(stringp(str) && sscanf(str,"%s in %s", this, that) == 2) {
		if(present(this,TP)) {
			if(present(that,TP) || present(that,ETP)) {
				ths = present(this,TP);
				tht = present(that,TP);
				if(ths == tht) {
					notify_fail("Get real!\n");
					return 0;
				}
				if(!tht) tht = present(that,ETP);
				if(ths->drop()) {
					notify_fail("You cannot drop that!\n");
					return 0;
				}
				if(tht != TO) return 0;
				if(!ths->is_weapon()) {
					notify_fail("This is meant for daggers only.\n");
					return 0;
				}
				if(sizeof(all_inventory(TO)) > 0) {
					notify_fail("There is already a dagger in the boot.\n");
					return 0;
				}
				if(ths->query_size() > 1 || !ths->id("dagger")) {
					notify_fail("That is a little large, this is meant for daggers only.\n");
					return 0;
				}
				if(tht->receive_objects()) {
					res = (int)ths->move(tht);
					if(res == MOVE_OK) {
						write("You put "+ths->query_short()+" in "+tht->query_short()+".\n");
						say(""+TPQCN+" puts "+ths->query_short()+" in "+tht->query_short()+".\n");
						return 1;
					}
					if(res == MOVE_NO_ROOM)
						notify_fail("For some reason it does not fit...\n");
					if(res == MOVE_NOT_ALLOWED)
						notify_fail("You are not allowed to do that...\n");
					return 0;
				}
				notify_fail("It is closed.\n");
				return 0;
			}
			notify_fail(capitalize(that)+" is not here.\n");
			return 0;
		}
		notify_fail("You are not carrying "+this+".\n");
		return 0;
	}
	return 0;
}
*/
