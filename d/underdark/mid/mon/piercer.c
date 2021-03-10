#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

int y, timer, dropped, counter, falling;
void piercem(object targ);

void create(){
    ::create();
    set_name("piercer");
    set_id(({"piercer","stalactite","limestone stalactite"}));
    set_short("%^BOLD%^%^BLACK%^limestone stalactite%^RESET%^");
    set_long("%^ORANGE%^Your initial impression of this creature is that it is just a broken %^BLUE%^stalactite"
"%^ORANGE%^, fallen from the ceiling. A closer look, however, reveals that it is an actual creature, slug-like "
"in appearance and about four feet long, covered in a %^BOLD%^%^BLACK%^hardy carapace %^RESET%^%^ORANGE%^that "
"resembles a protrusion of limestone. A pair of %^CYAN%^tiny eyestalks %^ORANGE%^curl along the side of the "
"creature, the only feature that truly reveals it to be something other than a piece of rock.%^RESET%^");
    set_gender("neuter");
    set_race("piercer");
    set_body_type("piercer");
    set_hd(30,1);
    set_guild_level("fighter",30);
    set_mlevel("fighter",30);
    set_exp(750);
    set_max_hp(75);
    set_hp(75);
    add_limb("body","body",0,0,0);
    set("aggressive","agg_func");
    set_attack_limbs(({"body"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_funcs(({"acidspit"}));
    set_func_chance(100);
    set_invis();
    set_property("swarm",1);
    set_funcs(({"acidspit"}));
    set_func_chance(100);
    dropped = 0;
    falling = 0;
}

int agg_func(){
    if(wizardp(TP)) return 1;
    if(TP->query_invis()) return 1;
    timer=(roll_dice(1,8));
    if(!falling) {
      call_out("piercem",timer,TP);
      falling = 1;
    }
}

void piercem(object targ){
    if (!objectp(TO)) return 0;
    if (!present(targ)) return 0;
    if((TO)->query_invis()) set_invis();
    if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco(TO->query_hd())) - (int)(targ->query_ac())){
      tell_object(targ,"%^BOLD%^%^BLACK%^A stalactite falls on you from the ceiling!%^RESET%^");
      tell_room(environment(targ),"%^BOLD%^%^BLACK%^A stalactite falls on "+targ->QCN+"!%^RESET%^",targ);
      targ->do_damage("head",(roll_dice(2,10)));
    }
    else {
      tell_object(targ,"%^BOLD%^%^BLACK%^A stalactite falls from the ceiling, but misses you!%^RESET%^");
      tell_room(environment(targ),"%^BOLD%^%^BLACK%^A stalactite falls from the ceiling, narrowly missing "
+targ->QCN+"!%^RESET%^",targ);
    }
    command("kill "+targ->query_name());
    falling = 0;
    dropped = 1;
}

void acidspit(object targ){
    if (!objectp(TO)) return 0;
    if (!present(targ)) return 0;
    counter++;
    if(dropped==0 || counter==y) {
      piercem(targ);
      return 0;
    }
    if((roll_dice(1,20))>(targ->query_stats("dexterity"))){
      tell_object(targ,"%^BOLD%^%^BLACK%^A splash of corrosive %^GREEN%^acid%^BLACK%^ splashes on you from the "
"piercer, as it tries to climb slowly back up to the ceiling.%^RESET%^");
      tell_room(environment(targ),"%^BOLD%^%^BLACK%^A splash of corrosive %^GREEN%^acid%^BLACK%^ splashes on "
+targ->QCN+" from the piercer, as it tries to climb slowly back up to the ceiling.%^RESET%^",targ);
      targ->do_damage("torso",random(4)+1);
    }
    else{
      tell_object(targ,"%^BOLD%^%^BLACK%^Corrosive %^GREEN%^acid%^BLACK%^ splashes from the piercer skin as it crawls away, but fortunately it misses you.%^RESET%^");
      tell_room(environment(targ),"%^BOLD%^%^BLACK%^Corrosive %^GREEN%^acid%^BLACK%^ splashes from the piercer skin as it crawls away, but fortunately it misses "+targ->QCN+".%^RESET%^",targ);
    }
}

void die(object thing){
    if(!random(4)) {
      new("/d/antioch/valley/obj/gem")->move(TO);
      tell_room(ETO,"%^RED%^A %^WHITE%^gl%^BOLD%^i%^RESET%^%^WHITE%^tter%^BOLD%^i%^RESET%^%^WHITE%^ng %^RED%^"
"gemstone clinks upon the ground, falling from the piercer's broken shell.%^RESET%^");
    }
    return ::die(thing);
}
