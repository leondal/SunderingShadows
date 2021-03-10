#include <std.h>
#include "../defs.h"
inherit INH + "spiderarches";

void create()
{
    ::create();
    set_short("A non-existant room.");
    set_long("This room no longer exists.  If you're stuck here, get a wiz to move you out.");
    //set_long("" + ::query_long() + "\n");
    set_property("no teleport", 1); //cause this room technically doesn't exist anymore after Selucia collapsed the roof on it.  You shouldn't be able to TP in here.
    /*set_exits(([
                   "southwest" : UPPER "tunnel37",
                   "southeast" : UPPER "tunnel35",
               ]));*/
}

/*void reset()  //leaving this here just in case someone is curious about how it was done
   {
    ::reset();
    if (!present("altar")) {
        new("realms/odin/ashra_altar")->move(this_object());
    }
   }*/
