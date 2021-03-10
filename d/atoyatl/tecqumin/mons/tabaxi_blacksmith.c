//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
#define THANX ({"Thanksh meeshter, yerra diamond", "Jusht one more liddle one, then",\
             "Ayve a feeling theesh one will hit the shpot!", "Ayll get the nexsht ones",\
             "You're my besht fren, you are. I lovesh you",\
             "Theesh one ish for all thee girlsh I've loved before", "More tecquila!",\
             "Wheresh thee salt an lime?", "You're all wunnerful people",\
             "Salud, amor y pesetas, y tiempo para gastarlas!",\
             "Healths, lovesh, an money, an time to shpend it!", "Down thee hatches!"})
inherit MOB + "tabaxi";


string short_desc();

void create()
{
      ::create();
  	set_name("Graciela");
  	set_id(({"tabaxi", "humanoid", "tabaxi blacksmith", "blacksmith"}));
  	set_short( (:TO, "short_desc" :));
      set_gender("female");
      set_long( (:TO, "long_desc":) );
  	set_race("tabaxi");
  	set_body_type("humanoid");
  	set_hd(27,12);
  	set_size(2);
  	set("aggressive",6);
	set_class("fighter");
	set_mlevel("fighter",27);
	set_level(27);
	set_guild_level("fighter",27);
   	set_hp(random(50)+250);
   	set_exp(5500);
	set_max_level(27);
	set_property("swarm",1);
  	set_overall_ac(-1);
  	set_alignment(4);
      set_property("full attacks",1);
      add_intox(5000);
      set_emotes(2, ({"%^MAGENTA%^Graciela says%^RESET%^: I know thish leetle plashe...",
               "%^MAGENTA%^Graciela says%^RESET%^: My home ish yoursh. Eef I can find eet", 
               "Graciela sings a little song about pigs", 
               "Graciela mutters something about the fluffy bunnees", 
               "%^MAGENTA%^Graciela says%^RESET%^: Theesh time Aym not gonna drink sho much", 
               "%^MAGENTA%^Graciela says%^RESET%^: Why didsh the tabaxi hit heesh wife over thee head"
               +" with a bottle? Tequila!", 
               "%^MAGENTA%^Graciela says%^RESET%^: All thee godsh preserve ush!", 
               "%^MAGENTA%^Graciela says%^RESET%^: Aquello es bueno que bien acaba", 
               "%^MAGENTA%^Graciela says%^RESET%^: Quien juega con fuego, se quema los dedos",
               "%^MAGENTA%^Graciela says%^RESET%^: Only thee very wisesht people know how wise eet ees"
               +" not to be too wise. And they are too wishe to know eet.",  
               "Graciela looks around for another drink", "Graciela slumps forward, sleepily",
               "%^MAGENTA%^Graciela says%^RESET%^: My name eesh Graciela and I am an alca, an alaca,"
               +" an acala -  a blacksmith"}), 0);
}

void init(){
  ::init();
}

string short_desc(){
  string desc;
  if (query_intox()>0){
    desc =  "A muscular, but dishevelled looking female tabaxi";
  } else {
    desc = "Graciela, the tabaxi blacksmith";
  }
  return desc;
}

void catch_say(string msg){
   if (!interactive(TP)){
     return;
   }
   call_out("reply_func",1,msg,TP);
}

string long_desc(){
  string desc;
  if (query_intox()>1){
    desc = "%^ORANGE%^This large female tabaxi looks in a bit of a mess. Her fur is%^BOLD%^%^BLACK%^"
          +" ma%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d%^RESET%^"
          +" %^ORANGE%^and unwashed, her %^RESET%^whiskers%^ORANGE%^ droop and her movements are jerky"
          +" and unbalanced. She is %^MAGENTA%^powerfully built%^ORANGE%^, with broad shoulders, a"
          +" thick waist and strong looking arms. Her garments are"
          +" s%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^ott%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d and"
          +" %^CYAN%^sta%^RESET%^i%^CYAN%^n%^RESET%^e%^CYAN%^d%^ORANGE%^, her teeth are"
          +" y%^RESET%^e%^ORANGE%^l%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^o%^RESET%^w%^ORANGE%^ed and"
          +" her breath is, quite frankly, unpleasant.";
  } else {
    desc = "%^ORANGE%^This large female tabaxi looks as though she has recently made a not entirely"
          +" successful effort to clean up. Her fur looks a bit damp and out of place. Her"
          +" %^RESET%^whiskers %^ORANGE%^have a few kinks, but are at least held at a cheery looking"
          +" angle. She is %^MAGENTA%^powerfully built%^ORANGE%^, with broad shoulders, a thick waist"
          +" and strong looking arms. Her garments are"
          +" s%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^ott%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d and a bit"
          +" s%^CYAN%^t%^ORANGE%^a%^CYAN%^in%^ORANGE%^ed. Her teeth are a bit"
          +" y%^RESET%^e%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^l%^RESET%^o%^ORANGE%^wed, but her breath"
          +" smells like some kind of %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^nty"
          +" m%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^uthw%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^sh%^RESET%^"
          +"%^ORANGE%^.";
    if (objectp(ETO) && ETO == find_object_or_load(TABAXROOM + "smithy")){
      desc += "\nThe blacksmith could probably make weapons, armour, or bows here. ";
    } 
  }
  return desc;
}

void receive_given_item(object obj){
  if (!objectp(obj)){return;}
  if (obj->id("drink") && query_intox()>0 ){
    force_me("say " + THANX[random(sizeof(THANX))]);
    force_me("emote grabs the drink and guzzles it down");
    call_out("drink_me", 2);
  }
}

void drink_me(){
  force_me("drink drink");
  call_out("drink2", 9);
}

void drink2(){
  if (query_intox()<1){
    force_me("emote appears to suddenly notice the state of herself and makes a mad effort to tidy"
            +" herself up");
    set_emotes(0, ({}), 0);
  }
}

void reply_func(string msg, object speaker){
  if (!objectp(speaker) || !objectp(ETO) || !present(speaker, ETO) ){
    return;
  }
  if (query_intox()>0){
    return;
  }
  if (interact("follow", msg)){
  }
}

