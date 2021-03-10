#include <std.h>
#include <objects.h>

inherit ROOM;
int opened;
object ob;


void create() {
    room::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange but interesting objects.  The tunnel abluntly
ends here.  The walls are dark and covered with disgusting slime mold
from the many decades of sewage that flowed within here.
    ");
    set_exits(([
       "north" : "/d/dragon/sewer/sewer24"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_search("default","%^GREEN%^You search the nasty human waste and find a small lever within the south wall.");
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
  opened = 0;
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
    if(opened){
      write("%^RED%^The lever has been pulled down already.");
      return 1;
    }
    tell_room(ETP, "%^GREEN%^\n"+TP->query_cap_name()+" pulls a lever that was located within the south wall down.",TP);
    if(roll_dice(1,20) > TP->query_stats("dexterity")) {
      write("With your unluck, the floor below you falls.");
      if(!TP->move("/d/dragon/sewer/fall1"))
        environment(TP)->start_slide();
      return 1;
    }
    write("%^GREEN%^\nYou reveal a hidden passage to the east.");
    add_exit("/d/dragon/sewer/sewer26","east");
    ob = find_object_or_load("/d/dragon/sewer/sewer26");
    ob->add_exit("/d/dragon/sewer/sewer25","west");
    call_out("back",60);
    opened = 1;
    return 1;
  }
  if(str == "lever up") {
    if(!opened){
      write("%^RED%^The lever has been pulled up already.");
      return 1;
    }
    ob = find_object_or_load("/d/dragon/sewer/sewer26");
    ob->remove_exit("west");
    ob->add_exit("/d/dragon/sewer/sewer27","east");
    write("%^GREEN%^You pull the lever back into place.");
    say("%^GREEN%^"+TP->query_cap_name()+" pulls the lever back to the upward position.");
    remove_exit("east");
    opened = 0;
    return 1;
  }
  else if(str == "lever") {
    tell_object(TP,"It appears as though the lever can be pulled up or down.");
    return 1;
    }
  write("what is it that you would like to pull?");
  return 1;
}

void back(){
  remove_exit("east");
  ob = find_object_or_load("/d/dragon/sewer/sewer26");
  ob->remove_exit("west");
  tell_room(TO,"%^GREEN%^The lever moves back to its original place automatically.");
  opened = 0;
}
