// Pator@ShadowGate
// Jan 17th 1997
// /d/ptalkin/room/belltower3.c
#include "/d/shadow/room/shadow.h"
#include "/d/ptalkin/ptalkin.h"
inherit "/std/room";

void create() {
    ::create();
      set_property ("light", 2);
      set_property("indoors", 0);
      set_short("The staircase in the Ptalkin Belltower");
      set_long(
@PATOR
%^ORANGE%^
You are on a winding staircase leading up into the belltower. When
you have a better look you see dust covering everything. You see the 
Ptalkin church below you and an Admin Bell above you. 
PATOR
);
      set_exits( ([
		"up" : PROOM+"belltower4.c",
		"down" : PROOM+"belltower2.c"
		   ]) );
      set_items( ([
	"staircase" : "Large, sturdy, covered with dust  and made out of oak",
	"belltower" : "High, nice and it holds an Admin Bell",
	"dust"      : "It covers everything in thick layers"
		  ]) );
      set_smell("default", "You smell the dust lying on the staircase");
      set_listen("default", "You hear just the usual rushing of the wind through the belltower");
}
