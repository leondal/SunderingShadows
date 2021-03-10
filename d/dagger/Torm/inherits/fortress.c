#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_property("light",2);
  set_short("Gateway of a great Mansion");
  set_long(
  "Gateway of a great Mansion.\n"
  "  You stand at the gateway of a great mansion.  The doors stand"+
  " closed and the tall walls make you think that the residents of this"+
  " mansion are not accepting visitors.  As you look closer you notice"+
  " weeds growing up from in front of the gates and the rust on the"+
  " hinges.  Nobody has opened these in a long time."
  );
  set("night long",
  "%^BLUE%^"
  "The fog creeps up against the closed gates to the grounds of a huge"+
  " mansion.  It seems a little bit colder here, and the mansion most"+
  " definitely looks uninviting.  You can see weeds growing up around"+
  " the grounds, and the gates appear rusty."
  );
  set_smell("default",
  "You smell salt in the air from the Dagger Sea."
  );
  set_listen("default",
  "The waves of the sea wash against the docks."
  );
  set_items(([
  "mansion" : "The mansion beyond the gates is incredibly large, dark, and"+
  " ominous. If anyone even lives there, they obviously don't go out or"+
  " care to have visitors, the place couldn't possibly look more forboding.",
  "gates" : "The gates are made of thick wrought iron with some sort of a"+
  " family crest or something in the center. They would be almost impossible"+
  " to bend. You notice that rust is starting to cover the hinges on the"+
  " sides and there are a few spider webs in places. These gates obviously"+
  " haven't been opened in a long time.",
  "walls" : "The walls around the mansion are incredibly high, reaching over"+
  " ten feet in height. They are made out of carefully cemented stone bricks"+
  " and there appear to be spikes on the top of the walls.",
  "weeds" : "%^GREEN%^There are weeds growing up around the yard of the"+
  " mansion and near the gates. Obviously this place isn't taken care of"+
  " very well.",
  "fog" : "The fog has settled around the grounds of the mansion,"+
  " although it avoids the building itself, it blankets most of the"+
  " grass.",
  ]));
}
