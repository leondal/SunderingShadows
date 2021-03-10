#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit OBJECT;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_id(({"bloodshard","blood shard","shard"}));
    set_name("bloodshard");
    set_short("%^BOLD%^%^RED%^b%^RESET%^%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^ds%^BOLD%^%^RED%^h%^RESET%^%^RED%^ard%^RESET%^");
    set_weight(5);

    set_long("%^RED%^This elongated piece of %^RED%^dark %^RED%^re%^BOLD%^%^RED%^d%^RESET%^ %^RED%^glass%^BOLD%^%^RED%^,%^RESET%^%^RED%^ known as bloodshard, seems to %^RED%^fl%^BOLD%^%^RED%^o%^RESET%^%^RED%^w%^RED%^ in its irregular %^RED%^sh%^BOLD%^%^RED%^a%^RED%^p%^RESET%^%^RED%^e%^RED%^ at a slow pace. Just by looking at it you experience.. Some form of discomfort. Perhaps even pain? Yet is warm on touch and doesn't feels dangerous. Closer, you can see an etching in unknown tongue, yet you still can %^BOLD%^%^BLACK%^<read bloodshard>%^RESET%^%^RED%^ and understand what it says.
");

    set_lore("Regardless of the origin of powers within, this piece of bloodglass will teleport to relative safety when broken, even from the deepest dungeons.");
    set_read("%^BOLD%^%^RED%^IN DESPERATION <BREAK BLOODSHARD> TO AVOID YOUR MORTAL MISERY%^RESET%^");
    set_language("wizish");

    set_value(6000);
}

void init()
{
    ::init();
    if(!objectp(TO))
        return;
    if(!interactive(ETO) ||
       !userp(ETO))
        return;
    add_action("break_fun", "break");
}

int break_fun(string args)
{
    if(!stringp(args) ||
       args != "bloodshard")
        return 0;

    if(sizeof(TP->query_attackers()))
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^THERE IS ONLY ONE ESCAPE IN COMBAT. DIE OR <KILL YOURSELF>.%^RESET%^");
        return 1;
    }

    if(TP->query_property("bloodshard")+1800>time())
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^THE SHARD WON'T BREAK THAT SOON. DIE OR <KILL YOURSELF>.%^RESET%^");
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^RED%^SO BE IT.%^RESET%^");
    tell_object(TP,"%^RED%^As the shard %^RED%^s%^BOLD%^%^RED%^h%^RESET%^%^RED%^a%^BOLD%^%^RED%^t%^RESET%^%^RED%^t%^BOLD%^%^RED%^e%^RESET%^%^RED%^rs%^RED%^ dark mist envelops you.");

    call_out("do_teleport",ROUND_LENGTH, TP);

    return 1;
}

void do_teleport(object who)
{
    object *stuff;
    int i;

    if(!objectp(who))
        return;
    tell_object(who,"%^BOLD%^%^RED%^You feel a pull on the soul, then outside power drags you elsewhere.%^RESET%^");

    stuff=all_inventory(who);
    for (i=0;i<sizeof(stuff);i++)
    {
        if(!objectp(stuff[i]))
            continue;
        if(stuff[i]->id("questob"))
        {
            tell_object(who,"%^BOLD%^%^RED%^The mist consumes your "+stuff[i]->query_short()+"!%^RESET%^");
            stuff[i]->remove();
        }
    }

    who->move_player("/d/darkwood/room/road18.c","with a loud clap");
    who->set_asleep(36, "You are stunned into slumber after shock of sudden teleportation!");
    who->do_damage("torso",who->query_hp()-1);
    who->remove_property("bloodshard");
    who->set_property("bloodshard",time());

    log_file("player/bloodshards",identify(who)+" "+file_name(ENV(who))+"\n");

    tell_object(who,"%^BOLD%^%^RED%^Bloodshard is destroyed.%^RESET%^");

    TO->remove();
}
