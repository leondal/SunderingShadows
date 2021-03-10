inherit "/std/room";

void create() {
  ::create();
  set_property("indoors", 0);
  set_property("light", 3);
  set_short("WaterHaven, Main Street");
  set_long("You are standing on the main street of WaterHaven. It continues\n"+
           "north, to the east and west side streets branch off.");
  set_listen("default","You hear the sounds of a busy city.");
  set_exits(([ "north":"/d/darkwood/waterhaven/street2" ]));
}

