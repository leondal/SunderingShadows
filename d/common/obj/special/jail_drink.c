inherit "/std/drink.c";

void create(){
 	::create();
  	set_name("jail drink");
  	set_id(({"jail drink","water", "drink"}));
  	set_short("%^RESET%^cl%^BOLD%^%^BLACK%^o%^RESET%^ud%^ORANGE%^y"
	   "%^RESET%^ water%^RESET%^");
  	set_long("This is a cup of what you suppose is water.  It's a "
	   "little cl%^BOLD%^%^BLACK%^o%^RESET%^ud%^ORANGE%^y %^RESET%^"
	   "and warm but looks drinkable.");
  	set_destroy();
   set_poison(0);
   set_type("water");
  	set_strength(3);
  	set_my_mess("You hold your nose and drink the water.");
  	set_your_mess("downs the cup of water quickly.");
	set_weight(1);
	set_value(0);
}