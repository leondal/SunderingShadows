#include <std.h>
#include "../undead.h"
inherit MON+"ogre_guard";

void create()  {
    ::create();
    set_emotes(5,({"%^MAGENTA%^The guard whispers%^RESET%^: Want safe passage out of this hell hole?","%^MAGENTA%^The guard mumbles%^RESET%^: For a fee of 20 gold I might be able to help you out a little.","%^MAGENTA%^The guard speaks low%^RESET%^: Pay me 20 gold and I'll show you a safe way around the battlefield."}) ,0);
    add_id("ditchguard");
}
