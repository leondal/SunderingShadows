#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, dining room");
set_long ("%^GREEN%^In total contrast to the kitchen the dining room is immaculate.  A long dining <table> covered with snowy white <linen> and set with a <service> for eight graces the middle of the room.  Artfully carved <chairs> surround the table, and <sconces> give off a glow of warmth and welcome.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nSubtle odours of cinnamon and cardomon fill the air from the sconces.");
set_listen ("default", "You can still hear the sound of a wooden flute, haunting and soulful.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomH4c",
"east" : "/d/dagger/Elvanta/forest/roomH4a",
"southeast" : "/d/dagger/Elvanta/forest/roomH4",
"up" : "/d/dagger/Elvanta/forest/roomH4j"
]) );
set_items(([
"table" : "A table made of finest birch, gleaming white with years of polish graces this room",
"linen" : "Snowy white linen with cutwork of lilies and anthurium lays upon the table waiting to be admired.",
"service" : "Unlike the cutlery in the kitchen, this cutlery is shining with polish, and patterned after columnea vines.  'Tis a wonder to behold.  The plates, goblets and decanters also reflect the owners love of plants as roses and marigolds entwine to complete the service.",
"chairs" : "Chairs carved a lifetime ago, with reeds and grasses as the basic pattern add to the grace of this room.",
"sconces" : "Wall sconces with teardrop candles are the lighting for this room.  Both a warmth of light and the smell of home are given off by the sconces.  The sconces themselves are a metalsmiths work of art molded into wild roses."
]) );
}
