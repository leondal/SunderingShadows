//vilpathway.c - Inherit for the path through Lothwaite.  Circe 2/14/04
#include <std.h>
#include <daemons.h>
inherit VAULT;

void villagelife();
void do_villagelife();

void create(){
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_property("night light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A wide footpath"); 
   set_short("A wide footpath");
   set_long( (: TO, "ldesc" :) );
   set("night long", (: TO, "ndesc" :));
   set_items(([
      ({"path","trail","pathway","footpath"}) : (: TO, "path_desc" :),
      ({"mountain","mountainside","rocks","rocky mountainside"}) : (: TO, "mtn_desc" :),
      ({"bushes","bush","scraggly bushes"}) : (: TO, "bush_desc" :),
      ({"building","buildings"}) : (: TO, "buildings_desc" :),
      "grass" : "%^BOLD%^%^GREEN%^The grass covers all the ground not taken up "+
         "by the pathway.  Despite the rocky surroundings, it is a vibrant "+
         "green and is kept cut short.",
      ({"hawk","hawks","sky"}) : "Occasionally hawks wheel in the sky, little more "+
         "than tiny dots against the blue backdrop.",
      ({"thin poles","small poles","pennant","pennants","flags"}) : (: TO, "flags_desc" :),
      ({"tall poles","large poles","lanterns","ropes","lantern"}) : (: TO, "lantern_desc" :),
      ({"panel","panels","wattle"}) : "%^ORANGE%^Wattle panels are very thin "+
         "panels made from woven willow.  Mud has been used to fill in the cracks.",
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
}

string ldesc(){
   string tmp;
/*   if(TP->query_size() < 2){
      tmp = "%^GREEN%^Massive %^RESET%^buildings %^GREEN%^rise up "+
         "all around you, and even the %^ORANGE%^pathway %^GREEN%^you "+
         "are walking on seems enormous.  Scraggly %^BOLD%^bushes "+
         "%^RESET%^%^GREEN%^line the path, reaching about as tall "+
         "as you are.  Despite the rocky %^BOLD%^%^BLACK%^mountainside"+
         "%^RESET%^%^GREEN%^, %^BOLD%^grass %^RESET%^%^GREEN%^grows "+
         "all in this valley.  The %^CYAN%^sky %^GREEN%^above seems empty "+
         "except for occasional %^RED%^hawks %^GREEN%^that wheel "+
         "on the air currents.  You occassionally see  "+
         "thick %^ORANGE%^poles %^GREEN%^from which bright massive %^BOLD%^"+
         "green %^RESET%^%^GREEN%^and %^BOLD%^%^WHITE%^white "+
         "%^RESET%^%^GREEN%^pennants wave.  Thick rope has been run between "+
         "poles well over four times your height, and strung onto the rope are "+
         "several unlit %^YELLOW%^lanterns%^RESET%^%^GREEN%^.";
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
*/
      tmp = "%^GREEN%^Abnormally tall %^ORANGE%^buildings %^GREEN%^stand "+
         "all around these twisting %^ORANGE%^pathways%^GREEN%^.  "+
         "The %^ORANGE%^path %^GREEN%^itself is extremely wide, easily "+
         "wide enough for three or four humans to walk abreast of "+
         "one another.  Lining the %^ORANGE%^path %^GREEN%^are scraggly "+
         "%^BOLD%^bushes %^RESET%^%^GREEN%^reaching just about to your "+
         "waist.  Although the entire %^BOLD%^%^BLACK%^mountainside "+
         "%^RESET%^%^GREEN%^around this hamlet seems rocky, this "+
         "uneven valley is filled with %^BOLD%^grass%^RESET%^%^GREEN%^.  "+
         "The %^CYAN%^sky %^GREEN%^above is gray and empty except for "+
         "occasional %^RED%^hawks %^GREEN%^that wheel and dive on "+
         "air currents.  %^ORANGE%^Poles %^GREEN%^placed at "+
         "seemingly random points support large %^BOLD%^green %^RESET%^%^GREEN%^"+
         "and %^BOLD%^%^WHITE%^white %^RESET%^%^GREEN%^pennants.  Thick rope has "+
         "been run between poles well over twice your height, and strung onto the rope "+
         "are several unlit %^YELLOW%^lanterns%^RESET%^%^GREEN%^.";
/*   } else {
   tmp = "%^GREEN%^Low, one-story %^ORANGE%^buildings %^GREEN%^are "+
      "spread around the %^ORANGE%^pathway %^GREEN%^you walk upon.  "+
      "The %^ORANGE%^path %^GREEN%^seems to have been made for you, "+
      "extending about an extra foot and a half on either side of you.  "+
      "Short, scraggly %^BOLD%^bushes %^RESET%^%^GREEN%^barely reaching "+
      "your knee have been placed at intervals along the %^ORANGE%^path "+
      "%^GREEN%^and seem to give it some definition.  You can see that "+
      "though the %^BOLD%^%^BLACK%^mountainside %^RESET%^%^GREEN%^is "+
      "rocky, the small valley you're standing in is filled with "+
      "well-tended %^BOLD%^grass%^RESET%^%^GREEN%^.  The %^CYAN%^sky "+
      "%^GREEN%^above is empty, save for an occasional small %^RED%^hawk "+
      "%^GREEN%^that dives and dances on the air currents.  Extremely "+
      "thin %^ORANGE%^poles %^GREEN%^are placed at even intervals "+
      "all around the halmlet, each one bearing a small %^BOLD%^green "+
      "%^RESET%^%^GREEN%^and %^BOLD%^%^WHITE%^white %^RESET%^%^GREEN%^"+
      "pennant.  Thin cording has been run between poles just above your head, "+
      "and strung on the cording are unlit %^YELLOW%^lanterns%^RESET%^%^GREEN%^.";
   }
*/
   return tmp;
}

string ndesc(){
   string tmp;
/*   if(TP->query_size() < 2){
      return("%^BLUE%^Massive buildings rise up all around you, their "+
         "gigantic bulk casting deep %^BOLD%^%^BLACK%^shadows %^RESET%^"+
         "%^BLUE%^over the %^ORANGE%^path%^BLUE%^.  The %^ORANGE%^path "+
         "%^BLUE%^seems far too open, but the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^is scattered somewhat by the %^YELLOW%^light "+
         "%^RESET%^%^BLUE%^of the many %^YELLOW%^lanterns %^RESET%^%^BLUE%^"+
         "hanging from %^ORANGE%^ropes %^BLUE%^far overhead.  Quick "+
         "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^and an eerie flapping "+
         "sound hint at the pennants flying high above.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
*/
      tmp = "%^BLUE%^Large buildings rise up all around you, their "+
         "oversized bulk casting deep %^BOLD%^%^BLACK%^shadows %^RESET%^"+
         "%^BLUE%^over the %^ORANGE%^path%^BLUE%^.  The %^ORANGE%^path "+
         "%^BLUE%^seems rather open, but the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^is scattered somewhat by the %^YELLOW%^light "+
         "%^RESET%^%^BLUE%^of the many %^YELLOW%^lanterns %^RESET%^%^BLUE%^"+
         "hanging from %^ORANGE%^ropes %^BLUE%^well overhead.  Quick "+
         "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^and an eerie flapping "+
         "sound hint at the pennants flying around the path.";
/*
   } else {
   return("%^BLUE%^Buildings rise up all around you, their "+
         "bulk casting deep %^BOLD%^%^BLACK%^shadows %^RESET%^"+
         "%^BLUE%^over the %^ORANGE%^path%^BLUE%^.  The %^ORANGE%^path "+
         "%^BLUE%^seems comfortable and welcoming, and the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^is scattered somewhat by the %^YELLOW%^light "+
         "%^RESET%^%^BLUE%^of the many %^YELLOW%^lanterns %^RESET%^%^BLUE%^"+
         "hanging from %^ORANGE%^ropes %^BLUE%^just overhead.  Quick "+
         "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^and an eerie flapping "+
         "sound hint at the pennants flying around the path.");
   }
*/
   return tmp;
}

string path_desc(){
   if(TP->query_size() < 2){
      return("The pathway is huge!  It is made of strong timber planks "+
         "bound together with rope lashings.  The rope is easily as thick "+
         "as your wrist.  It has been covered in mud "+
         "to help fill in cracks, and some sections have panels of wattle "+
         "as well.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("This pathway is clearly wider than it would need to be for most "+
         "humans.  It spans a little over eight feet, and it is made of large "+
         "wooden planks bound together with thick rope lashings.  The pathway "+
         "is covered in mud to fill in the cracks, and some portions are made "+
         "up of wattle panels.");
   } else {
   return("This comfortable pathway must have been made with someone like you "+
      "in mind.  It is wide enough to allow you easy passage, and it gives you "+
      "a pleasant view of the small hamlet around you.  The pathway is made of "+
      "narrow planks tied together with cording, and the cracks have been filled "+
      "with mud.  Small panels of wattle have been used in some places as well.");
   }
}

string mtn_desc(){
   if(TP->query_size() < 2){
      return("This massive valley forms a deep cleft in the mountainside.  All "+
         "around it, the deep gray stone of the mountain rises up to form "+
         "some measure of shelter.  However, the wind still howls through "+
         "the valley, bringing a chillness that seldom leaves the pennants still.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("This large valley forms a deep cleft in the mountainside.  All "+
         "around it, the deep gray stone of the mountain rises up to form "+
         "some measure of shelter.  However, the wind still howls through "+
         "the valley, bringing a chillness that seldom leaves the pennants still.");
   } else {
   return("This small valley forms a cleft in the mountainside.  All "+
         "around it, the deep gray stone of the mountain rises up to form "+
         "some measure of shelter.  However, the wind still howls through "+
         "the valley, bringing a chillness that seldom leaves the pennants still.");
   }
}

string bush_desc(){
   if(TP->query_size() < 2){
      return("%^GREEN%^Scraggly bushes twisted by the wind line the path.  Despite "+
         "their strange, somewhat tortured appearance, they are evidently quite "+
         "healthy and rise to your height.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^GREEN%^These tall bushes rise to your waist and seem to have "+
         "been misshapen by the wind.  They are still very healthy, however, "+
         "and look well-tended.");
   } else {
   return("%^GREEN%^Scraggly bushes reach to about your knees, lining the "+
      "path on each side.  They seem to have been twisted and warped by the "+
      "wind, although they are obviously cared-for.");
   }
}

string buildings_desc(){
   if(TP->query_size() < 2){
      return("%^ORANGE%^The massive wooden buildings rise up high over your head, "+
         "so tall that they seem to block out the light.  The sides are made of "+
         "wattle packed with mud to keep out the chill.  There seem to be no windows, "+
         "but you catch a glimpse of smoke rising into the air.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^ORANGE%^The tall buildings look to be at least two stories high.  They "+
         "are made of wattle that has been packed with mud to keep out the chill wind "+
         "of the valley.  Each building is at least twice as long as it is tall, and "+
         "just peeking over each slanted room, you can see the round stones of a chimney "+
         "belching smoke.");
   } else {
   return("%^ORANGE%^The buildings rise a little over head and shoulders taller than "+
      "you.  The walls are made of wattle that has been packed with dirt and mud to keep "+
      "out the bitter wind of the valley.  The rooftops are all slanted, supporting "+
      "round stone chimneys at their peaks.  The buildings are much longer than they "+
      "are tall, sprawling out over the valley.");
   }
}

string flags_desc(){
   if(TP->query_size() < 2){
      return("%^GREEN%^Poles thicker than your arm rise up from the ground at strange "+
         "intervals, sprouting atop hills and in crannies.  They reach over twice your "+
         "height, and craning your neck, you can see that they support enormous "+
         "triangular pennants made of %^BOLD%^green fabric %^RESET%^%^GREEN%^"+
         "trimmed in %^BOLD%^%^WHITE%^white braid%^RESET%^%^GREEN%^.  In the center "+
         "of each pennant is the same symbol - five bees flying in a diamond pattern.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^GREEN%^Sturdy poles about wrist-thick rise up from the ground at "+
         "what seems to be strange intervals, standing high atop hills and deep "+
         "within crannies.  They reach well over your head, and each one supports "+
         "a large triangulard pennant made of %^BOLD%^green fabric %^RESET%^%^GREEN%^"+
         "trimmed in %^BOLD%^%^WHITE%^white braid%^RESET%^%^GREEN%^.  In the center "+
         "of each pennant is the same symbol - five bees flying in a diamond pattern.");
   } else {
   return("%^GREEN%^Thin poles whip in the wind, rising up to just above your "+
      "shoulders.  They are placed at regular intervals, set rigidly in place "+
      "no matter what the terrain.  Consequently, several rise from hills while "+
      "others are in deep crannies.  Each pole supports "+
      "a large triangulard pennant made of %^BOLD%^green fabric %^RESET%^%^GREEN%^"+
      "trimmed in %^BOLD%^%^WHITE%^white braid%^RESET%^%^GREEN%^.  In the center "+
      "of each pennant is the same symbol - five bees flying in a diamond pattern.");
   }
}

string lantern_desc(){
   if(query_night()){
      if(TP->query_size() < 2){
         return("Enormous poles reaching to dizzying heights above your head "+
            "have been strung with thick ropes.  From the ropes hang many "+
            "brightly lit %^YELLOW%^lanterns%^RESET%^, bathing the path in "+
            "their golden light.");
      }
      if(TP->query_size() > 1 && TP->query_size() < 3){
         return("Thick poles lining the path reach about twice your height, and thick "+
            "rope has been strung up between them.  From the ropes hang many "+
            "brightly lit %^YELLOW%^lanterns%^RESET%^, bathing the path in "+
            "their golden light.");
      } else {
      return("Poles lining the winding path rise up just above your head.  "+
         "Thick rope has been strung between them, supporting many "+
         "brightly lit %^YELLOW%^lanterns%^RESET%^, bathing the path in "+
         "their golden light.");
      }
   } else {
      if(TP->query_size() < 2){
         return("Enormous poles reaching to dizzying heights above your head "+
            "have been strung with thick ropes.  From the ropes hang many "+
            "lanterns which may be lit at night to brighten the path.  Now, "+
            "though, they remain dark.");
      }
      if(TP->query_size() > 1 && TP->query_size() < 3){
         return("Thick poles lining the path reach about twice your height, and thick "+
            "rope has been strung up between them.  From the ropes hang many "+
            "lanterns which may be lit at night to brighten the path.  Now, "+
            "though, they remain dark.");
      } else {
      return("Poles lining the winding path rise up just above your head.  "+
         "Thick rope has been strung between them, supporting many "+
         "lanterns which may be lit at night to brighten the path.  Now, "+
         "though, they remain dark.");
      }
   }
}

void villagelife() {
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

void do_villagelife() {
   if(!random(4)) {
      switch(random(20)){
         case 0:  tell_room(TO,"%^GREEN%^A young firbolg girl skips down the path, giggling.");
                  break;
         case 1:  tell_room(TO,"%^CYAN%^A firbolg boy with a fishing pole wanders by on his way to the lake.");
                  break;
         case 2:  tell_room(TO,"%^BOLD%^%^BLACK%^A hawk wheels in the sky overhead.");
                  break;
         case 3:  tell_room(TO,"The sound of clashing swords rings out from the practice field.");
                  break;
         case 4:  tell_room(TO,"%^BOLD%^%^CYAN%^The wind whips around the mountainside, sending pennants fluttering.");
                  break;
         case 5:  tell_room(TO,"%^GREEN%^A deep green pennant, bordered with white, floats on the air.");
                  break;
         case 6:  tell_room(TO,"%^YELLOW%^A young firbolg maiden with blonde curls past her waist walks by.");
                  break;
         case 7:  tell_room(TO,"%^ORANGE%^A hulking firbolg warrior with a giant greatsword strides confidently down the path.");
                  break;
         case 8:  tell_room(TO,"A village elder with an aging gray beard pauses for a moment to sit on the side of the path.");
                  break;
         case 9:  tell_room(TO,"%^RESET%^%^ORANGE%^The breeze brings with it the sound of a slamming door.");
                  break;
         case 10:  tell_room(TO,"%^YELLOW%^The buzzing of bees fills the air briefly.");
                  break;
         case 11:  tell_room(TO,"%^CYAN%^A cool mountain breeze suddenly picks up before dying out just as quickly.");
                  break;
         case 12:  tell_room(TO,"The lonely sound of hammering makes its way down from the lake.");
                  break;
         case 13:  tell_room(TO,"The wind suddenly dies, leaving a strange quiet over the village.");
                  break;
         case 14:  tell_room(TO,"%^BOLD%^%^BLUE%^A hawk suddenly cries out on the wind.");
                  break;
         case 15:  tell_room(TO,"A firbolg couple strolls past with a toddler ambling between them.");
                  break;
         case 16:  tell_room(TO,"%^BLUE%^A strange moan rises on the wind from the southeast.");
                  break;
         case 17:  tell_room(TO,"%^BOLD%^%^CYAN%^The babbling voice of the spring rises above the noise of the wind.");
                  break;
         case 18:  tell_room(TO,"%^GREEN%^A tree branch creaks and breaks, falling to the ground somewhere in the forest.");
                  break;
         case 19:  tell_room(TO,"%^RESET%^%^ORANGE%^A chattering squirrel dashes across the path.");
                  break;
      }
      return;
   }
}

int GoThroughDoor(){
   if(!random(3)){
      do_villagelife();
   }
   return ::GoThroughDoor();
}

void reset(){
   ::reset();
   do_villagelife();
}