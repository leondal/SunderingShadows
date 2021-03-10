// Pator@ShadowGate
// Jan 17th 1997
// /d/ptalkin/room/belltower1.c
#include "/d/shadow/room/shadow.h"
#include "/d/ptalkin/ptalkin.h"
inherit "/std/room";

void create() {
    ::create();
      set_property ("light", 2);
      set_property("indoors", 0);
      set_short("The Elven Church of Ptalkin");
      set_long(
@PATOR
%^ORANGE%^
You stand at the start of a large winding staircase going up.
High up in the belltower you see an Admin Bell which you can ring
if you need help from an administrator. It is a long way up though.
PATOR
);
      set_exits( ([
		"up" : PROOM+"belltower2.c",
		"south" : PROOM+"church"
		   ]) );
      set_items( ([
	"staircase" : "Large, sturdy and made out of oak",
	"belltower" : "High, nice and it holds an Admin Bell"
		  ]) );
	set_smell("default", "You smell the incense from the church");
      set_listen("default", "You hear just the usual rushing of the wind through the belltower");
}
