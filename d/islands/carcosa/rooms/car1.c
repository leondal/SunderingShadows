inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",3);
  set("short","The Main dock of Carcosa");
  set("long","You are standing on the sandy dock on the Isle of Carcosa.\n"+
             "To the north you see a path cutting through the rocky terrian.\n"
  );
    set_listen("default","You hear little more than the sound of the ocean.");
    set_smell("default","The scent of the sea air pervades your senses.");
    set_items(([
    "dock" : "You see an old dock worn by both weather and time.",
    "ladder" : "There is a ladder that leads down to the beach below.",
    ]));
  set_exits((["north":"/d/islands/carcosa/rooms/car2.c",
              "ladder":"/d/islands/carcosa/rooms/carbea.c"]));
  }
     


