#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Moirbin Castle, Throne Room");
set_long("%^GREEN%^You travel down a long red carpet looking around you.  Courtiers of every size, shape and race fill the room.  Silver, crystal, carved wooden pieces and clothwork hangings gleam in the light of the oil lamps and candles.  The room is bright and cheerful full of noise and laughter.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nCandle wax, perfume, flower fragrances and burning scented oils fill the air.");
set_listen("default", "%^CYAN%^Laughter, music, and a general hub bub of people talking arises from the room.%^RESET%^");
set_exits( ([
"east" : "/d/dagger/Elvanta/forest/roomcastle6",
"south" : "/d/dagger/Elvanta/forest/roomcastle8"
]) );
set_items(([
"carpet" : "%^GREEN%^This richly coloured carpet comforts your weary feet.  Each step is like stepping into a cloud of warm wool.",
"wolf" : "The sculpture shows a large silver grey wolf laying upon her side with three small pups nuzzling.  Two other pups seem to be playing hide and seek behind her haunch.  The sculpture is most life like and the details exquisite",
"elven archer" : "An archer stands approximately twelve inches tall.  He is dressed in forest browns and greens.  One arm is fully extended holding a long bow, while the other draws back the bow string.  His grey eyes seem intent upon some distant target.  His lithe body seems as taut as the string he pulls.",
"dragons" : "A sculpure three feet high and four feet long grabs your attention.  A group of dragons is before you.  An old black dragon with silver underwings and the eyes of ages past, sits upon a rock.  Five or six young dragons, bronze, blue, red, green and amber range just below him.  It appears he is telling stories and their cats eyes shimmer with delight.  You wish you too could sit at the old Ones' feet.",
"hawk" : "How the sculpture managed to catch the haughty yet fiercesome demeanor of the hawk you cannot comprehend.  Every feather upon the hawk and the very stance which he has taken screams out arrogance and pride.",
"whales" : "Your eyes fill with joy and wonder as you look upon Orca whales flying through the waves.  Great spumes appear behind the whales as a tail slaps the water.  Blue green water carresses a mother and calf while a male looks upon them with pride.",
"statues" : "Statues of long forgotten heroes and heroines sit upon every other pillar.  Some seemed to be resting in comfort under trees of gold, and yet some are forever captured in battle.",
"pillars" : "Each pillar is a pale green colour, standing approximately four feet high, and two feet in diameter.  Each one has either a sculpture or a bowl of flowers placed upon it."
]) );
}
void reset() {
::reset();
if(!present("armour"))
new("/d/dagger/Elvanta/forest/mon/armour")->move(this_object());
if(!present("dragon horse"))
new("/d/dagger/Elvanta/forest/mon/dragon_horse")->move(TO);
}
