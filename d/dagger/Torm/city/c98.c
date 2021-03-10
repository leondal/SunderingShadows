//closed off the doors at Godzilla's request.  This will be temporary until renovations are complete. Tsera
#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void create()   {
  ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
  set_property("light",2);
  set_short("Gateway of a great Mansion");
  set_long(
  "Gateway of a great Mansion.\n"
  "  You stand at the gateway of a great mansion.  The grounds along the "
  "cobblestone path are now well manicured, the bushes and trees carefully "
  "pruned, and even the ivy on the walls seems to have been trimmed.  The "
  "carvings on the massive %^ORANGE%^walnut doors %^RESET%^and the %^YELLOW%^"
  "gleaming brass hardware %^RESET%^speak of both fine workmanship and a pride "
  "in ownership."
  );
  set("night long",
  "%^BLUE%^"
  "The fog creeps up against the doors of this huge "
  "mansion but light shines from within.  The grounds along the "
  "cobblestone path are now well manicured, the bushes and trees carefully "
  "pruned, and even the ivy on the walls seems to have been trimmed.  The "
  "carvings on the massive %^ORANGE%^walnut doors %^BLUE%^and the %^YELLOW%^"
  "gleaming brass hardware %^RESET%^%^BLUE%^speak of both fine workmanship and a pride "
  "in ownership."
  );
  set_smell("default", "You smell salt in the air from the Dagger Sea and the "
    "aroma of fine cooking from inside.");
  set_listen("default", "The waves of the sea wash against the docks.");
  set_items(([
  "mansion" : "The mansion beyond the gates is incredibly large and"+
  " impressive.  There seems to be a great deal of activity going on inside"
  " and in the city nearby.",
  "gates" : "The gates are made of thick wrought iron with some sort of a"+
  " family crest or something in the center.  They would be almost impossible"+
  " to bend.  They stand open for all visitors.",
  "walls" : "The walls around the mansion are incredibly high, reaching over"+
  " thirty feet in height.  They are made out of carefully cemented stone bricks"+
  " and there appear to be spikes on the top of the walls.  You can just see"
  " the top floor of the mansion above them.",
  "fog" : "The fog has settled around the grounds of the mansion."+
  "  Although it avoids the building itself, it blankets most of the grass.",
  "doors":"The doors have been barred shut with a small sign running across them reading: %^BOLD%^Temporarily closed for renovations",
  ]));
  set_exits(([
  "northeast":TCITY+"c10",
  "southwest": "/d/guilds/fist/mansion/entry",
  ]));
   set_door("door","/d/guilds/fist/mansion/entry","southwest");
  set_locked("door",0);
   set_door_description("door", "These massive doors are solid walnut and have been intricately carved with scenes of sea dragons, nymphs, and other creatures of lore and legend.  Heavy brass hinges, knobs, and hardware are burnished to a soft lustre.");
  set_string("door","open","The massive walnut doors swing open soundlessly.");
  set_string("door","close","The massive walnut doors close solidly.");
}
