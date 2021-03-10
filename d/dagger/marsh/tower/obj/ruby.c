#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"gem","emerald"}));
    set_short("%^GREEN%^Emerald%^RESET%^");
    set_long(
	"%^GREEN%^A large emerald which is probably worth a nice "
	"sum of gold."
	"%^RESET%^"
);
   set_weight(3);
    set_value(1000);
}
