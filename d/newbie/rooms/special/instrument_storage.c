#include "../../newbie.h"
inherit ROOM;

void create(){
   ::create();
   set_properties((["light":1,"indoors":1,"no teleport":1]));
   set_short("Offestry Instrument Storage");
   set_long("Offestry Instrument Storage. Supplies are all around but you shouldn't be here.  Report to a wiz if you are please.");
}

void reset(){
   ::reset();
   if(!present("case 2")) new(INSTRUMENT"instrument_case")->move(TO);
   if(!present("case 2")) new(INSTRUMENT"instrument_case")->move(TO);
   if(!present("flute")) new(INSTRUMENT"flute")->move(TO);
   if(!present("lyre")) new(INSTRUMENT"lyre")->move(TO);
   if(!present("harmonica")) new(INSTRUMENT"harmonica")->move(TO);
   if(!present("handbells") && random(2)) new(INSTRUMENT"handbell")->move(TO);
   if(!present("bones")) new(INSTRUMENT"bones")->move(TO);
   if(!present("fiddle")) new(INSTRUMENT"fiddle")->move(TO);
   if(!present("lute")) new(INSTRUMENT"lute")->move(TO);
   if(!present("pipes")) new(INSTRUMENT"panpipes")->move(TO);
   if(!present("drum")) new(INSTRUMENT"drum")->move(TO);
}
