inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_property("indoors",1);
set_short("Banquet hall");
set_long(
@MILT
You enter the keep's banquet hall.  Once fabled to house the greatest
banquets in this part of the realms, this enormous hall could easily hold
over one hundred guests.  With a gigantic fireplace taking up one of the
walls and iron chandeliers, some still hanging on the ceiling, this hall
was a safe haven from the cold and cruel wilderness outside.
MILT
);
}
