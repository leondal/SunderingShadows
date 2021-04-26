//updated by Circe 8/29/04 with new desc, etc, provided by Nightfall
#include <std.h>
#include "/d/common/common.h"
inherit CWEAP"two_hand_scythe";

object owner;

void init() {
    ::init();
    if(interactive(ETO) && !owner) { owner = ETO->query_name(); }
}

void create() {
    ::create();
    set_name("scythe");
    set_id(({"scythe","scythe of death","rune scythe","rune-inscribed scythe"}));
    set_short("%^BOLD%^%^BLACK%^Sc%^RESET%^%^GREEN%^y%^BOLD%^%^BLACK%^the "+
       "of De%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^th%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^Shimmering %^RESET%^%^GREEN%^r"+
       "%^BOLD%^u%^RESET%^%^GREEN%^n%^BLACK%^%^BOLD%^e inscr%^GREEN%^i"+
       "%^BLACK%^bed scythe%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Forged of a shimmering spectral metal, "+
       "this sleekly curved weapon is truly of magnificent craft.  The "+
       "shadowy transparancy serves only to more fully accentuate the "+
       "%^BOLD%^%^GREEN%^gl%^RESET%^%^GREEN%^ow%^BOLD%^ing %^BLUE%^arcane "+
       "symbols %^BLACK%^inscribed along its surface, each one c%^GREEN%^r"+
       "%^RESET%^%^GREEN%^a%^BOLD%^c%^BLACK%^kling with its own %^RESET%^"+
       "%^GREEN%^po%^BOLD%^tent ene%^RESET%^%^GREEN%^rgy%^BOLD%^%^BLACK%^"+
       ".  The haft has been fashioned to resemble a humanoid spinal "+
       "column, each vertabra mounted with w%^RESET%^%^RED%^i%^BOLD%^"+
       "%^BLACK%^ck%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d b%^RESET%^%^RED%^a"+
       "%^BOLD%^%^BLACK%^rbs that run the length of the column before "+
       "tapering off at a %^RESET%^%^RED%^serrated blade%^BOLD%^%^BLACK%^"+
       "-like tail.  The haft is topped with an open-mouthed %^BOLD%^"+
       "%^WHITE%^skull%^BLACK%^, its empty sockets filled with a "+
       "%^GREEN%^fiendish green fire%^BLACK%^ and its fanged maw "+
       "spewing forth a %^RESET%^flickering ghostly blade%^BLACK%^"+
       "%^BOLD%^. The great curving blade emits an unholy %^BLUE%^ch"+
       "%^CYAN%^i%^BLUE%^ll %^BLACK%^and as you watch you see faces "+
       "appear along its surface, each twisting as if in terrible "+
       "agony before fading back into the blade as silently as they "+
       "appeared.%^RESET%^"
    );
    set_lore("Taken from the creatures known as Reavers, these "+
       "scythes are not of this realm.  They are crafted by the "+
       "dead and imbued with the magical power of that realm.  "+
       "Only those of the most corrupted souls would dare wield "+
       "such a weapon, and - indeed - it is said that the weapon "+
       "itself refuses all others.");
    set_property("enchantment",3+roll_dice(1,2));
    set_wc(3,4);
    set_value(4000);
//    set_prof_type("death scythe"); removed this, to let it inherit from the CWEAP -Ares
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"extra_hit":));
}
int extra_wield() 
{
    int align;

    if(!userp(ETO)) { return 1; }

    if((int)ETO->query_level() < 25) {    
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^GREEN%^arcane symbols "+
         "%^BLACK%^flare to life and burn into your vision!");
	tell_room(EETO,"%^BOLD%^%^BLACK%^The %^GREEN%^arcane symbols "+
         "%^BLACK%^flare to life as "+ETOQCN+" tries to wield it!\n"+
         "%^GREEN%^It disappears!",ETO);
	ETO->do_damage("torso",random(25)+25);
	ETO->add_attacker(TO);
	ETO->continue_attack();
	ETO->remove_attacker(TO);
      ETO->set_blind(1);
	TO->remove();
	return 0;
    }
    /*
    if(interactive(TP) && (string)TP->query_name() != owner){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You hear a crackling sound in "+
         "the air as the %^GREEN%^symbols %^BLACK%^flare to life "+
         "and the scythe vanishes!");
	tell_room(EETO,"%^BOLD%^%^BLACK%^You hear a crackling sound in "+
         "the air as the %^GREEN%^symbols %^BLACK%^flare to life "+
         "and the scythe vanishes when "+ETOQCN+" tries to wield it!",ETO);
	TO->remove();
	return 0;
    }
    */
    align = (int)ETO->query_alignment();
    if(align == 1 || align == 4 || align == 7) {
	tell_object(ETO,"The scythe refuses your hand!\n");
	return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^A soft whisper fills your mind: "+
       "%^RED%^'%^BOLD%^%^BLACK%^Come, let us feed and grow strong "+
       "together...%^RESET%^%^RED%^'%^RESET%^");
    tell_object(ETO,"%^BOLD%^%^BLACK%^The shimmering haft of the weapon "+
       "ripples in your grasp, and you feel a new hunger as its %^GREEN%^"+
       "e%^BLACK%^n%^GREEN%^e%^BLACK%^r%^RESET%^%^GREEN%^g%^BOLD%^y "+
       "%^BLACK%^washes over you.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^Ripples spread along the length of "+
       "the weapon as its %^GREEN%^e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^"+
       "%^GREEN%^rg%^BOLD%^y %^BLACK%^b%^GREEN%^u%^BLACK%^rsts "+
       "forth and %^GREEN%^a%^BLACK%^rcs along "+ETOQCN+"'s body.",ETO);
    ETO->set_property("evil item",1);
    return 1;
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}

int extra_hit(object vic) {
    int dmg;
    object obj;
    string wielder = ETO;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 0;
    if(!random(4)){
       switch(random(80)){
          case 0..58:   tell_room(EETO,"%^BOLD%^%^BLACK%^A %^RESET%^"+
                           "so%^BOLD%^%^BLACK%^u%^RESET%^l %^BOLD%^%^CYAN%^"+
                           "c%^BLUE%^h%^CYAN%^i%^BLUE%^ll%^CYAN%^i%^BLUE%^n"+
                           "%^CYAN%^g shri%^BLUE%^e%^CYAN%^k %^BLACK%^"+
                           "erupts from the blade as it %^RESET%^%^RED%^"+
                           "scythes%^BOLD%^%^BLACK%^ through "+vic->QCN+"!"+
                           "%^RESET%^",vic);
                        tell_object(vic,"%^BOLD%^%^BLACK%^As the blade "+
                           "%^RESET%^%^RED%^scythes%^BOLD%^%^BLACK%^ into "+
                           "you, a %^CYAN%^c%^BLUE%^h%^CYAN%^i%^BLUE%^ll"+
                           "%^CYAN%^i%^BLUE%^n%^CYAN%^g shri%^BLUE%^e"+
                           "%^CYAN%^k  %^BOLD%^%^BLACK%^resonates through "+
                           "your body, turning your %^RESET%^%^RED%^blood "+
                           "%^BOLD%^%^BLUE%^c%^CYAN%^o%^BLUE%^ld%^BLACK%^!%^RESET%^");
                        dmg = roll_dice(3, 4);
                        ETO->set_property("magic",1);
                        //vic->do_damage(vic->return_target_limb(),dmg);
                        ETO->set_property("magic",-1);
                        break;
          case 59..65:  tell_room(EETO,"%^MAGENTA%^With surprising speed "+
                           ""+ETOQCN+" catches "+vic->QCN+"'s leg with "+
                           "the blade and sends "+vic->QO+" sprawling with "+
                           "a vicious kick to the chest!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^MAGENTA%^Deftly hooking the "+
                           "curving blade behind "+vic->QCN+"'s knee, you "+
                           "spin quickly to launch a kick to the chest "+
                           "that sends "+vic->QO+" sprawling!%^RESET%^");
                        tell_object(vic,"%^MAGENTA%^"+ETOQCN+" suddenly "+
                           "hooks your leg with "+ETO->QP+" curving "+
                           "blade and spins, sending you tumbling over "+
                           "with a solid kick to the chest!%^RESET%^");
                        vic->set_tripped(1,"You are trying to stand!");
                        break;
          case 66..71:  tell_room(EETO,"%^RED%^Spinning quickly "+
                           ""+ETOQCN+" sends "+vic->QCN+" stumbling "+
                           "with a vicious slash, then quickly slams "+
                           "the serrated tail down into "+vic->QP+" "+
                           "%^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, trapping "+
                           "it!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^RED%^With a vicious strike "+
                           "you send "+vic->QCN+" stumbling back, then "+
                           "quickly slam the serrated tail down into "+
                           ""+vic->QP+" %^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, "+
                           "trapping it!%^RESET%^");
                        tell_object(vic,"%^RED%^With a vicious strike "+
                           ""+ETOQCN+" sends you stumbling back, then "+
                           "quickly slams the serrated tail down into "+
                           "your %^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, "+
                           "trapping it!%^RESET%^");
                        tell_room(EETO,"%^BOLD%^%^BLACK%^The shadow "+
                           "rises up before "+ETOQCN+"!",ETO);
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The shadow "+
                           "rises up before you!");
                        obj = new("/d/dagger/marsh/tower/mon/scythe_shadow");
	                  obj->move(EETO);
	                  obj->force_me("protect "+wielder->query_name());
	                  wielder->add_follower(obj);
                        break;
          case 72..76:  tell_room(EETO,"%^BLUE%^"+ETOQCN+" spins, "+
                           "sweeping "+ETO->QP+" %^RED%^scythe%^BLUE%^ "+
                           "through "+vic->QCN+" before suddenly "+
                           "reversing "+ETO->QP+" momentum and driving "+
                           "the weapon's barbed tail deep into "+
                           ""+vic->QP+" %^BOLD%^%^RED%^gut%^RESET%^"+
                           "%^BLUE%^!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^BLUE%^Whirling with your "+
                           "blade, you slash your %^RED%^scythe%^BLUE%^ "+
                           "through "+vic->QCN+", you suddenly reverse "+
                           "your momentum, driving the weapon's barbed "+
                           "tail deep into "+vic->QP+" %^BOLD%^%^RED%^gut"+
                           "%^RESET%^%^BLUE%^!%^RESET%^");
                        tell_object(vic,"%^BLUE%^"+ETOQCN+" spins, "+
                           "sweeping "+ETO->QP+" %^RED%^scythe%^BLUE%^ "+
                           "through you before suddenly reversing "+
                           ""+ETO->QP+" momentum and driving the "+
                           "weapon's barbed tail deep into your "+
                           "%^BOLD%^%^RED%^gut%^RESET%^%^BLUE%^!%^RESET%^");
                        dmg = roll_dice(3, 6);
                        ETO->set_property("magic",1);
                        //vic->do_damage(vic->return_target_limb(),dmg);
                        ETO->set_property("magic",-1);
                        break;
          case 77..79:  if(!(int)vic->query_stats("constitution") > random(25)){
                       tell_object(ETO,"%^GREEN%^The %^RESET%^"+
                          "gh%^BOLD%^%^BLACK%^o%^RESET%^stly "+
                          "%^GREEN%^scything blade suddenly %^BOLD%^"+
                          "fl%^RESET%^%^GREEN%^a%^BOLD%^res %^RESET%^"+
                          "%^GREEN%^to life as it sinks deeply into "+
                          ""+vic->QCN+"'s chest!%^RESET%^");
                       tell_room(EETO,"%^GREEN%^The ghostly "+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^GREEN%^a%^BOLD%^res%^RESET%^%^GREEN%^ to "+
                          "life as it sinks deeply into "+vic->QCN+"'s "+
                          "chest.%^RESET%^",({ETO,vic}));
                       tell_room(EETO,"%^GREEN%^"+vic->QCN+" "+ 
                          "screams, clutching the haft of the weapon "+
                          "as the %^BOLD%^%^WHITE%^color %^RESET%^"+
                          "%^GREEN%^is drained from "+vic->QP+" skin "+
                          "and "+vic->QP+" eyes melt as green "+
                          "%^BOLD%^flames%^RESET%^%^GREEN%^ pour "+
                          "from the sockets!%^RESET%^",vic);
                       tell_object(ETO,"%^GREEN%^You tug the "+
                          "weapon free contemptiously letting the "+
                          "lifeless body fall to the ground.%^RESET%^");
                       tell_room(EETO,"%^GREEN%^"+ETOQCN+" smirks "+
                          "contemptiously as "+ETO->QS+" tugs the "+
                          "weapon free, letting the lifeless body "+
                          "fall to the ground.%^RESET%^",({ETO,vic}));
                       tell_object(vic,"%^GREEN%^The %^RESET%^gh"+
                          "%^BOLD%^%^BLACK%^o%^RESET%^stly %^GREEN%^"+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^GREEN%^a%^BOLD%^res %^RESET%^%^GREEN%^to "+
                          "life as it sinks deeply into your chest!%^RESET%^");
                       tell_object(vic,"%^GREEN%^Your mind is suddenly "+
                          "filled with a thousand images of %^BOLD%^"+
                          "%^BLACK%^death %^RESET%^%^GREEN%^and "+
                          "%^RED%^agony%^GREEN%^, and your blood runs "+
                          "cold as %^BOLD%^%^CYAN%^i%^BLUE%^c%^CYAN%^e."+
                          "%^RESET%^");
                       tell_object(vic,"%^GREEN%^Clutching at the "+
                          "weapon in you, you scream as your vision "+
                          "turns %^BOLD%^green%^RESET%^%^GREEN%^ and "+
                          "then, everything goes %^BOLD%^%^BLACK%^"+
                          "black...%^RESET%^");
                       vic->set_hp(-1000);
                     }else{
                       tell_object(vic,"%^RED%^You barely move in time to "+
                          "avoid being beheaded by "+ETOQCN+"'s scythe!  "+
                          "%^BOLD%^Blood pours everywhere!");
                       tell_room(EETO,"%^GREEN%^The %^RESET%^gh%^BOLD%^"+
                          "%^BLACK%^o%^RESET%^stly %^GREEN%^scything "+
                          "blade suddenly %^BOLD%^fl%^RESET%^%^GREEN%^"+
                          "a%^BOLD%^res %^RESET%^%^GREEN%^to life as "+
                          "it sinks deeply into "+vic->QCN+"'s chest!"+
                          "%^RESET%^",vic);
                       tell_room(EETO,"%^GREEN%^"+vic->QCN+" screams, "+
                          "clutching at the shaft of the weapon, before "+
                          "gritting "+vic->QP+" teeth and pushing "+
                          "free, stumbling back.%^RESET%^",vic);
                       tell_object(vic,"%^GREEN%^The %^RESET%^gh"+
                          "%^BOLD%^%^BLACK%^o%^RESET%^stly %^GREEN%^"+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^GREEN%^a%^BOLD%^res %^RESET%^%^GREEN%^to "+
                          "life as it sinks deeply into your chest!%^RESET%^");
                       tell_object(vic,"%^GREEN%^You scream as you feel "+
                          "the blades awful power tearing at your "+
                          "essence before gritting your teeth and "+
                          "pushing free, stumbling back.%^RESET%^");
                       ETO->set_property("magic",1);
                       //vic->do_damage("torso",random(50)+50);
                       dmg = roll_dice(3, 6);
                       ETO->set_property("magic",-1);
                     }
                     break;
          default:  break;
       }
   return roll_dice(3, 4) + dmg;
   }
   return dmg;
}
