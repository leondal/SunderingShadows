#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The Dungeon");
set_long("%^BLUE%^Another dark and depressing room, filled with memories and implements of horror beyond belief.");
set_smell("default", "%^MAGENTA%^\nDried blood, mold and mildew reaches your nose.");
set_listen("default", "%^BOLD%^RED%^Only echoes, haunting, frightning, and sad");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomcastle5c"
]) );
}
