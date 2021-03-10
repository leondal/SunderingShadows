//
// test thief monster
#include <std.h>
#include <daemons.h>

inherit NPC;

#define FILE "/d/save/retainers/"+followee->query_name()+"/"+query_name()


object followee;
int set = 0;
int counter,tick;


void create()
{
    ::create();
    set_spoken("common");
}

void saveFollower()
{
    saveMonster(FILE);
}

void restoreFollower()
{
    restoreMonster(FILE);
}

void set_followee(object f)
{
    followee = f;
    set = 1;
}

object get_followee()
{
    return followee;
}

int clean_up()
{
    if(!objectp(followee)) { return ::clean_up(); }
    return 1;
}

void heart_beat()
{
    int i;

  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
    if(set && !objectp(followee))
    {
        saveFollower();
        tell_room(ETO,"%^BOLD%^%^GREEN%^The retainer goes about his business.");
        move("/d/shadowgate/void");
        remove();
        return;
    }
    
  	if(query_hp_percent() < 50 && present("vial",TO))
    {
        for(i=0;i<5;i++)
        {
            command("quaff vial");
        }
	}

    counter++;
    if (counter > 120) 
    {
        counter = 0;
        saveFollower();
    }
}

void die(object ob)
{
    if(objectp(followee))
        followee->remove_retinue(query_name());
    clearMonster(FILE);
    ::die(ob);
}

string knownAs(string str)
{
    if(!objectp(followee))
    {
        return 0;
    }
    return followee->knownAs(str);
}

string realName(string str)
{
    if(!objectp(followee))
    {
        return 0;
    }
    return followee->realName(str);
}


void receive_message(string cl, string msg) 
{
    ::receive_message(cl,msg);
    if (cl == "reply") 
    {
        force_me("say "+msg);
    }
}
