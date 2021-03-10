#include <std.h>
#include <daemons.h>
/* trainers include -
  /d/laerad/mon/estal
  /d/islands/pirates/mon/shawologon.c (halfling weapon shop guy, up to 10th)
  /d/dagger/Daggerdale/shops/npcs/selena Vethor's guild recept. (up to 10th)
  d/tharis/monsters/lathis - Tharis tea shop (10th)

*/

inherit DAEMON;

int cmd_struggle(string what) {
   int str, dex, dampct, loosen, bindings, prof, delay, saves, blindwas, formu;
   string see_struggle;
   if (!TP->query_bound()) {
      return notify_fail("You aren't bound so you don't need to struggle.\n");
      return 0;
   }
   bindings = (int)TP->query_bound();
   str = (int)TP->query_stats("strength");
   dex = (int)TP->query_stats("dexterity");
   prof = TP->query_skill("rope use");
   dampct = 100 - ( ((int)TP->query_hp()*100) /(int)TP->query_max_hp() );
// loosen was tested with randoms str/3, dex/2, & 4, changed 4 to prof
//   loosen =  random(str/3) + random(dex/2) + (prof*2) + (random(prof)*3) ;
    loosen = (10 + (prof *40));
//   tell_object(find_player("styx"),"Bindings = "+bindings+", damagepct = "
//       +dampct+", and loosen = "+loosen+".\n");
/*   if(prof > 20) {
      delay = random(5);
    } else {
      delay = 20 - random(prof);
   }*/
   delay = 20 - (prof/2);
   if(delay < 5) delay = 5;
   if(!TP->query_time_delay("escape",delay) ) {
      notify_fail("You need more time to figure out what may actually "
            "help loosen the bonds.\n");
      return 0;
   }
    formu = (random(8)*3) + ( ((loosen*4)+(dampct/5))/(prof+1) );
    //added by saide to make sure stamina use does not give
    //stamina
    if(formu < 1) {
        formu = 1 + random(3);
    }
    TP->use_stamina(formu);
/*   if(TP->has_nwp("escape"))
      NWP_D->perform_nwp(TP, "escape");*/
   TP->set_time_delay("escape");
   if(loosen > bindings) {
        TP->set_bound(0);
        write("%^BOLD%^%^GREEN%^You have managed to escape your bonds!");
        return 1;
   }
   if(what == "gag") {
      if(!TP->query_gagged()) {
        notify_fail("You aren't gagged, why bother?\n");
        return 0;
      }
      if(random(4))
            tell_room(ETP,TPQCN+" seems to be struggling against the gag.");
      switch(random(100)-prof) {

        case 0:
              TP->set_gagged(0);
              write("Somehow you manage to slip free of the gag!");
              if(random(4)) tell_room(ETP, "You notice "+TPQCN+" slip "
                          "free of "+TP->query_possessive()+" gag.");
              break;
        case 1..10 :
           write("You fight against the gag but only manage to hurt yourself!");
           TP->cause_typed_damage(TP, "head", random(3), "untyped");
           break;
        default : break;
      }
   }
   if(what == "blindfold") {
      if(!TP->query_blindfolded()) {
         notify_fail("You aren't blindfolded, why bother?\n");
         return 0;
      }
      if(random(4))
          tell_room(ETP,TPQCN+" seems to be struggling against the blindfold.", TP);
      switch(random(100)-prof) {

        case 0:
              TP->set_blindfolded(0);
              write("Somehow you manage to slip the blindfold off!");
              if(random(4)) tell_room(ETP, "You notice "+TPQCN+" slip free "
                          "of "+TP->query_possessive()+" blindfold.", TP);
              break;
        case 1..5 :
// adapted from Garrett's original blindfold object
	     blindwas = TP->query_blindfolded();
             TP->set_blindfolded(0);
             if (TP->query_blind())  {
                 tell_object(TP,"You feel the blindfold slip but you're "
                     "blind underneath it!");
             } else {
                 tell_object(TP,"%^BOLD%^The blindfold slips and allows you to "
                     "glance around!");
                 message("my_environment",ETP->query_long(), ({TP}));
                 TP->set_blindfolded(blindwas);
             }
           if(random(3))  TP->cause_typed_damage(TP, "head", random(3), "untyped");
           break;
        default : break;
      }
   }

   see_struggle = "You notice "+TPQCN+" struggling against "
        +TP->query_possessive()+" bonds.";
   TP->set_bound(bindings - loosen);
   switch(random(50)+prof) {
       case 0:  write("You pull a muscle trying to loosen your bonds.");
                if(random(3))
                  tell_room(ETP,"You notice "+TPQCN+" wince in pain.", TP);
                TP->cause_typed_damage(TP, "torso", random(4), "untyped");
                break;
       case 1:  write("The ropes %^RED%^cut into your wrists %^RESET%^as you "
                      "struggle.");
                if(random(3))
                  tell_room(ETP,"You notice "+TPQCN+"'s %^RED%^wrist bleeding"
                      "%^RESET%^ as "+TP->query_subjective()+" struggles.", TP);
                TP->cause_typed_damage(TP, "right arm", random(5), "untyped");
		break;
       case 2:  write("The ropes cause %^BOLD%^blisters %^RESET%^as you struggle.");
                if(random(2))
                  tell_room(ETP,TPQCN+" seems to be struggling against the "
                            "ropes.", TP);
                TP->cause_typed_damage(TP, "left arm", random(3), "untyped");
		break;
       case 3:  write("%^ORANGE%^The ropes tighten around your neck and choke "
                      "you as you struggle to free yourself.");
                if(random(2))
                  tell_room(ETP,TPQCN+" coughs and seems to be choking.", TP);
                TP->cause_typed_damage(TP, "neck", random(5)+2, "untyped");
		break;
       case 4:  write("The ropes chafe against your skin as you struggle.  "
                      "Some of the blisters break open and begin to bleed.");
                if(random(3))
                  tell_room(ETP,TPQCN+" winces as "+TP->query_subjective()+
                      " struggles against the ropes.", TP);
                TP->cause_typed_damage(TP, "torso", random(4), "untyped");
		break;
       case 10:  write("You pray your captors don't return or notice before "
                      "you manage to break free.");
                if(random(3))  tell_room(ETP,see_struggle,TP);
		break;
       case 15:  write("This is so strenuous and painful you have to be "
                      "thinking about giving up.");
                if(random(3))  tell_room(ETP,see_struggle,TP);
		break;
       case 20: write("You struggle against your bonds and may have loosened "
                      "them a little.");
                if(random(3))  tell_room(ETP,see_struggle,TP);
                break;
       case 21..49 : if(random(10)-(prof/3))  tell_room(ETP,see_struggle,TP);
                     break;
       default: if(!random(3)) tell_object(TP,"You struggle but wonder if "
                     "your efforts are futile.");
                break;
   }
   if(!random(20 - prof/2) )
      write("You can definitely tell the bonds are loosening.");

   if(TP->query_condition_percent() < 30)
      tell_object(TP,"You're becoming exhausted from the struggling.");

   if(TP->query_condition_percent() < 1)
      tell_room(ETP,TPQCN+" has passed out from exhaustion.", TP);
   if(TP->query_hp() < 1)
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" falls unconscious from "
          +TP->query_possessive()+" wounds.", TP);
   return 1;
}

int help(){
   write(
"
%^CYAN%^NAME%^RESET%^

struggle - get out of binding

%^CYAN%^SYNOPSIS%^RESET%^

struggle
struggle gag | blindfold

%^CYAN%^DESCRIPTION%^RESET%^

This gives you the chance to loosen bonds and free yourself. It takes time and uses stamina. If you are already injured it may take more of what little strength and energy you have left. Of course there is also a chance of your struggling being noticed by your captor if they are around.

The 'rope use' skill will improve your chances and speed of escaping, lower the chances of being detected.

%^CYAN%^SEE ALSO%^RESET%^

rope use, skills, bind, unbind, gag, ungag, strip, pkilling, blindfold, unblindfold
"
      );
   return 1;
}
