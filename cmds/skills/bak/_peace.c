//	_peace.c
//	Monk and cleric ability
//	created by Descartes 14 November 1992

#include <std.h>

inherit DAEMON;


int cmd_peace(string str) {
    object *inv;
    int faith, i;

    if((int)this_player()->query_mp() < 10) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if((string)this_player()->query_class() == "kataan") {
        notify_fail("You want PEACE??????\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your power.\n");
        return 0;
    }
    faith = (int)this_player()->query_skill("faith");
    this_player()->add_mp(-10);
    if(random(51) > random(faith)) {
        notify_fail("Your faith does not bring peace, this time.\n");
        return 0;
    }
    write("You bring peace to the area.\n");
    say(this_player()->query_cap_name()+" raises "+this_player()->query_possessive()+" hands to the sky and brings peace to the area.\n", this_player());
    this_player()->add_skill_points("faith", 5);
    this_player()->add_alignment(5);
    inv = all_inventory(environment(this_player()));
    for(i=0; i<sizeof(inv); i++) {
        if(!living(inv[i])) continue;
        inv[i]->cease_all_attacks();
    }
    return 1;
}

void help() {
    write("Syntax: <peace>\n\n"+
        "This prayer brings full peace to all beings in an area.\n");
}
