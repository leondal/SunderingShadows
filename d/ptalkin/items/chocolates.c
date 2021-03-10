#include <std.h>
inherit "/std/food.c";

void create()
{
::create();
	seteuid(geteuid());
set_name("chocolate");
set_id(({"chocolate"}));
set_short("chocolate");
set_long("a chocolate");
set_weight(1);
set_strength(1);
set_my_mess("As you eat the chocolate, a slow grin of appreciation lights your face.");
set_your_mess(" eats a chocolate and smiles");
}
