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
    if(!objectp(followee)) { return; }
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    mkdir("/d/save/retainers/"+followee->query_name());
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
        tell_room(ETO,"%^BOLD%^%^GREEN%^The retainer goes about his business.");
        move("/d/shadowgate/void");
        remove();
        return;
    }

  	if(query_hp_percent() < 70 && present("vial",TO))
    {
        for(i=0;i<4;i++)
        {
            command("quaff vial");
        }
	}

    counter++;
    if (counter > 120)
    {
        if(objectp(TO) && interactive(followee))
        {
            counter = 0;
            saveFollower();
        }
    }
}

void die(object ob)
{
    set_hp(10);
    saveFollower();
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

int remove() {
    saveFollower();
    return ::remove();
}

int remove_without_save() { return ::remove(); }

/* varargs receive_objects(object ob) { */
/* // so. this is to stop players using followers as storage. Any item given to the follower */
/* // picks up the monsterweapon flag, which then makes it inaccessible to players. N, 5/14. */
/*     if(::receive_objects(ob)) { */
/*       ob->set_property("monsterweapon",1); */
/*       return 1; */
/*     } */
/*     return 0; */
/* } */

int is_retinue() { return 1; }
