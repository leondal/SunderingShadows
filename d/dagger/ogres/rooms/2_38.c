#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void jumping_fail(object tp, int num);
void jumping_succeed(object tp, int num);

void init() {
    ::init();
    add_action("jump_func", "jump");
    add_action("lever_func", "pull");

}

void create(){
   ::create();
set_long(::query_long()+"%^BLACK%^%^BOLD%^There is a giant chasm here. You can see the "+
"passage continue to the south. There is a drawbridge here...%^RESET%^.\n");
   set_exits(([
      "southwest" : ROOMS"2_39",
   ]));

    set_items
    (([
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The ground here is"+
"rough, uneven, and random outcroppings of rock make navigating difficult.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls here are rough, and"+
" mostly cloaked in shadows.%^RESET%^",
        ({"drawbridge"}) : "%^RESET%^%^ORANGE%^A drawbridge made from giant oak planks, "+
"this is obviously not of ogre design. The mechanism for operating the drawbridge "+
"is a lever and it seems to be powered by water!%^RESET%^",
        ({"chasm"}) : "%^BOLD%^%^BLACK%^The cave is cut by a giant chasm, dropping down "+
"into nothingness. Its not too far so you might be able to %^CYAN%^jump%^BLACK%^%^BOLD%^ but "+
"you might not make it.%^RESET%^",
        ({"lever"}) : "%^RESET%^%^ORANGE%^A giant lever sits near the drawbridge. You could %^BOLD%^pull%^RESET%^%^ORANGE%^ it.%^RESET%^",
        ({"corpses"}) : "%^RESET%^%^ORANGE%^corpses of what look to be both ogres"+
" and various demons lay in varied stages of mutilation and decomposition. "+
"%^RESET%^%^YELLOW%^Rats %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^WHITE%^maggots"+
" %^RESET%^%^ORANGE%^swarm over the more recent piles...%^RESET%^",
    ]));
add_exit(ROOMS"2_28","bridge");
}

int lever_func(string str) {
     object pow_rm;
     pow_rm =find_object_or_load( ROOMS"power");
    if(!str) {
        tell_object(TP,"Pull what?");
    return 1;
    }
    if((str == "lever") || (str == "wooden lever")){
        if(member_array("bridge",TO->query_exits()) != -1) {
            tell_object(TP,"%^RED%^The draw bridge is already lowered!%^RESET%^");
        return 1;
        }
        if (pow_rm->check_power()>3){
            tell_object(TP,"%^YELLOW%^You pull the lever and as water rushes through various mechanisms the drawbridge lowers to bridge the chasm!\n");
            tell_room(ETP,"%^YELLOW%^"+TPQCN+" %^YELLOW%^Pulls the lever and lowers the drawbridge!\n",TP);
            add_exit(ROOMS"2_28","bridge");
        return 1;
        }
            tell_object(TP,"%^RESET%^%^ORANGE%^You pull the lever and you hear a trickle of water. It doesn't seem there is enough water getting to whatever mechanism runs this%^RESET%^ \n");
            tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+"%^RESET%^%^ORANGE%^ Pulls the lever and and nothing happens!\n",TP);
    return 1;
    }
    tell_object(TP,"Pull what?");
    return 1;
}

int jump_func(string str){
        int roll,jump;
        roll = random(30);
        jump = TP->query_stats("dexterity"); 

if(!str){return 0;
        }
    if(str != "chasm"){
            tell_object(TP,"Jump what? You could jump the chasm...\n");
        return 1;
    }
    if(roll > jump) {
            TP->set_paralyzed(3000,"You are unable to do that!");
            jumping_fail(TP,0);
        return 1;
    }
        
    if(roll < jump) {
            TP->set_paralyzed(3000,"You are unable to do that!");
            jumping_succeed(TP,0);
        return 1;
    }
}
void jumping_fail(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"%^RESET%^%^BOLD%^You step back then leap across the chasm with all you can!  \n");
                        break;
                case(1):tell_object(TP,"%^RESET%^%^BOLD%^You flail your arms as you sail over the chasm!  \n");
                        break;
                case(2):tell_room(ETP,"%^RESET%^%^BOLD%^"+TPQCN+"%^RESET%^%^BOLD%^ steps back and leaps across the chasm! \n",TP);
                        break;
                case(3):tell_object(TP,"%^RED%^%^BOLD%^So close!  \n");
                        break;
                case(4):tell_object(TP,"%^RED%^%^BOLD%^Oh no!  \n");

                        break;
                case(5):tell_object(TP,"%^RED%^%^BOLD%^Not close enough! \n");
                        break;
                case(6):tell_object(TP,"%^RED%^%^BOLD%^There goes the ledge!!! \n");
                        tell_room(ETP,"%^RED%^%^BOLD%^"+TPQCN+" %^RESET%^%^RED%^screams as they don't quite make it! \n",TP);
                        break;
                case(7):tell_object(TP,"%^BLACK%^%^BOLD%^You fall into the darkness!!!  \n");
                        break;
                case(8):tell_object(TP,"%^BLACK%^%^BOLD%^You hear.. rushing water?  \n");
                        break;
                case(9):tell_object(TP,"%^BLUE%^%^BOLD%^You fall into an underground river, and are swept away... \n");
                        break;
                case(10):tell_object(TP,"%^RESET%^%^ORANGE%^You are washed up on a shore deeper underground... \n"); 
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
                }
    num++;
    call_out("jumping_fail",0,tp,num);
    return;
}

void jumping_succeed(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"%^RESET%^%^BOLD%^You step back then leap across the chasm with all you can!  \n");
                        break;
                case(1):tell_object(TP,"%^RESET%^%^BOLD%^You flail your arms as you sail over the chasm!  \n");
                        break;
                case(2):tell_room(ETP,"%^RESET%^%^BOLD%^"+TPQCN+"%^RESET%^%^BOLD%^ steps back and leaps across the chasm! \n",TP);
                        break;
                case(3):tell_object(TP,"%^RED%^%^BOLD%^So close!  \n");
                        break;
                case(4):tell_object(TP,"%^RED%^%^BOLD%^Oh YES!  \n");

                        break;
                case(5):tell_object(TP,"%^RED%^%^BOLD%^You JUST make the ledge \n");
                        break;
                case(6):tell_object(TP,"%^RESET%^%^BOLD%^You pull yourself up! \n");
                        tell_room(ETP,"%^RED%^%^BOLD%^"+TPQCN+" %^RESET%^%^RED%^cheers as they pull themselves up onto the ledge! \n",TP);
                        TP->move_player(ROOMS"3_1.c");
                        TP->set_paralyzed(0);
                        return;
                }
    num++;
    call_out("jumping_succeed",0,tp,num);
    return;
}
