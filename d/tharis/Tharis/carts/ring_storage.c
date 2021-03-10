#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;
void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set("short", "perfume dealer's cart");
    set("long", "Supplies and such are stored here.\n");
}
void reset() {
object ob;
::reset();
	while(ob = present("perfume")){
		ob->remove();
	}
	new("/d/tharis/obj/rings/kp.c")->move(TO);
	new("/d/tharis/obj/rings/de.c")->move(TO);
	new("/d/tharis/obj/rings/sg.c")->move(TO);
	new("/d/tharis/obj/rings/hj.c")->move(TO);
	new("/d/tharis/obj/rings/so.c")->move(TO);
}
