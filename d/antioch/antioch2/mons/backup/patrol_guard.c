//new guard for antioch
//hades 2/2/14

//Updated by Tlaloc - 12/28/19
#include <std.h>
#include <security.h>
#include "../antioch.h"
#include "/d/common/common.h"
#define CITYLAW "Antioch law"

inherit "/std/guardsman.c";
int horn; // used to keep the horn from spamming

void set_guard_stuff();
void blow_horn(object watchman);

void create(){
  int droll;
  string rank;
        ::create();
        will_open_doors(1);
        set_nogo( ({ "/d/antioch/antioch2/rooms/gates", }) );
        set_name("guard");
        set_short("A guardsman of Antioch");
        set_id(({"guard","guardsman","antioch guard",CITYLAW,
                "guardsman of Antioch","guardsman of antioch","Antioch guard"}));
        set_long(
        "This is one of the common guards of the city of Antioch. They are all"+
        " well trained and veterans of many years, dedicated to protecting the"+
        " city at all costs. He is wearing the uniform of the guards, "+
                "silver robe"+
        " and belt, with matching shield and helm. A suit of chain mail covers"+
        " his body, and a silver longsword is in his hand. He looks alert and"+
        " ready for trouble." );
        set_hd(50,8);
        rank = set_ranks(([
        18 : "rookie",
        20 : "lieutenant",
        24 : "sergeant",
        28 : "captain",
        29 : "Commander",
        ]));
        droll =(10+random(21));
        set_gender("male");
        set_race("human");
        set_max_hp(roll_dice( query_hd(), 40));
        set_hp(query_max_hp());
        set_alignment(1);
        set_overall_ac(-30);
        set_class("fighter");
        set_mlevel("fighter",50);
        set_level(50);
        set_property("no dominate",1);
        set_property("no bows",1);
        set_stats("strength",24);
        set_stats("constitution",22);
        set_stats("dexterity",16);
        set_stats("charisma",12);
        set_stats("wisdom",15);
        set_stats("intelligence",14);
        set_emotes(1,({
        "The guard paces back and forth.",
        "The guard looks around for any signs of trouble.",
        "The guard sharpens his sword.",
        "The guard listens carefully for any sounds of danger.",
        "The guard tightens the laces of his boots.",
        }),0);
        set_emotes(5,({
        "The guard lunges at you with a furious slash.",
        "The guard calls for aide from his comrades.",
        "The guard spits in your face.",
        "The guard bashes you with his shield.",
        }),1);
        set_new_exp(50,"normal");
        set_max_level(50);
        set_property("swarm",1);
        set_property("full attacks",1);
        set("aggressive",0);
        new(OBJ+"silver_robe")->move(TO);
        new(OBJ+"silver_belt")->move(TO);
        new(OBJ+"silver_shield")->move(TO);
        new(OBJ+"silvered_helm")->move(TO);
        new(OBJ+"light_chain")->move(TO);
        new(OBJ+"silver_sword")->move(TO);
        command("wield silver sword");
        command("wearall");
}

void set_guard_stuff() {
    set_jail_location(ROOMS + "jail_main");
    set_guarding("Antioch");
    set_bad_races(RACIST);
    set_race_action("capture");  //might as well :D
    set_race_messages(([
                "undead"          : "A zombie! destroy it!.",
                "drow"            : "Drow!  Kill the trator!",
                "fey'ri"          : "Fey'ri!  They've come to kidnap us!",
          ]));
    ARREST_MSG        = "Stop in the name of the law!";
    CAPTURE_MSG       = "To the cage with you, rabid beast!";
    RACE_CAPTURE_MSG  = "You'll be put on display for entering the city!";
    EXPEL_MSG         = "Begone! Do not return to Ashta'Rathai!";
    KILL_MSG          = "For your crimes, you now die!";
    JAIL_MSG          = "Off to jail you go for your crimes!";
    return;
}

int is_bad_race(object live){ // added N's fix for subraces
    object myshape;
    if(!objectp(live)) { return 0; }
    if(live->query_true_invis()) { return 0; }
    if(live->query_invis() && !detecting_invis()) { return 0; }
    if(live->query_unconscious()) { return 0; }
    if(live->id("wild_world_monster")) { return 1; }
    if(query_bad_race(live)) { return 1; }
    
    if(live->query_race() == "shade")
        return 1;
    
    if((string)live->query_race() == "elf") { 
        // un-altered fey'ri in natural demonic form
      if((string)live->query("subrace") == "fey'ri" &&
      !live->query_property("altered")) return 1;
    }
    if(objectp(myshape = live->query_property("shapeshifted"))) {
      if((string)myshape->query_shape_race() == "dragon") return 1;
    }
    else return 0;
}

void do_special_combat_actions() {
   blow_horn(TO);
}

void do_laws(object live){
do_laws();
do_laws();
do_laws();
do_laws();
if(sizeof(live->query_wielded()))
  force_me("say please unhand your weapon");
}

void blow_horn(object ob) {
    if(!objectp(ob)) { return; }
    if(horn) { return; }
    broadcast_area(ROOMS, "The warning horn"+
        " blows, alerting the guards!");
    horn = 1;
}

void init()
{
   ::init();
   if(present("silver robe",ETO) || present("silver belt",ETO) ||
present("silver shield",ETO) || present("silvered helm",ETO) ||
present("light chain",ETO) || present("silver sword",ETO)) {
      force_me("get all");
   }
}

int isWatch() {
    return 1;
}

void die(object obj) {
  // You love me, Crystal. You know you do.
  // garrett

  object killer;
  seteuid(UID_LOG);
  if (objectp(killer=TO->query_current_attacker()))
   log_file("antioch", killer->query_name()+
   " killed guard on "+ctime(time())+".\n");
  seteuid(getuid(previous_object()));
  return ::die(obj);

}
