#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Castle Moirbin, The Entrance Hall");
set_long("%^CYAN%^Welcome to the Castle Moirbin.  It is the crowning jewel of the city of Elvanta.  As you look around, you see the room is oval in shape and has royal blue carpet covering the floor.  You look and see sculptures lining the walls in niches and a crystal chandelier lit by a hundred candles, everbright, reflected by and through crystal teardrops.  Curved settees line the walls, covered in pale blue damask.  In the centre of the room stands a fountain, rising and falling to a tune unheard.
%^CYAN%^The fountain waters play with lights of deep green, blue and amber, and just as you think you have the rhythm to the play of waters, it changes.  A gentle perfume fills the air, and as you breathe deeply of the pleasant odour a sense of peace and contentment fills your body and soul.  You realize you have reached a place of sanctuary for the mind and heart.");
set_smell ("default", "%^MAGENTA%^\nThe faint odour of jasmine and sandlewood mixes in the air, refreshing your weary senses.%^RESET%^");
set_listen ("default", "%^GREEN%^The falling of the fountain waters soothes the mind and body.");
set_exits( ([
"east" : "/d/dagger/Elvanta/forest/roomcastle2",
"west" : "/d/dagger/Elvanta/forest/roomgarden16"
]) );
set_items(([
"carpet" : "%^BLUE%^This rich royal blue carpet has been woven by artists of the highest talent.  The colour grabs your eyes while enmeshing your feet in the softest wool.  Your feet thank you.%^RESET%^",
"wolf" : "The sculpture shows a large silver grey wolf laying upon her side with three small pups nuzzling.  Two other pups seem to be playing hide and seek behind her haunch.  The sculpture is most life like and the details exquisite",
"elven archer" : "An archer stands approximately twelve inches tall.  He is dressed in forest browns and greens.  One arm is fully extended holding a long bow, while the other draws back the bow string.  His grey eyes seem intent upon some distant target.  His lithe body seems as taut as the string he pulls.",
"dragons" : "A sculpure three feet high and four feet long grabs your attention.  A group of dragons is before you.  An old black dragon with silver underwings and the eyes of ages past, sits upon a rock.  Five or six young dragons, bronze, blue, red, green and amber range just below him.  It appears he is telling stories and their cats eyes shimmer with delight.  You wish you too could sit at the old Ones' feet.",
"hawk" : "How the sculpture managed to catch the haughty yet fiercesome demeanor of the hawk you cannot comprehend.  Every feather upon the hawk and the very stance which he has taken screams out arrogance and pride.",
"whales" : "Your eyes fill with joy and wonder as you look upon Orca whales flying through the waves.  Great spumes appear behind the whales as a tail slaps the water.  Blue green water carresses a mother and calf while a male looks upon them with pride.",
"chandelier" : "%^YELLOW%^Light is cast in rainbow hues from this chandelier, a hundred candles burn forever, reflected through and by the crystalline drops of tears.%^RESET%^"
]) );
}
void reset() {
::reset();
if(!present("guard"))
new("/d/dagger/Elvanta/forest/mon/castleguard")->move(this_object());
}
