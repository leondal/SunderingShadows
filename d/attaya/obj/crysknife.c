//coded by Circe for Oghma 8/30/04
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/dagger";
int OWNED;
string owner;

void create(){
   ::create();
   set_name("crysknife");
   set_id(({"knife","dagger","crysknife","tooth","sharpened tooth"}));
   set_obvious_short("%^BOLD%^%^WHITE%^A sharpened tooth%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^C%^YELLOW%^r%^WHITE%^ys%^YELLOW%^kn"+
      "%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^e%^RESET%^");
   set_long("%^MAGENTA%^This seemingly innocuous-looking dagger is "+
      "carved from one solid piece of what appears to be the %^WHITE%^"+
      "fragile, %^BOLD%^%^WHITE%^milky-%^YELLOW%^yellow%^RESET%^"+
      "%^MAGENTA%^, %^ORANGE%^cr%^BOLD%^%^YELLOW%^ys%^WHITE%^ta"+
      "%^RESET%^%^WHITE%^l%^YELLOW%^iz%^RESET%^%^ORANGE%^ed %^WHITE%^"+
      "tooth%^MAGENTA%^ of some great beast.  Considering the length "+
      "of the blade, one would imagine that the size of the maw this "+
      "%^WHITE%^tooth%^MAGENTA%^ was extracted from would have to have "+
      "been colossal.  A lingering smell of %^ORANGE%^ozone%^MAGENTA%^ "+
      "and %^BOLD%^%^YELLOW%^sulfur%^RESET%^%^MAGENTA%^ surrounds the "+
      "weapon, so much so as to seem permanently suffused and embedded "+
      "within it.  An eerie pulsing resonates in a palpitating vibrato, "+
      "so much like a %^BOLD%^%^RED%^heartbeat%^RESET%^%^MAGENTA%^, "+
      "from its core, as to fool one into believing the dagger itself "+
      "alive.  The texture of the blade itself where it has not been "+
      "chiseled and struck like glass to a honed razor-edge would best "+
      "be described as %^BOLD%^%^YELLOW%^gritty%^RESET%^%^MAGENTA%^, "+
      "and %^CYAN%^sharkskin-like%^MAGENTA%^.  The hilt itself goes "+
      "unwrapped, but is ringed in carvings done in an archaic form of "+
      "common, which when combined with the texture of the natural "+
      "material makes for an impressive grip.  Oftentimes it is evident "+
      "that minor %^BOLD%^%^YELLOW%^electrical%^RESET%^%^MAGENTA%^ "+
      "discharges run across and throughout this unconventional marvel "+
      "of tribal weaponry.");
   set_language("common");
   set_read("%^BOLD%^%^WHITE%^From whence it sprang shall all return, "+
      "claimed by the desert itself and becoming whole with the earth."+
      "  Only then can our mortal souls be shed of the prison of flesh, "+
      "to assist our Lords and Queens in the halls of our forebears.  "+
      "Bringing death to your enemies is but an honor they recieve along "+
      "their immortal paths.");
   set_lore("Crysknives are the legendary weapons carried by the most "+
      "influential in the nomadic desert tribes wandering throughout "+
      "the lands.  The carved daggers are initially aquired by extruding "+
      "the teeth from the gargantuan Sand Worm, a rare sight to behold "+
      "even in the deep desert, one whose maw is hundreds of yards "+
      "across, filled with lightning and flame, and are said to instill "+
      "tremendous fear in even the most stout of heart.  The tooths can "+
      "only be taken by those that had either had the fortune to come "+
      "across the corpse of the worm laying out decaying upon the dunes, "+
      "or those that had in fact, slain one themselves.  If not done this "+
      "way, the initial electrical bond that is formed between the still "+
      "living appendage of the tooth and its extractor is broken, "+
      "effectively killing the tooth, making it extremely brittle, and "+
      "normally violently shattering it.  Considering that the worms' "+
      "lifespans are near unfathomable to gauge, and that the desert "+
      "tribes concur that it is at very least a millenia, it is "+
      "remarkable if they are ever found without fight.  These daggers "+
      "are sacred amongst the desert dwellers, and if found without "+
      "pulse in the hands of a foreigner, they shall assume the worst, "+
      "and the foreigner will most likely become but the sand they walk upon.");
   set_property("lore difficulty",25);
   set_property("enchantment",4);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_hit((:TO,"hitme":));
   set_value(500);
}

int wieldme(){
   if((string)ETO->query_name() != owner){
      tell_object(ETO,"%^BOLD%^The blade turns dull and milky in "+
         "your hands, then suddenly shatters!");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" looks startled as the "+
         "blade in "+ETO->QP+" hands suddenly shatters!",ETO);
      tell_object(ETO,"%^BOLD%^%^RED%^The shards pierce your skin!");
      ETO->do_damage(ETO->return_target_limb(),30+random(40));
      TO->remove();
      return 0;
   }
   tell_object(ETO,"%^RESET%^%^ORANGE%^As you grip the blade, its "+
      "opaque color fades to a %^YELLOW%^transluscent crystalline sheen!");
   tell_room(EETO,"%^RESET%^%^ORANGE%^The blade of "+ETOQCN+"'s weapon "+
      "grows %^YELLOW%^crystalline %^RESET%^%^ORANGE%^as "+ETO->QS+" "+
      "wields it!",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^The %^YELLOW%^crystalline "+
      "blade %^RESET%^%^ORANGE%^fades to a dull, cloud-like white "+
      "once more.");
   tell_room(EETO,"%^RESET%^%^ORANGE%^As "+ETOQCN+" lowers the "+
      "blade, its %^YELLOW%^crystalline sheen %^RESET%^%^ORANGE%^"+
      "dulls once more.",ETO);
   return 1;
}

int hitme(object targ){
   object obj;
   int i, j;
   object *inven;
   object *live;
   string wielder = ETO;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(!random(6)){
      switch(random(50)){
         case 0..20:  tell_object(ETO,"%^YELLOW%^A crackling salvo of "+
                      "current seems to pull from you, and discharges "+
                      "into "+targ->QCN+"!");
                      tell_object(targ,"%^YELLOW%^A cacophanous boom "+
                      "resounds in your skull, as a ball of lightning "+
                      "pulsates into you!");
                      tell_room(EETO,"%^YELLOW%^A tempest of ozone and "+
                      "charred flesh fills the area as "+targ->QCN+" "+
                      "becomes consumed in a torrent of energy!",({ETO,targ}));
                      ETO->set_property("magic",1);
                      targ->do_damage(targ->return_target_limb(),6+random(4));
                      ETO->set_property("magic",-1);
                      break;
         case 21..35: tell_object(ETO,"%^MAGENTA%^You feel a magnetic "+
                      "force build within the dagger as you extract it "+
                      "from "+targ->QCN+", drawing a massive gout of "+
                      "%^BOLD%^%^RED%^blood %^RESET%^%^MAGENTA%^from the wound!");
                      tell_object(targ,"%^MAGENTA%^"+ETOQCN+" wrenches "+
                      "the dagger from you with a trembling hand.  You "+
                      "feel the pull from its blade draw out a stream "+
                      "of %^BOLD%^%^RED%^blood%^RESET%^%^MAGENTA%^!");
                      tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" appears to "+
                      "fight to keep "+ETO->QP+" dagger as "+targ->QCN+" "+
                      "suddenly pales from the loss of %^BOLD%^%^RED%^blood "+
                      "%^RESET%^%^MAGENTA%^streaking from "+targ->QP+" wound!",
                      ({ETO,targ}));
                      ETO->set_property("magic",1);
                      targ->do_damage(targ->return_target_limb(),8+random(8));
                      ETO->set_property("magic",-1);
                      break;
         case 36..42: tell_object(ETO,"%^BOLD%^%^CYAN%^Your soul "+
                      "courses with a divine prescience, and your "+
                      "body responds with a flux of pure celerity!");
                      tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s "+
                      "eyes take on a bright neon glow and blur, as "+
                      ""+ETO->QS+" counters your every move with "+
                      "three of "+ETO->QP+" own!");
                      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" "+
                      "seems to have broken the confines of time "+
                      "itself as "+ETO->QP+" now scintillating eyes "+
                      "leave trails of light admist "+ETO->QP+" "+
                      "attack!",({ETO,targ}));
                      ETO->execute_attack();
                      ETO->execute_attack();
                      break;
         case 43..47: tell_object(ETO,"%^RESET%^%^RED%^From beyond "+
                      "this realm, you believe you hear a sardonic "+
                      "voice begging for release!\n%^BOLD%^%^RED%^Something "+
                      "has heard your call!");
                      tell_room(EETO,"%^RESET%^%^RED%^A malicious "+
                      "tinkling of fey-like laughter fills the sky "+
                      "as a portal opens releasing a sand-shrouded "+
                      "figure!",ETO);
                      obj = new("/d/avatars/circe/dust_mephit");
                      obj->move(EETO);
                      obj->force_me("protect "+wielder->query_name());
                      wielder->add_follower(obj);
                      break;
         case 48..49: inven = all_living(EETO);
                      live = filter_array(inven, "is_non_immortal_player", FILTERS_D);
                      j = sizeof(live);
                      tell_object(ETO,"%^RESET%^%^ORANGE%^Gritting "+
                      "your teeth, you arc the dagger in a spin "+
                      "from the ground up in a fluid motion.  A "+
                      "momentary rift snaps open sending a "+
                      "%^YELLOW%^squall of sand %^RESET%^%^ORANGE%^and "+
                      "debris at your foes!");
                      tell_room(EETO,"%^RESET%^%^ORANGE%^As "+ETOQCN+" "+
                      "completes a circumvolution, you see a rift "+
                      "begin to open!  A %^YELLOW%^tornado of sand "+
                      "%^RESET%^%^ORANGE%^billows forth in a wicked frenzy!",ETO);
                      for(i=0;i<j;i++) {
                         if(!objectp(live[i])) continue;
                         if(live[i] == ETO) continue;
                         tell_object(live[i],"%^YELLOW%^Suddenly "+
                            "a roar of searing sand "+
                            "begins to sheer and flay your flesh!");
                         live[i]->do_damage("torso",random(10)+8);
                         live[i]->set_paralyzed(3+random(2),"You "+
                            "are reeling from the sand!");
                      }
                      break;
      }
      return roll_dice(1, 4);
   }
   return 0;
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}
   
