#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();

    set_long(""+ ::query_long() + "\n%^RED%^To the northwest, the marsh grows much "
        "darker and thicker. You are fairly sure that the Marsh of Fear begins here.%^RESET%^");

    set_listen("default","You hear wails and screams coming form the northwest.");

    set_exits(([
"southeast": RPATH "m_p000_p004",
"northwest": RPATH "f_p000_p007",
    ]));
}
