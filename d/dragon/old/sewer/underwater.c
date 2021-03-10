#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
You are swimming through human waste.  It's very dark within these
disgusting waters, making it very hard to see underwater.  You believe if
you open your eyes, the waste could cause you to become blind.
    ");
    set_exits(([
       "up" : "/d/dragon/sewer/pool"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
//    set_search("default", (: this_object(), "ball" :));
    set_post_exit_functions(({"up"}),({"go_up"}));
//     set_search("sewage",  (: this_object(), "ball" :));
//    set_search("pool",    (: this_object(), "ball" :));
}

void init() {
  ::init();
   if(wizardp(TP)) return;
  if(present("sack",TP)) {
    write("%^GREEN%^\nYou are able to breath underwater.");
    return 1;
  }
  write("%^GREEN%^\nYou cannot swim underwater for long, cause you cannot breath underwater for long.");
tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" cannot swim underwater, so "+TP->query_subjective()+" must swim to the surface before "+TP->query_subjective()+" dies.",TP);
  this_player()->do_damage("torso", roll_dice(2,6));
  this_player()->move_player("/d/dragon/sewer/pool");
  return 1;
}

void ball() {
  object ob;
  write("You manage to search the pool and find a crystal ball.");
  remove_search("default");
  remove_search("sewage");
  remove_search("pool");
  new("/d/dragon/obj/misc/Cryball")->move(this_object());
}

int go_up() {
  tell_room(ETP, "%^GREEN%^"+TP->query_cap_name()+" comes out from under the water, with sewage and human waste all over "+TP->query_possessive()+" face.",TP);
  return 1;
}
