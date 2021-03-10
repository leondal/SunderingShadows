#include <std.h>
#include "/d/common/common.h"
inherit ROOM;

void create(){
   ::create();
   set_properties((["light":1,"indoors":1,"no teleport":1]));
   set_short("Shadow Instrument Storage");
   set_long("Shadow Instrument Storage. Supplies are all around but you
shouldn't be here.  Report to a wiz if you are please.");
   set_exits(([ "up" : ROOM"bardguild" ]));
}

void reset(){
   ::reset();
   if(!present("case 2")) new(COBJ"instruments/instrument_case")->move(TO);
   if(!present("case 2")) new(COBJ"instruments/instrument_case")->move(TO);
   if(!present("flute")) new(COBJ"instruments/flute")->move(TO);
   if(!present("lyre")) new(COBJ"instruments/lyre")->move(TO);
   if(!present("bones")) new(COBJ"instruments/bones")->move(TO);
   if(!present("fiddle")) new(COBJ"instruments/fiddle")->move(TO);
   if(!present("lute")) new(COBJ"instruments/lute")->move(TO);
   if(!present("pipes")) new(COBJ"instruments/panpipes")->move(TO);
   if(!present("drum")) new(COBJ"instruments/drum")->move(TO);
   if(!present("guitar")) new(COBJ"instruments/guitar")->move(TO);
   if(!present("harmonica")) new(COBJ"instruments/harmonica")->move(TO);
}
