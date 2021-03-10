#include <std.h>
#include "../phedefs.h"
inherit MONSTER;
object ob;
void create(){
  ::create();
  set_name("vengance knight");
  set_id(({"skeletal knight","knight","skeleton","vengance knight"}));
  set_race("undead");
  set_mob_magic_resistance("average");
  set_gender("male");
  set_short("%^BOLD%^%^BLUE%^Vengance knight%^BOLD%^%^RED%^");
  set_long(
  "  This massive figure dressed in charred plate armor radiates a sense of sorrow and undead power."
  "  The human who once wore this armor was once a powerfull knight who failed in his services to his lord and was trapped on his moment of death by a foul spell."
  "  Giving evidence to his violent death, his full helms visor is torn away and a great slash mark runs from above his left eye to below his jaw.   A blow from a great axe."
  "  A great flamerge rests in its hands which it swing back and forth challenging the occupants of the fortress who appear not to want to have anything to do with him."
  );
  set_ac(-8);
  set_size(2);
  set_body_type("human");
  set_class("fighter");
  set_mlevel("fighter",35);
  set_hd(35,5);
  set_attack_bonus(2);
  add_search_path("/cmds/fighter");
  set_alignment(4);
  set_property("full attacks",1);
  set_stats("strength",20);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",19);
  add_money("gold",random(2000));
  add_money("platinum",random(2000));
  set_hp(1000);
  set_exp(30000);
  set_emotes(15,({
  }),1);
  ob=new("/d/shadow/obj/armor/fullplate.c");
  ob->set_short("%^BOLD%^%^BLACK%^Blackened fullplate%^RESET%^");
  ob->set_property("enchantment",1);
  ob->set_long("  This fullplate looks like its been struck by lightning and scorched by some incredibly hot fire.  Its doubtfull the wearer could of survived such treatment.   The armor is freezing cold to the touch.");
  ob->move(TO);
  command("wear plate");
  ob=new("/d/shadow/obj/weapon/two_hand_sword.c");
  ob->set_name("flamberge");
  ob->set_short("Flamberge");
  ob->set_id(({"flamberge","two handed sword","sword"}));
  ob->set_long(
  "  This massive two handed sword was designed to crush through armor."
  "  Its edge is wavy to increase the force imparted with the area in contact with the target."
  "  You dont really want to see the gruesome wounds this weapon would produce, at least not against you!"
  );
  ob->set_property("enchantment",3);
  ob->move(TO);
  command("wield sword");
  ob=new("/d/shadow/obj/armor/helm.c");
  ob->set_short("Shattered helm");
  ob->set_long("  This full helm has taken a horrific blow across the left side of its front.   The wearer must surely of died from the blow!  It feels cold to the touch, the chill of the grave.");
  ob->set_id(({"helm","shattered helm","full helm","helmet"}));
  ob->set_property("enchantment",1);
  ob->move(TO);
  command("wear helm");
}
