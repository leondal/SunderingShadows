// goldpan.c

#include <std.h>

inherit OBJECT;

int count;

void create(){
   ::create();
   set_id(({"pan","gold pan"}));
   set_name("pan");
   set_short("a pan");
   set_long("This is a small circular aluminum pan.  It is somewhat cone shaped and the inside edge of one side has a set of ridges built into it that look like they are designed to catch something.  Tiny %^YELLOW%^golden flecks %^RESET%^catch your eye from the inside of the pan.  On the bottom of the pan is a small inscription.");
   set_read("%^BOLD%^BLUE%^%^To the fair townsfolk of Levinshire, I gift you each"
" with this to help you live long your simple yet prosperous lifestyle.  May the"
" bounties brought forth by this gift add to the beauty of your fine city.%^RESET%^");
   set_language("common"); 
   set_weight(1);
   set_size(2);
}
void init(){
   ::init();
   add_action("panning","pan");
}
int panning(string str){
   if(!str) return notify_fail("Pan what?\n");
   if(member_array(str,({"water","stream","river","for gold"})) == -1) return
notify_fail("You cannot pan that!\n");
   if(!ETP->is_goldriver()) return notify_fail("This doesn't look like a good place to pan.\n");
   if(TP->query_property("is_panning")) return notify_fail("You are already
panning!\n");
   if(!TO->query_wielded()) return notify_fail("You must be wielding the pan to use it.\n");     
    else{
      tell_object(TP,"%^RESET%^You sit down near the edge of the %^CYAN%^rive"
"r %^RESET%^and fill the pan with %^ORANGE%^dirt %^RESET%^and %^BOLD%^%^BLACK%^rock."
"  %^RESET%^You begin %^BOLD%^%^CYAN%^swirling %^RESET%^the %^BOLD%^%^CYAN%^water"
" %^RESET%^in the pan around, washing away all the lighter %^BOLD%^%^BLACK%^debris."
"%^RESET%^");
      tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->query_cap_name()+" kneels down by the rivers edge and begins to pan for gold.%^RESET%^",TP);
   }
   TP->set_property("is_panning",1);
   TP->set_paralyzed(5,"You are still panning for gold.");
   call_out("while_panning",5,TP);
   TP->use_stamina(10);
   count = 1;
   return 1;
}

void while_panning(string str2){
   count++;
   if(!TO->query_wielded()) {
      tell_object(TP,"You cannot continue panning without the pan.");
      TP->remove_property("is_panning");
   return;
   }
   if(!ETP->is_goldriver()) {
      tell_object(TP,"You cannot pan here.");
      TP->remove_property("is_panning");
   return;
   }
   if(TP->query_unconscious()) {
      tell_object(TP,"You are lucky you didn't drown.");
      TP->remove_property("is_panning");
      return;
   }  
   TP->set_paralyzed(5,"You are busy panning.");
   switch(random(50)){
      case 0..48:
         switch (count) {
            case 1..2: 
               tell_object(TP,"%^BOLD%^%^CYAN%^Water splashes around you from the moving stream.%^RESET%^");
               TP->use_stamina(5);
               call_out("while_panning",5,TP);
            break;
            case 3: 
               tell_object(TP,"The pan is slowly getting empty, but you still see no gold.");
               tell_room(ETP,"The pan "+TPQCN+" is holding is getting empty but there still doesn't seem to be any gold.",TP);
               TP->use_stamina(5);
               call_out("while_panning",5,TP);
            break;
            case 4:
               tell_object(TP,"%^RESET%^%^CYAN%^You're getting wet from all the water.%^RESET%^");
               tell_room(ETP,"%^RESET%^%^CYAN%^"+TPQCN+" is getting soaked from the moving waters of the stream.%^RESET%^",TP);
               TP->use_stamina(5);
               call_out("while_panning",5,TP);
            break;
            case 5:
               tell_object(TP,"Your arms are getting sore and you realize you're going to need some rest after this.");
               tell_room(ETP,""+TPQCN+" is beginning to look tired from constantly swirling the water around.",TP);
               TP->use_stamina(5);
               call_out("end_panning",5,TP);
            break;
         }
      break;
      case 49:
         tell_object(TP,"Darn!  You got overzealous in your panning efforts and have accidentally splashed everything out!");
         tell_room(ETP,""+TPQCN+" starts to swirl the water faster and faster until... Oops!  There is nothing left in the pan!",TP);
         TP->use_stamina(15);
         call_out("stop_panning",5,TP);
     break;
   }
}
int end_panning(object who){
   int total, found, i;
   object ob, where;
   if(!objectp(who)) return 1;
   where = environment(who);
   if(!objectp(where)) return 1;
   tell_object(who,"You see that the pan is nearly empty and you stop to inspect it.");
   tell_room(where,who->query_cap_name()+" stops swirling the water and peers into the pan.",who);
   who->remove_property("is_panning");
   total = where->query_to_find();
   if(!random(2)){ 
      found = random(total)+1;
      where->set_found(found);
      for(i=0;i<found;i++) {
         ob = where->get_found_ob();
         ob->move(where);
      }
      tell_room(where,"%^BOLD%^%^MAGENTA%^You see something solid inside the pan and watch as "+TPQCN+" dumps the contents of the pan onto the ground beside the river.%^RESET%^",TP);
      tell_object(who,"%^BOLD%^%^MAGENTA%^Woo-Hoo!  A chunk of something!  Very carefully you dump the contents of the pan onto the ground beside the river.%^RESET%^");
   }
   else{
      tell_object(who,"%^RESET%^%^ORANGE%^After all your work, there is nothing but flecks of dirt left!%^RESET%^");
   }
   count = 1;
   return 1;
}
int stop_panning(object who){
   object ob, where;
   if(!objectp(who)) return 1;
   where = environment(who);
   if(!objectp(where)) return 1;
   tell_object(who,"%^RESET%^%^ORANGE%^Well, the pan is completely empty now. Maybe you should calm down and try again%^RESET%^.");
   tell_room(where,"%^RESET%^%^ORANGE%^"+who->query_cap_name()+" sighs slightly%^RESET%^.",who);
   who->remove_property("is_panning");
}

