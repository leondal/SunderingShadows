#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("figurine");
    set_id(({"figurine","jade figurine","figurine1","death_figure"}));
    set_short("%^RESET%^%^GREEN%^Jade figurine%^RESET%^");
    set_long("%^GREEN%^"
	"The small figurine appears to resemble the twisted and contorted "
	"body of a humanoid in great anguish or pain."
	"%^RESET%^"
);
    set_weight(5);
    set_value(100);
}
