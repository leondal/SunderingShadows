#include <std.h>
#include "../witchlair.h"
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("ahkserin");
   set_id(({"witch","half-orc","ahkserin","half-orc witch",
"Ahkserin"}));
   set_short("%^RESET%^%^BLUE%^Ahkserin%^MAGENTA%^, the "
"%^GREEN%^M%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^r%^GREEN%^sh "
"%^MAGENTA%^W%^BOLD%^%^CYAN%^i%^RESET%^%^MAGENTA%^t"
"%^BOLD%^%^GREEN%^c%^RESET%^%^MAGENTA%^h%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This being is clearly the master "
"of this twisted place. Slightly %^GREEN%^green-tinged "
"%^MAGENTA%^skin and sharp %^BOLD%^%^WHITE%^fangs "
"%^RESET%^%^MAGENTA%^protruding from the lower jaw signify orcish"
" blood, and her face is %^RED%^drenched %^MAGENTA%^in that of "
"some other poor wretch. In spite of her more %^ORANGE%^bestial "
"%^MAGENTA%^heritage, this woman's slim form would fill some "
"human women with envy. Hair black as night frames her abnormally"
" appealing facial features, made a wild, tangled mass by this "
"unforgiving environment despite her best efforts. Little bits "
"of %^WHITE%^b%^BOLD%^on%^RESET%^e%^MAGENTA%^, mainly small "
"bird and rodent skulls, are woven into her frizzled "
"%^RESET%^%^MAGENTA%^locks. An unnatural %^RED%^li"
"%^BOLD%^%^RED%^gh%^RESET%^%^RED%^t %^MAGENTA%^blazes from her "
"enraged eyes as she glares upon you, clawed hands already "
"alight in %^RED%^u%^BOLD%^%^RED%^n%^BLACK%^h%^RESET%^%^RED%^o"
"%^BOLD%^%^RED%^l%^BLACK%^y %^RESET%^%^RED%^f%^BOLD%^%^CYAN%^i"
"%^WHITE%^r%^RESET%^%^RED%^e %^MAGENTA%^to cleanse her domain "
"of your presence."); 
   set_race("half-orc");
   set_body_type("humanoid");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",12);
   set_stats("charisma",19);
   set_stats("dexterity",14);
   set_stats("constitution",14);
   set_hd(40,15);
   set_max_hp(random(200)+1000);
   set_hp(query_max_hp());
   set_class("mage");
   set_mlevel("mage",30);
   set_guild_level("mage",20);
   set_max_level(30);
   add_search_path("cmds/wizard");
   set_spells(({"fireball","fireball","powerword stun","powerword
 stun","vampiric touch","ball lightning",
"ball lightning"}));
   set_spell_chance(75);
   set_alignment(6);
   set_gender("female");
   set_size(2);
   set_property("swarm",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_property("damage resistance",10);
   set_property("spell penetration",20);
   set_property("not random monster", 1); //added by saide in order to prevent these from spawning in alternative worlds
   set_property("no animate",1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no tripped",1);
   set_exp(60000);
   set_overall_ac(6);
   set_attack_limbs( ({"left hand","right hand"}) );
   set_attacks_num(1);
   set_base_damage_type("bludgeoning");
   set_damage(1,6);
   set("aggressive","agg_fun");
   add_money("platinum",random(100));
   add_money("electrum",random(300)+15);
   set_property("no bows");
   set_funcs(({"bite_func","bite_func"}));
   set_func_chance(35);
}
void init(){
   ::init();
   add_action("deflect_fun","throw");
   add_action("deflect_fun","toss");
   if(!TP->query_true_invis()) {
     if(TP->query_invis()) { TP->set_invis();}
   }
}

int agg_fun(object mob){
   if (sizeof(TO->query_attackers()) < 1) {
     force_me("emoteat "+TPQN+" $M slowly turns and glares at $N, "
"a snarl forming on her lips as her hands whip out to the sides,"
" engulfed in %^BOLD%^%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^RED%^r"
"%^BLACK%^k f%^RESET%^%^RED%^la%^BOLD%^%^BLACK%^me.");
     force_me("emote hisses in utter RAGE!");
   new("cmds/spells/s/_stoneskin")->use_spell(TO,TO,25,100,"mage");
   new("/cmds/spells/g/_gate")->use_spell(TO,"summoning",25,100,"mage");
   call_out("force_me", 10, "command outsider to protect ahkserin");
   call_out("force_me", 15, "command outsider to protect ahkserin");
   call_out("force_me", 20, "command outsider to protect ahkserin");
   force_me("kill "+TP->query_name());
   }
}

void bite_func(object vict) {
   tell_object(vict,"%^RESET%^%^RED%^The witch turns her focus"
" solely to you, leaping forward with teeth bared and sinks those"
" sharp, sharp %^BOLD%^%^WHITE%^fangs %^RESET%^%^RED%^into your"
" neck! A %^BOLD%^%^RED%^warm%^RESET%^%^RED%^, wet sensation "
"trickles down your side as you feel her drawing the lifeblood "
"from your veins!");
   tell_room(ETO,"%^BOLD%^%^RED%^The witch hisses and leaps for"
" "+vict->QCN+", pulling them into a dark embrace, sinking her "
"v%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^c%^RESET%^%^RED%^i"
"%^BOLD%^%^WHITE%^0%^RED%^us %^WHITE%^fangs %^RED%^into the side of "
"their neck, her %^RESET%^%^RED%^e%^BOLD%^%^RED%^y%^RESET%^%^RED%^es"
" %^BOLD%^%^RED%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^wing "
"brighter as she drinks of their life essence!",vict);
   TO->set_property("magic",1);
   vict->do_damage("neck",random(20)+25);
   TO->remove_property("magic");
   vict->set_paralyzed(30,"%^BOLD%^%^RED%^You're trying to "
"stop the blood from flowing out of your wound!");
   return 1;
}

int deflect_fun(string str) {
   if (strsrch(str,"witch") != -1 || strsrch(str,"ahkserin") != -1 ||
strsrch(str,"half-orc") != -1) {
     write("Ahkserin hisses and covers her eyes, unnatural reflexes"
" lashing out to backhand you!");
     write("%^BOLD%^%^WHITE%^You're sent flying into a wall!");
     tell_room(ETP,""+TP->QCN+" tries to throw something at the "
"witch but is sent into a wall from a wicked backhand!",TP);
     TP->set_paralyzed(20,"%^BOLD%^%^BLACK%^You're still in a daze"
" from being smacked across the room. That wench is stronger than "
"she looks!");
     return 1;
   }
   return 0;
}

void die(object ob) {
   object who;
   tell_room(ETO,"%^BOLD%^%^BLACK%^Ahkserin gives a choked, almost"
" sobbing gasp, eyes sparkling with %^RESET%^%^CYAN%^t"
"%^BOLD%^%^CYAN%^e%^WHITE%^a%^RESET%^%^CYAN%^rs "
"%^BOLD%^%^BLACK%^as she whispers %^RESET%^%^MAGENTA%^You've "
"ruined everything... %^BOLD%^%^BLACK%^before collapsing into"
" a %^RESET%^%^RED%^burning %^BOLD%^%^BLACK%^pile of ash"
".%^RESET%^\n"
"Moments later, a portal flickers into life near the remains.");
   if(member_array("portal",ETO->query_exits()) == -1)
ETO->add_exit(ROOMS"archway","portal");
   new(OBJ"neckbiter")->move(TO);
   new(OBJ"journal")->move(TO);
  :: die(TO);
}
