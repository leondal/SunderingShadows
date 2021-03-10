inherit "/std/food.c";

void create(){
 	::create();
  	set_name("jail food");
  	set_id(({"jail food","food"}));
  	set_short("%^RESET%^%^ORANGE%^lu%^GREEN%^m%^ORANGE%^p of food%^RESET%^");
  	set_long("%^RESET%^%^ORANGE%^This looks like some type of bread.  "
	   "It is heavy, dark, and grainy with a few %^GREEN%^greenish "
	   "%^ORANGE%^splotches.  "
	   "It doesn't look especially appetizing but is certainly better "
	   "than starving.%^RESET%^\n");
  	set_destroy();
   set_poison(0);
  	set_strength(8);
  	set_my_mess("You chew a while but manage to get the bread down.");
  	set_your_mess("chews on the dark substance and swallows hard.");
	set_weight(1);
	set_value(0);
}