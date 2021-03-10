#include <std.h>
#include <config.h>

inherit "/std/room" ;
inherit "/std/virtual/compile";

#define BASE "/d/guilds/virtual/field/"
#define SUFFIX ".field"
#define BAT_DAEMON "/d/guilds/virtual/field_daemon.c"
#define MONDIR "/d/guilds/mon/"

int x,y;
object ob;

int is_virtual() { return 1; }

void virtual_setup(string arg)
{
    int i,x1,x2,y1,y2;
    string north, south, east, west ;
    seteuid(getuid());
    sscanf(arg,"%d,%d",x,y);
    south = BASE + (x+1) +  "," + y       + SUFFIX ;
    east = BASE + x       +  "," + (y+1) + SUFFIX;
    north  = BASE + (x-1) +  "," + y       + SUFFIX;
    west = BASE + x       +  "," + (y-1) + SUFFIX;
    set_property("light", 3);
    set_exits( ({}), ({}) );
    i = (int)BAT_DAEMON->get_exits(x,y) ;
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
   set_climate("jungle");
 }

string query_short()
{
    return (string)BAT_DAEMON->get_short(x,y);
}

string query_long(string item)
{
    if (item)
    {
        return((string)this_object()->describe(item));
    }
    else
    {
    	return (string)BAT_DAEMON->get_short(x,y)+"\n"+(string)BAT_DAEMON->get_long(x,y);
    }
}

string query_smell(string str){
	if(!str) return 0;
	if(str != "default") return 0;
   return "You smell the death of countless battles that have occurred here.";
}
string query_listen(string str){
	if(!str) return 0;
	if(str != "default") return 0;
   "The sounds of battle surround you.";
}

void init(){
  ::init();
  add_action("flee","flee");
}

int flee(string str){
  tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" flees the chaos of the battlefield.",TP);
  tell_object(TP,"%^BOLD%^%^MAGENTA%^You flee the battlefield, leaving your comrades to fend for themselves.");
  TP->move_player("/d/shadowgate/adv_main");
return 1;
}
