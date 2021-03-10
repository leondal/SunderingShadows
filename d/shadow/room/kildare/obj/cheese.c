#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("crowdie");
	set_short("a cake of crowdie");
	set_id(({"crowdie","cake","cake of crowdie","cheese","food"}));
	set_long(
         "This is a small cake of a simple white cheese.  It is somewhat "+
         "softer than other cheeses made for travel, but it is protected "+
         "in a bag made of sheepskin.  Made from the milk of a sheep, "+
         "it is seasoned with salt and pepper, giving it a bit more flavor."
	);
	set_weight(3);
      set_strength(12);
	set_value(6);
	set_poison(0);
	set_destroy();
	set_canSave(1);
	set_my_mess("The cheese is saved from being completely bland by "+
         "a hint of salt, pepper, and sour milk.");
	set_your_mess("eats a cake of cheese and grimaces slightly.");
}
