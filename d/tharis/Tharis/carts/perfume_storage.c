//updated by Circe 1/9/05 with new products.
#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;
void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set_short("perfume dealer's cart");
    set_long("Supplies and such are stored here.\n");
}
void reset() {
::reset();
  if(!present("perfume")){
		new("/d/tharis/obj/perfume.c" )->move(TO);
		new("/d/tharis/obj/perfume.c" )->move(TO);
		new("/d/tharis/obj/perfume.c" )->move(TO);
	}
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
