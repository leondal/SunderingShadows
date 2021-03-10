// Changed the heartbeat because it was adding 50MR, instead of resetting it to 50MR. Nienne, 11/04 //
#include <std.h>
#include <../derrodefs.h>
inherit WEAPONLESS;

  int chained;
  object rex;
void create(){
  ::create();
  set_id(({"lava rex","elemental","para-elemental","rex"}));
  set_name("lava para-elemental");
  set_short("%^RESET%^%^RED%^Lava Rex%^RESET%^");
  set_long(
  "  This massive creature rears out of the lava bed a creation itself of the combination of fire and earth."
  "  Its skin is molted black and red like the surface of cooling lava, resembling scales and his eyes glow like pools of pure molten silver."
  "   It looms nearly 50 feet tall out of the lava beds with no legs just a colum of lava that forms into a massive reptilian head and tiny forarms."
  );
  set_hd(61,5);
  set("aggressive",20);
  set_hp(1300);
  set_race("para-elemental");
  set_size(3);
  set_max_hp(1300);
   add_limb("upper torso","upper torso",0,0,0);
   add_limb("left clawed appendage","upper torso",0,0,0);
   add_limb("right clawed appendage","upper torso",0,0,0);
   add_limb("head","upper torso",0,0,0);
   add_limb("tooth filled maw","head",0,0,0);
   add_limb("lower lava torso","upper torso",0,0,0);
  set_ac(-16);
  set_property("magic",1);
  set_property("no bows",1);
  set_mob_magic_resistance("average");
  set_property("no dominate",1);
  set_property("no death",1);
  set_property("no steal",1);
  set_exp(50000);
  set_attacks_num(1);
  set_attack_limbs(({"toothed maw","right clawed appendage","searing lava","left clawed appendage"}));
  set_damage(10,10);
  set_funcs(({
  "maul",
  "smash",
  "sweep"
  }));
  set_func_chance(40);
}
void sweep(object targ){
  object *heat;
  int i,j;
  if(!present(targ)) return;
  tell_object(targ,"%^BOLD%^%^RED%^The elemental sweeps a huge wave of lava over the walkway which carries you into the lava!");
   tell_room(environment(targ),"%^BOLD%^%^RED%^The elemental sweeps a huge wave of lava over the walkway which nearly knocks you off your feet but carries "+targ->QCN+" screaming away with it!",targ);
  targ->do_damage("torso",random(50)+50);
  targ->set_paralyzed(random(10)+20,"You struggle to catch your footing in the lava sea!");
  targ->move(ROOMS"lavapit.c");
  heat=all_living(ETO);
  rex=(present("lava rex",ETO));
  heat-=({rex});
  j=sizeof(heat);
  for(i=0;i<j;i++) {
// fixed this from TP->avatarp() return 1 which was totally wrong.  *Styx*
// 11/23/03 last change was 3/00 
    if(heat[i]->query_true_invis()) continue;
    tell_object(heat[i],"%^RED%^The lava splashes up on your legs as the wave passes!");
    heat[i]->do_damage("torso",random(20)+15);
    heat[i]->add_attacker(TO);
    heat[i]->continue_attack();
  }
}
void maul(object targ){
  if(!present(targ)) return;
  tell_object(targ,"%^BOLD%^%^RED%^The elemental suddenly moves with surprising speed and grabs you in its jaws and lifts you high above the path while chewing on you!\n  He slams you back down on the path!");
  tell_room(environment(targ),"%^BOLD%^%^RED%^The elemental suddenly lunges forward and grabs "+targ->QCN+" and lifts him screaming high above the path then SLAMS him back down ripping and chewing the whole time!!",targ);
  targ->do_damage("torso",random(50)+75);
  targ->set_paralyzed(random(20)+1,"\n%^BOLD%^%^WHITE%^You struggle for your breath!");
}
void smash(object targ){
  if(!present(targ)) return;
  tell_object(targ,"%^BOLD%^%^WHITE%^The shimmering pools of molten silver that is the elementals eyes hold you entranced!\n\n You lower your weapon and watch in awe as the creature raises itself to its full height and then %^RED%^SLAMS %^WHITE%^his body down on you!"); 
  tell_room(environment(targ),"%^BOLD%^%^WHITE%^"+targ->QCN+" suddenly stares blankly at the huge blazinge creature which raises itself to its full height of some 60 feet and then %^RED%^SLAMS%^WHITE%^ itself down on their motionless body!",targ);
  targ->do_damage("torso",random(10)+100);
  targ->set_paralyzed(random(5)+3,"\n%^BOLD%^%^WHITE%^You struggle to regain your footing and your breath after that blow!");
}
void die(mixed ob){
  message("environment","%^BOLD%^The elemental sways back for a second.%^RESET%^\n\n"
  "%^BOLD%^%^RED%^  The massive being starts to run at the edges and thrashes feebly as the lava reclaims its own!%^RESET%^\n"
  "\n%^BOLD%^%^WHITE%^You see something emerge from the lava mass but then it sinks into the lava with the beast far out on the lava sea to the east.%^RESET%^"
  ,environment(TO));
  message("info",
  "%^BOLD%^%^RED%^A great heat builds and then settles in the ground beneath your feet as the rumblings of a lava pool are quieted far below you!%^RESET%^"
  ,users());
  switch(random(100)) {
    case 0..49:
        new(OBJ"emerald.c")->move(TO);
        break;
    case 50..99:
        new(OBJ"crimson_bracers")->move(TO);
        break;
  }
  TO->move(ROOMS"c29.c");
  ::die(ob);
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(TO->query_property("magic resistance")<50) {
    TO->remove_property("magic resistance");
    TO->set_mob_magic_resistance("average");
  }
  if(query_hp()<1000){
     write("You draw on the fire and molten lava to heal yourself");
     tell_room(ETO,"%^BOLD%^%^RED%^The elemental draws power from the lava beneath it!%^RESET%^");
     TP->add_hp(random(10)+5);
  }
}

void chain(string str){
  object ob;
  if (TP->query_bound() || TP->query_unconscious()){
    write("You squirm about");
    tell_room(ETO, TPQCN+" squirms about.");
    return;
  }
  ob=present("blackened chains",TP);
  if(ob){
    if(chained==1) {
	write("%^RED%^The elemental avoids the second chains easily.");
	return;
    }
    chained=1;
    write("%^RED%^The elementals sees the chains and almost seems as if it's laughing.");
    write("The chains leap from your hands and try to wrap themselves around the elemental and he struggles to break them to attack!");
    ob->remove();
    tell_room(ETO,"%^RESET%^%^RED%^"+TPQCN+" pulls out a set of blackened chains and throws them at the elemental who tries in vain to avoid them!",TP);
    TO->force_me("kill "+TPQN);
    TO->set_paralyzed(50,"You fight the chains!");
    return;
  }
}

init(){
  ::init();
  add_action("chain","chain");
    if(TP->query_invis()  && !avatarp(TP)){
    tell_room(ETO,"%^BOLD%^RED%^The elemental surges forwards to attack!");
    kill_ob(TP,1);
  }
}
