#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Moirbin Castle, a balconey");
set("day long", "%^GREEN%^Made of polished green granite, the balconey looks out upon the city of Elvanta.  The city looks to be laid out in a spiral of verdant green.  Flashes of bright colours fly by as birds of wonderous hues take wing.");
set("night long", "%^GREEN%^Made of polished green granite, the balconey looks out upon the city of Elvanta.  The city looks to be a jewel set upon green velvet with facets of twinkling and flashing lights which dot the city.");
set_smell("default", "%^MAGENTA%^The air is filled with the scent of a thousand flowers and the heady scent of pine");
set_listen("default", "%^CYAN%^Sounds of laughter, song and cheer rise up from below.");
set_exits( ([
"east" : "/d/dagger/Elvanta/forest/roomcastle6b",
"south" : "/d/dagger/Elvanta/forest/roomcastle8b",
"southeast" : "/d/dagger/Elvanta/forest/roomcastle9b"
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
