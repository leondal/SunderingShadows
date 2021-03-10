#include <std.h>
#include "../defs.h"
inherit NPC;

#define TIER1 ({ "camel","spider","fish" }) // sustenance, spider climb, water breathing
#define TIER2 ({ "hare","owl","crow" }) // evasion, illumination, insight
#define TIER3 ({ "bull","salamander","chameleon"}) // mind shielding, regeneration,stealth
#define TIER4 ({ "air","earth","water","fire" }) // detection, reflection, freedom, energy -> not yet in
#define TRADE1 ({ "/d/shadow/room/kildare/obj/hornblade","/d/darkwood/yntala/obj/vinewhip","/d/antioch/valley/obj/spear" }) // peryton talon, yntala whip, dark trail ogrespear
#define TRADE2 ({ "/d/barriermnts/ruins/obj/bladestaff","/d/laerad/lgnolls/obj/warbow","/d/islands/coralsea/obj/sharkskinwhip" }) // archie's bladestaff, gnoll comp bow, coral sea whip
#define TRADE3 ({ "/d/antioch/ruins/obj/fire_spear","/d/islands/dreams/obj/yewbow","/d/deku/weapons/fire_dagger" }) // fireplanes fire spear, dreams yewbow, kinorda fire dagger
#define TRADE4 ({ "/d/underdark/lower/dragon/obj/sheoldagger","/d/attaya/obj/cal_crysknife","/d/islands/argentrock/obj/bonebow" }) // arkhon's dagger, callista's crysknife, dragonbone bow
string ring1, ring2, ring3, ring4;

void create() {
    ::create();
    set_name("chakit");
    set_id( ({ "beastkin", "chakit", "ChaKit", "beastfolk", "carver"}) );
    set_short("%^RESET%^%^ORANGE%^ChaKit, beastkin carver%^RESET%^");
    set("aggressive", 0);
    set_hd(29,2);
    set_long("%^GREEN%^ChaKit bears less powerful musculature than most beastkin, but what he lacks in power, he appears to make "
"up for in speed and grace.  Perched upon a nearby branch, his long and slender fingers (and sometimes toes!) are always at work "
"on this carving or that, his sharp green eyes intently focussed upon his latest project.  He wears nothing but his own hair/fur, "
"from which hangs a series of trinkets, tiny wooden shapes to mimic feathers and leaves and fangs.");
    set_gender("male");
    set_property("no dominate", 1);
    set_property("no kill", 1);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_alignment(5);
    set_race("beastkin");
    set_overall_ac(-19);
    set_stats("strength", 18);
    set_stats("dexterity", 20);
    set_stats("constitution", 18);
    set_stats("intelligence", 12);
    set_stats("wisdom", 14);
    set_stats("charisma", 14);
    set_class("fighter");
    set_body_type("human");
    set_hp(400);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(0);
    set_max_mp(query_mp());
    force_me("speak common");
    force_me("speech voice in growls and chirps");
    ring1 = TIER1[random(sizeof(TIER1))];
    ring2 = TIER2[random(sizeof(TIER2))];
    ring3 = TIER3[random(sizeof(TIER3))];
    ring4 = TIER4[random(sizeof(TIER4))];
}

void catch_say(string msg){
   ::catch_say(msg);
   call_out("do_stuff",1,msg,TP);
}

void do_stuff(string msg, object ob){

// messages for invis folks
   if(TP->query_invis()) {
      switch(random(5)) {
        case 0: force_me("emote peers around curiously.");
          break;
        case 1: force_me("say Hiding thing, there?");
          break;
        case 3:  force_me("emote 's verdant eyes spare a moment away from his current carving to scan the area.");
          break;
        default: break;
      }
      return;
   }

// messages to pick up conversation
   if(strsrch(msg, "hello") != -1 || strsrch(msg,"greeting") != -1 ||
       strsrch(msg,"Hello") != -1 || strsrch(msg,"Greeting") != -1) {
     force_me("say Hi-hi! What's here for? Come to learn from best at carving? But never as good as ChaKit!");
     force_me("emote preens, clearly impressed with his own skill.");
     force_me("say you trade for ChaKit's carvings? ChaKit wants weapon for tribe.");
     return;
   }
   if(strsrch(msg, "carving") != -1 || strsrch(msg,"trade") != -1) {
     force_me("emote holds up a small, carved wooden ring.");
     force_me("say ChaKit can make, call on spirits to bless.");
     force_me("emote closes his eyes, and seems to meditate for a long moment.");
     force_me("say Feels today, "+ring1+" and "+ring2+" and "+ring3+" spirits will listen.");
//     force_me("say Feels today, "+ring1+" and "+ring2+", "+ring3+" and "+ring4+" spirits will listen.");
     force_me("emote claps his furry hands.");
     force_me("say You ask if not knowing spirits! Or what weapon to bring!");
     return;
   }
   if(strsrch(msg, ring1) != -1) { // tier1 explanations & trade items
     force_me("say So you want knowing of "+ring1+" spirit? ChaKit tells.");
     force_me("emote raises himself up to explain.");
     switch(ring1) {
       case "camel": force_me("say Camel goes with no food, no water, one moon or more."); break;
       case "spider": force_me("say Spider goes up tree, cave wall, easy."); break;
       case "fish": force_me("say Fish goes under water, no need for air."); break;
     }
     force_me("say ChaKit wants weapon for trade! Hear of many good ones, far away.");
     force_me("say you bring sword made of peryton antler. Or whip of vines from yuan-ti. Or blood-spear from orcs, on trail to north. ChaKit swaps for these.");
     force_me("emote smiles broadly.");
     return;
   }
   if(strsrch(msg, ring2) != -1) { // tier1 explanations & trade items
     force_me("say So you want knowing of "+ring2+" spirit? ChaKit tells.");
     force_me("emote raises himself up to explain.");
     switch(ring2) {
       case "hare": force_me("say Hare is swift, skips to side and other side, gets away from hunter."); break;
       case "owl": force_me("say Owl sees with big eyes, even in most dark night."); break;
       case "crow": force_me("say Crow is most clever of animals, many ideas to get what wants."); break;
     }
     if(ob->query_level() < 15) { // they're too small to wear it!
       force_me("emoteat "+ob->query_name()+" peers intently at $N.");
       force_me("say ChaKit feels, you not strong enough for this spirit.");
       return;
     }
     force_me("say ChaKit wants weapon for trade! Hear of many good ones, far away.");
     force_me("say you bring two-end sword from ruins in Barrier Mountain. Or whip from coral under-sea. Or great bow from gnolls on Laerad. ChaKit swaps for these.");
     force_me("emote smiles broadly.");
     return;
   }
   if(strsrch(msg, ring3) != -1) { // tier1 explanations & trade items
     force_me("say So you want knowing of "+ring3+" spirit? ChaKit tells.");
     force_me("emote raises himself up to explain.");
     switch(ring3) {
       case "bull": force_me("say Bull is stubborn, never stopped when wanting a thing."); break;
       case "salamander": force_me("say Salamander can heal from hurts. Even grow back legs! But maybe that is too strong for spirit to give. Only heal small hurts!"); break;
       case "chameleon": force_me("say Chameleon is good at hiding, pretend to be something else."); break;
     }
     if(ob->query_level() < 25) { // they're too small to wear it!
       force_me("emoteat "+ob->query_name()+" peers intently at $N.");
       force_me("say ChaKit feels, you not strong enough for this spirit.");
       return;
     }
     force_me("say ChaKit wants weapon for trade! Hear of many good ones, far away.");
     force_me("say you bring yew-bow from dream island. Or fire-dagger from tunnel on Deku island. Or fire spear from plane of fire, hiding in ruin to north. ChaKit swaps for these.");
     force_me("emote smiles broadly.");
     return;
   }
/*   if(strsrch(msg, ring4) != -1) { // tier4 explanations & trade items
     force_me("say So you want knowing of "+ring4+" spirit? ChaKit tells.");
     force_me("emote raises himself up to explain.");
     switch(ring4) {
       case "air": force_me("say Air carries all, brings sound, smell, to tell of danger. Air is for sensing."); break;
       case "earth": force_me("say Earth is strong, many things strike, only bounce off. Earth is for protecting."); break;
       case "water": force_me("say Water gets away, always runs through, around, off. Water is for escape."); break;
       case "fire": force_me("say Fire holds heat, warmth, gives strength to magic. Fire is for energy."); break;
     }
     if(ob->query_level() < 35) { // they're too small to wear it!
       force_me("emoteat "+ob->query_name()+" peers intently at $N.");
       force_me("say ChaKit feels, you not strong enough for this spirit.");
       return;
     }
     force_me("say ChaKit wants weapon for trade! Hear of many good ones, far away.");
     force_me("say you bring shadow dagger from dragon, deep under earth. Or tooth dagger from tower of crystal. Or bone bow from island of fey'ri. ChaKit swaps for these.");
     force_me("emote smiles broadly.");
     return;
   } */

// messages if nothing in their convo matches trigger words!
   if(random(4)) return;
   switch(random(5)) {
     case 0:
       force_me("say ChaKit knows spirits. Can feel them in world, all around.");
       break;
     case 1:
       force_me("emote hands his current project off to hold in his toes, freeing up his hands to hone his carving knife.");
       break;
     case 2:
       force_me("emote etches tiny patterns of leaves down the side of a wooden ring.");
       break;
     case 3:
       force_me("emote adds the last touches to a tiny wooden feather, before pausing to tie it into his fur as an ornament.");
       break;
     case 4:
       force_me("say You come for trade? ChaKit makes carvings, calls on spirits to help!");
       break;
   }
   return;
}

void receive_given_item(object ob){
   int oktogive;
   if(member_array(base_name(ob),TRADE1) != -1) { // tier 1
     switch(ring1) {
       case "camel": new(RINGS"sustenance")->move(TO); oktogive = 1; break;
       case "spider": new(RINGS"spiderclimb")->move(TO); oktogive = 1; break;
       case "fish": new(RINGS"waterbreathing")->move(TO); oktogive = 1; break;
     }
   }
   if(member_array(base_name(ob),TRADE2) != -1) { // tier 1
     switch(ring2) {
       case "hare": new(RINGS"evasion")->move(TO); oktogive = 1; break;
       case "owl": new(RINGS"illumination")->move(TO); oktogive = 1; break;
       case "crow": new(RINGS"insight")->move(TO); oktogive = 1; break;
     }
   }
   if(member_array(base_name(ob),TRADE3) != -1) { // tier 1
     switch(ring3) {
       case "bull": new(RINGS"mindshielding")->move(TO); oktogive = 1; break;
       case "salamander": new(RINGS"regeneration")->move(TO); oktogive = 1; break;
       case "chameleon": new(RINGS"stealth")->move(TO); oktogive = 1; break;
     }
   }
/*   if(member_array(base_name(ob),TRADE4) != -1) { // tier 1
     switch(ring4) {
       case "air": new(RINGS"detection")->move(TO); oktogive = 1; break;
       case "earth": new(RINGS"reflection")->move(TO); oktogive = 1; break;
       case "water": new(RINGS"freedom")->move(TO); oktogive = 1; break;
       case "fire": new(RINGS"energy")->move(TO); oktogive = 1; break;
     }
   } */
   if(oktogive) {
     ob->move("/d/shadowgate/void");
     ob->remove();
     force_me("emote claps his hands.");
     force_me("say this is one ChaKit wants for tribe!");
     force_me("emote snags the weapon in his toes, using it as deftly as a hand.");
     force_me("say ChaKit asks spirit to bless.");
     force_me("emote growls a few words low as he takes up his carving knife, etching a symbol into the wooden ring he holds.");
     force_me("give carved ring to "+TPQN);
     if(present("carved ring", TO)) {
       command("say You not carry this. ChaKit puts it down for you.");
       command("emote sets it carefully on the branch beside him, within your reach.");
       command("drop carved ring");
     }
     return;
   }
   force_me("say this not what ChaKit ask for.");
   force_me("emote puts the item down.");
   force_me("drop "+ob->query_id()[1]+"" );
   return;
}
