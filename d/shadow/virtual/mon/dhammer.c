//dhammer.c - updated by Circe with new desc, lore, etc. 6/12/04
//Changed + to every 7 instead of 9, for kicks - Octothorpe 3/22/10
#include <std.h>

inherit "/d/common/obj/weapon/dwarvenwaraxe";
int max;

void create(){
   ::create();

   set_name("dwarven hammer");
   set_obvious_short("an aged dwarven waraxe");
   set_short("%^BOLD%^%^BLUE%^Dwarven Legacy%^RESET%^");
   set_id(({"axe","dwarven axe","dwarven waraxe","waraxe","legacy","dwarven legacy","Dwarven Legacy","Legacy"}));
   set_long("%^BOLD%^This fantastic axe has double head made of thick, aged steel that widens on both sides and tapers towards the middle.  At the middle, where the head attaches to a thick %^RESET%^mithril handle%^BOLD%^, dwarven runes have been carved into a small %^RESET%^mithril plate%^BOLD%^.  The %^RESET%^mithril handle %^BOLD%^widens near the base and has been carved with meticulous crosshatching filled in with some %^BLACK%^darkening agent %^WHITE%^to make its presence even more pronounced.  The waraxe has an ancient appearance, with minute cracks and crevices in the steel though it is clearly still sound and has been well-tended.");
   set_lore("This hammer is known as Legacy among the dwarves.  "+
      "It is said to contain some of the spirit of each dwarf "+
      "who has carried it.  These spirits help aid the dwarven "+
      "warrior in battle, guiding him and reminding him of his "+
      "roots.  There are a few such hammers in existence, each "+
      "with its own particular history and lineage.  A dwarf "+
      "blessed to carry such a hammer treasures it above all "+
      "else and considers losing it his greatest failure.  No "+
      "one outside the dwarven community is sure exactly how "+
      "these hammers came into existence - and the ones inside "+
      "share that knowledge with no one, not even other dwarves.");
   set_property("lore difficulty",12);
   set_value(400);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_me":));
   set_hit((:TO,"hit_em":));
}

int hit_em(object targ){
   if(!objectp(targ)) return 5;
   if(!random(10)){
      switch(random(4)){
         case 0..1:
            tell_room(environment(targ),"%^BOLD%^"+ETOQCN+" smashes "+
               ""+targ->QCN+" deeply with the axe over the "+
               "head.",({targ,ETO}));
            tell_object(targ,"%^BOLD%^"+ETOQCN+" smashes you over "+
               "the head.");
            tell_object(ETO,"%^BOLD%^You smash "+targ->QCN+" over "+
               "the head as the axe sings a rousing battle tune!");
            set_property("magic",1);
            targ->do_damage("torso",random(10));
            set_property("magic",-1);
            return random(6);
            break;
         case 2:
            if((string)targ->query_race() == "kobold" ||
               (string)targ->query_race() == "orc" ||
               (string)targ->query_race() == "drow" ||
               (string)targ->query_race() == "half-orc" ||
               (string)targ->query_race() == "goblin"){
                  tell_room(environment(targ),"%^BOLD%^%^BLUE%^"+ETOQCN+" "+
                     "growls fiercly and swings the axe wide, smacking "+
                     ""+targ->QCN+" across the face!",({targ,ETO}));
                  tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" growls "+
                     "fiercly as "+ETO->QS+" smacks you across the "+
                     "face with an axe!");
                  tell_object(ETO,"%^BOLD%^%^RED%^The hammer tells "+
                     "you%^RESET%^: There's one of them filthy "+
                     ""+targ->query_race()+"s now!!  Kill it!\n"+
                     "%^BOLD%^%^BLUE%^You swing the axe wide, "+
                     "striking "+targ->QCN+" across the face!");
                  set_property("magic",1);
                  targ->do_damage("torso",random(10)+8);
                 set_property("magic",-1);
                  return random(6);
            }else{
                  tell_room(environment(targ),"%^BOLD%^%^BLUE%^"+ETOQCN+" "+
                     "growls fiercly and swings the axe wide, smacking "+
                     ""+targ->QCN+" across the face!",({targ,ETO}));
                  tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" growls "+
                     "fiercly as "+ETO->QS+" smacks you across the "+
                     "face with an axe!");
                  tell_object(ETO,"%^BOLD%^%^BLUE%^You swing the axe wide, "+
                     "striking "+targ->QCN+" across the face!");
//                 set_property("magic",1);
                  targ->do_damage("torso",random(10));
                  return random(6);
            }
            break;
         case 3:
            tell_room(environment(targ),"%^RED%^"+ETOQCN+" brings the "+
               "axe straight up, catching "+targ->QCN+" square in "+
               "the chin!",({targ,ETO}));
            tell_object(targ,"%^RED%^You see %^BOLD%^%^WHITE%^stars "+
               "%^RESET%^%^RED%^all around you as "+ETOQCN+" brings "+
               ""+ETO->QP+" axe up into your chin!");
            tell_object(ETO,"%^BOLD%^%^RED%^The axe tells you"+
               "%^RESET%^: Ya need ta stun 'em - like this!\n"+
               "%^RED%^You swing with wild strength, bringing "+
               "the axe straight up into "+targ->QCN+"'s chin!");
            set_property("magic",1);
            targ->do_damage("torso",random(5)+3);
            targ->set_paralyzed(random(3)+1,"You still see stars before you eyes!");
            set_property("magic",-1);
            return random(6);
            break;
      }
   }
   return 0;
}

int wield_me(){
   int myflag, i;
   object *mywielded;
   string RACE;
   RACE = ETO->query_race();
   if(RACE != "dwarf"){
      tell_object(ETO,"%^BOLD%^%^RED%^The axe tells you%^RESET%^: "+
         "Ya think I'll be wielded by a scurvy "+RACE+"??\nThe hammer "+
         "laughs at you and refuses your hands.");
      return 0;
   }
   if(sizeof(ETO->query_wielded())) {
     myflag = 0;
     mywielded = ETO->query_wielded();
     for(i = 0; i < sizeof(mywielded); i ++) {
       if(base_name(mywielded[i]) == "/d/shadow/virtual/mon/dhammer") myflag = 1;
     }
     if(myflag) {
       tell_object(ETO,"%^BOLD%^%^BLACK%^A rumble runs down your arm as you attempt to take up both axes at once.  As "
"your hand takes grip around the handle, it crumbles into dust!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" attempts to take up two axes at once, but the second hammer "
"simply crumbles into dust!%^RESET%^",ETO);
       TO->remove();
       return 0;
     }
   }

   if((int)ETO->query_highest_level() > 5){
      remove_property("enchantment");
// making it grow a little slower *Styx*  2/20/05
      max = (int)TP->query_lowest_level()/7;
      if(max > 5) max = 5;
      set_property("enchantment", max);
      while(query_property("enchantment") < 0){
	   remove_property("enchantment");
         set_property("enchantment", max);
      }
   tell_object(ETO,"%^BOLD%^%^RED%^The waraxe tells you%^RESET%^: "+
      "Let's find some orc skulls ta cleave!");
   tell_room(EETO,""+ETOQCN+" hefts the waraxe with a wild grin.",ETO);
   return 1;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^The waraxe tells you%^RESET%^: "+
      "I don't think ya can handle the likes of me just yet!");
   return 0;
}

int unwield_me(){
   tell_object(ETO,"%^BOLD%^%^RED%^The waraxe tells you%^RESET%^: "+
      "What are ya doin'?!  We were just startin' ta have fun!");
   remove_property("enchantment");
   return 1;
}

int save_me(string file){
   ::save_me(file);
   return 1;
}
