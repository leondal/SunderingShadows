//      /bin/user/_money.c
//      from the Nightmare mudlib
//      a comand to allow players to search their pockets
//      created by Descartes of Borg 25 april 1993

#include <str_fmt.h>

#include <std.h>

inherit DAEMON;

int cmd_money(string str) {
    string *currs;
    string borg;
    int i, tmp;

    if(str) return 0;  /* to allow the wiz command to work */
    currs = (string *)this_player()->query_currencies();
    if(!currs || !sizeof(currs)) {
        write("You are broke.");
     tell_room(ETP,this_player()->query_cap_name()+" comes up with empty pockets.",TP);
        return 1;
    }
    write("%^BOLD%^%^CYAN%^In your pockets you find these coins:");
    for(i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg = sprintf(" %%^CYAN%%^%-10s%%^MAGENTA%%^:  %%^GREEN%%^%s %%^BOLD%%^%%^GREEN%%^coins.",capitalize(currs[i]),english_number(this_player()->query_money(currs[i])));
    	write((borg));
    }
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

money - look into your purse

%^CYAN%^DESCRIPTION%^RESET%^

Money are mysterious substance that makes you happier when you have more of it.

This command displays currency you have on yourself.

%^ULINE%^%^CYAN%^Money conversions:%^RESET%^

1 platinum = 5 gold = 10 electrum = 50 silver = 500 copper

%^ULINE%^%^CYAN%^Charu numerals:%^RESET%^

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Left number to larger subtracts.
Right number to larger adds.
Stortest way to write a number prevails in common use.

%^CYAN%^SEE ALSO%^RESET%^

inventory, eq, score, give, pp, steal
"
    );
}
