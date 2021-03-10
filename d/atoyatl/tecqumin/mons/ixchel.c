#include <std.h>
#include "/d/atoyatl/tecqumin/tecqumin.h"

inherit NPC;
void create() {
    ::create();
    set_name("Ixchel");
    set_id( ({ "ixchel", "healer"}) );
    set_short("Ixchel, tabaxi apothecary");
    set("aggressive", 0);
      set_property("not random monster", 1);
    set_level(49);
    set_long("%^CYAN%^This bright-eyed young %^ORANGE%^tabaxi%^CYAN%^ woman has %^ORANGE%^soft brown fur%^CYAN%^, which is stained in %^RED%^r%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^RESET%^%^GREEN%^n%^CYAN%^b%^BLUE%^o%^MAGENTA%^w c%^BLUE%^o%^CYAN%^l%^GREEN%^o%^YELLOW%^u%^RESET%^%^ORANGE%^r%^RED%^s %^CYAN%^from repeated exposure to %^GREEN%^ground herbs%^CYAN%^ and %^RED%^powders%^CYAN%^, from her hands to her elbows. Her face is more deliberately decorated with a %^RED%^ba%^ORANGE%^n%^BOLD%^%^YELLOW%^d %^RESET%^%^GREEN%^o%^CYAN%^f %^BLUE%^ra%^MAGENTA%^in%^BLUE%^bo%^CYAN%^w %^RESET%^%^GREEN%^s%^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^ip%^RED%^es%^CYAN%^ across her cheekbones");
    set_gender("female");
   set_alignment(2);
   set_race("tabaxi");
    set_hd(49,6);
    add_money("gold", random(5000));
    set_body_type("human");
    set_property("no attack", 1);
    set_hp(100);
    set_max_hp(100);
    set_stabbed_func( (: TO,"stab_func" :) );
    set_max_sp(query_hp());
    set_sp(query_max_sp());
//    set_mp(random(500));
//    set_max_mp(query_mp());
    set_exp(10);
    remove_std_db();
        set_nwp("healing",15);
}


void heart_beat() {
    object ob,*killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(present("guard 2",ETO)) return;
    /******** We don't need this now. Maybe later.
     if(query_hp() < 80) {
     command("say HELP!!");
     tell_room(ETO,"You see a guard rushes in to help Hettman.");
     ob = new("/d/shadow/mon/guard1");
     ob->move(ETO);
     ob->set_stats("strength",25);
     ob->set_stats("dexterity",25);
     ob->force_me("block west");
     ob->force_me("protect hettman");
     ob->force_me("protect hettman");
     ob->force_me("say I will protect our town folks!");
     killers = query_attackers();
     for(i=0;i<sizeof(killers);i++){
        ob->kill_ob(killers[i],1);
     }
     }
 **************************************/
  }

  void stab_func() {
     if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
  }
