//   Inheritable to control the listings of members in guilds.
//   Basically automated through initiate and remove commands
//   this inheritable allows wiz control over messed up lists,
//   and allows the lists to be read.
//   If a new guild is added, this must be changed, specifically the #define
//   below to include the new guild.
//   created by Grendel@ShadowGate 3/7/98

#include <std.h>
#include <daemons.h>

inherit ROOM;

string guild_name, guild_object;

void sort(string *stuff);
private void swap(int i, int j, string *stuff);
void set_guild_name(string str);
void set_guild_object(string str);

void set_guild_name(string str) {
    guild_name = str;
    return;
}

void set_guild_object(string str){
    guild_object = str;
    return;
}

void create() {
    ::create();
}

void init() {
    ::init();
    add_action("read_fcn", "read");
    add_action("return_obj", "request");
    if(GUILDS_D->is_leader(guild_name, TPQN) || wizardp(TP)){
        add_action("appoint_hc", "appoint");
        add_action("demote_hc", "demote");
    }
     if(GUILDS_D->is_hc(guild_name,TPQN) || avatarp(TP)){
        add_action("add_fcn", "add");
        add_action("remove_fcn", "remove");
    }
}

int read_fcn(string str) {
    string guild;
    string *list;
    int i;
    if (!str) return notify_fail("Read what?\n");
    if (str != "sign" && str != "list") return notify_fail("That is not here.\n");

    if (str == "sign") {
        tell_object(TP, "%^BOLD%^%^RED%^In order to read a listing of your fellow guild members, type 'read list'.  If you are not on this list, or know someone that should be, please contact a wiz.%^RESET%^\n");
        tell_object(TP, "%^BOLD%^%^YELLOW%^To get your guild object back, type 'request'");
        if(GUILDS_D->is_leader(guild_name, TPQN) || wizardp(TP)){
            tell_object(TP, "%^BOLD%^%^BLUE%^Leader commands:");
            tell_object(TP, "%^BOLD%^%^BLUE%^    appoint <person>:  Assigns <person> as HC");
            tell_object(TP, "%^BOLD%^%^BLUE%^    demote <person>:  Removes <person> as HC");
            tell_object(TP, "%^BOLD%^%^BLUE%^    add <name>: adds named person to the guild's list,");
            tell_object(TP, "%^BOLD%^%^BLUE%^    remove <name>: removes name from the guild's list.");
        }
        if(GUILDS_D->is_hc(guild_name, TPQN) || wizardp(TP)){
            tell_object(TP, "\n%^BOLD%^%^BLUE%^HC commands:");
            tell_object(TP, "%^BOLD%^%^BLUE%^    add <name>: adds named person to the guild's list,");
            tell_object(TP, "%^BOLD%^%^BLUE%^    remove <name>: removes name from the guild's list.");
        }
        return 1;
    }

    if (str == "list") {
        if (!guild_name) {
            tell_object(TP, "%^BOLD%^ERROR: Notify a Wiz please!");
            return 1;
        }
        if (member_array(guild_name, (string *)GUILDS_D->query_all_guilds()) == -1) {
            tell_object(TP, "ERROR: Guild name is not one of the legal guilds.");
            return 1;
        }
        list = (string *)GUILDS_D->query_guild_members(guild_name);
        if (list == ({})) {
            tell_object(TP, "%^BOLD%^The list is currently empty.  Please contact a wiz.");
            return 1;
        }

        tell_object(TP, "For the guild "+guild_name+":");
        tell_object(TP, "Your leader is:  "+capitalize((string)GUILDS_D->query_guild_leader(guild_name)));

        tell_object(TP, "Your HC are:");
        list = (string *)GUILDS_D->query_guild_hc(guild_name);
        sort(list);
        for (i=0;i<sizeof(list);i++) {
            tell_object(TP, "%^BOLD%^   "+capitalize(list[i]));
        }

        list = (string *)GUILDS_D->query_guild_members(guild_name);
        tell_object(TP, "%^BOLD%^%^BLUE%^The members of your guild are:");
        sort(list);
        for (i=0;i<sizeof(list);i++) {
            tell_object(TP, "%^BOLD%^   "+capitalize(list[i]));
        }
        return 1;
    }
}

int add_fcn(string str) {
    string who;
    if (!str) return notify_fail("Add who?  More info please.\n");

    who = lower_case(str);

    if (member_array(guild_name, (string *)GUILDS_D->query_all_guilds()) == -1) {
        tell_object(TP, "That guild does not exist.");
        return 1;
    }

    if (GUILDS_D->is_member(guild_name, who)) {
        tell_object(TP, "That person is already on the list.");
        return 1;
    }

    GUILDS_D->add_guild_member(guild_name, who);
    tell_object(TP, "%^BOLD%^ "+who+" has been added to guild list "+guild_name+".");
    return 1;
}

int remove_fcn(string str) {
    string who;
    object ob;

    if (!str) return notify_fail("Remove who from what?  More info please.\n");
    who = lower_case(str);

    if (member_array(guild_name, (string *)GUILDS_D->query_all_guilds()) == -1) {
        tell_object(TP, "That guild does not exist.");
        return 1;
    }

    if (!GUILDS_D->is_member(guild_name, who)) {
        tell_object(TP, "That person not on the list.");
        return 1;
    }

    GUILDS_D->remove_guild_member(guild_name, who);
     if(ob = find_player(who)){
          ob->remove_guild(guild_name);
      }
    tell_object(TP, "%^BOLD%^ "+who+" has been removed from guild list "+guild_name+".");
    return 1;
}

int appoint_hc(string str){

    if(!str) return notify_fail("Who?\n");
    str = lower_case(str);
    if(!GUILDS_D->is_leader(guild_name, TPQN) && !wizardp(TP)) return 0;
    if(GUILDS_D->is_hc(guild_name, str)) return notify_fail("They are already HC.\n");
    if(!GUILDS_D->is_member(guild_name, str)) return notify_fail("They are not a member of this guild.");

    GUILDS_D->add_guild_hc(guild_name, str);
    tell_object(TP, str+" is now a HC of "+guild_name+".");

    return 1;
}

int demote_hc(string str){
    if(!str) return notify_fail("Who?\n");
    str = lower_case(str);
    if(!GUILDS_D->is_leader(guild_name, TPQN) && !wizardp(TP))
    if(!GUILDS_D->is_hc(guild_name, str)) return notify_fail("They are not HC.\n");

    GUILDS_D->remove_guild_hc(guild_name, str);
    tell_object(TP, str+" is no longer HC of "+guild_name+".");

    return 1;
}

int return_obj(string str){
    object ob;

    if(!guild_object || guild_object == "")
        return notify_fail("There is no object set.  Contact a wiz.\n");

    if(!GUILDS_D->is_member(guild_name, TPQN))
        return 0;

    ob = new(guild_object);

    if(present(((string *)ob->query_id())[0], TP))
        return notify_fail("You already have one!\n");

    tell_object(TP, "You request a new guild insignia");
    ob->move(TP);
    return 1;
}




void sort(string *stuff) {
    int i,j;

    for (j=0;j<sizeof(stuff);j++)
        for (i=sizeof(stuff)-1;i>j;i--) {
            if (stuff[i] < stuff[i-1]) {
                swap(i-1,i,stuff);
            }
        }
}

private void swap(int i, int j, string* stuff) {
    string tmp;

    tmp = stuff[i];
    stuff[i]=stuff[j];
    stuff[j]=tmp;
}
