#include <std.h>
#include <daemons.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("cylinder");
    set("id",({"cylinder","cylinder of smoke"}));
    set("short",
        "Cylinder of smoke"
    );
    set("long",
        "This cylinder is filled with a smoky green substance. There appears "
        "to be no way of opening the cylinder other than smashing it."
    );
    set_value(100);
    set_weight(10);
}
void init(){
    ::init();
    add_action("smash_func","smash");
}
int smash_func(string str) {
    object here,sucker,*players;
    object ob;
    int x,num_p,dam;
    int thaco = 0;
    if(!str) {
        notify_fail("Smash what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(str != "cylinder") {
        notify_fail("Smash what?\n");
        return 0;
    }
    if((int)TP->query_level() < 10) {
        notify_fail("Try as you might you cannot smash the cylinder\n");
        return 0;
    }
    write(
        "You smash the cylinder on the ground releasing "
        "a green cloud of smoke!\n"
        "Fearing the smoke you hold your breath."
    );
    say(
        ""+TPQCN+" smashes a cylinder releasing "
        "a thick green smoke!"
    ,TP);
    if(!(userp(environment(TO)))) {
        return 0;
    }
    here=environment(environment(TO));
    players=filter_array(all_living(here),"is_non_immortal_player",FILTERS_D);
    num_p=sizeof(players);
    for (x=0;x<num_p;x++) {
        sucker=players[x];
        ob=sucker;
        if((living(sucker)) && sucker !=this_player() &&
(int)sucker->query_max_level() < 100) {
            thaco = TP->Thaco(1,ob,TO);
            if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
            if( random(20)+1 > thaco){
                dam = random(15) + 5;
                tell_object(TP,
                    "The gas seizes "
                    +ob->query_cap_name()+"'s nerves!"
                );
                tell_object(ob,
                    "The gas seizes your nerves!"
                );
                ob->set_paralyzed(dam,"Your muscles are seized!"
                "");
            } else {            
                tell_object(ob,
                    "Fearing the smoke you hold your breath."
                );
            }           
        }
    }
    TO->remove();
    return 1;
}