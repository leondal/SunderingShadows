#include <std.h>
#include <daemons.h>
#include <clock.h>

inherit OBJECT;

object controlled,caster,controller,feat;

void save_me(string file) { return 1; }

void create()
{
    ::create();
    seteuid(geteuid());
    set_name("device");
    set_id(({"devicex999"}));
    set_short("");
    set_long("");
    set_weight(0);
    set_property("no animate",1);
}

int drop() { return 1; }

int move(mixed dest)
{
   if(ETO && objectp(ETO))
   {
       if(interactive(ETO)) { return 0; }
   }
   ::move(dest);
   set_heart_beat(1);
}

set_caster(object ob)
{
   if(objectp(ob)) { caster = ob; }
   else remove();
}

void set_controller(object ob)
{
    if(!objectp(ob)) { return; }
    controller = ob;
    return;
}

void set_feat(object ob)
{
    if(objectp(ob)) { feat = ob; }
    return;
}

object query_feat() { return feat; }

object query_controller() { return controller; }

object query_controlled() { return controlled; }

object query_caster() { return caster; }

void set_controlled(object ob)
{
    if(objectp(ob)) { controlled = ob; }
    else remove();
}

void defend()
{
    object *attackers;
    int i;

    if(!objectp(caster)) { return; }
    if(!objectp(controlled)) { return; }

    attackers = caster->query_attackers();

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) { continue; }
        if(member_array(attackers[i],(object *)controlled->query_attackers()) != -1) { continue; }
        controlled->kill_ob(attackers[i],1);
        tell_room(environment(controlled),"%^BOLD%^%^RED%^"+controlled->query_short()+" attacks "
            ""+attackers[i]->QCN+"!%^RESET%^");
    }
    return;
}

void heart_beat()
{
   if(!objectp(caster)) remove();
   if(!objectp(controlled)) remove();
   if(sizeof((object *)caster->query_attackers())) { defend(); }
}

void remove() { if(objectp(TO)) return ::remove(); }

void init()
{
   ::init();
   add_action("cmd","command");
   add_action("dismiss","dismiss");
}

int cmd(string str)
{
    string who;
    object ob;

    if(!stringp(str) || str == " " || str == "") { return 0; }
    if(!objectp(caster)) { return 0; }
    if(!objectp(controlled)) { return 0; }

    if(strsrch(str,"armored titan to") != -1) { str = replace_string(str,"armored titan to ",""); }
    else if(strsrch(str,"titan to") != -1)    { str = replace_string(str,"titan to ",""); }
    else
    {
        return notify_fail("Syntax: command titan to <action> | command armored titan to <action>");
    }

    if(strsrch(str,"follow") != -1)
    {
        if(!present(controlled,environment(caster)))
        {
            tell_object(caster,""+controlled->query_short()+" must be present before it can follow you");
            return 1;
        }
        tell_object(caster,""+controlled->query_short()+" is now following you.");
        caster->remove_follower(controlled);
        caster->add_follower(controlled);
        return 1;
    }
    seteuid(geteuid(TO));

    if(!controlled->force_me(str))
    {
        tell_object(caster,"You fail to command "+controlled->query_short()+" to "+str+"");
        return 1;
    }
    return 1;
}

int dismiss(string str)
{
    if(!objectp(caster)) { return 1; }
    if(!objectp(controlled)) { return 1; }
    if(!stringp(str) || str == "" || str == " ") { return 1; }
    if(str != "titan" && str != "armored titan") { return 1; }

    caster->set_property("armoredtitan_timer",time() + HOUR);
    if(objectp(feat))
    {
        caster->remove_property_value("active_feats",({feat}));
        feat->dest_effect();
    }


    tell_object(caster,"%^BOLD%^You concentrate on the "+controlled->query_short()+" and send "
        "it away!%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" concentrates carefully and "
        ""+controlled->query_short()+" winks out of existance!%^RESET%^",caster);

    controlled->move("/d/shadowgate/void");
    controlled->remove();

    if(objectp(TO))
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
    }
    return 1;
}
