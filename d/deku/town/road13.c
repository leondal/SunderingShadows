//removed pre-exit message since it doesn't fit now 
//(not sure when it did actually) *Styx* 4/11/02
#include <std.h>
inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^");
    set_long(
"%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^
%^ORANGE%^You are at the entrance to the peaceful town of %^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^. Before you stands the entrance %^CYAN%^gate%^ORANGE%^. Two large woo%^GREEN%^den door%^ORANGE%^s stand open welcoming all adventures within its city walls. Toward the east stands the %^BOLD%^%^BLACK%^dark, shadowy forest%^RESET%^%^ORANGE%^. Through the gate, the town within looks alive.%^WHITE%^
"
    );
    set_exits(([
       "west" : "/d/deku/town/road8",
     "east" : "/d/deku/forest/dforest15-5",
    ] ));
    set_door("wooden gates","/d/deku/town/road8", "west");
	set_string("wooden gates", "open","%^MAGENTA%^The gates swing "+
    "slowly open.%^RESET%^");
	set_locked("wooden gates",0);
    set_open("wooden gates",1);
	set_door_description("wooden gates","%^MAGENTA%^These wooden "+
    "gates are made from several slabs of %^BOLD%^%^GREEN%^oak"+
    "%^MAGENTA%^ that have been tightly bound together with a thick "+
    "and course rope.%^RESET%^");
 
    set_items(([
    ] ));
    
    if(!present("guard")) 
    {
        new("/d/deku/monster/gguard")->move(TO);
        new("/d/deku/monster/gguard")->move(TO);
    }
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/deku/monster/gguard")->move(TO);
    new("/d/deku/monster/gguard")->move(TO);
  }
}

