#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works");
set_long ("%^GREEN%^The first thing to attack your senses is the noise.  Sounds of metal striking metal, the hissing of hot iron, the crashing of objects being moved or dropped.  You notice this room is rather small but, has a <table> and <chair> off to the left, and examples of iron work on the right <wall>.  A large burly elf sits at the table waiting to take any orders.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of heated metal assails your nose.");
set_listen ("default", "The sounds of metals being banged into different forms is overwhelming.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/room50",
"north" : "/d/dagger/Elvanta/forest/roomforgea",
"west" : "/d/dagger/Elvanta/forest/roomforgeb",
"east" : "/d/dagger/Elvanta/forest/roomforgec"
]) );
set_items
(([
"table" : "A long table roughly hewn from a large tree stands in front of you.  Blacked areas show where hot metals have laid, paper and ink lay here as well, for orders.",
"chair" : "This chair is huge and could seat at least three people, or just the burly elf waiting for you",
"wall" : "As you look at the wall, you see examples of horseshoes, and other oddly shaped shoes, swords, knives and other weapons.  The wall seems to be the catalogue of items made here."
]));
}
void reset(){
::reset();
if(!present("dirg"))
new("/d/dagger/Elvanta/forest/mon/dirg")->move(this_object());
}
