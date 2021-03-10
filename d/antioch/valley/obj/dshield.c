//dsheild.c - Added new long desc based on reports that it looked just like a leather shield.  Circe 11/22/03
//updated by Circe 7/22/19 to fix armor bonus issues
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/shield.c";

void create(){
   ::create();
   set_name("oval shield");
   set_obvious_short("An oval shield");
   set_short("%^BOLD%^%^BLACK%^Darkened Shield%^RESET%^");
   set_id(({"dark shield","shield","shadow shield","darkened shield","oval shield"}));
   set_lore("This was once a normal metal shield, but it has been with the "
      "shadows so long that it has been twisted towards evil.");
   set_long("This oval shield was crafted of steel that has been darkened by "
      "an unknown force. A faint aura of wrongness seems to radiate from the metal.");
   set_size(2);
   set_value(40);
   set_weight(10);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme(){
	int align;

	align = ETO->query_alignment();
	if(ETO->query_level() < 10) {
		notify_fail("You are not adept enough to use this equipment.");
		return 0;
	}
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The shield feels like"+
			" it was meant to be there as you slip it on.%^RESET%^");
   TO->set_property("enchantment",2);
   while((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
         ETO->set_property("evil item",1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^%^BLUE%^A slight chill washes"+
			" over you as you place the shield on your arm.%^RESET%^");
			tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
			" shivers slightly as "+ETO->query_subjective()+" wears"+
			" the %^BLACK%^Darkened Shield.%^RESET%^",ETO);
         ETO->set_property("evil item",1);
			return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^%^CYAN%^You can sense a great"+
			" evil within the shield.%^RESET%^");
         ETO->set_property("evil item",1);
			return 1;
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^You feel vulnerable as"+
			" you lose the protection of the Darkened Shield.%^RESET%^");			
   if((int)TO->query_property("enchantment")) {
     TO->remove_property("enchantment");
   }
         ETO->set_property("evil item",-1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^%^BLUE%^You feel warmer as you"+
			" remove the %^BLACK%^Darkened Shield%^BLUE%^ but your"+
			" skin tingles where the touch of the metal was.%^RESET%^");
			tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
			" removes the %^BLACK%^Darkened Shield%^BLUE%^ but has"+
			" a thoughtful look on "+ETO->query_possessive()+" face.",ETO);
         ETO->set_property("evil item",-1);
			return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^%^CYAN%^You gladly remove the"+
			" evil shield, happy to be rid of the sinister presence.");
         ETO->set_property("evil item",-1);
			return 1;
	}
}
