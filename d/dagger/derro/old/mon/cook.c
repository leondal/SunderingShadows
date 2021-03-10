//changed white smock for 2 new items
//Circe 4/26/04
//Turned his weapons into random drops - Cythera 8/05
#include <std.h>
#include "/d/dagger/derro/derrodefs.h"
  object ob;
  object obj;
  object ob2;
inherit MONSTER;

create(){
  ::create();
  set_name("giants cook");
  set_id(({"cook","human","giants cook"}));
  set_race("human");
  set_gender("male");
  set_short("Cook");
  set_long(
  "  This human turns from his pots to watch you.  You're not sure if its malice in his eyes or just insanity but his gaze is that of someone eyeing a tidbit for the table."
   "  He keeps a sharp eye on your movements and his presence makes you wonder why he's here of his own free will."
   "  In fact you wonder why he hasn't been thrown in a cook pot himself till you see the way he holds his matched set of curved blades one long, one short, as he works."
  );
  set_ac(0);
  set_size(2);
  set_body_type("human");
  add_attack_bonus(10);
  set_hd(30,15);
  set_class("thief");
  set_alignment(5);
  set_class("mage");
  set_mlevel("thief",30);
  set_mlevel("mage",30);
  set_thief_skill("hide in shadows",95);
  set_thief_skill("move silently",95);
  add_search_path("/cmds/thief");
  add_search_path("/cmds/mage");
  set_scrambling(1);
  set_stats("strength",19);
  set_stats("dexterity",19);
  set_guild_level("thief",20);
  set_guild_level("mage",20);
  obj=new(OBJ"wakizashi.c");
if(random(4))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
  command("wield wakizashi");
  obj=new(OBJ"tanto.c");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
  command("wield tanto");
//  new(OBJ"whitesmock.c")->move(TO);
//  command("wear smock");
  if(!random(4)){
     new(OBJ"ramjerkin")->move(TO);
     command("wear jerkin");
  }else{
     new(OBJ"whitebliaut")->move(TO);
     command("wear bliaut");
  }
  if(!random(6)) {
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
  "Cook dips a spoon in a massive pot then tastes the greyish slime on the spoon",
  "%^RED%^Oven door bangs open and the cook rushes over to beat some writhing figures back into it before shutting and latching it!%^RESET%^",
  "Cook mumbles something about needing parsley.",
  "Cook eyes your limbs and giggles to himself.",
  "%^BLUE%^Suddenly the cook throws a large mushroom in the air and dices it with his swords before it can land!%^RESET%^",
  }),0);
  remove_property("swarm");
}

void stab_derro(object obj)
{
  command("say I said not TILL SUPPER!");
  command("stab "+obj->query_name());
  if(objectp(obj)) obj->die();
  command("offerall");
  command("offerall");
  return;
}

init()
  {
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

int xstab(string str)
  {
  if(str=="cook"){
  object ob;
  write("You sneak around the cook and try to stab him but as you do he moves to the side as he opens the oven.\n");
  write("%^BOLD%^%^RED%^With a little shove he sends you barreling into the open OVEN!%^RESET%^");
  TP->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
  return 1;
  }
}
int xrush(string str)
  {
  if(str=="cook"){
  write("The cook looks with distain as you rush maddly towards him.\n");
  write("%^BOLD%^%^RED%^At the last second he steps aside and trips you into the open oven he was standing in front of!");
  TP->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
 return 1;
  }
}
int xcrit(string str)
  {
  if(str=="cook"){
  write("You slide up to the cook and try to sneak in a deadly blow.\n");
  write("%^BOLD%^%^RED%^The cook grins just as you try to land the blow and sidesteps easily, and gives you a little push as your're off balance right into the OVEN!");
  TP->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
  new(MON"firesnake.c")->move(ROOMS"oven.c");
  return 1;
  }
}
int cook(string str)
  {
  ob=present("frozen cow",TP);
  if(!ob) return notify_fail("\nThe cook thinks you shouldn't try anything and shoos you away from the kitchen.\n");
  ob->remove();
  message("environment",
  "%^BOLD%^WHITE%^The cooks eyes light up and he grabs the frozen cow and tosses it in the oven."
  "\n"
  "%^BOLD%^%^RED%^You hear a sizzling from the oven and in no time at all the cook pulls the cooked beef out and tosses it to "+TPQCN+" with a grin."
  "\n"
  ,environment(TO));
  new(OBJ"cocow.c")->move(TP);
  return 1;
}
int ask(string str){
  if((str=="about captive")||(str=="about king")){
  message("environment","\n Ahh, but of course.  My skills are vivaled by noone, and the King and that captive know what they're missing.   Dont really care about em though, and I'ld a just as well serve the %^BLUE%^Derro%^RESET%^ as anyone.   Means nothing to me who my employer is, although the giants showed special appreaciation for a cooked %^BOLD%^cow%^RESET%^ now and then that hasnt been rivaled by any others."
  ,environment(TO));
  return 1;
}
  if((str=="about food")){
  message("environment","\n%^MAGENTA%^Giants cook says:  %^RESET%^Ah, but of course you'ld like to sample my cooking.  Feel free to %^BOLD%^buy%^RESET%^ some.",environment(TO));
  return 1;
}
  if((str=="about cow")){
  message("environment","\n Roast whole cow is one of my specialties.   I know we got one left in the %^BOLD%^freezer%^RESET%^ to the north.  Go get it and bring it back and I'll COOK it."
  ,environment(TO));
  return 1;
  }
  if((str=="about derro")||(str=="about Derro")){
  message("environment","\n Odd little creatures seem to like mushrooms and fungus in everthing, but its a challenge Im up to."
  "  The occasional piece of meat they bring in kicking and squirming seems to add a little spice to the pot!"
  "\n\n Cook looks you over and grins."
  ,environment(TO));
  return 1;
  }
  if((str=="about cook")){
  message("environment",
  "\nCook flexes his muscles."
  "\n"
  "%^MAGENTA%^Cook says:%^RESET%^ Ive done alot of training to get to where Im at now.   Lots of anatomy lessons with my lessons on seasonings and spices.   All the better to remove those tasty limbs for my dishes."
  "\n\nCook takes a second to ponder your limbs."
  "\n%^MAGENTA%^Cook says:%^RESET%^ Heh, but enough of me, what do you want?   If you brought me something for someone else I would COOK it for ya Im sure, or you could BUY something that I got around that you could eat..   Never a cook who doesnt like to show off you know."
  ,environment(TO));
  return 1;
  }
  if((str=="about freezer")){
  message("environment","%^MAGENTA%^Cook says:%^RESET%^"
  "  Best watch your self in there.  The door sticks sometimes and the is a key but I seem to have misplaced it.  Maybe a %^BLUE%^Derro%^RESET%^ ran off with it."
  ,environment(TO));
  return 1;
  }
  if(str=="about way out"){
  message("environment","Cook grins evilly.\n"
  "%^MAGENTA%^Cooks says:%^RESET%^Yah I know a way out but it'll cost ya.  Just pay and I'll get you out."
  , environment(TO));
  return 1;
  }
  if((str=="about savant")||(str=="about derro savant")){
  message("environment","%^MAGENTA%^Cook says:%^RESET%^ The savant is here after some magical treasure or another.   You know there used to be two savants leading this band but the %^BLUE%^second savant%^RESET%^ went and got hisself killed."
  ,environment(TO));
  return 1;
  }
    if((str=="about second savant")){
  message("environment","%^MAGENTA%^Cook says:%^RESET%^  That second savant went to go try to %^BLUE%^imprison%^RESET%^ a elemental or something and it wasted him."
  ,environment(TO));
  return 1;
  }
  if((str=="about imprison")){
  message("environment","%^MAGENTA%^Cook says:%^RESET%^ Sure he had a chain that could be used to chain specific elementals to bad he picked the wrong one, Heh.."
  ,environment(TO));
  return 1;
  }
}
int pay(string str){
  if((TP->query_money("platinum"))<2000) return notify_fail("Cook wants 2000 platinum to let ya out.");
  TP->add_money("platinum",-2000);
  say(""+TPQCN+" and the cook discus something in hushed terms.");
  say("%^MAGENTA%^Cook says:%^RESET%^What the hell is that?\n");
  say("When you turn back to look the cook and "+TPQCN+" have left.");
  say("The cook pops back in next time you spin around to check for them.");
  write("The cook takes your 2000 platinum with a grin and then everything goes black!");
  TP->move_player(ROOMS"a1.c");
  return 1;
}
int buy(){
  if((TP->query_money("gold"))<25) return notify_fail("Cook says:You need at least 25 gold to cover the cost of my expenses.\n");
  TP->add_money("gold",-25);
  write("The cook wanders around his kitchen, tossing things in pans and slicing at questionable pieces of meat.  He pauses for a second and leaves something for you on the counter before turning back to his work.");
  say("The cook wanders around his kitchen tossing things in pands and slicing at questionable pieces of meat.   He pauses for a second and leaves something for "+TPQCN+" on the counter before turning back to his work.");
  new(OBJ"food.c")->move(ETO);
  return 1;
  }
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(present("beef",TO)){
  tell_room(environment(TO),"%^MAGENTA%^Cook says:%^RESET%^ I dont want it.  If you want it cooked just try 'cook'");
  command("drop beef");
  }
}
