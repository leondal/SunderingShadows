// Pator@ShadowGate
// Jan 16th 1997
// The top of the Ptalkin belltower which holds an Admin Bell

#include "/d/shadow/room/shadow.h"
#include "/d/ptalkin/ptalkin.h"

inherit ROOM;
void create() {
    ::create();
      set_property ("light", 2);
      set_property("indoors", 0);
      set_short("The chamber high in the belltower");
      set_long(
@PATOR
%^ORANGE%^
You are standing in the chamber high up in the bell tower.  When you look
out you get a nice scenic view of the Ptalkin area. You see that the
bell tower is well kept, but that every thing is covered with a thick
layer of dust.
PATOR
);
      set_exits( ([
		"down" : PROOM+"belltower3.c"
		   ]) );
      set_items( ([
	"staircase" : "Large, sturdy, covered with dust  and made out of oak",
	"belltower" : "High, nice and it holds an Admin Bell",
	"dust"      : "It covers everything in thick layers",
	"view"	    : "You get a pretty scenic view of the Ptalkin area."
		  ]) );
      set_smell("default", "You smell the dust lying on the staircase");
      set_listen("default", "You hear just the usual rushing of the wind through the belltower");
}

init() {
	::init();
	if (!present("admin_bell")) {
	   new("/d/shadowgate/arch/bell.c")->move(this_object()); } }

reset() {
	::reset();
        if (!present("admin_bell")) {
           new("/d/shadowgate/arch/bell.c")->move(this_object()); } }

