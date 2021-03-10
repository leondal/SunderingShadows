inherit "/std/room.c";
string LUCIFER;
void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",3);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are stading on the southern coast of Carcosa.
There appears to be some sort of footprints in the sand.
The beach continues to the east and the dock is off to the west.
LUCIFER
);
  set_items((["footprints":"Webbed footprints lead up from the water.\n"]));
    set_listen("default","You hear little more than the sound of the ocean.");
    set_smell("default","The scent of the sea air pervades your senses.");

  set_exits((["southwest":"/d/islands/carcosa/rooms/carbea2.c",
	      "northeast":"/d/islands/carcosa/rooms/carbea4.c"]));
  }
     
    void init() {
      ::init();
      do_random_encounters(({"/d/islands/carcosa/mon/crab2.c"}),60,6);
}
