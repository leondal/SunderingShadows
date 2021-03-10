#include <std.h>
#include <daemons.h>

inherit ARMOUR;
string guild_name;
string guildobj;

int query_secret_guild();

void create() {
    ::create();

}

void init() {
    ::init();   
    if (objectp(ETO) && living(ETO) && present(query_id()[0]+" 2",TP))
        remove();

    if (!TP->in_guild(guild_name) && !avatarp(TP)) {
        remove();
    }

    if (!GUILDS_D->is_hc(guild_name, TPQN) && !avatarp(TP))
        return;

//    add_action("__Bring", "bring");
    add_action("__Initiate", "initiate");
    add_action("__Retire", "retire");
}

int __Initiate(string str) {
    object ob, tmp;
    int i,j;
    string theGuild;

    if (!GUILDS_D->is_hc(guild_name, TPQN) && !avatarp(TP))
        return 0;
    
    if (!str)
        return notify_fail("Initiate whom?\n");
    
    if(sscanf(str, "%s into %s",str, theGuild) == 2){
        if(theGuild != guild_name) return notify_fail("You can not do that.\n");
    }
    if (!(ob=present(lower_case(str), ETP)) || !living(ob))
        return notify_fail("No one of that nature here.\n");
    
    if (!interactive(ob))
        return notify_fail("You can only initiate players.\n");
    
    if ( (int)ob->query_level() < 10)
        return notify_fail("That player is not high enough level to be initiated.\n");
    
    if (ob->in_guild(guild_name))
        return notify_fail("That person is already a member.\n");
    
    ob->add_guild(guild_name);
    GUILDS_D->add_guild_member(guild_name, ob->query_name());
    ob->update_channels();
    new(guildobj)->move(ob);

    message("info", "You are now a member of the "+guild_name+".", ob);
    message("other_action", (string)ob->query_cap_name() +" is now a member of the "+guild_name+".", environment(ob), ({ob}));
    return 1;
}

int __Retire(string str) {
    object ob, tmp;
    int i,j;
    string *ids, id;

    if (!GUILDS_D->is_hc(guild_name, TPQN) && !avatarp(TP))
        return 0;
    
    if (!str)
        return notify_fail("Retire whom?\n");
    
    if (!(ob = present(lower_case(str), ETP)))
        return notify_fail(sprintf("No %s here!\n", capitalize(str)));

    if (!living(ob))
        return notify_fail(sprintf("%s is not alive!\n", capitalize(str)));

    if (!ob->in_guild(guild_name))
        return notify_fail(capitalize(str)+" is not one of us!\n");
        
    if (ob == TP)
        return notify_fail("You cannot retire yourself, find another HC member.\n");
    
    ob->remove_guild(guild_name);

    GUILDS_D->remove_guild_member(guild_name, ob->query_name());
    message("my_action", capitalize(str)+" is no longer a member of the "+guild_name+"!", this_player());
    message("other_action", (string)TP->query_cap_name() +" has removed you as a member of the "+guild_name+"!", ob);
    
    return 1;
}

/*
int __Bring(string str) {
    object who;

    if (!str)
         return notify_fail("Bring whom?\n");

    if (!(who = find_player(lower_case(str))))
        return 0;
    
    if (wizardp(who))
        return 0;
    
    if (member_array(guildname, (string *)who->query_guild() == -1) )
        return notify_fail(capitalize(str)+" is not one of you!\n");

    if (environment(who)->query_property("no teleport")) {
        notify_fail("A magic force blocks your powers.\n");
        return 0;
    }
    
    if (environment(this_player())->query_property("no teleport")) {
        notify_fail("A magic force blocks your powers.\n");
        return 0;
    }

    who->move_player(environment(this_player()));
    return 1;
}
*/

int get() {
    return 1;
}

int drop() {
    return 1;
}


void set_guild_name(string str) {
    guild_name = str;
}

string query_guild_name() {
    return guild_name;
}

void set_guild_object(string str){
    guildobj = str;
}

string query_guild_object(){
    return guildobj;
}
