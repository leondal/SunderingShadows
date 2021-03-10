#include <std.h>
inherit ROOM;

int bloodrose_wait;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",0);
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^As you walk along here you see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining the fence here. Their "+
"fragrance is %^MAGENTA%^sweet%^RESET%^%^GREEN%^ and %^MAGENTA%^alluring%^RESET%^%^GREEN%^. It makes you want to get closer to smell "+
"them, or maybe even try to %^BOLD%^pick%^RESET%^%^GREEN%^ one.%^RESET%^\n");
  set_listen("default", "You can hear the wind rustle the leaves and roses gently.");
  set_smell("default", "You can smell the sweet fragrance of roses here.");
  set_smell("roses","So sweet and very alluring...you have a desire to pick one.");
  set_items( ([
     "bushes" : "The dominating color of rose here is black.",
     "rose" : "You take a closer look and notice that there are tints of red in the black colored roses."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os3",
     "west":"/d/koenig/town/os5"
]) );
  bloodrose_wait = 0;
}

void init()
{
  ::init();
    add_action("pick_rose","pick");
}

int pick_rose(string str)
{
    object rose;
    if(str != "rose" || bloodrose_wait != 0)
    return 0;
    if(present("bloodrose",TP))
{
    tell_object(this_player(),"There isn't one to pick.");
    tell_room(environment(TP),TPQCN+" looks for another rose to pick but "
              "cant find one.",TP);
    return 1;
}
    bloodrose_wait = 1;
    new("/d/koenig/town/mon/blkbloodrose.c")->move(this_object());
    tell_object(TP,"You go to pick a rose and are attacked by the bush!");
    tell_room(environment(TP),TPQCN+" goes to pick a rose and is attacked "
              "by the rosebush!",TP);
    return 1;
}

void reset()
{
  ::reset();
    if(bloodrose_wait != 0)
    bloodrose_wait--;
}
