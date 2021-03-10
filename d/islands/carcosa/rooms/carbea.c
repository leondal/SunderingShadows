inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",3);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are stading on the Carcosan beach under the main dock.             
Splinters of wood fall from the dock onto the sand below.
There appears to be some sort of footprints in the sand.
LUCIFER
);
  set_items((["footprints":"Large, webbed footprints lead up from the water and seem to go off to the east.\n","ladder":"This ladder leads back up to the dock.\n","dock":"You can see the rotted supports of the dock.  You feel even more insecure about standing on it!\n"]));
    set_listen("default","You hear little more than the sound of the ocean.");
    set_smell("default","The scent of the sea air pervades your senses.");
    set_exits((["ladder":"/d/islands/carcosa/rooms/car1.c",
	      "east":"/d/islands/carcosa/rooms/carbea1.c"]));
  }
     
