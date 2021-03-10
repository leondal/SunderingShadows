#include <std.h>
inherit VAULT;

string time;

void move_stone(string str);
void push_stone(string str);

int key_wait;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_door("gate","/d/koenig/town/grave1.c","gate","black death key");
    set_open("gate",0);
    set_locked("gate",1);
    set_string("gate","open","%^BOLD%^%^BLACK%^The gate noisily opens making you think it could "
                             "wake the dead.");
    set_string("gate","close","%^BOLD%^%^BLACK%^The gate eerily closes without a sound.");
    set_string("gate","unlock","%^BOLD%^%^BLACK%^The lock tumblers stick.  Then with a loud, "
                               "echoing click, it unlocks.");
    set_string("gate","lock","%^BOLD%^%^BLACK%^The tumblers click easily back into place.");
  set_property("light",1);
  set_property("indoors",0);
  set_short("The Streets of Muileann");
  set("day long", "%^RESET%^%^ORANGE%^The strange, ominous %^BOLD%^%^BLACK%^tower%^RESET%^%^ORANGE%^ stands to your south, but your way is still blocked by that fence. Although this tower makes your body tremble, it also makes you very curious to know what lies within. Looking about, you also notice that you are standing before the gates of a %^BOLD%^%^BLACK%^graveyard%^RESET%^%^ORANGE%^. The %^RESET%^gate%^RESET%^%^ORANGE%^ is rather interesting.%^RESET%^\n");
  set("night long", "%^RESET%^%^BLUE%^This really isn't the time to be dawdling about, adventurer. There are too many things in this town that feel wrong and make your skin %^BOLD%^crawl%^RESET%^%^BLUE%^, and your blood %^BOLD%^chill%^RESET%^%^BLUE%^. The fence continues to block your path to the tower to the south, and for that you should be grateful. The %^BOLD%^%^BLACK%^graveyard%^RESET%^%^BLUE%^ stands to your north. Which will you choose?%^RESET%^\n");
// added the following to the gate descript; the object in the room doesn't show up as the door settings override. N, 3/11.
    set_door_description("gate","The gate stands within a huge stone %^RED%^arch %^RESET%^that has %^RED%^pillars %^RESET%^to each side...the %^RED%^gate %^RESET%^itself is of wrought iron and very plain...");
  set_items( ([
     "tower" : "It raises towards the heavens as if in defiance, it looks "
               "very cold, dark, and ominous. Makes you wonder what could "
               "possibly bear to live in such a place!",
     "fence" : "This fence stands roughly 8 feet tall with lots of spikes "
               "running along the top. There is no way over that you "         
               "can see.",
     "gate" : "The gate stands within a huge stone %^RED%^arch %^RESET%^"
              "that has %^RED%^pillars %^RESET%^to each side. The " 
              "%^RED%^gate %^RESET%^itself is of wrought iron and very "
              "plain...",
     "arch" : "The arch almost appears to be one solid piece of stone that "
              "has been cut and placed here. It makes you wonder who or what "
              "moved it here. An 8-foot %^RED%^wall %^RESET%^runs east and "
              "west to either side of it.",
     "wall" : "Someone of great talent laid the stones for this " 
              "wall... hmmm, is that a loose %^RED%^stone%^RESET%^?",
     "pillars" : "On each pillar there sits a %^RED%^gargoyle%^RESET%^.",
     "gargoyle" : "One looks as if about to spring but the other seems "     
                  "almost friendly, different as night and day.",
    "stone" : "Hmmm this one stone looks very loose...maybe you can "
              "push or move it aside."
]) );
  set_smell("default", "You smell death and decay.");
  set_listen("default", "You hear the wind and the soft whimper of a child.");
  set_listen("whimper", "The whimpering sounds of the child appear to come from within the graveyard.");
  set_exits( ([
     "west" : "/d/koenig/town/room5",
     "gate" : "/d/koenig/town/grave1"
]) );
  key_wait = 0;
}
void init()
{
  ::init();
    add_action("move_stone", "move");
    add_action("push_stone","push");
}
  int move_stone(string str)
{
  object stone;
  if(str != "stone" || key_wait != 0)
  return 0;
    if(present("black death key",TP))
{
tell_object(this_player(), "You find nothing else.\n");
tell_room(environment(TP),TPQCN+" is awful silly, they are searching for another one.", TP);
  return 1;
}
  key_wait = 1;
new("/d/koenig/town/items/cryptkey.c")->move(this_object());
tell_object(this_player(), "You find a strange key.");
tell_room(environment(TP),TPQCN+" has found a strange key behind the loose stone.", TP);
  return 1;
}

int push_stone(string str)
{
  object stone;
  if(str != "stone" || key_wait != 0)
  return 0;
    if(present("key",TP))
{
    tell_object(this_player(),"You find nothing else.\n");
    tell_room(environment(TP),TPQCN+" is awful silly, they are searching "
              "for another one.",TP);
  return 1;
}
    key_wait = 1;
    new("/d/koenig/town/items/cryptkey.c")->move(this_object());
    tell_object(this_player(),"You find a strange key.");
    tell_room(environment(TP),TPQCN+" has found a strange key.",TP);
  return 1;
}

void reset()
{
  ::reset();
  if(key_wait != 0)
    key_wait--;
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight" || time == "night")
    if(!present("hyena2"))
        new("/d/koenig/town/mon/hyena2.c")->move(this_object());
}
