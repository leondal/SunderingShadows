#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Castle Moirbin, Throne Room");
set_long("%^CYAN%^The vast doors are covered with beaten gold and they swing ponderously open to reveal an enormous, domed hall.  Since the dome is higher than surrounding structures, the illuminateion in the room comes through inch-thick crystal windows high overhead.  The hall is of suitably stupendous dimensions and the expanses of mother of pearl white is broken by accents of crimson and gold.  Heavy red velvet draperies hang at intervals along the glowing walls, flanking columnar buttressess.
The buttressess are inlaid with gold.  A wide avenue of crimson carpet leads from the huge doors to the foot of the throne.  The room is filled with people, the two most important being, the King and Queen of Elvanta, His Majesty Daffyd Strongarm, and his wife Mauveen Evenstar.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe faint odour of jasmine and sandlewood mixes in the air, refreshing your weary senses.%^RESET%^");
set_listen ("default", "%^GREEN%^The falling of the fountain waters soothes the mind and body.");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomcastle7",
"south" : "/d/dagger/Elvanta/forest/roomcastle4"
]) );
set_items(([
"carpet" : "%^BLUE%^This rich royal blue carpet has been woven by artists of the highest talent.  The colour grabs your eyes while enmeshing your feet in the softest wool.  Your feet thank you.%^RESET%^",
"chandelier" : "%^YELLOW%^Light is cast in rainbow hues from this chandelier, a hundred candles burn forever, reflected through and by the crystalline drops of tears.%^RESET%^"
]) );
}
void reset() {
::reset();
if(!present("herald"))
new("/d/dagger/Elvanta/forest/mon/herald")->move(this_object());
}
