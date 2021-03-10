#include <std.h>
inherit "/std/monster";

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create() {
  ::create();
  set_name("toad");
  set_id(({"toad","giant toad","king toad","bufo","Bufo","King Bufo"}));
  set_race("amphibian");
  set_body_type("reptile");
  set_gender("male");
  set_property("water breather",1);

  set_short("King Bufo, Lord of Cor'Alu Lake");
  set_long("%^BOLD%^%^GREEN%^Bufo the Toad, self titled King of "+
"%^RESET%^%^CYAN%^Cor'Alu Lake%^BOLD%^%^GREEN%^, wears a dainty "+
"%^YELLOW%^golden crown %^GREEN%^upon his large wart covered "+
"head.  The crown is held down by several thick strands of vine, "+
"that overwhelm the tiny circlet but keep it securely tied to "+
"his head.  Sickly %^RESET%^%^ORANGE%^b%^GREEN%^r%^BOLD%^"+
"%^BLACK%^o%^RESET%^%^GREEN%^w%^ORANGE%^n-g%^GREEN%^r%^BOLD%^"+
"%^BLACK%^e%^RESET%^%^GREEN%^e%^ORANGE%^n %^BOLD%^%^GREEN%^skin "+
"drapes his rotund body in thick folds that roll with %^BLACK%^"+
"boils %^GREEN%^and %^RESET%^%^CYAN%^pox-marks %^BOLD%^%^GREEN%^"+
"from his skinny legs to the large protruding head.  A constant "+
"%^BLACK%^ichor %^GREEN%^leaks from these sores and clouds the "+
"water around him.  Thick bony ridges rise over large %^YELLOW%^"+
"yellow eyes %^GREEN%^that flank a pronounced triangle-shaped "+
"snout.  His wide jaw hangs open slightly, exposing a thick "+
"%^BLACK%^gray tongue %^GREEN%^that lashes out now and again."+
"%^RESET%^");

  set_alignment(6);
  set_body_type("reptile");
  set_size(2);
  set_hd(3,2);
  set_stats("dexterity",12);
  set_stats("strength",16);
  set_overall_ac(8);
  set_hp(random(15)+80);
  set_exp(100+random(20));
  add_money("gold",random(80));
  add_money("silver",random(80));
  add_money("copper",random(20));
  set_wimpy(3);
  set_emotes(1,({"%^BOLD%^%^GREEN%^Bufo blinks his large %^YELLOW%^"+
"yellow eyes %^GREEN%^and peers about the %^BLACK%^murky water"+
"%^GREEN%^.%^RESET%^","%^CYAN%^Bufo adjusts his %^YELLOW%^crown "+
"%^CYAN%^then preens at his reflextion in a nearby piece of metal."+
"%^RESET%^","%^BOLD%^%^BLUE%^Bufo shoots his %^BLACK%^tongue "+
"%^BLUE%^out and snares a small %^RESET%^fish%^BOLD%^%^BLUE%^ that "+
"dared to investigate the King's home.%^RESET%^"}), 0 );
  
  force_me("speech croak deeply");
  set_funcs(({"king_special"}));
  set_func_chance(20);
  set("aggressive","agg_func");
}

void agg_func(){
  if(TP->query_invis()){return;}
    force_me("emote flicks his tongue out and tests the water.");
    force_me("say You are not one of my subjects! Guards! Remove "+
"these interlopers!");
    force_me("say Guards!  Guards?!");
    force_me("emote looks about, turning his large head left, "+
"then right, looking a bit confused.");
    force_me("say Fine! I will evict them myself!");
    force_me("kill "+TP->query_name());
  return;
}

int king_special(object targ) {
  switch(random(3)){
    case 0..1:
    tell_object(targ,"%^BOLD%^%^BLACK%^King Bufo's tongue lashes "+
"out, snareing you!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^BLACK%^King Bufo's tongue lashes out "+
"at "+targ->QCN+"!%^RESET%^",targ);
    targ->do_damage("torso",random(4)+4);
    targ->set_paralyzed(random(12),"%^BOLD%^%^BLACK%^You're still "+
"trying to escape the %^GREEN%^sticky goo%^BLACK%^ that King "+
"Bufo's tongue left all over you!%^RESET%^");
    break;

    case 2:
    tell_object(targ,"%^RESET%^%^GREEN%^You get too close to the "+
"toad's pox-marked skin and some of the %^BLACK%^%^BOLD%^ichor"+
"%^RESET%^%^GREEN%^rubs off on you.\n%^BOLD%^%^BLACK%^You "+
"don't feel so good.%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->QCN+" looks rather "+
"sickly as they brush up against the toad's sore ridden "+
"body!%^RESET%^",targ);
    targ->do_damage("torso",random(10));
    break;
  }
return 1;
}

void die(object ob){
  tell_room(ETO,"%^BOLD%^%^GREEN%^King Bufo hops one last time, "+
"then croaks!%^RESET%^");
  new("/d/newbie/rooms/lake/atomiecrown.c")->move(TO);
  ::die(ob);
}
