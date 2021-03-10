//pathway6.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include <daemons.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create()
{
   ::create();
   set_long(::query_long()+"%^RESET%^%^BLUE%^The passage drop sharply to the southwest, "+
      "and a pile of %^BOLD%^boulders %^RESET%^lies across the path that way.");
   set("night long",(:TO,"ndesc":));
   add_item("boulders","The pile of boulders looks to form a semi-circle "+
      "on the lower pathway.  It would be too treacherous to jump, but you "+
      "might be able to climb down the boulders.");
   add_item("pile","The pile of boulders looks to form a semi-circle "+
      "on the lower pathway.  It would be too treacherous to jump, but you "+
      "might be able to climb down the boulders.");
   set_search("default","The pile of boulders catches your attention.");
   set_search("boulders","You search the pile of boulders and realize "+
      "they look like stairs you could climb down.");
   set_search("pile","You search the pile of boulders and realize "+
      "they look like stairs you could climb down.");
   set_exits(([
      "northeast" : PATHEXIT"pathway7",
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
         "The passage drops sharply to the southwest, and a pile of %^BOLD%^"+
         "%^WHITE%^boulders %^RESET%^%^BLUE%^lies across the path that way.");
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
         "The passage drops sharply to the southwest, and a pile of %^BOLD%^"+
         "%^WHITE%^boulders %^RESET%^%^BLUE%^lies across the path that way.");
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
         "The passage drops sharply to the southwest, and a pile of %^BOLD%^"+
         "%^WHITE%^boulders %^RESET%^%^BLUE%^lies across the path that way.");
   }
}

int climb_em(string str)
{
    if(!str)
    {
        tell_object(TP,"What are you trying to climb?");
        return 1;
    }
    if(str == "stairs" || str == "the stairs" || str == "down stairs" || str == "boulders" || str == "the boulders" || str == "down boulders")
    {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        if(TP->query_size() < 3)
        {
            //if(TP->query_stats("dexterity") < random(25)) 
            if(!CLIMB_D->check_climb(random(25), TP))
            {
                tell_object(TP,"%^BOLD%^%^RED%^As you try to climb down the boulders, "+
                "you lose your footing and fall!");
                tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" falls hard to the "+
                "ground below after trying to climb down the boulders!",TP);
                TP->move(PATHEXIT"pathway5");
                TP->force_me("look");
                TP->set_tripped(2,"You are recovering from your fall!");
                return 1;
            }
            tell_object(TP,"Stretching, you manage to climb down the stairs "+
            "using both your hands and feet.");
            tell_room(ETP,""+TPQCN+" slowly lowers "+TP->QO+"self over "+
            "the boulders.",TP);
            TP->move(PATHEXIT"pathway5");
            tell_room(ETP,""+TPQCN+" uses both "+TP->QP+" "+
            "hands and feet to slowly climb down the boulders.",TP);
            TP->force_me("look");
            return 1;
        }
        if(TP->query_size() > 2)
        {
            tell_object(TP,"You easily climb down the well-placed steps.");
            tell_room(ETP,""+TPQCN+" walks easily down the boulders, making "+
            "it seem a stairway.",TP);
            TP->move(PATHEXIT"pathway5");
            //same as pathway5, shouldn't change anything except when the message
            //is given - Saide
            tell_room(ETP,TPQCN+" steps easily down the"+
            "boulders.",TP);
            TP->force_me("look");
            return 1;
        }
      
    }
    return 0;
}

