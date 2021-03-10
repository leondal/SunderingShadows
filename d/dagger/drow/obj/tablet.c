#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"tablet","tablet of earth"}));
    set_short("%^GREEN%^%^BOLD%^Tablet of earth%^RESET%^");
    set_long("This tablet is formed from an earthy substance and is covered "
	"in strange runes. While the runes meanings are not clear, you know "
	"that the tablet could be inset into something by <inset tablet>."
    );
    set_weight(1);
}
