#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_long("%^GREEN%^A hallway within the castle,  large enough to hold the fountain that appears in front of you, tinkling to music you cannot hear.");
set_property("light", 2);
set_property("indoors", 1);
set_short("Castle Moirbin, Entrance to Throne Room");
set_smell ("default", "%^MAGENTA%^\nThe faint odour of jasmine and sandlewood mixes in the air, refreshing your weary senses.%^RESET%^");
set_listen ("default", "%^GREEN%^The falling of the fountain waters soothes the mind and body.");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomcastle6",
"south" : "/d/dagger/Elvanta/forest/roomcastle4",
"up" : "/d/dagger/Elvanta/forest/roomcastle5b"
]) );
set_items(([
"carpet" : "%^BLUE%^This rich royal blue carpet has been woven by artists of the highest talent.  The colour grabs your eyes while enmeshing your feet in the softest wool.  Your feet thank you.%^RESET%^",
"chandelier" : "%^YELLOW%^Light is cast in rainbow hues from this chandelier, a hundred candles burn forever, reflected through and by the crystalline drops of tears.%^RESET%^"
]) );
}
void reset() {
::reset();
if(!present("guard"));
new("/d/dagger/Elvanta/forest/mon/castleguard")->move(this_object());
if(!present("fountain"))
new("/realms/svaha/items/fountain")->move(TO);
}
