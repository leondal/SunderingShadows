#include <std.h>
#include "../tharis.h"

#define MESSAGE ({"%^BLACK%^%^BOLD%^Your foot slips as you enter, and you begin sliding downward!%^RESET%^",\
  "%^BLACK%^%^BOLD%^You hear water falling all around you.%^RESET%^",\
  "%^BLACK%^%^BOLD%^You feel you sodden body fall further.%^RESET%^",\
  "%^RESET%^%^ORANGE%^You hit a small ledge and bounce off!%^RESET%^",\
  "%^BOLD%^%^BLUE%^You breathe in water and start to sputter.%^RESET%^",\
  "%^RESET%^%^BOLD%^COUGH! COUGH! COUGH!%^RESET%^",\
  "%^RESET%^%^BOLD%^You gasp for air!%^RESET%^",\
  "%^BOLD%^%^BLUE%^The dirty water tears at your eyes!%^RESET%^",\
  "%^BOLD%^%^BLUE%^You hear distantly below you the waters crashing into something!%^RESET%^",\
  "%^RED%^%^BOLD%^Your lungs burn! Your heart hurts!%^RESET%^",\
  "%^BLACK%^%^BOLD%^You crash again into the wall!%^RESET%^",\
  "%^BLACK%^%^BOLD%^Pain rushes through your whole body!%^RESET%^",\
  "%^BOLD%^%^BLUE%^Below you, you hear the water rushing up at you very quickly...%^RESET%^"\
})

inherit STORAGE"sewer";

void create(){
    ::create();
    set_property("light",-10);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_property("no attack",1);
    set_property("no teleport",1);
    set_name("The downward slide");
    set_short("The downward slide");
    set_long("You are falling!");
/*    set_exits(([
        "southeast" : SEWERS"fakesewer",
    ]));
    set_pre_exit_functions(({"southeast"}),({"GoThroughDoor"})); */
    set_items(([]));
}

void init(){
        write(""+MESSAGE[0]);
        call_out("limbo",1,TP, 1);
}

void limbo(object ob, int flag){
        if(!objectp(ob)) return;
        if(TO != environment(ob)) return;
        if(flag < sizeof(MESSAGE)){
                tell_object(ob,""+MESSAGE[flag]+"\n\n");
                flag++;
                call_out("limbo",2,ob,flag);
        }
        else ob->move_player(SEWERS"slide2");
}

int GoThroughDoor(){
        write("You cant scramble up to that!");
        return 0;
}
