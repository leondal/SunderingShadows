#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("sheep sausage");
	set_short("sausage links");
	set_id(({"sausage","sheep sausage","sausage links","food"}));
	set_long(
         "%^RESET%^%^ORANGE%^These sausage links are about one and a "+
         "half inches in diameter.  Each one is about four inches long.  "+
         "They are in natural lamb casings and the odors of sage and "+
         "other spices rise from them.  It looks as if they have been "+
         "cured to keep for some time, but would probably rot after "+
         "awhile.%^RESET%^"
	);
	set_weight(6);
      set_strength(20);
	set_value(18);
	set_poison(0);
	set_destroy();
	set_canSave(1);
	set_my_mess("The heavily spiced sausages seem a little greasy, "+
         "but the taste is nice and they are rather filling.");
	set_your_mess("eats several links of sausage.");
}
