#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"gem","ruby"}));
    set_short("%^RED%^Ruby%^RESET%^");
    set_long(
	"%^RED%^A large ruby which is probably worth a nice "
	"sum of gold."
	"%^RESET%^"
);
    set_weight(10);
    set_value(1500);
}
