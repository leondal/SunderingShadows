
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Museum within the Kinnesaruda fortress");
        set_long("
    This is a magnificent museum!  All around you are fine works of art and paintings.  The room is almost too busy and colorful and your eyes dance around its many intricacies and details.
    Magnificent chandeliers dangle from the ceiling and some of the paintings catch your eye.
");
       set_listen("default", "The sound of rushing water is soothing somehow.");
       set_exits(([
       "north" : "/d/attaya/tower/hall3",
       "east" : "/d/attaya/tower/hall1",
]));
       set_items(([
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "chandeliers" : "The intricate chandeliers are truely marvels.  They are phenominally crafted from gold and glass and have some of the finest details you have ever seen even in jewelry!",
    "paintings" : "There are 6 paintings on this side of the room.",
    "painting 1" : "%^GREEN%^An ancient tower stands atop a mountain overlooking a rough sea.  The night sky in the scene draws you in as the various stars, galaxies, and nebulas are exaggerated.",
    "painting 2" : "%^GREEN%^A lovely young woman strokes a white kitten from a bench in a gazebo.  She stares out of the painting at you.",
    "painting 3" : "%^GREEN%^A young man and a young woman cringe as a huge towering monster bears down upon them from a dense jungle",
    "painting 4" : "%^GREEN%^Two knights are locked in mortal combat, one holds a mace and has blood pouring from the slits in his helmet, the other with a narrow dagger seems to be grinning out at you.",
    "painting 5" : "%^GREEN%^OK, we've all seen them...  The seemingly moronic canvases of a single painted color that hang defiantly on walls in the finest museums.  Well, appearantly some moron hung one in here too...  OOOH, purple...  Purrty.",
    "painting 6" : "%^GREEN%^A dead condor lies in the rut of a wagon wheel on a muddy road.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "art" : "The works of art consist of sculptures, statues, and grand paintings.",
    "statues" : "There are a few little ones and a large one of a woman pouring water.",
    "sculptures" : "There are a few abstract sculptures here.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void reset(){
        ::reset();
    if(!present("statue"))
     new("d/attaya/tower/obj/waterstatue")->move(this_object());
}
