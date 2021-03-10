#include <std.h>
#include <objects.h>

int num;
inherit ROOM;

void create() {
    room::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
This is some kind of sewage pool.  No telling what many wonderous
objects could be found under the disgusting slime that's beginning to
cling to your armor.  There are no obvious exits that you know of
but you can see the sewage moving, and feel a slight current.
    ");
    set_exits(([
       "swim" : "/d/dragon/sewer/tunnel04"
    ] ));
    set_invis_exits(({"swim"}));
    set_search("default","You search around but you find nothing.");
    set_search("sewage","You search the sewage, but find nothing.");
    set_search("pool","You search the pool, but can't go deep enough to search the entire pool.");
    set_pre_exit_functions(({"swim"}),({"do_swim"}));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_smell("default","The smell of human waste is becoming overwhelming.");
    num = 0;
}

void init() {
  ::init();
  add_action("dive","dive");
}

int dive() {
  if(present("monster")) {
    write("%^YELLOW%^No matter where you run, the monster will follow you.");
    return 0;
  }
  write("You take a deep breath and dive underwater.");
  say(TP->query_cap_name()+" takes a deep breath and dives underwater.");
  this_player()->move_player("/d/dragon/sewer/underwater");
  return 1;
}

int do_swim() {
  write("%^RED%^You start swiming around through the disgusting human waste.");
  say(TP->query_cap_name()+" starts swiming through the disguesing human waste.");
  if(num == 0) {
    tell_room(environment(this_player()), "%^GREEN%^"+TP->query_cap_name()+" distrubs something resting under the water.");
    num = 1;
    return 0;
  }
  if(present("monster")) {
    write("The monster is expecting you for dinner, you cannot leave now.");
    return 0;
  }
  write("You swim around the pool for a couple of minutes and find a way out.");
  return 1;
}
