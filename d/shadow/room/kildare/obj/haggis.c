#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("haggis");
	set_short("haggis");
	set_id(({"haggis","sheep haggis","food"}));
	set_long(
         "This unusual meal is made by boiling the windpipe, lungs, "+
         "heart, and liver of sheep, then mincing them.  The ingredients "+
         "are then mixed with seasoning and oatmeal, then stuffed into "+
         "the sheep's stomach and sewn closed.  After being boiled again, "+
         "this meal is enjoyed as a delicacy in Kildare Glen, though "+
         "there are some in other lands who find it revolting."
	);
	set_weight(7);
      set_strength(30);
	set_value(25);
	set_poison(0);
	set_destroy();
	set_my_mess("The unusual haggis is heavily spiced and soft, "+
         "complete with a wonderful flavor of various spices.");
	set_your_mess("eats the haggis and looks surprised.");
}
