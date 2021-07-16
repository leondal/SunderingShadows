#include <std.h>
inherit ROOM;

void retrieve_brick(string str);
int key_wait;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The Sitting Room");
  set_long("%^RESET%^%^CYAN%^This sitting room is very cozy looking. There is a %^BOLD%^%^BLACK%^fireplace%^RESET%^%^CYAN%^ here with a nice %^RED%^w%^ORANGE%^a%^RED%^rm fi%^ORANGE%^r%^RED%^e%^RESET%^%^CYAN%^ burning in it, and there is some very comfortable %^MAGENTA%^furniture%^RESET%^%^CYAN%^ all about you. There are a few paintings on the walls, but there is one especially %^BOLD%^strange painting%^RESET%^%^CYAN%^ hanging over the mantel. You notice an open %^ORANGE%^door%^RESET%^%^CYAN%^ to the south.\n");
  set_smell("default", "You smell the wood burning in the fireplace.");
  set_listen("default", "You hear the crackling of the fire and soft whispers in this room.");
  set_items( ([
     "fireplace" : "It is made of %^RED%^bricks %^RESET%^... hmmm, one of the bricks looks a bit out of place.",
     "brick" : "Looks like you could retrieve it.",
     "painting" : "This painting appears to be a portrait of 3 sisters - 3 very DEFORMED and UGLY sisters. You find yourself praying they are not the owners of this place. This painting looks so life like, it's almost like you could enter it..."
]) );
  set_exits( ([
     "east" : "/d/koenig/town/house2",
     "enter" : "/d/koenig/town/sister",
     "south" : "/d/koenig/town/house7"
]) );
  set_invis_exits(({"enter"}));
  set_pre_exit_functions(({"enter"}),({"go_enter"}));
  key_wait = 0;
}
void init()
{
  ::init();
  add_action("retrieve_brick", "retrieve");
}
int retrieve_brick(string str)
{
  object brick;
  if(str != "brick" || key_wait != 0)
  return 0;
  if(present("small golden key",TP))
{
  write("You find nothing more here.\n");
  say(TPQCN+" is snooping about for something more.");
  return 1;
}
  key_wait = 1;
  new("/d/koenig/town/items/goldkey.c")->move(this_player());
  new("/d/koenig/town/items/paper2.c")->move(this_player());
  say(TPQCN+" has found a small key.\n");
  write("%^GREEN%^You find a small %^RESET%^%^BOLD%^%^YELLOW%^golden key %^RESET%^%^GREEN%^from inside the fireplace where the brick was.");
  return 1;
}
  void reset()
{
  ::reset();
  if(key_wait != 0)
  key_wait--;
}

int go_enter() {
  say(TPQCN+" %^CYAN%^looks disbelievingly at the painting and then vanishes before your very eyes!");
  write("%^CYAN%^You enter the painting and become part of it. You now battle for your very life against the 3 sisters!");
  set_items(([
    "painting":"It is a portrait done of 3 sisters - 3 very DEFORMED and UGLY\n"+
               "sisters who appear to be fighting "+this_player()->query_cap_name()+". You find yourself praying\n"+
                "they are not the owners of this place."
  ]));
  return 1;
}
