#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's foyer");
    set_long("A pair of massive and ornately carved doors open from the outdoors into this foyer of the mansion.  Along the east wall is a walk-in closet for coats and cloaks.  A large, thick, hand-woven rug covers the floor at the entrance to catch any moisture or dirt tracked in as well as being quite decorative with its colorful geometric design.  The %^ORANGE%^rich walnut paneled walls %^RESET%^and %^ORANGE%^highly waxed parquet flooring %^RESET%^provide an impressive introduction to the high quality of materials used throughout the interior.\nThe focal point of the room is a magnificent spiral staircase to the south that rises to the upper floors.  Hanging from the ornamental ceiling far above are two half-globe stained glass lighting fixtures that light the staircase and the foyer."
 );
    set_listen("default","You hear the buzz of conversation all about.");
    set_smell("default","You smell a mixture of perfumes and pipe smoke.");
    set_items(([
      ({"fixtures", "lighting fixtures", "fixture" }) : "The stained glass "
         "of the lamps "
         "is in a starburst pattern and the rich colors make even the palest "
         "colors or complexions seem to glow.",
      "ceiling" : "%^CYAN%^The ceiling is tiled with sections of tin that have "
         "been pounded or pressed to create snowflake-like patterns."
    ] ));
    set_exits(([
//       "dining" : "/d/guilds/fist/mansion/dining",       
       "up" : "/d/guilds/fist/mansion/staircase1",
       "out" : "/d/dagger/Torm/city/c98",
       "west" : "/d/guilds/fist/mansion/ghall",
    ] ));
   set_door("door","/d/dagger/Torm/city/c98","out");
   set_locked("door",0);
   set_door_description("door", "These massive doors are solid walnut and "
      "have been intricately carved with scenes of sea dragons, nymphs, and "
      "other creatures of lore and legend.  Heavy brass hinges, knobs, and "
      "hardware are burnished to a soft lustre.");
  set_string("door","open","The massive walnut doors swing open soundlessly.");
  set_string("door","close","The massive walnut doors close solidly.");
}