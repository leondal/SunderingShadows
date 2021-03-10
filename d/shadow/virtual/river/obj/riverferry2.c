// ferry for inland river by Styx 5/2003
#include <std.h>

inherit "/d/shadow/virtual/river/obj/riverferry1";

void create() {
   ::create();
   set_long("This is a ferry boat that carries travelers, for a fee "
	"of course.  A sign over the boarding ramp shows the cost for "
	"this ferry ride is a mere %^YELLOW%^"+price+" gold pieces.  "
	"%^RESET%^Once you <%^BOLD%^buy ticket for "+ticket+"%^RESET%^>, "
	"you will board this ferry for that route.  "
	"The sign on this one identifies it as running between Shadow and Tabor.");
   ferryroom = find_object_or_load("/d/shadow/virtual/river/obj/r_ferryroom2");
}
