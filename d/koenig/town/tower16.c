#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_door("door","/d/koenig/town/os1.c","door","open_door");
    set_open("door",0);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Hallway");
  set_long("%^BOLD%^%^WHITE%^You now stand in a short hallway. There are %^RESET%^%^ORANGE%^stairs%^BOLD%^%^WHITE%^ leading "
           "up and a door that leads outside. Oddly enough there are not many "
           "decorations of any kind here. The only thing that decorates the "
           "wall is a %^RESET%^lone %^BOLD%^%^MAGENTA%^tapestry%^BOLD%^%^WHITE%^.%^RESET%^\n");
  set_smell("default", "The scent of flowers is strong here.");
  set_listen("default", "Oddly enough there is only silence here.");
  set_items( ([
     "tapestry" : "You see a beautiful maiden sitting by a clear pool of "
                  "water in the middle of a meadow full of wild flowers. " 
                  "In the background you see snow capped mountains, and "
                  "to your horror you see a shadowy figure lurking up behind "
                  "her with a dagger posed to strike a killing blow!",
      "door" : "It is about two feet thick and made of solid wood. On its "
               "surface a delicate design of climbing ivy has been carved.",
     "figure" : "You can make out no details for it is cloaked in darkness.",
     "flowers" : "The flowers blaze with all the colors of the rainbow.",
     "dagger" : "Very wicked looking and deadly...it appears to have something "
                "already dripping from it...poison maybe?"
]) );
  set_pre_exit_functions( ({"door"}),({"go_door"}) );
  set_exits( ([
     "west" : "/d/koenig/town/tower15",
     "door" : "/d/koenig/town/os1",
     "up" : "/d/koenig/town/tower17"
]) );
}
void init() {
  ::init();
  add_action("look_maiden", "look");
}
int look_maiden(string str) {
  if(!str || str != "maiden") return 0;
  say("You see "+TPQCN+" look closely at the maiden in the tapestry and disappears before your very eyes!");
  write("As you look more closely at the maiden something begins to happen...");
  write("The maiden raises her eyes to look deep into your own...");
  write("You can not seem to move...");
   write("There is a look of sadness as you gaze into the maiden's eyes...");
  write("You feel compelled to comfort her...");
  write("%^BOLD%^%^RED%^With a sudden shift in reality you find yourself standing next to the clear pool, but now the maiden is gone!");
  set_items( ([
     "tapestry" : "You see "+TPQCN+" standing in the middle of a meadow full of wild flowers. In the background there is a grave, and further back you see snow capped mountains. Lurking just behind "+TPQCN+" is a shadowy figure with a dagger!"
]) );
  TP->move_player("/d/koenig/town/maiden");
  return 1;
}
int go_door() {
  if(present("butler")) {
   write("Lurch blocks your path and glares at you balefully!");
  say("Lurch blocks "+TPQCN+"'s path!");
  return 0;
}
  return 1;
}
void reset()
{
  ::reset();
  if(!present("butler"))new("/d/koenig/town/mon/butler.c")->move(this_object());
}
