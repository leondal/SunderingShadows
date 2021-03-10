#include <std.h>
#include <objects.h>

inherit "/std/vault";

void create() {
    vault::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange but interesting objects.  This section of the
tunnel ends here.  The walls are black and covered with disgusting 
slime mold from the many decades of sewage that has flowed within here.
    ");
    set_exits(([
       "down" : "/d/dragon/sewer/sewer41",
       "west" : "/d/dragon/sewer/sewer29"
    ] ));
    set_items(([
        "sewers":"The disgusting tunnels of wast under Sanctuary.",
      "grate" : (: this_object(), "look_at_grate" :)
    ] ));
    set_search("default","You search through the human waste and find a closed grate under the water.");
    set_open("grate", 0);
    set_locked("grate", 1);
    set_invis_exits(({"down"}));
    set_property("no teleport", 1);
    set_door("grate","/d/dragon/sewer/sewer41","down",0);
     set_string("grate","open","You open the grate leading further into the sewers.");
    set_pre_exit_functions(({"down"}),({"go_down"}));
}

void look_at_grate() {
  if(query_open("grate")) {
    write("The grate is old and rusty.  It is under the human waste and slime.");
    write("The grate is open.");
  } else {
    write("The grate is old and rusty.  It is under the human waste\nIt is closed.");
  }
}

void reset() {
  ::reset();
  if(!present("neo-otyugh")) {
    new("/d/dragon/mon/neo")->move(this_object());
  }
}

int go_down() {
  if(present("neo-otyugh")) {
    write("%^RED%^The many tenticles of the Neo-otyugh blocks your attempt to go down.");
    return 0;
  }
  return 1;
}
