#include <std.h>
inherit OBJECT;
mapping LOCATIONS;
// Coral Sea Area - Created January 2009 by Ari
void create(){
  ::create();
  set_name("brass compass");
  set_id(({"compass","brass compass","cscompriin"}));
  set_short("%^RESET%^%^ORANGE%^a brass compass%^RESET%^");
  set_obvious_short("%^RESET%^%^ORANGE%^a brass compass%^RESET%^");       
  set_long("%^RESET%^%^ORANGE%^Made of brass, this small device "+
    "sits easily within the palm of one's hand.  A %^CYAN%^"+
    "glass cover %^ORANGE%^seals the top and within you can "+
    "see a %^BOLD%^%^BLACK%^sliver of iron %^RESET%^%^ORANGE%^"+
    "floats upon the surface of some type of clear looking "+
    "%^CYAN%^liquid%^ORANGE%^.  Below, painted on the "+
    "interior of the compass is a %^GREEN%^green starburst "+
    "%^ORANGE%^with eight points laid out as a compass rose.  "+
    "No other markings present themselves on the interior, "+
    "but on the exterior there are words etched in a fluid, "+
    "flowery %^GREEN%^script%^ORANGE%^.%^RESET%^");
        set_weight(1);
        set_value(100);

  set_lore("As long as men have sailed the seas they have "+
    "found means by which to guide themselves home.  From "+
    "the sun, moon and stars to clever devices such as this "+
    "one, the goal has always been to find ones way back "+
    "to land when all that surrounds you is a horizon to "+
    "horizon view of open water.");
  set_property("lore difficulty",5);

  set("read","%^RESET%^%^ORANGE%^You peer at the writing and "+
  "can make out the following instructions: \n"+
  "%^BOLD%^%^WHITE%^set stuff \n"+
  "%^YELLOW%^findland (name) %^WHITE%^will tell");
	
  LOCATIONS = ([]);
}

void init(){
    ::init();
    add_action("find_land","findland");
    add_action("set_location","locationset");		
}


int find_land(string str){
  object ob;
  string room;
  string *tmp=({});
  string *location_keys=({});
  int num;
  int x_cord,y_cord;
  int compare_x,compare_y;
  int *coords=({});
  int north,south,east,west;
  
  if(!stringp(str) || str == "" || str == " "){
    return 0;
	}
  location_keys=keys(LOCATIONS);
  if(!sizeof(location_keys) || member_array(str,location_keys) == -1){
    tell_object(TP,"Location is not valid.");
    return 1;
	}

    // Gets the file name of the room the compass is in.
    if(objectp(ob=ETP->query_boat()));
    room=base_name(environment(ob)); 
	  // Check to see if its a dock, if so stop, if not continue.
      if(strsrch(room,"dock") != -1){
      tell_object(TP,"You are currently located at a dock. The "+
	    "compass will not function unless you are out to sea."); 
	  return 1; 
	  }
	num=strsrch(room,"/",-1);
	room=replace_string(room,".sea","");
	room=room[(num+1)..(strlen(room)-1)];
	tmp=explode(room,",");
	x_cord=to_int(tmp[1]);
	y_cord=to_int(tmp[0]);

	coords=LOCATIONS[str];
	compare_x=coords[0];
	compare_y=coords[1];
    //north=cords_x - compare_x;
    north=x_cord - compare_x;
      if(north<0){ south = north;}
    //east=cords_y - compare_y;	  
    east=y_cord - compare_y;
      if(east<0){ west = east;}
	if(south && west){
	  tell_object(TP,"You need to steer "+west+" west "+
	  "and "+south+" south");
	}
	if(north && west){
	  tell_object(TP,"You need to steer "+west+" west "+
	  "and "+north+" north");
	}
	if(south && east){
	  tell_object(TP,"You need to steer "+south+" south "+
	  "and "+east+" east");
	}
	if(north && east){
	  tell_object(TP,"You need to steer "+north+" north "+
	  "and "+east+" east");
	}
	if(!south && !north && !east && !west){
	  tell_object(TP,"You've arrived at your destination!");
	}
	return 1;  
}

int set_location(string str){
  string location,name;
  string *tmp=({});
  int *coords=({});
    if(!stringp(str) || str == "" || str == " "){
    return 0;
	}
	tmp=explode(str," ");
	if(sizeof(tmp) !=2){
	  tell_object(TP,"Syntax: locationset <name> "+
	  "<coordinate-1,coordinate-2> \n"+
	  "Example: locationset shadow 0,36");
	  return 1;
	  }
	coords=tmp[1];
	tmp=explode(coords,",");
    if(sizeof(tmp) != 2){
	  tell_object(TP,"Syntax: locationset <name> "+
	  "<coordinate-1,coordinate-2> \n"+
	  "Example: locationset shadow 0,36");
	  return 1;
	  }
	LOCATIONS["name"]=name=({to_int(tmp[0]),to_int(tmp[1])});
	tell_object(TP,"Location "+name+" set to "+
	"coordinates "+tmp[0]+","+tmp[1]+"");
	return 1;
}
	
