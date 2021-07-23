#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("stone bracers");
	set_id(({ "bracers", "stone bracers" }));
	set_short("%^RESET%^%^ORANGE%^S%^BOLD%^%^BLACK%^t%^RESET%^o%^ORANGE%^ne B%^BOLD%^%^BLACK%^r%^RESET%^a%^ORANGE%^ce%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a pair of %^RESET%^%^ORANGE%^stone%^BOLD%^%^BLACK%^ bracers%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^These odd bracers are made of stone, but curiously they appear to have been carved and designed to look like leather.  "
"Every supple detail of the leather has been painstakingly carved into the stone, including the laces that keep the bracers closed.  Oddly there's no way "
"to open these bracers and only a small hand could fit through the wrist part in order to wear them.  On the back of each bracer is a small %^BOLD%^%^BLACK%^"
"onyx stone %^RESET%^%^ORANGE%^that glitters prettily in the light.%^RESET%^");
	set_weight(13);
   set_value(0);
	set_lore("There is no lore that you can recall about anyone crafting such a set of bracers like these, but they were found in a place where a medusa "
"was said to have lived.  Perhaps they really were once made of leather and have suffered a change under her stony gaze.  Whatever the case, they are surely "
"very strong and protective after such a treatment.  If not a little heavy.");
	set_property("lore difficulty",23);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("spell damage resistance",15);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the "+query_short()+"%^BOLD%^%^BLACK%^ onto your arm and the black jewels on the back of each bracer glitter brightly.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The bright glitter of the black jewels on the back of the "+query_short()+"%^BOLD%^%^BLACK%^ fade away.%^RESET%^");
	return 1;
}

int is_metal() { return 0; }
