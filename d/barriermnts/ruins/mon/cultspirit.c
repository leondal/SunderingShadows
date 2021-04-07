#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

int flag;

create() {
   ::create();
   flag = random(6);
   set_name("ghostly spirit");
   set_id(({ "spirit","ghost","ghostly spirit"}));
   set_short("a ghostly spirit");
   set_long((:TO,"long_fun":));
   set_property("swarm",1);
   set_hd(30,10);
   set_class("fighter");
   set_mlevel("fighter",26);
   set_guild_level("fighter",26);
   add_search_path("/cmds/fighter");
   set_race("spirit");
   set_body_type("human");
   set_stats("intelligence",14);
   set_stats("wisdom",14);
   set_stats("strength",15);
   set_stats("charisma",6);
   set_stats("dexterity",19);
   set_stats("constitution",12);
   set_alignment(6);
   if (flag < 3) { set_gender("female"); }
   else { set_gender("male"); }
   set_size(2);
   set_exp(8000);
   set_overall_ac(-3);
   set_max_hp(random(100)+400);
   set_hp(query_max_hp());
   set_attacks_num(3);
   set_attack_limbs( ({"left hand","right hand"}) );
   set_base_damage_type("slashing");
   set_damage(2,5);
   //set_mob_magic_resistance("average");
   set("aggressive","agg_fun");
   set_funcs(({"slash"}));
   set_func_chance(10);
   set_emotes(1, ({"%^BLUE%^The spirit floats slowly through the air.",
"%^BLACK%^%^BOLD%^A low wail comes from the spirit.",
"%^ORANGE%^The spirit flickers and nearly disappears from view.",
"%^CYAN%^The spirit brushes past you, sending chills down your spine.",
"%^MAGENTA%^The spirit passes through a wall and reappears again a few seconds later."}), 0);
   set_achats(2, ({"%^RED%^The spirit screams at you in rage!",
"%^BLUE%^The spirit swirls around you, and you nearly lose sight of it!",
"%^BLACK%^%^BOLD%^The spirit's eyes glow with anger."}) );
   set_nogo(({"/d/barriermnts/ruins/room/8-3","/d/barriermnts/ruins/room/u7-3","/d/barriermnts/ruins/room/b6-2"}));
   set_speed(random(20)+41);
   set_moving(1);
   command("message in floats in.");
   command("message out drifts $D.");
   set_property("undead",1);
}

int agg_fun() {
   force_me("emoteat "+TPQN+" lets out a long wail.");
   force_me("kill "+TP->query_name());
}

string long_fun() {
   switch(flag) {
     case 0:
     return("%^BLUE%^A translucent form hovers in the air before you, though it is nearly impossible to "
"see as more than a whisp of fog.  The humanoid outline has a slightly feminine appearance, and at a "
"closer look you can see that she still wears what appears to be ceremonial robes and an ornate "
"headdress.  Flowing hair billows around her shoulders like a nebula, and two dark pools glow faintly "
"where her eyes should be.");
     break;
     case 1:
     return("%^BLUE%^The outline of a dark, shadowy form is visible before you.  It is hard to focus on, "
"like a breath of smoke in the air, but its two dark glowing eyes are quite clear, peer forth from a "
"slightly feminine face.  Ornate ceremonial robes are draped over her ghostly figure, and a delicate "
"headdress holds down much of her long, hazy hair.");
     break;
     case 2:
     return("%^BLUE%^Hazy fog hovers in the air before you, forming the vague outline of a humanoid "
"figure.  It looks slightly feminine, clothed in long ceremonial robes and wearing an ornate headdress.  "
"Long, flowing hair flows down over her shoulders like tendrils of smoke, and two dark orbs peer forth "
"where her eyes should be.");
     break;
     case 3:
     return("%^BLUE%^A translucent form hovers in the air before you, though it is nearly impossible to "
"see as more than a whisp of fog.  The humanoid outline has a slightly masculine appearance, and at a "
"closer look you can see that he still wears what appears to be ceremonial robes and an ornate "
"headdress.  Short hair rests about his ears, and two dark pools glow faintly where his eyes should be.");
     break;
     case 4:
     return("%^BLUE%^The outline of a dark, shadowy form is visible before you.  It is hard to focus on, "
"like a breath of smoke in the air, but its two dark glowing eyes are quite clear, peer forth from a "
"slightly masculine face.  Ornate ceremonial robes are draped over his ghostly figure, and a delicate "
"headdress holds rests upon his head.");
     break;
     case 5:
     return("%^BLUE%^Hazy fog hovers in the air before you, forming the vague outline of a humanoid "
"figure.  It looks slightly masculine, clothed in long ceremonial robes and wearing an ornate "
"headdress.  Short hair frames his face around the edges of the headdress, and two dark orbs peer forth "
"where her eyes should be.");
     break;
   }
}

void slash(object target) {
   tell_room(ETO,"%^BLUE%^The spirit slashes at "+target->QCN+", "+TO->QP+" hand passing right through "
+target->QP+" body!",target);
   tell_object(target,"%^BLUE%^The spirit slashes at you, "+TO->QP+" hand passing right through your "
"body and chilling you to the bone!");
   TO->set_property("magic",1);
   target->do_damage("torso",roll_dice(2,12));
   TO->remove_property("magic");
}

void die(object ob) {
   object myob;
   tell_room(ETO,"%^WHITE%^%^BOLD%^The spirit shrieks and disappears!");
   if(!random(4)) { new(OBJ+"essence")->move(ETO); }
   if(!random(5)) { new(OBJ+"sash")->move(ETO); }
   if(random(5) > 2) {
     switch(random(6)) {
       case 0..1: myob = new("/d/common/obj/rand/epants"); break;
       case 2: myob = new("/d/common/obj/rand/mage_robes"); myob->set_property("enchantment",1); break;
       case 3: myob = new("/d/common/obj/rand/rand_shirts"); myob->set_property("enchantment",1); break;
       case 4: myob = new("/d/common/obj/rand/r_shoes"); myob->set_property("enchantment",1); break;
       case 5: myob = new("/d/common/obj/rand/rand_leath_head"); break;
     }
     myob->set_size(random(2)+1);
     myob->move(ETO);
   }
   TO->remove();
}
