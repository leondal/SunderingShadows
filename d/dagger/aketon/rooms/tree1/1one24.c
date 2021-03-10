#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Aketon Tobacco Shop");
   set_long("%^BOLD%^Aketon Tobacco Shop%^RESET%^
The shop is dimmly lighted by some candles. Everything here is in dark "
      "colour compared to other shops in this city. There is a cabin with "
      "numerous small drawers arranged in matrix form to the far end of "
      "shop. Before it is a wooden counter with a small candle on top of "
      "it. Very little customers are visiting the shop, yet those here "
      "looks enjoying a stay and picking up many packs of tobaccos.");
   set_items( (["candles":"They are supported by many candlesticks here "
      "and lighten up the shop.",
      "cabin":"You see numerous small drawers arranged in matrix form in "
      "the cabin.",
      "drawers":"They must be used to store tobaccos.",
      "counter":"It is made of rose wood. A small candle is on top of it.",
      "candle":"It is on top of the counter. It lights up the counter for "
      "customers to look clearly at the tobaccos they are choosing.",
      "customers":"Not many of them are here. They looks enjoy a stay "
      "here and purchase a whole many of tobaccos each."]) );
   set_smell("default","Strong tobacco odors impairs your senses.");
   set_smell("tobacco","Your senses are impaired by the strong odor, yet "
      "you can still smell the sweet smell of tobaccos.");
   set_listen("default","It is relatively quiet here.");
   set_exits( (["west":RPATH1+"1one23"]) );
}

void reset() {
   ::reset();
   if( !present("vathodouse") )
      new(MPATH+"vathodouse")->move(TO);
}
