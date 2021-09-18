#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit OBJECT;

mapping sayings;
int cloned;
string owner;

void create(){ //This is a TEST
   ::create();
   cloned = -1;
   set_lore("The parrots of the Tecqumin jungle are known for their curious"
     +" temperaments and their for mimicry. They also like nuts."
     +" And chocolate, but it's not good for them.\n");
   set_property("lore difficulty",25);
   set_weight(3);
   set_value(0);
   set_long((:TO, "long_desc":));
   set_name("parrot");
   set_short("%^BOLD%^%^BLUE%^br%^RED%^igh%^CYAN%^tl%^BLUE%^y"
     +" p%^YELLOW%^l%^BLUE%^u%^CYAN%^m%^YELLOW%^e%^BLUE%^d"
     +" %^BLUE%^pa%^RED%^rr%^BLUE%^ot%^RESET%^");
   set_id(({"parrot","bright parrot", "brightly plumed parrot", "jungle parrot"}));
   set_heart_beat(1);
   sayings = ([]);
   set_property("no animate", 1);
}

void set_owner(string own){
  owner = own;
}

string query_owner(){
  return owner;
}

int befriend_me(string str){
  string * classes;
  if (!id(str)){
    return notify_fail("befriend what?");
  }
  if ( !objectp(ETO) || !living(ETO)){
    return notify_fail("You would have to be carrying the parrot to befriend it");
  }
  classes = ETO->query_classes();
  if (sizeof(classes)<1 || member_array("ranger", classes)== -1){
    if (TP->query_skill("survival")< 20 + random(20)){
      tell_object(TP, "You don't manage to draw the parrot to join you"
        +" as a companion");
      return 1;
    }
  }
  owner = ETO->query_name();
  tell_object(ETO, "You have befriended the "+ query_short()+ ", and now it"
    +" thinks of you as its " + ETO->query_race());
  return 1;
}

string long_desc(){
  object posessor;
  string desc;
  if (cloned ==1){return "";}
  desc = "A %^BOLD%^%^BLUE%^br%^RED%^igh%^CYAN%^tl%^BLUE%^y f%^YELLOW%^ea"
     +"%^BLUE%^th%^CYAN%^er%^YELLOW%^e%^BLUE%^d%^RESET%^, perky"
     +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l"
     +"%^BOLD%^e %^BLUE%^pa%^RED%^rr%^BLUE%^ot%^RESET%^. It has a cheerful"
     +" looking %^BOLD%^%^YELLOW%^bright yellow beak%^RESET%^, and beady"
     +" %^GREEN%^br%^BOLD%^i%^RESET%^%^GREEN%^g%^BOLD%^ht"
     +" gr%^RESET%^%^GREEN%^ee%^BOLD%^n eyes%^RESET%^.\n";
  if (stringp(owner) && (string)TP->query_name()==owner){
    desc += "\n%^ORANGE%^This is your " + query_short() + "%^RESET%^, and"
     +" you are its " + TP->query_race();
  } else {
    if (objectp(ETO)&& stringp(owner)){
      posessor = present(owner, ETO);
      if (objectp(posessor)){
        desc += "This is " + posessor->QCN + "'s " + query_short();
      }
    }
    desc += "\n %^RESET%^If you wish, you could %^ORANGE%^befriend%^RESET%^ this "
      + query_short() +" for yourself.";
  }
  return desc;
}
void init(){ 
  if (cloned ==1){// This check prevents abuse by dropping and insta-getting
    remove();
    return;
  }
   ::init();
   add_action("hear", "say");
   add_action("befriend_me", "befriend");
}

void set_sayings(mapping s){
  sayings = s;
}

mapping query_sayings(){
  return sayings;
}

int is_living(){
  return 0;
}

int move(object dest){
  object parrot;
  int i, count, res;
  if (cloned ==1){remove(); return 0;}
  res = ::move(dest);
  if (cloned == -1){ //so that the object can be moved to a
    cloned = 0;     // non-living environment on creation
    return res;
  }
    if (!living(ETO)){
    parrot = new ("/realms/lujke/tecqumin/mons/" + "parrot");
    if (stringp(owner)){
      parrot->set_owner(owner);
    }
    parrot->set_sayings(([]));
    if (mapp(sayings)){
      parrot->set_sayings(sayings);
    }
    cloned = 1;               //
    set_short("");            // These lines avoid any duping 
    set_long("");             // problems
    set_id(({"clonedparrot"}));// Lujke
    call_out("remove", 1);
    parrot->move(ETO);
    return res;
  }
  return res;
}

void report(string str){
  "/d/atoyatl/reporter_d.c"->report("lujke", str);
}

int hear(string str){
  mixed * details;
  int num, sentences, i, j, n;
  string language, speech, describe, sentence1, sentence2, sentence3, sentence4, sentence5, sentence6, saylias, saylias1,
saylias2;
  string * ks, * ls;
  mapping als;
  
  report ("Hear 1");
  ks = keys (sayings);
  language = TP->query_language();
  str = strip_colors(str);
  sentences = sscanf(str, "%s.%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5, sentence6);
  switch (sentences){
  case 0:
    sentence1 = str;
    sentences = 1;
    break;
  case 1:
    sentences = sscanf(str, "%s.%s", sentence1, sentence2);
    break;
  case 2:
    sentences = sscanf(str, "%s.%s.%s", sentence1, sentence2, sentence3);
    break;
  case 3:
    sentences = sscanf(str, "%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4);
    break;
  case 4:
    sentences = sscanf(str, "%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5);
    break;
  case 5:
    sentences = sscanf(str, "%s.%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5, sentence6);
 }
  report ("Hear 2");

  als = TP->query_aliases();
  report ("Hear 2.1");
  saylias = "";
  if (mapp(als) && sizeof(als) >0)
  {
    report ("Hear 2a");
    ls = keys(als);
    if (member_array("say", ls)!=-1)
    {
      saylias = als["say"];
    }
    report ("Hear 2b");
    saylias = strip_colors(saylias);
    saylias = saylias[4..strlen(saylias)-1];
    n = sscanf(saylias, "%s$*%s", saylias1, saylias2);
    report ("Hear 2c");
    if (n>1 && strlen(saylias2)>0)
    {
      str = str[0..strlen(str)-1-strlen(saylias2)];
    }
    report ("Hear 2d");
    if (n>0 && strlen(saylias1)>0)
    {
      str = str[strlen(saylias1)..strlen(str)-1];
    }
    report ("Hear 2e");
  }
  report ("Hear 3");

  speech = TP->query("speech string");
  if (speech ==0)
  {
    speech = "";
  } else speech += "s";
  describe = TP->query("describe string");
  if (describe == 0) describe = "";
  for (i=0;i<sentences;i++){
    switch(i){
    case 0:
      str = sentence1;
      break;
    case 1:
      str = sentence2;
      break;
    case 2:
      str = sentence3;
      break;
    case 3:
      str = sentence4;
      break;
    case 4:
      str = sentence5;
      break;
    case 5:
      str = sentence6;
      break;
    }
/*
    if (stringp(saylias)){
      j = 0;
      while(interact("$*", saylias) && j<50){
        sscanf(saylias, "%s$*%s", saylias1, saylias2);
        saylias = saylias1+saylias2;
        j++;
      }
      if (saylias == "say " + str){
        continue;
      }
    }
*/
    report ("Hear 3");

    if (str ==""){
      continue;
    }
    while (strlen(str)>1 && str[0..0] == " "){
      str = str[1..strlen(str)-1]; //remove any starting space from sentence
    } 
//    str = FILTERS_D->filter_colors(str);
    if (member_array(str, ks)!= -1){
      num = sayings[str][0];
      num++;    
    } else {
      num = 1;
    }
    details = ({num, language, speech, describe});
    sayings[str] = details;
  }
  report ("Hear 4");

  return 0;
}



void squawk(){
  object ob;
  ob = new (MOB + "parrot.c");
  if (objectp(ob)){
    if (objectp(ETO) && interactive(ETO)){
      if (objectp(EETO)){
        ob->move(EETO);
      } else {
        return;
      }
    }
    ob->set_cloned(1);
    ob->set_sayings(sayings);
    if (!catch(ob->squawk())) report ("Hurrah, successful squawk");
    ob->remove();
  }
  if (random(4)){
    call_out("squawk", 1 + random(4));
  }
}

void heart_beat(){
  if (!random(1000)){
    squawk(); 
  }
}
