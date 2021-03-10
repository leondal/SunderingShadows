#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create(){
      ::create();
      set_name("squirrel suit");
      set_id(({ "squirrel suit","squirrel leather","leather","suit" }));
     	set_short("%^RESET%^G%^BLUE%^r%^RESET%^a%^BLUE%^y %^RESET%^"+
		"Squirrel Suit%^RESET%^");
      set_obvious_short("%^RESET%^A gray squirrel suit%^RESET%^");
      set_long( "%^BLUE%^This little suit is made from real "+
		"%^RESET%^gray squirrel%^BLUE%^ fur.  The full body"+
		" suit looks warm and inviting, like it could cut the chill"+
		" of even the most coldest winters.  "+
		"A %^BOLD%^%^WHITE%^lighter shade%^RESET%^%^BLUE%^ of fur "+
		"runs down the tummy of the suit, giving contrast to"+
		" the fuzzy gray fur.  A large bushy tail is attached to "+
		"the back of the suit.  It seems as if the tail"+
		" has a wire core, allowing it to be bent into shape.%^RESET%^\n");
     	set_value(1400);
     	set_lore( "As the Tabby Cat and the Green Frog head to "+
		"Daggerdale they encounter a new friend, The Gray"+
		"Squirrel, a crabby and grumpy old creature, in "+
		"The Tabby Cat in Silver Sandals  The Gray Squirrel is a "+
		"character who's seen what the world is like"+
		" and has become jaded by his experiences.  The Gray "+
		"Squirrel serves as the voice of reason, all be it crabby,"+
		" to the Tabby Cat. Still despite his gruff appearance, "+
		"there is still something likeable if not loveable about"+
		" the Gray Squirrel.  - A History of Plays - Isley Threvet");
      set_property("lore difficulty",13);
      set_size(1);
      set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
	::init();
      	add_action("wiggle","wiggle");
}
int wear_func(){
     	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" climbs into the"+
		" fuzzy gray suit, dressing up like a bushy tail squirrel.",ETO);
      tell_object(ETO,"%^BLUE%^You climb into the fuzzy gray suit, "+
		"feeling like a squirrel. You almost feel like giving your tail"+
		" a %^RESET%^wiggle%^RESET%^");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^%^BLUE%^%^"+ETOQCN+" climbs out "+
		"of the fuzzy gray suit.",ETO);
      tell_object(ETO,"%^BLUE%^You climb out of the squirrel suit.");
      return 1;
}
int wiggle(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
      	TP->send_paralyzed_message("info",TP);
    	return 1;
}
if(query_worn() && !str) {
    	tell_object(ETO,"%^BLUE%^You give your %^RESET%^gray%^BLUE%^"+
		" bushy tail a wiggle, fluffing the fur out.");
      tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" gives their bushy tail a "+
		"wiggle, fluffing the fur out.",ETO);
      return 1;
}
}
