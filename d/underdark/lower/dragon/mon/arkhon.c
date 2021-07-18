#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../lair.h"
inherit WEAPONLESS;

int rath, active;
object *fighterz;

void create() {
   ::create();
   set_name("Arkhon Bloodscale");
   set_id(({ "dragon","arkhon","arkhon bloodscale","bloodscale","Arkhon","Arkhon Bloodscale","ancient dragon","deep dragon","ancient deep dragon"}));
   set_short("%^RESET%^%^MAGENTA%^A%^BLUE%^r%^MAGENTA%^khon Bl%^RED%^o%^MAGENTA%^ods%^BOLD%^%^BLACK%^ca%^RESET%^%^MAGENTA%^le, an an%^BLUE%^c%^MAGENTA%^ient deep dra%^BOLD%^%^BLACK%^g%^RESET%^%^MAGENTA%^on%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^Smaller than most dragons, this creature still t%^RED%^o%^MAGENTA%^wers over you at an "
"impressive sixteen feet tall, and stands easily more than thirty feet from head to tail.  A pair of blackened spu"
"%^RESET%^r%^MAGENTA%^s lead from either side of his forward-swept jawline, with vi%^RED%^c%^MAGENTA%^ious fangs visible "
"as his draconic maw parts in a sna%^GREEN%^r%^MAGENTA%^l.  A flat, tapered noseplate lies beneath narrow eyes that "
"glitter with mal%^YELLOW%^e%^RESET%^%^MAGENTA%^volent intellect, leading his face back in a streamline, shielded crest "
"of s%^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^ines.  His slender profile is reminiscent of a sn%^BOLD%^%^GREEN%^a%^RESET%^"
"%^MAGENTA%^ke, with a long and sinuous neck leading down to a lithe but muscular frame.  Thick ri%^ORANGE%^d%^MAGENTA%^"
"ged spines run the length of his neck, like a line of jagged ob%^BLUE%^s%^MAGENTA%^idian shards.  Here where his sinuous "
"neck meets the muscular rise of his shoulders, a pair of narrow wings lift on powerfu%^RED%^l%^MAGENTA%^ly corded sinews"
", still half-folded to allow ease of movement in this enclosed space, but likely reaching nearly fifty feet at their "
"full span.  A long, oph%^GREEN%^i%^MAGENTA%^dian tail trails out behind the dragon, moving and coiling like a serpent.  "
"His entire scaled coat is a deep, rich shade of pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple, fading to jet-bl%^BOLD%^%^BLACK%^a"
"%^RESET%^%^MAGENTA%^ck at the extremities of his spines, claws and wingtips.  Just looking upon this dragon takes your "
"breath away.%^RESET%^");
   set_race("dragon");
   set_gender("male");
   set_body_type("dragon");
   set_alignment(9);
   set_size(4);
   set_exp(500000);
   add_limb("teeth","head",0,0,0);
   set_attack_limbs( ({"teeth","left foreclaw","right foreclaw"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_damage(3,10);
   set_hd(50,12);
   set_class("fighter");
   set_mlevel("fighter",50);
   set_guild_level("fighter",50);
   set_class("cleric");
   set_mlevel("cleric",50);
   set_guild_level("cleric",50);
   set_max_hp(8000);
   set_hp(query_max_hp());
   set_property("weapon resistance",4);
   set_property("damage resistance",10);
   set_property("no animate", 1);
   set_property("no death", 1);
   set_property("no steal", 1);
   set_property("no hold", 1);
   set_property("no dominate", 1);
   set_property("no bows", 1);
   set_property("no web", 1);
   set_overall_ac(-27);
   set_funcs(({"earthtomud","earthtomud","teeth_fun","teeth_fun","breath_fun","breath_fun","claws_fun","claws_fun"}));
   set_func_chance(85);
   set_property("swarm",1);
   rath = 0;
   active = 0;
}

void init() {
   string whoami;
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
   add_action("no_cast","caress");
   whoami=TP->query_name();
   if(whoami != "Rath'argh" && !TP->query_true_invis()) {
//     TO->force_me("kill "+whoami+"");
     TO->add_attacker(TP);
     TP->add_attacker(TO);
   }
}

int no_cast(string str) {
   tell_object(TP,"%^YELLOW%^The dragon swings his massive spined head to send a frightful glare your way, and you "
"can't help but %^CYAN%^freeze %^YELLOW%^as that dread gaze falls upon you!%^RESET%^");
   return 1;
}

void breath_fun(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^GREEN%^Arkhon lifts his head, and hissing drops of %^BOLD%^acid %^RESET%^%^GREEN%^fall from "
"his fangs as he opens his jaws wide!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   TO->set_property("magic",1);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_name() == "rath'argh") continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     if(((int)vars[i]->query_level() + roll_dice(1,4)) < 35) { //failed save, do burn twice. No lowbies allowed!
       tell_object(vars[i],"%^BOLD%^%^GREEN%^From his fanged maw issues a breath of choking, corrosive gas that "
"%^YELLOW%^burns %^GREEN%^horribly as it touches your skin!%^RESET%^");
       vars[i]->do_damage("torso",150+random(50));
       call_out("reburn",ROUND_LENGTH,vars[i]);
     }
     else {
       tell_object(vars[i],"%^BOLD%^%^GREEN%^From his fanged maw issues a breath of choking, corrosive gas. You dive "
"aside to avoid the worst of it, but it still %^YELLOW%^burns %^GREEN%^horribly as it touches your skin!%^RESET%^");
       //vars[i]->do_damage("torso",150+random(50));
       vars[i]->cause_typed_damage(vars[i], vars[i]->return_target_limb(), 150 + random(50), "acid");
     }
   }
   tell_room(ETO,"%^BOLD%^%^GREEN%^From his fanged maw issues a breath of choking, corrosive gas that %^YELLOW%^burns "
"%^GREEN%^horribly wherever it touches bare skin!%^RESET%^",vars);
   TO->remove_property("magic");
   return;
}

void reburn(object target) {
   if(!target || !objectp(target)) return;
   tell_object(target,"%^BOLD%^%^GREEN%^The corrosive gas eats into your skin, and you can't help but to scream in "
"agony!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^GREEN%^"+target->QCN+" screams in agony as the corrosive gas continues to eat into "
+target->QP+" skin!%^RESET%^",target);
   TO->set_property("magic",1);
   //target->do_damage("torso",200+random(100));
   target->cause_typed_damage(target, target->return_target_limb(), 200 + random(100), "acid");
   TO->remove_property("magic");
}

void earthtomud(object target){
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^ORANGE%^The dragon swipes a clawed forefoot through the air and snarls unintelligable words"
".  Suddenly, entire portions of the stone beneath your feet is no longer solid, as the transmutation changes it into "
"%^RED%^thick mud%^ORANGE%^!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_name() == "rath'argh") continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->set_tripped(4,"%^YELLOW%^You're trying to get free of the mud!%^RESET%^",ROUND_LENGTH);
   }
}

void teeth_fun(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_object(target,"%^BOLD%^%^RED%^Arkhon darts forward towards you with startling speed, and searing pain burns "
"through your body as his teeth sink into your shoulder and he lifts you from the ground.  With a jerk of his powerful "
"serpentine neck, he releases his hold and suddenly you are airborne, and the cavern wall rushes up to meet you with a "
"jarring impact!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^Arkhon darts forward with startling speed, his teeth sinking into "+target->QCN+"'s "
"shoulder and lifting "+target->QO+" bodily from the ground.  A jerk of that powerful serpentine neck, and suddenly "
+target->QS+" is flying through the air, to impact the cavern wall with an audible thud!%^RESET%^",target);
   TO->set_property("magic",1);
   //target->do_damage("torso",random(75)+100);
   target->cause_typed_damage(target, target->return_target_limb(), 100 + random(75), "piercing");
   TO->remove_property("magic");
}

void claws_fun(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   tell_room(ETO,"%^MAGENTA%^Arkhon coils back on his haunches, before leaping upwards and outwards to descend upon "
"his foes in a l%^BOLD%^i%^RESET%^%^MAGENTA%^vid fre%^RED%^n%^BOLD%^z%^RESET%^%^MAGENTA%^y of claws and fangs.%^RESET%^");
   for(i = 0;i<4;i++) {
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     switch(random(4)) {
       case 0:
         tell_object(target,"%^RED%^He rends you horribly with his claws!%^RESET%^");
         tell_room(ETO,"%^RED%^He rends "+target->QCN+" horribly with his claws!%^RESET%^",target);
       break;
       case 1:
         tell_object(target,"%^RED%^His jaws tear your flesh to shreds!%^RESET%^");
         tell_room(ETO,"%^RED%^His jaws tear "+target->QCN+"'s flesh to shreds!%^RESET%^",target);
       break;
       case 2:
         tell_object(target,"%^RED%^He rakes you with the vicious claws of his hind leg!%^RESET%^");
         tell_room(ETO,"%^RED%^He rakes "+target->QCN+" with the vicious claws of his hind leg!%^RESET%^",target);
       break;
       default:
         tell_object(target,"%^RED%^Razor-sharp fangs pierce your skin!%^RESET%^");
         tell_room(ETO,"%^RED%^Razor-sharp fangs pierce "+target->QCN+"'s skin!%^RESET%^",target);
       break;
     }
   target->cause_typed_damage(target, target->return_target_limb(), 100 + random(75), "slashing");
   }
}

void heart_beat() {
    object myob, thatroom, room;
    int currhp, maxhp, i;
    string printme;
    ::heart_beat();

    if(!objectp(TO)) return;
    room = environment(this_object());
    if(!room)
        return;
    if((int)TO->query_hp() < (int)TO->query_max_hp() && !active) {
      TO->add_hp(random(60)+60);
    }
    if(!active && sizeof(query_attackers())) {
      active = 1;
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      if(sizeof(fighterz)) printme = fighterz[0]->query_name();
      if(sizeof(fighterz) > 1) {
        for(i=1;i<sizeof(fighterz);i++) printme += ", "+fighterz[i]->query_name();
      }
//      tell_room(ETO,"%^BOLD%^%^BLUE%^Debugging: fighterz array to select "+printme+".");
    }
    if(active) {
      if(!sizeof(query_attackers()) && query_property("no paralyze")) {
        active = 0;
        fighterz = ({});
      }
      else {
        if(!rath) {
          maxhp = (int)TO->query_max_hp()/2;
          currhp = (int)TO->query_hp();
          if(currhp < maxhp) {
            myob = new(OBJ"rathsummon");
            myob->move(ETO);
            myob->start_me();
            rath = 1;
          }
        }
      }
    }
    if((myob = present("rath'argh")) && !active) {
      tell_room(ETO,"%^MAGENTA%^Arkhon turns his spined head towards the drow, and gives the slightest of nods as he "
"hisses:%^RESET%^ 'Go, my pet. Your work here is done.'");
      tell_room(ETO,"%^BOLD%^%^BLACK%^The shrouded drow dips into a deep, almost mocking bow, before he swirls his cloak "
"around himself and vanishes from sight.%^RESET%^");
      myob->move("/d/shadowgate/void");
      myob->remove();
      rath = 0;
      return;
    }
    if(!active) {
      tell_room(ETO,"%^ORANGE%^The muddied floor shimmers and becomes rock-solid again.%^RESET%^");
      if(member_array("tunnel",ETO->query_exits()) == -1) ETO->add_exit(ROOMS"tunnel1","tunnel");
      thatroom = find_object_or_load(ROOMS"tunnel1");
      if(member_array("cavern",thatroom->query_exits()) == -1) thatroom->add_exit(ROOMS"lair","cavern");
      tell_room(ETO,"%^CYAN%^Arkhon seems to grow hazy, and then shrinks rapidly back into the form of the naked drow he "
"had once been.  He steps back into the darkness of the cavern and fades from view.%^RESET%^");
      ETO->reset_cinematics();
      TO->remove();
    }
}

void die(object ob){
   object *ppl, treasures, thatroom;
   string printme;
   int i;
   string *donequests, queststring, queststringb;
   queststring = "%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^";
   queststringb = "%^BOLD%^%^BLACK%^Vanquished %^RESET%^%^MAGENTA%^Ark%^BLUE%^h%^MAGENTA%^on Blo%^RED%^o%^MAGENTA%^dscale%^BOLD%^%^BLACK%^, ancient dragon of the deep!%^RESET%^";
   tell_room(ETO,"%^ORANGE%^The dragon lets out an ear-splitting shriek, whisps of %^GREEN%^aci%^BOLD%^d%^RESET%^"
"%^GREEN%^ic breath %^ORANGE%^escaping his fanged maw as droplets splatter and hiss upon the stone floor.%^RESET%^");
   tell_room(ETO,"%^RED%^Mortally wounded, he staggers back, his slender legs swaying with the effort, and finally he "
"collapses to the ground with an impact that %^ORANGE%^s%^RESET%^ha%^RED%^k%^YELLOW%^e%^RESET%^%^ORANGE%^s %^RED%^the "
"very walls of the cavern.%^RESET%^");
   message("info","%^BOLD%^%^RED%^A great %^RESET%^%^RED%^r%^BOLD%^o%^RESET%^%^RED%^ar %^BOLD%^shakes the earth beneath "
"your feet, as Arkhon Bloodscale breathes his last!%^RESET%^",users());
   ppl = ({});
   for(i=0;i<sizeof(fighterz);i++) {
     if(userp(fighterz[i])) {
       ppl += ({ fighterz[i] });
       if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
         fighterz[i]->set_mini_quest(queststring,3100000,queststringb);
         tell_object(fighterz[i],"\n%^BOLD%^%^CYAN%^A thrilling sense of accomplishment runs through you as you realise "
"the mighty deep dragon has fallen to your hand!%^RESET%^\n");
       }
     }
   }
   tell_room(ETO,"%^ORANGE%^As the last living breath escapes him, Arkhon's spells begin to fall apart.  A transmuted "
"stone wall congeals back into %^RED%^mud %^ORANGE%^and oozes to the ground, revealing a passageway to %^CYAN%^escape"
"%^ORANGE%^ into a small side cavern!%^RESET%^");
   if(sizeof(ppl) && rath) {
     for(i = 0;i<sizeof(ppl);i++) {
       if(!i) printme = (string)ppl[i]->query_name();
       else printme += ", "+(string)ppl[i]->query_name();
     }
     treasures = find_object_or_load(ROOMS"treasurevault");
     if(objectp(treasures)) treasures->activate_loot();
   }
   else tell_room(ETO,"%^YELLOW%^Error: notify Nienne of this message - ppl or rath variables not written!%^RESET%^");
   if(member_array("out",ETO->query_exits()) == -1) ETO->add_exit(ROOMS"treasurevault","out");
   if(member_array("tunnel",ETO->query_exits()) == -1) ETO->add_exit(ROOMS"tunnel1","tunnel");
   thatroom = find_object_or_load(ROOMS"tunnel1");
   if(member_array("cavern",thatroom->query_exits()) == -1) thatroom->add_exit(ROOMS"lair","cavern");
   ::die(TO);
}
