
//bounty.c

#include <std.h>
#include <daemons.h>

inherit ROOM;

void sort(string *bounties);private void swap(int i, int j, string *bounties);
string dink;

void create(){
    ::create();
    set_property("training",1);
    dink = FINGER_D->user_finger_display("jim");
}

void init(){
    ::init();

    add_action("post","issue");
    add_action("read","read");
    add_action("revoke", "revoke");
}

int read(string str){
    string *bounties, *pbounties, tmp, alias;
    mapping mbounties;
    int i, j;

    bounties = ({});
    pbounties = ({});
    mbounties = ([]);
    if (!str || (str != "bounty board" && str != "board" && str != "sign"))
        return 0;
    if (str == "board" || str == "bounty board") {
        bounties = KILLING_D->query_bounties();
        pbounties = KILLING_D->query_personals();
        mbounties = KILLING_D->query_personal_bounties();
        //query_bounty_dead(name);

        write("%^BOLD%^%^MAGENTA%^\t\t\tThe Bounty Board\n");
        write("%^BOLD%^%^CYAN%^\t   Bounties have been placed by the law on:\n");

        i = sizeof(bounties);
        if (bounties && i)
            sort(bounties);
        for (j=0;j<i;j++) {
                alias = KILLING_D->query_bounty_alias(bounties[j]);
                if (KILLING_D->query_bounty_dead(bounties[j]))
                    tmp = "\t%^BOLD%^"+arrange_string(capitalize(alias)+ ", %^RESET%^%^MAGENTA%^"+USERCALL->user_call(bounties[j],"getWholeDescriptivePhrase"),60)+"%^YELLOW%^ : DEAD";
                else
                    tmp = "\t%^BOLD%^"+capitalize(alias)+ ", %^RESET%^%^MAGENTA%^"+USERCALL->user_call(bounties[j],"getWholeDescriptivePhrase");
                write(tmp);
                //tmp = arrange_string(tmp, 15);
        }
        if (!avatarp(TP) && !TP->query("is_assassin")) return 1;
        write("\n");
        write("%^BOLD%^%^CYAN%^\tThe following rewards are offered by private citizens:\n");
        j = sizeof(pbounties);
        if (pbounties && j)
            sort(pbounties);
        for (i=0;i<j;i++)
            write("%^BOLD%^%^YELLOW%^\t   A reward of "+mbounties[pbounties[i]]["money"]+" is offered for "+capitalize(pbounties[i])+"!");
        tell_room(TO,TPQCN+" reads over the bounty board!",TP);
        return 1;
    }
    if (str == "sign") {
        write("%^BOLD%^The sign reads:");
        write("%^BOLD%^%^ORANGE%^To post a bounty on another player");
        write("%^BOLD%^%^ORANGE%^ \t\tissue bounty for <amount gold> on <name>.");
        write("%^BOLD%^%^ORANGE%^To remove a personal bounty upon someone's head");
        write("%^BOLD%^%^ORANGE%^\t\t type 'revoke bounty on <name>'  The cost is 3 times the bounty.");
        write("%^BOLD%^%^ORANGE%^To see what bounties are currently issued");
        write("%^BOLD%^%^ORANGE%^ \t\t read board");
        tell_room(TO,TPQCN+" reads the sign!",TP);
        return 1;
    }
    return 0;
}

int post(string str){
    int money,min;
    string name;

    if (!str) return notify_fail("Syntax: issue bounty for <amount> on <name>. (the amount is always in gold)\n");
    if (!interactive(TP)) return notify_fail("The bondsman smirks and just shakes his head at the strange things that come in here nowadays.\n");

    if (sscanf(str,"bounty for %d on %s", money, name) != 2)
        return notify_fail("Syntax: issue bounty for <amount gold> on <name>.\n");
/*
    if(member_array(name,KILLING_D->query_personals()) != -1)
        return notify_fail("There is currently a bounty issued for that person!\n");
*/
    if ((string)FINGER_D->user_finger_display(name) == dink)
        return notify_fail(dink);
    min = (int)(TP->query_lowest_level())*500;
    if (min<1000) min = 1000;
    if (wizardp(TP)) min = 1000;
    if (money < min)
        return notify_fail("The minimum bounty for your level is "+min+" gold!\n");
    if (name == (string)TPQN && (int)TP->query_alignment() != 8)
        return notify_fail("Only crazy people may issue bounties on themselves!\n");
    if (!TP->query_funds("gold",money)) {
        write("%^BOLD%^The bondsman says you need to have the money with you and in gold!");
        tell_room(TO,"%^BOLD%^The bondsman tells "+TPQCN+" that the money needs to be present and in gold!",TP);
        return 1;
    }

    write("%^BOLD%^The bondsman takes down all the information and your money.");
    tell_room(TO,"%^BOLD%^The bondsman takes down some information from "+TPQCN+" and takes some money!",TP);
    name = lower_case(name);
    if (str = KILLING_D->add_personal_bounty(name, TP, money)) {
        write(str);
        return 1;
    }

    TP->use_funds("gold",money);
    return 1;
}

int revoke(string str){
    mapping stuff;
    int amount;
    string name,who;
    string *list;

    if (!TP->query("is_assassin") && !TP->is_class("assassin") && !avatarp(TP))
        return notify_fail("The bondsman gives you a strange look and turns back to his work.\n");
    if (!str) {
        tell_object(TP, "Syntax: revoke bounty on <name>. Cost: 3 times amount of the bounty.\n");
        return 1;
    }
    if (sscanf(str,"bounty on %s",who) != 1)
        return notify_fail("Syntax: revoke bounty on <name>. Cost: 3 times amount of the bounty.\n");

    stuff = KILLING_D->query_personal_bounties();
    name = (string)TP->query_name();
    list = KILLING_D->query_personals();
    if (member_array(who, list) == -1) {
        tell_object(TP, "There is no bounty on "+who+"'s head!");
        return 1;
    }
    amount = stuff[who]["money"];
    amount *= 3;
    if (!TP->query_funds("gold",amount)) {
        tell_object(TP, "You must have 3 times the amount of the bounty, "+amount+" in your case, to buy off the bounty.\n");
        return 1;
    }

    TP->use_funds("gold", amount);
    TP->force_me("save");
    tell_object(TP, "The bondsman laughs.\n");
    tell_object(TP, "The bondsman says:  How's it feel getting some easy money from those fool?\n");
    message("broadcast",
            "%^BOLD%^%^ORANGE%^The bounty on "+capitalize(who)+" has been revoked!\n",
            users());
    log_file("bounties", "Personal bounty on "+who+" revoked by "+name+" at "+ctime(time())+".\n");
    KILLING_D->remove_personal_bounty(who);
    return 1;
}

void sort(string *bounties){
    int i,j;

    for (j=0;j<sizeof(bounties);j++) {
        for (i=sizeof(bounties)-1;i>j;i--) {
            if (bounties[i] < bounties[i-1]) {
                swap(i-1,i,bounties);
            }
        }
    }
}

private void swap(int i, int j, string *bounties){
    string tmp;

    tmp = bounties[i];
    bounties[i]=bounties[j];
    bounties[j]=tmp;
}
