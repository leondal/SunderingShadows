#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("figurine");
    set_id(({"figurine","bronze figurine","figurine2","death_figure"}));
    set_short("%^RESET%^%^ORANGE%^Bronze figurine%^RESET%^");
    set_long("%^ORANGE%^"
	"The small figurine appears to resemble the twisted and contorted "
	"body of a humanoid in great anguish or pain."
	"%^RESET%^"
);
    set_weight(5);
    set_value(100);
}
