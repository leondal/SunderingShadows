
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void jumping_succeed(object tp, int num);

void init() {
    ::init();
    add_action("jump_func", "jump");

}

void create(){
   ::create();
    set_long(::query_long()+"%^BLACK%^%^BOLD%^The cavern opens up to a raging underground river%^RESET%^.\n");
    set_exits(([
        "east" : ROOMS"ogremaze35",
        "southeast" : ROOMS"ogremaze38",
   ]));
 set_items
    (([
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The ground here is"+
"rough, uneven, and random outcroppings of %^BLACK%^%^BOLD%^obsidion%^RESET%^%^ORANGE%^"+
" make navigating difficult.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls here are rough, and"+
" mostly cloaked in shadows.%^RESET%^",
        ({"river", "water"}) : "%^BLUE%^%^BOLD%^A raging river runs through the cavern."+
" If you're lost, you might as well jump in and get more lost...%^RESET%^",
        ({"corpses"}) : "%^RESET%^%^ORANGE%^corpses of what look to be both ogres"+
" and various demons lay in varied stages of mutilation and decomposition. "+
"%^RESET%^%^YELLOW%^Rats %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^WHITE%^maggots"+
" %^RESET%^%^ORANGE%^swarm over the more recent piles...%^RESET%^",
        ({"mist"}) : "%^RESET%^%^BOLD%^A thick covering of mist covers the ground here.%^RESET%^",
    ]));

}

int jump_func(string str){

if(!str){return 0;
        }
    if((str == "water") || (str == "into water") || (str == "into river") || (str == "river")){
        jumping_succeed(TP,0);
        return 1;
    }
    tell_object(TP,"Jump what? You could jump into the water...\n");
    return 1;
    }


void jumping_succeed(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"%^RESET%^%^BOLD%^You step back then leap into the raging water!  \n");
                        break;
                case(1):tell_object(TP,"%^BLUE%^%^BOLD%^You hit the water hard!  \n");
                        break;
                case(2):tell_room(ETP,"%^RESET%^%^BOLD%^"+TPQCN+"%^RESET%^%^BOLD%^ steps back and leaps into the raging water! \n",TP);
                        break;
                case(6):tell_object(TP,"%^RESET%^%^ORANGE%^You are washed up down stream... \n");
                        tell_room(ETP,"%^RED%^%^BOLD%^"+TPQCN+" %^RESET%^%^RED%^disapears completely into the water! \n",TP);
                        switch(random(3)){
                        case(0):
                            TP->move_player(ROOMS"3_a.c");
                            TP->set_paralyzed(0);
                        break;
                        case(1):
                            TP->move_player(ROOMS"3_b.c");
                            TP->set_paralyzed(0);
                        break;
                        case(2):
                            TP->move_player(ROOMS"3_c.c");
                            TP->set_paralyzed(0);
                        break;
                        default:
                            TP->move_player(ROOMS"3_d.c");
                            TP->set_paralyzed(0);
                        break;
                        return;
                        }
                        return;
                }
    num++;
    call_out("jumping_succeed",0,tp,num);
    return;
}

