#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Sewers under Sanctuary");
    set_long(
      "%^BOLD%^%^BLACK%^This is a oval tunnel, being supported by some massive round columns."+
      " The tunnel is faintly illuminated by lichen that clings to the walls,"+
      " columns, and ceiling."
    );
    set_exits(([
      "north" : SEWER+"sewer34",
      "east" : SEWER+"sewer37",
      "west" : SEWER+"sewer36",
      "south" : SEWER+"sewer39"
    ] ));
    set_items(([
    ] ));
    set_property("no teleport", 1);
}

void reset(){
   ::reset();
   if(!present("quaggoth")) {
      new(MON+"quaggothlead")->move(TO);
   }
}

