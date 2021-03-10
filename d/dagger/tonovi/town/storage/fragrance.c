//storage room for Tonovi.  Circe 12/29/04
#include <std.h>
#include "../../short.h"
inherit ROOM;

#define TABOR "/d/darkwood/tabor/obj/"+

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Tobacco Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/dagger/tonovi/town/bazaar5"]));
}

void reset()
{
object obj;
	::reset();
if(!present("blushing laughter") && !random(2))
 new(TABOR"blushing_laughter")->move(TO);
if(!present("joyful heart"))
 new(TABOR"joyful_heart")->move(TO);
if(!present("spice of the soul") && !random(2))
 new(TABOR"spice_of_the_soul")->move(TO);
if(!present("enraptured gaze"))
 new(TABOR"enraptured_gaze")->move(TO);
if(!present("tharis perfume"))
 new("/d/tharis/obj/perfume")->move(TO);
if(!present("tharis perfume 2"))
 new("/d/tharis/obj/perfume")->move(TO);
if(!present("citrus perfume"))
 new("/d/dagger/Torm/obj/perfume")->move(TO);
  if(!present("dryad's essence") && !random(3))
   new("/d/tharis/obj/dryad_essence")->move(TO);
  if(!present("istishia's refreshing rains") && !random(3))
   new("/d/tharis/obj/ishy_rains")->move(TO);
  if(!present("lathander's renewal") && !random(3))
   new("/d/tharis/obj/lathander_renewal")->move(TO);
  if(!present("moon's radiance") && !random(3))
   new("/d/tharis/obj/moon_radiance")->move(TO);
  if(!present("oghma's rhapsody") && !random(3))
   new("/d/tharis/obj/oghma_rhapsody")->move(TO);
  if(!present("satyr's charm") && !random(3))
   new("/d/tharis/obj/satyr_charm")->move(TO);
  if(!present("waters of the tide") && !random(3))
   new("/d/tharis/obj/water_tide")->move(TO);
  if(!present("secrets of shar") && !random(3))
   new("/d/tharis/obj/secret_shar")->move(TO);
}
