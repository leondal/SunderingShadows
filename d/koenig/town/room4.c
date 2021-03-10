#include <std.h>
inherit ROOM;

string time;
  object drunk;


void create() {
//  object ob;  removing ooc boards and ones that have outlived their usefulness *Styx*  4/15/03
  ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  set_property("light",1);
  set_short("The Streets of Muileann");
  set("day long", "%^ORANGE%^You have traveled down the street towards the %^BOLD%^%^BLACK%^ominous%^RESET%^%^ORANGE%^ tower. Your way to the east is blocked by an intricatly designed %^BOLD%^%^BLACK%^wrought iron fence%^RESET%^%^ORANGE%^ that stands roughly 8 feet high and has many %^RESET%^spikes%^RESET%^%^ORANGE%^ up top. There is definately no way over it. The street continues both north and south, or you could always leave the way you came.\n%^RESET%^");

  set("night long", "%^RESET%^%^BLUE%^Setting eyes upon the %^RESET%^tower%^RESET%^%^BLUE%^ and the %^RESET%^fence%^RESET%^%^BLUE%^ that guards it by night is like looking at a scene from one of your own %^BOLD%^nightmares%^RESET%^%^BLUE%^. You can hear someone %^RESET%^weeping%^RESET%^%^BLUE%^ and the sound of creaking %^ORANGE%^wheels%^RESET%^%^BLUE%^ to your south.\n%^RESET%^");
  set_items( ([
			"tower" : "Its looming prescence casts a shadow over the small town.",
           "street" : "The street is filthy and makes you glad to have boots.",
           "fence" : "%^RESET%^The fence is of black wrought iron, and its %^BOLD%^design%^RESET%^ is most mysterious.",
           "design" : "The design is both delicate and twisted. It makes you wonder if it reflects the individual residing in the tower."
]) );

  set_smell("default","You can smell the stench of death strongly here.");
  set_listen("default","You can hear insects and odd laughter from the tower.");
/*

  ob = new(BBOARD);
  ob->set_name("board");
  ob->set_id( ({"board","opinions"}) );
  ob->set_board_id("Opinions");
  ob->set_max_posts(30);
  ob->set_location("/d/koenig/town/room4");
  ob->set("short","Opinion Board");
  ob->set("long","On this board you can state your opinions of this area and even give some helpful ideas or suggestions.");
*/

  set_exits( ([
     "north" : "/d/koenig/town/room5",
     "south" : "/d/koenig/town/room6",
     "west" : "/d/koenig/town/room1"
]) );
}
void reset()
{
  ::reset();
  time = "daemon/events_d"->query_time_of_day();
  if(time == "dawn" || time == "day")
  if(!drunk)
{
  drunk = new("/d/koenig/town/mon/drunk2.c");
  drunk->move(TO);
  }
}
