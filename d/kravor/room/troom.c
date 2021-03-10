inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_property("indoors",1);
set_short("Throne room");
set_long(
@MILT
You enter the Throne room.  As you look around this large room you notice
this room was not elaborately furnished.  You see a large throne on
one end of the room, and a large fireplace on the adjacent walls.  High
up on the walls are old broken out windows with light filtering through
the slits.
MILT
);
}
