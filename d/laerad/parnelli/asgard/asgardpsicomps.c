//coded by ~Circe~ 10/19/07
//altered for the destruction of Asgard ~Circe~ 3/29/13
#include <std.h>
#include <daemons.h>

inherit VAULT;
int dmg;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
//   set_property("no teleport",1);
   set_indoors(1);
   set_name("The Sublime Cut");
   set_short("The Sublime Cut");
   set_long(
         "%^BOLD%^The Sublime Cut, Asgard%^RESET%^\n"+
         "%^RESET%^%^ORANGE%^This simple shop features walls of planks "+
         "hewn smooth and lightly %^YELLOW%^varnished%^RESET%^"+
         "%^ORANGE%^.  A plain %^YELLOW%^worktable %^RESET%^"+
         "%^ORANGE%^topped by hammers, chisels, files, and other "+
         "instruments fills the southern wall, matched by a "+
         "smooth %^RESET%^bleached wooden counter %^ORANGE%^along the "+
         "northern wall.  %^BOLD%^%^BLACK%^Iron chests %^RESET%^"+
         "%^ORANGE%^and %^CYAN%^glass display cases %^ORANGE%^"+
         "are spread about the room, offering up a pretty display "+
         "of %^BOLD%^%^CYAN%^cut crystals %^RESET%^%^ORANGE%^divided "+
         "by color and type.  The eastern wall is fitted with "+
         "%^BOLD%^%^CYAN%^windows %^RESET%^%^ORANGE%^set with "+
         "plain glass of a somewhat low quality, still showing "+
         "a slight distortion and a few bubbles.  The only object "+
         "of any ornamentation in the room is the door on "+
         "the western wall.  It is set within an arched doorway "+
         "and inlaid with colored wooden panels that create the "+
         "image of a %^CYAN%^proud p%^BOLD%^e%^GREEN%^a%^BLUE%^c"+
         "%^RED%^o%^MAGENTA%^c%^YELLOW%^k%^RESET%^%^ORANGE%^.  "+
         "A plain wooden staircase leads up to a back-room beyond.\n\n"+
         "%^RESET%^<help shop> will give you help on how to use the shop.\n"
   );
   set_smell("default","The light fragrance of a woodsy incense reaches you.");
   set_listen("default","The ring of hammer and chisel mingle with fragments of conversation.");
   set_items( ([
      ({"table","work table","worktable"}) : "The simple worktable is "+
         "raised slightly to allow easy access from the matching stool "+
         "standing nearby.  Its surface is covered with an assortment "+
         "of tools needed for cutting gems.",
      ({"hammers","chisels","files","instruments","tools"}) : "The surface "+
         "of the worktable is covered with scattered tools.  Small "+
         "hammers with handles of oak and ash lie among tiny chisels "+
         "used for carving the crystals into their delicate final shapes.  "+
         "The blackened iron files in different gradients are used to "+
         "smooth the edges once the major cuts have been made.",
      ({"counter","wooden counter","cases","chests"}) : "A bleached wooden counter "+
         "runs along the northern wall, nearly filling one-half of the shop.  "+
         "Its surface is covered with various-sized chests and display "+
         "cases filled with glittering crystals cut and ready to be "+
         "used by psions.",
      ({"window","windows"}) : "The thick glass windows are large and "+
         "allow a view of the city outside.  They are somewhat uneven "+
         "and give a distorted view but allow in ample light during the "+
         "day."
   ]) );
   set_exits(([
      "east" : "/d/laerad/parnelli/asgard/as65",
      "west" : "/d/laerad/parnelli/asgard/asgardworkroom",
      "up" : "/d/laerad/parnelli/asgard/portal"
   ]));
   set_door("door","/d/laerad/parnelli/asgard/asgardworkroom","west",0);
   set_door_description("door","%^ORANGE%^Crafted from "+
      "light blond oak, this door is inlaid with countless "+
      "colored wood pieces forming the image of a majestic "+
      "%^CYAN%^p%^BOLD%^e%^GREEN%^a%^BLUE%^c"+
      "%^RED%^o%^MAGENTA%^c%^YELLOW%^k%^RESET%^%^ORANGE%^ with "+
      "his tailfeathers spread.%^RESET%^");
   set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));
}

void reset(){
   ::reset();
   if(!present("natalia")) {
      find_object_or_load("/d/laerad/mon/natalia")->move(TO);
   }
}

int GoThroughDoor(){
   if(!TP->is_class("psion") && !TP->is_class("psywarrior")){
      dmg = (((int)TP->query_max_hp())/5);
      if(SAVING_D->saving_throw(TP,"spell",0)){ dmg = dmg/2; }
      if(((int)TP->query_hp()-2) < dmg){
         tell_object(TP,"In your current condition, you feel the "+
            "barrier might do permanent damage.  You might want to "+
            "heal up first.");
         return 0;
      }
      tell_object(TP,"%^BOLD%^%^CYAN%^As you move to go through the door, "+
         "you feel something in your mind %^RED%^snap%^CYAN%^, leaving "+
         "you with a terrible headache.%^RESET%^");
      TP->do_damage("head",dmg);
      return ::GoThroughDoor();
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You feel a slight tingling "+
      "as you attune your mind to pass through the barrier on "+
      "the door.%^RESET%^");
   return ::GoThroughDoor();
}
