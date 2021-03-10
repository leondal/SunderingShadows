#include <std.h>
#include "../dragon.h";

inherit BSEWER;
int opened;
object ob;


void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange but interesting objects. The tunnel abluntly"+
      " ends here. The walls are dark and covered with disgusting slime mold"+
      " from the many decades of sewage that flowed within here."
    );
    set_exits(([
       "north" : SEWER"sewer24"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary.",
       "lever":"This lever can be pulled up or down."
    ] ));
    set_search("default","%^RESET%^%^GREEN%^You search the nasty human waste and find a small lever within the south wall.");
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
    write("%^RESET%^%^GREEN%^\nYou reveal a hidden passage to the east.");
    add_exit(SEWER+"sewer26","east");
    opened = 1;
    return 1;
  }
  if(str == "lever up") {
    if(!opened){
      write("%^RED%^The lever has been pulled up already.");
      return 1;
    }
    write("%^RESET%^%^GREEN%^You pull the lever back into place.");
    say("%^RESET%^%^GREEN%^"+TP->query_cap_name()+" pulls the lever back to the upward position.");
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

void reset() {
   ::reset();
   if(!present("quaggoth")) {
   new(MON+"quaggoth")->move(TO);
}
}
