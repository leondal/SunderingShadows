//Cape of the shifting winds
//Written as a reward for a quest I sent high levels HM's on.  Testing for possible Danger item

#include <std.h>
#include <clock.h>

inherit ARMOUR;
int uses;

void create(){
    ::create();
    set_name("%^BOLD%^Cape of the %^CYAN%^S%^BLUE%^h%^RESET%^i%^BLUE%^f%^BOLD%^t%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^g W%^WHITE%^i%^RESET%^%^BLUE%^n%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^");
    set_id(({"armor","cape","wind cape","cape of shifting winds","Cape of shifting winds","Wind cape","Cape of winds","cape of winds","cloak","Cape of the shifting winds","cape of the shifting winds"}));
    set_short("%^BOLD%^Cape of the %^CYAN%^S%^BLUE%^h%^RESET%^i%^BLUE%^f%^BOLD%^t%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^g W%^WHITE%^i%^RESET%^%^BLUE%^n%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^");
    set_obvious_short("%^BOLD%^A %^CYAN%^b%^WHITE%^i%^BLUE%^l%^CYAN%^l%^WHITE%^o%^CYAN%^w%^RESET%^%^CYAN%^i%^BLUE%^n%^BOLD%^g %^CYAN%^c%^WHITE%^a%^CYAN%^p%^BLUE%^e%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This hoodless cape is made from a very %^RESET%^light fabric %^CYAN%^that could"
" be mistaken for the lightest of silks if one did not take a very close look.  On further inspection however,"
" it is quite obvious that this fabric is like nothing you have ever seen before.  The cloth is"
" %^RESET%^semi-tr%^BOLD%^a%^RESET%^nsp%^BOLD%^a%^RESET%^rent %^CYAN%^and so %^RESET%^thin %^CYAN%^and"
" %^RESET%^light %^CYAN%^that the slightest of %^RESET%^b%^BOLD%^ree%^RESET%^z%^BOLD%^e%^RESET%^s %^CYAN%^makes"
" it %^BOLD%^b%^WHITE%^i%^CYAN%^ll%^WHITE%^o%^CYAN%^w %^RESET%^%^CYAN%^out, almost as if it had the urge to take"
" to the %^BOLD%^winds %^RESET%^%^CYAN%^and fly free.  The colors seem to range from a very"
" %^RESET%^clean %^BOLD%^white %^RESET%^%^CYAN%^to %^BOLD%^%^BLUE%^sh%^CYAN%^i%^BLUE%^mm%^CYAN%^e%^BLUE%^ring blue"
"%^RESET%^%^CYAN%^, and the whole thing wreaks with a %^BOLD%^magical aura%^RESET%^%^CYAN%^.  Within the collar"
" of the cape, a %^GREEN%^beautiful message %^CYAN%^has been sewn in a elegant type of %^GREEN%^calligraphy."
"%^RESET%^\n");
   set_lore("%^BOLD%^In the year 323 SG, the %^RESET%^%^GREEN%^elven priestess Alamerielle D'Allyan'ya"
" %^BOLD%^%^WHITE%^of Akadi was tending to her %^RESET%^%^GREEN%^mountain garden %^BOLD%^%^WHITE%^within the"
" %^RESET%^%^GREEN%^forest %^BOLD%^%^WHITE%^when a %^BLACK%^dark cloud %^WHITE%^came to %^BLACK%^shadow"
" %^WHITE%^over the area.  Looking up, %^RESET%^%^GREEN%^Priestess Alamerielle %^BOLD%^%^WHITE%^thought"
" nothing of the %^BLACK%^cloud%^WHITE%^, nor did she think much of it for the next three months."
"  But alas, under the %^BLACK%^clouds cruel darkness %^WHITE%^the %^RESET%^%^GREEN%^crops %^BOLD%^%^WHITE%^did"
" fail, the animals of the %^RESET%^%^GREEN%^mountain forests %^BOLD%^%^WHITE%^began to"
" %^RESET%^%^ORANGE%^starve%^BOLD%^%^WHITE%^, and the %^RESET%^%^GREEN%^People %^BOLD%^%^WHITE%^soon"
" after began to suffer as well.  %^RESET%^%^GREEN%^Alamerielle %^BOLD%^%^WHITE%^was given the task of travelling"
" to the great temple of %^CYAN%^Akadi%^WHITE%^, located high on the %^RESET%^%^BLUE%^mountain peak"
" %^BOLD%^%^WHITE%^that rose above the usual life giving"
" %^RESET%^c%^BOLD%^lo%^RESET%^u%^BOLD%^d%^RESET%^s %^BOLD%^%^WHITE%^of %^CYAN%^rain%^WHITE%^.  "
"%^RESET%^%^GREEN%^Alamerielle %^BOLD%^%^WHITE%^took this task upon herself with much joy and set out towards"
" the %^RESET%^%^BLUE%^mountain peak%^BOLD%^%^WHITE%^.  Within three days"
" time she reached the Goddess's temple and marvelled at the great"
" %^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^b%^WHITE%^l%^RESET%^e %^BOLD%^pillars that stretched towards the"
" %^YELLOW%^heavens%^WHITE%^.  All around her she could see the %^BLACK%^cloud %^WHITE%^that was wreaking havoc"
" upon her %^RESET%^%^GREEN%^people %^BOLD%^%^WHITE%^and for ten days and ten nights did she fast before lighting"
" the %^RESET%^%^ORANGE%^incense sticks %^BOLD%^%^WHITE%^around the temple.  When all were lit and burning"
" happily she knelt before the altar and prayed to the Goddess that she speed the %^CYAN%^winds of change"
" %^WHITE%^to finally blow the %^BLACK%^cloud %^WHITE%^through.  %^RESET%^%^ORANGE%^Weak"
" %^BOLD%^%^WHITE%^but determined,"
" %^RESET%^%^GREEN%^Alamerielle %^BOLD%^%^WHITE%^stayed within the temple for another ten days and nights"
" until finally the %^RESET%^w%^BOLD%^i%^RESET%^n%^BOLD%^d%^RESET%^s %^BOLD%^began to"
" %^RESET%^b%^BOLD%^l%^CYAN%^o%^RESET%^w%^BOLD%^, and the %^BLACK%^mighty cloud of doom %^WHITE%^began to shift."
"  %^RESET%^%^GREEN%^Blessed %^BOLD%^%^WHITE%^so was the %^RESET%^%^GREEN%^daughter %^BOLD%^%^WHITE%^of"
" the %^CYAN%^Wind Goddess %^WHITE%^that a %^CYAN%^gift %^WHITE%^blew in on the"
" travelling %^CYAN%^breeze%^WHITE%^.  A %^RESET%^light, t%^BOLD%^ra%^RESET%^nspar%^BOLD%^e%^RESET%^nt"
" c%^BOLD%^a%^RESET%^pe %^BOLD%^found its way to the temple and fell at the feet of the beloved"
" %^RESET%^%^GREEN%^Elven Priestess%^BOLD%^%^WHITE%^.  Knowing then that her prayers had been answered"
" the %^RESET%^%^GREEN%^daughter %^BOLD%^%^WHITE%^of the %^CYAN%^Winds %^WHITE%^wrapped the"
" %^RESET%^c%^BOLD%^a%^RESET%^pe %^BOLD%^about herself and began"
" the journey home, glad to see the %^BLACK%^darkened cloud %^WHITE%^finally blowing past.  Unknown to the"
" %^RESET%^%^GREEN%^beloved priestess %^BOLD%^%^WHITE%^though, the %^BLACK%^cloud"
" %^WHITE%^was an %^BLACK%^omen %^WHITE%^of the things to come.  "
"For the %^BLACK%^dark-elves %^WHITE%^of the %^BLACK%^Underdark %^WHITE%^had hatched a plan, and for several"
" hundred years did they plan this attack on their fair-skinned cousins.  The %^BLACK%^cloud of doom"
" %^WHITE%^did shift, but the %^BLACK%^dark-elf magic %^WHITE%^was persistant.  Another"
" %^BLACK%^cloud %^WHITE%^soon followed on the tail of the first, and settled like a %^BLACK%^heavy blanket"
" %^WHITE%^over the mountain community.  Soon all the %^RESET%^%^GREEN%^elves %^BOLD%^%^WHITE%^of"
" %^RESET%^%^GREEN%^L'Yillianye %^BOLD%^%^WHITE%^were %^RESET%^%^ORANGE%^weakened %^BOLD%^%^WHITE%^and"
" %^RESET%^%^RED%^starving%^BOLD%^%^WHITE%^, and then the %^BLACK%^dark-elves %^WHITE%^did move in."
" Under the cover of the %^BLACK%^night time sky %^WHITE%^created by their %^BLACK%^foul magics %^WHITE%^did"
" they move, and like a %^BLACK%^plague %^WHITE%^did they creep into every house and home to steal the"
" %^CYAN%^wind-loving %^WHITE%^families from their %^RESET%^%^MAGENTA%^reverie%^BOLD%^%^WHITE%^."
"  Few know the story of what happened next, but all know that none of the %^RESET%^%^GREEN%^elves"
" %^BOLD%^%^WHITE%^of %^RESET%^%^GREEN%^L'Yillianye %^BOLD%^%^WHITE%^were ever seen again.%^RESET%^");
   set_read("%^BOLD%^May the winds of Akadi always keep you %^CYAN%^free.%^RESET%^");
   set_weight(3);
   set_size(-1);
   set_type("clothing");
   set_limbs(({"neck",}));
   set_ac(0);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("reflex",2);
   set_value(0);
   set_wear((:TO,"wear_it":));
   uses = 2;
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_it(string str){
    tell_object(ETO,"%^BOLD%^The cape comes to life and begins to shift and blow in the winds as you wrap it around your shoulders.%^RESET%^");
    tell_room(environment(ETO),"%^BOLD%^The cape comes to life and begins to shift and blow in the winds as "+ETO->query_cap_name()+" wraps it around "+ETO->query_possessive()+" shoulders.%^RESET%^",ETO);

return 1;
}
void init() {
    ::init();
    add_action("free","free");
}
void free(){
   if(!objectp(ETO)){
   return; 
   }
   if((string)ETO->query_deity()=="grumbar"){
	tell_object(TP,"%^BOLD%^%^CYAN%^You follow the enemy of Akadi child, this cape is of no use to you.%^RESET%^");
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^BOLD%^You must be wearing the cape to call upon its blessings.%^RESET%^");
   return 1; 
   }
   if(!(string)ETO->query_paralyzed()){
	tell_object(TP,"%^BOLD%^%^CYAN%^A softly soothing voice blows in on the winds: %^WHITE%^Ah my child, you are already free....%^RESET%^");
   return 1; 
   }
   if(uses<1){
      if (time()-DAY < (int)ETO->query_property("freecape")) {
	   tell_object(TP,"%^BOLD%^You have already called upon the magic of the cape too many times this day.%^RESET%^");
   return 1;
      }
      else{
         uses = 2;
      }
   return ;
   }  
   else{
      tell_object(TP,"%^BOLD%^The winds pick up and causes the cape to billow around you as you call upon its magic.  Within moments you can feel the winds of Akadi blessing you with the freedom she loves so much.%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+"'s cape begins to billow in a wind that seems to have come from nowhere!%^RESET%^",ETO);
     ETO->set_paralyzed(0);
     uses --;
     ETO->set_property("freecape",time());
   }
}