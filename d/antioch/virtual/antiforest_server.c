#include <config.h>
#include <std.h>
inherit "/std/room" ;
inherit "/std/virtual/compile";

#define BASE "/d/antioch/virtual/antiforest/"
#define SUFFIX ".antiforest"
#define FOREST_DAEMON "/d/antioch/virtual/antiforest_daemon.c"

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
    i = (int)FOREST_DAEMON->get_exits(x,y) ;
    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
 }

string query_short()
{
    return (string)FOREST_DAEMON->get_short(x,y);
}

string query_long(string item)
{
    if (item)
    {
        return((string)this_object()->describe(item));
    }
    else
    {
        return (string)FOREST_DAEMON->get_short(x,y)+"\n"+(string)FOREST_DAEMON->get_long(x,y);
    }
}

string query_smell(string str){
        if(!str) return 0;
        if(str != "default") return 0;
/*        if((y < 48) && (y > 1) && (x < 48) && (x > 1))
                return "The dry desert air fills your nostrils.";
        else if(y > 47)
                return "You can smell the fresh ocean air blowing from the east.";
        else if(y < 2)
                return "You can smell the fresh scent of pine to the west.";
        else if(x > 47)
                return "You can smell the stench of the marshes to the south.";
        else if(x < 2)
                return "You can smell the fresh mountian air to the north.";
*/
        if((y == 10) && (x < 21) && (x > 2))
           return "%^CYAN%^You smell rotten flowers.";
        else return 0;
}
string query_listen(string str){
        if(!str) return 0;
        if(str != "default") return 0;
/*        if((y < 48) && (y > 1) && (x < 48) && (x > 1))
                return "Geen listen beschrijving.";
        else if(y > 47)
                return "You can hear the crashing ocean waves to the east.";
        else if(y < 2)
                return "You can hear the rustling of tree's to the west.";
        else if(x > 47)
                return "You can hear the gurgling sounds of the marshes to the south.";
        else if(x < 2)
                return "You can hear the sound of the wind through the mountians to the north."; 
*/
        if((y == 10) && (x < 21) && (x > 2) && (x % 2))
           return "The wind %^BOLD%^%^RED%^howls%^RESET%^%^GREEN%^ through the trees.";         /* Oneven */
        else if((y == 10) && (x < 21) && (x > 2) && !(x % 2))
           return "%^BOLD%^%^RED%^You hear the sounds of a bird who is afraid.";       /* Even */
        else return 0;

}

void init()
{
 ::init();
}
