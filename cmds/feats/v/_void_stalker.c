#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <teleport.h>
inherit FEAT;

int DELAY = 300;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Assassin");
    feat_name("void stalker");
    feat_syntax("void_stalker TARGET");
    feat_prereq("Assassin L7");
    feat_desc("This feat allows an assassin to travel through primordial nothing directly to his target. The strain of such action prevents them from doing it frequently.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("assassin") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_void_stalker(string str)
{
    object ob,location;
    string target;

    if(!objectp(TP))
        return 0;
    if(!stringp(str))
        return 0;
    if(!str)
        return 0;

    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed())
    {
        TP->send_paralyzed_message("info",ETO);
    }

    if(TP->query_property("void_stalker_used")>time())
    {
        tell_object(TP,"You can not touch the void beyond yet.");
        return 1;
    }

    target = TP->realNameVsProfile(str);
    ob = find_player(target);

    if(!ob)
    {
        notify_fail("Nothing happens.");
        return 1;
    }

    tell_object(ETO, "%^BOLD%^%^WHITE%^You concentrate on the nothing beyond, thinking of your target.");

    location = environment(find_living(target));

    if(!TELEPORT->object_can_be_teleported(TP,location,TP->query_base_character_level()))
    {
        notify_fail("Something is blocking your path.");
        return 1;
    }
    else
    {
        TP->move_player(location);
        tell_object(TP,"%^BOLD%^%^WHITE%^You have arrived.");
        TP->set_property("void_stalker_used",time()+DELAY);
        return 1;
    }

    return 1;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
