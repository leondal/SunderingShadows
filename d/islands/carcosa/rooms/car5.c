inherit "/std/room.c";

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set("short","The Isle of Carcosa");
  set("long",
@LUCIFER
You are standing on the Isle of Carcosa.
You can see that the main trail splits in three directions from this
point.  Each path looks as if it will put you on a dark mountain 
trail.  Of all the trials, the east one looks the most traveled as
you can make out faint footprints and discoloration in the rocks.
The trail to the north look like it leads to water and the trial to
the northeast quickly winds out of sight.
LUCIFER
      );
  set_smell("default","The smell of rotting flesh overwhelms your senses.");
  set_listen("default","You hear the chanting louldly now.");
  set_listen("chanting","Religous chanting fills your head.\n"+
             "From here you think it is coming from the north.\n");
  set_exits((["north":"/d/islands/carcosa/rooms/car6.c",
              "south":"/d/islands/carcosa/rooms/car4.c",
	      "west":"/d/islands/carcosa/rooms/car10.c",
	      "northeast":"/d/islands/carcosa/car17.c"]));
  }
     
