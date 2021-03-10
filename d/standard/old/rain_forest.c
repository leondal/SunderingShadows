inherit "std/room";

void create() {
  ::create();
    set_property("light", 1);
    set("short", "Deep in the rain forest");
    set("long",
	"You are deep inside a tropical rain forest.");
    set_items(
	([ "forest" : "A very humid jungle away from civilization."]) );
    set_exits( 
	      (["southwest" : "/d/standard/jungle",
		"east" : "/d/jungle/jungle1"]) );
}

