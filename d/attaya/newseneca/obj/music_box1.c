//music_box1.c - coded by ~Circe~, descriptions by Lurue
//for new Seneca 1/5/08
#include <std.h>

inherit BAG;

int closed;

void create(){
   ::create();
   set_name("a wooden music box");
   set_short("%^RESET%^%^ORANGE%^a wooden music box%^RESET%^");
   set_id(({"wooden music box","wood music box","music box","musicbox","box"}));
   set_long("%^RESET%^%^ORANGE%^This finely made %^RED%^rose "+
      "%^ORANGE%^and %^BOLD%^%^BLACK%^ash %^RESET%^%^ORANGE%^wood "+
      "box is small enough to fit in the palm of your hand.  "+
      "Delicately carved and masterfully finished with a deep, "+
      "vibrant %^YELLOW%^glow%^RESET%^%^ORANGE%^, the wood was "+
      "clearly shaped and designed by a master carver.  Opening "+
      "the lid reveals a painted %^GREEN%^forest scene%^ORANGE%^ "+
      "upon the inside lid.  In the foreground a pair of tiny "+
      "dancers twirl around each other as the sound of a %^RESET%^"+
      "woodwind instrument %^ORANGE%^plays in the background.  One "+
      "dancer appears to be a %^BOLD%^%^WHITE%^silk clad nymph "+
      "%^RESET%^%^ORANGE%^while the other is clearly a %^CYAN%^"+
      "faun%^ORANGE%^, complete with a goat legs and horns, "+
      "holding a set of panpipes to his lips.  A small metal knob "+
      "extends out the back of the box and can be turned clockwise "+
      "to wind the music box up.  A petite drawer in the front "+
      "allows an item, like a %^WHITE%^ring%^ORANGE%^, %^YELLOW%^"+
      "necklace %^ORANGE%^or %^BOLD%^%^CYAN%^pin %^RESET%^"+
      "%^ORANGE%^to be placed inside.  It is a delicate item and "+
      "could easily be crushed or broken if not handled carefully.%^RESET%^");
   set_value(1250);
   set_max_internal_encumbrance(2);
   set_weight(3);
   closed = 1;
}

int is_light_opaque() { return 1;}

void init(){
   ::init();
   add_action("turn_em","turn");
}

int turn_em(string str){
   if(!str) return 0;
   if(str != "knob" && str != "knob on music box") return 0;
   tell_object(TP,"You turn the knob on a music box.");
   if(ETO == TP){
      tell_room(EETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(EETO,"%^RESET%^%^ORANGE%^The sound of a %^RESET%^"+
         "woodwind instrument %^ORANGE%^rises from the tiny carved "+
         "music box and as the two dancers begin to twirl around "+
         "each other.%^RESET%^");
   }else{
      tell_room(ETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(ETO,"%^RESET%^%^ORANGE%^The sound of a %^RESET%^"+
         "woodwind instrument %^ORANGE%^rises from the tiny carved "+
         "music box and as the two dancers begin to twirl around "+
         "each other.%^RESET%^");
   }
   call_out("turn2",3);
   return 1;
}

void turn2(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^RESET%^%^ORANGE%^The %^RESET%^woodwind "+
         "instrument %^ORANGE%^lifts and falls as the two figures "+
         "in the carved music box twirl around each other in an "+
         "endless dance.%^RESET%^");
   }else{
      tell_room(ETO,"%^RESET%^%^ORANGE%^The %^RESET%^woodwind "+
         "instrument %^ORANGE%^lifts and falls as the two figures "+
         "in the carved music box twirl around each other in an "+
         "endless dance.%^RESET%^");
   }
   call_out("turn3",3);
   return;
}

void turn3(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^RESET%^%^ORANGE%^The carved figures of "+
         "the %^BOLD%^%^WHITE%^nymph %^RESET%^%^ORANGE%^and "+
         "%^CYAN%^fawn %^ORANGE%^circle each other as the sounds "+
         "of a %^RESET%^woodwind instrument %^ORANGE%^rise from "+
         "the small music box.%^RESET%^");
   }else{
      tell_room(ETO,"%^RESET%^%^ORANGE%^The carved figures of "+
         "the %^BOLD%^%^WHITE%^nymph %^RESET%^%^ORANGE%^and "+
         "%^CYAN%^fawn %^ORANGE%^circle each other as the sounds "+
         "of a %^RESET%^woodwind instrument %^ORANGE%^rise from "+
         "the small music box.%^RESET%^");
   }
   call_out("turn4",3);
   return;
}

void turn4(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^ORANGE%^The two figures begin to wind down "+
         "their dance as the music comes to an end.%^RESET%^");
   }else{
      tell_room(ETO,"%^ORANGE%^The two figures begin to wind down "+
         "their dance as the music comes to an end.%^RESET%^");
   }
   return;
}
