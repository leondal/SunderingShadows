#include <std.h>
#include <objects.h>
#include <security.h>
#define IMMORTALS ({"creator", "developer", "builder", "apprentice", "avatar", "overseer"})

inherit OBJECT;
string *iceList, icePos, iceType;
object myOwner;
int myCount;

void create() 
{
    ::create();
    set_name("a freezing object");
    set_id( ({"object", "ice object"}) );
    set_short("a freezing object");
    set_long("This is the ice object interacting with the daemon "+
    "via the ice command. You can dest this object in order to stop the "+
    "daemon from running.");
    set_weight(0);
    myCount = 0;
}

void set_ice_owner(object who) { myOwner = who; }
void set_ice_position(string str) { icePos = str; }
void set_ice_type(string str) { iceType = str; }


void do_icing()
{
    int x, i;
    string *toRemove = ({}), name, ridType;
    object ridob;
    if(!objectp(TO)) return;
    if(!objectp(myOwner)) { TO->remove(); return; }
    if(!member_group((string)myOwner->query_true_name(), "law")) { TO->remove(); return; }
    if(iceType == "level" && !stringp(icePos))
    {
        tell_object(myOwner, "Attempting to ice by level, without a valid position. Aborting....");
        TO->remove();
        return;
    }
    x = 50;
    if(x > sizeof(iceList)) x = sizeof(iceList);
    
    if(iceType == "level" && member_array(icePos, IMMORTALS) != -1) ridType = "immortal iced";
    else if(iceType == "level" && icePos == "newbie") ridType = "newbie";
    else if(iceType == "level") ridType = "mortal";
    else ridType = iceType;    
    
    for(i=0;i<x;i++)
    {
        name = iceList[i];
        toRemove += ({name});
        seteuid(UID_ROOT);
        ridob = new("/cmds/adm/_rid");
        ridob->do_actual_rid(myOwner, name, ridType);
        if(objectp(ridob)) ridob->remove();
        continue;        
    }   
    myCount += sizeof(toRemove);
    iceList -= toRemove;
    if(sizeof(iceList))
    {
        call_out("do_icing", 5);
        return;
    }
    else 
    { 
        switch(iceType)
        {
            case "level":            
                tell_object(myOwner, "Icing complete... "+myCount+" users removed who were position "+icePos+".");
                break;
            default:
                tell_object(myOwner, "Icing complete.... "+myCount+" users removed who fit the specified criteria.");
                break;
        }
    }    
    if(objectp(TO)) { TO->remove(); }
    return;    
}

void ice_list(string *list)
{
    if(!objectp(TO)) return;
    if(!objectp(myOwner)) { TO->remove(); return; }
    if(!pointerp(list))
    {
        tell_object(myOwner, "Something went wrong with the list of names to ice.");
        TO->remove();
        return;
    }
    if(iceType == "level" && !stringp(icePos))
    {
        tell_object(myOwner, "Attempting to ice by level, without a valid position. Aborting....");
        TO->remove();
        return;
    }
    if(!sizeof(list))
    {
        tell_object(myOwner, "No users to ice based on the supplied criteria.");
        TO->remove();
        return;
    }
    iceList = list;
    do_icing();    
    return;
}