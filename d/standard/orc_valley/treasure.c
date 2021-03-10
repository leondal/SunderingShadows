#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_smell_string("default", "It smells very musty in here.");
    set("short", "Treasury of the Valley Orcs");
    set("long",
        "This small vault where the orc of the valley keep their "
        "treasure is poorly lit and littered with dust, making you well "
        "aware that the orcs willingly allow anyone in here.");
    set_items(
        (["vault" : "It is very, very dimly lit."]) );
    set_exits( (["south" : "/d/standard/orc_valley/shaman"]) );
    set_no_clean(1);
    set_property("no teleport", 1);
}

void reset() {
    ::reset();
      if(!present("chest")) 
	new("d/standard/obj/misc/chest")->move(this_object());
      if(!present("chest")->receive_objects()) 
	present("chest")->toggle_closed();
      if(!present("orcslayer", present("chest")))
        new("d/standard/obj/weapon/orc_slayer")->move(present("chest"));
      present("chest")->toggle_closed();
}
