//NPC thieves' fence for Newbietown

#include <std.h>
inherit "/std/fence";

void create() {
   ::create();
   set_name("Granstun");
   set_id( ({ "granstun","Granstun","half-orc"}) );
   set_short("Granstun, a seedy looking half-orc");
   set("aggressive", 0);
   set_level(20);
   set_long(
@STYX
Granstun has a wide, flattened, roundish nose and a grayish-green 
tint to his skin that makes it obvious he's not fully human.  
However, although also stooped and primitive looking, he's not nearly 
as repulsive to the more civilized races as his orcish ancestors.  
Dressed in rather drab clothing that looks like he might have slept 
in it, he has thick and rather unkempt reddish-brown hair.
STYX
);
   set_gender("male");
   set_alignment(5);
   set_hd(20, 1);
   set_class("thief");
   set_mlevel("thief",20);
   set_race("half-orc");
   add_money("gold", random(50));
   set_overall_ac(2);
   set_exp(250);
   set_nwp("concealment", 4, 500);
   set_body_type("human");
//   set_property("no bump", 1); no longer used per Tristan (Styx 7/20/01)
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init() {
   ::init();
   call_out("whisper",2);
}

void whisper() {
   if(TP->query_invis()) return;
   if(userp(TP)) {
     command("eye "+TPQN);
     if(TP->is_class("thief") || TP->is_class("bard") || TP->is_class("assassin")) {
       command("whisper "+TPQN+" Have anythin' ya wanna be gettin' rid of on the sly?");
       command("smirk "+TPQN);
       command("whisper "+TPQN+" I kin fence it fer ya.  Fer a fee o' course.");
       return;
     }
   command("say I don' think we'll be doin' any bus'ness.");
   command("sigh");
   return;
   }
}
