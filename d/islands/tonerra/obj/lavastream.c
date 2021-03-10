//lavasteam.c
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit OBJECT;
object room;

void create(){
    ::create();
    set_name("Magma stream");
    set_short("%^RESET%^%^RED%^Magma Stream%^RESET%^");
    set_id(({"lava stream","stream","lava","magma","magma stream"}));
    set_long("%^BOLD%^%^RED%^This brilliant red-orange flow of rock radiates with extreme heat.  "
        "You can see the heat coming from the stream in waves. Sometimes you "
        "wonder what it would feel like if you were to <jump into> that flaming and "
        "broken flow of lava.\n%^RESET%^");
    set_weight(100000);
    set_property("no animate",1);
    set_heart_beat(1);
    heart_beat();
}

void init(){
    object ob;
    int i;
    ::init();
    add_action("jump","jump");

    if(!TP->is_player()) { return; }

    if(!objectp(room)){
        room = find_object_or_load(OBJ+"froom");
        room->add_exit(base_name(ETO),"out");
    }

    while(ob = present("salamander",room)){
       ob->move_player(ETO);
       ob = 0;
       tell_room(ETO,"%^RED%^A salamander rises from the depths of the flames.%^RESET%^");
    }

/*
    for(i=0;i<roll_dice(1,4);i++){
       ob = new(MON+"salamander");
       ob->move(ETO);
       tell_room(ETO,"%^RED%^A salamander rises from the depths of the flames.%^RESET%^");
    }
*/
}

int jump(string str){
    // added "into lava" & changed return 0 to meaningful notify_fail message *Styx*  11/22/03
    if(!str || (str != "into magma" && str != "into stream" && str != "into lava")){
        return notify_fail("Are you really wanting to try to jump into lava - or are you just trying to look silly, or maybe both?");
    }

    tell_room(ETO,TPQCN+" bravely jumps into the flaming inferno that holds the magma stream.",TP);
    tell_object(TP,"You bravely (or stupidly) jump into the inferno containing the magma.");

    if(!objectp(room)){
        room = find_object_or_load(OBJ+"froom");
        room->add_exit(base_name(ETO),"out");
    }

    TP->move_player(room);
    return 1;
}

object query_room(){
    if(!objectp(room)){
        room = find_object_or_load(OBJ+"froom");
        room->add_exit(base_name(ETO),"out");
    }
    return room;
}

void heart_beat(){
    object *inven;
    int i;

    if(!objectp(TO) || !objectp(ETO)) return;

    inven = all_living(ETO);

    for(i=0;i<sizeof(inven);i++){
        if(!objectp(inven[i])) { continue; }
        // added exclude true invis immortals *Styx*  11/22/03, last change was 7/20/98
        if(inven[i]->query_true_invis()) { continue; }
        if(inven[i]->query_property("fire resistant")) { continue; }

        tell_object(inven[i],"%^RED%^You are scorched by the heat.");

        inven[i]->do_damage("torso",roll_dice(2,4));
        inven[i]->add_attacker(TO);
        inven[i]->continue_attack();
        // adding another objectp check due to consistent bugs *Styx*  11/22/03, last change 7/20/98
        if(objectp(inven[i])) { inven[i]->remove_attacker(TO); }
    }
}
