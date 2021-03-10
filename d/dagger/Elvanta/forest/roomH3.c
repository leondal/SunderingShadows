#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a home");
set_long ("%^GREEN%^You have entered one of the many elven homes in this city.  It is within the great redwood tree itself.  No sharp angles or edges meet your eyes.  It is truly remarkable to see a home molded from a tree. You are in a living area, with <couches>, <chairs> and small tables scattered around the room.  A large <fireplace> covers one wall and a <bookshelf> the other.  A round window is on the north side and looks out into the forest.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell from the forest fills this room and makes it a pleasant place to be.");
set_listen ("default", "Sounds of pots and plates and of food being prepared reaches your ears.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/room41",
"west" : "/d/dagger/Elvanta/forest/roomH3a",
"east" : "/d/dagger/Elvanta/forest/roomH3b",
"up" : "/d/dagger/Elvanta/forest/roomH3c"
]) );
set_items(([
"fireplace" : "This fireplace is made from blue stone quarried many miles from here.  It is large and takes up one wall, and has several rods set into it to use for cooking.",
"bookshelf" : "Obviously elves love to read, as this bookshelf takes up three quarters of a wall and is loaded with books, papers and scrolls.",
"couches" : "The couches extrude from the walls and seem to be part of the tree itself.  Bright cushions reside upon them.",
"chairs" : "As with the couches, the chairs are also molded from the tre and seem immovable but comfortable.",
"tables" : "Round tables, perhaps three feet in diameter are scattered throughout the room and have many colourful plants placed on them."
]) );
}
