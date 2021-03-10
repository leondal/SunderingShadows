//pathway.c - Inherit for that path to the firbolg village.  Circe 1/04/04
#include <std.h>
#include <daemons.h>
inherit ROOM;

void slipping();
void do_slipping();

void create() {
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A rough trail"); 
   set_short("A rough trail");
   set_long( (: TO, "ldesc" :) );
   set("night long", (: TO, "ndesc" :));
   set_items(([
      ({"path","trail","pathway","footpath"}) : (: TO, "path_desc" :),
      ({"tree","trees","evergreens"}) : (: TO, "tree_desc" :),
      ({"brush","undergrowth","bushes"}) : (: TO, "brush_desc" :),
      ({"rocks","stones","rock","stone","boulder","boulders"}) : (: TO, "rocks_desc" :),
      ({"pinecones","needles","pine needles","cones"}) : (: TO, "needles_desc" :),
   ]));
   set_property("treestride_possible",1);
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","Occasional rustling noises rise from the undergrowth.");
}

string ldesc(){
   string tmp;
/*
   if(TP->query_size() < 2){
      return("This %^ORANGE%^footpath %^RESET%^is incredibly wide, stretching out "+
         "at least four feet on either side of you.  The %^ORANGE%^trail %^RESET%^"+
         "looks as if it sees little use, and its %^BOLD%^%^BLACK%^rocky %^RESET%^"+
         "cradle has been covered over with %^CYAN%^seas %^RESET%^of %^GREEN%^"+
         "pine needles %^RESET%^and large %^ORANGE%^pinecones %^RESET%^the size "+
         "of both your fists.  The %^GREEN%^trees %^RESET%^loom high overhead, "+
         "with their first branches starting well above anywhere you could reach.  "+
         "Thick %^GREEN%^undergrowth %^RESET%^crowds along the floor of the sparse "+
         "forest, making it impossible for you to leave the trail.\n");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
*/
      tmp = "This %^ORANGE%^footpath %^RESET%^is rather wide, about eight "+
         "feet across in most places.  It would easily be wide enough for "+
         "wagons, but the %^BOLD%^%^BLACK%^rocky bottom %^RESET%^and "+
         "%^GREEN%^pine needles %^RESET%^make that all but impossible.  "+
         "It seems strange that a path so wide would twist and turn so up the "+
         "mountainside, clearly making it impractical for trade.  %^ORANGE%^"+
         "Pinecones %^RESET%^falling from the tall %^GREEN%^evergreens %^RESET%^"+
         "above have littered the trail as well, and large %^BOLD%^%^BLACK%^"+
         "boulders %^RESET%^just about your height are scattered around the "+
         "trail.  The ancient %^GREEN%^trees %^RESET%^are surrounded by "+
         "%^GREEN%^thick undergrowth %^RESET%^that make it impossible to leave "+
         "the trail.\n";
/*
   } else {
   return("This %^ORANGE%^trail %^RESET%^winding up the mountainside "+
      "feels like it was made for you.  It is quite wide, with plenty "+
      "of room on either side.  Tall, ancient %^GREEN%^evergreens "+
      "%^RESET%^rise high above, towering well over even your head.  The "+
      "%^BOLD%^%^BLACK%^rocky path %^RESET%^has grown covered with "+
      "%^GREEN%^pine needles %^RESET%^and occasional %^ORANGE%^"+
      "pinecones%^RESET%^, which might make footing slippery for "+
      "those with a shorter stride than yours.  Large %^BOLD%^%^BLACK%^"+
      "boulders %^RESET%^stand along the trail, just reaching your "+
      "shoulders.  Running through the forest around the bases of the "+
      "trees is a thick tangle of short %^GREEN%^bushes %^RESET%^that would "+
      "make leaving the trail all but impossible.\n");
   }
*/
   return tmp;
}

string ndesc(){
   string tmp;
/*
   if(TP->query_size() < 2){
      return("%^BLUE%^The wide, empty %^ORANGE%^trail %^BLUE%^seems eerily open at night, "+
         "as if it would allow ample room for anything that might hunt you.  "+
         "The safety of the %^GREEN%^trees %^BLUE%^is far out of reach, "+
         "their branches fading into the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^high overhead.  To either side of the path, "+
         "the %^BOLD%^%^BLACK%^dark, shadowy shapes %^RESET%^%^BLUE%^"+
         "of %^ORANGE%^tree trunks %^BLUE%^rise, tangled in a mess of "+
         "%^GREEN%^underbrush%^BLUE%^.  Huge, hulking %^BOLD%^%^BLACK%^"+
         "shadows %^RESET%^%^BLUE%^tower overhead at strange intervals.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
*/
      tmp = "%^BLUE%^The wide %^ORANGE%^path %^BLUE%^provides little "+
         "cover, although you doubt much could come through the thick "+
         "tangle of %^GREEN%^undergrowth %^BLUE%^that seems almost "+
         "intent on taking over the forest.  The branches of the "+
         "%^GREEN%^trees %^BLUE%^are high overhead, almost out of view "+
         "in the %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  In the "+
         "dark, the %^GREEN%^pine needles %^BLUE%^look like dark pools "+
         "on the %^ORANGE%^trail%^BLUE%^.  Lining the path at odd "+
         "intervals are huge, hulking %^BOLD%^%^BLACK%^shadows "+
         "%^RESET%^%^BLUE%^that reach well over your head.";
/*
   } else {
   return("%^BLUE%^The trail seems pleasant even at night, with the "+
      "wide %^ORANGE%^path %^BLUE%^providing just enough room without "+
      "making it feel too open.  The %^GREEN%^trees %^BLUE%^are "+
      "comfortably just over your head, and the thick %^GREEN%^"+
      "undergrowth %^BLUE%^provides something of a low wall on "+
      "either side of you.  The tall %^BOLD%^%^BLACK%^shadowy "+
      "shapes %^RESET%^%^BLUE%^of the boulders rise at irregular "+
      "intervals along the %^ORANGE%^trail %^BLUE%^and seem almost "+
      "comforting somehow.");
   }
*/
   return tmp;
}

string path_desc(){
   if(TP->query_size() < 2){
      return("The pathway is huge!  It winds its way up the mountainside "+
         "and is very wide.  Something much larger than you must have "+
         "worked hard to make this pathway, although it seems to have "+
         "become less used over the years.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("This pathway is clearly wider than it would need to be for most "+
         "humans.  It spans a little over eight feet, but there are no signs of "+
         "wagon ruts whatsoever.");
   } else {
   return("This comfortable pathway must have been made with someone like you "+
      "in mind.  It is wide enough to allow you easy passage, and even the "+
      "tree branches rise high over your head, giving you room to breathe.");
   }
}

string tree_desc(){
   if(TP->query_size() < 2){
      return("%^GREEN%^Giant evergreens rise all around you.  Their "+
         "thick branches prevent you from seeing very far, and you cannot "+
         "tell how tall they might be.  Their trunks are thick, and it would "+
         "be easy to hide your slight body behind them.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^GREEN%^The ancient evergreens tower high over you.  Their "+
         "branches clear your head by several feet, and it looks as though the "+
         "lower branches may have been cut back, though you cannot tell when..."+
         "or why.");
   } else {
   return("%^GREEN%^The ancient evergreens rising around you seem to have "+
      "stood here for countless years.  You notice that the lower branches, "+
      "which would have caused you to duck, have been trimmed away and their "+
      "stubs have been sealed so that they will not grow back.  Someone clearly "+
      "tends to this path.");
   }
}

string brush_desc(){
   if(TP->query_size() < 2){
      return("Holly bushes and long, twisting vines of ivy crowd "+
         "close together beneath the ancient trees.  Most of the "+
         "bushes are about your height, and they grow so close "+
         "together that it is impossible to leave the trail.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("Vibrant holly bushes mingle with long, twisting vines of "+
         "ivy, crowding close together beneath the ancient trees.  "+
         "The bushes come up to your waist and are so thick they would "+
         "make leaving the path incredibly difficult.");
   } else {
   return("Down around your knees, holly bushes and twisting vines of "+
      "ivy form a very thick brush.  Although you could probably step "+
      "over it, it would make travelling off the pathway very difficult.");
   }
}

string rocks_desc(){
   if(TP->query_size() < 2){
      return("The pathway has a rocky bottom that spreads out wide "+
         "beneath the trees.  Here and there large rocks stand, some "+
         "of them towering well over your head.  They might have "+
         "been markers of some kind...or they might be left from "+
         "landslides.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("The rocky bottom of the pathways spreads wide beneath "+
         "the trees.  Large boulders about your height stands in "+
         "random places along the path.  You cannot quite tell why "+
         "they are there, but perhaps they were left by a landslide.");
   } else {
   return("Large boulders scattered here and there on the trail "+
      "rise to just below your shoulders.  They are placed at wide "+
      "intervals, and you can tell from markings made on their tops "+
      "that they provide directions.  An arrow pointing up and northward "+
      "has been marked %^BOLD%^%^GREEN%^Lothwaite%^RESET%^, while "+
      "those pointing down and southward are marked %^YELLOW%^"+
      "Dagger%^RESET%^.");
   }
}

string needles_desc(){
   if(TP->query_size() < 2){
      return("%^ORANGE%^Pinecones %^RESET%^are scattered across the "+
         "pathway, resting on beds of %^GREEN%^needles%^RESET%^.  "+
         "Most of the cones are larger than both of your hands together, "+
         "and they still fall occasionally from the trees above.  "+
         "The slick %^GREEN%^pine needles %^RESET%^make footing "+
         "uncertain at times.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("Thick, slippery layers of %^pine needles %^RESET%^line "+
         "the rocky bottom of the pathway.  They make footing a little "+
         "treacherous, and you have to watch your step to avoid falling "+
         "down.  %^ORANGE%^Pinecones %^RESET%^ are scattered around as well, "+
         "and a cracking sound occasionally echoes down the path as one "+
         "falls from overhead.");
   } else {
   return("Small piles of %^GREEN%^pine needles %^RESET%^have fallen "+
      "on the pathway, a minor annoyance that has not yet been cleaned up.  "+
      "They are spread wide apart, allowing you to easily step over them.  "+
      "Tiny %^ORANGE%^pinecones %^RESET%^also dot the ground below and "+
      "randomly fall from overhead.");
   }
}

void slipping() {
    int i;
    string *exits, *num;
    exits = ({}) + TO->query_exits();
    num = ({});
    for(i = 0;i < sizeof(exits);i++) {
      if(num == ({})) {
         num = ({"GoThroughDoor"});
         continue;
      }
         num += ({"GoThroughDoor"});
    }
    if(sizeof(exits) > 0) {
      set_pre_exit_functions(exits,num);
    }       
}

int do_slipping() {
int dex;
   dex = TP->query_stats("dexterity");
   if(TP->query_size() > 2) return 1;
   if(TP->query_true_invis()) return 1;
   if(TP->query_property("flying")){
      if(!random(3)){ 
         tell_object(TP,"You glide over the slippery needles.");
      }
      return 1;
   }
   if(!TP->query_in_vehicle()){
      if(dex < random(16)) { //changed from random(19) so that those
//players who have a dex above 15 never slip ~Circe~ 5/13/08
         tell_object(TP,"%^BOLD%^%^GREEN%^You slip on the pine needles, "+
            "falling flat on your face!");
         tell_room(TO,"%^BOLD%^%^GREEN%^"+TPQCN+" slips on the pine "+
            "needles as "+TP->QS+" leaves and falls flat on "+TP->QP+" face!",TP);
         TP->set_tripped(1,"You are still trying to catch your breath.  Wow, "+
            "those were slippery!");
         return 1;
      }
   }
}

int GoThroughDoor(){
   do_slipping();
   return 1;
}

void reset(){
    int i;
    object *live;
    object targ;
    live = ({}) + filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
    if(sizeof(live) < 1) return;
    targ = live[random(sizeof(live))];
   ::reset();
        if(!objectp(targ)) return;
           if((int)targ->query_stats("dexterity") < random(30)){
              tell_object(targ,"%^ORANGE%^A pinecone dropping from the trees above "+
                 "bounces off your head.");
              tell_room(TO,"%^ORANGE%^A pinecone falls from above, bouncing off "+
                 ""+targ->QCN+"'s head!",targ);
              TO->set_property("magic", 1);
              targ->do_damage("head", random(3)+4);
              TO->set_property("magic", -1);
              return;
           }
           tell_room(TO,"%^CYAN%^A pinecone drops from above and lands on the ground.");
           return;
}