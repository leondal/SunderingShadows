
#include <std.h>

int step, num, num1;

inherit OBJECT;

void create() {
  ::create();
  set_name("wooden barrel");
  set_id(({"barrel","wooden barrel"}));
  set_short("Old wooden barrel");
  set_long("This is an old wooden barrel.  Most likely it was once used for\n"+
           "some kind of ale.  Now it seems empty, but still you cannot \n"+
           "lift it up.  It is closed.\n");
  set_weight(5000);
  set_value(5000);
  num = 7;
}

void init() {
  ::init();
  add_action("open_it","open");
//  add_action("enter_it","enter");
}

int open_it(string str) {
  int i;
  if(!str) {
    write("So what is it that you would like to open?");
    return 1;
  }
  if(str != "barrel") {
    write("You try to open "+str+" but it seems like it won't open.");
    say(this_player()->query_cap_name()+" tries to open "+str+" but it seems like it won't open.");
    return 1;
  }
  if(step == 1) {
    write("The barrel is already open, and it's empty.");
    return 1;
  }
    tell_room(ETP, "%^BOLD%^%^BLUE%^"+TPQCN+" opens the barrel.\n All of a sudden, smoke rises from the emply barrel and a white monkey climbs out.\n",TP);
    tell_object(TP,"%^BOLD%^%^BLUE%^You open the barrel.\n All of a sudden, smoke rises from the empty barrel and a white monkey climbs out.\n");
  new("/d/dragon/mon/ape")->move(environment(this_player()));
    set_long("This is an old wooden barrel.  Most likely it was once used for\n"+
           "some kind of ale.  Now it seems empty, but still you cannot\n"+
           "lift it up.  It is opened.\n");
  step = 1;
    call_out("open_barrel", 7);
    call_out("open_barrel",14);
    call_out("open_barrel",21);
    call_out("open_barrel",28);
    call_out("open_barrel",35);
    call_out("open_barrel",42);
    call_out("open_barrel",49);
    call_out("open_barrel",56);
    call_out("open_barrel",63);
    call_out("open_barrel",70);
    call_out("open_barrel", 77);
    call_out("open_barrel", 84);
    call_out("open_barrel", 91);
    call_out("open_barrel", 98);
  return 1;
}

void open_barrel() {
  tell_room(environment(this_object()), "%^BOLD%^%^RED%^From within the barrel another white monkey climbs out.");
  new("/d/dragon/mon/ape")->move(environment(this_object()));
}

//int enter_it(string str) {
//  if(!str) {
//    write("What is it that you would like to enter?");
//    return 1;
//  }
//  if (str != "barrel") {
//    write("What are you thinking of, trying to enter "+str+"!");
//    return 1;
//  }
//  if( step == 0) {
//    write("You cannot enter a barrel when it's closed.");
//    say(TP->query_cap_name()+" tries to enter a closed barrel, and fails.");
//    return 1;
//}
//  if(present("monkey")) {
//    write("The monkey forbids your entrance into the barrel.");
//    say("The monkey forbids "+TP->query_cap_name()+" from entering the barrel.");
//    return 1;
//  }
//  write("You enter the barrel, and climb down into the sewers.");
//  say(TP->query_cap_names()+" enters a emply barrel, and vanishes.");
//  TP->move_player("/d/dragon/sewer/sewer01");
//  return 1;
//}

void reset() {
  ::reset();
  step = 0;
}
