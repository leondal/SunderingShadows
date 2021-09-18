//jontar.c - The Old Priest
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
#include "../chants.h"
inherit QNPC;

void set_responses();
int query_day_number();

int asking_about_quali, asking_about_madness;

string* jetstone_givers;

void create(){
   ::create();
   asking_about_quali = 0;
   jetstone_givers = ({});
   set_name("Jontar");
   set_id( ({"jontar","priest","old priest", "ghost",
                                            "tecqumin"}) );
   set_short("Jontar, the old priest");
   set_long("The ghost of an elderly Tecqumin priest");
   set_gender("male");
   set_race("ghost");
   set_body_type("human");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_overall_ac(-30);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_level(35);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_exp(60);
   set("aggressive",0);
   set_responses();
   will_open = 1;
   set_property("untrackable", 1);
   asking_about_madness = 0;
}

set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday", "hi"}),
    ({"Hello there.", "Why, you are of the living, and not of the"
     +" %^CYAN%^Tecqumin%^RESET%^. What a strange thing." }),
      "frown" );
  set_response(({"tecqumin"}), ({"We are the people of this island."
    +" A race long dead, once beloved of the %^BOLD%^%^RED%^S"
    +"%^YELLOW%^u%^RED%^n Lord%^RESET%^, now %^CYAN%^cursed%^RESET%^"
    +" to roam in undeath." }) );
  set_response(({"chant for today", "chant for the day"}), ({"Now"
    +" let me see, let me see..." }),"chant", "Knows of the Heart"
    +" of the Jungle");
  set_response(({"sacred chant"}), ({"The sacred chants? I am"
    +" surprised you know of them.", "We priests learned many sacred"
    +" chants, for different days and different seasons. Part of our"
    +" ritual duty was to say the correct chants for each day, when"
    +" sacrifices were made or powers invoked.",
        "Would you like to know the %^GREEN%^chant for today"
    +"%^RESET%^?" }),"frown", "Knows of the Heart of the Jungle" );
  set_response(({"fountain", "fountain of youth"}), ({"We%^CYAN%^"
   +" Tecqumin %^RESET%^had a legend of a fountain, you know. The fabled"
   +" %^BOLD%^%^CYAN%^f%^BLUE%^ou%^CYAN%^nt%^BLUE%^a%^WHITE%^i%^CYAN%^n"
   +"%^RESET%^ of %^BOLD%^%^YELLOW%^Youth%^RESET%^! So %^BOLD%^%^WHITE%^"
   +"bright%^RESET%^was its %^BOLD%^%^BLUE%^water%^RESET%^, so"
   +" %^BOLD%^%^CYAN%^clear%^RESET%^ were its %^BLUE%^depths%^RESET%^."
   +" A single drink was enough to restore youth to the oldest of"
   +" mortals, it was said." , "Sadly, no-one in living memory ever found"
   +" it, so it's hard to be sure if the legends were true.", "I do"
   +" recall from the legend of Inami, that it was said he found it on a"
   +" %^BLUE%^river island%^RESET%^ but declined to drink, for fear of"
   +" angering the Gods.", "They already had their eyes on him after he"
   +" stole the secret of fire from them, you see..." }) );
  set_response(({"island", "river island"}), ({"Perhaps there is an"
    +" island in the river that flows through the jungle. I do not know,"
    +" and have not seen one.", "But then, I lived in the city and rarely"
    +" ventured beyond"  }) );
  set_response(({"cursed", "curse"}), ({"Yes, we were cursed at the %^CYAN%^"
    +"downfall of our race%^RESET%^. Thus we died, but did not die"
    +" and all who lived at that time now continue to exist as"
    +" ghosts, our souls unable to gather at the side of the"
    " %^BOLD%^%^RED%^S%^YELLOW%^u%^RED%^n Lord%^RESET%^ or the"
    +" %^BOLD%^%^GREEN%^Spirit of the J%^RESET%^%^GREEN%^u%^BOLD%^"
    +"%^GREEN%^ngle%^RESET%^", "If only there was a way to"
    +" %^CYAN%^lift the curse" }) );
  set_response(({"god"}), ({"The Gods of the %^CYAN%^Tecqumin"
    +"%^RESET%^ are ancient. We worshipped them for many years."
    +" %^RED%^An-Tehp%^RESET%^, the %^BOLD%^%^RED%^S%^YELLOW%^u"
    +"%^RED%^n Lord%^RESET%^, %^GREEN%^Quali%^RESET%^, the %^BOLD%^"
    +"%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngle Sp%^RESET%^"
    +"%^GREEN%^i%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^i%^BOLD%^"
    +"%^GREEN%^t%^RESET%^, %^ORANGE%^Nobach Eri%^RESET%^, the"
    +"%^BLUE%^ jaguar%^RESET%^, %^ORANGE%^Inami%^RESET%^, the"
    +" %^RED%^hero of the flame%^RESET%^ and %^CYAN%^Teoctauoc"
    +"%^RESET%^, the %^BOLD%^%^GREEN%^fe%^BOLD%^%^BLUE%^a%^BOLD%^"
    +"%^GREEN%^th%^YELLOW%^e%^GREEN%^r%^CYAN%^e%^GREEN%^d s%^RESET%^"
    +"%^GREEN%^e%^BOLD%^%^GREEN%^rp%^RESET%^%^GREEN%^e%^BOLD%^"
    +"%^GREEN%^nt%^RESET%^. All these were our Gods.", "But more"
    +" lately, there was another. A dark thing that I will not name."
    +" We came to worship it under the auspices of %^CYAN%^Epithon"
    +"%^RESET%^, our prince. He brought us under its spell, and I"
    +" think that was the beginning of our end." }) );
  set_response(({"downfall"}), ({"Our people were weakened already."
    +" Dying, I think, due to the demands for %^ORANGE%^sacrifices"
    +"%^RESET%^ that %^CYAN%^Epithon%^RESET%^, our prince, made for"
    +" the new God he worshipped. And then came a day of fear, a day"
    +" when terror and destruction rained from the sky and the very"
    +" land itself broke.",
        "The first we knew was when the sky darkened with clouds as"
    +" black as the coat of %^ORANGE%^Nobach Eri%^RESET%^. Then a"
    +" sound came, so loud that men fell to the ground, clutching at"
    +" their ears, unable even to hear their own screaming. The"
    +" ground shook, buildings fell and many died. And when we"
    +" looked up, those who still lived, half the%^ORANGE%^ mountain"
    +" %^RESET%^was gone, smote in two by some great force, and a"
    +" cloud of dust blocked out the sun for many days.",
        "After that, there were no more children for the%^CYAN%^"
    +" Tecqumin%^RESET%^. No lives to replace those who died. But"
    +" those who died did not leave. Not for them the final journey"
    +" to rest among the %^ORANGE%^Gods%^RESET%^. They stayed, here"
    +" among us as %^CYAN%^ghosts%^RESET%^, just as you see me now."
    +" Unable to live, unable to die. Cursed for an eternity for our"
    +" folly."}), "downfall" );
  set_response(({"sacrifice"}), ({"In the glory days of our"
    +" race, sacrifices to the Gods were made in ritual ceremonies"
    +" at the very summit of the %^CYAN%^Ziggurat%^RESET%^. We"
    +" offered grain and animals and flowers and precious stones,"
    +" but most precious of all, we offered them %^RED%^blood gift"
    +"%^RESET%^, and the life force that flowed within it.",
         "At one time, over a thousand souls went to the%^BOLD%^"
    +" %^RED%^S%^YELLOW%^u%^RED%^n Lord%^RESET%^ in this way in the"
    +" space of a week. %^ORANGE%^Slaves%^RESET%^ and captured foes"
    +" of the %^CYAN%^Tecqumin%^RESET%^, and even those who"
    +" volunteered to embrace the %^CYAN%^flowery death%^RESET%^ and"
    +" take their places in glory at the side of %^RED%^An-Tehp"
    +"%^RESET%^, in the heavens." }) );
  set_response(({"unfettered"}), ({"Speak not its name!",
        "That foul thing was the cause of the %^CYAN%^downfall of"
    +" our people%^RESET%^. After %^CYAN%^Epithon%^RESET%^ diverted"
    +" much of the worship from the %^BOLD%^%^RED%^S%^YELLOW%^u"
    +"%^RED%^n Lord%^RESET%^, he demanded more and more of the"
    +" %^RED%^blood gift%^RESET%^ for that creature.",
        "I don't know why it would have needed so much %^CYAN%^life"
    +" force%^RESET%^ for itself. But I think that whatever it was"
    +" doing caused the destruction that rained down on our people."
     }),"alarmed",({"Heard of the Unfettered"}) );
  set_response( ({"blood gift"}), ({"The blood gift is the sacrifice"
    +" of life, given to all our gods on occasion, but most"
    +" regularly to %^RED%^An-Tehp%^RESET%^, the %^BOLD%^%^RED%^S"
    +"%^YELLOW%^u%^RED%^n Lord%^RESET%^. The power of %^CYAN%^life"
    +" force%^RESET%^ passed to him from those given the%^CYAN%^"
    +" flowery death%^RESET%^ enabled him to keep the sun moving in"
    +" its journey across the sky each day.",
        "In life, I was a priest of the %^BOLD%^%^RED%^S%^YELLOW%^u"
    +"%^RED%^n Lord%^RESET%^, though some doubts have risen in my"
    +" mind in the centuries since I have been a ghost.",
        "It has made me wonder that the sun has continued on its"
    +" journies, long long after the sacrifices came to an end."}));
  set_response(({"life force"}), ({"In each being there is a force"
    +" of life. Even plants and animals contain life force, but it"
    +" is strongest in sentient beings. Through the rituals of"
    +" %^ORANGE%^sacrifices%^RESET%^, we priests directed the life"
    +" force of those given the %^CYAN%^flowery death%^RESET%^ to"
    +" the service of the %^ORANGE%^Gods%^RESET%^."}) );
  set_response(({"flowery death"}), ({"In our society, great honour"
    +" was accrued by those who gave up their life force to the"
    +" %^ORANGE%^Gods%^RESET%^. They were sacrificed cleanly and"
    +" swiftly as possible by the priests, with the"
    +" %^BOLD%^%^CYAN%^dr%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ug"
    +"%^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^t %^RESET%^%^CYAN%^of"
    +" %^BOLD%^%^MAGENTA%^f%^YELLOW%^l%^RESET%^%^MAGENTA%^o"
    +"%^BOLD%^%^MAGENTA%^we%^GREEN%^r%^MAGENTA%^s%^RESET%^, a"
    +" concoction of drugged wine given them to spare any pain.",
        "Thus they began their journey to the Heavens in a state of"
    +" euphoria",
        "Great honour was also accrued by their patrons, those who"
    +" supplied %^ORANGE%^slaves%^RESET%^ or captured foemen to the"
    +" %^ORANGE%^sacrifice%^RESET%^. This was one path by which the"
    +" people of the %^CYAN%^Tecqumin%^RESET%^ were able to rise in"
    +" station in the sight of their rulers"}) );
  set_response(({"draught of flowers"}), ({"A wondrous concoction"
    +" made by the city herbalists, it rendered the drinker"
    +" euphoric and compliant, so that they could be lead easily to"
    +" their end on the altar of the Gods",
        "They always looked quite happy, it seemed to me. There were"
    +" rumours that some of the priests drank it too, straight from"
    +" the mushroom cups it came in. I never tried, though.",
        "Certainly the priests removed all that was in the temple,"
    +" when the %^CYAN%^downfall of our race%^RESET%^ came. If any"
    +" remains, it will be in the %^MAGENTA%^city"
    +" apothecary%^RESET%^. "}) );
  set_response(({"mushroom cup", "mushroom cups"}), ({"The"
    +" %^BOLD%^%^CYAN%^dr%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ug"
    +"%^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^t %^RESET%^%^CYAN%^of"
    +" %^BOLD%^%^MAGENTA%^f%^YELLOW%^l%^RESET%^%^MAGENTA%^o"
    +"%^BOLD%^%^MAGENTA%^we%^GREEN%^r%^MAGENTA%^s%^RESET%^ was"
    +" delivered to the priests in stoppered cups in"
    +" mushroom shapes, perhaps because mushrooms were involved in"
    +" its making. Something must have given it its special"
    +" qualities."}) );
  set_response(({"apothecary", "city apothecary"}), ({"The"
    +" main apothecary was one of the grander huts in the city, close"
    +" to the plaza."}) );
  set_response(({"slaves"}), ({"Those unable to pay their debts,"
    +" those guilty of crimes, the sons and daughters of enslaved"
    +" parents, those captured in battle or blood feud. All could"
    +" become slaves.",
       "Their work was vital to the working of our land, growing"
    +" food, building works and, of course, making the %^RED%^blood"
    +" gift %^RESET%^to the %^ORANGE%^Gods%^RESET%^"}) );
  set_response(({"sun lord", "an-tehp"}), ({"An-Tehp, the Sun Lord,"
    +" father of the Gods, has the task of carrying the sun on its"
    +" journey across the sky each day. The %^RED%^blood gift"
    +" %^RESET%^we gave to him gave him strength to continue with"
    +" his task",
       "I wonder how he has continued to manage it since."}),
    "puzzled" );
  set_response(({"lift the curse", "lift curse", "lift your curse"}),
    ({"The curse is so powerful, strong enough to seal the fates of"
    +" an entire nation. I can only think it is a punishment from"
    +" the %^ORANGE%^Gods%^RESET%^. But surely this curse did not"
    +" come from any of our Gods?",
       "I have not been able to commune with them since the"
    +" %^CYAN%^downfall of our people%^RESET%^. If you can find any"
    +" way to contact one of our %^ORANGE%^Gods%^RESET%^, perhaps a"
    +" way might be found to lift the curse."}) );
  set_response(({"hero of the flame", "inami", "hero of fire"}),
    ({"Inami was the hunter who tracked the sun across the sky to"
    +" its nighttime resting place, and there stole from it the"
    +" secret of fire. He had but nine fingers, having burned one of"
    +" them to the stump before he came up with the plan to steal"
    +" the fire using a brand from a tree."}) );
  set_response(({"nobach eri", "nobach eri", "jaguar"}), ({"Nobach"
    +" Eri the jaguar was the god of the underworld. Sometime man,"
    +" sometime jaguar, sometime light, sometime dark. He was a"
    +" figure of mystery and of great power. Like the greatest of"
    +" the%^CYAN%^ Tecqumin%^RESET%^ people, Nobach Eri survived"
    +" death by escaping from the %^CYAN%^underworld%^RESET%^"
    +" through an exit not available to average men and women."}) );
  set_response(({"quali", "jungle spirit"}), ({"Yes, he lives! It is"
    +" so exciting! But tell me how he is. Is his mind all that it"
    +" once was?",  "smile", "Told Jontar that Quali Lives"}) );
  set_response(({"quali", "jungle spirit"}), ({"Quali is the life"
           +" of the jungle. He lives among the trees. Perhaps he is"
    +" the trees.",
       "It is interesting that the Jungle has remained since the"
    +" %^CYAN%^downfall of my people%^RESET%^. Perhaps he is still"
    +" out there, somewhere."}) );
  set_response(({"teoctauoc", "feathered serpent"}),
       ({"Teoctauoc was the feathered serpent of the sky. He curled"
    +" around%^RED%^ An-Tehp%^RESET%^ as He lead the%^BOLD%^"
    +" %^YELLOW%^Sun%^RESET%^ across the Heavens."}) );
  set_response(({"taluc"}), ({"Taluc was the adviser of%^MAGENTA%^"
    +" Epithon%^RESET%^. He was the one who brought darkness into"
    +" the lives of the %^CYAN%^Tecqumin%^RESET%^, when he whispered"
    +" to %^MAGENTA%^Epithon%^RESET%^ of the creature whose name I"
    +" will not speak. Even after his plans were cast down, and the"
    +" ceature imprisoned, he made attempts to free the thing.",
     "I wonder what he is up to now." }) );
  set_response(({"creature imprisoned", "plans cast down",
                "plans were cast down", "creature was imprisoned"}),
   ({"The downfall of the %^CYAN%^Tecqumin%^RESET%^ people came when"
    +" %^ORANGE%^great spirits%^RESET%^ from far away came to wreak"
    +" vengeance on them for empowering the creature that%^BLUE%^"
    +" Taluc%^RESET%^ persuaded %^MAGENTA%^Epithon%^RESET%^ to"
    +" worship. The %^CYAN%^Tecqumin%^RESET%^ were laid low and the"
    +" creature imprisoned, but even in death %^BLUE%^Taluc%^RESET%^"
    +" has persisted in trying to find ways to release it. I wonder"
    +" what his latest plan might be."}) );
  set_response(({"jetstone" }),
    ({"Taluc's jetstone is was about the size of a small gourd, and"
    +" it was carved with the face of a jaguar, and inscribed with"
    +" many strange symbols."}),"thoughtful",
      ({"Heard of the Jetstone"}) );
  set_response(({"epithon", "prince" }), ({"Prince Epithon was the"
    +" ruler of the %^CYAN%^Tecqumin%^RESET%^ at the end of our days"
    +", the %^CYAN%^downfall of our race%^RESET%^.", "He took power"
    +" from the Empress while she was lost in grief for her dead"
    +" love."}) );
  set_response(({"empress", "mehaq"}), ({"Mehaq is our rightful"
    +" Empress, and should have remained our leader. It was a"
    +" terrible sadness that she fell into grief after the death of"
    +" her lover, and allowed %^BLUE%^Epithon%^RESET%^ to seize the"
    +" power he so greedily sought."}) );
  set_response(({"underworld", "Underworld"}),({"The underworld is"
    +" where the souls of the %^CYAN%^Tecqumin%^RESET%^ go after"
    +" death, guided by our %^ORANGE%^Gods%^RESET%^, including"
    +" %^BOLD%^%^BLACK%^Nobach Eri%^RESET%^, who is the only one who"
    +" knows the way back from the underworld to the land of the"
    +" living."}));
  set_response(({"no"}), ({"hmm"}), "quali_unwell" );

}
void chant(object speaker){
  force_me("say You must realise, it has been some time since I have"
    +" needed to recall the chants. Now, today is " + day(time())
    +", and the month is " + month(time()) +".");
  call_out("chant2",2, speaker);
}

void chant2(object speaker){
  if (objectp(speaker) && objectp(ETO) && present(speaker, ETO)){
    force_me ("emoteat " + speaker->QCN + " frowns at $N");
  }
  force_me("say That is right, isn't it?");
  call_out("chant3",1);
}

void chant3(){
  force_me("say Yes, yes of course it is. And the chant for a "
             + day(time())+" in " + month(time()) +" is:");
  call_out("chant4", 2, 0);
}

void chant4(int count){
  int day, num;
  day = query_day_number();
  num = day%sizeof(CHANTS);
  force_me("say " + CHANTS[num][count]);
  if (count <3){
    count ++;
    call_out("chant4", 2, count);
  }
}

void quali_unwell(){
  if (!asking_about_quali) return;
  force_me("say Quali is not His old tranquil self?"
   +" Then tell me, how is he, what is he like?");
}

void die(object ob) {
  object slayer, * attackers, ectoplasm;
  string slayer_name;
  int i, tmp_size, count;
  ectoplasm = new (OBJ + "ectoplasm");
  ectoplasm->set_spirit_name(TO->query_name());
  ectoplasm->move(tmp);
  attackers = query_attackers();
  count = sizeof(attackers);
  if (count > 0){
    for (i=0;i<count;i++){
      slayer = attackers[i];
      if (objectp(slayer) && slayer->is_player()){
        slayer_name = slayer->query_name();
        "/d/atoyatl/tecqumin_d.c"->kill_jontar(slayer_name);
      }
    }
  }
  ::die();
}
/*
   object money_ob;
   object *contents;
   string *currs;

   message("other_action", "%^RED%^"+query_cap_name()+
     " swirls, loses form and is banished%^RESET%^",
     environment(this_object()), ({ this_object()}));
   message("other_action", "%^BLUE%^A smeary residue is left behind",
     environment(this_object()), ({ this_object()}));
   tmp = ETO;
   tmp_size=sizeof(currs=query_currencies());
   if(tmp_size && has_value()) {
      money_ob = new("/std/obj/coins");
      for(i=0; i<tmp_size; i++) {
         money_ob->add_money(currs[i], query_money(currs[i]));
         add_money(currs[i], -query_money(currs[i]));
      }
      money_ob->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) {
      if(contents[i]->query_property("monsterweapon"))
         continue;
      else
         if(!contents[i]->query_short()) continue;
      else contents[i]->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) contents[i]->remove();
   if(TO->query_property("riding"))
      if(TO->query_owner() && objectp(TO->query_owner()))
         (TO->query_owner())->remove_pet(TO);

        if(TO->query_property("death effects"))
        {
                "/daemon/death_effects_d"->get_death_effect(TO);
        }
   remove();
}*/

void gasp(object speaker){
  object * people, room;
  string * quests;
  int i;
  room = ETO;
  if(!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
    for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Told Jontar that Quali Lives",quests)==-1){
      people[i]->set_mini_quest("Told Jontar that Quali Lives",10000000,"%^BOLD%^%^Told Jontar that Quali Lives\n");
    }
  }
  force_me("emote gasps and leans forward eagerly");
}

void alarmed(object speaker){
  force_me("emote looks up in alarm");
}

void puzzled(object speaker){
  force_me("emote looks puzzled for a moment");
}
void thoughtful(object speaker){
  force_me("emote lowers his gaze thoughtfully");
  if (objectp(speaker)){
    if (present("xxjetstonexx", speaker)){
      force_me("say Have you managed to obtain the Jetstone from"
        +" Taluc, somehow? If you have, please give it to me.");
    }
  }
}

void downfall(object speaker){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if(member_array("Knows about the downfall of the Tecqumin",
                                                    quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Knows about the downfall of the"
     +" Tecqumin",10000000,"%^BOLD%^Knows about the downfall of the Tecqumin!");
  }
}

void frown(){
  force_me("emote frowns");
}

void report(string str){
  "/daemon/reporter_d.c"->report("lujke", str);
}

void reply_func(string msg, object speaker){
  object room;
  string * quests;
  int i;
  report ("Trying %^BOLD%^%^BLUE%^Jontar's%^RESET%^ reply func");
  if (!interactive(speaker)){
    return;
  }
  room = ETO;
  if (!objectp(ETO)){
    force_me("emote looks disturbed by " + TO->QP + " surroundings,"
      +" which may well be broken");
  }
  report( "Attempting to process specific responses");
  if (!objectp(speaker)||!present(speaker, room)){
    return;
  }
  quests = speaker->query_mini_quests();
  if (member_array("Discovered the Madness of Quali", quests)==-1){
    report ("The speaker, " + speaker->QCN + " has not discovered the madness of QUali");






 //   force_me("say Quali was the spirit of the Jungle. ");









//    tell_room(ETO, "Quali's madness not discovered. Defaulting to baseline responses");
    base_reply_func(msg, speaker);
    asking_about_quali = 0;
    return;
  }
  report("The speaker HAS discovered the madness of Quali");
  msg = strip_colors(msg);
  msg = lower_case(msg);
  if ( interact("quali", msg) || interact ("jungle spirit", msg)
       || interact("spirit of the jungle", msg))
  {
    if (interact("kill", msg)||interact("slay", msg)||
        interact("destroy", msg) || interact("sacrifice", msg))
    {
      force_me("say No! To harm Quali would be a terrible thing to"
        +" do!");
      return;
   }
   if (member_array("Told Jontar of Quali's madness", quests)!=-1)
   {
     force_me("say It is too sad to learn of Quali's affliction. But"
       +" come! there may be a way to return him to his senses!");
    call_out("maddened",2);
    asking_about_quali = 0;
    asking_about_madness = 0;
    return;
    }
    if (asking_about_madness == 1
       || interact(" mad", msg)|| interact("maddened", msg)
       ||interact("madness", msg) || interact("crazy", msg)
       ||interact("crazed", msg) || interact("raving", msg)
       ||interact("insane", msg) || interact("insanity", msg)
       ||interact("lunatic", msg)|| interact(" loon", msg)
       ||interact("mind is lost", msg) || interact("agony", msg)
       ||interact("cursed", msg) || interact ("suffering", msg))
    {
      force_me("emote raises an eyebrow");
      force_me("say Maddened, you say? I am not surprised. I had"
        +" thought Him completely vanquished during the destruction"

        +" that accompanied the %^CYAN%^downfall of my people"
        +"%^RESET%^ But, if He lives, perhaps there may be a way to"
        +" return His senses to Him.");
      call_out("maddened",2);
      asking_about_madness = 0;
      return;
     }
    force_me("emote raises an eyebrow");
    force_me("say Quali lives? You have seen him?");
    call_out("lives",2);
    asking_about_madness = 0;
    return;
  }
  if (interact(" mad", msg)|| interact("maddened", msg)
    ||interact("madness", msg) ||interact("crazy", msg)
    ||interact("crazed", msg) ||interact("raving", msg)
    ||interact("insane", msg) ||interact("insanity", msg)
    ||interact("lunatic", msg)||interact(" loon", msg)
    ||interact("mind is lost", msg) || interact("agony", msg)
    ||interact("cursed", msg) || interact ("suffering", msg)){
    force_me("say Who is maddened?");
    asking_about_madness = 1;
    return;
  }

//  tell_room(ETO, "Nothing in the special Quali responses. Checking for baseline responses");
  asking_about_madness = 0;
  base_reply_func(msg, speaker);
}

void warn_unfettered2(){
  force_me("say %^BLUE%^The %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^ will most likely"
    +" make for the top of the great Ziggurat. From there, it can absorb"
    +" the power it needs to free itself completely and challenge the"
    +" %^MAGENTA%^Gods%^RESET%^.");
}

void warn_unfettered_loose(){
  force_me("say The prison is empty! %^BLUE%^The Un%^BLUE%^f%^MAGENTA%^e"
    +"%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^ has"
    +" got loose! If you would save these Realms, you must seek it out"
    +" and destroy it or drive it back.");
  call_out("warn_unfettered2", 2);
}

void congratulate_on_strengthened_seal2(object ob){
  object k;
  if (!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("emote sighs as he loses track of who he was speaking to");
    return;
  }
  force_me("say Some of the greatest treasures of the %^CYAN%^Tecqumin%^RESET%^"
    +" were preserved from the grasp of %^ORANGE%^Epithon%^RESET%^ when he overtook"
    +" Mehaq's rightful rule. Loyal servants hid them away in secret room in the ziggurat."
    +" Take this and"
    +" search the plinth of the green urn in the processional room for a notch. Insert it"
    +" there to gain access to the store.");
  k = new (OBJ + "pyramidkey");
  k->move(TO);
  tell_object(ob, query_name() + " gives you a " + k->query_name());
  tell_room( query_name() +  " gives something to " + ob->QCN);
  k->move(ob);
//  force_me("give crystal  to " + ob->query_name());
}

void congratulate_on_strengthened_seal(ob){
  force_me("say Strangers, that was very well done. You have served the safety of these Realms,"
   +" and kept the %^RESET%^%^BLUE%^Unfettered%^RESET%^ locked in its cage for"
   +" longer than it would otherwise have been. I would reward you, in the name of our Gods and yours.");
  call_out("congratulate_on_strengthened_seal2", 3, ob);
}

void lives(){
  object room, *people;
  string * quests;
  int i;
  room = ETO;
  if (!objectp(ETO)){
    force_me("emote looks disturbed by " + TO->QP + " surroundings,"
      +" which may well be broken");
   return;
  }
  force_me("emote gasps");
  call_out("lives2", 2);
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Told Jontar that Quali Lives",quests)==-1){
      people[i]->set_mini_quest("Told Jontar that Quali Lives",10000000,"%^BOLD%^Told Jontar that Qauli Lives");
    }
  }
}

void lives2(){
  force_me("say Tell me how he is! Does the spirit of the jungle"
    +" flow through him in tranquility and calm, the way it always"
    +" did?");
  asking_about_quali = 1;
}

void maddened(){
  object room, *people;
  string * quests;
  int i;
  room = ETO;
  if (!objectp(ETO)){
    force_me("emote looks disturbed by " + TO->QP + " surroundings,"
     +" which may well be broken");
    return;
  }
  force_me("say %^CYAN%^Taluc%^RESET%^, the betrayer of our people,"
    +" once owned an enchanted %^BOLD%^%^BLACK%^jetstone%^RESET%^"
    +" that he used to gather the %^CYAN%^life force%^RESET%^ from"
    +" those souls sacrificed to the one he brought to replace our"
    +" %^ORANGE%^Gods%^RESET%^. If you can obtain that %^BOLD%^"
    +"%^BLACK%^jetstone%^RESET%^ from him, by guile or by force, and"
    +" bring it to me, I believe it may be possible to use it to"
    +" restore the %^GREEN%^Spirit of the Jungle%^RESET%^ to His"
    +" natural state");
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Heard of the Jetstone",quests)==-1){
      people[i]->set_mini_quest("Heard of the Jetstone",10000000,"%^BOLD%^Heard of the Jetstone.");
    }
    if (member_array("Told Jontar of Quali's madness", quests)==-1){
      people[i]->set_mini_quest("Told Jontar of Quali's madness",10000000,"%^BOLD%^Told Jontar of Quali's madness");
    }
    if (member_array("Told Jontar that Quali Lives",quests)==-1){
      people[i]->set_mini_quest("Told Jontar that Quali Lives",10000000,"%^BOLD%^Told jontar that Quali Lives");
    }
  }
}

void  receive_given_item(object ob){
  if (ob->id("xxjetstonexx")){
    force_me("emote gasps");
    call_out ("receive_jetstone", 2, TP);
  }
}

void smile(){
  object * critters;
  string * quests;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  force_me("emote smiles");
  critters = all_living(ETO);
  count = sizeof(critters);
  for (i=0;i<count;i++){
    if (!interactive(critters[i])){
      continue;
    }
    quests = critters[i]->query_mini_quests();
    if (member_array("Told Jontar that Quali Lives", quests)==-1){
      critters[i]->set_mini_quest("Told Jontar that Quali Lives",10000000,"%^BOLD%^Told Jontar that Quali Lives");
    }
  }
}

void receive_jetstone(object giver){
  string giver_name;
  if (!objectp(giver)){return;}
  force_me("say You have obtained the Jetstone? That is wonderful"
    +" news!");
  force_me("say I am sure I should be able to make something with"
    +" this to heal Quali's mind. Give me a few moments...");
  giver_name = giver->query_true_name();
  call_out("create_healstone", 2, giver_name);
}

void create_healstone(string who){
  object healstone, jetstone;
  jetstone_givers += ({who});
  jetstone = present("jetstone", TO);
  if (!objectp(jetstone)){
    force_me("emote blanches");
    force_me("say I have lost the stone! This is terrible, I am so"
      +" sorry. I am sure I had it right here in my hands!");
    return;
  }
  jetstone->remove();
  healstone = new(OBJ + "healstone");
  healstone->move(TO);
  force_me("emote holds the %^BOLD%^%^BLACK%^jetstone%^RESET%^"
    +" carefully and murmrs a chant, as if to himself. Something"
    +" swirls in the depths of the stone.");
  call_out("give_healstone", 4, who);
}

void give_healstone(string who){
  force_me("emote smiles beatifically");
  force_me("say It is done");
  call_out("give_healstone2", 3, who);
}

void give_healstone2(string who){
  string action;
  force_me("say You shall have the healing stone, stranger. Take it"
    +" with my blessings and use it to begin the healing of our land"
    +". Help Quali to regain his mind");
  action = "give healing stone to " + who;
  force_me(action);
}

string query_chant(int num, int num2 ){
  if (num > sizeof(CHANTS)-1 || num<0 || num2 < 0 || num2 >3){
    return 0;
  }
  return CHANTS[num][num2];
}

int query_day_number(){
  //returns the number of the day in the year.
  int day,mon;
  day = date(time());
  switch (month(time()))
  {
  case "Winterstime":
    mon = 0;
    break;
  case "Renewal":
    mon = 1;
    break;
  case "Springstime":
    mon = 2;
    break;
  case "Plantingdays":
    mon = 3;
    break;
  case "Sundays":
    mon = 4;
    break;
  case "Summerstime":
    mon = 5;
    break;
  case "Growingdays":
    mon = 6;
    break;
  case "Harvestdays":
    mon = 7;
    break;
  case "Autumnstime":
    mon = 8;
    break;
  case "Colddays":
    mon = 9;
    break;
  }
  return (mon*10)+day;
}
