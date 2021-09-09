/*
  bladegolem.c
  
  Guards for Tharis
  
  -- Tlaloc -- 9.2.21
*/

#include <std.h>
#include <security.h>
#include "/d/common/common.h"
#define CITYLAW "tharis law"

inherit "/std/guardsman.c";
int horn; // used to keep the horn from spamming

void set_guard_stuff();
void blow_horn(object watchman);

void create()
{
  int droll;
  string rank;
        ::create();
        will_open_doors(1);
        set_nogo( ({ "/d/tharis/newtharis/eroad2", "/d/tharis/road/road8", "/d/magic/temples/shar_path5", "/d/tharis/road/wroad2" }) );
        set_name("golem");
        set_short("%^BOLD%^%^BLACK%^A mi%^RESET%^t%^BOLD%^h%^RESET%^r%^BOLD%^%^BLACK%^il-%^RESET%^%^CYAN%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^CYAN%^golem %^BOLD%^i%^BLACK%^nscr%^CYAN%^i%^BLACK%^bed with a%^CYAN%^r%^RESET%^%^CYAN%^c%^BOLD%^%^BLACK%^a%^CYAN%^n%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^r%^CYAN%^u%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^WHITE%^");
        set_id(({"guard","golem","blade golem","tharis guard",CITYLAW, "guardsman of tharis","Tharis guard"}));
        set_long("%^BOLD%^%^BLACK%^You gaze upon one of the well-armored %^RESET%^%^CYAN%^blade golems %^BOLD%^%^BLACK%^that serve as the guards of Tharis. A featureless helm rests upon its wide shoulders, an %^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e gl%^RESET%^%^CYAN%^o%^BOLD%^w %^BLACK%^behind its %^RESET%^sm%^BOLD%^%^BLACK%^o%^RESET%^ky %^BOLD%^%^BLACK%^visor. Its unnatural body is formed from plates of dark mi%^RESET%^t%^BOLD%^h%^RESET%^r%^BOLD%^%^BLACK%^il b%^RESET%^u%^BOLD%^ff%^RESET%^e%^BOLD%^%^BLACK%^d to a dull, %^RESET%^matte %^BOLD%^%^BLACK%^finish. A%^RESET%^%^CYAN%^rc%^BOLD%^%^BLACK%^a%^CYAN%^n%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^r%^CYAN%^u%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s %^BOLD%^%^BLACK%^have been engraved across the dark metal, glowing with the same %^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e l%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^h%^BOLD%^t %^BLACK%^that emanates from within its helm. Unlike many golems, it is not unwieldy or clumsy, instead lithe, but powerful; built for speed and accuracy. Within its hands it carries two %^RESET%^bastard swords %^BOLD%^%^BLACK%^with blades composed of the same pure %^CYAN%^pale blue energy %^BLACK%^that permeates the rest of its being.%^RESET%^");
        set_hd(50,8);
        rank = set_ranks(([
        18 : "rookie",
        20 : "lieutenant",
        24 : "sergeant",
        28 : "captain",
        29 : "Commander",
        ]));
        droll =(10+random(21));
        set_gender("neuter");
        set_race("golem");
        set_max_hp(roll_dice( query_hd(), 50));
        set_hp(query_max_hp());
        set_alignment(2);
        set_overall_ac(-50);
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
        "The golem stomps around, looking for a threat.",
        "The golem looks around for any signs of trouble.",
        "The golem listens carefully for any sounds of danger.",
        }),0);
        set_emotes(5,({
        "The golem lunges at you with a furious slash.",
        "The golem calls for aide from his comrades.",
        }),1);
        set_new_exp(50,"normal");
        set_max_level(50);
        set_property("swarm",1);
        set_property("full attacks",1);
        set("aggressive",0);
        /*
        new(OBJ+"silver_robe")->move(TO);
        new(OBJ+"silver_belt")->move(TO);
        new(OBJ+"silver_shield")->move(TO);
        new(OBJ+"silvered_helm")->move(TO);
        new(OBJ+"light_chain")->move(TO);
        new(OBJ+"silver_sword")->move(TO);
        command("wield silver sword");
        command("wearall");
        */
}

void set_guard_stuff() {
    set_jail_location("/d/tharis/newtharis/rooms/jail_main");
    set_guarding("tharis");
    //set_bad_races(RACIST);
    set_race_action("capture");  //might as well :D
    /*
    set_race_messages(([
                "undead"          : "A zombie! destroy it!.",
                "drow"            : "Drow!  Kill the trator!",
                "fey'ri"          : "Fey'ri!  They've come to kidnap us!",
          ]));
    */
    ARREST_MSG        = "DO NOT RESIST!";
    CAPTURE_MSG       = "YOU ARE COMING WITH ME!";
    RACE_CAPTURE_MSG  = "You'll be put on display for entering the city!";
    EXPEL_MSG         = "Begone! Do not return to Tharis!";
    KILL_MSG          = "For your crimes, you now die!";
    JAIL_MSG          = "Off to jail you go for your crimes!";
    return;
}

int is_bad_race(object live)
{
    object myshape;
    if(!objectp(live)) { return 0; }
    if(live->query_true_invis()) { return 0; }
    if(live->query_invis() && !detecting_invis()) { return 0; }
    if(live->query_unconscious()) { return 0; }
    if(live->id("wild_world_monster")) { return 1; }
    if(query_bad_race(live)) { return 1; }

    if(objectp(myshape = live->query_property("shapeshifted"))) {
      if((string)myshape->query_shape_race() == "dragon") return 1;
    }
    else return 0;
}

void do_special_combat_actions()
{
   blow_horn(this_object());
}

void do_laws(object live){
do_laws();
do_laws();
do_laws();
do_laws();
if(sizeof(live->query_wielded()))
  force_me("say please unhand your weapon");
}

void blow_horn(object ob)
{
    if(!objectp(ob)) { return; }
    if(horn) { return; }
    broadcast_area("/d/tharis/newtharis/rooms/", "The warning horn" + " blows, alerting the guards!");
    horn = 1;
}

void init()
{
   ::init();
}

int isWatch() {
    return 1;
}

void die(object obj)
{
    object killer, room, *attackers;
  
    room = environment(this_object()); 
    attackers = this_object()->query_attackers();
  
    room && tell_room(room, "%^BOLD%^%^BLACK%^As the %^RESET%^%^CYAN%^automaton %^BOLD%^%^BLACK%^expires, it begins to shudder, the %^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e gl%^RESET%^%^CYAN%^o%^BOLD%^w %^BLACK%^emanating from its being beginning to %^CYAN%^p%^RESET%^%^CYAN%^u%^BOLD%^l%^RESET%^%^CYAN%^s%^BOLD%^e%^BLACK%^. With a sonic deafening %^WHITE%^BOOM %^BLACK%^and a %^CYAN%^flash %^BLACK%^of %^CYAN%^azure light%^BLACK%^, the guard explodes, dark shr%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pn%^RED%^e%^BLACK%^l flying.%^RESET%^");
  
    foreach(object ob in attackers)
    {
        tell_object(ob, "%^RED%^BOLD%^Pieces of shrapnel pierce deep in your flesh, causing you to bleed!%^RESET%^");
        ob->set_property("rend", 5);
    }
         
    seteuid(UID_LOG);
    if (objectp(killer=this_object()->query_current_attacker()))
    log_file("tharis", killer->query_name()+" killed blade golem on "+ctime(time())+".\n");
    seteuid(getuid(previous_object()));
    return ::die(obj);
}
