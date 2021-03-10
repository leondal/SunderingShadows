// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create(){
    	::create();
	set_name("tabby suit");
      set_id(({ "tabby cat suit","tabby suit","leather","suit","cat suit" }));
      set_short("%^RESET%^%^ORANGE%^T%^BOLD%^a%^RESET%^"+
      	"%^ORANGE%^bby C%^BOLD%^a%^RESET%^%^ORANGE%^t Suit%^RESET%^");
      set_obvious_short("%^ORANGE%^A t%^YELLOW%^a%^RESET%^"+
      	"%^ORANGE%^bby cat suit%^RESET%^");
      set_long( "%^ORANGE%^This little suit is made to look "+
      	"like the body of a tabby cat.  The full body leather"+
      	" suit is covered with soft golden orange fur that is "+
      	"intersected with %^YELLOW%^light orange%^RESET%^%^ORANGE%^"+
      	" tabby stripes.  The fur is"+
      	" rich and has a bright sheen to it, showing that it's "+
      	"been well cared for.  A long narrow tail pokes out of"+
      	" the back of the suit.  The tail has been tacked down "+
      	"to the back of the suit, to keep it from getting into "+
      	"the way.  This suit is quite warm and cozy.%^RESET%^\n");
     	set_value(1400);
      set_lore( "The Tabby Cat in Silver Sandals is a favorite "+
           "play of young and old.  The children delight in"+
           " seeing the adventures of the Tabby Cat played out, "+
           "while adults find humor the jokes that seem to be aimed for"+
           " them.  The Tabby Cat is granted her wish to speak after "+
           "finding a pair of silver sandals and sets out to"+
           " Daggerdale in her new shoes.  Along the way she meets "+
           "a couple of friends, and the three of them have a"+
           " series of misadventures. - A History of Plays - Islev Threvet");
     	set_property("lore difficulty",13);
      set_size(1);
      set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
	::init();
      	add_action("purr","purr");
}

int wear_func(){
   if((string)ETO->query_race() == "gnome" || (string)ETO->query_race() == "halfling") TO->set("chabonus",1);
   else TO->set("chabonus",1);
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" tugs on the tabby cat "+
      	"suit, which fits "+ETO->QO+" purrfectly.",ETO);
   tell_object(ETO,"%^ORANGE%^You pull on the tabby cat suit and "+
      	"have the urge to %^BOLD%^purr%^RESET%^%^ORANGE%^!");
   return 1;
}

int remove_func(){
   	tell_room(EETO,"%^ORANGE%^"+ETOQCN+" climbs out of the tabby cat suit.",ETO);
   	tell_object(ETO,"%^ORANGE%^You climb out of the tabby cat suit.");
   	return 1;
}
int purr(string str)
{
  	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
    	TP->send_paralyzed_message("info",TP);
     		return 1;
}
if(query_worn() && !str) {
     	tell_object(ETO,"%^ORANGE%^You purr happily as the suit fits you purrrfectly.");
     	tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" purrs happily in their tabby"+
		" cat suit.",ETO);
     	return 1;
}
}
