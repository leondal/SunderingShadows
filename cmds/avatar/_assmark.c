#include <std.h>

inherit DAEMON;

int help(){
    write(
"
%^CYAN%^NAME%^RESET%^

assmark - marks a player as an assassination target

%^CYAN%^SYNTAX%^RESET%^

assmark %^ORANGE%^%^ULINE%^PLAYER%^RESET%^ %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ %^ORANGE%^%^ULINE%^REASON%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Attach %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ of marks of assassination to %^ORANGE%^%^ULINE%^PLAYER%^RESET%^ for %^ORANGE%^%^ULINE%^REASON%^RESET%^. This will cause %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ of assassins to hunt %^ORANGE%^%^ULINE%^PLAYER%^RESET%^ after a small amount of time has passed. These assassins are scaled to the level of the player and the %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ should be representative of the value of the bounty on their head reflected by the %^ORANGE%^%^ULINE%^REASON%^RESET%^. The %^ORANGE%^%^ULINE%^REASON%^RESET%^ will be noted in the notes of the %^ORANGE%^%^ULINE%^PLAYER%^RESET%^.  These assassins will (or should) show up simultaneously.  Anything greater than two is most likely an automatic death sentence.

This command is meant to be a tool to address low effort conflict that the game world cannot respond to properly by itself. An example would be a player continuing to harass a city and kill guards without thought of repercussion. One to two asassins should be enough to take an unsuspecting player by surprise, any more would be an almost guaranteed death for even the most seasoned.

%^CYAN%^SEE ALSO%^RESET%^

note
"
    );
    return 1;
}

int cmd_assmark(string str){
    int num, i;
    string who,reason;
    object player;

    string posxxx;
    if(!objectp(TP)) return 0;
    posxxx = lower_case((string)TP->query_position());
    if(posxxx == "builder" || posxxx == "apprentice") {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
    }

    if (!str) return help();

    if (sscanf(str, "%s %d %s", who, num, reason) != 3) return help();

    player = find_player(who);
    if (!objectp(player)) return notify_fail("That player isn't around.\n");

    write("%^BOLD%^You attach "+num+" assassin marks to "+capitalize(who));

    for(i=0;i<num;i++) {
        object mark;
        mark = new("/d/common/assassins/obj/mark");
        mark->set_reason(reason);
        mark->move(player);
    }

    "/cmds/avatar/_note.c"->cmd_note("ckpt "+player->query_name()+" %^BOLD%^%^RED%^was marked with "+num+" mark(s) of assassination by "+capitalize(TP->query_true_name())+" for "+reason+".%^RESET%^");

    return 1;
}
