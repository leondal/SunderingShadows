inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long","You are stading on the path leading north from the dock.\n"+
      "The atmosphere seems to become more forboding as you venture onward.\n"+
      "Sharp rock formations close the path in on either side and block much of the light.\n"+
      "The path continues to the north and south.\n");
    
    set_smell("default","The smell of rotting flesh overwhelms your senses.");
    set_listen("default","You hear the chanting more clearly now.");
    set_listen("chanting","Religous chanting of the likes you have never heard before.");
    

  set_items((["path":"The path is more used than you would expect.\n",
    ({"rock","rocks","mountains"}):"The rocks are unnaturally jagged.\n"]));
  set_exits((["north":"/d/islands/carcosa/rooms/car4.c",
	      "south":"/d/islands/carcosa/rooms/car2.c"]));
  }
     
