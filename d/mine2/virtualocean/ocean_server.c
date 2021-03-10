#include <std.h>
#include <config.h>

inherit ROOM;
inherit "/std/virtual/compile";

#define BASE "/d/mine2/virtualocean/"
#define SUFFIX ".ocean"

int x,y;
object ob;

int is_virtual() { return 1; }
int is_water() { return 1; }

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
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
 }
string query_long(string item)
{
    if (item)
    {
        return((string)this_object()->describe(item));
    }
}
string query_smell(string str){
    if(!str) return 0;
    if(str != "default") return 0;
    if(y > 57)
       return "You smell death!";
    else if(y < 1)
       return "You smell death!";
    else if(x > 46)
       return "You smell death!"; 
    else if(x < 1)
       return "You smell death!";
    else
       return "You can smell the fresh ocean air.";
}
string query_listen(string str){
    if(!str) return 0;
    if(str != "default") return 0;
    if(y > 57)
        return "You can hear the water falling off the edge of the world!";
    else if(y < 1)
        return "You can hear the water falling off the edge of the world!";
    else if(x > 46)
        return "You can hear the water falling off the edge of the world!";
    else if(x < 1)
        return "You can hear the water falling off the edge of the world!";
   else
        return "You hear nothing on the ocean.";
}

void init(){
    ::init();
}

