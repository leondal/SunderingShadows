inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_property("indoors",1);
set_short("Keep's Kitchen");
set_long(
@MILT
You step foot into the ancient kitchen of Kravor Keep.  Several millennia
have passed since this kitchen was put into use.  Once in the keep's glory
days this kitchen catered huge banquets numbering hundereds of guests.
Now all that is left are piles of charred rubble which once used to be the
keep's stone ovens and firepits.
MILT
);
}
