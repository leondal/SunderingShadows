#include <std.h>
#include <objects.h>

inherit ROOM;
int num;
object ob;


void create() {
    room::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange but interesting objects.  The tunnel abluntly
ends here.  The walls are dark and covered with disgusting slime mold
from the many decades of sewage that flowed within here.
    ");
    set_exits(([
       "west" : "/d/dragon/sewer/sewer26"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_search("default","%^GREEN%^You search the nasty human waste and find a small lever within the south wall.");
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
  num = 1;
}

void init() {
  ::init();
  add_action("pull_lever","pull");
}

int pull_lever(string str) {
  if(!str) {
    write("%^RED%^What is it that you would like to pull?");
    return 1;
  }
  if(str == "lever down") {
    tell_room(environment(TP), "%^GREEN%^\n"+TP->query_cap_name()+" pulls a lever down that located within the south wall.",TP);
    write("%^GREEN%^\nYou reveal a hidden passage to the south.");
    add_exit("/d/dragon/sewer/sewer28","south");
    ob = find_object_or_load("/d/dragon/sewer/sewer28");
    ob->add_exit("/d/dragon/sewer/sewer27","north");
    return 1;
  }
  if(str == "lever up") {
    ob = find_object_or_load("/d/dragon/sewer/sewer28");
    ob->remove_exit("north");
    ob->add_exit("/d/dragon/sewer/sewer29","south");
    write("%^GREEN%^You pull the lever back into place.");
    say("%^GREEN%^"+TP->query_cap_name()+" pulls the lever back to the upward position.");
    remove_exit("south");
    return 1;
  }
  write("What is it that you would like to pull.");
  return 1;
}

void reset() {
  ::reset();
  if(!present("neo-otyugh")) {
    new("/d/dragon/mon/neo")->move(this_object());
  }
}
