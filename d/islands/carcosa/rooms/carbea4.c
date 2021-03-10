inherit "/std/room.c";
string LUCIFER;
void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",3);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are stading on the coast of Carcosa.
There appears to be some sort of footprints in the sand.
LUCIFER
);
  set_items((["footprints":"Webbed footprints lead up from the water.\n"]));
    set_listen("default","You hear little more than the sound of the ocean.");
    set_smell("default","The scent of the sea air pervades your senses.");

  set_exits((["southwest":"/d/islands/carcosa/rooms/carbea3.c",
	      "northeast":"/d/islands/carcosa/rooms/carbea5.c"]));
  }
     
    void init() {
      ::init();
      do_random_encounters(({"/d/islands/carcosa/mon/crab2.c"}),60,6);
}
