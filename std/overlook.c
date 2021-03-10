//  Overlook Room object
//  Allows for player in room to see into 
//  other rooms that are "below" that room
//  in elevation, but that are not necesarily
//  adjacent.

#include <std.h>
#include <daemons.h>
inherit ROOM;

mapping  __Over;

void     set_overlook(mapping over) ;
mapping  query_overlook();
string   overlook_path(string dir);
string   add_overlook(string dir, string path);
string   remove_overlook(string dir);
int      overlook(string str) ;
int      describe_overlook_room(object env, object looker);



void create() 
{
	room::create();
}

void init()
{
	room::init();
	add_action("overlook", "overlook");
}

// __Over = ([ DIRECTION : PATH, ])
void set_overlook(mapping over) 
{
	__Over = over;
}

mapping query_overlook()
{
	if(!__Over) return ([]);
	return __Over;
}

string overlook_path(string dir)
{
	if((!__Over) || (!(__Over[dir]))) return 0;
	return __Over[dir];
}

string add_overlook(string dir, string path)
{
	if(!__Over) __Over = ([]);
	__Over[dir] = path;
	return __Over[dir];
}

string remove_overlook(string dir)
{
	if((!__Over) || (!(__Over[dir]))) return 0;
	map_delete(__Over, dir);
	return dir;
}

int overlook(string str) 
{
	object below;
	
	below = find_object_or_load(__Over[str]);
	if(!below) {
		tell_object(TP, "You do not have an overlook in that direction.");
		return 1;
	}
	describe_overlook_room(below, TP);
	return 1;
}

int describe_overlook_room(object env, object looker)
{
    string borg;
    mixed tmp;
    int light,bonus,verbose;
    
    verbose = 0;
    bonus = looker->query_sight_bonus();
    if(wizardp(looker)) borg = file_name(env)+"\n";
    else borg = "";
    borg += "%^BOLD%^Overlooking this area from your position, you see:%^RESET%^\n\n";
    if((light=env->query_light()) > 6 ||( light+bonus) < 1) {
        if(light > 6) borg += "It is too bright to see.";
        else if(light+bonus > -2) borg += "It is dark.";
        else if(light+bonus > -4) borg += "It is quite dark.";
        else if(light+ bonus > -6) borg += "It is very dark.";
        else borg += "It is completely dark.";
        message("room_description", borg, looker);
        if(stringp(tmp=(string)env->query_smell("default")))
         message("smell", tmp, looker);
        else if(functionp(tmp))
          message("smell",(string)((*tmp)("default")), looker);
        if(stringp(tmp=(mixed)env->query_listen("default")))
          message("listen", tmp, looker);
        else if(functionp(tmp)) message("listen",(string)((*tmp)("default")), looker);
         if(stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
           message("weather", ""+tmp+"", looker);
       return 1;
    }
    else if(light > 3) borg += "It is really bright.\n";
    borg += (verbose ? (string)env->query_long(0)+" " :
      (string)env->query_short());
    message("room_description", borg, looker);
    if(!verbose)
      message("room_exits", (string)env->query_short_exits(),looker);
    if(verbose && stringp(tmp=(mixed)env->query_smell("default")))
      message("smell", tmp, looker);
    else if(verbose && functionp(tmp))
      message("smell",(string)((*tmp)("default")), looker);
    if(verbose && stringp(tmp=(mixed)env->query_listen("default")))
        message("listen", tmp, looker);
    else if(verbose && functionp(tmp))
      message("listen", (string)((*tmp)("default")), looker);
    if(stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
           message("weather", ""+tmp+"", looker);
    if(stringp(tmp=(string)env->query_effects()))
      message("room_effects",tmp,looker);
    if(verbose && (tmp=(string)env->query_long_exits()) && tmp != "")
      message("room_exits", sprintf("\n%s\n", tmp), looker);
    if(verbose && stringp(tmp=(string)env->query_effects()))
      message("room_effects",tmp,looker);
    if((tmp=(string)env->describe_living_contents(({looker})))!="")
      message("living_item", tmp, looker);
    if((tmp=(string)env->describe_item_contents(({})))!="")
      message("inanimate_item", tmp, looker);
    return 1;
}

