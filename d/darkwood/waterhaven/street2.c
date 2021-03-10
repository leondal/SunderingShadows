inherit "/std/room";

void create() {
  ::create();
  set_property("indoors", 0);
  set_property("light", 3);
  set_short("WaterHaven, Main Street");
  set_long("You are standing in the middle of the main street of WaterHaven.\n"+
           "This road continues north and south.");
  set_listen("default","You hear the sounds of a busy city.");
  set_exits(([ "south":"/d/darkwood/waterhaven/street1",
               "north":"/d/darkwood/waterhaven/street3" ]));
}

