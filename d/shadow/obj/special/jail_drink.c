inherit "/std/drink.c";

void create(){
 	::create();
  	set_name("jail drink");
  	set_id(({"jail drink","water"}));
  	set_short("%^RESET%^cloudy water%^RESET%^");
  	set_long("This is a cup of water.  It's a little cloudy but looks drinkable.");
  	set_destroy();
   set_poison(0);
   set_type("water");
  	set_strength(3);
  	set_my_mess("You hold your nose and drink the water.");
  	set_your_mess("downs the cup of water quickly.");
	set_weight(1);
	set_value(0);
}