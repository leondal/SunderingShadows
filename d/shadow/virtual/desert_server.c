#include <config.h>
#include <std.h>


inherit "/std/room" ;
inherit "/std/virtual/compile";

#define BASE "/d/shadow/virtual/desert/"
#define SUFFIX ".desert"
#define DESERT_DAEMON "/d/shadow/virtual/desert_daemon.c"
#define MONDIR "/d/shadow/mon/"

int x,y;
object ob;

int is_virtual() { return 1; }

void virtual_setup(string arg) {
    int i,x1,x2,y1,y2;
    string north, south, east, west ;
    string terrain;
    seteuid(getuid());
    sscanf(arg,"%d,%d",x,y);
    south = BASE + (x+1) +  "," + y       + SUFFIX ;
    east = BASE + x       +  "," + (y+1) + SUFFIX;
    north  = BASE + (x-1) +  "," + y       + SUFFIX;
    west = BASE + x       +  "," + (y-1) + SUFFIX;
    set_property("light", 3);
    set_exits( ({}), ({}) );
    i = (int)DESERT_DAEMON->get_exits(x,y) ;
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }

    if(y == 49) terrain = SHORE;
    else if(!x) terrain = ROCKY;
    else if(y < 3) terrain = LIGHT_FOREST;
    else if(y < 6) terrain = SCRUB_LANDS;
    else if(y < 9) terrain = GRASSLANDS;
    else if(x < 3 || x > 47) terrain = ROCKY;
    else terrain = DESERT;

   set_climate("desert");
   set_terrain(terrain);
   set_travel(RUTTED_TRACK);
 }

string query_short()
{
    return (string)DESERT_DAEMON->get_short(x,y);
}

string query_long(string item)
{
    if (item)
    {
        return((string)this_object()->describe(item));
    }
    else
    {
        return (string)DESERT_DAEMON->get_short(x,y)+"\n"+(string)DESERT_DAEMON->get_long(x,y);
    }
}

string query_smell(string str){
    if(!str) return 0;
    if(str != "default") return 0;
    if((y < 48) && (y > 1) && (x < 48) && (x > 1))
        return "The dry desert air fills your nostrils.";
    else if(y > 47)
        return "You can smell the fresh ocean air blowing from the east.";
    else if(y < 2)
        return "You can smell the fresh scent of pine to the west.";
    else if(x > 47)
        return "You can smell the stench of the marshes to the south.";
    else if(x < 2)
        return "You can smell the fresh mountain air to the north.";
}
string query_listen(string str){
    if(!str) return 0;
    if(str != "default") return 0;
    if((y < 48) && (y > 1) && (x < 48) && (x > 1))
        return "You can hear the breeze blowing over the sand, it is so quiet here.";
    else if(y > 47)
        return "You can hear the crashing ocean waves to the east.";
    else if(y < 2)
        return "You can hear the rustling of trees to the west.";
    else if(x > 47)
        return "You can hear the gurgling sounds of the marshes to the south.";
    else if(x < 2)
        return "You can hear the sound of the wind through the mountains to the north.";
}

void init(){
    ::init();
    do_random_encounters(({MONDIR+"rattlesnake",MONDIR+"rat"}),1,2);
}

