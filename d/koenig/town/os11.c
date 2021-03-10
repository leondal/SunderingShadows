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
  set_long("%^RESET%^%^GREEN%^You can see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ to the east and west of here, and further beyond "+
"%^BOLD%^bushes%^RESET%^%^GREEN%^ trimmed into the shapes of animals. However, where you stand now is "+
"like nothing you have ever seen in your %^BOLD%^%^BLACK%^worst nightmares%^RESET%^%^GREEN%^. Before you here "+
"stands a very large %^ORANGE%^misshapen tr%^GREEN%^e%^ORANGE%^e%^RESET%^%^GREEN%^. You didn't realize how misshapen and "+
"horrifying it was until you stood before it. It stands very tall, but it bears "+
"no leaves, and its fruit turns your stomach: %^BOLD%^%^BLACK%^Heads%^RESET%^%^GREEN%^ hang from this "+
"tree and you can hear each one softly keen for help. Around the base of the "+
"tree you see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ and in front of that stands a %^BOLD%^%^BLACK%^stone altar%^RESET%^%^GREEN%^ that "+
"that looks to be stained by much %^RED%^blood%^RESET%^%^GREEN%^ from the sacrifices made here. Your "+
"mind is beside itself to give this place some form of reason. You have heard "+
"tales of such trees, and all this time you thought they were just tales.%^RESET%^\n");
  set_listen("default", "The soft keening is loudest here.%^RESET%^");
  set_listen("keening","The source of the keening comes from the heads hanging on the tree.");
  set_smell("default","The air smells foul with death and the fragrance of roses.");
  set_smell("roses","Its fragrance is sweet and appealling, even here. Hard to believe, but you still desire to pick one.");
  set_items( ([
     "bushes":"These rose bushes surround the base of the tree and the most dominating color of rose here is red.",
     "rose":"You take a closer look and notice that there are tints of a lighter shade of red in the blood red roses."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os12",
     "west":"/d/koenig/town/os10"
]) );
  bloodrose_wait = 0;
}

void init() {
  ::init();
  add_action("pick_rose","pick");
}
int pick_rose(string str) {
  object rose;
  if(str != "rose" || bloodrose_wait != 0)
  return 0;
  if(present("bloodrose",TP))
{
  tell_object(this_player(),"You cant pick one now.");
  tell_room(environment(TP),TPQCN+" searches for a rose to pick but cant find one.", TP);
  return 1;
}
  bloodrose_wait = 1;
  new("/d/koenig/town/mon/redbloodrose.c")->move(this_object());
  tell_object(this_player(),"%^BOLD%^%^RED%^You go to pick a rose and are attacked by the rosebush!");
  tell_room(environment(TP),TPQCN+" goes to pick a rose and is attacked by the rosebush!", TP);
  return 1;
}
void reset() {
  ::reset();
  if(bloodrose_wait != 0)
  bloodrose_wait--;
}