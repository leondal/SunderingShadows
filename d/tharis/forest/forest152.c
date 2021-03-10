//forest152.c

#include <std.h>
#include "./forest.h"

inherit ROOM;

void create(){
    ::create();
    set_name("An ettercap's trap");
    set_short("A small path through the forest");
    set_property("indoors",0);
    set_property("light",1);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
As you enter the forest you notice a quiet all around you. Tall trees
loom over you almost basking in their grandure. Around you you
sense a horrible feeling of pain. Nature's work is here but that
work is being hurt. Small plants grow around the floor of the forest,
fighting for sunshine as it creeps sparcely through the thick canopy.
The ground draws your eye.
OLI
    );
    set_items((["floor":"The ground is cluttered  with twigs and leaves.",
                "trees":"These grand creatures range from oak and hickory to Pine and spruce.",
                "ground":"You notice a small cob web across the paths to the northeast and northwest.",
                "cobweb":"You notice that it is connected to a bent tree. You would have to disarm the trap to go further."
                ]));
    set_exits(([
                "southeast":TFOREST"forest151",
                "northeast":TFOREST"forest157",
                "northwest":TFOREST"forest153",
                ]));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
    find_object_or_load(TFOREST"forest71");
    set_trap_functions(({"northwest","northeast"}),({"kill_em","kill_em2"}),({"northwest","northeast"}));
}

int kill_em(){
    write("%^BOLD%^As you walk northwest you casually brush away a small cob web, but....");
    tell_room(TO,"%^BOLD%^As "+TPQCN+" walks northwest "+TP->query_cap_name()+" cassually brushes away a cob web.",TP);
    toggle_trap("northwest");
    call_out("falling",1,TP);
    return 1;
}

int kill_em2(){
    write("%^BOLD%^As you walk northeast you casually brush away a small cob web, but....");
    tell_room(TO,"%^BOLD%^As "+TPQCN+" walks northeast "+TP->query_cap_name()+" cassually brushes away a cob web.",TP);
    toggle_trap("northeast");
    call_out("falling",1,TP);
    return 1;
}

void falling(object targ){
    object ob;
    if(objectp(targ)){
        if(present(targ->query_name())){
            tell_room(TO,"%^BOLD%^%^YELLOW%^Suddenly several bent sapplings snap up, launching several small rocks.");
            write("%^BOLD%^%^YELLOW%^The rocks seem to be directed at you!");
            tell_room(TO,"%^BOLD%^%^YELLOW%^The rocks seem directed at "+targ->query_name(),targ);
            write("%^BOLD%^%^YELLOW%^The rocks smash into your body with crushing force, leaving you incapacitated.");
            tell_room(TO,"%^BOLD%^%^YELLOW%^The rocks smash into "+targ->query_name()+"'s body with crushing force, leaving "+targ->query_objective()+" incapacitated.",targ);
            targ->do_damage(targ->return_target_limb(),roll_dice(3,12));
            targ->set_paralyzed(20,"You are stunned");
            targ->add_attacker(TO);
                        //targ->continue_attack();
                        tell_room(TO,"%^BOLD%^%^RED%^An ettercap appears to see what its trap has caught!");
            ob=new("/d/tharis/monsters/ettercap");
            ob->move(TO);
            ob->kill_ob(targ,1);
        }
    }
}

void reset(){
    ::reset();
    if(!trapped("northwest"))
        toggle_trap("northwest");
    if(!trapped("northeast"))
        toggle_trap("northeast");
}
