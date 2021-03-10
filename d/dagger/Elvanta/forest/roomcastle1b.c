#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Moirbin Castle, the library");
set_long("%^CYAN%^The walls are lined floor to ceiling with bookshelves crammed to the limit with tomes of knowledge.  A large oval desk sits in the middle of the room with a chair beside it awaiting the keeper.");
set_smell("default", "%^MAGENTA%^\nThe musty smell of old books rises from the shelves.");
set_listen("default", "%^CYAN%^Sounds of laughter, song and cheer rise up from below.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomcastle8b.c",
"northeast" : "/d/dagger/Elvanta/forest/roomcastle9b",
"east" : "/d/dagger/Elvanta/forest/roomdruid2"
]) );
set_items(([
"desk" : "Made of oak, it stands sentinel to the knowledge held within this room",
"chair" : "The chair is worn on the seat where the rulers have sought knowledge down through the ages",
"bookshelves" : "Bookshelves, creaking under the weight of centuries, past and present line all walls in this room"
]) );
}
