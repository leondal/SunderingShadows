inherit "std/room";
#include <std.h>
#include <objects.h>
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
        set("short","A storage room for the clothery.");
    set("long", "clothes are stored here.\n");
    set_exits( (["up" : "/d/shadow/room/gs_store"]) );
}
void reset() {
::reset();           
	if(!present("embroidered robe"))
		new("/d/tharis/obj/clothing/erobe.c")->move(TO);
	if(!present("fur cloak"))
		new("/d/tharis/obj/clothing/fcloak.c")->move(TO);
	if(!present("girdle"))
		new("/d/tharis/obj/clothing/girdle.c")->move(TO);
	if(!present("gloves"))
		new("/d/tharis/obj/clothing/gloves.c")->move(TO);
	if(!present("hose"))
		new("/d/tharis/obj/clothing/hose.c")->move(TO);
	if(!present("pants"))
		new("/d/tharis/obj/clothing/pants.c")->move(TO);
	if(!present("cloak of good cloth"))
		new("/d/tharis/obj/clothing/plcloak.c")->move(TO);
	if(!present("riding boots"))
		new("/d/antioch/antioch2/obj/riding_boots")->move(TO);
	if(!present("sandals"))
		new("/d/tharis/obj/clothing/sandals.c")->move(TO);
	if(!present("short boots"))
		new("/d/antioch/antioch2/obj/short_boots")->move(TO);
	if(!present("shoes"))
		new("/d/tharis/obj/clothing/shoes.c")->move(TO);
	if(!present("jacket"))
		new("/d/tharis/obj/clothing/sjacket.c")->move(TO);
	if(!present("tunic"))
	new("/d/tharis/obj/clothing/tunic.c")->move(TO);
}
