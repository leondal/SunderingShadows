//nereid.c - Laurelinduin, the nereid for the Nereid's Riddle Quest.  Circe 12/11/03
//updated by Circe 7/12/05 with a few new rewards and base changes
//Added centaur, minotaur, & yuan-ti to the riddle groups - Octothorpe 1/12/14
//Added beastkin, saurian, satyr to the riddle groups - Circe 7/19/19
//Until the new items are in for new gods, I'm adapting so people at least get a generic reward ~Circe~ 7/24/19
#include <std.h>
#include <daemons.h>
#include <move.h>
#include "/d/koenig/nereid.h"

inherit NPC;
int step1;
int step2;
int step3;
int riddle1;
int riddle2;
int riddle3;
string *asked;
string *killers;
void caution();
void give_stuff();
void oops();
void interim();

void create(){
	::create();
	set_name("Laurelinduin");
	set_id(({"laurelinduin","Laurelinduin","nereid","Nereid"}));
	set_short("Laurelinduin, a nereid");
	set_long(
         "This breath-taking young woman has an ethereal quality that makes "+
         "her seem more than she appears.  Her %^YELLOW%^sparkling golden "+
         "hair %^RESET%^%^CYAN%^cascades in waves down her back to her "+
         "slender waist.  Full hips and an ample bosom are emphasized by "+
         "the transluscent %^BOLD%^%^WHITE%^white shift %^RESET%^%^CYAN%^"+
         "she wears cinched loosely by an intricate %^YELLOW%^ belt of "+
         "gold%^RESET%^%^CYAN%^.  Her skin is a radiant %^BOLD%^%^WHITE%^"+
         "pearly white%^RESET%^%^CYAN%^, complemented well by her "+
         "entrancing %^BOLD%^%^GREEN%^emer%^WHITE%^a%^GREEN%^ld eyes%^RESET%^%^CYAN%^.  "+
         "Draped elegantly about her shoulders is a thin %^BOLD%^%^WHITE%^"+
         "white shawl %^RESET%^%^CYAN%^that looks to be made of silk.  "+
         "Her %^BOLD%^%^MAGENTA%^full lips %^RESET%^%^CYAN%^are usually "+
         "tipped into a playful smile, and she is clearly more at home in "+
         "the %^BOLD%^water %^RESET%^%^CYAN%^than on land.  Each of her "+
         "movements is filled with a fluid grace unmatched by those who "+
         "walk upon the earth.  Despite her small stature and delicate "+
         "grace, the glint in her eyes reveals her to be a deadly foe."
	);
	set_gender("female");
	set_race("nereid");
	set_body_type("human");
	set_hd(30,6);
	set_alignment(8);
	set_diety("istishia");
	set_max_hp(300+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-17);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_level(30);
	set_stats("wisdom",14);
	set_stats("strength",16);
	set_stats("intelligence",26);
	set_stats("constitution",12);
	set_stats("charisma",22);
	set_stats("dexterity",20);
	set_mob_magic_resistance("average");
	set_exp(5000);
	set_max_level(20);
	set("aggressive",0);
      set_funcs(({"kiss","spit","summon","mist"}));
      set_func_chance(40);
      force_me("speech sing enchantingly");
}

void kiss(object targ)
{
   if(targ->query_gender("female")) return;
   if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_object(targ,"%^BOLD%^%^MAGENTA%^The nereid motions you closer and"+
         "kisses you deeply, leaving you lost in ecstasy.");
      tell_room(ETO,"%^BOLD%^%^MAGENTA%^You watch in horror as the nereid "+
         "grins devilishly and pulls "+targ->query_cap_name()+" to her for a kiss!",targ);
      tell_object(targ,"%^BOLD%^%^CYAN%^Your lungs fill with water from the "+
         "nereid's kiss!");
      targ->set_hp(-1);
      return;
   }
   tell_object(targ,"%^MAGENTA%^The nereid motions you forward for a kiss, "+
      "but you resist her charm!");
   tell_room(ETO,"%^MAGENTA%^The nereid motions "+targ->query_cap_name()+" forward, "+
      "but he resists her charm!",targ);
   return;
}

void spit(object targ)
{
   int con, roll;
   con = targ->query_stats("constitution");
   roll = random(20);
   if(roll > con) {
      tell_object(targ,"%^BOLD%^%^GREEN%^The nereid grows hideous with a fierce "+
         "look in her eyes as she spits %^YELLOW%^venom %^GREEN%^in your face!");
      tell_room(ETO,"%^BOLD%^%^GREEN%^The nereid spits %^YELLOW%^venom %^GREEN%^"+
         "in "+targ->query_cap_name()+"'s face!",targ);
      tell_object(targ,"%^BOLD%^%^WHITE%^The venom burns into your eyes, blinding "+
         "you!");
      targ->set_blind(1);
      return;
   }
   tell_object(targ,"%^GREEN%^The nereid's face grows contorted as she spits into "+
      "your face, but you withstand the venom!");
   tell_room(ETO,"%^GREEN%^The nereid tries to spit into "+targ->query_cap_name()+"'s "+
      "face, but "+targ->query_subjective()+" resists the venom!",targ);
   return;
}

void summon()
{
object ob;
   tell_room(ETO,"%^BOLD%^%^BLUE%^The nereid hovers in the %^CYAN%^water%^BLUE%^,"+
      "letting it drip through her fingers as she chants in a voice of the seas.");
   tell_room(ETO,"%^BOLD%^%^CYAN%^The water begins to swirl and churn, taking "+
      "on a life of its own!");
   ob = new(MON"water_weird");
   ob->move(ETO);
   ob->force_me("protect nereid");
   return;
}

void mist()
{
    int i;
    object *live;
    object targ;
    live = all_living(ETO);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;
           tell_room(ETO,"%^BOLD%^%^WHITE%^The nereid chants with the rhythm of the seas, "+
              "calling forth a %^CYAN%^scalding mist%^WHITE%^!");
           tell_object(targ,"%^BOLD%^%^WHITE%^The mist sears your flesh!");
           TO->set_property("magic", 1);
           targ->do_damage("torso", random(30)+20);
           TO->set_property("magic", -1);
           continue;
    }
    return;
}

#define GROUP4 ({"beastman","half-ogre","wemic","centaur","saurian"})
#define GROUP5 ({"elf","hobgoblin","half-drow","yuan-ti"})
#define GROUP6 ({"gnome","ogre","kobold","minotaur"})
#define GROUP7 ({"voadkyn","bugbear","dwarf","shade"})
#define GROUP1 ({"firbolg","goblin","half-elf","satyr", "nymph"})
#define GROUP2 ({"half-orc","halfling","drow","human"})
#define GROUP3 ({"ogre-mage","gnoll","orc","beastkin", "kitsune", })
#define BADDIES ({"scarlet","traelis","testlackey"})
//BADDIES is for anyone who has done something stupid in front of the nereid
//a minor IC punishment.  Circe 6/21/04
//Scarlet, Eiryasha, and Traelis had a threesome in her pool
//Eiryasha has since appeased the Nereid.  Circe 4/23/05

void reply_func(string msg, object who)
{
//Note - quests are stored on the player.o, not by name.
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   riddle1 = SAVE_D->query_array("riddle_quest_riddle1");
   riddle2 = SAVE_D->query_array("riddle_quest_riddle2");
   riddle3 = SAVE_D->query_array("riddle_quest_riddle3");
   asked = SAVE_D->query_array("riddle_quest_asked");
   killers = SAVE_D->query_array("riddle_quest_killers");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("say How dare you return after attacking me?!  You will pay, foul "+race+"!");
      force_me("emoteat "+name+" hisses at $N and attacks!");
      force_me("kill "+name+"");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote seems not to notice the interruption as she talks with "+who->query_cap_name()+".");
     return;
   }
   if(member_array(name,BADDIES) != -1){
      force_me("emote sneers.");
      force_me("say You think I will speak to you after what you did here?");
      force_me("say Be gone!");
      force_me("emote waves her hand and turns her back.");
      return;
   }
/*   if(who->query_quests()) {
     if(member_array("Riddle Quest",who->query_quests()) != -1) {
        force_me("say Welcome back, brave adventurer!");
        force_me("smile "+name+"");
        force_me("say You have already solved my riddle, but you may rest here awhile if you will.");
        return;
     }
   }
*/
   if(member_array(name, asked) != -1) {
     if(strsrch(msg,"repeat") != -1 || strsrch(msg,"last") != -1 || strsrch(msg,"Repeat") != -1){
       if(member_array(TPQN, riddle3) != -1){
          force_me("say Oh, you'd like me to repeat your last riddle?");
       if(member_array(race, GROUP1) != -1) {
         force_me("say Armor from the pure %^BOLD%^ir%^YELLOW%^i%^WHITE%^de"+
            "%^CYAN%^s%^WHITE%^cent pearls");
         force_me("say Found amid the %^CYAN%^waves %^RESET%^where the "+
            "%^BOLD%^%^CYAN%^water %^RESET%^swirls");
      }
      if(member_array(race, GROUP2) != -1) {
         force_me("say A vision of %^YELLOW%^beauty %^RESET%^within "+
            "the %^GREEN%^wilderness");
         force_me("say Can turn any woman into a %^BOLD%^god%^MAGENTA%^d%^WHITE%^ess");
      }
      if(member_array(race, GROUP3) != -1) {
         force_me("say A %^MAGENTA%^minstrel's %^RESET%^cloak, once "+
            "%^CYAN%^fine %^RESET%^and %^ORANGE%^fair");
         force_me("say Now covered with %^MAGENTA%^r%^RED%^a%^YELLOW%^g"+
            "%^RED%^s %^RESET%^in disrepair");
      }
      if(member_array(race, GROUP4) != -1) {
         force_me("say Supple %^ORANGE%^leather %^RESET%^binds lightly "+
            "those who would %^BOLD%^fly");
         force_me("say And keeps them %^ORANGE%^rooted %^RESET%^though "+
            "they look to the %^CYAN%^sky");
      }
      if(member_array(race, GROUP5) != -1) {
         force_me("say Made of the %^CYAN%^strangest %^RESET%^fabric ever seen");
         force_me("say It somehow shifts %^YELLOW%^yellow %^RESET%^"+
            "and %^BOLD%^%^GREEN%^green%^RESET%^!");
      }
      if(member_array(race, GROUP6) != -1) {
         force_me("say Made of coiled %^ORANGE%^guts %^RESET%^that are "+
            "%^BOLD%^%^GREEN%^rotting %^RESET%^and %^BLUE%^reeking");
         force_me("say Among the %^BLUE%^corpses %^RESET%^you must go sneaking");
      }
      if(member_array(race, GROUP7) != -1) {
         force_me("say %^CYAN%^Liquid %^RESET%^and %^BOLD%^%^BLACK%^shadow "+
            "%^RESET%^within a thin %^BOLD%^%^CYAN%^vial");
         force_me("say Releases a %^GREEN%^beast %^BLUE%^soulless %^RESET%^"+
            "and %^BOLD%^%^BLACK%^vile");
      }
     return;
     }
     if(member_array(name, riddle2) != -1){
        force_me("say Oh, you'd like me to repeat your second riddle?");
      if(member_array(race, GROUP1) != -1) {
         force_me("say Living %^GREEN%^lash %^RESET%^the color of %^BOLD%^%^GREEN%^spring");
         force_me("say Wound with %^GREEN%^lea%^BOLD%^v%^RESET%^%^GREEN%^es "+
            "%^RESET%^of vibrant %^BOLD%^%^GREEN%^green");
      }
      if(member_array(race, GROUP2) != -1) {
         force_me("say Sparkling %^YELLOW%^jewels %^RESET%^twi%^BOLD%^n%^RESET%^kle "+
            "and %^YELLOW%^sh%^WHITE%^i%^YELLOW%^ne");
         force_me("say Amid %^ORANGE%^filth %^RESET%^from those living like %^RED%^swine");
      }
      if(member_array(race, GROUP3) != -1) {
         force_me("say Black as the %^BOLD%^%^BLACK%^shadows %^RESET%^and "+
            "sparkling %^BOLD%^%^RED%^red");
         force_me("say Topped with a %^RED%^shattered %^RESET%^dwarven %^BOLD%^head");
      }
      if(member_array(race, GROUP4) != -1) {
         force_me("say Shimmering %^BOLD%^platinum %^RESET%^fit with %^BOLD%^%^CYAN%^aquamarine");
         force_me("say Shifting and swirling as %^CYAN%^water %^RESET%^it seems");
      }
      if(member_array(race, GROUP5) != -1) {
         force_me("say Deep, dark %^RED%^russet %^RESET%^and rough against skin");
         force_me("say A sign of %^YELLOW%^honor %^RESET%^among the %^RED%^goblinkin");
      }
      if(member_array(race, GROUP6) != -1) {
         force_me("say %^CYAN%^Pale blue %^RESET%^as the %^BOLD%^winter's %^RESET%^chill air");
         force_me("say A %^RED%^deadly %^RESET%^weapon, though exceedingly %^BOLD%^%^CYAN%^fair");
      }
      if(member_array(race, GROUP7) != -1) {
         force_me("say Thorny %^ORANGE%^spikes %^RESET%^all twisted and curved");
         force_me("say Still no %^RED%^harm %^RESET%^will come to those with nerve");
      }
     return;
     }
     if(member_array(name, riddle1) != -1){
        force_me("say Oh, you'd like me to repeat your first riddle?");
      if(member_array(race, GROUP1) != -1) {
         force_me("say In no living %^GREEN%^beast %^RESET%^do I %^RED%^pulse %^RESET%^or %^BOLD%^%^RED%^bleed%^RESET%^");
         force_me("say Yet for %^CYAN%^release%^RESET%^, I am what %^BOLD%^%^BLACK%^they %^RESET%^need");
      }
      if(member_array(race, GROUP2) != -1) {
         force_me("say %^BOLD%^Claw %^RESET%^of the %^BOLD%^%^BLACK%^abyss%^RESET%^, curved and strong");
         force_me("say Colored with %^RED%^blood %^RESET%^that does not belong");
      }
      if(member_array(race, GROUP3) != -1) {
         force_me("say A %^BOLD%^%^BLACK%^twisted %^RESET%^razor's edge is what I bring");
         force_me("say Frightened %^CYAN%^shepherds %^RESET%^feel my %^BOLD%^%^RED%^sting%^RESET%^");
      }
      if(member_array(race, GROUP4) != -1) {
         force_me("say A grisly %^YELLOW%^prize %^RESET%^from a fresh %^RED%^kill");
         force_me("say %^BOLD%^%^BLACK%^Black sp%^YELLOW%^o%^BLACK%^tt%^YELLOW%^e%^BLACK%^ "+
            "d %^RESET%^with a %^ORANGE%^silky soft %^RESET%^feel");
      }
      if(member_array(race, GROUP5) != -1) {
         force_me("say Writhing %^BOLD%^%^GREEN%^jade c%^RESET%^%^GREEN%^o%^BOLD%^i%^RESET%^"+
            "%^GREEN%^l%^BOLD%^s %^RESET%^shift in size");
         force_me("say And peer lifelessly from %^BOLD%^%^RED%^ruby %^RESET%^eyes");
      }
      if(member_array(race, GROUP6) != -1) {
         force_me("say Pure as the fresh fallen %^BOLD%^%^CYAN%^rain %^RESET%^am I");
         force_me("say On %^YELLOW%^golden hooks %^RESET%^I drop from the %^CYAN%^sky");
      }
      if(member_array(race, GROUP7) != -1) {
         force_me("say Rich %^BOLD%^%^RED%^red %^RESET%^that is tattered and torn");
         force_me("say With a %^BOLD%^silver chain %^RESET%^still proudly worn");
      }
     return;
     }
    }
    else{
       switch(random(6)){
         case 0:
            force_me("say Have you found the answer to my riddle yet?");
            break;
         case 1:
            force_me("emote smiles and sings a wordless tune.");
            break;
         case 2:
            force_me("say If you need me to repeat your latest riddle, simply ask!");
            break;
         case 3:
            force_me("emote dives down deep into the pool, splashing water on the ledge behind her.");
            break;
         case 4:
            force_me("emote comes up from the pool sputtering and laughing merrily.");
            break;
         case 5:
            force_me("emote hums and seems to be deep in thought before she giggles and dives again.");
            break;
         default:
            force_me("emote turns a slow sommersault in the water.");
            break;
      }
      return;
    }
  }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
  if(member_array(name, asked) == -1) {
    if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1 || strsrch(msg,"Hey") != -1) && !step1){
      if((int)who->query_lowest_level() < 10){
         force_me("say Hmm...well, I would love to ask you "+
            "a few riddles, but you couldn't possibly have "+
            "seen enough of the world to answer them yet!");
         force_me("say Come back when you've explored some more?");
         force_me("smile "+name+"");
         return;
      }
      step1 = 1;
      force_me("emote splashes lightly in her pool then turns and smiles.");
      force_me("say Why, hello young traveller!  Welcome to my grotto!");
      force_me("emote rises from the water and takes a seat at the edge, dangling her feet in the pool.");
      force_me("say Would you like to hear a riddle?");
      force_me ("? "+name+"");
   }
   if((strsrch(msg,"riddle") != -1 || strsrch(msg,"yes") != -1 ||
    strsrch(msg,"Yes") != -1 || strsrch(msg,"would like") != -1 ||
    strsrch(msg,"answer") != -1  || strsrch(msg,"reward") != -1 || strsrch(msg,"okay") != -1 || strsrch(msg,"Okay") != -1 || strsrch(msg,"Sure") != -1 || strsrch(msg,"sure") != -1)&& step1 && !step2)        {
      force_me("say Wonderful!");
      force_me("emote bites her bottom lip and thinks a moment with a playful smile "+
         "on her lips.");
      force_me("say Ahh yes...here we are.  First, though, the rules!");
      force_me("emoteat "+name+" studies you appraisingly.");
      force_me("say Each of your riddles can be answered with a certain item.  You "+
         "must decide the answer, go forth and find the item, and bring it back to "+
         "me!  Should you do this with each riddle I give you, you will be rewarded.");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 ||
   strsrch(msg,"agree") != -1 || strsrch(msg,"Agree") != -1 || strsrch(msg,"fair") != -1 || strsrch(msg,"first") != -1 || strsrch(msg,"okay") !=-1 || strsrch(msg,"Okay") != -1 || strsrch(msg,"lright") != -1 || strsrch(msg,"riddle") != -1 || strsrch(msg,"understand") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("riddle_quest_asked", name);
      }
      force_me("emote smiles happily.");
      force_me("say Oh, good!  Here is your first riddle...return with the answer, and "+
         "I will give you your second.");
      if(member_array(race, GROUP1) != -1) {
         force_me("say In no living %^GREEN%^beast %^RESET%^do I %^RED%^pulse %^RESET%^or %^BOLD%^%^RED%^bleed%^RESET%^");
         force_me("say Yet for %^CYAN%^release%^RESET%^, I am what %^BOLD%^%^BLACK%^they %^RESET%^need");
      }
      if(member_array(race, GROUP2) != -1) {
         force_me("say %^BOLD%^Claw %^RESET%^of the %^BOLD%^%^BLACK%^abyss%^RESET%^, curved and strong");
         force_me("say Colored with %^RED%^blood %^RESET%^that does not belong");
      }
      if(member_array(race, GROUP3) != -1) {
         force_me("say A %^BOLD%^%^BLACK%^twisted %^RESET%^razor's edge is what I bring");
         force_me("say Frightened %^CYAN%^shepherds %^RESET%^feel my %^BOLD%^%^RED%^sting%^RESET%^");
      }
      if(member_array(race, GROUP4) != -1) {
         force_me("say A grisly %^YELLOW%^prize %^RESET%^from a fresh %^RED%^kill");
         force_me("say %^BOLD%^%^BLACK%^Black sp%^YELLOW%^o%^BLACK%^tt%^YELLOW%^e%^BLACK%^ "+
            "d %^RESET%^with a %^ORANGE%^silky soft %^RESET%^feel");
      }
      if(member_array(race, GROUP5) != -1) {
         force_me("say Writhing %^BOLD%^%^GREEN%^jade c%^RESET%^%^GREEN%^o%^BOLD%^i%^RESET%^"+
            "%^GREEN%^l%^BOLD%^s %^RESET%^shift in size");
         force_me("say And peer lifelessly from %^BOLD%^%^RED%^ruby %^RESET%^eyes");
      }
      if(member_array(race, GROUP6) != -1) {
         force_me("say Pure as the fresh fallen %^BOLD%^%^CYAN%^rain %^RESET%^am I");
         force_me("say On %^YELLOW%^golden hooks %^RESET%^I drop from the %^CYAN%^sky");
      }
      if(member_array(race, GROUP7) != -1) {
         force_me("say Rich %^BOLD%^%^RED%^red %^RESET%^that is tattered and torn");
         force_me("say With a %^BOLD%^silver chain %^RESET%^still proudly worn");
      }
      step3 = 1;
      SAVE_D->set_value("riddle_quest_riddle1", name);
		return;
    }
  }
}

void receive_given_item(object obj){
   string race, deity;
   deity = TP->query_diety();
   race = TP->query_race();
   asked = SAVE_D->query_array("riddle_quest_asked");
   riddle1 = SAVE_D->query_array("riddle_quest_riddle1");
   riddle2 = SAVE_D->query_array("riddle_quest_riddle2");
   riddle3 = SAVE_D->query_array("riddle_quest_riddle3");
   killers = SAVE_D->query_array("riddle_quest_killers");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("say Begone, foul "+race+"!  I will not stand for your attacks again!");
      force_me("emoteat "+TPQN+" hisses at $N and ducks beneath the water, disappearing!");
      TO->move("/d/shadowgate/void");
      destruct(TO);;
     return;
   }
/*
   if(member_array("Riddle Quest",TP->query_quests()) != -1){
      force_me("say You have already solved my riddle and received your reward!  Do "+
         "you have a riddle for me?");
      force_me("smile");
      return;
   }
*/
   if(member_array(TPQN, asked) == -1) {
     force_me("say Thank you for the gift!");
     force_me("emote smiles brightly, her emerald eyes sparkling.");
     force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
        "reemerging, dripping wet.");
     obj->remove(TO);
     return;
   }
   if(member_array(race, GROUP1) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "%^BOLD%^%^WHITE%^P%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l breastplate"  && (string)obj->query_name() != "%^BOLD%^%^WHITE%^Pearl breastplate%^RESET%^") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "%^BOLD%^%^WHITE%^P%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l breastplate" || (string)obj->query_name() == "%^BOLD%^%^WHITE%^Pearl breastplate%^RESET%^") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "vinewhip") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "vinewhip") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say Armor from the pure %^BOLD%^ir%^YELLOW%^i%^WHITE%^de"+
              "%^CYAN%^s%^WHITE%^cent pearls");
           force_me("say Found amid the %^CYAN%^waves %^RESET%^where the "+
              "%^BOLD%^%^CYAN%^water %^RESET%^swirls");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "peryton heart") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "peryton heart") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Living %^GREEN%^lash %^RESET%^the color of %^BOLD%^%^GREEN%^spring");
           force_me("say Wound with %^GREEN%^lea%^BOLD%^v%^RESET%^%^GREEN%^es "+
              "%^RESET%^of vibrant %^BOLD%^%^GREEN%^green");
           return;
         }
      }
   }
   if(member_array(race, GROUP2) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^s%^GREEN%^t gown") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^s%^GREEN%^t gown") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "royal goblin crown") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "royal goblin crown") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say A vision of %^YELLOW%^beauty %^RESET%^within "+
              "the %^GREEN%^wilderness");
           force_me("say Can turn any woman into a %^BOLD%^god%^MAGENTA%^d%^WHITE%^ess");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "peryton talon") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "peryton talon") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Sparkling %^YELLOW%^jewels %^RESET%^twi%^BOLD%^n%^RESET%^kle "+
              "and %^YELLOW%^sh%^WHITE%^i%^YELLOW%^ne");
           force_me("say Amid %^ORANGE%^filth %^RESET%^from those living like %^RED%^swine");
           return;
         }
      }
   }
   if(member_array(race, GROUP3) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "ragged cloak") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "ragged cloak") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "ogre spear") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "ogre spear") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say A %^MAGENTA%^minstrel's %^RESET%^cloak, once "+
              "%^CYAN%^fine %^RESET%^and %^ORANGE%^fair");
           force_me("say Now covered with %^MAGENTA%^r%^RED%^a%^YELLOW%^g"+
              "%^RED%^s %^RESET%^in disrepair");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "peryton horn") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "peryton horn") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Black as the %^BOLD%^%^BLACK%^shadows %^RESET%^and "+
              "sparkling %^BOLD%^%^RED%^red");
           force_me("say Topped with a %^RED%^shattered %^RESET%^dwarven %^BOLD%^head");
           return;
         }
      }
   }
   if(member_array(race, GROUP4) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "band of the owls") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "band of the owls") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "aquamarine ring of protection") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "aquamarine ring of protection") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say Supple %^ORANGE%^leather %^RESET%^binds lightly "+
              "those who would %^BOLD%^fly");
           force_me("say And keeps them %^ORANGE%^rooted %^RESET%^though "+
              "they look to the %^CYAN%^sky");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "lion pelt") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "lion pelt") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Shimmering %^BOLD%^platinum %^RESET%^fit with %^BOLD%^%^CYAN%^aquamarine");
           force_me("say Shifting and swirling as %^CYAN%^water %^RESET%^it seems");
           return;
         }
      }
   }
   if(member_array(race, GROUP5) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "yellow and green robe") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "yellow and green robe") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "russet cloak") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "russet cloak") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say Made of the %^CYAN%^strangest %^RESET%^fabric ever seen");
           force_me("say It somehow shifts %^YELLOW%^yellow %^RESET%^"+
              "and %^BOLD%^%^GREEN%^green%^RESET%^!");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "jade snake armband") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "jade snake armband") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Deep, dark %^RED%^russet %^RESET%^and rough against skin");
           force_me("say A sign of %^YELLOW%^honor %^RESET%^among the %^RED%^goblinkin");
           return;
         }
      }
   }
   if(member_array(race, GROUP6) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "%^RESET%^%^RED%^Necklace of %^ORANGE%^en"+
            "%^RED%^t%^ORANGE%^rai%^RED%^l%^ORANGE%^s%^RESET%^") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "%^RESET%^%^RED%^Necklace of %^ORANGE%^en"+
             "%^RED%^t%^ORANGE%^rai%^RED%^l%^ORANGE%^s%^RESET%^") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "flail of frost") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "flail of frost") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say Made of coiled %^ORANGE%^guts %^RESET%^that are "+
              "%^BOLD%^%^GREEN%^rotting %^RESET%^and %^BLUE%^reeking");
           force_me("say Among the %^BLUE%^corpses %^RESET%^you must go sneaking");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "water earrings") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "water earrings") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say %^CYAN%^Pale blue %^RESET%^as the %^BOLD%^winter's %^RESET%^chill air");
           force_me("say A %^RED%^deadly %^RESET%^weapon, though exceedingly %^BOLD%^%^CYAN%^fair");
           return;
         }
      }
   }
   if(member_array(race, GROUP7) != -1) {
      if(member_array(TPQN, riddle3) != -1){
         if((string)obj->query_name() != "peryton vial") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "peryton vial") {
           force_me("say Well done!  You have answered all I have asked of you!");
           force_me("smile proudly");
           force_me("say Hmm...and for a fitting reward...");
           force_me("emoteat "+TPQN+" studies $N for a long moment, then dips beneath the waves, "+
              "coming up dripping.");
           obj->remove(TO);
           call_out("reward_me",1);
           return;
         }
      }
      if(member_array(TPQN, riddle2) != -1){
         if((string)obj->query_name() != "%^RESET%^%^ORANGE%^Bracelet of Brambles%^RESET%^") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "%^RESET%^%^ORANGE%^Bracelet of Brambles%^RESET%^") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle3", TPQN);
           force_me("say %^CYAN%^Liquid %^RESET%^and %^BOLD%^%^BLACK%^shadow "+
              "%^RESET%^within a thin %^BOLD%^%^CYAN%^vial");
           force_me("say Releases a %^GREEN%^beast %^BLUE%^soulless %^RESET%^"+
              "and %^BOLD%^%^BLACK%^vile");
           return;
         }
      }
      if(member_array(TPQN, riddle1) != -1){
         if((string)obj->query_name() != "red cloak") {
           force_me("say Thank you for the gift!");
           force_me("emote smiles brightly, her emerald eyes sparkling.");
           force_me("emote giggles and dives into the water, disappearing beneath the waves before "+
              "reemerging, dripping wet.");
           obj->remove(TO);
           return;
         }
         if((string)obj->query_name() == "red cloak") {
           force_me("say Ahh, very good!  You have brought me what I asked for!");
           force_me("smile");
           force_me("say And now, I will give you your next riddle...");
           obj->remove(TO);
           SAVE_D->set_value("riddle_quest_riddle2", TPQN);
           force_me("say Thorny %^ORANGE%^spikes %^RESET%^all twisted and curved");
           force_me("say Still no %^RED%^harm %^RESET%^will come to those with nerve");
           return;
         }
      }
   }
}

//Adding a generic reward function until new deity items are in place ~Circe~ 7/24/19
int reward_me(){
   string file;
   object obj;
   asked = SAVE_D->query_array("riddle_quest_asked");
   killers = SAVE_D->query_array("riddle_quest_killers");
   riddle1 = SAVE_D->query_array("riddle_quest_riddle1");
   riddle2 = SAVE_D->query_array("riddle_quest_riddle2");
   riddle3 = SAVE_D->query_array("riddle_quest_riddle3");
   if(member_array(TPQN, asked) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_asked", TPQN);
   if(member_array(TPQN, riddle1) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle1", TPQN);
   if(member_array(TPQN, riddle2) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle2", TPQN);
   if(member_array(TPQN, riddle3) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle3", TPQN);
      if(TP->is_class("mage") || TP->is_class("psion") || TP->is_class("sorcerer")){
               obj = new("/d/koenig/riddle/rewards/mage_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if(TP->is_class("druid")){
               obj = new("/d/koenig/riddle/rewards/druid_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if((TP->is_class("thief") && (!TP->is_class("fighter") && !TP->is_class("cleric"))) || TP->is_class("warlock") || TP->is_class("monk")){
               obj = new("/d/koenig/riddle/rewards/thief_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if(TP->is_class("cleric")){
               obj = new("/d/koenig/riddle/rewards/cleric_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if(TP->is_class("fighter") || TP->is_class("barbarian") || TP->is_class("psywarrior")){
               obj = new("/d/koenig/riddle/rewards/fighter_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if(TP->is_class("ranger")){
               obj = new("/d/koenig/riddle/rewards/ranger_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if((TP->is_class("cavalier")) || (TP->is_class("paladin")) || (TP->is_class("antipaladin"))){
               obj = new("/d/koenig/riddle/rewards/cav_default.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      if(TP->is_class("bard")){
               obj = new("/d/koenig/riddle/rewards/c_bard.c");
               obj->move(ETO);
               call_out("interim",1);
               return 1;
      }
      else{
         tell_room(ETO,"Ack, something has gone horribly wrong!  "+
            "Please contact a wiz!  If one cannot be found, please "+
            "mail Circe with your race, class, and deity "+
            "along with any error messages so she can fix the problem.  "+
            "I apologize, and thanks!");
         return 1;
     }
}

//interim message to be used while quest is being updated
void interim(){
   tell_object(TP,"Laurelinduin hmms softly as she places a "+
      "well-made reward at your feet.");
   tell_room(ETO,"Laurelinduin hmms softly and places a reward"+
      "before "+TP->QCN+".",TP);
   tell_room(ETO,"%^MAGENTA%^Laurelinduin says%^RESET%^: I'm afraid I don't have a more "
      "fitting reward at the moment. With the cosmos in such a state, I am still learning "
      "the essence of all the gods. Come back again when you can!");
   if(member_array("Riddle Quest",TP->query_quests()) != -1) {
      return 1;
   }else{
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You have solved the "+
         "Nereid's Riddle!%^RESET%^");
      TP->set_quest("Riddle Quest");
      TP->fix_exp(50000,TP);
   }
   return 1;
}

/*
BEGIN PORTION TO BE RESTORED
int reward_me(){
   string deity, file;
   object obj;
   deity = TP->query_diety();
   asked = SAVE_D->query_array("riddle_quest_asked");
   killers = SAVE_D->query_array("riddle_quest_killers");
   riddle1 = SAVE_D->query_array("riddle_quest_riddle1");
   riddle2 = SAVE_D->query_array("riddle_quest_riddle2");
   riddle3 = SAVE_D->query_array("riddle_quest_riddle3");
   if(member_array(TPQN, asked) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_asked", TPQN);
   if(member_array(TPQN, riddle1) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle1", TPQN);
   if(member_array(TPQN, riddle2) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle2", TPQN);
   if(member_array(TPQN, riddle3) != -1)
        SAVE_D->remove_name_from_array("riddle_quest_riddle3", TPQN);
//   if(member_array("Riddle Quest",TP->query_quests()) == -1){
      if(TP->is_class("mage") || TP->is_class("psion") || TP->is_class("sorcerer") || TP->is_class("psywarrior")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/mage_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/mage_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/mage_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if(TP->is_class("druid")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/druid_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/druid_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/druid_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if((TP->is_class("thief") && (!TP->is_class("fighter") && !TP->is_class("cleric"))) || TP->is_class("warlock") || TP->is_class("monk")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/thief_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/thief_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/thief_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if(TP->is_class("cleric")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/cleric_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/cleric_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/cleric_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if(TP->is_class("fighter") || TP->is_class("barbarian")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/fighter_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/fighter_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/fighter_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if(TP->is_class("ranger")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/ranger_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/ranger_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/ranger_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if((TP->is_class("cavalier")) || (TP->is_class("paladin")) || (TP->is_class("antipaladin"))){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/cav_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/cav_default.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/cav_default.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      if(TP->is_class("bard")){
         if(TP->query_diety() && deity != "pan"){
            file = "/d/koenig/riddle/rewards/bard_"+deity+".c";
            if(file_exists(file)){
               obj = new(file);
               obj->move(ETO);
               call_out("give_stuff",1);
               return 1;
            }else{
               obj = new("/d/koenig/riddle/rewards/c_bard.c");
               obj->move(ETO);
               call_out("oops",1);
               return 1;
            }
         }else{
               obj = new("/d/koenig/riddle/rewards/c_bard.c");
               obj->move(ETO);
               call_out("caution",1);
               return 1;
         }
      }
      else{
         tell_room(ETO,"Ack, something has gone horribly wrong!  "+
            "Please contact a wiz!  If one cannot be found, please "+
            "mail Circe with your race, class, and deity "+
            "along with any error messages so she can fix the problem.  "+
            "I apologize, and thanks!");
         return 1;
     }
//   }
}

//give_stuff rewards those with a deity
void give_stuff(){
   tell_room(ETO,"%^MAGENTA%^Laurelinduin says%^RESET%^:  Your faith in your "+
      "deity is well-founded.  Go with my blessing!");
   tell_room(ETO,"Laurelinduin places a fitting reward before "+TP->QCN+".",TP);
   tell_object(TP,"Laurelinduin places a fitting reward before you.");
      if(member_array("Riddle Quest",TP->query_quests()) != -1) {
          return 1;
      }else{
         tell_object(TP,"%^BOLD%^%^MAGENTA%^You have solved the "+
            "Nereid's Riddle!%^RESET%^");
         TP->set_quest("Riddle Quest");
         TP->fix_exp(50000,TP);
      }
      return 1;
}

//caution rewards those without a deity
void caution(){
   tell_object(TP,"Laurelinduin frowns slightly before placing a "+
      "well-made reward at your feet.");
   tell_room(ETO,"Laurelinduin frowns and places a reward"+
      "before "+TP->QCN+".",TP);
   tell_room(ETO,"%^MAGENTA%^Laurelinduin says%^RESET%^: You really "+
      "should look to the condition of your soul.  Those without faith "+
      "are lost.  This was the best reward I could find for you.");
   if(member_array("Riddle Quest",TP->query_quests()) != -1) {
      return 1;
   }else{
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You have solved the "+
         "Nereid's Riddle!%^RESET%^");
      TP->set_quest("Riddle Quest");
      TP->fix_exp(50000,TP);
   }
   return 1;
}
END PORTION TO BE RESTORED
*/

//oops is for those screw ups where we missed rewards
void oops(){
   tell_object(TP,"Uh oh, seems like we're missing a reward.  "+
      "Please mail Circe with your class(es), deity, and "+
      "tell her you got the default reward instead.  I "+
      "apologize for any inconvenience.");
   if(member_array("Riddle Quest",TP->query_quests()) != -1) {
      return 1;
   }else{
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You have solved the "+
         "Nereid's Riddle!%^RESET%^");
      TP->set_quest("Riddle Quest");
      TP->fix_exp(50000,TP);
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("riddle_quest_killers", "stringname")
    int hold;
    killers = SAVE_D->query_array("riddle_quest_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(victim->query_name(), killers) != -1 || !interactive(victim)) return hold;
    if((int)victim->query_highest_level() < 10){
       force_me("say Be gone, little one, before I show you "+
          "my power!");
       force_me("emote dives into the pool.");
       TO->remove();
       return 0;
    }
    SAVE_D->set_value("riddle_quest_killers", victim->query_name());
    force_me("say You dare attack me, foul "+victim->query_race()+"?!  Now, "+
       "you will die!");
    force_me("emoteat "+victim->query_name()+" hisses at $N and attacks!");
    return hold;
}

void catch_say(string msg)
{
    if(!objectp(TO)) return;
    ::catch_say(msg);
    if(!objectp(TP)) return;
    if(interactive(TP))
    {
        call_out("reply_func",1,msg,TP);
        return;
    }
    return;
}


void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
