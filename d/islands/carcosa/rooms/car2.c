inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",3);
  set("short","The Isle of Carcosa");
   set("long","You are stading on the path leading north from the dock\n"+
       "To the north the path leads into a moutainous area.\n"+
       "To the south you can still see the ocean.\n");
  set_items((["path":"You are suprised to see how worn this path is."]));
  set_exits((["north":"/d/islands/carcosa/rooms/car3.c",
	      "south":"/d/islands/carcosa/rooms/car1.c"]));
  }
     
    void init() {
      ::init();
      do_random_encounters(({"/d/islands/carcosa/mon/crab2.c"}),60,6);
}
     
