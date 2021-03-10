//      /bin/user/_party.c
//      handles all party commands
//     created 111192 by Descartes of Borg
// changing to fix so can't tell if someone, or self, is invis., last change was 10/02  *Styx*  8/16/03


#include <std.h>
#include <party.h>

inherit DAEMON;

int form(string str);
int leave();
int join_party(string str);
int add_member(string str);
int sub(string str);
int leader(string str);
int list();
int party_line(string str);
int party_emote(string str);
void help();

int cmd_party(string str){
    string com, extra;

    //if(wizardp(this_player())) return 0;
    if(!str) {
        help();
        return 1;
    }
    if(sscanf(str, "%s %s", com, extra) == 2) {
        switch(com) {
            case "form": return form(extra); break;
            case "leave": return leave(); break;
	    case "join": return join_party(extra); break;
            case "add": return add_member(extra); break;
            case "remove": return sub(extra); break;
            case "leader": return leader(extra); break;
            case "list": return list(); break;
            //case "line": return party_line(extra); break;
            //case "emote": return party_emote(extra); break;
            default: help(); return 1; break;
        }
    }
    else {
        if(str == "leave") return leave();
        else if(str == "list") return list();
        else {
            help();
            return 1;
        }
    }
}

int form(string str) {
    string *tmp;
    int x;

    tmp = (string *)PARTY_OB->query_parties();
    if(!tmp) tmp = ({});
    if(member_array(str, tmp) != -1) {
        notify_fail("A party by that name already exists.\n");
        return 0;
    }
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
        notify_fail("You are already a member of another party.\n");
        return 0;
    }
    write("%^BOLD%^%^GREEN%^You form the party "+str+".\nYou are the leader.\n");
    return 1;
}

int leave() {
    int x;
    string party;

    party = (string)TP->query_party();
    if(!party) return 1;
    x = (int)PARTY_OB->remove_member(this_player());
    if(x==NOT_MEMBER) {
        notify_fail("You are not a member of any party!\n");
        return 0;
    }
// changed to capitalize.. getParsableName from QCN
    write("%^MAGENTA%^You leave your party.\n");
    return 1;
}

int add_member(string str) {
    object ob;
    string party;
    int x;

    str = TP->realNameVsProfile(str);
    ob = find_player(str);
    if(!ob) {
        notify_fail("No player by that name on the mud.\n");
        return 0;
    }
    if(wizardp(ob)) {
        notify_fail("Immortals may not join.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to add any members!\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of your party to add any members!\n");
        return 0;
    }
    PARTY_OB->add_invited(ob, party);
// changed to capitalize.. getParsableName from QCN
    PARTY_OB->notify_party(party, capitalize((string)ob->getParsableName())+" has been invited to join the party.");
    tell_object(ob, "%^BOLD%^%^RED%^"+capitalize(TP->getParsableName())+" invites you to join the party \""+party+"\".\n%^RESET%^You have 60 seconds to type <party join "+party+">.\n");
    return 1;
}

int sub(string str) {
    object ob;
    string party;
    int i;

    str = TP->realNameVsProfile(str);
    ob = find_player(str);
    if(!ob) {
//        write(identify(ob));
        notify_fail("That player is not on the mud.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to remove a member.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of the party to remove a member.\n");
        return 0;
    }
    i = (int)PARTY_OB->remove_member(ob);
    if(i==NOT_MEMBER) {
// fixing invis. here too, changed to capitalize.. getParsableName from QCN
  //getParsableName() here was returning their real name, so
  //I've changed it to do knownAs(str) - str is their real
  //name and knownAs() returns what you know them as - Saide 4/08/04
        notify_fail(capitalize(TP->knownAs(str))+" is not a member of your group.\n");
        return 0;
    }
// and invis. here
    PARTY_OB->notify_party(party, capitalize(TP->knownAs(str))+" is no longer in the group.");
    return 1;
}

int leader(string str) {
    object ob;
    string party;
    int x;

    str = TP->realNameVsProfile(str);
    ob = find_player(str);
    if(!ob) {
        notify_fail("That player is not on line.\n");
        return 0;
    }
    if(ob == this_player()) {
        notify_fail("You are already the leader!\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must lead a group before you may change its leader.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of a group in order to change the leadership.\n");
        return 0;
    }
    if((string)ob->query_party() != party) {
        notify_fail(ob->query_cap_name()+" is not in your party!\n");
        return 0;
    }
    x = (int)PARTY_OB->change_leader(ob);
    if(x != OK) {
        notify_fail("Leadership change failed.\n");
        return 0;
    }
    write("You are no longer the leader.\n");
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" is now the party leader.");
    return 1;
}

int list() {
    object *who;
    int i;
    string party;

    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of any party.\n");
        return 0;
    }
    who = (object *)PARTY_OB->query_party_members(party);
    if(!sizeof(who)) {
        notify_fail("You are no longer in a party.\n");
        return 0;
    }
    write("%^BOLD%^%^CYAN%^The following are members of the party %^WHITE%^"+party+"%^CYAN%^:");
    write(" %^BOLD%^%^RED%^"+capitalize((string)who[i]->getParsableName())+"%^RESET%^%^WHITE%^ (leader)");

    for(i=0; i<sizeof(who); i++) {
        if(!i) continue;
	write(" %^BOLD%^%^RED%^"+capitalize(who[i]->getParsableName())+"");
    }
    return 1;
}

int join_party(string str) {
    int x;

    if(!str) return 0;
    if(!PARTY_OB->invited_now(this_player(), str)) {
	notify_fail("You must be invited into a party in order to join.\n");
	return 0;
    }
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
	notify_fail("You are already in another party!\n");
	return 0;
    }
// fixing invis. & real name problem here too
    PARTY_OB->notify_party(str, capitalize(TP->getParsableName())+" has joined the party.\n");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

party -- manage your party

%^CYAN%^SYNTAX%^RESET%^

party [form|join] %^ORANGE%^%^ULINE%^NAME%^RESET%^
party [add|remove|leader] %^ORANGE%^%^ULINE%^PLAYER%^RESET%^
party list
party leave

%^CYAN%^DESCRIPTION%^RESET%^

This command accesses the various party enabling functions. The person who forms any party is automatically the leader of the party. Only that player may add or remove players. That player may also designate another player as the party leader.

%^CYAN%^SEE ALSO%^RESET%^

levelcheck, follow, unfollow, followers, who, kill, threaten, flag
");
}

int party_line(string str) {
    string party, pl_name;

    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of a party.\n");
        return 0;
    }
    //str= "daemon/language_d"->translate(str, TP->query_spoken(), TP);
    pl_name = capitalize((string)this_player()->query_name());
    if(avatarp(TP) && TP->query_disguised()) pl_name = capitalize(TP->query_vis_name());
       PARTY_OB->message_party(party,"%^RESET%^"+str);
    return 1;
}

int party_emote(string str){
    string party, pl_name;

    if(TP->query("emote loss")) return 0;


    party = (string)this_player()->query_party();
    if(!party){
        notify_fail("You are not a member of a party.\n");
        return 0;
    }
    pl_name = capitalize((string)this_player()->query_name());
    if(avatarp(TP) && TP->query_disguised()) pl_name = capitalize(TP->query_vis_name());

    PARTY_OB->party_emote(party, "%^RESET%^"+pl_name+" "+str);
    return 1;
}
