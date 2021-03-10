inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are stading on the Isle of Carcosa.
Just to the north you can see a river cutting across the island 
east to west.  You can walk onto the river bank from here.      
LUCIFER
      );
  set_smell("default","The smell of rotting flesh overwhelms your senses.");
  set_listen("default","You hear the chanting louldly now.");
  set_listen("chanting","Religous chanting fills your head.\n"+
             "It now seems to be coming from the northeast.\n");
  set_exits((["north":"/d/islands/carcosa/rooms/car9.c",
              "south":"/d/islands/carcosa/rooms/car7.c"]));
  }
     
