#include <std.h>

inherit OBJECT;


int clean_up(){return 1;}

void create(){
    ::create();
        set_id(({ "ferry","boat","ship" }));
        set_short("A ferry boat");
        set_long(
@FERRY
This is a ferry boat. The cost for a ferry ride is a mere 5 gp.
Once you pay 5 gold, you will be let on the ferry.
FERRY
);
        set_weight(10000);
}

void init(){
    ::init();
        add_action("pay","pay");
        add_action("board","board");
}

int board(string str) {

   if(!id(str))
     if (TO != present(str,ETO))
       return 0;
   write("%^BOLD%^The sailor stops you and holds his hand out for you to pay him.");
   return 1;
}
int pay(string str){
    string coin;
    int amount,inc,riders;
    object *ob;

        if(!str) return notify_fail("Pay how much, of what?\n");
//        if(TP->query_in_vehicle()) return notify_fail("Please dismount first. Horses are not allowed on the boat.");
        if(sscanf(str,"%d %s",amount,coin) != 2)
                return notify_fail("Try <pay 5 gold>!\n");
        if(coin != "gold") return notify_fail("You must pay with gold!\n");
        if(amount < 5) return notify_fail("It costs 5 gold!\n");
        if(!TP->query_funds(coin, amount))
                return notify_fail("You don't have that much "+coin+"!\n");
     	if(ob = all_inventory(find_object_or_load("/d/shadow/virtual/sea/obj/ferryroom1"))){
                for(inc = 0; inc < sizeof(ob);inc ++)
                        if(interactive(ob[inc])) riders += 1;
            if(riders > 10)
                        return notify_fail("Sorry, the ferry is full!\n");
        }
        TP->use_funds("gold",amount);
        write(
@BOARD

%^BOLD%^%^CYAN%^A clumsy sailor takes the gold from your hand, and drops it
into his pocket. He then waves you onto the ferry, and turns
away.
BOARD
);
        tell_room(environment(TO),TPQCN+" pays the sailor some money, and is allowed onto the ferry.",TP);
        tell_room(environment(TO),"The sailor yells out: Ferry leaves in one minute!");
        TP->move_player("/d/shadow/virtual/sea/obj/ferryroom1");
        return 1;
}
