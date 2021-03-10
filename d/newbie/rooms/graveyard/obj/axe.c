#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";

int polished;

void create() {
   ::create();
   set_name("battleaxe");
   set_short("%^BOLD%^%^WHITE%^Rashan\'s Cleaver%^RESET%^");
   set_obvious_short("%^RESET%^%^WHITE%^an old grimy axe%^RESET%^");
   set_id(({"axe","grimy axe","battleaxe","battle axe","rashans cleaver","rashan's cleaver","steel axe","cleaver"}));
   set_long("This is a quite sturdy battleaxe, crafted of what appears to"
           +" be solid %^BOLD%^%^WHITE%^steel%^RESET%^.  It looks very"
           +" old, covered in %^ORANGE%^dirt%^RESET%^ and %^BOLD%^"
           +"%^BLACK%^grime,%^RESET%^ but seems to be quite servicable,"
           +" with a blade that is still honed to a %^YELLOW%^sharp"
           +" %^RESET%^edge.  Its wooden handle is tightly wrapped in"
           +" aged %^ORANGE%^leather%^RESET%^, serving as quite a"
           +" comfortable grip to the light weapon.  Upon one face of its"
           +" single blade is etched some sort of %^MAGENTA%^ornate"
           +" %^RESET%^insignia or image, though it is difficult to see"
           +" just what it depicts under all the dirt.  It could really"
           +" do with a thorough %^BOLD%^%^BLUE%^clean%^RESET%^.\n");
   set_weight(5);
   set_value(4);
   set_lore("%^WHITE%^%^BOLD%^This battleaxe is said to have once belonged to Rashan, a local hero of the town "
"of Offestry.  He was said to be fond of such axes above all others - this one was a gift for his efforts from "
"the grateful people of his hometown.  Slain in an orc raid upon the city, he was buried in a tomb entirely "
"his own, in honor of his contributions to the wellbeing of Offestry.%^RESET%^\n");
   set_property("lore difficulty",3);
   polished = 0;
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hit_fun":));
}

void init() {
   ::init();
   add_action("polish_fun","clean");
}

int wieldme(){
   if(!polished && !random(3)) { tell_object(ETO,"Some %^ORANGE%^dirt %^RESET%^crumbles off the axe's blade as "
"you wield it.  It could really use a good %^BOLD%^%^BLUE%^clean%^RESET%^."); }
   return 1;
}

int polish_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!str) {
     notify_fail("What do you want to clean?\n");
     return 0;
   }
   if(str != "axe" && str != "battleaxe" && str != "battle axe" && str != "grimy axe") {
     notify_fail("You can't polish that.\n");
     return 0;
   }
   if((int)TO->query_wielded()) {
     notify_fail("That might be a bit difficult while you're wielding it.\n");
     return 0;
   }
   if(sizeof(TP->query_attackers()) > 0) {
     notify_fail("That might be a bit difficult while you're fighting.\n");
     return 0;
   }
   if(polished) {
     notify_fail("The axe has already been cleaned.\n");
     return 0;
   }
   tell_object(TP,"You spend a little time cleaning the dirt and grime from the axe.");
   tell_room(ETP,""+TP->QCN+" spends a little time cleaning the dirt and grime from the axe.",TP);
   TO->set_obvious_short("%^BOLD%^%^WHITE%^a steel battleaxe%^RESET%^");
   TO->set_long("This is a quite sturdy battleaxe, crafted of what"
               +" appears to be solid %^BOLD%^%^WHITE%^steel%^RESET%^."
               +"  It looks to be rather old, but is still in very good"
               +" shape, with its blade honed to a %^YELLOW%^sharp"
               +" %^RESET%^edge.  Its wooden handle is tightly wrapped in"
               +" aged %^ORANGE%^leather%^RESET%^, serving as quite a"
               +" comfortable grip to the light weapon.  Upon one face of"
               +" its single polished blade is etched an ornate image,"
               +" depicting a lithe dragon with its"
               +" %^BOLD%^%^WHITE%^claws %^RESET%^outstretched, ready to"
               +" pounce upon a foe.\n");
   set_value(15);
   polished = 1;
   return 1;
}

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(4)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The axe's sharp edge cleaves deeply into "+targ->QCN+"!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s axe cleaves deeply into your skin!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" sharp axe cleaves deeply into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      return 1;
   }
}
