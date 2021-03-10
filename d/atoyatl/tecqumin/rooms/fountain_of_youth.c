#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;
int calculate_target_age(object ob);


string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("A magical fountain");
  set_short("%^RESET%^%^BOLD%^%^MAGENTA%^A %^BLUE%^f%^CYAN%^o%^BLUE%^unt"
           +"%^CYAN%^a%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^n %^MAGENTA%^of "
           +"%^YELLOW%^y%^BOLD%^%^WHITE%^o%^YELLOW%^uth%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_search("default", "You notice that one of the trees at the edge of the clearig seems to have a doorway marked in its trunk");
  set_items(([  ({ "frescoes", "ornate frescoes"}) :
               "%^BOLD%^CYAN%^The fountain frescoes depict scenes of"
              +" %^BOLD%^%^GREEN%^springtime%^RESET%^%^CYAN%^, %^BOLD%^"
              +"%^YELLOW%^youth%^CYAN%^ and %^BOLD%^%^MAGENTA%^renewal"
              +"%^BOLD%^%^CYAN%^." ,
                ({"portal", "door", "tree", "tree door",}): "An old"
      +" %^ORANGE%^higurion %^GREEN%^t%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e"
      +"%^RESET%^, wide at the base but stunted in height, sits on the"
      +" border of the clearing. In the bark of its trunk, the cracks form"
      +" the outline of a doorway. You think that you could possibly enter it",

               "urn": "The urn whose neck forms the spout of the"
      +" %^BOLD%^%^CYAN%^f%^BLUE%^ou%^CYAN%^nt%^WHITE%^a%^BLUE%^i%^CYAN%^n"
      +" %^RESET%^is about four feet in height, with curly handles carved"
      +" in the shape of a"
      +" %^BOLD%^%^MAGENTA%^f%^CYAN%^ea%^MAGENTA%^th%^GREEN%^e%^YELLOW%^r"
      +"%^GREEN%^e%^MAGENTA%^d"
      +" %^GREEN%^s%^RESET%^%^GREEN%^e%^BOLD%^rp%^RESET%^%^GREEN%^e%^BOLD%^"
      +"nt%^RESET%^ leaping up a hillside",
               ({"fountain", "stone fountain", "ornate fountain", "ornate stone fountain"}):
       "%^BOLD%^%^CYAN%^The fountain is made of %^RESET%^grey"
      +"%^BOLD%^%^CYAN%^ and %^ORANGE%^cream %^BOLD%^%^CYAN%^stone. It has"
      +" a circular base and %^BOLD%^%^BLUE%^pool%^CYAN%^, with ornate"
      +" %^BOLD%^%^WHITE%^frescoes %^CYAN%^carved on the outside. The centre"
      +" is dominated by a plinth that carries a decorative, double handled"
      +" %^RESET%^%^ORANGE%^urn%^BOLD%^%^CYAN%^. The neck of the urn forms"
              +" the spout of the %^BOLD%^%^BLUE%^f%^BOLD%^%^WHITE%^o"
              +"%^CYAN%^u%^BLUE%^nt%^CYAN%^a%^WHITE%^i%^BLUE%^n%^CYAN%^."
              +" Water pours and bubbles from it, spraying a short way"
              +" into the air before cascading down the plinth and into"
              +" the pool."   ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","You can hear"
                      +" the joyful, invigorating and exuberant"
                      +" sound of water tinkling from the fountain.");
  set_exits( ([ "south"     : ROOMS + "river_beach"]) );
}
void init() {
   ::init();
   add_action("drink_water", "drink");
   add_action("enter_portal", "enter");
}

string long_desc(){
return "%^BOLD%^%^CYAN%^The j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng"
      +"%^BOLD%^%^GREEN%^l%^%^RESET%^%^GREEN%^e %^BOLD%^%^CYAN%^breaks"
      +" into a clearing"
      +" here, revealing a rare glimpse of the %^BOLD%^%^BLUE%^sky"
      +" %^CYAN%^above. A grassy mound sits in the centre of the clearing,"
      +" with an %^BOLD%^%^WHITE%^ornate%^BOLD%^%^BLUE%^ "
      +"f%^CYAN%^o%^BLUE%^unt%^CYAN%^a%^RESET%^%^CYAN%^i%^BOLD%^"
      +"%^BLUE%^n %^BOLD%^%^CYAN%^at the top.";
}

int enter_portal(string str){
  if (str !="portal" && str !="doorway" && str != "door" && str != "tree" && str != "higurion" && str != "higurion tree")
  return -1;
  tell_room(TO, TPQCN + " walks up to an old ^ORANGE%^higurion %^GREEN%^t%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e"
      +"%^RESET%^ at the edge of the clearing, and simply walks into the trunk, vanishing from view", TP);
  tell_object(TP, "You walk up to the %^ORANGE%^higurion %^GREEN%^t%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e"
      +"%^RESET%^ and simply walk into the doorway in its trunk. As you step through, you find yourself somewhere else");
  call_out("depart", 1, TP);
  return 1;
}

int depart(object ob){
  ob->move(JUNG_ROOM7 + "parrot_room");
  ob->force_me("look");
  return 1;
}

int calculate_target_age(object ob){
  string age;
  int i;
  if (!objectp(ob)){
    return -1;
  }
  for (i=10;i<200;i++){
    age = "/cmds/mortal/_stats"->get_age(ob, i);
    if (age == "average"){
      return i-1;
    }
  }
}

int calculate_modifier(object ob){
  int age_now, current_modifier, unmodified_age, target_age;
  if (!objectp(ob)){
    return 0;
  }
  current_modifier = ob->query("age_modifier");
  age_now = ob->query_real_age();
  unmodified_age = age_now-current_modifier;
  target_age = calculate_target_age(ob);
  return target_age - unmodified_age;
}

int set_age_modifier(object ob){
  string age;
  int i, j, orig;
  if (!objectp(ob))
  {
    return -1;
  }
  orig = ob->query("age_modifier");
  for (i=1;i<2000;i++)
  {
    ob->set("age_modifier", (i * -1));
    if (ob->query_real_age_cat() == "child")
    {
      while (ob->query_real_age_cat() == "child" && j<500)
      {
        j++;
        ob->set("age_modifier", (i * -1)+j );
      }

      break;
    }
  }
}


int drink_water(string str){
  str = lower_case(str);
  if (str != "fountain" && str != "from fountain" && str != "water"
     && str !="water from fountain" && str != "from the fountain"){
    return notify_fail ("Did you want to drink from the fountain?");
  }
  tell_object(TP, "%^BOLD%^%^MAGENTA%^You dip your hands into the %^BOLD%^%^BLUE%^pool"
                 +" %^BOLD%^%^MAGENTA%^and drink deeply from the %^BOLD%^%^WHITE%^"
                 +"fr%^BOLD%^%^BLUE%^o%^BOLD%^%^WHITE%^th%^BOLD%^%^CYAN%^i%^BOLD%^"
                 +"%^WHITE%^ng %^BOLD%^%^BLUE%^w%^BOLD%^%^WHITE%^a%^BOLD%^%^BLUE%^"
                 +"t%^CYAN%^e%^BLUE%^r");
  tell_room (TO, "%^BOLD%^%^WHITE%^" + TPQCN + "%^BOLD%^%^MAGENTA%^ dips " + TP->QP
                 +" hands into the %^BOLD%^%^BLUE%^pool %^BOLD%^%^MAGENTA%^and drinks"
                 +" deeply from the %^BOLD%^%^WHITE%^fr%^BOLD%^%^BLUE%^o%^BOLD%^%^WHITE%^"
                 +"th%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^ng %^BOLD%^%^BLUE%^w%^BOLD%^"
                 +"%^WHITE%^a%^BOLD%^%^BLUE%^t%^CYAN%^e%^BLUE%^r", TP);
  call_out("invigorate", 2, TP);
  return 1;
}

void rejuvenate(object ob)
{
    int mod;
    if (!objectp(ob) || !objectp(environment(ob))) {
        return;
    }
    set_age_modifier(ob);
//  mod = calculate_modifier(ob);
//  tell_room(TO, "Rejuvenating " + ob->QCN);
//  ob->set("age_modifier", mod);
}

void invigorate(object ob)
{
    int mod;
    string* quests;
    if (!objectp(ob) || !objectp(environment(ob))) {
        return;
    }
    quests = ob->query_quests();

    // Small adition, hope Lujke won't mind... Illy.
    if (ob->is_vampire()) {
        tell_object(ob, "%^BOLD%^%^GREEN%^You sense your unlife ends here as you drink... You are living again.");
        ob->delete("vampire");
        ob->delete("undead");
    }

    if (EVENT_RECORDS_D->completed_event(ob->query_name(), "Supped the fountain of youth", DAY * 300) > 0) {
        tell_object(ob, "%^BOLD%^%^YELLOW%^The %^BOLD%^%^BLUE%^cool water %^BOLD%^%^YELLOW%^"
                    + "washes down your throat, bringing a %^BOLD%^%^CYAN%^refreshing"
                    + " %^BOLD%^%^YELLOW%^sense of %^BOLD%^%^GREEN%^renewal%^BOLD%^"
                    + "%^YELLOW%^ and %^BOLD%^%^CYAN%^invigoration%^BOLD%^%^YELLOW%^. You"
                    + " are reminded of when you drank from the fountain of youth before.");
        tell_room(environment(ob), (string)ob->QCN + " smiles serenely as  " + (string)ob->QS
                  + " finishes drinking.", ob);
        return;
    }
    tell_object(ob, "%^BOLD%^%^YELLOW%^The %^BOLD%^%^BLUE%^cool water %^BOLD%^%^YELLOW%^"
                + "washes down your throat, bringing an %^BOLD%^%^MAGENTA%^overwhelming"
                + " %^BOLD%^%^YELLOW%^sense of %^BOLD%^%^GREEN%^renewal%^BOLD%^"
                + "%^YELLOW%^ and %^BOLD%^%^CYAN%^invigoration%^BOLD%^%^YELLOW%^. The"
                + " %^BOLD%^%^MAGENTA%^euphoria %^BOLD%^%^YELLOW%^builds to an almost"
                + " unbearable level, and you collapse into %^RESET%^%^BLUE%^unconsciousness");
    tell_room(environment(ob), (string)ob->QCN + " trembles for a moment, then collapses to "
              + (string)ob->QP + " knees before toppling over sideways, unconscious. As "
              + (string)ob->QS + " sleeps, you can see " + (string)ob->QP + " features"
              + " changing and shifting as " + (string)ob->QS
              + " miraculously becomes young again.", ob);
    ob->set_hp(-10);
    if (member_array("Supped the fountain of Youth", quests) == -1) {
        ob->set_quest("Supped the fountain of Youth");
    }
    EVENT_RECORDS_D->record_event(ob->query_name(), "Supped the fountain of youth", time());
    rejuvenate(ob);
}
