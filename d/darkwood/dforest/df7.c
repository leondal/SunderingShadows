#include <std.h>
#include <dirs.h>
inherit ROOM;
void look_fork(string str);
int fork_wait;
    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"You suddenly come to a fork in the road. "
"Amazingly you stand stunned because it IS a Giant FORK! "
"The giant fork stands upright in the middle of the path. "
"To the west you can see nothing but trees here and there, but "
"to the southeast, the trees get thicker. "
"A light breeze nips at you and although it's not cold, it still "
"chills you to the bone. You are beginning to get curious about "
"whats in store next.\n"
);
    set_exits( ([
                "southeast" : "/d/darkwood/dforest/df8",
                "southwest" : "/d/darkwood/dforest/df6",
                 "west" : "/d/darkwood/dforest/df11",
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You hear the shuffle of little feet deep behind the trees.");
fork_wait = 0;
}
void init()
{
  ::init();
add_action("lookatfork", "look");
}
int lookatfork(string str)
{
  object fork;
if (str != "at fork" || fork_wait !=0)
  return 0;
if(present("fork"))
    {
     tell_object(this_player(),"Dont you think one was enough? \n");
  tell_room(environment(TP),TPQCN+" has lost their mind, they are searching
the path for more GIANT FORKS! RUN AAAWWAAAYYY!!",TP);
     return 1;
}
  fork_wait = 1;
  new("/d/darkwood/dforest/mon/fork.c")->move(this_object());
  tell_object(this_player(), "A Giant Fork charges towards you and attempts to SPORK you!!");
  tell_room(environment(TP),TPQCN+" looks at the fork and taunts it!",TP);
  return 1;
}

void reset()
{
  ::reset();
  if(fork_wait != 0)
    fork_wait--;
}

