#include <std.h>
#include "../lizard.h"
inherit ROOM;

void turning(object tp, int num);

void create(){
    ::create();
  	set_terrain(BUILT_TUNNEL);
  	set_travel(PAVED_ROAD);
    set("short","Dark, dank dripping room.");
    set("long","You have entered a room that is dark, dank, and wet.  "+
        "Water glistens at various points on the walls, while mold and fungus "+
        "sprout everywhere.  A small stream of fetid and foul smelling liquid "+
        "disappears quickly into a hole in the wall to the south.  On the south wall above "+
        "the hole a metal wheel with spokes can be seen afixed to the wall.  There is a metal "+
        "plaque on the wall above the spoked wheel");
    set_property("light",1);
    set_property("indoors",1);
    set_smell("default","The odor in here is intense and thick.  The smell of a dank sewer presses in on you.");
    set_listen("default","Very little can be heard over the rush of water through the hole in the floor.");
    set_items(([
        ({"sign","plaque"}):"The lettering on the sign has faded away over time, surely it was there for a reason.",
        "wheel":"The wheel is on a rod that disappears into the wall.  Above the wheel is a sign.",
        "stream":"The fluid flows rapidly and splashes the walls, are you sure you want to get your face any closer?",
        "hole":"The hole is small enough to wedge a small size goblin in tight.  Even if you could overcome the smell and the chance of swallowing the loathesome liquid, your size will prevent you from squeezing into the hole successfully.",
        ({"wall","walls"}):"Slimy and slick, they fester with disease."
        ]));
    set_exits(([
        "north":LROOMS+"sw8",
        ]));
}
void init(){
    ::init();
    add_action("turn","turn");
}
int turn(string str) {
    if(str == "wheel" || str=="spoked wheel"){
        TP->set_paralyzed(5000,"You are unable to do that!");
        turning(TP,0);
        return 1;}
        else  {tell_object(TP,"Turn what?");
                return 1;}
}
void turning(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"You force the wheel to move and then it suddenly breaks loose and spins "+
                                "wildly as though something else is forcing it!  \n");
                        break;
                case(1):tell_object(TP,"You feel a deep rumbling and suddenly the floor beneath you opens up.  As quickly "+
                                "as it started, you and the filthy water are washed out through the hole!  \n");
                        break;
                case(2):tell_room(ETP,""+TPQCN+" turns the wheel and then is hidden from view as a door slams "+
                                "down between "+TPQCN+" and you.  Gurgling sounds can be heard from the "+
                                "other side of the wall, then silence and the wall slides upward. \n "+TPQCN+" is "+
                                "nowhere to be seen!!! \n",TP);
                        break;
                case(3):tell_object(TP,"          %^BOLD%^%^YELLOW%^AHHHHHHHHHHHHHHHH!!!%^RESET%^");
                        break;
                case(4):tell_object(TP,"%^BOLD%^%^YELLOW%^AHHHHHHHHHHHHH!!!%^RESET%^");
                        break;
                case(5):tell_object(TP,"      %^BOLD%^%^BLUE%^GURGLE \n");
                        tell_object(TP,"           %^BOLD%^%^BLUE%^GURGLE%^RESET%^");
                        break;
                case(6):tell_object(TP,"          %^BOLD%^%^YELLOW%^AHHHHHHHHHHHHHHHH!!!%^RESET%^ ");
                        break;
                case(7):tell_object(TP,"    %^BOLD%^%^YELLOW%^AHHHHHHHHHHHHHHHH!!!%^RESET%^ ");
                        break;
                case(8):tell_object(TP,"   %^RESET%^%^ORANGE%^COUGH \n");
                        tell_object(TP,"       %^RESET%^%^ORANGE%^COUGH%^RESET%^");
                        break;
                case(9):tell_object(TP,"          %^BOLD%^%^YELLOW%^AHHHHHHHHHHHHHHHH!!!%^RESET%^");
                        break;
                case(10):tell_object(TP,"  %^BOLD%^%^YELLOW%^AHHHHHHHHHH!!! \n");
                        break;
                case(11):tell_object(TP,"%^BOLD%^%^RED%^SPLUT%^RESET%^!!!! \n");
                        break;
                case(12):tell_object(TP, "You cough and choke as you come to a sudden stop in the soft, slimy mud banks "+
                            "of an underground lake.  \n");
                        break;
                case(13):tell_object(TP, "The soft mud saved you broken bones, but was it really worth it?  \n");
                        TP->move(LROOMS+ "l2");
                        tell_object(TP,"How will you get out of here, the entrance to this cavern is lost up in the darkness "+
                                        "far overhead?  \n");
                        TP->set_paralyzed(0);
                        return;
                }
    num++;
    call_out("turning",0,tp,num);
    return;
}
