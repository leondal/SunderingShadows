#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

int flag,parryflag;

create() {
   ::create();
   flag = random(6);
   parryflag = 0;
   set_name("guardian spirit");
   set_short("guardian spirit");
   set_id(({ "spirit","ghost","guardian spirit","guardian"}));
   set_long((:TO,"long_fun":));
   set_property("swarm",1);
   set_hd(35,10);
   set_race("spirit");
   set_body_type("human");
   set_stats("intelligence",14);
   set_stats("wisdom",14);
   set_stats("strength",14);
   set_stats("charisma",14);
   set_stats("dexterity",14);
   set_stats("constitution",14);
   set_invis(1);
   if (flag == 0) {
     set_class("fighter");
     set_mlevel("fighter",24);
     set_guild_level("fighter",24);
     set_class("thief");
     set_mlevel("thief",27);
     set_guild_level("thief",27);
     add_search_path("/cmds/thief");
     set_thief_skill("hide in shadows",95);
     set_thief_skill("move silently",95);
     set_stats("dexterity",19);
     set_stats("strength",16);
   }
   if (flag == 1) {
     set_class("bard");
     set_mlevel("bard",29);
     set_guild_level("bard",29);
     set_stats("charisma",17);
     set_stats("constitution",17);
   }
   if (flag == 2) {
     set_class("fighter");
     set_mlevel("fighter",28);
     set_guild_level("fighter",28);
     add_search_path("/cmds/fighter");
     set_stats("strength",18);
     set_stats("constitution",18);
   }
   if (flag == 3) {
     set_class("mage");
     set_mlevel("mage",24);
     set_guild_level("mage",24);
     add_search_path("/cmds/wizard");
     set_stats("intelligence",18);
     set_stats("wisdom",16);
   }
   if (flag == 4) {
     set_class("ranger");
     set_mlevel("ranger",27);
     set_guild_level("ranger",27);
     add_search_path("/cmds/ranger");
     set_stats("strength",17);
     set_stats("dexterity",18);
   }
   if (flag == 5) {
     set_class("thief");
     set_mlevel("thief",29);
     set_guild_level("thief",29);
     add_search_path("/cmds/thief");
     set_thief_skill("hide in shadows",95);
     set_thief_skill("move silently",95);
     set_stats("dexterity",18);
     set_stats("intelligence",16);
   }
   set_alignment(5);
   if (flag < 2) { set_gender("female"); }
   else { set_gender("male"); }
   if (!flag) { set_size(1); }
   else { set_size(2); }
   set_exp(12000);
   set_overall_ac(-4);
   set_max_hp(random(75)+450);
   set_hp(query_max_hp());
   set_attack_limbs( ({"left hand","right hand"}) );
   if (flag == 0 || flag == 2) { set_attacks_num(3); }
   if (flag == 1) { set_attacks_num(2); }
   if (flag == 3) { set_attacks_num(1); }
   if (flag == 4 || flag == 5) { set_attacks_num(4); }
   if (flag == 0 || flag == 4) { set_base_damage_type("slashing"); }
   if (flag == 2 || flag == 3) { set_base_damage_type("bludgeoning"); }
   if (flag == 1 || flag == 5) { set_base_damage_type("piercing"); }
   set_damage(2,6);
   //set_mob_magic_resistance("average");
   set_property("undead",1);
   set("aggressive","agg_fun");
   if (flag == 1) {
     set_spells(({"magic missile","magic missile","burning hands","acid arrow","lightning bolt"}));
     set_spell_chance(40);
   }
   if (flag == 3) {
     set_spells(({"magic missile","magic missile","scorcher","acid arrow","lightning bolt","cone of cold"}));
     set_spell_chance(90);
   }
   if (flag == 0 || flag == 5) { set_scrambling(1); }
   if (flag == 2) { set_funcs(({"brush","gaze","flashit","rushit"})); }
   else { set_funcs(({"brush","gaze"})); }
   set_func_chance(10);
   set_emotes(1, ({"%^BLUE%^The spirit floats slowly through the air.",
"%^BLACK%^%^BOLD%^The spirit's mournful gaze passes over you.",
"%^ORANGE%^The spirit flickers and nearly disappears from view.",
"%^CYAN%^The spirit brushes past you, sending chills down your spine.",
"%^MAGENTA%^The spirit passes through a wall and reappears again a few seconds later."}), 0);
   set_achats(2, ({"%^RED%^The spirit moans mournfully!",
"%^BLUE%^The spirit swirls around you, and you nearly lose sight of it!",
"%^CYAN%^The spirit flickers and nearly disappears.",
"%^BLACK%^%^BOLD%^The spirit's eyes glow with despair."}) );
   command("message in floats in.");
   command("message out drifts $D.");
   set_property("no bows",1);
   TO->set_invis(1);
}

int agg_fun() {
   force_me("emoteat "+TPQN+" fixes "+TO->QP+" despairing gaze upon $N.");
   if (flag == 0 || flag == 5) { force_me("stab "+TPQN+""); }
   force_me("kill "+TP->query_name());
   if (flag == 2) { call_out("doparry",2,TP); }
}

string long_fun() {
   switch(flag) {
     case 0:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the figure of a female halfling, with short ringlets brushing her "
"shoulders, slightly chubby features, and bare feet covered in curly hair.  Her small figure is garbed "
"in a tunic and cloak, and carries a rather odd-looking rope-disk in one hand.  Her face carries a "
"strange expression, what seems a mix of anger and despair, and her dark glowing eyes follow your every "
"move.");
     break;
     case 1:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the slender figure of a half-elf woman, with long flowing hair and "
"delicate features.  She is wrapped in a myriad of exotic billowing garments, and a long veil covers much "
"of her face, pinned up over her hair with a single hairpin.  Her face carries a strange expression, what "
"seems a mix of anger and despair, and her dark glowing eyes follow your every move.");
     break;
     case 2:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the stout form of a male dwarf, clad in a thick jacket and breeches, and "
"heavy metal plate.  He has bushy eyebrows, and a long beard that brushes the ground, and holds a heavy "
"axe in both calloused hands.  His face carries a strange expression, what seems a mix of anger and "
"despair, and his dark glowing eyes follow your every move.");
     break;
     case 3:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the frail figure of a human man, swathed in flowing robes and with both "
"hands covered by fine gloves.  His fine, close-cropped hair frames his angular face, and a slender "
"circlet rests upon his brow.  His face carries a strange expression, what seems a mix of anger and "
"despair, and his dark glowing eyes follow your every move.");
     break;
     case 4:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the toned figure of an elven male, clad in chainmail and wrapped in a "
"flowing cape.  Plaits run through his long hair, and his ears are sharply pointed.  In his hands is an "
"exotic-looking weapon, that resembles a staff fitted with a curved blade at each end.  His face carries "
"a strange expression, what seems a mix of anger and despair, and his dark glowing eyes follow your "
"every move.");
     break;
     case 5:
     return("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit resembles the lithe silhouette of a male half-elf, shrouded in shadowy garments and "
"light leather armor.  Over one elbow he wears a small shield, and in each hands he holds a small "
"blade.  His face carries a strange expression, what seems a mix of anger and despair, and his dark "
"glowing eyes follow your every move.");
     break;
   }
}

void brush(object target) {
   tell_room(ETO,"%^CYAN%^%^BOLD%^The spirit brushes against "+target->QCN+", who freezes at the "
"touch!",target);
   tell_object(target,"%^CYAN%^%^BOLD%^The spirit brushes up against you with a chilling touch, and your "
"body freezes up!");
   target->set_paralyzed(20,"You can't move your limbs!");
}

void gaze(object target) {
   tell_room(ETO,"%^BLACK%^%^BOLD%^The spirit fixes its mournful gaze upon "+target->QCN+".",target);
   tell_object(target,"%^BLACK%^%^BOLD%^The spirit fixes its mournful gaze upon you, and a burning "
"sensation fills your body!");
   call_out("burn",5,target,1);
}

void burn(object target,int counter) {
   if(!objectp(TO)) return;
   if(!objectp(target)) return;
   if (counter < 6) {
     tell_room(environment(target),"%^BLACK%^%^BOLD%^"+target->QCN+" writhes in agony!",target);
     tell_object(target,"%^BLACK%^%^BOLD%^Your entire body burns!");
     target->do_damage("torso",roll_dice(2,5));
     counter = counter + 1;
     call_out("burn",5,target,counter);
   }
   else {
     tell_object(target,"%^BLACK%^%^BOLD%^The burning sensation finally fades from your body.");
   }
}

void die(object ob) {
   tell_room(ETO,"%^WHITE%^%^BOLD%^The spirit releases a soft sigh and disappears.");
   TO->remove();
}

void heart_beat() {
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!TO->query_invis() && sizeof(TO->query_attackers()) < 1) { TO->set_invis(1); }
   if(TO->query_invis() && sizeof(TO->query_attackers()) > 0) { TO->set_invis(0); }
   return;
}

void flashit(object target) {
   force_me("flash "+target->query_name());
}

void rushit(object target) {
   force_me("rush "+target->query_name());
}

void doparry(object targ){
   if(!objectp(targ) || !objectp(TO)) return;
   if (parryflag == 1) return;
   force_me("parry");
   parryflag = 1;
}
