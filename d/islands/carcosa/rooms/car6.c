inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are standing on the Isle of Carcosa.
You can see a river in the distance to the north and the fork 
is now to youe south.
LUCIFER
);
  set_smell("default","The smell of rotting flesh overwhelms your senses.");
  set_listen("default","You hear the chanting louldly now.");
  set_listen("chanting","Religous chanting fills your head.\n"+
             "You find it hard to ignore.\n");
  set_exits((["north":"/d/islands/carcosa/rooms/car7.c",
              "south":"/d/islands/carcosa/rooms/car5.c"]));
  }
     
