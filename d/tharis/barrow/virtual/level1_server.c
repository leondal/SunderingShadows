#include <config.h>
#include "/d/tharis/barrow/short1.h"
inherit "/std/room" ;
inherit "/std/virtual/compile";

#define BASE "/d/tharis/barrow/virtual/level1/"
#define SUFFIX ".level1"
#define LEVEL1_DAEMON "/d/tharis/barrow/virtual/level1_daemon.c"


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
    set_property("light", 0);
    set_property("indoors",1);
    set_exits( ({}), ({}) );
    i = (int)LEVEL1_DAEMON->get_exits(x,y) ;
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
 }

string query_short()
{
    return (string)LEVEL1_DAEMON->get_short(x,y);
}

string query_long(string item)
{
    if (item)
    {
        return((string)this_object()->describe(item));
    }
    else
    {
    	return
(string)LEVEL1_DAEMON->get_short(x,y)+"\n"+(string)LEVEL1_DAEMON->get_long(x,y);
    }
}

string query_smell(string str){
	if(!str) return 0;
	if(str != "default") return 0;
	return "The aroma of the hot jungle surrounds you.";
}
string query_listen(string str){
	if(!str) return 0;
	if(str != "default") return 0;
	return "You hear dead silence. It is as though only plants have "
	"survived here."; 
}

void init(){
    ::init();
}

