//Garrett pointed out that he could be attacked to summon infinite guards.  
//It was tough to come up with something that didn't screw up him being 
//available, but hopefully this works well enough.  Styx  11/13/01

#include <std.h>
inherit MONSTER;

int step;
int guards;

void reply_snarl(string str);
void reply_yell(string str);
void reply_ask(string str);

void create() {
   ::create();
   set_name("gatekeeper");
   set_id( ({"gatekeeper"}) );
   set_short("%^BOLD%^%^RED%^An Irritated Gatekeeper%^RESET%^");
   set_long("The Gatekeeper is very large and less than handsome...it looks like "+
            "he could hold his own and then some. I would think it wiser to "+
            "answer his questions or simply be on your way than to fight him.");
   set_race("ogre");
   set_gender("male");
   set_body_type("human");
   set_size(3);
   set_alignment(5);
   set_hd(20,20);
   set_max_hp(180);
   set_hp(180);
   set_overall_ac(2);
   set_wielding_limbs( ({"left hand", "right hand"}) );
   new("/d/koenig/town/mon/weapons/waraxe.c")->move(TO);
   new("/d/koenig/town/mon/weapons/bonedagger.c")->move(TO);
   command("wield axe in right hand");
   command("wield dagger in left hand");
   enable_commands();
   set_class("fighter");
   set_new_exp(10, "normal");
   set("aggressive", 1);
}

void init() {
   ::init();
   add_action("kill","kill");
   //call_out("start_grumble",5);
   step = 0;
}

void reset() {
   ::reset();
   guards = 0;
//   if(!interactive(TP)) { 
// that was bugging of course since reset isn't triggered by a player *Styx*  8/21/05
   if(objectp(ETO) && !present("player", ETO)) {
      tell_room(ETO,"The Gatekeeper shrugs and lumbers off.");
      move("/d/shadowgate/void");
      remove();
   }
}

int kill(string str) {
   object guard1, hyena1, ob;
   if(str != "gatekeeper") return 0;
   if(guards == 1) {
     force_me("say %^BOLD%^%^RED%^Ya try ta kill me ??!!");
     force_me("say I don't gotta take this outta nobody, I just go 'way.");
     tell_room(ETO,"The Gatekeeper scowls and leaves.");
     move("/d/koenig/town/room11");
     force_me("say Stupid people think dey kill me, I just leave 'em out dere.");   
     return 1;
   }     
   reply_snarl("Ya try attackin' me?!");
   reply_yell("%^BOLD%^GUARDS!!!!");
   tell_room(ETO,"The Gatekeeper leaves to get more "
             "reinforcements as his call has been answered by one guard and "
             "the local equivalant of a laughing meat grinder.");
   if(!present("guard1",ETO)) {
      new("/d/koenig/town/mon/guard1.c")->move(ETO);
      if(!random(3)) new("/d/koenig/town/mon/guard1.c")->move(ETO);
   }
   if(!present("hyena1",ETO)) {
      ob = new("/d/koenig/town/mon/hyena1.c");
      ob->move(ETO);
   }
   guards = 1;
   return 1;
}

void start_grumble(string str) {
   string time;
   time = "daemon/events_d"->query_time_of_day();
   if(!present(TP->query_name(),ETO)) {
      tell_room(ETO,"The Gatekeeper comes to the gate and looks around.");
      reply_snarl("What the hell!");
      tell_room(ETO,"The Gatekeeper shrugs and leaves.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   if(time == "day") {
      reply_snarl("I cant wait until I retire! I'm sick of this getting up and "
                  "down everytime some fool wishes to enter!");
      tell_room(ETO,"The Gatekeeper comes to the gate "
                "and carefully looks "+TPQCN+" over.",TP);
      tell_object(TP,"The Gatekeeper comes to the gate and carefully looks "
                  "you over.");
      call_out("start_exam",1);
      return 1;
   }
   else {
      reply_snarl("Who the devil would be knocking at this infernal time of "
                  "night?! I swear, some people just have no consideration for "
                  "those of us who are trying to get some sleep!");
      tell_room(ETO,"The Gatekeeper comes to the gate "
                "and carefully looks "+TPQCN+" over.",TP);
      tell_object(TP,"The Gatekeeper comes to the gate and carefully looks "
                  "you over.");
      call_out("start_exam",5);
      return 1;
   }
}

void start_exam(string str) {
   if(!present(TP->query_name(),ETO)) {
      reply_snarl("Another fool!");
      tell_room(ETO,"The Gatekeeper turns around and "
                "marches back into the gatehouse, cursing under his breath.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   if(((int)TP->query_lowest_level() < 6)) {
      reply_snarl("I CAN NOT LET YOU PASS!! You are clearly too inexperienced to be venturing into this place as yet.  BE GONE and be thankful I saved you from your doom for now!!");
      tell_room(ETO,"The Gatekeeper turns around and "
                "marches back into the gatehouse, cursing under his breath.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   else {
      reply_ask("Go away, "+TP->query_race()+"! Muileann is closed for now for some remodeling. Try again some other time.");
   }
}

void reply_snarl(string str) {
   tell_room(ETO,"%^MAGENTA%^The Gatekeeper snarls: "
             "%^RESET%^"+str, TO);
}

void reply_yell(string str) {
   tell_room(ETO,"%^MAGENTA%^The Gatekeeper shouts: "
             "%^RESET%^"+str, TO);
}

void reply_ask(string str) {
   tell_room(ETO,"%^MAGENTA%^The Gatekeeper asks: "
             "%^RESET%^"+str, TO);
}
