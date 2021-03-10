#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long(
      "%^CYAN%^You are on the road along the cliffs that edge the seacoast of dagger.  Directly to the north, you can see an impressive fortress and just beyond it, the Yniam plains and the strange wall that protects the city of Tonovi.  To the northeast you can see the seaport of Torm quite well, and a little further to the north the town of Daggerdale.  To the east you can see the cliffs where they meet the ocean.  A little bit up the road you can see where the cliffs end and the beaches line the seacoast.  A lone statue stands by the roadside here, as if standing eternal watch over those who pass.  It is formed as a man clad in heavy steel plate armor with his features hidden behind a visor, and his greatsword point-downwards to touch the ground at his feet."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"cliffs" : "You can see the ocean below the great granite cliffs.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road9",
	"northeast" : RPATH "road11",
      ]) );
}
