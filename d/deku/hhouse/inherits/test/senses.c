//      /std/room/senses.c
//      from the Nightmare Mudlib
//      allows players to search, hide, smell, listen in every room
//      created by Descartes of Borg 18 june 1993
//      modified to save MAJOR memory by Descartes of Borg 930830

#include <config.h>
#include <rooms.h>

object __Search_Obj;
private mapping __Smells, __Listens, __Searches;

void set_search(string item, mixed desc);
void set_smell(string item, mixed desc);
void set_listen(string item, mixed desc);
void remove_search(string item);
void remove_smell(string item);
void remove_listen(string item);
mixed query_search(string item);
mixed query_smell(string item);
mixed query_listen(string item);

// #ifdef __OLD_ROOM_BEHAVIOUR
// #define __SENSES_C
// #include <old_room.h>
// #endif /* __OLD_ROOM_BEHAVIOUR */

void create() 
{
    log_file("deku_code", "@@START@@\n senses.c start of create function\n");
    __Search_Obj = 0;
    __Smells = ([]);
    __Listens = ([]);
    __Searches = ([]);
    log_file("deku_code", "@@END@@\n senses.c end of create function\n");
}

void initiate() {
    //add_action("hide_something", "hide");
    add_action("search_room","search");
    add_action("smell_things", "smell");
    add_action("do_listen", "listen");
}

int search_room(string str) 
{
    int i;
    int x;
	if(!objectp(this_object())) return 0;
	if(!objectp(this_player())) return 0;
    if (!x = this_object()->search(str)) {
        return 0;
    }
    if(!__Searches) return notify_fail("You find nothing of interest.\n");
    if(str == "default") return notify_fail("What is a default?\n");
    if(!str || str == "") str = "default";
    if(functionp(__Searches[str])) (*__Searches[str])(str);
    else if(stringp(__Searches[str])) {
        message("my_action", __Searches[str], this_player());
        message("other_action", (string)this_player()->query_cap_name() +
          " searches around.", this_object(), ({ this_player() }) );
    }
    else if (x ==1) message("my_action", "You find nothing odd.", this_player());
    return 1;
}

status smell_things(string str) 
{
	if(!objectp(this_object())) return 0;
	if(!objectp(this_player())) return 0;
    if(!str || str == "") str = "default";
    if(!__Smells || !__Smells[str]) {
        if(!this_object()->id(str))
          return notify_fail("You do not notice that here.\n");
        else message("smell", "You smell no odd odors.", this_player());
        return 1;
    }
    if(functionp(__Smells[str]))
      message("smell", (string)((*__Smells[str])(str)), this_player());
    else if(stringp(__Smells[str])) {
        message("smell", __Smells[str], this_player());
        if(str == "default") message("other_action",
          (string)this_player()->query_cap_name()+" smells around.",
          this_object(), ({ this_player() }));
        else message("other_action", (string)this_player()->query_cap_name()+
          " smells the "+str+".", this_object(), ({this_player()}));
    }
    else message("smell","You notice no interesting odors.",this_player());
    return 1;
}

status do_listen(string str) {
	if(!objectp(this_object())) return 0;
	if(!objectp(this_player())) return 0;
    if(!str || str == "") str = "default";
    else if(sscanf(str, "to %s", str) != 1)
      return notify_fail("Listen to what?\n");
    if(!__Listens || !__Listens[str]) {
        if(!this_object()->id(str))
          return notify_fail("You do not notice that here.\n");
        else message("listen", "You hear nothing unusual.",this_player());
        return 1;
    }
    if(functionp(query_listen(str)))
      message("listen", (string)((*__Listens[str])(str)), this_player());
    else if(stringp(__Listens[str])) {
        message("listen", __Listens[str], this_player());
        if(str == "default") message("other_action",
          (string)this_player()->query_cap_name()+" listens intently.",
          this_object(), ({ this_player() }) );
        else message("other_action", (string)this_player()->query_cap_name()+
          " listens intently to "+str+".", this_object(),({this_player()}));
    }
    else message("listen", "You hear nothing unusual.", this_player());
    return 1;
}

void set_search(string item, mixed desc) {
    if(functionp(desc) && geteuid(this_object()) != geteuid(desc[0])) return;
	if(!mapp(__Searches)) __Searches = ([]);
    __Searches[(item ? item : "default")] = desc;
}

void remove_search(string item) 
{
	if(!mapp(__Searches)) __Searches = ([]);
	if(!__Searches[item]) return; 
	map_delete(__Searches, item); 
}

void set_smell(string item, mixed desc) 
{
    	if(functionp(desc))
	{
		if(geteuid(this_object()) != geteuid(desc[0])) return;
	}
	if(!item) item = "default";
	if(!mapp(__Smells)) __Smells = ([]);
	__Smells[item] = desc;
}

void remove_smell(string item) { map_delete(__Smells, item); }

void set_listen(string item, mixed desc) 
{
    	if(functionp(desc))
	{
		if(geteuid(this_object()) != geteuid(desc[0])) return;
	}
	if(!item) item = "default";
	if(!mapp(__Listens)) __Listens = ([]);
	__Listens[item] = desc;
}

void remove_listen(string item) { map_delete(__Listens, item); }

mixed query_search(string item) { 
    return (__Searches ? __Searches[item] : 0);
}

mixed query_smell(string item) {
    return (__Smells ? __Smells[item] : 0);
}

mixed query_listen(string item) {
    return (__Listens ? __Listens[item] : 0);
}
