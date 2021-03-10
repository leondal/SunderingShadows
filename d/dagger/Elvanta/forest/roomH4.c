#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a home");
set_long ("%^GREEN%^As you step inside this home, the first thing to catch your attention is the <plants>.  They are covering every surface available.  A warm and inviting room.  Comfortable <chairs> are placed in front of a <fireplace> with small <tables> beside the chairs.  <Candles>, <books> and sheets of <music> lay scattered.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nExotic perfume fills the air.");
set_listen ("default", "You hear soft music being played upon a wooden flute.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomH4a",
"west" : "/d/dagger/Elvanta/forest/roomH4d",
"east" : "/d/dagger/Elvanta/forest/room57",
"northwest" : "/d/dagger/Elvanta/forest/roomH4b",
"up" : "/d/dagger/Elvanta/forest/roomH4j"
]) );
set_items(([
"plants" : "Brilliant red anthurium, bold yellow conophytums, orange, burgundy and yellow hibiscus, vines of passion flowers, columnea and exacum affine are a few of the well tended plants",
"chairs" : "Straight backed chairs are placed in front of and to the side of the fireplace.  Cushions of bold reds, blue and green cover the chairs.",
"fireplace" : "A small well constrcuted fireplace of orange stone takes up the centre of the west wall.",
"candles" : "Candles of graceful teardrop shapes, star shapes and bowl shapes lend a dreamy quality to the room.",
"tables" : "Rounds tables, perhaps three feet in diameter are scattered throughout the room and have many colourful plants placed on them.",
"books" : "The books cast around the room are of an odd combination.  Books on weapons and armour vie for space with books on music and composers.",
"music" : "Yellowed sheets of hand written music with notations added add to the mystique of this room."
]) );
}
