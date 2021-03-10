//updated to current code ~Circe~ 7/31/19
//changed white smock for 2 new items
//Circe 4/26/04
//Turned his weapons into random drops - Cythera 8/05

#include <std.h>
#include "/d/dagger/derro/derrodefs.h"

inherit MONSTER;

object ob;
object obj;
object ob2;

void create(){
   ::create();
   set_name("cook");
   set_id(({"cook","human","giants cook","giant's cook"}));
   set_race("human");
   set_gender("male");
   set_short("Cook");
   set_long("This aging man is thick around the middle and has beady black eyes.  You're not sure if you see malice or madness in his eyes, but his gaze is that of someone eyeing a tidbit for the table.  He keeps a sharp eye on your movements, and his presence makes you wonder why he's here of his own free will.  In fact, you wonder why he hasn't been thrown in a cookpot himself till you see the way he holds his matched set of curved blades - one long, one short - as he works.");
   set_ac(0);
   set_body_type("human");
   add_attack_bonus(10);
   set_hd(30,15);
   set_class("thief", 30);
   set_alignment(5);
   set_class("mage", 30);
   set_skill("stealth",40);
   add_search_path("/cmds/thief");
   set_scrambling(1);
   set_stats("strength",19);
   set_stats("dexterity",19);
   obj=new(OBJ"wakizashi.c");
   if(random(4)){
      obj->set_property("monsterweapon",1);
   }
   obj->move(TO);
   command("wield wakizashi");
   obj=new(OBJ"tanto.c");
   if(random(3)){
      obj->set_property("monsterweapon",1);
   }
   obj->move(TO);
   command("wield tanto");
   if(!random(4)){
      new(OBJ"ramjerkin")->move(TO);
      command("wear jerkin");
   }else{
      new(OBJ"whitebliaut")->move(TO);
      command("wear bliaut");
   }
   if(!random(6)){
      new(OBJ"noblemanspants")->move(TO);
      command("wear pants");
   }
   add_money("gold",1000);
   set_hp(300);
   set_mob_magic_resistance("average");
   set_exp(15000);
   set_spell_chance(30);
   set_spells(({"scorcher","acid arrow","acid orb","shout"}));
   set_emotes(5,({
      "Cook dips a spoon in a massive pot, then tastes the grayish slime on the spoon.",
      "%^RED%^The oven door bangs open, and the cook rushes over to beat some writhing figures back into it before shutting and latching it!%^RESET%^",
      "Cook mumbles something about needing parsley.",
      "Cook eyes your limbs and giggles to himself.",
      "%^BLUE%^Suddenly the cook throws a large mushroom in the air and dices it with his swords before it can land!%^RESET%^"
   }),0);
   remove_property("swarm");
}

void stab_derro(object obj){
   force_me("say I said not TILL SUPPER!");
   force_me("stab "+obj->query_name());
   if(objectp(obj)) obj->die();
   force_me("offerall");
   force_me("offerall");
   return;
}

void init(){
   ::init();
   add_action("xstab","stab");
   add_action("buy","buy");
   add_action("xcrit","crit");
   add_action("xrush","rush");
   add_action("cook","cook");
   add_action("ask","ask");
   add_action("pay","pay");
   ob=(present("derro",ETO));
   if(ob){ call_out("stab_derro",1,ob); }
}

int xstab(string str){
   object myroom;
   if(str=="cook"){
      object ob;
      tell_object(TP,"You sneak around the cook and try to stab him, but as you do, he moves to the side as he opens the oven.");
      tell_object(TP,"%^BOLD%^%^RED%^With a little shove, he sends you barreling into the open OVEN!%^RESET%^");
      tell_room(ETO,"As "+TPQCN+" tries to stab the cook, he spins out of the way and shoves "+TP->QO+" into the oven!",TP);
      myroom=find_object_or_load(ROOMS"oven.c");
      if(!objectp(myroom)){
         tell_object(TP,"An error occurred! Please <game bug here> and tell us the Derro cook errored when you stabbed.");
         return 1;
      }
      TP->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      return 1;
   }
}

int xrush(string str){
   object myroom;
   if(str=="cook"){
      tell_object(TP,"The cook looks with distain as you rush maddly towards him.");
      tell_object(TP,"%^BOLD%^%^RED%^At the last second, he steps aside and trips you into the open oven he was standing in front of!%^RESET%^");
      tell_room(ETO,"As "+TPQCN+" tries to rush the cook, he sidesteps and shoves "+TP->QO+" into the oven!",TP);
      myroom=find_object_or_load(ROOMS"oven.c");
      if(!objectp(myroom)){
         tell_object(TP,"An error occurred! Please <game bug here> and tell us the Derro cook errored when you rushed.");
         return 1;
      }
      TP->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      return 1;
   }
}

//I'm not even sure crit is still in the game, but it doesn't hurt to leave it.
int xcrit(string str){
   object myroom;
   if(str=="cook"){
      tell_object(TP,"You slide up to the cook and try to sneak in a deadly blow.");
      tell_object(TP,"%^BOLD%^%^RED%^The cook grins just as you try to land the blow and sidesteps easily, giving you a little push right into the OVEN!%^RESET%^");
      tell_room(ETO,"As "+TPQCN+" tries to crit the cook, he sidesteps and shoves "+TP->QO+" into the oven!",TP);
      myroom=find_object_or_load(ROOMS"oven.c");
      if(!objectp(myroom)){
         tell_object(TP,"An error occurred! Please <game bug here> and tell us the Derro cook errored when you crit.");
         return 1;
      }
      TP->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      new(MON"firesnake.c")->move(myroom);
      return 1;
   }
}

int cook(string str){
   ob=present("frozen cow",TP);
   if(!ob) return notify_fail("The cook thinks you shouldn't try anything and shoos you away from the kitchen.\n");
   ob->remove();
   tell_room(ETO,"%^BOLD%^%^WHITE%^The cook's eyes light up, and he grabs the frozen cow and tosses it in the oven.\n%^BOLD%^%^RED%^You hear a sizzling from the oven, and in no time at all the cook pulls the cooked beef out and tosses it to "+TPQCN+" with a grin.%^RESET%^",TP);
   tell_object(TP,"%^BOLD%^%^WHITE%^The cook's eyes light up, and he grabs the frozen cow and tosses it in the oven.\n%^BOLD%^%^RED%^You hear a sizzling from the oven, and in no time at all the cook pulls the cooked beef out and tosses it to you with a grin.%^RESET%^",TP);
   new(OBJ"cocow.c")->move(TP);
   return 1;
}

int ask(string str){
   tell_object(TP,"What would you like to ask him about? Simply say it out loud, and he'll respond.");
   return 1;
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

//Changing him to use catch_say, but adding a hint under ask for old players
void reply_func(string msg, object who){
   object current;
   object obj;
   string name;
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1){
      force_me("emote waves his blades around and cackles maniacally.");
      force_me("say What did you want?");
      return;
   }
   if(strsrch(msg,"captive") != -1 || strsrch(msg,"king") != -1 ||strsrch(msg,"Captive") != -1 || strsrch(msg,"King") != -1){
      force_me("say Ahh, but of course.  My skills are rivaled by none, and the king and that captive know what they're missing.  Don't really care about 'em though, and I'd just as well serve the %^BLUE%^Derro%^RESET%^ as anyone.  Means nothing to me who my employer is, although the giants showed special appreciation for a cooked %^BOLD%^cow%^RESET%^ now and then that hasn't been rivaled by any others.");
      return 1;
   }
   if(strsrch(msg,"food") != -1){
      force_me("say Ah, but of course you'd like to sample my cooking.  Feel free to %^BOLD%^buy%^RESET%^ some.");
      return 1;
   }
   if(strsrch(msg,"cow") != -1){
      force_me("say Roast whole cow is one of my specialties.  I know we got one cow carcass left in the %^BOLD%^freezer%^RESET%^ to the north.  Go get it and bring it back, and I'll COOK it.");
      return 1;
   }
   if(strsrch(msg,"derro") != -1 || strsrch(msg,"Derro") != -1){
      force_me("say Odd little creatures ... seem to like mushrooms and fungus in everthing, but it's a challenge I'm up to.  The occasional piece of meat they bring in kicking and squirming seems to add a little spice to the pot!");
      force_me("emote looks you over and grins.");
      return 1;
   }
   if(strsrch(msg,"cook") != -1 || strsrch(msg,"Cook") != -1){
      force_me("emote flexes his muscles.");
      force_me("say I've done a lot of training to get to where I'm at now.  Lots of anatomy lessons with my lessons on seasonings and spices.  All the better to remove those tasty limbs for my dishes.");
      force_me("emote takes a second to ponder your limbs.\n\n");
      force_me("say Heh, but enough about me, what do you want?  If you brought me something for someone else, I would COOK it for ya, I'm sure, or you could BUY something that I got around that you could eat.  Never met a cook who didn't like to show off, you know.");
     return 1;
   }
   if(strsrch(msg,"reezer") != -1){
      force_me("say Best watch yourself in there.  The door sticks sometimes, and there is a key, but I seem to have misplaced it.  Maybe a %^BLUE%^Derro%^RESET%^ ran off with it.");
      return 1;
   }
   if(strsrch(msg,"way out") != -1){
      force_me("emote grins evilly.");
      force_me("say Yeah, I know a way out, but it'll cost ya.  Just pay, and I'll get you out.");
      return 1;
   }
   if(strsrch(msg,"avant") != -1){
      force_me("say The savant is here after some magical treasure or another.  You know, there used to be two savants leading this band, but the %^BLUE%^second savant%^RESET%^ went and got himself killed.");
      force_me("say He went to go try to %^BLUE%^imprison%^RESET%^ an elemental or something, and it wasted him.");
      return 1;
   }
   if(strsrch(msg,"mprision") != -1){
      force_me("say Sure, he had a chain that could be used to chain specific elementals. Too bad he picked the wrong one, heh...");
      return 1;
   }
}

int pay(string str){
   if((TP->query_money("platinum"))<2000) return notify_fail("Cook wants 2000 platinum to let ya out.");
   TP->add_money("platinum",-2000);
   tell_room(ETO,""+TPQCN+" and the cook discus something in hushed terms.",TP);
   force_me("say Whatt the hell is that?");
   tell_room(ETO,"When you turn back to look, the cook and "+TPQCN+" have left.",TP);
   tell_room(ETO,"The cook pops back in next time you spin around to check for them.",TP);
   tell_object(TP,"The cook takes your 2000 platinum with a grin, and then everything goes black!");
   TP->move_player(ROOMS"a1.c");
   return 1;
}

int buy(){
   if((TP->query_money("gold"))<25) return notify_fail("%^RESET%^%^MAGENTA%^Cook says: %^RESET%^You need at least 25 gold to cover the cost of my expenses.\n");
   TP->add_money("gold",-25);
   tell_object(TP,"The cook wanders around his kitchen, tossing things in pans and slicing at questionable pieces of meat.  He pauses for a second and leaves something for you on the counter before turning back to his work.");
   tell_room(ETO,"The cook wanders around his kitchen tossing things in pands and slicing at questionable pieces of meat.  He pauses for a second and leaves something for "+TPQCN+" on the counter before turning back to his work.",TP);
   new(OBJ"food.c")->move(ETO);
   return 1;
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("beef",TO)){
   force_me("say I don't want it.  If you want it cooked, just try <cook>.");
   command("drop beef");
   }
}
