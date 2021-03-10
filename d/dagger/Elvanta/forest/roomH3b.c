#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a dining room");
set_long ("%^GREEN%^This is the dining room of the home.  A long oval <table> rests upon a carved wooden <lion> in the middle of the room.  Tall backed <chairs> are around the table.  Place settings with <goblets>, <earthenware dishes> and <cutlery> seem to await dinner.  The walls are set off with pale rose <draperies> over porthole <windows>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of rose petals emerges from the candles.");
set_listen ("default", "Quiet surrounds you in this room, it is peaceful and soul healing.");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomH3"
]) );
set_items(([
"table" : "This table can easily seat twelve people, and maybe sixteen in a pinch.  It is long and oval in shape and made from the redwood tree.",
"lion" : "This carved base is supporting the huge oval table upon the back of a life like lion.  His mane and tail support the furthest ends, while his back supports the major section of the table.",
"chairs" : "Tall backed chairs stuffed with horsehair surround the table.  The backs are carved with lions and tigers.  Truly a remarkable sight.",
"goblets" : "The goblets are wrought of silver and have lions etched upon them.",
"earthenware dishes" : "These dishes are made from a type of pale blue clay and have scenes of the jungle painted in detail upon them.",
"cutlery" : "Knives, forks and spoons made of bright metal accompany the dishes.",
"draperies" : "Pale rose draperies cover the porthole windows to shut out the cool night air and the bright sunlight during the day.",
"windows" : "Porthole windows covered by drapes are on both north and west walls.  They look out into the cool forest."
]) );
}
