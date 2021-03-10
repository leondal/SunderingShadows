#define TEC_SEAL_D "/realms/lujke/daemon/tecqumin_seal_d"
#include <std.h>
#include <move.h>
#include <daemons.h>
#include "/d/atoyatl/tecqumin/tecqumin.h"

inherit ROOM;
int seal_revealed, seal_strengthened, seal_broken;

string long_desc();

void create() {
  ::create();
  seal_revealed = 0;
  seal_strengthened = 0;
  seal_broken = 0;
  set_indoors(1);
  set_property("light", 2);
  set_terrain(NAT_TUNNEL);
  set_travel(SLICK_FLOOR);
  set_name("A rock walled cavern");
  set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^ORANGE%^rock%^BOLD%^%^BLACK%^"
    +" walled c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^"
    +"%^BLACK%^rn");
  set_long( "%^ORANGE%^A large, semicircular cavern opens out beneath the"
    +" ground. It is cut from %^RESET%^local stone%^ORANGE%^, apart from"
    +" the very back wall. That wall is formed of %^BOLD%^%^BLACK%^h"
    +"%^RESET%^e%^BOLD%^%^BLACK%^xag%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^nal"
    +" bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck %^BOLD%^%^BLACK%^b"
    +"%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^lt"
    +"%^RESET%^%^ORANGE%^. It looms over the space like a %^BLUE%^curse"
    +"%^RESET%^%^ORANGE%^, and exudes a %^BOLD%^%^BLACK%^dark sense"
    +"%^RESET%^%^ORANGE%^ of %^BOLD%^%^BLACK%^menace%^RESET%^%^ORANGE%^.");
  set_items (([ ({"wall", "back wall", "basalt wall", "black wall",
    "columns", "black basalt wall", "hexagonal basalt wall", "basalt columns",
    "basalt", "black hexagonal basalt wall"}): "%^BOLD%^%^BLACK%^The wall"
    +" is formed of dozens and dozens of  %^BOLD%^%^BLACK%^h"
    +"%^RESET%^e%^BOLD%^%^BLACK%^xag%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^nal"
    +" bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck %^BOLD%^%^BLACK%^b"
    +"%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^lt"
    +" columns, running from floor to ceiling and edge to edge"
    +" of the cave. In the centre of the wall, a group of the hexagonal faces"
    +" carry strange %^BOLD%^%^WHITE%^m%^RESET%^a%^BOLD%^%^WHITE%^"
    +"rkings%^RESET%^.",
    ({"markings", "markings", "strange markings", "block", "blocks", "image", "new image"}): (:TO, "view_markings" :),
    ({"blank square", "square", "squares"}):"All of the hexagons have"
    +" markings. There is a strange energy to the markings; it"
    +" doesn't make you feel like touching them.",
    ({"eye"}): (:TO, "view_eye" :),
    ({"seal", "mystic seal"}): (:TO, "view_seal":),
    ({"jewel", "wrist"}): (:TO, "view_wrist" :),
    ({"gauntlet", "upright gauntlet", "war gauntlet", "upright war gauntlet"}): (:TO, "view_gauntlet" :),
    ({"blank square", "square", "squares"}):"All of the hexagons have"
    +" markings. There is a strange energy to the markings; it"
    +" doesn't make you feel like touching them.",
    ({"blank square", "square", "squares"}):"All of the hexagons have"
    +" markings. There is a strange energy to the markings; it"
    +" doesn't make you feel like touching them.",
    ({"blank square", "square", "squares"}):"All of the hexagons have"
    +" markings. There is a strange energy to the markings; it"
    +" doesn't make you feel like touching them." ]) );
  set_smell("default","There is an odd, faintly metallic smell in the air");
  set_listen("default","Sounds of the jungle drift down from above. There"
    +" are occasional tinkling sounds, like rocks under great pressure.");
  set_exits( (["up": JUNG_ROOM10 + "carved_gate"]) );
}
void init() {
  object * critters;
  string * quests;
  int i, count, flag;
   ::init();
  add_action("touch_blocks", "touch");
  add_action("touch_blocks", "push");
  add_action("touch_blocks", "press");
  add_action("touch_blocks", "stroke");
  add_action("touch_blocks", "poke");
  add_action("touch_blocks", "finger");
  add_action("touch_blocks", "punch");
  add_action("check_grid", "check");
  add_action("study_me", "study");
  if (seal_revealed == 0){
    if(HEXER_D->check_completed()>0){
      tell_room(TO, "%^BOLD%^%^BLACK%^The black b%^RESET%^a%^BOLD%^%^BLACK%^"
        +"s%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^lt columns slide back into"
        +" place, with a new %^RESET%^image %^BOLD%^%^BLACK%^covering what"
        +" lays beneath.");
      HEXER_D->set_new_pic();
    }
    if (completed_quest(TP) && !TP->query_true_invis()){
      flag = 0;
      critters = all_living(TO);
      count = sizeof(critters);
      for (i=0;i<count;i++){
        if (!interactive(critters[i])){
          continue;
        }
        if (completed_quest(critters[i])==-1){
          flag = 1;
          break;
        }
      }
      if (flag == 0){
        call_out("auto_reveal", 2, TP);
      }
    }
  }

}

void reset(){
  ::reset();
  if (!query_had_players())
  {
    seal_revealed = 0;
    seal_strengthened = 0;
    seal_broken = 0;
    HEXER_D->remove();
  }
}

int break_seal(string str){
  if (str != "seal" && str != "the seal"){
    return notify_fail("do you want to break the seal?");
  }
  tell_object(TP, "You don't have any power that would allow you to do that,"
    +" unaided. Perhaps if you had an object with sufficient power invested"
    +" in it, and the right sort of enchantments to focus that power, there"
    +" might be a way?");
  return 1;
}

int query_seal_broken(){
  return seal_broken;
}

void set_seal_broken(int i){
  seal_broken = i;
}

int study_me(string str){
  object ob;
  if (!seal_revealed){
    return notify_fail("You can't see that here");
  }
  if (str != "eye" && str != "eye of helm" && str != "blue eye" && str != "repository" && str != "repository of Helm" && str != "blue eye on gauntlet" && str != "eye on gauntlet"){
    if (str != "wrist" && str != "jewel on wrist" && str != "jewel" && str != "jewel on gauntlet" && str != "aventurine" && str != "blue aventurine" && str != "aventurine on gauntlet"){
      return notify_fail("You can't see that here");
    } else {
      ob = new(OBJ + "aventurine");
      ob->move(TP);
      TP->force_me("study blue aventurine of Helm");
      ob->move("/d/shadowgate/void");
      return 1;
    }
    return notify_fail("You can't see that here");
  } else {
    ob = new(OBJ + "eyeofhelm");
    ob->move(TP);
    TP->force_me("study blue eye of Helm");
    ob->move("/d/shadowgate/void");
    return 1;
  }
}

void summon_unfettered(){
  object unf;
  unf = new (MOB + "unfettered_main");
  unf->move(TO);

}

int query_seal_revealed(){
  return seal_revealed;
}

string view_eye(){
  if (!seal_revealed){
    return "You can't see that here";
  }
  return "The eye is the repository of Helm's watchful strength. You"
    +" could study it, if you think you might have knowledge of that"
    +" sort of thing.";
}

string view_wrist(){
  if (!seal_revealed){
    return "You can't see that here";
  }
  return "The %^BOLD%^%^CYAN%^bl%^BLUE%^ue"
   +" av%^RESET%^%^BLUE%^e%^BOLD%^nturi%^CYAN%^ne%^RESET%^"
   +" gl%^BOLD%^%^WHITE%^i%^RESET%^tters bright on the wrist of the"
   +" gauntlet. You could study it, if you have knowledge of that"
   +" sort of thing.";

}

string view_gauntlet(){
  if (!seal_revealed){
    return "You can't see that here";
  }
}

int completed_quest(object ob){
  string * quests;
  if (TP->query_true_invis()) return 0;
  quests = TP->query_mini_quests();
  if (sizeof(quests)>0 && member_array("Arranged the blocks to reveal the seal on the Unfettered's cage", quests)!=-1){
    return 1;
  }
  return 0;
}

void auto_reveal(object ob){
  if (!objectp(ob) || !present(ob, TO)){
    return;
  }
  tell_object(ob, "As you enter the room, the markings on the"
    +" %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^"
    +"a%^BOLD%^%^BLACK%^lt columns%^RESET%^ recognize you and rearrange"
    +" themselves to form an image");
  tell_room(TO, "As " + ob->QCN + "%^RESET%^ enters the room, the markings"
    +" on the %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^"
    +"%^BLUE%^a%^BOLD%^%^BLACK%^lt columns%^RESET%^ recognize "+ ob->QO
    +" and rearrange themselves to form an image");
  call_out("reveal_seal", 3);
}

int touch_blocks(string str){
  string what, which, result, * quests;
  int num, rows, columns;
  num = sscanf(str, "%s %s", what, which);
  if (num <2){
    what = str;
  }
  if (what != "block" && what != "hexagon" && what != "marking" && what != "blocks"
         && what != "markings" && what != "column"  && what != "image"){
    return notify_fail("Do you want to %^ORANGE%^touch%^RESET%^ one of"
      +" the blocks?");
  }
  if (num <2){
    tell_object(TP, "You'll need to say which block you want to touch,"
      +" by specifying a hexagon by letter. For example: 'touch block"
      +" A'");
    tell_object(TP, "To see the letters for the different hexagons"
      +",%^ORANGE%^ <check letters>");
    return 1;
  }
  which = upper_case(which);
  if (HEXER_D->is_a_hex(which)==-1){
    tell_object(TP, which + " is not a hexagon letter. To see the letters for the different hexagons"
      +",%^ORANGE%^ <check letters>");
    return 1;
  }
  if (seal_revealed == 1){
    tell_object(TP, "The heagonal blocks have moved aside to reveal a new image beneath");
    return 1;
  }
  if (HEXER_D->query_highlight() == "none"){
    tell_object(TP, "%^BOLD%^%^BLUE%^As your fingers brush the %^RESET%^"
      +"marking%^BOLD%^%^BLUE%^, the hex beneath it begins to %^RESET%^"
      +"%^RED%^gl%^BOLD%^o%^RESET%^%^RED%^w r%^RESET%^e%^RESET%^%^RED%^"
      +"d%^BLUE%^.");
    tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " %^BOLD%^%^BLUE%^touches"
      +" one of the basalt columns. As " + TP->QP + " fingers brush the"
      +" %^RESET%^marking%^BOLD%^%^BLUE%^, the hex beneath it begins to"
      +" %^RESET%^%^RED%^gl%^BOLD%^o%^RESET%^%^RED%^w r%^RESET%^e"
      +"%^RESET%^%^RED%^d%^BLUE%^.", TP);
    HEXER_D->highlight_hex(which);
    return 1;
  }
  if (which == HEXER_D->query_highlight()){
    tell_object(TP, "%^BOLD%^%^BLUE%^As your fingers brush the %^RESET%^"
      +"marking%^BOLD%^%^BLUE%^, the %^RED%^gl%^BOLD%^%^RED%^o%^RESET%^"
      +"%^RED%^w %^RESET%^beneath it begins to %^RESET%^fade%^BOLD%^"
      +"%^BLUE%^.");
    tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " %^BOLD%^%^BLUE%^touches"
      +" one of the basalt columns. As " + TP->QP + " fingers brush the"
      +" %^RESET%^marking%^BOLD%^%^BLUE%^, the %^RED%^gl%^BOLD%^%^RED%^"
      +"o%^RESET%^%^RED%^w %^RESET%^beneath it begins to %^RESET%^fade"
      +"%^BOLD%^%^BLUE%^.", TP);
    HEXER_D->highlight_hex("none");
    return 1;
  }
  tell_object(TP, "Comparing hex " + which + " to hex: " + HEXER_D->query_highlight());
  if (HEXER_D->can_swap(which, HEXER_D->query_highlight())==-1){
    tell_object(TP, "%^BOLD%^%^BLUE%^As your fingers brush the %^RESET%^"
      +"marking%^BOLD%^%^BLUE%^, the image you touch, and the one"
      +" currently %^RESET%^%^RED%^glo%^RESET%^%^RED%^wi%^RESET%^%^RED%^ng"
      +" re%^RESET%^%^RED%^d %^BOLD%^%^BLUE%^suddenly"
      +" %^BOLD%^%^CYAN%^fl%^BLUE%^a%^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^h"
      +" %^BOLD%^%^BLUE%^b%^CYAN%^lue%^BOLD%^%^BLUE%^, then both fade back"
      +" to %^RESET%^normal%^BOLD%^%^BLUE%^. You think it might be because"
      +" they were not the same shape as each other.");
    tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " %^BOLD%^%^BLUE%^touches"
      +" one of the basalt columns. As " + TP->QP + " fingers brush the"
      +" %^RESET%^marking%^BOLD%^%^BLUE%^, the image " + TP->QS
      +" touches, and the one currently"
      +" %^RESET%^%^RED%^glo%^RESET%^%^RED%^wi%^RESET%^%^RED%^ng"
      +" re%^RESET%^%^RED%^d %^BOLD%^%^BLUE%^suddeny"
      +" %^BOLD%^%^CYAN%^fl%^BLUE%^a%^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^h"
      +" %^BOLD%^%^BLUE%^b%^CYAN%^lue%^BOLD%^%^BLUE%^, then both fade"
      +" back to %^RESET%^normal%^BOLD%^%^BLUE%^.", TP);
    HEXER_D->highlight_hex("none");
    return 1;
  }
  tell_object(TP, "%^BOLD%^%^BLUE%^As your fingers brush the %^RESET%^"
    +"marking%^BOLD%^%^BLUE%^, the image flickers away from your fingers,"
    +" swapping places with the one on the %^RESET%^%^RED%^gl%^BOLD%^o"
    +"%^RESET%^%^RED%^w%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng c%^BOLD%^o"
    +"%^RESET%^%^RED%^l%^BOLD%^u%^RESET%^%^RED%^mn%^BOLD%^%^BLUE%^."
    +" Once they settle down, the %^RESET%^%^RED%^gl%^BOLD%^o%^RESET%^"
    +"%^RED%^w %^RESET%^fades away%^BOLD%^%^BLUE%^.");
  tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " %^BOLD%^%^BLUE%^touches"
    +" one of the basalt columns. As " + TP->QP + " fingers brush the"
    +" %^RESET%^marking%^BOLD%^%^BLUE%^, the image flickers away from"
    + TP->QP + " fingers, swapping places with the one on the"
    +" %^RESET%^%^RED%^gl%^BOLD%^o%^RESET%^%^RED%^w%^BOLD%^%^RED%^i"
    +"%^RESET%^%^RED%^ng c%^BOLD%^o%^RESET%^%^RED%^l%^BOLD%^u%^RESET%^"
    +"%^RED%^mn%^BOLD%^%^BLUE%^. Once they settle down, the"
    +" %^RESET%^%^RED%^gl%^BOLD%^o%^RESET%^%^RED%^w %^RESET%^fades away"
    +"%^BOLD%^%^BLUE%^.", TP);
  HEXER_D->swap_hexes(which, HEXER_D->query_highlight());
  HEXER_D->highlight_hex("none");
  if (HEXER_D->check_completed()==1){
    call_out("reveal_seal", 2);
  }
  quests = TP->query_mini_quests();
  if (member_array("Arranged the blocks to reveal the seal on the Unfettered's cage", quests)==-1){
    TP->set_mini_quest("Arranged the blocks to reveal the seal on the Unfettered's cage");
  }
  return 1;
}


varargs void grant_quest(object sealer, string quest, int exp,
                              string explanation, int must_be_near){
  object leader, * party, found_thing;
  string name, party_name, * quests;
  int i, count;
  if (!objectp(sealer)){
    return;
  }
  leader = sealer->query_property("minion");
  if (objectp(leader)){
    sealer = leader;
  }
  party_name = "/adm/daemon/party_d.c"->party_member(sealer);
  party = "/adm/daemon/party_d.c"->query_party_members(party_name);
  count = sizeof(party);
  if (count>0){
    for (i=0;i<count;i++){
      name = party[i]->query_name();
      found_thing = PATHFINDER_D->far_present(ETO, name, 4);
      if (must_be_near && !objectp(found_thing)){
        continue;
      }
      tell_object( party[i],explanation);
      quests = party[i]->query_mini_quests();
      if (member_array(quest, quests)!= -1){
        continue;
      }
      party[i]->set_mini_quest(quest);
      party[i]->add_exp(exp);
    }
  }
}

int check_grid(string str){
  if (str != "the letters" && str != "letters"){
    tell_object(TP, "Do you want to check the letters?");
    return 0;
  }
  if (seal_revealed == 1){
    tell_object(TP, "The heagonal blocks have moved aside to reveal a new image beneath");
    return 1;
  }
  HEXER_D->show_pic(TP,1);
  return 1;
}

string view_seal(){
  string desc;
  desc = "The rock underneath the image of the %^BOLD%^%^CYAN%^e%^BLUE%^y"
    +"%^CYAN%^e%^RESET%^ of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l"
    +"%^BLUE%^m%^RESET%^ has been shaped into a %^BOLD%^%^GREEN%^mystic"
    +" s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^.";
  if (seal_strengthened == 1){
    desc += " The %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a"
      +"%^BOLD%^%^GREEN%^l%^RESET%^ %^BOLD%^%^GREEN%^gl%^RESET%^ea%^BOLD%^"
      +"%^WHITE%^ms%^RESET%^ with intense %^BOLD%^%^YELLOW%^p%^RESET%^"
      +"%^ORANGE%^o%^BOLD%^%^YELLOW%^w%^RED%^e%^YELLOW%^r%^RESET%^. It"
      +" looks very solid and secure.";
  } else {
    if (seal_broken == 1)
    {
      desc += " The %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a"
        +"%^BOLD%^%^GREEN%^l%^RESET%^ is %^BOLD%^%^BLACK%^broken%^RESET%^."
        +" The image of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l"
        +"%^BLUE%^m%^RESET%^'s watchful %^BOLD%^%^CYAN%^e%^BLUE%^y"
        +"%^CYAN%^e%^RESET%^ has been wrenched open wide, and whatever was"
        +" confined by the enchantments it held is no longer trapped.\n\n"
        +"Oh dear. This is probably not good news.";
    } else
    {
      desc += " The ^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^GREEN%^l"
        +"%^RESET%^ looks aged and faded, covered over with a"
        +" %^ORANGE%^p%^BOLD%^%^BLACK%^a%^ORANGE%^t%^RESET%^i%^ORANGE%^n"
        +"%^BOLD%^%^BLACK%^a of %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o"
        +"%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^pt"
        +"%^RESET%^%^GREEN%^io%^BOLD%^%^GREEN%^n%^RESET%^. It doesn't"
        +" inspire confidence in its ability to hold whatever is inside much"
        +" longer.";
    }
  }
  return desc;
}

string view_markings(){
  string desc;
  if (seal_revealed == 1){
    desc = "%^BOLD%^%^WHITE%^The heagonal %^BOLD%^%^BLACK%^blocks%^RESET%^"
      +" have moved aside to reveal a new image beneath. You recognize the"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e %^RESET%^of %^BOLD%^%^RED%^H"
      +"%^RESET%^e%^BOLD%^%^WHITE%^l%^BLUE%^m%^RESET%^ on an upright war"
      +" gauntlet. Underneath the image, the %^BOLD%^%^BLACK%^rock%^RESET%^"
      +" forms a %^BOLD%^%^GREEN%^mystic s%^RESET%^%^GREEN%^e%^ORANGE%^a"
      +"%^BOLD%^%^GREEN%^l%^RESET%^. %^BLUE%^Something%^RESET%^ must be"
      +" trapped inside.";
  } else {
  desc = "%^BOLD%^%^BLUE%^The markings lie on the hexagonal surfaces of the basalt columns."
    +" You can't make much sense of them. A strange energy"
    +" comes from them, which does not make you feel like touching"
    +" them.";
  }
  HEXER_D->show_pic(TP);
  return desc;
}



void reveal_seal5(object ob){
  tell_room(TO, "As the new image becomse clear, you recognise"
    +" %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^RED%^l%^BLUE%^m'%^RESET%^s"
    +" staring %^CYAN%^e%^BOLD%^%^BLUE%^y%^RESET%^%^CYAN%^e%^RESET%^"
    +" emblazoned on an upright war gauntlet. ");
  tell_room(TO, "The %^CYAN%^e%^BOLD%^%^BLUE%^y%^RESET%^%^CYAN%^e%^RESET%^"
    +" is an obvious point of power in the image, as is the%^BOLD%^%^CYAN%^"
    +" je%^BLUE%^w%^CYAN%^el%^RESET%^ placed over the wrist of the gauntlet.");
}

void reveal_seal4(object ob){
  object * critters;
  int i, count;
  critters = all_living(TO);
  HEXER_D->set_helm_pic();
  count = sizeof(critters);
  for (i = 0; i<count; i++){
    if (interactive(critters[i])){
      HEXER_D->show_pic(critters[i]);
    }
  }
  seal_revealed = 1;
  call_out("reveal_seal5", 3);
}

void reveal_seal3(object ob){
    tell_room(TO, "The completed image holds in place for a moment, then"
    " one after another of the hexagonal basalt columns slides out of the"
    +" the way, revealing a whole new image beneath.");
  call_out("reveal_seal4", 4, ob);
}


void reveal_seal2(object ob){
  object * critters;
  int i, count;
  HEXER_D->setup_hex_blocks();
  HEXER_D->setup_hex_positions();
  critters = all_living(TO);
  count = sizeof(critters);
  for (i = 0; i<count; i++){
    if (interactive(critters[i])){
      HEXER_D->show_pic(critters[i]);
    }
  }
  call_out("reveal_seal3", 4, ob);
}


void reveal_seal(object ob){
  tell_room(TO, "%^BOLD%^%^BLUE%^As the last image slides into"
    +" position, the whole picture on the wall becomes clear.");
  call_out("reveal_seal2", 3, ob);
}

void set_seal_strengthened(int i){
  seal_strengthened = i;
}

int query_seal_strengthened(){
  return seal_strengthened;
}

void strengthen_seal(){
  seal_strengthened = 1;
}
