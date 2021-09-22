#include <std.h>
#include "../jarmila.h"

inherit STORAGE"hill.c";

void turning(object tp, int num);

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"35",
   ]));
}

void reset(){
   ::reset();
   if(!present("avatar")){
      new(MOBS"paladin.c")->move(TO);
   }
}

void pick_critters(){
               return;
}

int func_bork(){

tell_room(TO,"%^C216%^The mist fills the area, and you feel "+
"magic flee the area%^CRST%^.");
set_property("no magic",1);
return;
}

int func_unbork(){
tell_room(TO,"%^C216%^The mist clears the area, and you feel "+
"magic return the area%^CRST%^.");
remove_propery("no magic");
return;
}

void turning(object tp,int num){
            switch(num){
    case(0):   tell_room(TO,"%^C094%^As the %^C252%^paladin%^C094%^ slumps to the "+
"ground she %^C194%^smiles%^C094%^. Her %^C252%^sword%^C094%^ "+
"clatters to the rocks and disolves into "+
"%^C229%^light%^C094%^.%^CRST%^\n");
                        break;
    case(1):   tell_room(TO,"%^C094%^Quickly %^C196%^blood %^C094%^pools from her body...%^CRST%^\n");
                        break;
    case(2):   tell_room(TO,"%^C094%^She places her fingers on her lips and as "+
"she %^C252%^forgives%^C094%^ you her entire form is "+
"%^C196%^engulphed%^C094%^ in %^C231%^holy fire%^C094%^.%^CRST%^\n");
                        break;
    case(3):   tell_room(TO,"%^C094%^You feel a %^C172%^rumble%^C094%^ from all "+
"around you.%^CRST%^\n");
                        break;
    case(4):   tell_room(TO,"%^C094%^The %^C196%^fire%^C094%^ grows exponentially until "+
"it is a %^C196%^cyclone%^C094%^ a %^C221%^hundred "+
"feet%^C094%^ tall.%^CRST%^\n");
                        break;
    case(5):   tell_room(TO,"%^C094%^The %^C160%^heat%^C094%^ is %^C242%^unbearable"+
"%^C094%^!%^CRST%^\n");
                        break;
    case(6):   tell_room(TO,"%^C094%^With a %^C196%^scream of %^C226%^righteous "+
"fury%^C094%^, a massive %^C196%^phoenix%^C094%^ "+
"emerges from the %^C196%^fire%^C094%^ and dives "+
"at you!%^CRST%^\n");
				           new(MOBS"jarmila")->move(TO);
                        break;


                        return;
                }
    num++;
    call_out("turning",4,tp,num);
    return;
}
