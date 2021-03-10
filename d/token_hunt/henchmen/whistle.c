#include <std.h>
#include <clock.h>
#include "henchmen.h"

inherit OBJECT;

int SETUP,END_TIME;
string MERC_NAME,MERC_RACE;
object MERC;

int drop() { return 1; }

void create()
{
    ::create();
    set_name("magical whistle");
    set_id(({"whistle","magic whistle","magical whistle","merc_whistle_999"}));
    set_short("a plain looking silver whistle");
    set_obvious_short("a plain looking silver whistle");
    set_long("%^RESET%^%^BOLD%^This small whistle is about two inches in length.  It is a simple "
        "cylinder made of a material of a polished silver color.  There is a hole "
        "in one end to blow through, and a smaller opening in the other where sound "
        "would emit from.  There seems to be some writing on the side%^RESET%^");
    set_weight(0);
    set_value(0);
    set_property("death keep",1);
    set_property("no animate",1);
    set_property("no offer",1);
    set_property("no drop",1);

    set_read("%^RESET%^%^BOLD%^The impossibly small letters seem to magnify in your vision as you look at the side of the whistle: \n"
        "%^RESET%^%^BOLD%^You may %^CYAN%^<%^MAGENTA%^call merc%^RESET%^%^BOLD%^%^CYAN%^> %^RESET%^%^BOLD%^to call your hired mercenary to your aid.\n"
        "%^RESET%^%^BOLD%^You may make your merc %^CYAN%^<%^MAGENTA%^wait%^RESET%^%^BOLD%^%^CYAN%^> %^RESET%^%^BOLD%^for you if you need to go somewhere alone.\n"
        "%^RESET%^%^BOLD%^You may %^CYAN%^<%^MAGENTA%^end contract%^RESET%^%^BOLD%^%^CYAN%^> %^RESET%^%^BOLD%^your contract with the merc when you no longer need them.\n"
        "%^RESET%^%^BOLD%^You may %^CYAN%^<%^MAGENTA%^stuck_merc%^RESET%^%^BOLD%^%^CYAN%^> %^RESET%^%^BOLD%^if your merc isn't responding to call merc.\n"
        "%^RESET%^%^BOLD%^If you keep your mercenary with you for more than a day, you will be charged double \n"
        "%^RESET%^%^BOLD%^when you try to hire another.%^RESET%^\n"
        "%^RESET%^%^BOLD%^%^CYAN%^HINT: %^RESET%^%^BOLD%^If there is more than one person in the room and you are talking to the mercenary, it "
        "would be useful to address him or her by name, so the mercenary knows who you're talking to.%^RESET%^");

    call_out("check_duration",1);
}


void check_duration()
{
    if(SETUP && END_TIME)
    {
        if(time() > (END_TIME + DAY) )
        {
            if(objectp(ETO))
            {
                tell_object(ETO,"%^RESET%^%^BOLD%^%^GREEN%^The whistle vanishes as the mercenary contract has expired.%^RESET%^");
                HENCH_D->penalize(ETO,"late");
                TO->remove();
            }
        }
    }
    return;
}


void init()
{
    ::init();
    add_action("summon_merc","call");
    add_action("ditch_merc","wait");
    add_action("fire_merc","end");
    add_action("stuck_merc","stuck_merc");
}

// don't want whistles getting damaged
void set_overallStatus(int i){ return; }
int query_overallStatus() { return 100; }

int query_end_time() { return END_TIME; }

void setup_whistle(object obj)
{
    if(!objectp(obj)) { return; }

    MERC_NAME = (string)obj->query_name();
    MERC_RACE = (string)obj->query_race();
    if(!END_TIME) { END_TIME = (int)obj->get_end_time(); }
    MERC = obj;
    SETUP = 1;
}

int fire_merc(string str)
{
    object obj;

    if(!stringp(str) || str == "" || str == " ") { return 0; }
    if(str != "contract") { return 0; }

    tell_object(TP,"%^BOLD%^%^GREEN%^You terminate the mercenary contract.");

    if(!objectp(MERC))
    {
        if(time() > END_TIME) { HENCH_D->penalize(TP,"late"); }
        TO->remove();
        return 1;
    }
    MERC->fire_me();
    return 1;
}


int summon_merc(string str)
{
    object obj;

    if(!objectp(ETO) || !interactive(ETO)) { return 0; }
    if (str != "merc") {
        return 0;
    }
    if(!SETUP)
    {
        tell_object(ETO,"ERROR your whistle was not setup correctly... deleting.");
        TO->remove();
        return 0;
    }
    if(!stringp(str)) { return 0; }

    if(!objectp(MERC))
    {
        obj=new(PATH+"/henchman.c");
        MERC = obj;
        if(!objectp(obj)) { return 0; }
        obj->setup_merc("cleric",MERC_RACE,ETO,MERC_NAME);
        obj->set_my_whistle(TO);
        obj->move(HENCH_ROOM);
        setup_whistle(obj);
    }
    else { MERC->toggle_following(); }
    tell_object(TP,"You blow the magical whistle and it emits a sound that your ears cannot hear.");
    tell_object(TP,"It might take a moment for the mercenary to get to your location.");
    return 1;
}


int stuck_merc(string str)
{
    if(!SETUP)
    {
        tell_object(ETO,"ERROR your whistle was not setup correctly... deleting.");
        TO->remove();
        return 0;
    }

    summon_merc(str);
    MERC->set_heart_beat(1);
    MERC->move(EETO);
    MERC->toggle_following();

    return 1;
}


int ditch_merc(string str)
{
    if(!objectp(MERC)) { return 0; }

    MERC->ditch_hire();
    TP->remove_follower(MERC);
    MERC->force_me("speak wizish");
    MERC->force_me("say fine, I'll wait here.");
    return 1;
}
