#include <std.h>

inherit "/std/weapon";

void create() {
  ::create();
  set_name("longsword");
  set_id(({"sword","longsword","elfslayer"}));
  set("short","Longsword");
  set("long","This is the famous Elfslayer.  It is a very fine blade.  It is\n"+
              "covered with ancient runes.  Engraved on it is a picture of\n"+
             "the blade slicing an elf.\n");
  set_weight(4);
  set_size(2);
  set_wc(1,8);
  set_large_wc(1,12);
  set_type("slashing");
   set_prof_type("medium axe");
  set_value(125);
set_wield("You feel the magic that this weapon possesses.");
  set("read","You cannot read this sword for all of the blood and gore\n"+
             "covering the naked blade.\n");
  set_hit( (: this_object(), "weapon_hit" :) );
  set_destroy();
}

int weapon_hit(object ob) {
  int i;
  i = random(100);
  if(i < 75) {
    return 1;
  }
  if((i > 76) && (i < 89)) {
     tell_room(environment(ETO),"\n%^BOLD%^%^GREEN%^The axe pounds "+ob->query_cap_name()+" into tiny cubes of flesh!",ob);
    tell_object(ob,"\n%^BOLD%^%^GREEN%^The axe pounds you into tiny cubes of flesh!");
    ob->do_damage("torso", roll_dice(1,4)+1);
    return 1;
  }
   if((i > 90) && (i < 94)) {
    tell_room(environment(ETO),"\n%^BOLD%^%^BLUE%^A storm of elemental fury from the axe engulfs "+ob->query_cap_name()+", invoking a scream of pain and terror.\n",ob);
    tell_object(ob,"\n%^BOLD%^%^BLUE%^A storm of elemental fury from the axe engulfs you, invoking a scream of pain and terror.\n");
    ob->do_damage("torso", roll_dice(2,4)+2);
    return 1;
  }
    tell_room(environment(ETO), "\n%^BOLD%^%^CYAN%^The axe pulses with raw energy as it incinerates "+ob->query_cap_name()+" with a blast of energy!\n",ob);
    tell_object(ob,"\n%^BOLD%^%^CYAN%^The axe pulses with raw energy as it incinerates you with a blast of energy!\n");
  ob->do_damage("torso", roll_dice(3,4)+3);
  return 1;
}
