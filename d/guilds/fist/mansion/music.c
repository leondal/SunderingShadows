#include <std.h>
//add action for a musician to begin playing?  Add a minstrel randomly?
//catch_tell some of the music & send it to the dining room?

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's music room");
    set_long( "Ornate plaster wall panels, a %^BOLD%^wh%^YELLOW%^i%^WHITE%^te ma%^YELLOW%^r%^WHITE%^b%^YELLOW%^l%^WHITE%^e %^RESET%^hearth with gold veining, and elegant enameled %^GREEN%^lighting fixtures %^RESET%^distinguish this room.  The %^ORANGE%^lattice-patterned parquet floor %^RESET%^is meticulous in its workmanship and exquisite in its beauty.  A raised dais of %^ORANGE%^hand worked oak %^RESET%^sets the stage for the bards that come from near and far to enjoy the ambiance and entertain the hopefully rich and generous guests."
    );
    set_listen("default","You hear snippets of conversation between "
       "songs and stories.");
    set_smell("default","Delicious smells drift in from the dining room.");
    set_items(([
      ({ "stage", "dais" }) : "The dais is raised about three ft. and has a "
         "set of steps set in one side for the performers easy ascent.  "
         "It runs the length of one wall and is over ten ft. deep so that a "
         "whole orchestra or troupe of entertainers could perform at once.",
      "fixtures" : "The lighting fixtures are thin metal, cut and shaped into "
         "elegantly ornate designs of vines and flowers.  Etched glass globes "
         "and reservoirs for the oil lamps they hold not only light the room "
         "but colored oils enhance and provide a focal point to the floral "
         "designs.  The enamel "
         "paint has been hand-rubbed to a soft, but rich patina that picks up a "
         "soft glow from the light.",
    ] ));
    set_exits(([
       "dining" : "/d/guilds/fist/mansion/dining",
       "northeast" : "/d/guilds/fist/mansion/ghall",
       "library" : "/d/guilds/fist/mansion/library",
    ] ));
//   set_door("door","/d/guilds/fist/mansion/ghall","hall");
   set_door("pocket door","/d/guilds/fist/mansion/dining","dining");
   set_door_description("pocket door","This is actually a pair of doors that "
     "suspend from rollers in tracks in the ceiling rather than hanging on "
     "hinges to swing as most do.  The walls to each side "
     "are hollow and the doors simply slide inside them to open.");
  set_string("pocket door","open","The pocket doors slide smoothly aside into "
     "the spaces inside the walls.");
  set_string("pocket door","close","The pocket doors slide smoothly out from "
     "the space inside the walls to close the room off from the next.");
}
