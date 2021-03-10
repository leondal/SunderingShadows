//      /std/room/senses.c
//      from the Nightmare Mudlib
//      allows players to search, hide, smell, listen in every room
//      created by Descartes of Borg 18 june 1993
//      modified to save MAJOR memory by Descartes of Borg 930830

#include <config.h>
#include <rooms.h>

object __Search_Obj;
//making smells, listens, searches public, inherits not showing up
mapping __Smells, __Listens, __Searches; 

void set_search(string item, mixed desc);
void set_smell(string item, mixed desc);
void set_listen(string item, mixed desc);
void remove_search(string item);
void remove_smell(string item);
void remove_listen(string item);
mixed query_search(string item);
mixed query_searches(string item);
mixed query_smell(string item);
mixed query_listen(string item);
string *query_effects();

// #ifdef __OLD_ROOM_BEHAVIOUR
// #define __SENSES_C
// #include <old_room.h>
// #endif /* __OLD_ROOM_BEHAVIOUR */

void create() {
    __Search_Obj = 0;
    __Smells = ([]);
    __Listens = ([]);
    __Searches = ([]);
}

void initiate() {
    //add_action("hide_something", "hide");
    add_action("search_room","search");
    add_action("smell_things", "smell");
    add_action("do_listen", "listen");
}

int search_room(string str) 
{
    int i, x;
    string tmp;
	if(!objectp(this_object())) return 0;
	if(!objectp(this_player())) return 0;
    if (!x = this_object()->search(str)) {
        return 0;
    }
    if(!__Searches) return notify_fail("You find nothing of interest.\n");
    if(str == "default") return notify_fail("What is a default?\n");
    if(!str || str == "") str = "default";
    if(functionp(__Searches[str])) { tmp = (*__Searches[str])(1); call_other(TO, tmp, str); }
    else if(stringp(__Searches[str])) {
        message("my_action", __Searches[str], this_player());
        message("other_action", (string)this_player()->query_cap_name() +
          " searches around.", this_object(), ({ this_player() }) );
    }
    else if (x ==1) message("my_action", "You find nothing odd.", this_player());
    return 1;
}

int smell_things(string str) 
{
    string tmp;
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
    {
        tmp = (*__Smells[str])(1);
        message("smell", call_other(TO, tmp, str), this_player());
        return 1;
    }
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

int do_listen(string str) 
{
    string tmp;
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
    {
        tmp = (*__Listens[str])(1);
        message("listen", call_other(TO, tmp, str), this_player());
        return 1;
    }
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
	if(!item) item = "default";
	if(!mapp(__Smells)) __Smells = ([]);
	__Smells[item] = desc;
}

void remove_smell(string item) { map_delete(__Smells, item); }

void set_listen(string item, mixed desc) 
{
	if(!item) item = "default";
	if(!mapp(__Listens)) __Listens = ([]);
	__Listens[item] = desc;
}

void remove_listen(string item) { map_delete(__Listens, item); }

mixed query_search(string item) { 
    return (__Searches ? __Searches[item] : 0);
}

mapping query_searches()
{
    if (sizeof(__Searches) > 0) { return __Searches; }
   return ([]);
}

mixed query_smell(string item) 
{
    string tmp;
    if(!__Smells || !__Smells[item]) return 0;
    if(functionp(__Smells[item]) && objectp(this_player()))
    {
        tmp = (*__Smells[item])(1);
        return message("smell", call_other(TO, tmp, item), this_player());
    }
    return (__Smells ? __Smells[item] : 0);
}

mixed query_listen(string item) 
{
    string tmp;
    if(!__Listens || !__Listens[item]) return 0;
    if(functionp(__Listens[item]) && objectp(this_player()))
    {
        tmp = (*__Listens[item])(1);
        return message("listen", call_other(TO, tmp, item), this_player());        
    }
    return (__Listens ? __Listens[item] : 0);
}

string *query_effects() {
    string returnstring = "", *capturestring = (string *)TO->query_property("aoe_messages");
    int i;
    if(!sizeof(capturestring)) return 0;
    for(i=0;i<sizeof(capturestring);i++) {
        if(stringp(capturestring[i])) returnstring += capturestring[i]+" ";
    }
    return returnstring;
}
