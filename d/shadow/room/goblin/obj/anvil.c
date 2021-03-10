#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"anvil"}));
      set_name("Anvil");
    set_short("%^MAGENTA%^%^BOLD%^Anvil%^RESET%^");
    set_long("%^MAGENTA%^This is a glowing purple anvil. Where it came from is "
	"unexplainable.%^RESET%^"
    );
    set_weight(1000000);
    call_out("removal",20);
}
void removal() {
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO,"%^BOLD%^%^MAGENTA%^"
	"There is a loud popping sound and the Anvil vanishes!%^RESET%^"
    );
    TO -> remove();
    return;
}
