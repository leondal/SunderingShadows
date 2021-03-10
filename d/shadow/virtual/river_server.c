#include <std.h>
#include <config.h>

inherit ROOM;
inherit "/std/virtual/compile";

#define BASE "/d/shadow/virtual/river/"
#define SUFFIX ".river"
#define RIVER_DAEMON "/d/shadow/virtual/river_daemon.c"
// #define MONDIR "/d/shadow/mon/"  don't need mobs

int x,y;
object ob;

int is_virtual() { return 1; }
int is_water() { return 1; }

void virtual_setup(string arg) {
    int i,x1,x2,y1,y2;
    string north, south, east, west, northwest, northeast, southwest, southeast;
    seteuid(getuid());
    sscanf(arg,"%d,%d",x,y);
// disclaimer - this is not really the right way to do this so refer to the others for examples
    south = 	BASE + (x+1) + "," + y     + SUFFIX;
    east = 	BASE + x     + "," + (y+1) + SUFFIX;
    north  = 	BASE + (x-1) + "," + y     + SUFFIX;
    west = 	BASE + x     + "," + (y-1) + SUFFIX;
    northwest = BASE + (x-1) + "," + (y-1) + SUFFIX;
    southeast = BASE + (x+1) + "," + (y+1) + SUFFIX;
    southwest = BASE + (x+1) + "," + (y-1) + SUFFIX;
    northeast = BASE + (x-1) + "," + (y+1) + SUFFIX;
    set_property("light", 2);
    set_exits( ({}), ({}) );
    i = (int)RIVER_DAEMON->get_exits(x,y) ;
/*    if (!(i%2))     { add_exit(west , "west"  ); }
    if (!((i/2)%2)) { add_exit(east , "east"  ); }
    if (!((i/4)%2)) { add_exit(south, "south" ); }
    if (!((i/8)%2)) { add_exit(north, "north" ); }
*/
    switch(i) {
	case 0:   add_exit(west, "west");
		  add_exit(east, "east");
		  add_exit(north, "north");
		  add_exit(south, "south");
		  break;
	case 1:   add_exit(north, "north");
		  add_exit(south, "south");
		  break;
	case 2:   add_exit(west, "west");
		  add_exit(east, "east");
		  break;
	case 3:   add_exit(northwest, "northwest");
		  add_exit(southeast, "southeast");
		  break;
	case 4:   add_exit(northeast, "northeast");
		  add_exit(southwest, "southwest");
		  break;
	case 5:   add_exit(north, "north");
		  add_exit(southeast, "southeast");
		  break;
	case 6:   add_exit(west, "west");
		  add_exit(southeast, "southeast");
		  break;
	case 7:   add_exit(northwest, "northwest");
		  add_exit(east, "east");
		  break;
	case 8:   add_exit(northwest, "northwest");
		  add_exit(south, "south");
		  break;
	case 9:   add_exit(west, "west");
		  add_exit(northeast, "northeast");
		  break;
	case 10:   add_exit(east, "east");
		  add_exit(southwest, "southwest");
		  break;
	default:  add_exit("/d/shadow/room/forest/road16", "dock");
    }
    set_property("no teleport",1);
 }

string query_short() {
    return (string)RIVER_DAEMON->get_short(x,y);
}

string query_long(string item) {
    if (item) {
        return((string)this_object()->describe(item));
    } else {
    	return (string)RIVER_DAEMON->get_short(x,y)+"\n"+(string)RIVER_DAEMON->get_long(x,y);
    }
}

string query_smell(string str) {
	if(!str) return 0;
	if(str != "default") return 0;
	if(x <= 15)
	   return "The air smells fresh and clean from the forest."; 
	if(x > 15 && x < 20)    // bridge is at 17,4 - /d/shadow/room/meadows/
	   return "The dust travelers stir up from the road tickles your nose.";
	if(x >= 20 && x < 31)
	   return "Various scents from the city waft on the breeze.";
	if(x >= 31 && y < 28)
	   return "The scents of pine and decaying leaves waft on the breezes from the deep forest.";
	if(y >= 28 && y < 43)
	   return "You can smell the famous Tharis cooking and other less appealing city scents.";
	if(y >= 43 && y < 65)
	   return "The breezes carrying the scents of the woodlands are refreshing.";
	if(y > 64)
	   return "The salty sea spray and moist fresh air from the ocean is carried on a brisk wind.";
	else 
	   return "The moist air from the river smells fresh and clean.";
}

string query_listen(string str) {
	if(!str) return 0;
	if(str != "default") return 0;
	if(x <= 15)
	   return "You hear the rustling, growls, and other sounds of the animals in the meadowlands and forest.";
	if(x > 15 && x < 20)    // bridge is at 3,17, /d/shadow/room/meadows/
	   return "The pack animals and travelers on the nearby road sound anxious to reach the city.";
	if(x > 19 && x < 32)
	   return "Sounds of the city and travelers drown out the sounds of nature here.";
	if(x >= 32 && y < 28)
	   return "The forest muffles most sounds but you do hear wildlife from time to time.";
	if(y >= 28 && y < 43)
	   return "The din from the bustling city carries to the ferry and you realize that it must be very large as you drift past.";
	if(y >= 43 && y < 65)
	   return "The forest is almost eerily quiet at times.";
	if(y > 64)
	   return "The surf of the Saakrune Sea gurgles against the river current to the east.";
	else
	   return "You hear the waves splashing gently against the ferry and the bank.";
}

void init(){
    ::init();
}
