inherit "/std/room";

void create() {
  ::create();
  set_property("indoors", 0);
  set_property("light", 3);
  set_short("WaterHaven, Main Street");
  set_long("The main street of WaterHaven stretches out to the north and south before\n"+
           "you. To the north and south the street reaches out farther.\n"+
           "Along the west and east, shops line the roads.");
  set_listen("default","You hear the sounds of a busy city.");
  set_exits(([ "south":"/d/darkwood/waterhaven/street2" ]));
}

