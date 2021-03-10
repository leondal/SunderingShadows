#include <config.h>
#include <std.h>

inherit "/std/room" ;
inherit "/std/virtual/compile";


#define BASE "/d/tharis/virtual/mountains/"
#define SUFFIX ".mount"
#define LEVEL1_DAEMON "/d/tharis/virtual/mount_daemon.c"

int x,y;
object ob;

int is_virtual() { return 1; }

void virtual_setup(string arg)
{
    int i,x1,x2,y1,y2;
    string north, south, east, west, nw, sw,ne,se ;
    seteuid(getuid());


    sscanf(arg,"%d,%d",x,y);
    south = BASE + (x+1) +  "," + y       + SUFFIX ;
    east = BASE + x       +  "," + (y+1) + SUFFIX;
    north  = BASE + (x-1) +  "," + y       + SUFFIX;
    west = BASE + x       +  "," + (y-1) + SUFFIX;
    nw = BASE + (x-1) + "," + (y-1) + SUFFIX;
    sw = BASE + (x+1) + "," + (y-1) + SUFFIX;
    ne = BASE + (x-1) + "," + (y +1) + SUFFIX;
    se = BASE + (x+1) + "," + (y +1) + SUFFIX;
    set_property("light", 0);
    set_property("indoors",1);
    set_exits( ({}), ({}) );
    i = (int)LEVEL1_DAEMON->get_exits(x,y) ;
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
    if (!((i/16)%2)) { add_exit(nw, "northwest" ); }
    if (!((i/32)%2)) { add_exit(ne, "northeast" ); }
    if (!((i/64)%2)) { add_exit(sw, "southwest" ); }
    if (!((i/128)%2)) { add_exit(se, "southeast" ); }
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
        return (string)LEVEL1_DAEMON->get_short(x,y)+"\n"+(string)LEVEL1_DAEMON->get_long(x,y);
    }
}

string query_smell(string str){
        if(!str) return 0;
        if(str != "default") return 0;
        return "You smell stale air, and the odor of rotting flesh.";
}
string query_listen(string str){
        if(!str) return 0;
        if(str != "default") return 0;
        return "You hear a silence. Broken from time to time by the sounds of rats scurrying around.";
}

void reset(){
	::reset();
	
	if(!present("ogre")){
		new("/d/tharis/monsters/ogre_mage")->move(TO);
	}
}
