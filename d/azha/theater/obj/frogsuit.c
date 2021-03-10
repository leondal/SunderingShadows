#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create(){
        ::create();
      set_name("frog suit");
      set_id(({ "frog suit","frog leather","leather","suit" }));
      set_short("%^BOLD%^%^GREEN%^F%^RESET%^%^GREEN%^r%^BOLD%^"+
		"o%^RESET%^%^GREEN%^g %^BOLD%^Suit%^RESET%^");
      set_obvious_short("%^BOLD%^%^GREEN%^A frog suit%^RESET%^");
      set_long( "%^CYAN%^This little suit is made from real "+
		"frog leather.  The full body leather suit still"+
 		" retains a wet slick appearance, looking fresh and"+
		" supple.  A lighter band of "+
		"%^BOLD%^%^WHITE%^g%^GREEN%^r%^WHITE%^e%^GREEN%^e%^WHITE%^n"+
		"%^RESET%^%^CYAN%^ runs down the front of the"+
		" suit, the belly of the frog.   Fading from "+
		"%^BOLD%^%^GREEN%^light%^RESET%^%^CYAN%^ to %^GREEN%^"+
		"dark green%^CYAN%^ the color wraps around to the back"+
		" of the suit.  %^GREEN%^Darker green%^CYAN%^ spots dot"+
		" the arms and legs of the suit, adding to the life like"+
		" appearance of the leather suit.%^RESET%^\n");
      set_value(1400);
      set_lore( "As the Tabby cat in The Tabby Cat and the Silver"+
		" Sandals heads to Daggerdale she encounters"+
		" a strange sorts of characters.  One of those is Green Frog,"+
		" a smart though dense frog who can't seem to "+
		"locate his pond.  The sassy Tabby cat with her silver sandals"+
		" befriends the befuddled frog.  The two set"+
		" out towards Daggerdale.  The Green Frog's character is one "+
		"that offers an unbiased sincerity to"+
		" all he meets.  His simple charm and words often times strike"+
		" closer to home than most folk are willing"+
		" to admit.  - A History of Plays - Isley Threvet");
      set_property("lore difficulty",13);
      set_size(1);
      set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
     	::init();
    	add_action("hop","hop");
}
int wear_func(){
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" tugs"+
		" on the green leathersuit, dressing up like a frog.",ETO);
      tell_object(ETO,"%^GREEN%^You realize that it ain't easy being"+
		" green as you tug on the leather frog suit.  Maybe having a"+
		" %^BOLD%^hop%^RESET%^%^GREEN%^ will cheer you up.");
        		return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" climbs out"+
		" of the frog suit.",ETO);
      tell_object(ETO,"%^GREEN%^You climb out of the frog suit.");
        		return 1;
}
int hop(string str)
{
   	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
            	return 1;
        }

	if(query_worn() && !str) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^You hop about like a frog.");
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
		" hops about like a frog.",ETO);
                	return 1;
        }
}
