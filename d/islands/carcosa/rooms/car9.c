inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
Standing on the river bank, you can see off to the northeast a 
large black temple.  As far as you can tell, it is the source of 
the chanting.  There is a large log spanning the river here.
LUCIFER
);
  set_smell("default","The smell of rotting flesh overwhelms your senses.");
  set_listen("default","You barely hear chanting over the river.");
  set_listen("chanting","Religous chanting fills your head.\n"+
             "It is coming from the black temple.\n");
 set_items((["river":"The river is too wide and fast moving for you to swim across, but there is a log that you might be able to use as a bridge.\n","log":"The log seems sturdy enough th cross.\n"]));
  set_exits((["log":"/d/islands/carcosa/rooms/river3.c",
              "south":"/d/islands/carcosa/rooms/car8.c"]));
  }
     
