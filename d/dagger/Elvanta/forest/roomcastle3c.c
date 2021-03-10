#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The Kitchen");
set_long("%^BOLD%^BLUE%^The kitchen area is lined with huge brick fireplaces filled with cauldrons bubbling, spits of meat being turned by apprentices and vegetables and tubers laid upon huge trestle tables.");
set_smell("default" , "%^MAGENTA%^\nAromas from roasted meats, stews and vegetables makes your mouth water.");
set_listen("default", "%^ORANGE%^The clang of pots and pans, the yelling of cooks and the yelping of apprentices abuses your ears.");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomcastle2c",
"up" : "/d/dagger/Elvanta/forest/roomcastle3"
]) );
set_items(([
"fireplaces" : "Fireplaces built from brick are laid within the walls, cauldrons, big enough to hold small children, rest upon the fires.",
"tables" : "Long, scarred, burned, cut and bashed trestle tables fill the room waiting to be used for the making of food"
]));
}
