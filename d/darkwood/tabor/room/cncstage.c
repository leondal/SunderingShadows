//updated by Circe 5/30/04 with colors, etc.
//Added exit to backstage - Cythera 5/05
// Theatre of the Crown and Castle, Tabor
// Thorn@ShadowGate
// 001013
// Tabor
// cncstage.c

#include <std.h>
#include "../include/tabor.h"

inherit CROOM;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Theater of the Crown and Castle, Tabor");
  set_long(
"%^BOLD%^Theater of the Crown and Castle, Tabor%^RESET%^\n"+
"%^CYAN%^While food is considered the heart of most inns, it "+
"is clear that at the %^YELLOW%^Crown and Castle Inn%^RESET%^"+
"%^CYAN%^, the entertainment makes the world go round.  The "+
"%^ORANGE%^stage %^CYAN%^is the centerpiece of this room, a "+
"huge half-circle jutting out into a %^BOLD%^sea %^RESET%^%^CYAN%^"+
"of %^MAGENTA%^velvet-padded chairs%^CYAN%^.  A matching %^MAGENTA%^"+
"velvet curtain %^CYAN%^has been pulled back on both sides, "+
"revealing the large, %^ORANGE%^oaken stage%^CYAN%^.  This room "+
"is dedicated entirely to %^WHITE%^performance%^CYAN%^, so much so "+
"that food and drinks are served only in the other rooms and there "+
"are no tables here.  The %^ORANGE%^hardwood floors %^CYAN%^are "+
"left bare, but the %^RED%^brick walls %^CYAN%^have been lined with "+
"thick %^BOLD%^%^BLACK%^tapestries %^RESET%^%^CYAN%^to help the "+
"acoustics.  Tiny strands of %^BOLD%^%^WHITE%^enchanted %^YELLOW%^"+
"lights %^RESET%^%^CYAN%^have been run across the top of the stage, "+
"providing a little light.  The lighting of the room is mainly "+
"controlled by large %^YELLOW%^spotlights %^RESET%^%^CYAN%^of "+
"%^BOLD%^gnomish construction %^RESET%^%^CYAN%^that rise up near "+
"the back of the room.\n\n"+
"%^CYAN%^Here you can take in a show by a visiting bard or "+
"from Amergin himself, on occasion.  Amergin is known to hold "+
"that, %^BOLD%^'%^RESET%^The finest bard need only have the ground "+
"beneath him and the boundless air of the sky above him in order "+
"to bring his audience to laughter or tears.  Where there is only "+
"plain wood, a bard can bring a forest to life at will.%^BOLD%^"+
"%^CYAN%^'\n\n"+
"%^RESET%^From here you can go into the hall of the inn to the west."
  );
  set_smell("default","You smell the scents of the cafe to the west.");
  set_listen("default","You hear the muted babble of the socializing guests.");
  set_items(([
     "stage" : "%^ORANGE%^The large oaken stage dominates the room, "+
        "forming a massive semi-circle that is highly polished and "+
        "shines in the light.  The velvet curtain lining the stage "+
        "may be pulled closed, hiding performers from view, but now "+
        "it stands open.  There are stairs to the right and left of "+
        "the stage you may climb. On the right and left side of the"+
        " stage, a peek of the backstage area can be seen, where "+
        "performers wait for their cues.",
     ({"curtain","curtains"}) : "%^MAGENTA%^The plush curtains are "+
        "made of maroon velvet, and they look incredibly soft.  "+
        "They may be pulled open or closed by thick %^YELLOW%^"+
        "gold braid rope %^RESET%^%^MAGENTA%^pulls hanging on "+
        "each side.",
     ({"chair","chairs"}) : "Rows of chairs face the stage, each "+
        "of them made of deep mahogany.  They are all carved in "+
        "a simple, elegant manner and fitted with %^MAGENTA%^"+
        "velvet cushions%^RESET%^ that match the curtain.",
     ({"lights","enchanted lights"}) : "%^BOLD%^The top edge of "+
        "the stage is lined with tiny enchanted lights that "+
        "twinkle brightly.  They allow performers to see the "+
        "edge of the stage, even when it is dark in the theater.",
     ({"spotlight","spotlights"}) : "In the back of the room "+
        "are two enormous spotlights of ingenious gnomish "+
        "construction.  They utilize mirrors and large stones "+
        "enchanted with permanent light spells that seem much "+
        "brighter than usual.  They are encased in huge cylinders "+
        "of iron that may be turned any way they need to be and "+
        "they have flaps in the front that can be lowered, dimming "+
        "or completely obscuring the light.",
      "floor" : "The floor is a simple hardwood floor, highly "+
        "polished with no scuffmarks.",
      ({"wall","walls","tapestries"}) : "The brick walls are "+
        "covered with simple black tapestries.  Each tapestry "+
        "shows a different scene of entertainers - most of which "+
        "are shown performing right on this stage."
  ]));
  set_exits( ([
    "west" : ROOMDIR+"cnchall"
  ]) );
}

void init(){
   ::init();
   add_action("sit","sit");
   add_action("climb","climb");
	add_action("exit","exit");
}

int sit(string str){
   if(!str){
      tell_object(TP,"Try sitting on the chair?");
      return 1;
   }
   if(str == "chair" || str == "on chair" || str == "on the chair"){
      tell_object(TP,"You take a seat in a velvet lined chair "+
         "facing the stage.  Nice and comfortable.");
      tell_room(ETP,""+TPQCN+" sits in one of the velvet-lined chairs.",TP);
      TP->force_me("pose sitting in a velvet-lined chair");
      return 1;
   }
   return 0;
}

int climb(string str){
   if(!str) return 0;
   if(str != "stairs" && str != "stage" && str != "the stairs"){
      tell_object(TP,"Try climbing the stairs to get on the stage.");
      return 1;
   }
   tell_object(TP,"You climb the stage with slight butterflies in "+
      "your stomach.");
   tell_room(ETP,""+TPQCN+" climbs the stairs leading to the stage.",TP);
   TP->force_me("pose standing on stage");
   return 1;
}      
int exit(string str){
   if(!str){
      tell_object(TP,"Do you want to exit stageright or stageleft");
      return 1;
   }
   if(str == "stageright" || str == "stageleft"){
      tell_object(TP,"You exit the stage, heading backstage.");
      tell_room(ETP,""+TPQCN+" steps off the stage.",TP);
      TP->move(ROOMDIR"cnc_backstage");
	TP->force_me("look");
      return 1;
   }
   return 0;
}
