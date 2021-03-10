#include <std.h>
#include <objects.h>

inherit "/std/vault";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
This is a large oval chamber somewhere within the sewers under the
city of Sanctuary.  Faintly luminescent lichen clings to the walls,
reflecting lightly off the water that occasionally drip from the 
high ceiling.  Two flaming sphere hover above a large wooden desk 
that sits along the northern wall, while toward the east beside the
stone wall sits a circle of stone rocks.
    ");
    set_exits(([
       "south" : "/d/dragon/sewer/sewer49"
    ] ));
    set_items(([
       "desk":"The large wooden desk, looks as if someone or something has\n"+
              "been working here lately.",
       "circle of stone":"There are about 12 rough cut stones layed out to\n"+
                         "form a circle.",
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_search("desk",  (: this_object(), "book" :));
    set_property("no teleport", 1);
    set_smell("default","The rotting smell of waste is very strong in these tunnels.");
  set_door("door","/d/dragon/sewer/sewer49","south","dsewer_key");
  set_open("door",0);
  set_locked("door",1);
}

void init() {
  ::init();
  add_action("stand", "stand");
  add_action("stop_stab", "stab");
}

int stand(string str) {
  if(!str) {
    tell_object(this_player(), "You stand.");
    return 1;
  }
  if(str != "in circle") {
    tell_object(this_player(), "You stand "+str+".");
    return 1;
  }
  tell_room(ETP, "%^GREEN%^Some green smoke rises from the stone as "+TP->query_cap_name()+" begins to fade out of existance.");
  tell_room(ETP, "\n\n");
 call_out("go_stone", 10);
  return 1;
}

void go_stone() {
  write("%^RED%^You notice that your existance has been moved to somewhere within the sewers.\n\n");
  TP ->move_player("/d/dragon/sewer/sewer13");
}

void stop_stab(object ob) {
  if(ob == "toris" || ob == "mage" || ob == "magician" || ob == "Toris") {
    write("What! Are you trying to stab me foolish mortal.");
    return 1;
  }
}

void reset() {
  if(!present("toris")) {
    new("/d/dragon/mon/s_mage")->move(this_object());
  }
}

void book() {
  if(present("toris")) {
    tell_room(ETP, "%^MAGENTA%^The magician says: %^RESET%^So you want to search through my things will you.  Stupid "+TP->query_race()+"!");
    return 1;
  }
  tell_room(ETP, "%^YELLOW%^"+TP->query_cap_name()+" searches the desk and finds a old book.");
  new("/d/dragon/obj/misc/book")->move(this_player());
  remove_search("desk");
  return 1;
}
