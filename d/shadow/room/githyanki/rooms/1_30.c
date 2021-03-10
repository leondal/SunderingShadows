#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";
int faithful;


void init() {
    ::init();
    add_action("bow", "bow");
}

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall ends here...%^RESET%^\n");
    ob = new(OBJ"dragon_statue.c");
    set_exits(([
       "south" : ROOMS"1_31",
   ]));

}

void reset(){
   ::reset();
   if(!present("statue of tiamat")){
      new(OBJ"dragon_statue.c")->move(TO);
   }
}


int bow(string str,object who){
    object *inv;
    int i;
    faithful = 0;
    
    if(!str) {
       tell_object(TP,"%^BLACK%^%^BOLD%^Bow to what?\n%^RESET%^");
    return 1;
    }
    
    if(str == "statue"){
        tell_object(TP,"%^RED%^you bow...%^RESET%^");
        inv = all_inventory(TP);
            if (sizeof(inv)<1) { return 0 ;}
                for (i=0;i<sizeof(inv);i++){
                    if (inv[i]->id("symbol") && !inv[i]->id("gith symbol")){
                        tell_object(TP,"%^BLACK%^%^BOLD%^You feel a malign "+
"force flow over you, seeking something. Your %^WHITE%^holy symbol%^BLACK%^ begins to burn and"+
" you are forced to your knees in intense pain as the force of Tiamat rejects you");

                        set_property("magic",1);
                        TP->do_damage("torso",random(50)+30);
                        TP->add_attacker(TO);
                        TP->continue_attack();
                        TP->remove_attacker();
                        remove_property("magic");
                        tell_room(ETP,"%^RESET%^%^RED%^"+TPQCN+"%^RESET%^%^RED%^ bows to the statue, "+
"then falls to their knees in intense pain. You see the eyes of each dragon "+
"flare to life for a moment.%^RESET%^ ",TP);
                    return 1;
                    }
                    if (inv[i]->id("gith symbol")){
                        faithful = 1;

                    }
                }
            if (faithful == 1){
                tell_object(TP,"%^BLACK%^%^BOLD%^You feel a malign force flow "+
"over you, looking for something. The symbol of the Githyanki seems to warm "+
"slightly and the statue comes to life. Each head reaches forward, embracing "+
"you in a scaly grip. You feel yourself moved to another place...\n%^RESET%^");
                
            tell_room(ETP,"%^RESET%^%^RED%^As "+TPQCN+"%^RESET%^%^RED%^ bows "+
"to the statue, it suddenly comes alive. All of the heads suddenly snake "+
"forward and envelop them. The statue slowly returns to normal, and "+TPQCN+"%^RESET%^"+
"%^RED%^ is gone!",TP);
                TP->move_player(ROOMS"3_64.c");
                return 1;
            }
            if (faithful == 0){
                tell_object(TP,"%^BLACK%^%^BOLD%^You feel a malign "+
"force flow over you, seeking something. The searching becomes more intense and"+
" you are forced to your knees in intense pain as the force of Tiamat rejects"+
" you.\n%^RESET%^");
                set_property("magic",1);
                TP->do_damage("torso",random(50)+30);
                TP->add_attacker(TO);
                TP->continue_attack();
                TP->remove_attacker();
                remove_property("magic");
                tell_room(ETP,"%^RESET%^%^RED%^"+TPQCN+"%^RESET%^%^RED%^ bows to the statue, "+
"then falls to their knees in intense pain. You see the eyes of each dragon "+
"flare to life for a moment.%^RESET%^ ",TP);
                return 1;
            }
            return 1; 
            }

}
            