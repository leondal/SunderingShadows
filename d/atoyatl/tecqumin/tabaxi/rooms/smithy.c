#include <std.h>
#include <move.h>
#include "../../tecqumin.h"
#define WBASE "/d/common/obj/weapon/"
#define WPNS ({"club", "club_lg", "dagger", "halberd", "handaxe", "mace", "mspear", "shortsword",\
             "spear_lg", "partisan"})
#define ABASE "/d/common/obj/armour/"
#define ARMRS ({"chain", "leather", "studded", "splint"})

inherit ROOM;

int query_skill(object ob, string skill);

int cleaned, weapons, bows, armour;
object * weapon_makers, * bow_makers, * armour_makers;

void create() {
  ::create();
  cleaned = 0;
  weapons = random(3);
  bows = random(3);
  armour = random(3);
  weapon_makers = ({});
  bow_makers = ({});
  armour_makers = ({});
  set_short("Smithy");
  set_long((: TO, "long_desc" :) );
  set_items(([ ({"rack", "racks", "weapons", "armour","armor"}): (: TO, "rack_desc" :) ,
                "furnace": (:TO, "furnace_desc" :),
               ({"dirt", "grime", "dust"}) : (:TO , "dust_desc" :), 
               ({"tools", "tool"}) : "All the normal tools of the blacksmith's trade are here, along"
                                     +" with a variety of other implements that have clearly been made"
                                     +" in the forge for other crafts and activities." ,
               ({"anvil", "anvils"}) : "These are fairly standard anvils, in three different sizes. They"
                                    +" are all too big and heavy to move, though."
                                    ]));
  set_exits( ([ "out" : TABAXROOM + "centre" ,
             ]) );

}
 
void init(){
  object smith;
  ::init();
  add_action("make_em", "make");
  add_action("equip_em", "equip");
  add_action("clean_me", "clean");
  add_action("clean_me", "tidy");
  add_action("clean_me", "clear");
  add_action("clean_me", "straighten");
  set_had_players(3);
  smith = present("smith", TO);
  if (!objectp(smith)){
    smith = new (MOB + "blacksmith");
    smith->move(TO);
    smith->force_me("drink drink");
  }
}

int clean_up(){
  int clean, wpns, bws, armr, result;
  object * wpn_mkrs, * bw_mkrs, * armr_mkrs;
  clean = cleaned;
  wpns = weapons;
  bws = bows;
  armr = armour;
  wpn_mkrs = weapon_makers;
  bw_mkrs = bow_makers;
  armr_mkrs = armour_makers;
  wpns = weapons;
  result = ::clean_up();
  cleaned = clean;
  weapons = wpns;
  bows = bws;
  armour = armr;
  weapon_makers = wpn_mkrs;
  bow_makers = bw_mkrs;
  armour_makers = armr_mkrs;
  return result;
} 

void reset(){
  object * removals, *wp_mk, *bw_mk, *ar_mk, brazier;
  int i, skill, wpn, bw, armr, clean;
  wpn = weapons;
  bw = bows;
  armr = armour;
  wp_mk = weapon_makers;
  bw_mk = bow_makers;
  ar_mk = armour_makers;
  removals = ({});
  clean = cleaned;
  ::reset();
  for (i=0;i<2;i++){
    if (sizeof(children(TABAXOBJ + "brazier"))<3){
      brazier = new (TABAXOBJ + "brazier");
      brazier->move(TO);
    }
  }
  weapons = wpn;
  bows = bw;
  armour = armr;
  weapon_makers = wp_mk;
  bow_makers = bw_mk;
  armour_makers = ar_mk;
  cleaned = clean;
  if (sizeof(weapon_makers)>0){
    for(i=0;i<sizeof(weapon_makers);i++){
      if (!present(weapon_makers[i], TO)){
        removals += ({weapon_makers[i]});
        continue;
      }
      tell_object(weapon_makers[i], "You finish off a batch of weapons");
      skill = query_skill(weapon_makers[i], "weaponsmithing");
      weapons += skill/4 + random(skill/4);
    }
    if (sizeof(removals)>0){
      weapon_makers -= removals;
    }
    removals = ({});
  }
  if (sizeof(bow_makers)>0){
    for(i=0;i<sizeof(bow_makers);i++){
      if (!present(bow_makers[i], TO)){
        removals += ({bow_makers[i]});
        continue;
      }
      tell_object(bow_makers[i], "You finish off a batch of bows and arrows");
      skill = query_skill(bow_makers[i], "weaponsmithing");
      bows += skill/4 + random(skill/4);
    }
    if (sizeof(removals)>0){
      bow_makers -= removals;
    }
    removals = ({});
  }
  if (sizeof(armour_makers)>0){
    for(i=0;i<sizeof(armour_makers);i++){
      if (!present(armour_makers[i], TO)){
        removals += ({armour_makers[i]});
        continue;
      }
      tell_object(armour_makers[i], "You finish off a batch of bows and arrows");
      skill = query_skill(armour_makers[i], "armorsmithing");
      armour += skill/4 + random(skill/4);
    }
    if (sizeof(removals)>0){
      armour_makers -= removals;
    }
    removals = ({});
  }
  set_had_players(3);
}

int query_skill(object ob, string skill){
  int result;
  mapping skills;
  if (!objectp(ob)){
    return 0;
  }
  skills = ob->query_nwps_mapping();  
  result = skills[skill]["level"];
  return result;
}

void set_weapons(int wp){
  weapons = wp;
}

int query_weapons(){
  return weapons;
}

void set_armour(int ar){
  armour = ar;
}

int query_armour(){
  return armour;
}

void set_bows(int bw){
  bows = bw;
}

int query_bows(){
  return bows;
}

string how_many(int i){
  switch (i){
  case 0: 
    return "no";
  case 1:
    return "a single";
  case 2..4:
    return "a few";
  case 5..7:
    return "several";
  case 8..10:
    return "quite a few";
  default:
    return "lots of";
  }
}

string rack_desc(){
  string desc;
  desc = "Most of the weapons, armour and bows are unusable.";
  if (weapons < 1 && armour <1 && bows <1){
    desc += " In fact, you can't make out any serviceable ones at all.";
    return desc;
  }
    desc += " However, you can see " + how_many(weapons) +" serviceable hand weapon";
  if (weapons != 1){
    desc += "s";
  }
  desc += ", " + how_many(armour) + " set";
  if (armour != 1){
   desc += "s";
  }
  desc += " of armour and " + how_many(bows) + " bow";
  if (bows !=1){
    desc += "s";
  } 
  desc += " and arrows.";
  if (armour >0){
    if (weapons >0){
       if (bows>0){
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with weapon>%^RESET%^,"
              +" %^BOLD%^%^YELLOW%^<equip with armour>%^RESET%^ or %^BOLD%^%^YELLOW%^<equip with bow>";
       } else {
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with weapon>%^RESET%^ or"
              +" %^BOLD%^%^YELLOW%^<equip with armour>%^RESET%^";
       }
    } else {
       if (bows>0){
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with armour>%^RESET%^ or"
                +" %^BOLD%^%^YELLOW%^<equip with bow>";
       } else {
         desc += "You could probably %^BOLD%^%^YELLOW%^<equip with armour>%^RESET%^";
       }
    } 
  } else {
    if (weapons >0){
       if (bows>0){
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with weapon>%^RESET%^ or"
              +" %^BOLD%^%^YELLOW%^<equip with bow>";
       } else {
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with weapon>%^RESET%^";
       }
    } else {
       if (bows>0){
         desc += " You could probably %^BOLD%^%^YELLOW%^<equip with bow>";
       } 
    } 
  }
  return desc;
}

string furnace_desc(){
  switch(cleaned){
  case 10:
    return "The bellows-driven %^BOLD%^%^RED%^f%^RESET%^%^RED%^u%^BOLD%^%^RED%^rn%^RESET%^%^RED%^a"
          +"%^BOLD%^%^RED%^ce%^RESET%^ is lit on a slow burn, and is ready for use";
  default:
    return "The bellows-driven furnace is %^CYAN%^cold%^RESET%^ and unlit. It looks a little sad";
  }
}


string long_desc(){
  string desc;
  switch (cleaned){
  case 0:
    desc = "%^BOLD%^%^BLACK%^Every surface in the smithy is covered with %^RESET%^grime"
          +"%^BOLD%^%^BLACK%^, soot and %^GREEN%^sweat%^BOLD%^%^BLACK%^. Racks of %^RESET%^tools"
          +"%^BOLD%^%^BLACK%^, %^GREEN%^farm implements%^BOLD%^%^BLACK%^, %^ORANGE%^weapons%^BOLD%^"
          +"%^BLACK%^ and even %^CYAN%^armour%^BOLD%^%^BLACK%^ line the walls. A central, bellows-"
          +"driven furnace is long since cold, but there is fuel enough for that, as well as a couple"
          +" of open braziers. Hammers, punches, grips and assorted tools of the blacksmith's trade"
          +" are around the place. They have not been stored with any particular care, and some are"
          +" even showing spots of rust. There are two or three anvils of different sizes, but they"
          +" don't appear to have seen much use lately.";
    break;
  case 1..7:
   desc = "%^BOLD%^%^BLACK%^The %^RESET%^smithy%^BOLD%^%^BLACK%^ looks pretty grimy and untended. Most"
         +" of the %^RESET%^surfaces%^BOLD%^%^BLACK%^ are covered with soot and %^RESET%^greas%^BOLD%^"
          +"%^BLACK%^e. There are some signs that someone may have made an effort towards cleaning it"
          +" up recently, but there is a long way to go. Racks of %^RESET%^tools%^BOLD%^%^BLACK%^"
          +"%^BOLD%^%^BLACK%^, %^GREEN%^farm implements%^BOLD%^%^BLACK%^, %^ORANGE%^weapons%^BOLD%^"
          +"%^BLACK%^ and even %^CYAN%^armour%^BOLD%^%^BLACK%^ line the walls. A central, bellows-"
          +"driven furnace is long since cold, but there is fuel enough for that, as well as a couple"
          +" of open braziers. Hammers, punches, grips and assorted tools of the blacksmith's trade"
          +" are around the place. There are two or three anvils of different sizes, but they"
          +" don't appear to have seen much use lately.";
    break;
  case 8..9:
    desc = "The %^RESET%^smithy looks well on its way to being usable once more, after a lengthy"
          +" period of %^BOLD%^%^BLACK%^neglect%^RESET%^. Some of the surfaces are still"
          +" coated in %^GREEN%^grease%^RESET%^ and %^BOLD%^%^BLACK%^gr%^RESET%^i%^BOLD%^%^BLACK%^me"
          +"%^RESET%^, but most have been cleaned. Most of the %^ORANGE%^tools%^RESET%^,%^CYAN%^"
          +" weapons%^RESET%^ and%^BOLD%^%^BLACK%^ armour%^RESET%^ on the various %^BOLD%^%^BLACK%^"
          +"racks%^RESET%^ around the walls have been sorted and stored in an orderly fashion. The"
          +" floor has"
          +" been swept, and just needs a little more scrubbing to make it look nice. A central,"
          +" bellows-driven furnace is long since cold, but there is fuel enough for that, as well as"
          +" a couple of open braziers. Hammers, punches, grips and assorted tools of the blacksmith's"
          +" trade are stored here. There are two or three anvils of different sizes, but they"
          +" don't appear to have seen much use lately.";
    break;
  default:
    desc = "This is a relatively clean, neatly ordered smithy. %^ORANGE%^Tools%^RESET%^,%^CYAN%^"
          +" weapons%^RESET%^ and%^BOLD%^%^BLACK%^ armour%^RESET%^ are stored in an orderly fashion in"
          +" %^ORANGE%^racks%^RESET%^ lining the walls. The floor is clean and free of obstructions."
          +" Hammers, punches, grips and assorted tools of the blacksmith's trade are available at"
          +" hand. A central, bellows-driven %^BOLD%^%^RED%^f%^RESET%^%^RED%^u%^BOLD%^%^RED%^rn"
          +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^ce%^RESET%^ is lit on a slow burn. There is plenty of fuel"
          +" available for the furnace, as well as a couple of open %^BOLD%^%^BLACK%^br"
          +"%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^z%^RED%^i%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^."
          +" There are two or three %^BOLD%^%^BLACK%^anvils%^RESET%^ of different sizes, all ready for"
          +" use.";
     break;
  }
  return desc;
}
string dust_desc(){
  string desc;
  switch (cleaned){
  case 0:
    desc = "The %^BOLD%^%^BLACK%^smithy%^RESET%^ looks absolutely filthy and neglected";
    break;
  case 1..7:
   desc = "%^BOLD%^%^BLACK%^The %^RESET%^smithy%^BOLD%^%^BLACK%^ looks pretty grimy and untended. Most"
         +" of the %^RESET%^surfaces%^BOLD%^%^BLACK%^ are covered with soot and %^RESET%^greas%^BOLD%^"
          +"%^BLACK%^e. There are some signs that someone may have made an effort towards cleaning it"
          +" up recently, but there is a long way to go. ";
    break;
  case 8..9:
    desc = "The %^RESET%^smithy looks well on its way to being usable once more, after a lengthy"
          +" period of %^BOLD%^%^BLACK%^neglect%^RESET%^. Some of the surfaces are still"
          +" coated in %^GREEN%^grease%^RESET%^ and %^BOLD%^%^BLACK%^gr%^RESET%^i%^BOLD%^%^BLACK%^me"
          +"%^RESET%^, but most have been cleaned.";
    break;
  default:
    desc = "You can't see much dust, dirt or grime. Someone has done a good job of cleaning the"
          +" smithy recently.";
     break;
  }
  return desc;
}

int make_em(string str){
  int skill;
  mapping smithing;
  if (!stringp(str)){return 0;}
  if (cleaned<10){
    tell_object(TP, "The smithy is just too filthy for you to want to make anything here");
    tell_room(TO, TPQCN + " tries to make something, but gives up when " + TP->QS + " sees the state"
                +" of the smithy",TP);
    return 1;
  }
  if (str == "weapon" || str == "weapons"){
    if (member_array(TP, weapon_makers)!=-1){
      tell_object(TP, "You are already making weapons");
      return 1;
    }
    skill = TP->query_skill("craft, weaponsmith");
    if (skill<0){
      tell_object(TP, "You really wouldn't know where to begin with making weapons");
      return 1;
    }
    if (skill<5){
      tell_object(TP, "You don't really have the skills to make reasonable quality weapons yet");
      return 1;
    }
    if (member_array(TP, bow_makers)!=-1){
      tell_object(TP, "You stop making bows");
      tell_room(TO, TPQCN + "%^RESET%^ stops making bows", TP);
      bow_makers -= ({TP});
    }
    if (member_array(TP, armour_makers)!=-1){
      tell_object(TP, "You stops making armour");
      tell_room(TO, TPQCN + "%^RESET%^ stops making armour", TP);
      armour_makers -= ({TP});
    }
    tell_object(TP, "You set about making weapons in the smithy");
    tell_room(TO, TPQCN + "%^RESET%^ sets about making weapons in the smithy", TP);
    TP->force_me("pose Making weapons");
    weapon_makers += ({TP});
    return 1;
  }
  if(str=="bow"||str == "bows"){
    if (member_array(TP, bow_makers)!=-1){
      tell_object(TP, "You are already making bows");
      return 1;
    }
    skill = TP->query_skill("craft, weaponsmith");
    if (skill<5){
      tell_object("You don't really have the skills to make reasonable quality bows yet");
      return 1;
    }
    if (member_array(TP, weapon_makers)!=-1){
      tell_object(TP, "You stop making weapons");
      tell_room(TO, TPQCN + "%^RESET%^ stops making weapons", TP);
      weapon_makers -= ({TP});
    }
    if (member_array(TP, armour_makers)!=-1){
      tell_object(TP, "You stops making armour");
      tell_room(TO, TPQCN + "%^RESET%^ stops making armour", TP);
      armour_makers -= ({TP});
    }
    tell_object(TP, "You set about making bows and arrows in the smithy");
    tell_room(TO, TPQCN + "%^RESET%^ sets about making bows and arrows in the smithy", TP);
    bow_makers += ({TP});
    TP->force_me("pose Making bows and arrows");
    return 1;
  }
  if (str == "armor" || str == "armour"){
    if (member_array(TP, armour_makers)!=-1){
      tell_object(TP, "You are already making armour");
      return 1;
    }
    skill = TP->query_skill("craft, weaponsmith");
    if (skill<5){
      tell_object("You don't really have the skills to make reasonable quality armour yet");
      return 1;
    }
    if (member_array(TP, bow_makers)!=-1){
      tell_object(TP, "You stop making bows");
      tell_room(TO, TPQCN + "%^RESET%^ stops making bows", TP);
      weapon_makers -= ({TP});
    }
    if (member_array(TP, weapon_makers)!=-1){
      tell_object(TP, "You stops making weapons");
      tell_room(TO, TPQCN + "%^RESET%^ stops making weapons", TP);
      armour_makers -= ({TP});
    }
    tell_object(TP, "You set about making armour in the smithy");
    tell_room(TO, TPQCN + "%^RESET%^ sets about making armour in the smithy", TP);
    TP->force_me("pose Making weapons");
    return 1;
  }
  tell_object(TP, "This is a smithy. You could probably make %^BOLD%^%^YELLOW%^weapons%^RESET%^,"
                 +" %^BOLD%^%^YELLOW%^bows%^RESET%^ or %^BOLD%^%^YELLOW%^armour%^RESET%^ here");
  return 1;
}

object get_weapon(){
  object ob;
  string what;
  what = WBASE + WPNS[random(sizeof(WPNS))];
  ob = new(what);
  return ob; 
}

object get_armour(){
  object ob;
  string what;
    what = ABASE + ARMRS[random(sizeof(ARMRS))];
  ob = new(what);
  return ob; 
}

int equip_em(string str){
  string what;
  object ob, arrows;
  if (!stringp(str) || sscanf(str, "with %s", what)<1){
    tell_object(TP, "You might be able to %^BOLD%^%^YELLOW%^<equip with weapons>%^RESET%^,"
                   +" %^BOLD%^%^YELLOW%^<equip with armour>%^RESET%^ or %^BOLD%^%^YELLOW%^<equip with"
                   +" bows>%^RESET%^. Look at the racks, to see what's available.");
    return 1;
  }
  if (what == "weapon"){
    if (weapons<1){
      tell_object(TP, "There are no weapons here to equip yourself with");
      return 1; 
    }
    ob = get_weapon();
    if (!objectp(ob)){
      tell_room(TO, "There's been a problem with making a weapon for equipping someone with. Please"
                   +" tell Lujke, or make a bug report from this room. Thanks.");
      return 1;
    }
    tell_object(TP, "You help yourself to a " + ob->query_name() + " from the racks");
    tell_room(TO, TPQCN + "%^RESET%^ helps " + TP->QO + "self to a weapon from the racks", TP);
    ob->move (TP);
    weapons --;
    if (!interactive(TP)){
      what = ob->query_id();
      TP->force_me("wield " + what[0]);
    }
    return 1;
  }
  if (what == "armour" || what == "armor"){
    if (armour<1){
      tell_object(TP, "There is not armour here to equip yourself with");
      return 1; 
    }
    ob = get_armour();
    if (!objectp(ob)){
      tell_room(TO, "There's been a problem with making armour for equipping someone with. Please"
                   +" tell Lujke, or make a bug report from this room. Thanks.");
      return 1;
    }
    tell_object(TP, "You help yourself to some " + ob->query_name() + " from the racks");
    tell_room(TO, TPQCN + "%^RESET%^ helps " + TP->QO + "self to some armour from the racks", TP);
    ob->move (TP);
    armour --;
    if (!interactive(TP)){
      what = ob->query_id();
      TP->force_me("wear " + what[0]);
    }
    return 1;
  }
  if (what == "bow" || what == "bow and arrows"){
    if (bows<1){
      tell_object(TP, "There are no bows here to equip yourself with");
      return 1; 
    }
    ob = new("/d/common/obj/lrweapon/shortbow");
    if (!objectp(ob)){
      tell_room(TO, "There's been a problem with making armour for equipping someone with. Please"
                   +" tell Lujke, or make a bug report from this room. Thanks.");
      return 1;
    }
    tell_object(TP, "You help yourself to a " + ob->query_name() + " and some arrows from the racks");
    tell_room(TO, TPQCN + "%^RESET%^ helps " + TP->QO + "self to a bow and some arrows from the"
                 +" racks", TP);
    ob->move (TP);
    arrows = new("/d/common/obj/lrweapon/arrows");
    arrows->move(TP);
    arrows = new("/d/common/obj/lrweapon/arrows");    //repeated to provide 2 lots of arrows
    arrows->move(TP); 
    bows --;
    if (!interactive(TP)){
      what = ob->query_id();
      TP->force_me("wear " + what[0]);
    }
    return 1;
  }
  return 0;
}

int clean_me(string str){
  if (cleaned >10){
    tell_object(TP, "This is probably about as clean as a smithy is likely to get");
    return 1;
  }
  if (str != "up"){
    tell_object(TP, "The place might look better if you %^BOLD%^%^YELLOW%^<tidy up>");
    return 1;
  }
  if ((int)TP->query_property("cleaning")==1){
    tell_object(TP, "You are already cleaning up");
    return 1;
  }
  if ((int)TP->query_property("busy")==1){
    tell_object(TP, "You are busy doing something else");
    return 1;
  }
  TP->set_property("busy");
  TP->set_property("cleaning");
  tell_object(TP, "You set about cleaning the forge");
  tell_room(TO, TPQCN + "%^RESET%^ sets about cleaning the forge", TP);
  call_out("clean2", 2, TP);
  return 1;
}

void clean2(object ob){
  if (!objectp(ob)){
    return;
  }
  if (!present(ob, TO)){
    tell_object(ob, "You are no longer in the forge, so you stop tidying");
    ob->remove_property("cleaning");
    ob->remove_property("busy");
    return;
  }
  cleaned ++;
  if (cleaned >9){
    tell_object(ob, "You have finished cleaning the forge");
    tell_room(TO, (string)ob->QCN + " finishes cleaning the forge", ob);
    return;
  }
  switch(random(12)){
  case 0:
    tell_object(ob, "You work at scrubbing down one of the %^ORANGE%^work benches%^RESET%^, removing a"
                   +" thick layer of %^BOLD%^%^BLACK%^grime%^RESET%^.");
    tell_room(TO,(string)ob->QCN + "%^RESET%^works at scrubbing down one of the %^ORANGE%^work benches"
                 +"%^RESET%^, removing a thick layer of %^BOLD%^%^BLACK%^grime%^RESET%^.", ob);
    break;
  case 1:

    break;
  case 2:
    tell_object(ob, "You clean out the %^BOLD%^%^RED%^f%^RESET%^%^RED%^u%^BOLD%^%^RED%^rn%^RESET%^"
                   +"%^RED%^a%^BOLD%^%^RED%^ce");
    tell_room(TO, (string)ob->QCN + " cleans out the %^BOLD%^%^RED%^f%^RESET%^%^RED%^u%^BOLD%^"
                 +"%^RED%^rn%^RESET%^%^RED%^a%^BOLD%^%^RED%^ce", ob);
    break;
  case 3:
    tell_object(ob, "You tidy away some of the tools");
    tell_room(TO, (string)ob->QCN +  " tidies away some of the tools", ob);
    break;
  case 4:
    tell_object(ob, "You clean up some %^ORANGE%^rusty%^RESET%^ tools with a wire brush");
    tell_room(TO,(string)ob->QCN +  " cleans up some %^ORANGE%^rusty%^RESET%^ tools with a wire brush",
                ob);
    break;
  case 5:
    tell_object(ob, "You sweep the floor");
    tell_room(TO, (string)ob->QCN + " sweeps the floor", ob);
    break;
  case 6:
    tell_object(ob, "You get down on your hands and knees to scrub the floor");
    tell_room(TO, (string)ob->QCN + "gets down on " + ob->QP + " hands and knees to scrub the floor",
                 ob);
    break;
  case 7:
    tell_object(ob, "You polish an anvil");
    tell_room(TO, (string)ob->QCN + " polishes an anvil", ob);
    break;
  case 8:
    tell_object(ob, "You mop up something %^ORANGE%^%^%^sticky%^RESET%^ and %^GREEN%^unpleasant"
                   +" %^RESET%^smelling from the floor");
    tell_room(TO, (string)ob->QCN + " mops up something %^ORANGE%^sticky%^RESET%^ and"
                 +" %^GREEN%^unpleasant%^RESET%^ smelling from the floor", ob);
    break;
  case 9:
    tell_object(ob, "You try to polish out a damn spot");
    tell_room(TO, (string)ob->QCN + " tries to polish out a damn spot", ob);
    break;
  case 10:
    tell_object(ob, "You sweep the floor");
    tell_room(TO, (string)ob->QCN + " sweeps the floor", ob);
    break;  
  case 11:
    tell_object(ob, "You throw open the shutters, to let some fresh air in");
    tell_room(TO, (string)ob->QCN + " throws open the shutters to let some fresh air in", ob);
    break;  
  }
  call_out("clean2", 2 + random(3), ob);
}