//forest108.c

#include <std.h>

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
                "ground":"You notice a small silk thread across the paths to the northeast and northwest.",
                "thread":"This thread leads off the path and up a tree, you know that this is a trap."
                ]));
    set_exits(([
                "south":"/d/tharis/forest/forest107",
                "northeast":"/d/tharis/forest/forest116",
                "northwest":"/d/tharis/forest/forest141",
                ]));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
    find_object_or_load("/d/tharis/forest/forest71");
    set_trap_functions(({"northwest","northeast"}),({"kill_em","kill_em2"}),({"northwest","northeast"}));
}

int kill_em(){
    write("%^BOLD%^As you walk northwest you feel your foot catch on something.");
    tell_room(TO,"%^BOLD%^As "+TPQCN+" walks northwest "+TP->query_possessive()+" foot catches on something.",TP);
    toggle_trap("northwest");
    call_out("falling",1,TP);
    return 1;
}

int kill_em2(){
    write("%^BOLD%^As you walk northeast you feel your foot catch on something.");
    tell_room(TO,"%^BOLD%^As "+TPQCN+" walks northeast "+TP->query_possessive()+" foot catches on something.",TP);
    toggle_trap("northeast");
    call_out("falling",1,TP);
    return 1;
}

void falling(object targ){
    object ob;
    if(objectp(targ)){
        if(present(targ->query_name())){
            tell_room(TO,"%^BOLD%^%^YELLOW%^Out of nowhere a huge log comes flying down upon you.");
            write("%^BOLD%^%^YELLOW%^The log seems to be directed at you!");
            tell_room(TO,"%^BOLD%^%^YELLOW%^The log seems directed at "+targ->query_name(),targ);
            write("%^BOLD%^%^YELLOW%^The log smashes into your body with crushing force, leaving you incapacitated.");
            tell_room(TO,"%^BOLD%^%^YELLOW%^The log smashes into "+targ->query_name()+"'s body with crushing force, leaving "+targ->query_objective()+" incapacitated.",targ);
            targ->do_damage(targ->return_target_limb(),roll_dice(3,10));
            targ->set_paralyzed(20,"You are stunned");
            targ->add_attacker(TO);
            targ->continue_attack();
            tell_room(TO,"%^BOLD%^%^RED%^Two ettercaps appear to see what their trap has caught!");
            ob=new("/d/tharis/monsters/ettercap");
            ob->move(TO);
            ob->kill_ob(targ,1);
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
