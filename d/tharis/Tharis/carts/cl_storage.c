inherit "std/room";
#include <std.h>
#include <objects.h>
void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
        set("short","A storage room for the clothery.");
    set("long", "clothes are stored here.\n");
    set_exits( (["up" : "/d/shadow/room/gs_store"]) );
}
void reset() {
::reset();           
	if(!present("gloves"))
		new("/d/tharis/obj/clothing/gloves.c")->move(TO);
	if(!present("hose"))
		new("/d/tharis/obj/clothing/hose.c")->move(TO);
	if(!present("pants"))
		new("/d/tharis/obj/clothing/pants.c")->move(TO);
	if(!present("cloak of good cloth"))
		new("/d/tharis/obj/clothing/plcloak.c")->move(TO);
	if(!present("sandals"))
		new("/d/tharis/obj/clothing/sandals.c")->move(TO);
	if(!present("shoes"))
		new("/d/tharis/obj/clothing/shoes.c")->move(TO);
	if(!present("tunic"))
	new("/d/tharis/obj/clothing/tunic.c")->move(TO);
}
