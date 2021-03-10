#include <std.h>
#include <objects.h>

inherit "/std/vault";

void create() {
    vault::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange but interesting objects.  This section of the
tunnel ends here.  The walls are black and covered with disgusting 
slime mold from the many decades of sewage that has flowed within here.
    ");
    set_exits(([
       "down" : "/d/dragon/sewer/tunnel01",
       "south" : "/d/dragon/sewer/sewer19"
    ] ));
    set_items(([
        "sewers":"The disgusting tunnels of wast under Sanctuary.",
      "grate" : (: this_object(), "look_at_grate" :)
    ] ));
  set_smell("default","%^GREEN%^The smell of waste is overwhelmingly potent within this tunnel.");
    set_search("default","You search through the human waste and find a closed grate under the water.");
    set_open("grate", 0);
    set_locked("grate", 1);
    set_invis_exits(({"down"}));
    set_door("grate","/d/dragon/sewer/tunnel01","down",0);
     set_string("grate","open","You open the grate leading further into the sewers.");
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
  if(!present("neootyugh")) {
    new("/d/dragon/mon/neo1")->move(this_object());
    new("/d/dragon/mon/neo1")->move(this_object());
  }
}
