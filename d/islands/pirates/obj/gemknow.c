#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("Gem of Knowledge");
   set_id(({"gem","gem of knowledge","amber stone","amber gem"}));
   set_short("%^RESET%^%^ORANGE%^Gem of Knowledge%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^misty amber gem%^RESET%^");
   set_long("This %^ORANGE%^amber stone%^RESET%^ has some sort of mist floating inside.  As you peer into "
"its depths, you have the sudden urge to %^BOLD%^<concentrate>%^RESET%^ on the gem.");
   set_weight(1);
   set_value(4000);
   set_lore("%^WHITE%^%^BOLD%^Little items such as this are commonly crafted by mages of lesser skill.  "
"They're often nothing more than nick-nacks, imbued with some fairly useless enchantment, and created for "
"little more than amusement.  Some are quite sought after by magi, however, for use in their experiments to "
"unlock the secrets of other wizards' art.%^RESET%^\n");
   set_property("lore difficulty",6);
}

void init(){
   ::init();
   add_action("info","concentrate");
   add_action("answer","ask");
}

void info(){
   tell_object(TP,"%^MAGENTA%^The gem speaks to your mind%^RESET%^: Merely ask me the outcome of the next "
"situation you shall face, and I will tell you the answer.  I SEE AND KNOW ALL.");
   return 1;
}

void answer(string str){
   int x;

   if (!str) return notify_fail("Ask what?\n");
   if (str !="gem") return notify_fail("Oh, you're sure to get an answer from that.\n");

   tell_object(TP,"%^BOLD%^The mist in the gem swirls rapidly!%^RESET%^\n%^MAGENTA%^The gem speaks to your "
"mind%^RESET%^: Let me look into your future... Yes I see something... Ahhh.");
   tell_object(TP,"%^MAGENTA%^It says:%^RESET%^Yes yes... %^BOLD%^YES!!%^RESET%^\n");

   x = roll_dice(1,15);
   if (x==1) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: Outlook not so good.");
   if (x==2) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: When pigs fly.");
   if (x==3) tell_object(TP,"The gem just laughs at you.");
   if (x==4) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: You might have a chance.");
   if (x==5) tell_object(TP,"The gem snickers.");
   if (x==6) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: Try again later.");
   if (x==7) tell_object(TP,"The gem just laughs at you.");
   if (x==8) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: Eww, that looks messy.  Good luck, could you "
"kindly drop me off in a safe place?");
   if (x==9) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: This could be entertaining.");
   if (x==10) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: YES, you will win!");
   if (x==11) tell_object(TP,"The gem giggles.");
   if (x==12) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: That's strange....");
   if (x==13) tell_object(TP,"The gem cackles demonically.");
   if (x==14) tell_object(TP,"%^MAGENTA%^It says%^RESET%^: Not in a million years.");
   if (x==15) tell_object(TP,"The gem mutters.");
   return 1;
}
