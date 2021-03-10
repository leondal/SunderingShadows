#include <std.h>
#include "../defs.h"
#define MAX_ITEMS 25
inherit "/std/pstore";

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_owners( ({"nienne" }));
   set_drop_storage(STORAGE"poffice");
   set_drop_deposit(150);
   set_items_allowed( ({ "letters" }) );
   set_name("Messenger's office");
   set_short("%^BLUE%^Messenger's office%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Messenger's office%^RESET%^\n"
"%^BLUE%^Walking into this room, you immediately notice how neatly arranged it is, despite the small space within.  The "
"walls are bare and made of %^BOLD%^%^BLACK%^dark st%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, and the "
"only furniture present is the long counter against the far wall, and the single chair behind it.  Behind that, shelves "
"are attached to the wall, and are filled with %^ORANGE%^books %^BLUE%^and %^WHITE%^parchm%^BOLD%^e%^RESET%^nts %^BLUE%^"
"of all kinds, tidily arranged in rows.  The shop holds no windows, nor does it seem to need them, as it has nothing on "
"display for sale, merely a small %^WHITE%^sign%^BLUE%^ with a written list, sitting upon the counter-top, and a few "
"softly gleaming pinpoints of %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire %^BLUE%^upon the wall behind it.  The "
"room itself, along with the shelving and the countertop, are partly partitioned from another section further east.  "
"A narrow doorway allows access to the street outside.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The air carries the %^BOLD%^%^BLACK%^dry s%^RESET%^ce%^BOLD%^%^BLACK%^nt %^RESET%^"
"%^ORANGE%^of parchment, reminiscent of a library.");
   set_listen("default","%^GREEN%^It is particularly %^CYAN%^q%^GREEN%^ui%^CYAN%^et %^GREEN%^in here.");

   set_items(([
     ({"wall","walls","roof","nodes","faerie fire"}):"%^BLUE%^The walls and roof of this shop are made of %^BOLD%^"
"%^BLACK%^black st%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city.  They are plain, "
"but immaculately clean, as is most else in this store.  Along the back walls, behind the counter, are several shelves "
"filled with books and paper, and just above these shelves lie several spaced nodes of %^MAGENTA%^fae%^BOLD%^r%^RESET%^"
"%^MAGENTA%^ie fire%^BLUE%^ that cast gentle light about the room.%^RESET%^",
     ({"shelves","books","parchments"}):"%^BLUE%^Behind the counter, several shelves are attached to the wall, each "
"holding a row of ordered %^ORANGE%^books %^BLUE%^and %^WHITE%^parchm%^BOLD%^e%^RESET%^nts%^BLUE%^.%^RESET%^",
	"sign":({"\n%^BOLD%^%^WHITE%^The following services are available:%^RESET%^>\n\n%^CYAN%^Message service: %^RESET%^"
"150 gold%^RESET%^\nYou may leave a message for another person, <%^YELLOW%^leave letter for [name]%^RESET%^>\nYou may also "
"pickup letters left for you, <%^YELLOW%^pickup letter%^RESET%^>\n\n",
"\n%^BOLD%^%^WHITE%^The following services are available:\n\n%^CYAN%^Message service: %^RESET%^150 gold%^RESET%^\nYou may "
"leave a message for another person, <%^YELLOW%^leave letter for [name]%^RESET%^>\nYou may also pickup letters left for you, "
"<%^YELLOW%^pickup letter%^RESET%^>\n\n","wizish"}),
   ]));
   set_exits(([
     "north":ROOMS"west2",
     "east":ROOMS"scribe",
   ]));
}

void reset(){
   ::reset();
   if(!present("clerk")) new(MON"dirzstral")->move(TO);
}
