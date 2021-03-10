//created by Circe 3/26/05
//adapted by Circe 10/27/07 to use proper spells with new domains
#include <std.h>
#include <daemons.h>
#include "defs.h"

inherit "/d/common/obj/weapon/rapier";


void create(){
   ::create();
   set_name("iridescent sword");
   set_id(({"sword","iridescent sword","rapier","iridescent rapier","legacy","aislinn's legacy"}));
   set_obvious_short("%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^r%^YELLOW%^i"+
      "%^GREEN%^d%^CYAN%^e%^BLUE%^s%^RESET%^%^MAGENTA%^c%^BOLD%^"+
      "%^RED%^e%^RESET%^%^ORANGE%^n%^YELLOW%^t %^BLUE%^"+
      "rapier%^RESET%^");
   set_short("%^BOLD%^%^MAGENTA%^A%^RESET%^%^MAGENTA%^i"+
      "%^BOLD%^s%^RESET%^%^MAGENTA%^l%^BOLD%^i%^RESET%^"+
      "%^MAGENTA%^n%^BOLD%^n%^RESET%^%^MAGENTA%^'%^BOLD%^"+
      "s %^RESET%^%^CYAN%^Legacy%^RESET%^");
   set_long("%^MAGENTA%^This impressive longsword is "+
      "crafted from an unusual %^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^r%^YELLOW%^i"+
      "%^GREEN%^d%^CYAN%^e%^BLUE%^s%^RESET%^%^MAGENTA%^c%^BOLD%^"+
      "%^RED%^e%^RESET%^%^ORANGE%^n%^YELLOW%^t %^RESET%^%^MAGENTA%^"+
      "metal.  Unlike the the thicker blade of a standard "+
      "longsword, this sword has a thin, almost rapier-like "+
      "blade ending in a fine point.  The pommel of the sword "+
      "is sculpted into the lifelike image of a slender "+
      "%^BOLD%^dragon's%^RESET%^%^MAGENTA%^ head.  The %^BOLD%^"+
      "dragon's %^RESET%^%^MAGENTA%^open mouth supports "+
      "a smooth egg carved from an unusual %^BOLD%^%^CYAN%^"+
      "crystal %^RESET%^%^MAGENTA%^that is shot through with "+
      "%^BOLD%^%^CYAN%^v%^RESET%^e%^MAGENTA%^i%^BOLD%^%^BLUE%^n%^CYAN%^s "+
      "%^RESET%^%^MAGENTA%^of %^BOLD%^%^BLUE%^cobalt%^RESET%^%^MAGENTA%^"+
      ", %^BOLD%^amethyst%^RESET%^%^MAGENTA%^, and %^RESET%^clear calcite"+
      "%^MAGENTA%^.  All around the mouth are thin "+
      "%^YELLOW%^golden tendrils %^RESET%^%^MAGENTA%^"+
      "reminiscent of a dragon's whiskers.  The sinuous "+
      "body of the %^BOLD%^dragon %^RESET%^%^MAGENTA%^"+
      "wraps its way around the %^BOLD%^%^BLACK%^black "+
      "leather hilt%^RESET%^%^MAGENTA%^, with the "+
      "%^BOLD%^forked tail %^RESET%^%^MAGENTA%^finally "+
      "ending halfway up the blade of the sword.  "+
      "The %^BOLD%^dragon's %^RESET%^%^MAGENTA%^thin "+
      "%^YELLOW%^wings %^RESET%^%^MAGENTA%^have been "+
      "worked in gold and fold back upon one another "+
      "to form the protective basket of the sword.  The "+
      "exquisite craftsmanship and lifelike representation "+
      "of the dragon show that this sword must have "+
      "been crafted by a %^BOLD%^%^WHITE%^master "+
      "%^RESET%^%^MAGENTA%^- or a %^BOLD%^%^CYAN%^"+
      "magician%^RESET%^%^MAGENTA%^.");
   set_lore("My research has shown that the sword "+
      "named Aislinn's Legacy comes by its name "+
      "honestly.  The sword holds a potent amount "+
      "of the dragon's spirit, and consequently, the "+
      "spirit of dreams themselves.  Though not "+
      "technically sentient, it does seem to possess "+
      "some manner of will, but it remains utterly "+
      "neutral.  It is mystically "+
      "connected to three deities who can somewhat "+
      "alter or affect fate or illusion in some way - "+
      "namely, Selune, Mystra, and Cyric.  The crystal "+
      "set within the pommel is made of lucindaris, "+
      "a crystal that draws upon the powers of all the "+
      "elements. - "+
      "Matylin the Wise, 'An Account of the Dream Realm'");
   set_property("enchantment",4);
   set_value(3000);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_hit((:TO,"hitme":));
}

int wieldme(){
string mygod = ETO->query_diety();
    if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   if((int)ETO->query_stats("wisdom") < 12){
      tell_object(ETO,"%^CYAN%^The will of the sword seems "+
         "at odds with yours!  It resists your attempt to use it.");
      return 0;
   }
   switch(mygod){
      case "selune":  tell_object(ETO,"%^BOLD%^The "+
         "crystal egg brightens with a %^CYAN%^silvery "+
         "light %^WHITE%^as you lift the "+
         "sword.  You sense that the moon will help you "+
         "see the truth!");
         tell_room(EETO,"%^BOLD%^The crystal on "+
         ""+ETOQCN+"'s sword flares with a %^CYAN%^"+
         "silvery light %^WHITE%^as "+
         ""+ETO->QS+" wields it.",ETO);
         set_property("mygod","selune");
         break;
      case "mystra":  tell_object(ETO,"%^CYAN%^The "+
         "crystal egg flares with a %^BOLD%^mystical "+
         "blue light %^RESET%^%^CYAN%^as you lift "+
         "the sword.  You sense an ancient magic "+
         "fill you.");
         tell_room(EETO,"%^CYAN%^The crystal on "+
         ""+ETOQCN+"'s sword flares with a %^BOLD%^"+
         "blue light %^RESET%^%^CYAN%^as "+
         ""+ETO->QS+" wields it.",ETO);
         set_property("mygod","mystra");
         break;
      case "cyric":  tell_object(ETO,"%^BOLD%^%^BLACK%^The "+
         "crystal egg darkens with an %^BLUE%^eerie "+
         "black light %^BLACK%^as you lift "+
         "the sword.  You sense the power of an "+
         "ancient menace fill you.");
         tell_room(EETO,"%^BOLD%^%^BLACK%^The crystal on "+
         ""+ETOQCN+"'s sword darkens with an %^BLUE%^"+
         "eerie black light %^BLACK%^as "+
         ""+ETO->QS+" wields it.",ETO);
         set_property("mygod","cyric");
         break;
      default:  tell_object(ETO,"%^BOLD%^%^BLUE%^The "+
         "crystal in the dragon's mouth shimmers "+
         "dimly in the light as you wield the sword.");
         tell_room(EETO,"%^BOLD%^%^BLUE%^The crystal "+
         "on "+ETOQCN+"'s sword shimmers dimly as "+
         ""+ETO->QS+" wields it.",ETO);
         break;
   }
   return 1;
}

int unwieldme(){
string mygod = ETO->query_diety();
   switch(mygod){
      case "selune":
      case "mystra":
      case "cyric":
         tell_object(ETO,"%^MAGENTA%^The light of the "+
            "crystal fades as you put aside the sword.");
         tell_room(EETO,"%^MAGENTA%^The light of the "+
            "crystal in the sword wielded by "+ETOQCN+" "+
            "fades away as "+ETO->QS+" puts it aside.",ETO);
         remove_property("mygod");
         break;
      default:  tell_object(ETO,"%^BOLD%^%^BLUE%^You "+
         "lower the sword.");
         tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" lowers the sword.",ETO);
   }
   return 1;
}

int hitme(object targ){
string mygod = ETO->query_diety();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(20)){
      switch(mygod){
         case "selune":     tell_object(ETO,"%^BOLD%^You feel "+
                          "the dragon spirit within your sword "+
                          "rise and course through your veins!  "+
                          "For a moment, you are a %^MAGENTA%^"+
                          "half-dragon %^WHITE%^who lashes out "+
                          "at "+targ->QCN+"!");
                          tell_object(targ,"%^BOLD%^"+ETOQCN+"'s "+
                          "visage changes, and "+ETO->QS+" looks "+
                          "for a moment like a %^MAGENTA%^dragon"+
                          "%^WHITE%^!  The dragon lashes out at "+
                          "you, leaving you in pain!");
                          tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s "+
                          "visage changes, and "+ETO->QS+" looks "+
                          "for a moment like a %^MAGENTA%^dragon"+
                          "%^WHITE%^!  The dragon lashes out at "+
                          ""+targ->QCN+", leaving "+targ->QO+" "+
                          "howling in pain!",({targ,ETO}));
                          targ->do_damage(targ->return_target_limb(),random(3)+3);
                     break;
         case "mystra":  tell_object(ETO,"%^CYAN%^Your sword "+
                          "%^BOLD%^s%^RESET%^%^CYAN%^h%^BOLD%^i"+
                          "%^RESET%^%^CYAN%^m%^BOLD%^m%^RESET%^"+
                          "%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s "+
                          "with mystical energy.  Suddenly, "+
                          "seven %^BOLD%^%^WHITE%^shuriken "+
                          "%^RESET%^%^CYAN%^fly from its tip into "+
                          ""+targ->QCN+"!");
                       tell_object(targ,"%^CYAN%^The sword "+
                          "held by "+ETOQCN+" "+
                          "%^BOLD%^s%^RESET%^%^CYAN%^h%^BOLD%^i"+
                          "%^RESET%^%^CYAN%^m%^BOLD%^m%^RESET%^"+
                          "%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s "+
                          "with mystical energy.  Suddenly, "+
                          "seven %^BOLD%^%^WHITE%^shuriken "+
                          "%^RESET%^%^CYAN%^fly from its tip into "+
                          "you!");
                       tell_room(EETO,"%^CYAN%^The sword "+
                          "held by "+ETOQCN+" "+
                          "%^BOLD%^s%^RESET%^%^CYAN%^h%^BOLD%^i"+
                          "%^RESET%^%^CYAN%^m%^BOLD%^m%^RESET%^"+
                          "%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s "+
                          "with mystical energy.  Suddenly, "+
                          "seven %^BOLD%^%^WHITE%^shuriken "+
                          "%^RESET%^%^CYAN%^fly from its tip into "+
                          ""+targ->QCN+"!",({targ,ETO}));
                          targ->do_damage(targ->return_target_limb(),random(3)+3);
                     break;
         case "cyric":  tell_object(ETO,"%^BOLD%^%^BLACK%^As "+
                          "you swing the sword at "+targ->QCN+", "+
                          "the blade seems to grow liquid in your "+
                          "hands, changing into a massive two-"+
                          "handed sword that cleaves into "+targ->QO+"!");
                      tell_object(targ,"%^BOLD%^%^BLACK%^You "+
                          "watch in confusion as the rapier wielded "+
                          "by "+ETOQCN+" suddenly shifts in size "+
                          "to that of a two-handed sword that "+
                          "cleaves into you!");
                      tell_room(EETO,"%^BOLD%^%^BLACK%^You "+
                          "watch in confusion as the rapier wielded "+
                          "by "+ETOQCN+" suddenly shifts in size "+
                          "to that of a two-handed sword that "+
                          "cleaves into "+targ->QCN+"!",({targ,ETO}));
                          targ->do_damage(targ->return_target_limb(),random(3)+3);
                     break;
         default:  tell_object(ETO,"%^MAGENTA%^You roar with "+
                      "the rage of a dragon and slice into "+
                      ""+targ->QCN+"!");
                   tell_object(targ,"%^MAGENTA%^"+ETOQCN+" "+
                      "suddenly roars and slices into you!");
                   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" "+
                      "suddenly roars and slices into "+targ->QCN+"!",({ETO,targ}));
                   targ->do_damage(targ->return_target_limb(),random(3)+3);
                   break;
      }
      return roll_dice(1,3);
   }
   if(!random(30)){
      switch(mygod){
         case "selune":  tell_object(ETO,"%^BOLD%^You are "+
                         "filled with the energy of "+
                         "%^CYAN%^quicksilver %^WHITE%^and "+
                         "attack again quickly before "+
                         ""+targ->QCN+" can respond!");
                         tell_object(targ,"%^BOLD%^"+ETOQCN+" "+
                         "suddenly moves so quickly you "+
                         "lose sight of "+ETO->QO+"!  You "+
                         "feel another sword thrust just "+
                         "behind the last one!");
                         tell_room(EETO,"%^BOLD%^"+ETOQCN+" "+
                         "suddenly moves with amazing speed, "+
                         "seeming to blur as "+ETO->QS+" strikes "+
                         ""+targ->QCN+"!",({ETO,targ}));
                         ETO->execute_attack();
                         break;
         case "mystra":  tell_object(ETO,"%^BOLD%^%^BLUE%^"+
                         "You feel a gift from your goddess "+
                         "as you harness the powers of the "+
                         "%^CYAN%^arcane %^BLUE%^and blink "+
                         "to the other side of "+targ->QCN+" "+
                         "to attack "+targ->QO+" again!");
                         tell_object(targ,"%^BOLD%^%^BLUE%^"+
                         ""+ETOQCN+" suddenly vanishes and "+
                         "reappears at your side, striking "+
                         "you again with "+ETO->QP+" rapier!");
                         tell_room(EETO,"%^BOLD%^%^BLUE%^"+
                         ""+ETOQCN+" whispers words of "+
                         "%^CYAN%^arcane might %^BLUE%^and "+
                         "suddenly blinks beside "+targ->QCN+" "+
                         "to attack "+targ->QO+" again!",({ETO,targ}));
                         ETO->execute_attack();
                         break;
         case "cyric":  tell_object(ETO,"%^BOLD%^%^BLACK%^"+
                        "With cunning befitting your master, "+
                        "you strike "+targ->QCN+" before "+
                        "disappearing in an illusory smoke.  "+
                        "You reappear on the other side to "+
                        "sink your rapier into "+targ->QO+" "+
                        "once more!");
                        tell_object(targ,"%^BOLD%^%^BLACK%^"+
                        ""+ETOQCN+" disappears in a puff of "+
                        "smoke as "+ETO->QS+" strikes you!  "+
                        "%^RED%^Suddenly, you feel "+ETO->QP+" "+
                        "blade from your other side!  Where "+
                        "the hell did "+ETO->QS+" come from??");
                        tell_room(EETO,"%^BOLD%^%^BLACK%^As "+
                        ""+ETOQCN+" attacks "+targ->QCN+", "+
                        ""+ETO->QS+" disappears in a puff of "+
                        "smoke!  %^RED%^Suddenly, "+ETO->QS+"'s "+
                        "on "+targ->QCN+"'s other side to "+
                        "attack!",({ETO,targ}));
                        ETO->execute_attack();
                        break;
         default:  tell_object(ETO,"%^YELLOW%^The golden "+
                   "wings of the dragon sword's basket "+
                   "suddenly flare to life!  They thrust "+
                   "your sword forward, making you attack "+
                   "with incredible speed!");
                   tell_object(targ,"%^YELLOW%^The golden "+
                   "wings forming the basket of "+ETOQCN+"'s "+
                   "sword spring to life, thrusting the "+
                   "blade into you with incredible speed!");
                   tell_room(EETO,"%^YELLOW%^The golden "+
                   "wings forming the basket of "+ETOQCN+"'s "+
                   "sword spring to life, thrusting the "+
                   "blade into "+targ->QCN+" with "+
                   "incredible speed!",({ETO,targ}));
                   ETO->execute_attack();
                   break;
      }
      return random(2)+1;
   }
   if(!random(50)){
      tell_object(ETO,"%^MAGENTA%^A %^BOLD%^%^RED%^p%^RESET%^"+
         "%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a"+
         "%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^"+
         "c %^MAGENTA%^light bursts forth from the dragon's "+
         "egg in your sword, aimed for the eyes of "+targ->QCN+"!");
      tell_object(targ,"%^MAGENTA%^The egg in the pommel of the "+
         "sword wielded by "+ETOQCN+" suddenly brightens, sending "+
         "a %^BOLD%^%^RED%^p%^RESET%^"+
         "%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a"+
         "%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^"+
         "c %^MAGENTA%^beam right into your eyes!");
      tell_room(EETO,"%^MAGENTA%^The egg in the pommel of the "+
         "sword wielded by "+ETOQCN+" suddenly brightens, sending "+
         "a %^BOLD%^%^RED%^p%^RESET%^"+
         "%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a"+
         "%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^"+
         "c %^MAGENTA%^beam right into "+targ->QCN+"'s eyes!",({ETO,targ}));
      if((int)targ->query_stats("constitution") < random(20)){
         targ->set_paralyzed(random(3)+2,"You are reeling from the blinding light!");
         targ->set_temporary_blinded(10,"You see %^BOLD%^%^RED%^p%^RESET%^"+
         "%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a"+
         "%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^"+
         "c %^RESET%^spots before your eyes!");
      }else{
         tell_object(targ,"%^RED%^You fight off the worst "+
            "of the light!");
         targ->do_damage("head",random(6)+4);
      }
      return 1;
   }
   if(!random(50)){
      switch(mygod){
         case "selune":  tell_object(ETO,"%^BOLD%^You feel "+
                         "the blessings of your goddess "+
                         "heaped upon you as the words of "+
                         "an incantation escape your lips!");
                         tell_room(EETO,"%^BOLD%^"+ETOQCN+" "+
                         "closes "+ETO->QP+" eyes and whispers "+
                         "a prayer!",ETO);
                         new("/cmds/spells/m/_moonbeam")->use_spell(ETO,targ,8,100,"cleric");
                         break;
         case "mystra":  tell_object(ETO,"%^BOLD%^%^CYAN%^"+
                         "The presence of your goddess fills "+
                         "your mind, bringing with it the words "+
                         "of an ancient incantation!");
                         tell_room(EETO,"%^BOLD%^%^CYAN%^"+
                         ""+ETOQCN+" holds up one hand and "+
                         "calls forth an ancient incantation!",ETO);
                         new("/cmds/spells/m/_mystic_bolt")->use_spell(ETO,targ,8,100,"cleric");
                         break;
         case "cyric":  tell_object(ETO,"%^BOLD%^%^BLUE%^"+
                        "A smirk plays upon your lips as "+
                        "you sense your lord's will work "+
                        "its way into your mind, and you "+
                        "call forth an age-old curse!");
                        tell_room(EETO,"%^BOLD%^%^BLUE%^"+
                        ""+ETOQCN+" smirks knowingly and "+
                        "calls forth an age-old curse!",ETO);
                        new("/cmds/spells/u/_unholy_orb")->use_spell(ETO,targ,14,100,"cleric");
                        break;
         default:  tell_object(ETO,"%^BOLD%^%^MAGENTA%^You "+
                   "hear faint whisperings that seem to be "+
                   "coming from the lifeless dragon upon "+
                   "your sword.  Suddenly, you shout out "+
                   "an incantation!");
                   tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" "+
                   "looks surprised as "+ETO->QS+" shouts "+
                   "out an incantation!",ETO);
                   new("/cmds/spells/m/_monster_summoning_i")->use_spell(ETO,targ,8,100,"mage");
                   break;
      }
      return 1;
   }
   return roll_dice(1,4);
}
