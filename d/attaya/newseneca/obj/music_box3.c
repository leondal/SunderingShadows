//music_box2.c - coded by ~Circe~, descriptions by Lurue
//for new Seneca 1/6/08
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("music box");
   set_short("%^BOLD%^%^WHITE%^a porcelain music box%^RESET%^");
   set_id(({"musicbox","music box","porcelain music box","porcelain shell","shell music box"}));
   set_long("%^BOLD%^%^WHITE%^Made from porcelain this finely made "+
      "clam shell looks almost real due to the diligent efforts of "+
      "the painter.  Pale white with a pearlescent %^BLACK%^g"+
      "%^RESET%^r%^BOLD%^%^WHITE%^a%^BLACK%^y %^WHITE%^sheen to "+
      "it, the shell opens to reveal a shimmer of faint %^MAGENTA%^"+
      "p%^WHITE%^i%^MAGENTA%^nk %^WHITE%^luster upon the interior "+
      "with a bed of darker %^RESET%^%^MAGENTA%^m%^BOLD%^a%^RESET%^"+
      "u%^MAGENTA%^ve %^BOLD%^%^WHITE%^below.  Nestled in the "+
      "bottom shell is a real p%^MAGENTA%^e%^RESET%^a%^BOLD%^"+
      "%^WHITE%^rl that has been affixed to the hidden mechanism.  "+
      "When the pearl is turned clockwise, the music box plays an "+
      "enchanting melody.%^RESET%^");
   set_value(1100);
   set_weight(3);
}

void init(){
   ::init();
   add_action("turn_em","turn");
}

int turn_em(string str){
   if(!str) return 0;
   if(str != "knob" && str != "pearl" && str != "pearl on music box" && str != "knob on music box") return 0;
   tell_object(TP,"You turn the pearl on a music box.");
   if(ETO == TP){
      tell_room(EETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(EETO,"%^BOLD%^%^CYAN%^An enchanting melody full of "+
         "the sounds of wind and water crashing while flutes, "+
         "horns, and stringed instruments play lifts from the "+
         "delicate porcelain music box.%^RESET%^");
   }else{
      tell_room(ETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(ETO,"%^BOLD%^%^CYAN%^An enchanting melody full of "+
         "the sounds of wind and water crashing while flutes, "+
         "horns, and stringed instruments play lifts from the "+
         "delicate porcelain music box.%^RESET%^");
   }
   call_out("turn2",3);
   return 1;
}

void turn2(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^CYAN%^The melody playing within "+
         "the porcelain music box combines stringed instruments, "+
         "flutes, horns, and the sounds of wind and water to "+
         "create an invigorating song.%^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^CYAN%^The melody playing within "+
         "the porcelain music box combines stringed instruments, "+
         "flutes, horns, and the sounds of wind and water to "+
         "create an invigorating song.%^RESET%^");
   }
   call_out("turn3",3);
   return;
}

void turn3(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^CYAN%^You almost feel like you "+
         "are sailing over the waves as the music box plays "+
         "the sounds of stringed instruments blending "+
         "flawlessly with horns, flutes, and natural sounds.%^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^CYAN%^You almost feel like you "+
         "are sailing over the waves as the music box plays "+
         "the sounds of stringed instruments blending "+
         "flawlessly with horns, flutes, and natural sounds.%^RESET%^");
   }
   call_out("turn4",3);
   return;
}

void turn4(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^CYAN%^The music box's song fades "+
         "slowly away leaving you with a memory of waves and wind.%^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^CYAN%^The music box's song fades "+
         "slowly away leaving you with a memory of waves and wind.%^RESET%^");
   }
   return;
}