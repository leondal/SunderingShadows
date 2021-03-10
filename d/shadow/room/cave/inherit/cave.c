//changed to CROOM and added mobs for control - Circe 6/8/04
// added indoors and no sticks - *Styx* 7/21/01
// changed !randoms from 30/10 to 50/20 now that people have quit cycling so
// much and I got through the other rooms to lower the mob repops.
// changed to use a switch and lowered chances again *Styx*  6/15/03
// ditching the caveins and the no sticks property -Ares 3/7/13


#include "../../cave.h"

inherit CROOM;

void pick_critters();

void create(){
    pick_critters();
    ::create();
    set_repop(35);
    set_name("Dragon's Den Caverns");
    set_short("Dragon's Den Caverns");
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^\n"+
      "These wide %^BOLD%^%^BLUE%^caverns %^RESET%^seem to have "+
      "been naturally carved.  Strange "+
      "%^ORANGE%^striations %^RESET%^and variations in color along "+
      "the %^GREEN%^walls %^RESET%^suggest that "+
      "an %^BLUE%^underground river %^RESET%^was the origination of "+
      "these %^BOLD%^tunnels%^RESET%^.  The "+
      "%^CYAN%^air %^RESET%^is damp, heavy, and quite cool here in "+
      "the darkness.  The %^BOLD%^%^BLACK%^floors "+
      "%^RESET%^are worn completely smooth and are covered with a "+
      "light film of "+
      "%^ORANGE%^dirt %^RESET%^and %^GREEN%^debris %^RESET%^made "+
      "sticky from the occasional streams which still "+
      "flow through here during heavy rainfalls."+
      "\n"
    );
    set_property("light", 1);
    set_property("indoors",1);
//    if(!random(2)) set_property("no sticks",1);
    set_terrain(NAT_TUNNEL);
    set_travel(RUBBLE);
    set_items( ([ 
   	(({"rubble", "earth", "exit", "exits"})):"The cave walls have "+
         "crumbled and rocks and "+
         "earth have piled up at the exit.  Perhaps with some effort "+
         "you could dig that direction "+
         "and get the exit open again.", 
      (({"floor","floors"})) : "The smooth stone floors of the tunnel "+
         "have strange swirling striations "+
         "left by dirt and debris as the river passed through here "+
         "over centuries.",
      "ceiling" : "The ceiling overhead hangs low and is rough with "+
         "small outcroppings and forming "+
         "stalagtites.  It looks as though the rounded caverns are "+
         "still growing and forming, they and "+
         "are probably constantly changing.",
      (({"cave","cavern","caverns","tunnel","tunnels"})) : "The "+
         "twisting tunnels of Dragon's Den Caverns "+
         "wind their way deeper into the mountainside.  They widen "+
         "and narrow with each turn, in some places "+
         "only four feet across and in others as wide as fifteen feet.  "+
         "The walls are worn smooth near the "+
         "floor and grow rougher near the curving ceiling.",
      (({"striations","variations","color","stripes"})) : "The shifting "+
         "colors of the wall change from light "+
         "tan through deep brown and alternate with grays and blacks.  "+
         "Faint glimmers of greens and blues "+
         "peek through, hinting at various rocks within the tunnel walls.",
      	]) );
    set_exits(([
    ]));
}

int bomb_exits() { return 1; }

/*
int bomb_exits(){
    if (!userp(TP))
    	return 1;
    if (!ETP->query_property("collapse")) 
    	return 1;
    if (avatarp(TP)) 
    	return 1;
    switch(random(100)) {
	case 0:
           tell_room(ETP,"%^RED%^The room trembles suddenly with a quake of earth, and rubble blocks off all the exits!");
           ETP->collapse_all_exits();
//           write("%^B_GREEN%^%^BOLD%^%^WHITE%^All the exits should collapse.");
           return 0;
	   break;
	case 2..6:
           tell_room(ETP,"%^ORANGE%^Something breaks loose and the room shakes as the exit in front of you caves in!");
           ETP->collapse_exit(query_verb());
           return 0;
	   break;
	default:  return 1;
    }
}
*/

void reset(){
/*
   int active;
   active = has_mobs();
   if(!active){
     if(mons)  mons = ([]);
     pick_critters();
   }
*/
   ::reset();
}

void pick_critters(){
     switch(random(17)){
        case 0..2:  break;
        case 3:  set_monsters( ({MONDIR+"koboldchild"}),({1}));
                 break;
        case 4:  set_monsters( ({MONDIR+"kobold"}),({1}));
                 break;
        case 5:  set_monsters( ({MONDIR+"koboldcaptain"}),({1}));
                 break;
        case 6:  set_monsters( ({MONDIR+"koboldmage"}),({1}));
                 break;
        case 7:  set_monsters( ({MONDIR+"koboldthief"}),({1}));
                 break;
        case 8:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"kobold"}),({1,random(1)+1}));
                 break;
        case 9:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"koboldthief"}),({1,1}));
                 break;
        case 10:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief"}),({1,random(2)+1}));
                 break;
        case 11:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief",MONDIR+"koboldmage"}),({1,1,1}));
                 break;
        case 12:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"kobold"}),({1,random(3)+2}));
                 break;
        case 13:  set_monsters( ({MONDIR+"koboldchild"}),({random(3)+2}));
                 break;
        case 14:  set_monsters( ({MONDIR+"koboldmage",MONDIR+"koboldthief"}),({random(2),random(3)}));
                 break;
        case 15:  set_monsters( ({MONDIR+"koboldmage",MONDIR+"koboldchild"}),({1,random(3)}));
                 break;
        case 16:  set_monsters( ({MONDIR+"koboldmage",MONDIR+"kobold"}),({1,1}));
                 break;
      }
}