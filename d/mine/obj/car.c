#include <std.h>

inherit "/std/container";

#define DESTINATIONS ({ "/d/mine/lvl1room/minexroad",\
                        "/d/mine/lvl1room/minee1",\
                        "/d/mine/lvl1room/minee2",\
                        "/d/mine/lvl1room/minee3",\
                        "/d/mine/lvl1room/track1",\
                        "/d/mine/lvl1room/track2",\
                        "/d/mine/lvl1room/track3",\
                        "/d/mine/lvl1room/track4",\
                        "/d/mine/lvl1room/track5",\
                        "/d/mine/lvl1room/minew3",\
                        "/d/mine/lvl1room/minew2",\
                        "/d/mine/lvl1room/minew1" })
 
int currentpos;
int counter;
int someonein;
object playerin;
 
void create() {
    ::create();
    set_heart_beat(1);
    set_name("minecar");
    set_id( ({ "minecar", "car", "mine car" }) );
    set_short("A Minecar");
    set_long("A minecar, zipping around the mine.  <hop> in!\n");
    set_weight(1000000);
    set_value(0);
    currentpos = 0;
    someonein = 0;
}
 
void init() {
    string fname;
    ::init();
    add_action("do_hop","hop");
    add_action("bad_move","north");
    add_action("bad_move","south");
    add_action("bad_move","northeast");
    add_action("bad_move","northwest");
    add_action("bad_move","east");
    add_action("bad_move","southeast");
    add_action("bad_move","southwest");
    add_action("bad_move","west");
}

void bad_move(string str) {
  if(!someonein) return 0;
  if(playerin == this_player()) {
    write("You can't leave until you hop out of the mine car!");
    return 1;
  }
  return 0;
}

void do_hop(string str) {
  if(!str) {
    write("Hop in or hop out?");
    return 1;
  }
  if(str == "in") {
    if(someonein) {
      write("You can't get in!  There's already someone in!");
      return 1; 
    }
    write("You hop in the minecar just in time!");
    someonein = 1;
    playerin = this_player();
    return 1;
  }
  if(str == "out") {
    if(!someonein) {
       write("You are not in the mine car!");
       return 1;
    }
    if(playerin != this_player()) {
      write("You are not in the mine car!");
      return 1;
    }
    if((currentpos == 5) || (currentpos == 6) ||
       (currentpos == 8) || (currentpos == 9)) {
       write("Ack!  You can't get out HERE!  "+currentpos);
       return 1;
    }
    write("You hop out of the mine car.");
    this_player()->move(find_object_or_load(DESTINATIONS[currentpos-1]));
    someonein = 0;
    playerin = 0;
    return 1;
  }
}

void heart_beat() {
  string fname,s1,s2;
  object ob,ob2;
  
  fname = file_name(this_object());
  if(!sscanf(fname,"%s#%s",s1,s2)) { 
    return 1;
  }
  if(counter != 1) {
    counter = 1;
    return 1;
  }
  if(!someonein) 
    tell_room(environment(this_object()),"The mine car zips off along the railway.");
  else
    tell_room(environment(this_object()),
    "The mine car zooms off, "+playerin->query_cap_name()+
    " just barely staying in!",playerin);
  if(playerin) tell_player(playerin,"The mine car zooms away, taking you with it.\n");  
  this_object()->move(find_object_or_load(DESTINATIONS[currentpos]));
  if(playerin) tell_player(playerin,"The mine car rolls into a new section of the mine.\n");
  if(!someonein) 
    tell_room(environment(this_object()),"The mine car rolls in the room.");
  else
    tell_room(environment(this_object()),
    "The mine car rolls in "+playerin->query_cap_name()+
    " clinging to the sides in terror!",playerin);  
  if(someonein) playerin->move_player(find_object_or_load(DESTINATIONS[currentpos]));
  currentpos++;    
  if(currentpos > 11)
    currentpos = 0;
}