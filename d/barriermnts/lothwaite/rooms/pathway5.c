//pathway5.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include <daemons.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   set_long(::query_long()+"A pile of huge boulders has come to rest here, "+
      "blocking passage any further south.");
   set("night long",(:TO,"ndesc":));
   add_item(({"boulders","pile"}),"The pile of boulders forms a semi-circle to the "+
      "south, reaching around to the western and eastern sides of the trail "+
      "as well.  It effectively blocks passage any further, and you cannot "+
      "tell what may have left it - perhaps a landslide? You think you can <climb boulders> here.");
   set_search("default","The pile of boulders seems interesting...maybe "+
      "you should take a closer look?");
   set_search("boulders","Searching the boulders, you realize that rather than "+
      "a haphazard pile, they seem to be a very large stairway.  If you tried, "+
      "you might be able to climb the stairs.");
   set_search("pile","Searching the boulders, you realize that rather than "+
      "a haphazard pile, they seem to be a very large stairway.  If you tried, "+
      "you might be able to climb the stairs.");
   set_exits(([
      "north" : PATHEXIT"pathway4",
   ]));
   slipping();
}

void init(){
   ::init();
   add_action("climb_em","climb");
}

string ndesc(){
   if(TP->query_size() < 2){
      return("%^BLUE%^The wide, empty %^ORANGE%^trail %^BLUE%^seems eerily open at night, "+
         "as if it would allow ample room for anything that might hunt you.  "+
         "The safety of the %^GREEN%^trees %^BLUE%^is far out of reach, "+
         "their branches fading into the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^high overhead.  To either side of the path, "+
         "the %^BOLD%^%^BLACK%^dark, shadowy shapes %^RESET%^%^BLUE%^"+
         "of %^ORANGE%^tree trunks %^BLUE%^rise, tangled in a mess of "+
         "%^GREEN%^underbrush%^BLUE%^.  Huge, hulking %^BOLD%^%^BLACK%^"+
         "shadows %^RESET%^%^BLUE%^tower overhead at strange intervals.  "+
         "A pile of huge %^RESET%^boulders %^BLUE%^has come to rest here, "+
         "blocking passage any further south.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^BLUE%^The wide %^ORANGE%^path %^BLUE%^provides little "+
         "cover, although you doubt much could come through the thick "+
         "tangle of %^GREEN%^undergrowth %^BLUE%^that seems almost "+
         "intent on taking over the forest.  The branches of the "+
         "%^GREEN%^trees %^BLUE%^are high overhead, almost out of view "+
         "in the %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  In the "+
         "dark, the %^GREEN%^pine needles %^BLUE%^look like dark pools "+
         "on the %^ORANGE%^trail%^BLUE%^.  Lining the path at odd "+
         "intervals are huge, hulking %^BOLD%^%^BLACK%^shadows "+
         "%^RESET%^%^BLUE%^that reach well over your head.  "+
         "A pile of huge %^RESET%^boulders %^BLUE%^has come to rest here, "+
         "blocking passage any further south.");
   } else {
   return("%^BLUE%^The trail seems pleasant even at night, with the "+
      "wide %^ORANGE%^path %^BLUE%^providing just enough room without "+
      "making it feel too open.  The %^GREEN%^trees %^BLUE%^are "+
      "comfortably just over your head, and the thick %^GREEN%^"+
      "undergrowth %^BLUE%^provides something of a low wall on "+
      "either side of you.  The tall %^BOLD%^%^BLACK%^shadowy "+
      "shapes %^RESET%^%^BLUE%^of the boulders rise at irregular "+
      "intervals along the %^ORANGE%^trail %^BLUE%^and seem almost "+
      "comforting somehow.  "+
         "A pile of huge %^RESET%^boulders %^BLUE%^has come to rest here, "+
         "blocking passage any further south.");
   }
}

int climb_em(string str)
{
    if(!str)
    {
        tell_object(TP,"What are you trying to climb?");
        return 1;
    }
    if(str == "stairs" || str == "the stairs" || str == "up stairs" || str == "boulders" || str == "stones")
    {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped())
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        if(TP->query_size() < 3)
        {
         //if(TP->query_stats("dexterity") < random(25)) {
            if(!CLIMB_D->check_climb(random(25), TP))
            {
                tell_object(TP,"%^BOLD%^%^RED%^You try to climb the stairs "+
                "but lose your grip and fall back down!");
                tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" falls hard to the "+
                "ground after trying to climb the boulders!",TP);
                TP->set_tripped(2,"You are recovering from your fall!");
                return 1;
            }
            tell_object(TP,"Stretching, you manage to climb the stairs "+
            "using both your hands and feet.");
            tell_room(ETP,""+TPQCN+" uses both "+TP->QP+" "+
            "hands and feet to slowly climb up the boulders.",TP);
            TP->move(PATHEXIT"pathway6");
            tell_room(ETP,""+TPQCN+" slowly pulls "+TP->QO+"self over "+
            "the top of the boulders.",TP);
            TP->force_me("look");
            return 1;
        }
        if(TP->query_size() > 2)
        {
            tell_object(TP,"You easily climb up the well-placed steps.");
            tell_room(ETP,""+TPQCN+" walks easily up the boulders, making "+
            "it seem a stairway.",TP);
            TP->move(PATHEXIT"pathway6");
            //moved this down so that hopefully it wont bug when
            //the room has been loaded - Saide
            tell_room(ETP,""+TPQCN+" steps easily up the"+
            "boulders.",TP);
            TP->force_me("look");
            return 1;
        }
    }
    return 0;
}
