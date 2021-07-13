// The Gates of the Marble Academy, Tonovi
// tgate.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(CITY);
    set_name("The Gates of the Marble Academy, Tonovi");
    set_short("The Gates of the Marble Academy, Tonovi");
    set_long("%^RESET%^%^ORANGE%^The path opens here to a long %^RESET%^co%^BOLD%^%^BLACK%^bb%^RESET%^%^ORANGE%^l%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^%^ORANGE%^o%^RESET%^ne courtyard %^ORANGE%^that sits before the %^BOLD%^%^BLACK%^imposing gates %^RESET%^%^ORANGE%^of the %^BOLD%^%^WHITE%^high, m%^RESET%^a%^BOLD%^rb%^RESET%^l%^BOLD%^e t%^RESET%^o%^BOLD%^w%^RESET%^e%^BOLD%^r %^RESET%^%^ORANGE%^that looms over the city. Landscaped to perfection, it is rimmed with %^GREEN%^tall trees %^ORANGE%^and %^BOLD%^%^GREEN%^lush vegetation%^RESET%^%^ORANGE%^, both %^BOLD%^%^WHITE%^potted %^RESET%^%^ORANGE%^and in ground. In the center of the courtyard, a %^RESET%^large fountain %^ORANGE%^rests with its %^BOLD%^%^WHITE%^bu%^RESET%^bb%^BOLD%^%^WHITE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^ng %^CYAN%^w%^RESET%^a%^CYAN%^t%^BOLD%^er %^RESET%^fro%^BOLD%^th%^RESET%^ing %^RESET%^%^ORANGE%^out toward the %^CYAN%^long pools %^ORANGE%^that run down the center of the courtyard in either direction. Two large %^BOLD%^%^WHITE%^statues %^RESET%^%^ORANGE%^rest on either side of the steps leading up to the %^BOLD%^%^BLACK%^wrought iron gates %^RESET%^%^ORANGE%^marking the entry to the %^BOLD%^%^WHITE%^t%^RESET%^o%^BOLD%^w%^RESET%^e%^BOLD%^r%^RESET%^%^ORANGE%^.%^RESET%^\n 
With the tower still under construction, it appears you cannot yet enter the gates. \n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_items( ([
      "gates" : "%^RESET%^A %^CYAN%^strange magical force %^RESET%^seems to %^BOLD%^%^CYAN%^dance %^RESET%^between the %^BOLD%^%^BLACK%^bars %^RESET%^of the %^BOLD%^%^BLACK%^wrought iron gates%^RESET%^, suggesting that they are not as weak as they appear.  You get the feeling that these %^BOLD%^%^BLACK%^gates %^RESET%^could withstand the might of any army.",
      //({"wall", "wall of lightning", "lightning", "lightning wall"}) : "The lightning wall is truly imposing.  Leaping it may be possible, but not suggested.",
      ({"tower","mage tower"}) : "%^BOLD%^%^WHITE%^The white marble tower is truly a sight to behold.  Rising up at least five stories above the %^RESET%^%^CYAN%^City of Tonovi%^BOLD%^%^WHITE%^, it is easy to see why this city is considered a center of %^RESET%^%^CYAN%^learning %^BOLD%^%^WHITE%^and %^CYAN%^magical lore%^WHITE%^.  The white marble walls look impossibly smooth, unmarred by any lines save those of the %^BLACK%^tall, narrow windows%^WHITE%^.%^RESET%^",
      ({"fountain","large fountain"}) : "%^RESET%^%^ORANGE%^The focal point of this %^BOLD%^%^WHITE%^cou%^RESET%^rt%^BOLD%^yard %^RESET%^%^ORANGE%^is this large, %^BOLD%^%^WHITE%^circular fountain%^RESET%^%^ORANGE%^. Carved of %^BOLD%^%^WHITE%^ma%^RESET%^rb%^BOLD%^le%^RESET%^%^ORANGE%^, a %^BOLD%^%^WHITE%^tall human woman %^RESET%^%^ORANGE%^with %^BOLD%^%^WHITE%^long, cu%^RESET%^rl%^BOLD%^ing l%^RESET%^o%^BOLD%^cks %^RESET%^%^ORANGE%^tumbling freely over her shoulders %^BOLD%^%^WHITE%^rises %^RESET%^%^ORANGE%^from the %^CYAN%^w%^BOLD%^a%^RESET%^%^CYAN%^t%^RESET%^e%^CYAN%^r%^BOLD%^s %^RESET%^%^ORANGE%^of the %^CYAN%^central pool%^ORANGE%^. Garbed in the %^RED%^finest %^ORANGE%^of %^BOLD%^%^WHITE%^flowing si%^RESET%^lk%^BOLD%^s%^RESET%^%^ORANGE%^, she holds an %^BOLD%^%^BLUE%^open book %^RESET%^%^ORANGE%^close to her chest while %^BOLD%^%^CYAN%^fountains %^RESET%^%^ORANGE%^lining the %^RESET%^rim %^BOLD%^spray %^CYAN%^wa%^RESET%^%^CYAN%^t%^BOLD%^er %^RESET%^%^ORANGE%^upward in %^BOLD%^%^CYAN%^exhiliration %^RESET%^%^ORANGE%^around her. The overflow of the %^CYAN%^circular pool %^ORANGE%^is left free to flow outward into the %^CYAN%^long pools %^ORANGE%^running down the center of the %^RESET%^cour%^BOLD%^ty%^RESET%^ard %^ORANGE%^in either direction.%^RESET%^",
      ({"trees","plants","vegetation","pots"}) : "%^RESET%^%^GREEN%^Tall trees line the perimeter of the %^RESET%^courtyard%^GREEN%^, with %^BOLD%^lush vegetation %^RESET%^%^ORANGE%^dotting the %^ORANGE%^grounds %^GREEN%^between. %^BOLD%^Foliage %^RESET%^%^GREEN%^of all sorts, from %^BOLD%^ferns %^RESET%^%^GREEN%^to %^BOLD%^%^CYAN%^f%^RED%^l%^RESET%^%^RED%^o%^MAGENTA%^w%^BOLD%^%^BLUE%^e%^ORANGE%^r%^CYAN%^s %^RESET%^%^GREEN%^are meticulously spaced in an array of both %^ORANGE%^in-ground %^BOLD%^%^GREEN%^plants %^RESET%^%^GREEN%^and others planted in %^BOLD%^%^WHITE%^ma%^RESET%^rb%^BOLD%^le p%^RESET%^o%^BOLD%^ts %^RESET%^%^GREEN%^for added layers of height.%^RESET%^",
      ({"pools","central pools","long pools"}) : "%^RESET%^%^CYAN%^Each of these %^BOLD%^long pools %^RESET%^%^CYAN%^spread down the length of the %^RESET%^cour%^BOLD%^ty%^RESET%^ard %^CYAN%^from either side of the large %^BOLD%^fountain %^RESET%^%^CYAN%^in its center. About two feet in width apiece, both are dotted with %^BOLD%^%^WHITE%^fl%^RESET%^o%^YELLOW%^wer%^RESET%^i%^BOLD%^ng %^RESET%^%^GREEN%^l%^BOLD%^i%^RESET%^%^GREEN%^ly pads %^CYAN%^and have %^YELLOW%^gl%^RESET%^%^WHITE%^i%^CYAN%^mm%^WHITE%^e%^YELLOW%^rs of %^BOLD%^%^WHITE%^k%^BLACK%^o%^RED%^i %^RESET%^%^CYAN%^swimming within.%^RESET%^",
      ({"statues","steps"}) : "%^BOLD%^%^WHITE%^Sculpted from marble, two large statues of well garbed male humans stand at the edge of the steps leading to the %^BOLD%^%^BLACK%^iron gates%^WHITE%^. While holding %^BLUE%^open books %^WHITE%^in their hands, they seem to peer down their noses at you with judgemental eyes.%^RESET%^",
      ({"window","windows"}) : (:TO,"look_windows":),
    ]) );
    set_exits( ([
      "east" : "/d/dagger/tonovi/antipath1",
     // "gates" : "tfoyer",
    ]) );
    set_listen("default", "%^BOLD%^%^BLACK%^You hear %^RESET%^%^RED%^large bangs %^BOLD%^%^BLACK%^and %^BLUE%^explosions %^BLACK%^coming from within the %^WHITE%^t%^RESET%^o%^BOLD%^w%^RESET%^e%^BOLD%^r%^BLACK%^.%^RESET%^");
    set_smell("default", "%^RESET%^%^ORANGE%^Mingled in with the %^MAGENTA%^scents %^ORANGE%^of %^BOLD%^%^GREEN%^fresh foliage%^RESET%^%^ORANGE%^, you can smell the %^YELLOW%^acrid smell %^RESET%^%^ORANGE%^of %^YELLOW%^lightning%^RESET%^%^ORANGE%^.%^RESET%^");
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
