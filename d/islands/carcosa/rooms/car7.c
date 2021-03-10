inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are standing on the Isle of Carcosa.
This path is well lit and seems to head towards water.
The fork in the road is still visible to the south.
LUCIFER
);
  set_smell("default","The smell of rotting flesh overwhelms your senses.");
  set_listen("default","You hear the chanting louldly now.");
  set_listen("chanting","Religous chanting fills your head.\n"+
             "It seems to be coming from the north.\n");
  set_exits((["north":"/d/islands/carcosa/rooms/car8.c",
              "south":"/d/islands/carcosa/rooms/car6.c"]));
  }
     
