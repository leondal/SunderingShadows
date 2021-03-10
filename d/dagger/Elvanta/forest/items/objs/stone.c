#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("stone");
set_short ("A large emerald stone");
set_long("%^GREEN%^This stone is a monument and stands eight feet high, and about six feet in diameter.  Upon the stone is a bronze plaque with writing upon it.%^RESET%^");
set_weight (1000);
set_value (0);
}
