#include <std.h>

inherit OBJECT;

int number;

int *shave;



void create(){
    ::create();

    set_name("6 sided die");
    set_id(({"die","dice","6-sided dice"}));
    set_short("six-sided die");

    set_long("A carved cube of animal bone. each side has carved dots numbering one through six");

    number = 1;
    set_value(2);
    set_weight(2);

}

string query_short(){
    string sshort;
    sshort = ::query_short();
    if(!living(ETO)) {
        sshort += ", %^CYAN%^<"+number+">%^RESET%^%^BOLD%^%^MAGENTA%^ up%^RESET%^";
    }
    return sshort;
}

init(){
    ::init();

    add_action("roll","roll");
}

int roll(string str){
      if(ETO != TP || !id(str)){
        return notify_fail("Roll what?\n");
    }

    tell_room(ETP, TPQCN+" throws the dice out and watches them roll",TP);
    tell_object(TP,"You throw the dice out and watch them roll.");

    //shave logic

    number = random(6)+1;

    tell_room(ETP,"The die rolls, and stops with "+number+" up.");
    move(ETP);
    return 1;
}
