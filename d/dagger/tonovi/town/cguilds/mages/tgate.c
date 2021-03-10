//updated by Circe with color, expanded desc, etc. 5/30/04
// removing redundant restriction *Styx* 12/28/05
// The Gates of the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// tgate.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(CITY);
    set_name("The Gates of the Tower of the Arcane, Tabor");
    set_short("The Gates of the Tower of the Arcane, Tabor");
    set_long(
@TABOR
%^BOLD%^The Gates of the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^
Just before you is the short pathway leading up the smooth 
walls of a %^ORANGE%^rocky outcropping%^RESET%^.  There appears to be no other 
way to reach the %^YELLOW%^imposing tower %^RESET%^standing upon the stone.  The
walls of the tower are made of what looks to be %^BOLD%^sleek white
marble%^RESET%^, and you can see several %^CYAN%^windows %^RESET%^from which strange 
%^YELLOW%^lights %^RESET%^sometime emanate.  Before the tower looms a 
large double-gate made of classic %^BOLD%^%^BLACK%^wrought iron %^RESET%^set into 
huge %^BOLD%^%^BLACK%^gra%^WHITE%^n%^BLACK%^it%^WHITE%^e %^RESET%^pillars.  Behind you is an intimidating wall of 
%^YELLOW%^lightning %^RESET%^that crackles and hisses, obscuring the view of the 
road on the other side.
TABOR
    );
    set_property("light", 2);
    set_property("indoors", 1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_items( ([
      "gates" : "A strange magical force seems to dance between the "+
         "bars of the wrought iron gates, suggesting that they are "+
         "not as weak as they appear.  You get the feeling that these "+
         "gates could withstand the might of any army.",
      ({"wall", "wall of lightning", "lightning", "lightning wall"}) : "The "+
        "lightning wall is truly imposing.  Leaping it may be possible, but "+
        "not suggested.",
      ({"tower","mage tower"}) : "The white marble tower is truly "+
        "a sight to behold.  Rising up at least five stories about the "+
        "town of Tabor, it is easy to see why this city is considered "+
        "a center of learning and magical lore.  The white marble walls "+
        "look impossibly smooth, unmarred by any lines save those of the "+
        "tall, narrow windows.",
      ({"window","windows"}) : (:TO,"look_windows":),
    ]) );
    set_exits( ([
      "south" : ROOMDIR+"way3",
      "gates" : ROOMDIR+"tfoyer",
    ]) );
    set_listen("default", "You hear large bangs and explosions coming from within the tower.");
    set_smell("default", "You can smell the acrid smell of lightning.");
//    set_pre_exit_functions( ({"gates", "south"}), ({"GoThroughDoor", "go_south"}) );
}

/* way3.c has a check already fixed up...
* void init(){
*    ::init();
*    add_action("leaping","jump");
*    add_action("leaping","leap");
*    add_action("sneak","sneak");
*}
*/

int look_windows(){
   switch(random(4)){
      case 0:  tell_object(TP,"The tall, narrow windows of the tower "+
               "are set within the smooth marble walls.  All seems quiet "+
               "there now.");
               break;
      case 1:  tell_object(TP,"%^CYAN%^As you look up at the windows, "+
               "you suddenly see a vibrant %^BOLD%^blue glow %^RESET%^"+
               "%^CYAN%^emanate from one of them.  It lingers for a "+
               "moment, then is gone.");
               break;
      case 2:  tell_object(TP,"%^YELLOW%^Looking up at the windows, "+
               "you suddenly see a flash of %^WHITE%^lightning,"+
               "%^YELLOW%^followed by the sound of cheering as an "+
               "apprentice mage finds success.");
               break;
      case 3:  tell_object(TP,"%^ORANGE%^Several magi wander by "+
               "one of the low level windows, eagerly engaged "+
               "in conversation though you cannot hear anything "+
               "from here.");
               break;
   }
   if(!TP->query_invis()){
   tell_room(TO,""+TPQCN+" looks over the windows.",TP);
   }
   return 1;
}

/********** none of this is used now.....
int GoThroughDoor(){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return 1;
   tell_object(TP,"A strange force makes you feel unwanted here.");
   return 1;
}

int sneak(string str){
    if(TP->query_thief_skill("move silently")){
      tell_object(TP, "That isn't going to get you far here.");
      return 1;
    }
   return 0;
}

int go_south(){
    if(!TP->is_class("mage") && !TP->is_class("bard") && !avatarp(TP))
    {
        tell_object(TP,"%^ORANGE%^You try to walk through the lightning, but feel "+
"a slight shock.  You know you are not wanted here.");
        tell_room(TO,"%^ORANGE%^"+TPQCN+" walks up the the barrier "+
    "and shivers as "+TP->QP+" "+
             "body receives a small jolt of electricty.",TP);
    return 1;
    }
     tell_object(TP, "%^CYAN%^You attune your aura to allow the energy to flow "
        "around you and confidently walk through the wall of lightning."
    );
   if(TP->query_invis()) return 1;
    tell_room(ETP,"%^CYAN%^"+TPQCN+" walks carelessly over to the lightning wall, and "
        "simply walks through it, the energy seeming to have no effect.", 
    TP);
    return 1;
}

int leaping()
{
    if((int)TP->query_hp() < 30) {
        tell_object(TP, "You wouldn't survive.");
        return 1;
    }
    tell_object(TP, "%^YELLOW%^As you leap through the lightning barrier, you can "
        "feel your skin sizzle and your muscles convulse in exquisite pain."
    );
    TP->move_player("/d/darkwood/tabor/room/way3.c");
    tell_room(TO,"%^YELLOW%^"+TPQCN+" leaps through the energy, screaming in "
        "pain as the bolts burns "+TP->query_possessive()+" flesh!", TP);
    tell_room(ETP,"%^YELLOW%^"+TPQCN+" jumps through the wall of lightning to collapse "
        "on the ground, shivering in pain.", TP);
    TP->set_hp(1+random(20));
    TP->do_damage("torso", 1);
    return 1;
    
}
*************/
