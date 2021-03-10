#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("gem");
    set_id(({"gem","demongem","demongem2"}));
    set_short("%^RESET%^%^MAGENTA%^A large gem%^RESET%^");
    set_long(
	"%^MAGENTA%^A large smoky gem with various swirling patterns "
	"of colour flowing through it. Deep in the center you can see "
	"what appears to be a humanoid like shape frozen within the gem."
	"%^RESET%^"
);
   set_weight(1);
    set_value(500);
}
